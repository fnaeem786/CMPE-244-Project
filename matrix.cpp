/*
 * matrix.cpp
 *
 *  Created on: May 7, 2016
 *      Author: Rabeel Elahi
 */

#include "matrix.hpp"
#include "utilities.h"
#include <stdio.h>

displayAddress_t disp;

uint8_t fonttable[125][8] = {
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x7C, 0x86, 0x8A, 0x92, 0xA2, 0x7C, 0x00},	// Char 048 (0)
		{0x00, 0x22, 0x42, 0xFE, 0x02, 0x02, 0x00, 0x00},	// Char 049 (1)
		{0x00, 0x46, 0x8A, 0x8A, 0x92, 0x92, 0x66, 0x00},	// Char 050 (2)
		{0x00, 0x44, 0x82, 0x92, 0x92, 0x92, 0x6C, 0x00},	// Char 051 (3)
		{0x08, 0x18, 0x28, 0x4A, 0xFE, 0x0A, 0x08, 0x00},	// Char 052 (4)
		{0x00, 0xE4, 0xA2, 0xA2, 0xA2, 0xA2, 0x9C, 0x00},	// Char 053 (5)
		{0x00, 0x3C, 0x52, 0x92, 0x92, 0x92, 0x0C, 0x00},	// Char 054 (6)
		{0x00, 0xC0, 0x80, 0x8E, 0x90, 0xA0, 0xC0, 0x00},	// Char 055 (7)
		{0x00, 0x6C, 0x92, 0x92, 0x92, 0x92, 0x6C, 0x00},	// Char 056 (8)
		{0x00, 0x60, 0x92, 0x92, 0x92, 0x94, 0x78, 0x00},	// Char 057 (9)
		{0x00, 0x00, 0x00, 0x66, 0x00, 0x00, 0x00, 0x00},	    // Char 058 (:)
		{0x00, 0x00, 0x01, 0x66, 0x00, 0x00, 0x00, 0x00},	    // Char 059 (;)
		{0x00, 0x10, 0x28, 0x44, 0x82, 0x00, 0x00, 0x00},	    // Char 060 (<)
		{0x00, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x00},	    // Char 061 (=)
		{0x00, 0x00, 0x00, 0x82, 0x44, 0x28, 0x10, 0x00},	    // Char 062 (>)
		{0x00, 0x40, 0x80, 0x80, 0x8A, 0x90, 0x60, 0x00},	    // Char 063 (?)
		{0x00, 0x7C, 0x82, 0xBA, 0xAA, 0xAA, 0x78, 0x00},	    // Char 064 (@)
		{0x00, 0x3E, 0x48, 0x88, 0x88, 0x48, 0x3E, 0x00},	// Char 065 (A)
		{0x00, 0x82, 0xFE, 0x92, 0x92, 0x92, 0x6C, 0x00},	// Char 066 (B)
		{0x00, 0x38, 0x44, 0x82, 0x82, 0x82, 0x44, 0x00},	// Char 067 (C)
		{0x00, 0x82, 0xFE, 0x82, 0x82, 0x44, 0x38, 0x00},	// Char 068 (D)
		{0x00, 0x82, 0xFE, 0x92, 0xBA, 0x82, 0xC6, 0x00},	// Char 069 (E)
		{0x00, 0x82, 0xFE, 0x92, 0xB8, 0x80, 0xC0, 0x00},	// Char 070 (F)
		{0x00, 0x38, 0x44, 0x82, 0x8A, 0x8A, 0x4E, 0x00},	// Char 071 (G)
		{0x00, 0xFE, 0x10, 0x10, 0x10, 0x10, 0xFE, 0x00},	// Char 072 (H)
		{0x00, 0x00, 0x82, 0xFE, 0x82, 0x00, 0x00, 0x00},	// Char 073 (I)
		{0x00, 0x0C, 0x02, 0x02, 0x82, 0xFC, 0x80, 0x00},	// Char 074 (J)
		{0x00, 0x82, 0xFE, 0x10, 0x28, 0x44, 0x82, 0x02},	// Char 075 (K)
		{0x00, 0x82, 0xFE, 0x82, 0x02, 0x02, 0x06, 0x00},	// Char 076 (L)
		{0x00, 0xFE, 0x80, 0x40, 0x20, 0x40, 0x80, 0xFE},	// Char 077 (M)
		{0x00, 0xFE, 0x80, 0x40, 0x20, 0x10, 0xFE, 0x00},	// Char 078 (N)
		{0x00, 0x7C, 0x82, 0x82, 0x82, 0x82, 0x7C, 0x00},	// Char 079 (O)
		{0x00, 0x82, 0xFE, 0x92, 0x90, 0x90, 0x60, 0x00},	// Char 080 (P)
		{0x00, 0x78, 0x84, 0x84, 0x8C, 0x84, 0x7A, 0x02},	// Char 081 (Q)
		{0x00, 0x82, 0xFE, 0x92, 0x98, 0x94, 0x62, 0x00},	// Char 082 (R)
		{0x00, 0x64, 0x92, 0x92, 0x92, 0x92, 0x4C, 0x00},	// Char 083 (S)
		{0x00, 0xC0, 0x80, 0x82, 0xFE, 0x82, 0x80, 0xC0},	// Char 084 (T)
		{0x00, 0xFC, 0x02, 0x02, 0x02, 0x02, 0xFC, 0x00},	// Char 085 (U)
		{0x00, 0xF0, 0x08, 0x04, 0x02, 0x04, 0x08, 0xF0},	// Char 086 (V)
		{0x00, 0xFC, 0x02, 0x02, 0x1C, 0x02, 0x02, 0xFC},	// Char 087 (W)
		{0x00, 0x82, 0x44, 0x28, 0x10, 0x28, 0x44, 0x82},	// Char 088 (X)
		{0x00, 0x80, 0x40, 0x22, 0x1E, 0x22, 0x40, 0x80},	// Char 089 (Y)
		{0x00, 0xC2, 0x86, 0x8A, 0x92, 0xA2, 0xC2, 0x86},	// Char 090 (Z)
		{0x00, 0xFE, 0x82, 0x82, 0x82, 0x00, 0x00, 0x00},	// Char 091 ([)
		{0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x00},	// Char 092 (\)
		{0x00, 0x82, 0x82, 0x82, 0xFE, 0x00, 0x00, 0x00},	// Char 093 (])
		{0x10, 0x20, 0x40, 0x80, 0x40, 0x20, 0x10, 0x00},	// Char 094 (^)
		{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},	// Char 095 (_)
		{0x00, 0x00, 0x00, 0xC0, 0x20, 0x00, 0x00, 0x00},	// Char 096 (`)
		{0x00, 0x04, 0x2A, 0x2A, 0x2A, 0x2A, 0x1E, 0x02},	// Char 097 (a)
		{0x00, 0x80, 0xFE, 0x0C, 0x12, 0x12, 0x12, 0x0C},	// Char 098 (b)
		{0x00, 0x1C, 0x22, 0x22, 0x22, 0x22, 0x14, 0x00},	// Char 099 (c)
		{0x00, 0x0C, 0x12, 0x12, 0x12, 0x8C, 0xFE, 0x02},	// Char 100 (d)
		{0x00, 0x1C, 0x2A, 0x2A, 0x2A, 0x2A, 0x18, 0x00},	// Char 101 (e)
		{0x00, 0x00, 0x12, 0x7E, 0x92, 0x80, 0x40, 0x00},	// Char 102 (f)
		{0x00, 0x19, 0x25, 0x25, 0x25, 0x25, 0x1E, 0x20},	// Char 103 (g)
		{0x00, 0x82, 0xFE, 0x10, 0x20, 0x20, 0x1E, 0x00},	// Char 104 (h)
		{0x00, 0x00, 0x22, 0xBE, 0x02, 0x00, 0x00, 0x00},	// Char 105 (i)
		{0x00, 0x06, 0x01, 0x01, 0x01, 0x21, 0xBE, 0x00},	// Char 106 (j)
		{0x00, 0x80, 0xFE, 0x08, 0x14, 0x22, 0x02, 0x00},	// Char 107 (k)
		{0x00, 0x00, 0x82, 0xFE, 0x02, 0x00, 0x00, 0x00},	// Char 108 (l)
		{0x00, 0x3E, 0x20, 0x20, 0x1E, 0x20, 0x20, 0x1E},	// Char 109 (m)
		{0x00, 0x3E, 0x10, 0x20, 0x20, 0x20, 0x1E, 0x00},	// Char 110 (n)
		{0x00, 0x1C, 0x22, 0x22, 0x22, 0x22, 0x1C, 0x00},	// Char 111 (o)
		{0x00, 0x21, 0x3F, 0x19, 0x24, 0x24, 0x18, 0x00},	// Char 112 (p)
		{0x00, 0x18, 0x24, 0x24, 0x19, 0x3F, 0x21, 0x00},	// Char 113 (q)
		{0x00, 0x22, 0x3E, 0x12, 0x20, 0x20, 0x18, 0x00},	// Char 114 (r)
		{0x00, 0x12, 0x2A, 0x2A, 0x2A, 0x2A, 0x24, 0x00},	// Char 115 (s)
		{0x00, 0x20, 0x20, 0xFC, 0x22, 0x22, 0x04, 0x00},	// Char 116 (t)
		{0x00, 0x3C, 0x02, 0x02, 0x02, 0x04, 0x3E, 0x00},	// Char 117 (u)
		{0x00, 0x30, 0x08, 0x04, 0x02, 0x04, 0x08, 0x30},	// Char 118 (v)
		{0x00, 0x3C, 0x02, 0x02, 0x1C, 0x02, 0x02, 0x3C},	// Char 119 (w)
		{0x00, 0x22, 0x14, 0x08, 0x14, 0x22, 0x00, 0x00},	// Char 120 (x)
		{0x00, 0x39, 0x05, 0x05, 0x05, 0x05, 0x3E, 0x00},	// Char 121 (y)
		{0x00, 0x22, 0x26, 0x2A, 0x32, 0x22, 0x00, 0x00},	// Char 122 (z)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33}    // char 123 (custom colon)
};


