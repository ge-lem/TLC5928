#include<TLC5928.h>

int CLK = 7;
int DATA = 6;
int LAT = 5;
int BLANK = 4;

int numberTlc = 2;

TLC5928 tlc(CLK,DATA,LAT,BLANK,numberTlc);
void setup() {
  tlc.begin();
}

void loop() {
  tlc.on();
  for(int i=0; i<2; i++)
  {
    for(int j=0; j<10; j++)
    {
      tlc.setPixel(i,j,true);
      if(j>0)tlc.setPixel(i,j-1,false);
      else
      {
        tlc.setPixel(i==0 ? 1 : 0,9,false);
      }
      tlc.show();
      delay(1000);
    }
  }
  delay(1000);
  tlc.clear();
  delay(3000);
}