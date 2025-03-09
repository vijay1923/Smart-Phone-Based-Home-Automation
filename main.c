// MINI-PROJECT 1
// SMART PHONE BASSED HOME AUTOMATION USING BLUETOOTH TECHNOLOGY (BT-HC05)
#include<lpc21xx.h>
#include"header.h"

#define led1 1<<17			 // FOR BULB
#define led2 1<<18			 // FOR FAN
#define led3 1<<19			 // STATUS LED MANNUAL OR 
#define sw1 ((IOPIN0>>14)&1)	 // FOR BULB ON AND OFF
#define sw2 ((IOPIN0>>15)&1)	 // FOR  FAN ON AND OFF
#define sw3 ((IOPIN0>>16)&1)	 // FOR MODE SELECTION
int flag=1;
void bluetooth()
{
  unsigned char temp;
   IODIR0=led1|led2;
   uart0_init(9600);
   lcd_init();
   while(1)
   {
		 if(flag)
     temp=uart0_rx();
		 else
		 break;
	  switch(temp)
	 {
	  case 'a':IOCLR0=led1;break;	// LED1 ON
	  case 'b':IOSET0=led1;break;	// LED OFF
	  case 'c':IOCLR0=led2;break; //LED2 ON
	  case 'd':IOSET0=led2;break; //LED2 OFF
	  case 'e':IOCLR0=led1|led2;break; // LED1 & LED2 ON
	  case 'f':IOSET0=led1|led2;break; // LED1 & LED2 OFF
		case 'g':flag=!flag;break;  // TO CHANGE THE MODE
	  default :lcd_string("Invalid input"); // 
	 }
  }
}

void mannual(void )
{
 int f1=0,f2=0;
  while(1)
		{
			if(flag==1)
				break;
		if(sw3==0)		// SW3 IS FOR changing to bluetoth mode / mannual mode 
			{   
			 while(sw3==0);
		   flag=!flag;
			}
		  else if(sw1==0)   // IF SW1 IS PRESSED
		  {
		    while(sw1==0);
			if(f1%2==0)
			IOCLR0=led1;
			else
			IOSET0=led1;
			f1++;
		}	
			else if(sw2==0)			// IF SW2 IS PRESSED 
	  {
		    while(sw2==0);
			if(f2%2==0)
			IOCLR0=led2;
			else
			IOSET0=led2;
			f2++;
	  }	 
		 
 }
}
int main()
{
 // unsigned int i=0;
  uart0_init(9600);
  IODIR0=led1|led2|led3;
	IOSET0=led1|led2;
 // unsigned char temp;
  while(1)
  {
		
   	if(flag)
		{
			uart0_tx_string("bluetooth mode\r\n");
	     bluetooth();
		}
	else if(flag==0)
	 {
		uart0_tx_string("manual mode\r\n");
   	mannual();
	 }
 }   
}