bool matrix::init(uint8_t displayAddress, uint8_t dimmingRate, uint8_t blinkRate, I2C2 *i2c)
{
	if(0 == disp.display1_addr)
	{
		disp.display1_addr = displayAddress;
	}
	else if(0 == disp.display2_addr)
	{
		disp.display2_addr = displayAddress;
	}
	else if(0 == disp.display3_addr){
		disp.display3_addr = displayAddress;
	}
	else{
		disp.display4_addr = displayAddress;
	}

	/*
	 * Data is transferred MSB first
	 * 						HTK16K33 STATE MACHINE
	 * 						-------------
	 * 						POWER ON
	 * 						ENABLE SYSTEM CLOCK
	 * 						ROW/INT OUT PIN SET & INT PIN OUTPUT LEVEL SET
	 * 						DIMMING SET
	 * 						BLINKING SET
	 * 						END
	 */

	// Enable clock
	(i2c->writeReg(displayAddress, 0x21, 0x21));
	//Set dimming frequency (brightness of displays)
	(i2c->writeReg(displayAddress, dimmingRate, dimmingRate));
	//Turn display on and set blink frequency
	(i2c->writeReg(displayAddress, blinkRate, blinkRate));
	return true;
}

void matrix::writeDisplays(char string[], I2C2 *i2c)
{
	// starting address
	uint8_t column = 0x00;
	puts("writing display");

	for(int j=0; j<7; j++){

		i2c->writeReg(disp.display1_addr,column,fonttable[string[0]][j] >> 1);
		i2c->writeReg(disp.display2_addr,column,fonttable[string[1]][j] >> 1);
		i2c->writeReg(disp.display3_addr,column,fonttable[string[2]][j] >> 1);
		i2c->writeReg(disp.display4_addr,column,fonttable[string[3]][j] >> 1);
		column+=2;
	}
}

