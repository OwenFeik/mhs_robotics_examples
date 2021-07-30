/*
#include is a "preprocessor directive", it essentially tells the compiler
"Go and get this file, copy it and and paste it in here.".
*/
#include "motor.h"

/*
#define is another preprocessor directive. It allows you to declare literals
to reuse throughout your program. Anywhere BAUD_RATE is written, it will be
replaced with 115200. includes and defines should generally be placed at the
top of your files.
*/
#define BAUD_RATE 115200

/*
Variables declared here, outside any function are globals. You will be able
to access them inside setup(), loop() or any other functions you declare.

Motor is a class declared in the file "motor.h", which we included above. Here
we created a global Motor object so that we can use it in the loop() function.
The Motor class needs two pin numbers as arguments, both of which need to be
PWM capable.

Arduino Uno PWM pins: 3, 5, 6, 9, 10, 11
*/
Motor motor = Motor(5, 6);

/*
In an Arduino program, the setup() function is called once when the Arduino
first starts. The loop() function is then called repeatedly. One should put
their one time setup code (initialising or calibrating sensors, etc) in the
setup() function and their code to be run at every time step (reading sensor
values, updating motor speeds, etc) in the loop() function.
*/
void setup() {
    /*
    The Serial object allows the Arduino to communicate through a binary stream
    over either the RX and TX (receiving and transmitting) pins, 0 and 1 or the
    USB port.
    */
    Serial.begin(BAUD_RATE);
}

/*
Once the setup() function has been called once, the Arduino will simply run
loop() repeatedly.
*/
void loop() {
    /*
    Read incoming serial data, handling character commands. 3 commands are
    specified:
        s - Stop the motor.
        g - Start the motor.
        number - Set the motor to (number * 10)% speed. e.g. 9 => 90% speed. 
    */
    while (Serial.available()) {
        char input = Serial.read();

        if (input == 's') {
            motor.stop();
        }
        else if (input == 'g') {
            motor.drive(100);
        }
        else if (isDigit(input)) {
            motor.drive((input - '0') * 10);
        }
    }
}
