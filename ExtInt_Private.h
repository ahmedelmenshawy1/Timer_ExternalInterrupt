/*
 * ExtInt_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef EXTINT_PRIVATE_H_
#define EXTINT_PRIVATE_H_

#define ISR(vector)  															\
	void vector(void)	__attribute__((signal,used,externally_visible));		\
	void vector(void)

void (*ptr_EXT0)(void);
void (*ptr_EXT1)(void);
void (*ptr_EXT2)(void);



#define MCUCR_u8Address		(0x55)
#define MCUCSR_u8Address	(0x54)
#define GICR_u8Address		(0x5B)
#define GIFR_u8Address		(0x5A)

#define GIFR	(*(volatile u8 *) GIFR_u8Address  )


#define ExtInt_u8DisEnable	0
#define ExtInt_u8Enable		1

#define MCUCR	(*(volatile u8 *) MCUCR_u8Address )

#define ISC00		0
#define ISC01		1
#define ISC10		2
#define ISC11		3


#define GICR	(*(volatile u8 *) GICR_u8Address  )
#define INT2		5
#define INT0		6
#define INT1		7

#define	INT0_Number		0
#define	INT1_Number		1
#define	INT2_Number		2


#define ExtInt_u8LowLevel		0
#define ExtInt_u8AnyChange		1
#define ExtInt_u8FallingEdge	3
#define ExtInt_u8RisingEdge		4

#define MCUCSR	(*(volatile u8 *) MCUCSR_u8Address)
#define ISC2  6

#if   ExtInt_u8SenseControl2==ExtInt_u8FallingEdge
#undef ExtInt_u8SenseControl2
#define	ExtInt_u8SenseControl2		(1<<ISC2)
#elif  ExtInt_u8SenseControl2==ExtInt_u8RisingEdge
#undef ExtInt_u8SenseControl2
#define	ExtInt_u8SenseControl2		(0<<ISC2)
#endif


/*
ISC01 ISC00
ISC11 ISC10 Description
0 		0 		The low level of INT1 generates an interrupt request.
0 		1 		Any logical change on INT1 generates an interrupt request.
1 		0 		The falling edge of INT1 generates an interrupt request.
1 		1 		The rising edge of INT1 generates an interrupt request.
*/
//ExtInt_u8(LowLevel - AnyChange - FallingEdge - RisingEdge)
	//a5tar ely anta 3aizo w lw ExtInt_u8Interrupt1 Disable 7t two zero w a5rg
#if ExtInt_u8SenseControl0==ExtInt_u8LowLevel||ExtInt_u8Interrupt0==ExtInt_u8DisEnable
   	#undef ExtInt_u8SenseControl0
	#define	ExtInt_u8SenseControl0   (0<<ISC01)|(0<<ISC00)
#elif  ExtInt_u8SenseControl0==ExtInt_u8AnyChange
	#undef ExtInt_u8SenseControl0
	#define	ExtInt_u8SenseControl0   (0<<ISC01)|(1<<ISC00)
#elif  ExtInt_u8SenseControl0==ExtInt_u8FallingEdge
	#undef ExtInt_u8SenseControl0
	#define	ExtInt_u8SenseControl0   (1<<ISC01)|(0<<ISC00)
#elif  ExtInt_u8SenseControl0==ExtInt_u8RisingEdge
	#undef ExtInt_u8SenseControl0
	#define	ExtInt_u8SenseControl0   (1<<ISC01)|(1<<ISC00)
#endif

//a5tar ely anta 3aizo w lw ExtInt_u8Interrupt0 Disable 7t two zero w a5rg
#if ExtInt_u8SenseControl1==ExtInt_u8LowLevel||ExtInt_u8Interrupt1==ExtInt_u8DisEnable
	#undef ExtInt_u8SenseControl1
	#define	ExtInt_u8SenseControl1   (0<<ISC11)|(0<<ISC10)
#elif  ExtInt_u8SenseControl1==ExtInt_u8AnyChange
	#undef ExtInt_u8SenseControl1
	#define	ExtInt_u8SenseControl1   (0<<ISC11)|(1<<ISC10)
#elif  ExtInt_u8SenseControl1==ExtInt_u8FallingEdge
	#undef ExtInt_u8SenseControl1
	#define	ExtInt_u8SenseControl1   (1<<ISC11)|(0<<ISC10)
#elif  ExtInt_u8SenseControl1==ExtInt_u8RisingEdge
	#undef ExtInt_u8SenseControl1
	#define	ExtInt_u8SenseControl1   (1<<ISC11)|(1<<ISC10)
#endif

#if ExtInt_u8Interrupt0==ExtInt_u8Enable
#undef ExtInt_u8Interrupt0
#define	ExtInt_u8Interrupt0		(1<<INT0)
#elif ExtInt_u8Interrupt0==ExtInt_u8DisEnable
#undef ExtInt_u8Interrupt0
#define	ExtInt_u8Interrupt0		(0<<INT0)
#endif

#if ExtInt_u8Interrupt1==ExtInt_u8Enable
#undef ExtInt_u8Interrupt1
#define	ExtInt_u8Interrupt1		(1<<INT1)
#elif ExtInt_u8Interrupt1==ExtInt_u8DisEnable
#undef ExtInt_u8Interrupt1
#define	ExtInt_u8Interrupt1		(0<<INT1)
#endif

#if ExtInt_u8Interrupt2==ExtInt_u8Enable
#undef ExtInt_u8Interrupt2
#define	ExtInt_u8Interrupt2		(1<<INT2)
#elif ExtInt_u8Interrupt2==ExtInt_u8DisEnable
#undef ExtInt_u8Interrupt2
#define	ExtInt_u8Interrupt2		(0<<INT2)
#endif



#endif /* EXTINT_PRIVATE_H_ */
