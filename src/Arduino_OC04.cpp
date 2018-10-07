/*
	This is a library for the OC04
	Relay Out High Voltage

	The board uses I2C for communication.
	The board communicates with the following I2C device:
	* 	PCA9554A
	
	Data Sheets:
	PCA9554A - http://www.ti.com/lit/ds/symlink/pca9554a.pdf
*/

#include <Arduino_OC04.h>

/********************************************************
 	Constructor
*********************************************************/
xOC04::xOC04()
{
	PCA9554A_I2C_ADDRESS = 0x38;
}

xOC04::xOC04(uint8_t addr)
{
	PCA9554A_I2C_ADDRESS = addr;
}

/********************************************************
 	Configure OC04
*********************************************************/
bool xOC04::begin(void)
{
	begin(PCA9554A_ALL_OUTPUTS_OFF);
}

bool xOC04::begin(bool state)
{
	write(state);
	xCore.write8(PCA9554A_I2C_ADDRESS, PCA9554A_REG_CONFIG, PCA9554A_CONF_OUTPUT);
	return true;
}

/********************************************************
 	Write to PIN
*********************************************************/
void xOC04::write(bool state)
{	
	if(state == true){
		xCore.write8(PCA9554A_I2C_ADDRESS, PCA9554A_REG_OUTPUT_PORT, 0x01);
	}else if(state == false){
		xCore.write8(PCA9554A_I2C_ADDRESS, PCA9554A_REG_OUTPUT_PORT, 0x00);
	}
}

/********************************************************
 	Get output pin Status
*********************************************************/
uint8_t xOC04::getStatus(void)
{
	uint8_t pin_state = xCore.read8(PCA9554A_I2C_ADDRESS, PCA9554A_REG_OUTPUT_PORT); 
	return pin_state;
}



