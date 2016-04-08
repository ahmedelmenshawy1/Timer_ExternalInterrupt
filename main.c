/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#include "Types.h"
#include "DIO_interface.h"
#include "Timer_Interface.h"
#include "ExtInt_Interface.h"
#include "KeyPad_Interface.h"
#include "Debouncing_Interface.h"
#include "delay.h"

#define Pressed	 	 1
#define Released	 0

#define TurnOn	 	 1
#define TurnOff	 	 0

#define FiredInterrupt	 	 1
#define StopInterrupt 	     0

#define FirstPressed	 	 1
#define SecondPressed 	     2


#define FirstLed	 	 16
#define SecondLed	 	 17
#define ThirdLed	 	 18

#define ExternaInterruptZeroPin	 	 26


volatile u16 TotalTimeInMile;
volatile u8 ToggleLed1,ToggleLed2,ToggleLed3;
volatile u8 Led_1,Led_2,Led_3;
volatile u8 KeyPadVal_2;

void Toggle(void);
int main (void)
{
	u8 KeyPadVal,Toggle_3=0,Toggle_2=0,Toggle_1=0,SwitchPin;
	DIO_VoidInit();
	ExtInt_Init();
	Timer_VoidInit();
	ExtInt_EnableGlobalInt();

	//ExtInt_voidOverFlowInt0(Toggle);
	ExtInt_voidSetExtInt0(Toggle);

	while(1)
	{
		DIO_u8ReadPinVal(DIO_u8Pin24,&SwitchPin);
		if(u8_DebounceSenceHigh(SwitchPin,Pressed) == Pressed)
		{
			DIO_u8WritePinVal(ExternaInterruptZeroPin,TurnOn);
		}
		else DIO_u8WritePinVal(ExternaInterruptZeroPin,TurnOff);

		TotalTimeInMile=Timer_u16Count1mile();
		KeyPadVal=KeyPad_StructRead();
		if(KeyPadVal!=KeyPad_u8NoPressed)
		{
			KeyPadVal_2=KeyPadVal;
			//PORTB=KeyPadVal_2	;
		}
		else;
		if(TotalTimeInMile>=250)
		{

			if(Led_1==FiredInterrupt)
				{
					if(ToggleLed1==FirstPressed)
					{
						DIO_u8WritePinVal(FirstLed,Toggle_1^=1);
					}
					else DIO_u8WritePinVal(FirstLed,TurnOff);
				}
				else;

				if(Led_2==FiredInterrupt)
				{
					if(ToggleLed2==FirstPressed)
					{
						DIO_u8WritePinVal(SecondLed,Toggle_2^=1);
					}
					else DIO_u8WritePinVal(SecondLed,TurnOff);
				}
				else ;

				if(Led_3==FiredInterrupt)
				{
					if(ToggleLed3==FirstPressed)
					{
						DIO_u8WritePinVal(ThirdLed,Toggle_3^=1);
					}
					else DIO_u8WritePinVal(ThirdLed,TurnOff);
				}
				else;

			Timer_u16ResetCounter();
			Timer_u16ResetTotalTime();
		}
		else;
	}
	return 0;
}

void Toggle(void)
{
			switch (KeyPadVal_2)
				{
					case 1:
					Led_1=FiredInterrupt;
					ToggleLed1++;//first pressed
					if(ToggleLed1==SecondPressed){
						ToggleLed1=TurnOff;
					}
					else;
					break;

					case 2:
					Led_2=FiredInterrupt;
					ToggleLed2++;//first pressed
					if(ToggleLed2==SecondPressed){
						ToggleLed2=TurnOff;
					}
					else;
					break;

					case 3:
					Led_3=FiredInterrupt;
					ToggleLed3++;//first pressed
					if(ToggleLed3==SecondPressed)
					{
						ToggleLed3=TurnOff;
					}
					else;
					break;

					default:

					break;
				}
}
