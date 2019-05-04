// ULTRASOUND SENSOR TEST PROGRAM
// author : Jonathan Foucher

// pins init
int TRIG = 4, ECHO = 5;

void setup() {
    // setup the serial port speed at 9600 bits per second
    Serial.begin(9600);

    // setup the pins as ANALOG/DIGITAL and INPUT/OUTPUT
    pinMode(TRIG, OUTPUT);
    digitalWrite(TRIG, LOW);
    pinMode(ECHO, INPUT);
}

void loop() {
    // hard values init for the test
    float height = 300.00, airDepth = 0, sensorMeasurement = 0, soundSpeed = 345.00;
    int snowDepth = 0, snowDepthUnits = 0, snowDepthTens = 0, snowDepthHundreds = 0;
    long echo;

    // trigger the beginning of the measurement
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    // read the pulse to get the echo value
    echo = pulseIn(ECHO, HIGH);

    // conversion in centimeters
    sensorMeasurement = (float)echo / 58.00;

    // calculation of the real air depth in meters and in function of ultrasound speed value
    airDepth = sensorMeasurement * (soundSpeed / 340);

    // calculation of the snow depth in centimeters
    snowDepth = height - airDepth;

    // display the final distance result
    Serial.print("The measured distance is ");
    Serial.println(sensorMeasurement);
    Serial.print("The air depth is ");
    Serial.println(airDepth);

    // separate hundreds, tens and units to prepare the message in an array
    snowDepthHundreds = snowDepth / 100;
    snowDepthTens = (snowDepth - snowDepthHundreds * 100) / 10;
    snowDepthUnits = (snowDepth - snowDepthHundreds * 100 - snowDepthTens * 10);

    // display the test result of hundreds, tens and units
    Serial.print("The snow depth is ");
    Serial.print(snowDepthHundreds);
    Serial.print("-");
    Serial.print(snowDepthTens);
    Serial.print("-");
    Serial.println(snowDepthUnits);

    // wait 5 seconds
    delay(5000);
}