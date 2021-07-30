/*
#define is a "preprocessor directive". It allows you to declare literals
to reuse throughout your program. Anywhere MOTOR_PIN_1 is written, the compiler
will substitute 5. This allows us to improve readability and avoid having
"magic" numbers in our programs.

In this case, we are defining the pins our arduino has connected the motor
driver. These pins need to be PWM as the motor driver expects a PWM signal.

Arduino Uno PWM pins: 3, 5, 6, 9, 10, 11
*/
#define MOTOR_PIN_1 5 
#define MOTOR_PIN_2 6
/*
The baud rate of the Serial port. This is the rate of data transfer
(in bits per second) Generally 115200 is fine, but some devices may
only support a lower baud rate.
*/
#define BAUD_RATE 115200
/*
The argument provided to analogWrite is in a single byte range, so from 0 to
255, the largest number that can be represented in 8 bits.
*/
#define BYTE_MAX 255

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

    To drive the motor, we need to set one pin LOW (off) and write a PWM signal
    to the other. This PWM signal is a "duty cycle"; it indicates, as a
    proportion of 255, how much of the time the pin should be on for. If the
    duty cycle is 1 (i.e. 255/255), the motor will be at full speed. If it is
    50% (128/255), the motor will be at half speed, etc.
    */
    while (Serial.available()) {
        char input = Serial.read();

        if (input == 's') {
            digitalWrite(MOTOR_PIN_1, LOW);
            analogWrite(MOTOR_PIN_2, LOW);
        }
        else if (input == 'g') {
            digitalWrite(MOTOR_PIN_1, LOW);
            analogWrite(MOTOR_PIN_2, BYTE_MAX);
        }
        else if (isDigit(input)) {
            digitalWrite(MOTOR_PIN_1, LOW);
            analogWrite(MOTOR_PIN_2, map((input - '0'), 0, 10, 0, BYTE_MAX));
        }
    }
}
