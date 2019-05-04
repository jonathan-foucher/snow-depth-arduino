// RADIO EMISSION TEST PROGRAM BOARD 1
// REQUIRE RADIO RECEPTION TEST PROGRAM ON BOARD 2
// author : Jonathan Foucher

// import the radio transmitter library
#include <VirtualWire.h>

void setup() {
	// setup the serial port speed at 9600 bits per second
	Serial.begin(9600);

	// setup the radio communication speed at 2000 bits per second (VirtualWire)
	vw_setup(2000);
}

void loop() {
	// init variables
	int snowDepth = 257;
	char msg[3];

	// convert the integer in a char array
	itoa(snowDepth, msg, 10);

	// emit the message
	vw_send((uint8_t *)msg, strlen(msg));

	// wait the end of the emission
	vw_wait_tx();

	// wait 0.2 second before emitting the next message
	delay(200);
}