void matrix::clearDisplay(I2C2 *i2c)
{

	uint8_t column = 0x00;
	for(int j=0; j<8; j++){
		printf("%i", column);
		i2c->writeReg(disp.display1_addr,column,0x00);
		i2c->writeReg(disp.display2_addr,column,0x00);
		i2c->writeReg(disp.display3_addr,column,0x00);
		i2c->writeReg(disp.display4_addr,column,0x00);
		column+=2;
	}

}

void matrix::setTime(char string[], I2C2 *i2c)
{

	uint8_t column = 0x00;
	uint8_t temp[8] = {0};
	uint8_t temp2[8] = {0};

	for(int k=0; k<8; k++)
	{
		temp[k] = fonttable[string[1]][k+1];
	}

	temp[7] = 0x66;

	for(int i=7; i>=0; i--)
	{
		temp2[i] = fonttable[string[2]][i-1];
	}

	temp2[0] = 0x66;

	for(int j=0; j<8; j++){
		if(string[0] == '0'){
			puts("test");
			i2c->writeReg(disp.display1_addr,column,0x00);
		}
		else{
			i2c->writeReg(disp.display1_addr,column,fonttable[string[0]][j] >> 1);
		}

						i2c->writeReg(disp.display2_addr,column,temp[j] >> 1);
						i2c->writeReg(disp.display3_addr,column,temp2[j] >> 1);
						i2c->writeReg(disp.display4_addr,column,fonttable[string[3]][j] >> 1);
		column+=2;
	}


//	if(i2c->checkDeviceResponse(disp.display1_addr)){
//			puts("alive");
//	}
//	if(i2c->checkDeviceResponse(disp.display2_addr)){
//			puts("alive");
//		}
//	if(i2c->checkDeviceResponse(disp.display3_addr)){
//			puts("alive");
//		}
//	if(i2c->checkDeviceResponse(disp.display4_addr)){
//			puts("alive");
//		}


}

