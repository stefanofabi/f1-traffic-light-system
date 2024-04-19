
/* Simulates the f1 traffic light */

#include "utils.h"

int main(void)
{	
	init();

	while (1) 
	{
        start();
		sleep(900000);
    }
}


