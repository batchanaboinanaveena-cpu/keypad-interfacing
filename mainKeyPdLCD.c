#include<LPC21xx.h>
#include"delay.h"
#include"types.h"
#include"defines.h"
#include"keyPd.h"
#include"lcd.h"
int main()
{
	InitLCD();
	CmdLCD(0x80);
	IntLCD(123);
	//IODIR1|=(0X0F<<16);
	KeyPdInit();
	while(1)
	{
		while(ColStat());
		//wait for sw press
		delay_ms(10);//for avoiding keybouncing time.
  	CmdLCD(0x80);
		IntLCD(KeyVal());
		while(!ColStat());
		//wait for sw release
	}
	
}


