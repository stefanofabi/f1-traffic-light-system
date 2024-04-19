# Traffic Light F1 Simulator

This project is designed to simulate the traffic light system used in Formula 1 races. It uses an Arduino Nano ATmega328P connected to a breadboard to control the LEDs representing the traffic light's lights.

Its logic is simple, it turns on a traffic light every 1 second until all 5 lights are complete. When all the lights are on, all the lights turn off after a certain random time.

## Dependencies

Make sure you have the following dependencies installed before compiling and uploading the firmware to the microcontroller:

```bash
sudo apt-get install gcc-avr binutils-avr avr-libc gdb-avr avrdude -y
```

## Installation
Compile with:
```bash
make clean
make
```
Transfer the generated firmware to the MCU with:
```bash
make flash
```

## Pin connections
Connect an LED to each of the pins PB0-4 that are mapped on the Arduino board to pins D8-D12
- PB0 (D8)
- PB1 (D9)
- PB2 (D10)
- PB3 (D11)
- PB4 (D12)