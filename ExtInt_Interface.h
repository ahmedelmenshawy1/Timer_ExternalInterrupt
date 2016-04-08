/*
 * ExtInt_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef EXTINT_INTERFACE_H_
#define EXTINT_INTERFACE_H_

extern void ExtInt_Init(void);
extern void ExtInt_voidSetExtInt0(void (*Local_ptr)(void));
extern void ExtInt_voidSetExtInt1(void (*Local_ptr)(void));
extern void ExtInt_voidSetExtInt2(void (*Local_ptr)(void));
extern void ExtInt_EnableGlobalInt(void);
extern void ExtInt_voidenbaleInterrupt(u8 ExtInt_InterruptNumebr);
extern void ExtInt_voidDisbaleInterrupt(u8 ExtInt_InterruptNumebr);
extern void ExtInt_DisableGlobalInt(void);

#endif
