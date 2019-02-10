#include"TLC5928.h"

TLC5928::TLC5928(uint8_t clk, uint8_t data, uint8_t latch, uint8_t blank, uint8_t num) : pin_clk(clk), pin_data(data), pin_latch(latch), pin_blank(blank), num(num)
{
	
}

TLC5928::~TLC5928(){
	delete [] buffer;
}

void TLC5928::begin()
{
	buffer = new byte[num*16];
	for(uint16_t i=0; i<num*16;i++ )
	{
		buffer[i]=0;
	}
	
	pinMode(pin_clk, OUTPUT);
	pinMode(pin_data, OUTPUT);
	pinMode(pin_latch, OUTPUT);
	pinMode(pin_blank, OUTPUT);
	
	digitalWrite(pin_clk, LOW);
	digitalWrite(pin_data, LOW);
	digitalWrite(pin_latch, LOW);
	digitalWrite(pin_blank, LOW);
}

void TLC5928::setPixel(uint16_t numpi, bool on)
{
	buffer[numpi]=on ? 1 : 0;
}
void TLC5928::setPixel(uint16_t numtlc, uint16_t numpi, bool on)
{
	setPixel(numtlc*16+numpi, on);
}

void TLC5928::on()
{
	digitalWrite(pin_blank, LOW);
	delayMicroseconds(1);
}
void TLC5928::off()
{
	digitalWrite(pin_blank, HIGH);
	delayMicroseconds(1);
}

void TLC5928::show()
{
  for(int i = num*16-1;i>=0;i--)
  {
	writeBit(buffer[i]);
  }  
  digitalWrite(pin_latch, HIGH);
  delayMicroseconds(1);
  digitalWrite(pin_latch, LOW);
  delayMicroseconds(1);
}


void TLC5928::clear()
{
	for(int i = num*16-1;i>=0;i--)
	{
		buffer[i]=0;
		writeBit(buffer[i]);
	}  
	digitalWrite(pin_latch, HIGH);
	delayMicroseconds(1);
	digitalWrite(pin_latch, LOW);
	delayMicroseconds(1);
}

void TLC5928::writeBit(bool on)
{
	if(on)
	{
		digitalWrite(pin_data, HIGH);
	}
	else
	{
		digitalWrite(pin_data, LOW);
	}
	delayMicroseconds(1);
	digitalWrite(pin_clk, LOW);
	delayMicroseconds(1);
	digitalWrite(pin_clk, HIGH);
	delayMicroseconds(1);
}