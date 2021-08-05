/*
This is a C++ source code file, and contains the implementations for the
functions declared in motor.h. The convention is to have matching .h and
.cpp or .c files, with the .h files containing the declarations and the
.cpp files containing the implementations.
*/

/*
Arduino.h provides the Arduino standard library. It is automatically included
in your main .ino file, but if you want to access its functions in other files,
you'll need to include it manually.

We use <> instead of "" around this include because it is a system library
rather than a local file in the same folder.

This file uses the Arduino functions
    pinMode, to set up pins for writing to drive the motor.
    digitalWrite, to turn on and off pin outputs.
    analogWrite, to set the PWM value of pin outputs.
    map, to map values from one number range to another.
    abs, to get the absolute value of numbers.
*/
#include <Arduino.h>

/*
We include motor.h to bring the Motor class into scope so that we can implement
it's methods, such as when we implement Motor::drive, the drive(int speed)
function declared in motor.h.
*/
#include "motor.h"

Motor::Motor(int pin1, int pin2) {
    pin_1 = pin1;
    pin_2 = pin2;

    pinMode(pin_1, OUTPUT);
    pinMode(pin_2, OUTPUT);
}

/*
To drive the motor, we need to set one pin LOW (off) and write a PWM signal
to the other. This PWM signal is a "duty cycle"; it indicates, as a
proportion of 255, how much of the time the pin should be on for. If the
duty cycle is 1 (i.e. 255/255), the motor will be at full speed. If it is
50% (128/255), the motor will be at half speed, etc.

This function takes in a speed from -100 to 100, using the sign as a direction
(i.e. a negative number will cause the motor to spin backward) and the magnitude
as a percentage of full speed.
*/
void Motor::drive(int speed) {
    if (speed == 0) {
        stop();
    }
    else {
        bool direction;
        if (speed < 0) {
            direction = false; 
        }
        else {
            direction = true;
        }
        
        speed = map(abs(speed), 0, 100, 0, 255);

        if (direction) {
            digitalWrite(pin_1, LOW);
            analogWrite(pin_2, speed);
        }
        else {
            analogWrite(pin_1, speed);
            digitalWrite(pin_2, LOW);
        }
    }
}

void Motor::stop() {
    digitalWrite(pin_1, LOW);
    digitalWrite(pin_2, LOW);
}
