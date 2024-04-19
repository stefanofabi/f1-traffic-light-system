/* utils.c - support functions to the main program */

/* F1 traffic light lights on ports b0-4 of an atmega328p
 * Port B of an atmega328 has bits 0-5 mapped to pins 8-13 of the arduino
 */

#include <stdlib.h>
#include <time.h>
#include <limits.h>

/* ports E/S */

/* PORTB address (data record) */
volatile unsigned char * PUERTO_B = (unsigned char *) 0x25;

/* DDR B address (control register) */
volatile unsigned char * DDR_B = (unsigned char *) 0x24;

/* PIN B address (input data record) */
volatile unsigned char * PIN_B = (unsigned char *) 0x23;

/* 1 second = 450000 */
#define TIME_BETWEEN_LIGHTS 250000

void sleep(long delay) 
{
	// we tell the compiler not to optimize this variable
	volatile unsigned long i;
	for (i=0; i<delay; i++);
}

/* init: configure PORTB bit 5 as output */
void init() 
{
	/* turn off port pb0-4 gpio pin voltage */
	*(PUERTO_B) = *(PUERTO_B) & (0xE0);		//	0b11100000

	/* set pin as output=1 on ddrb port */
	*(DDR_B) = *(DDR_B) | (0x1F);			// 0b00011111
}

/* void led_on: turn on a specific led */
void led_on(int position)
{
	unsigned char valor_b;
	valor_b = *(PUERTO_B);
	valor_b |= (1 << position);
	*(PUERTO_B) = valor_b;
}

/* void turn_off_lights: turn off all the lights at the same time */
void turn_off_lights()
{
	unsigned char valor_b;
	valor_b = *(PUERTO_B);
	valor_b ^= (0x1F);
	*(PUERTO_B) = valor_b;
}

/* void start: turn on the traffic light sequence */
void start() 
{
	led_on(0);
	sleep(TIME_BETWEEN_LIGHTS);

	led_on(1);
	sleep(TIME_BETWEEN_LIGHTS);

	led_on(2);
	sleep(TIME_BETWEEN_LIGHTS);

	led_on(3);
	sleep(TIME_BETWEEN_LIGHTS);

	led_on(4);
	sleep(TIME_BETWEEN_LIGHTS);

	turn_off_lights();
    
    // generate a random number to sleep
	srand(time(NULL));
    int random_time = rand() % 450001;
	sleep(random_time);

}