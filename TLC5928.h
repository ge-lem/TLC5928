
#ifndef TLC5928_h
#define TLC5928_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <inttypes.h>

class TLC5928
{
 public:
		/**
		\param clk Clock pin
		\param data Data pin
		\param latch Latch pin
		\param blank Blank pin
		\param num number of chained TLC5928
		*/
		TLC5928(uint8_t clk, uint8_t data, uint8_t latch, uint8_t blank, uint8_t num);
		~TLC5928();
	
		/** Initialise the pin and allocate the led buffer
		*/
		void begin();
		
		/** Set state of a LED
		\param numpi number of the led
		\param on On/Off state of the led
		*/
		void setPixel(uint16_t numpi, bool on);
		
		
		/** Set state of a LED
		\param numtlc number of ship
		\param numpi number of the led on the specified ship
		\param on On/Off state of the led
		*/
		void setPixel(uint16_t numtlc, uint16_t numpi, bool on);
		
		/** Turn on the LEDs power
		*/
		void on();
		/** Turn off the LEDs power
		*/
		void off();
		/** Apply the change to the LEDs
		*/
		void show();
		/** Turn off all the LEDs
		*/
		void clear();
 
 protected:
    uint8_t pin_clk;
    uint8_t pin_data;
    uint8_t pin_latch;
    uint8_t pin_blank;
	
		uint8_t num;
	
		byte * buffer;

  private:
  	void writeBit(bool on);
};

#endif
