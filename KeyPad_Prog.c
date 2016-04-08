/*
 * KeyPad_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */
#include "Types.h"
#include "DIO_Private.h"
#include "DIO_config.h"
#include "DIO-utilites.h"
#include "DIO_interface.h"
#include "KeyPad_Private.h"
#include "KeyPad_Config.h"
#include "KeyPad_Interface.h"
#include "delay.h"

//int main(void)
//{
//	DIO_VoidInit();
//	while(1)
//	{
//		//PORTB=KeyPad_StructRead();
//		KeyPad_StructRead();
//	}
// return 0;
//}

u8 KeyPad_StructRead(void)
{
	//StructKeyPad x;
	u8 const keypad_u8Keys[4][4]={{KeyPad_Sw0,KeyPad_Sw1,KeyPad_Sw2,KeyPad_Sw3  },
								  {KeyPad_Sw4,KeyPad_Sw5,KeyPad_Sw6,KeyPad_Sw7  },
								  {KeyPad_Sw8,KeyPad_Sw9,KeyPad_Sw10,KeyPad_Sw11},
								  {KeyPad_Sw12,KeyPad_Sw13,KeyPad_Sw14,KeyPad_Sw15}
								 };
	u8 local_u8Counter,local_u8PortVal,local_u8Counter1,Keypad_u8Power[4]={1,2,4,8},local_u8LastVal=KeyPad_u8NoPressed;

	for(local_u8Counter=4;local_u8Counter<8;local_u8Counter++)
	{
		local_u8PortVal=(1<< local_u8Counter);
		DIO_u8WritePortVal(KeyPad_u8FirstNibbleInputSecondOutput,&local_u8PortVal );
		Delay_ms_Max1s(1);
		DIO_u8ReadPortVal(KeyPad_u8FirstNibbleInputSecondOutput,&local_u8PortVal );
		local_u8PortVal&= 0x0f;
		if(local_u8PortVal != 0)
		{
			local_u8Counter+=5;//break;
		}
		else;
	}
	if(local_u8PortVal != KeyPad_u8Released)//pressed
	{
		local_u8Counter-=6;
		for(local_u8Counter1=0;local_u8Counter1<4;local_u8Counter1++)
		{
			if(Keypad_u8Power[local_u8Counter1]==local_u8PortVal)
			{
				local_u8PortVal=local_u8Counter1;
				local_u8Counter1=5;//break
			}
		}
		local_u8LastVal=keypad_u8Keys[local_u8PortVal][local_u8Counter-4];
		//PORTB=keypad_u8Keys[local_u8PortVal][local_u8Counter-4];

	}
	return local_u8LastVal;
}
