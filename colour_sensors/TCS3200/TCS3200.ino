/*
Pins on the colour sensor that we need. LED_PIN is optional, if you don't need
to control the LEDs, you can simply remove it.

OUT_PIN is where we read the colour sensors output from.
LED_PIN is used to turn the LEDs on or off. This is optional.
S2_PIN and S3_PIN are used to configure which colour to read.
*/
#define OUT_PIN 3
#define LED_PIN 2
#define S2_PIN 5
#define S3_PIN 4

/* Aliases for colours, used as an enumeration for readColour. */
#define RED 'R'
#define BLUE 'G'
#define GREEN 'B'

/*
Serial communication baud rate.
Make sure your serial monitor is set to this value.
*/
#define BAUD_RATE 115200


/*
Gets a reading from the colour sensor for the provided colour. Accepts one of
the enumerated colours above, RED, BLUE or GREEN, to indicate which colour to
read.
*/
int readColour(char colour) {
    /*
    To set the colour to read, we write to S2 and S3. The colour is set
    according to

    +-------+-------+--------+
    | S2    | S3    | Colour |
    +-------+-------+--------+
    | LOW   | LOW   | Red    |
    | LOW   | HIGH  | Blue   |
    | HIGH  | HIGH  | Green  |
    | HIGH  | LOW   | -      |
    +-------+-------+--------+
    */
    switch (colour) {
      case RED:
        digitalWrite(S2_PIN, LOW);
        digitalWrite(S3_PIN, LOW);
        break;
      case BLUE:
        digitalWrite(S2_PIN, LOW);
        digitalWrite(S3_PIN, HIGH);
        break;
      case GREEN:
        digitalWrite(S2_PIN, HIGH);
        digitalWrite(S3_PIN, HIGH);
        break;
      default:
        return -1; // Invalid colour.
    }

    /*
    The value is reported using PWM. By calling pulseIn, the Arduino will read
    in a full pulse from the sensor and report the pulse length, which is the
    signal emitted by the sensor. 
    */
    return pulseIn(OUT_PIN, LOW);
}


void setup() {
    Serial.begin(BAUD_RATE);

    /* Set up pins for control and reading data. */    
    pinMode(OUT_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    pinMode(S2_PIN, OUTPUT);
    pinMode(S3_PIN, OUTPUT);

    /*
    The LEDs will be turned on if we write HIGH, or off if we write LOW.
    Here we turn them on because this provides better lighting, improving
    the reliability of colour sensing.
    */
    digitalWrite(LED_PIN, HIGH);
}

void loop() {
    Serial.print("Red: ");
    Serial.print(String(readColour(RED)));
    Serial.print("\tGreen: ");
    Serial.print(String(readColour(GREEN)));
    Serial.print("\tBlue: ");
    Serial.println(String(readColour(BLUE)));
    delay(500);
}
