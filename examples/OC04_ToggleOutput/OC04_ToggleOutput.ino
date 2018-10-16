/*************************************************************
	This is an examples for the OC04
	Relay Out High Voltage
	
	You can buy one on our store!
	-----> https://xinabox.cc/products/OC04/
	
	This example in structs the OC04 to turn its output port
	on and off
	
	The sensor communicates over the I2C Bus.
	
*************************************************************/

/********************* Library Includes *********************/
#include <arduino-OC04.h> // https://github.com/xinabox/arduino-OC04
#include <xCore.h>

/****************** Global sensor objects *******************/
xOC04 OC04;

/********************* SYSTEM VARIABLES *********************/
const int DELAY_TIME = 2000;

/*********************** Sketch Code ************************/
void setup() {
	// Start the Serial Monitor
	Serial.begin(115200);

	#ifdef ESP8266
		Wire.pins(2,14);
	#endif
		
	// Start the I2C Communication
	Wire.begin();
	
	// Start the OC04 port expander
	OC04.begin();

	Serial.println("OC04 Test");
}

void loop() {
	// Switch OUT on
	OC04.write(HIGH);
	delay(DELAY_TIME);
	
	// Switch OUT off
	OC04.write(LOW);
	delay(DELAY_TIME);
}