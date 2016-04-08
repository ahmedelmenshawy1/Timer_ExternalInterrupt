/*
 * ExtInt_Confih.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef EXTINT_CONFIG_H_
#define EXTINT_CONFIG_H_

/*Comment:Choose Your Interrupt*/
/*Range: ExtInt_u8DisEnable or ExtInt_u8Enable */
#define ExtInt_u8Interrupt0	 ExtInt_u8Enable
#define ExtInt_u8Interrupt1	 ExtInt_u8DisEnable
#define ExtInt_u8Interrupt2	 ExtInt_u8DisEnable

/*Comment:Choose Mode of Interrupt*/
/*Range:ExtInt_u8(LowLevel - AnyChange - FallingEdge - RisingEdge) */

#define ExtInt_u8SenseControl0	ExtInt_u8RisingEdge
#define ExtInt_u8SenseControl1	ExtInt_u8RisingEdge
/*Comment:Choose Mode of Interrupt*/
/*Range:ExtInt_u8(FallingEdge - RisingEdge)ExtInt_u8RisingEdge
 * only have falling and rising
 * */
#define ExtInt_u8SenseControl2	ExtInt_u8RisingEdge




#endif /* EXTINT_CONFIG_H_ */
