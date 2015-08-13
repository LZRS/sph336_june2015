/*
 * tsi_config.h
 *
 *  Created on: Jul 28, 2015
 *      Author: lincoln
 */

#ifndef TSI_CONFIG_H_
#define TSI_CONFIG_H_
/*
*Enabled clock gate
*Configured number of scans
*Calculated offset of the different channels
*Enabled tsi module
*/

#include "MK60DZ10.h"
#include "Mk60.h"
void tsi_init(void){
	//Enable clock gates
	//SIM_SCGC5 |= (SIM_SCGC5_PORTA_MASK); //Enabled in system_k60.c

	//PORTA_PCR4 = PORT_PCR_MUX(0); //Enabled in gpio.h
	//Enable ALT0 for portA4


	//Configure the number of scans and enable the interrupt
	TSI0_GENCS |= ((TSI_GENCS_NSCN(10))|(TSI_GENCS_TSIIE_MASK)|(TSI_GENCS_PS(3)));
	TSI0_SCANC |= ((TSI_SCANC_EXTCHRG(3))|(TSI_SCANC_REFCHRG(31))|
	(TSI_SCANC_DELVOL(7))|(TSI_SCANC_SMOD(0))|(TSI_SCANC_AMPSC(0)));

	//Enable the channels desired
	TSI0_PEN |= (TSI_PEN_PEN5_MASK|TSI_PEN_PEN7_MASK|
	TSI_PEN_PEN8_MASK|TSI_PEN_PEN9_MASK);
	TSI0_THRESHLD5 = (uint32_t)((0x1214)); //threshold channel offset = x1200 + (4d * n)
	TSI0_THRESHLD7 = (uint32_t)((0x121c)); //0x1200+28d
	TSI0_THRESHLD8 = (uint32_t)((0x1220)); //0x1200+32d
	TSI0_THRESHLD9 = (uint32_t)((0x1224)); //0x1200+36d
	//Enable TSI module
	TSI0_GENCS |= (TSI_GENCS_TSIEN_MASK);
	//Enables TSI
}



#endif /* TSI_CONFIG_H_ */

