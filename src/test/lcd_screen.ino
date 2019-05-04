// LCD SCREEN TEST PROGRAM
// author : Jonathan Foucher

// import the lcd screen libraries
#include <LCD.h>
#include <LCD_C0220BiZ.h>
#include <ST7036.h>

// set the lcd address to 0x7C, 16 chars and 2 line display
ST7036 lcd = ST7036(2, 16, 0x7C);

void setup() {
	// init the lcd screen
	lcd.init();
}

void loop() {
	// init variables
	int snowDepth = 135;

	// display on the lcd screen
	// first line of the screen
	lcd.setCursor(0, 0);
	lcd.print("The snow depth");

	// second line of the screen
	lcd.setCursor(1, 0);
	lcd.print("is ");
	lcd.print(snowDepth);
	lcd.print(" cm");

	// wait and display the message during 5 seconds
	delay(5000);

	// clear the screen
	lcd.clear();
}