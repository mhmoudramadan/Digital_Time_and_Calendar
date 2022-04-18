/*
 * MTIMER0_Interface.h
 *
 *  Created on: Feb 12, 2022
 *      Author: Dell
 */

#ifndef MCAL_MTIMER0_MTIMER0_INTERFACE_H_
#define MCAL_MTIMER0_MTIMER0_INTERFACE_H_

void MTIMER0_VidInit(void);
void MTIMER0_VidSetPreLoad(uint8 copy_uint8PreLoad);
void MTIMER0_VidSetCTCRegister(uint8 copy_uint8CTCValue);
void MTIMER0_VidTimerOverFlow_SetCallBack(void (*PtrToFun)(void));
void MTIMER0_VidTimerCTC_SetCallBack(void (*PtrToFun)(void));
uint8 MTIMER0_uint32Read(void);
void MTIMER0_VidUpdateDutyCycle(uint8 copy_uintDutyCycle);
#endif /* MCAL_MTIMER0_MTIMER0_INTERFACE_H_ */
