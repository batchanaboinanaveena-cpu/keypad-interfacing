#include<LPC21xx.h>
#include"delay.h"
#include"types.h"
#include"defines.h"
#include"keyPd.h"
#define LEDS 0xff//P0/0-P0.7

int main()
{
	IODIR0|=LEDS;//P0.0-P0.7 are conf for output direction
	//IODIR1|=(0X0F<<16);
	KeyPdInit();
	while(1)
	{
		while(ColStat());
		//wait for sw press
		delay_ms(10);//for avoiding keybouncing time.
		WRITEBYTE(IOPIN0,0,KeyVal());
		while(!ColStat());
		//wait for sw release
	}
	
}


