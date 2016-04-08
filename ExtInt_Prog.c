/*
 * ExtInt_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */
#include "delay.h"
#include "ExtInt_Config.h"
#include "ExtInt_Private.h"
#include "ExtInt_Interface.h"


void ExtInt_Init(void)
{
	MCUCR|=ExtInt_u8SenseControl0|ExtInt_u8SenseControl1;
	GICR|=ExtInt_u8Interrupt0|ExtInt_u8Interrupt1|ExtInt_u8Interrupt2;
	MCUCSR|=ExtInt_u8SenseControl2;
}
/***************************************/
//EXT1
ISR(__vector_1)
{
	ptr_EXT0();
}
/***************************************/

//EXT1
ISR(__vector_2)
{
	ptr_EXT1();
}
/***************************************/
//EXT2
ISR(__vector_3)
{
	ptr_EXT2();
}
/***************************************/
extern void ExtInt_voidenbaleInterrupt(u8 ExtInt_InterruptNumebr)
{
	switch (ExtInt_InterruptNumebr)
	{
		case INT0_Number:
		GICR|=(1<<INT0);
		break;

		case INT1_Number:
		GICR|=(1<<INT1);
		break;

		case INT2_Number:
		GICR|=(1<<INT2);
		break;
	}
}
/***************************************/
extern void ExtInt_voidDisbaleInterrupt(u8 ExtInt_InterruptNumebr)
{
	switch (ExtInt_InterruptNumebr)
	{
		case INT0_Number:
		GICR|=(0<<INT0);
		break;

		case INT1_Number:
		GICR|=(0<<INT1);
		break;

		case INT2_Number:
		GICR|=(0<<INT2);
		break;
	}
}
/***************************************/

extern void ExtInt_voidSetExtInt0(void (*Local_ptr)(void))
{
	ptr_EXT0=Local_ptr;
}
/***************************************/

extern void ExtInt_voidSetExtInt1(void (*Local_ptr)(void))
{
	ptr_EXT1=Local_ptr;
}
/***************************************/

extern void ExtInt_voidSetExtInt2(void (*Local_ptr)(void))
{
	ptr_EXT2=Local_ptr;
}
/***************************************/

extern void ExtInt_EnableGlobalInt(void)
{
	__asm__ __volatile__("sei");
}
/***************************************/
extern void ExtInt_DisableGlobalInt(void)
{
	__asm__ __volatile__("cli");
}
