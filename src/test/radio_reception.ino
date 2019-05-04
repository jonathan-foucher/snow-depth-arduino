// RADIO RECEPTION TEST PROGRAM BOARD 2
// REQUIRE RADIO EMISSION TEST PROGRAM ON BOARD 1
// author : Jonathan Foucher

// import the radio receiver library
#include <VirtualWire.h>

void setup() {
	// setup the serial port speed at 9600 bits per second
	Serial.begin(9600);

	// setup the radio communication speed at 2000 bits per second (VirtualWire) and start to listen
	vw_setup(2000);
	vw_rx_start();
}

void loop() {
	// init variables
	uint8_t msg[4];
	uint8_t msgSize = 3;
	int snowDepth, i;
	char msg2[4];

	// wait to detect a message
	vw_wait_rx();

	// get the message
	vw_get_message(msg, &msgSize); {
		// if the message is received
		// get each element of the message in a char array
		for (i = 0; i < msgSize; i++) {
			msg2[i] = char(msg[i]);
		}

		// convert char array to int
		snowDepth = atoi(msg2);

		// display the result
		Serial.println(snowDepth);
	}
}