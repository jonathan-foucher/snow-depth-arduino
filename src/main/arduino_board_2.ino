// BOARD 2 PROGRAM
// author : Jonathan Foucher

// import the radio receiver library
#include <VirtualWire.h>

// import the lcd screen libraries
#include <LCD.h>
#include <LCD_C0220BiZ.h>
#include <ST7036.h>

// set the lcd address to 0x7C, 16 chars and 2 line display
ST7036 lcd = ST7036(2, 16, 0x7C);

void setup() {
	// setup the serial port speed at 9600 bits per second
    Serial.begin(9600);

	// setup the radio communication speed at 2000 bits per second (VirtualWire) and start to listen
    vw_setup(2000);
    vw_rx_start();

	// init the lcd screen
    lcd.init();
}

void loop() {
	// VARIABLES INIT
    uint8_t msg[4], msgSize = 3;
    char msg2[4];
    int i, snowDepth = 0;

    // RECEIVE THE MESSAGE
	// wait to detect a message
    vw_wait_rx();

	// get the message
    vw_get_message(msg, &msgSize);
    for (i = 0; i < msgSize; i++) {
		// if the message is received
		// get each element of the message in a char array
        msg2[i] = char(msg[i]);
    }

	// convert char array to int
    snowDepth = atoi(msg2);

    // DISPLAY THE RESULT MESSAGE ON THE LCD SCREEN
	// clear the screen
    lcd.clear();

	// put the screen cursor on the first line
    lcd.setCursor(0, 0);

    if (snowDepth > 300) {
		// if the snowDepth is greater than 300, it means there is an error 
        // (300 is the maximum range of the ultrasonic device we used)
		// an error message is displayed
        lcd.print("Error, the distance");
        lcd.setCursor(1, 0);
        lcd.print("is too long");
    } else if (snowDepth < 0) {
		// else if snowDepth is negative, it means there was a problem with the radio transmission
		// an error message is displayed
        lcd.print("Error, there is");
        lcd.setCursor(1, 0);
		lcd.print("TX problem");
    } else {
		// else the value is good and we can display the result
        lcd.print("The snow depth");
        lcd.setCursor(1, 0);
        lcd.print("is ");
		lcd.print(snowDepth);
		lcd.print(" cm");
    }
}