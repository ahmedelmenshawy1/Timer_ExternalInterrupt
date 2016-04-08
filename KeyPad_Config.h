/*
 * KeyPad_Config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

/*********************************************************************/
/*************************Public Defination****************************/
/*********************************************************************/

/*Comment!:choose keypad PORT */
/*Range!: Port Index DIO_u8Port(0~3) */

#define KeyPad_u8FirstNibbleInputSecondOutput	DIO_u8Port0

/*Comment!:each switch which number */
/*Range!  :Number form zero to 15*/
#define KeyPad_Sw0	0
#define KeyPad_Sw1	1
#define KeyPad_Sw2	2
#define KeyPad_Sw3	3
#define KeyPad_Sw4	4
#define KeyPad_Sw5	5
#define KeyPad_Sw6	6
#define KeyPad_Sw7	7
#define KeyPad_Sw8	8
#define KeyPad_Sw9	9
#define KeyPad_Sw10	10
#define KeyPad_Sw11	11
#define KeyPad_Sw12	12
#define KeyPad_Sw13	13
#define KeyPad_Sw14	14
#define KeyPad_Sw15	15


#endif /* KEYPAD_CONFIG_H_ */
