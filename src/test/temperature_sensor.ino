// TEMPERATURE SENSOR TEST PROGRAM
// author : Jonathan Foucher

// pin init
float Vout = A0;

void setup() {
    // setup the serial port speed at 9600 bits per second
    Serial.begin(9600);

    // setup pin as ANALOG/DIGITAL and INPUT/OUTPUT
    pinMode(Vout, INPUT);
}

void loop() {
    // init variables
    float temperature = 0.00, soundSpeed = 0.00;

    // calculation of the temperature in Celsius and the ultrasound speed for that temperature in meters per second
    temperature = (5.00 * analogRead(Vout) * 100.00) / 1024.00;
    soundSpeed = 331.30 * sqrt((1.00 + (temperature / 273.15)));

    // display the result for temperature
    Serial.println("-------------------------");
    Serial.print("The temperature is ");
    Serial.print(temperature);
    Serial.println(" °C");

    // display the result for speed
    Serial.print("The speed is ");
    Serial.print(soundSpeed);
    Serial.println(" m/s");

    // wait 5 seconds
    delay(5000);
}