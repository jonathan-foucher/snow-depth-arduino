// BOARD 1 PROGRAM
// author : Jonathan Foucher

// import the radio transmitter library
#include <VirtualWire.h>

// pins init
float Vout = A0;
int TRIG = 4, ECHO = 5;

void setup() {
	// setup the serial port speed at 9600 bits per second
	Serial.begin(9600);

	// setup the pins as ANALOG/DIGITAL and INPUT/OUTPUT
	pinMode(Vout, INPUT);
	pinMode(TRIG, OUTPUT);
	digitalWrite(TRIG, LOW);
	pinMode(ECHO, INPUT);

	// setup the radio communication speed at 2000 bits per second (VirtualWire)
	vw_setup(2000);
}

void loop() {
	// VARIABLES INIT
	float temperature = 0.00, soundSpeed = 0.00, sensorMeasurement = 0, height = 300.00, airDepth = 0;
	int snowDepth = 0;
	long echo;
	char msg[3];

	// CALCULATION 1
	// calculation of the temperature in Celsius and the ultrasound speed for that temperature in meters per second
	temperature = (5.00 * analogRead(Vout) * 100.00) / 1024.00;
	soundSpeed = 331.30 * sqrt((1.00 + (temperature / 273.15)));

	// MEASUREMENT WITH THE ULTRASON SENSOR
	// trigger the beginning of the measurement
	digitalWrite(TRIG, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG, LOW);

	// read the pulse to get the echo value
	echo = pulseIn(ECHO, HIGH);

	// CALCULATION 2
	// conversion in centimeters
	sensorMeasurement = (float)echo / 58.00;

	// calculation of the real air depth in meters and in function of ultrasound speed value
	airDepth = sensorMeasurement * (soundSpeed / 340);

	// calculation of the snow depth in centimeters
	snowDepth = height - airDepth;

	// MESSAGE EMISSION
	// convert the integer in a char array
	itoa(snowDepth, msg, 10);

	// emit the message
	vw_send((uint8_t *)msg, strlen(msg));

	// wait the end of the emission
	vw_wait_tx();

	// wait 1 second before the next measurement and message emitting
	delay(1000);
}
