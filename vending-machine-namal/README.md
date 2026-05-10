# Embeded_Systems
TM4C123GH6PM Microcontroller/ STM CubeMx / Keil u vision/ Proteus Projects

## Vending Machine 

The project is a hardware prototype of the vending machine using the TM4C123GH6PM Microcontroller. The software part was done in C language using Keil u vision.
The user can use the input buttons to select the product from the list, after product selection user can chose the amount to pay, if payment is less than the machine 
asks for more and if the payed amount is greater then machine prompt the message on LCD that the specific amount is returned to the USER.

### Modules Covered:
1- LCD Display interfacing with Microcontroller.
2- Input Buttons Interfacing.
3- LEDs Interfacing.
4- Interupts configuration, GPIO pins configurations. 
5- Hardware Prototype.

### Main Functionality:
1- Welcome Display.
2- Product Selection.
3- Payment Options/ deposit amount selection.
4- Return or Demand amount calculation and Display.

The code is available: Startup, C, header file that can be directly run through keil and buil/uploaded on the Microcontroller board.


## Obstacle Avoidance Car(simulation based) 
##### Using STM32F401CB , STM CubeMx, Proteus, Keil U vision 
In this project the Motors, Ultrasonic sensor, Servo Motors are used to achieve the goal of Obstacle sensitivity. The code is not available as a separate file.
but the PDF contains the detail steps of how to implement and build from scratch the whole project.

Module Covered: 
(Making Initial Setup With STM CubeMx Software)

1. Motor/ Servo Motors Interfacing (PWM configuration)
2. Sensors/ LEDs/ Motor Driver interfacing.
3. GPIO Configuration.

(Building Logic in Keil u vision)

4. Obstacle avoidance logic based on ultra Sonic Sensor Reading.
5. Proteus Simulation.
