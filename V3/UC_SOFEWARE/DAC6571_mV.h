/************************************************************************
* FileName     : i2c.h
* Description  : Default MPC82G516 to ctrl AD111A0 IC function.
*
*
* Version control:
***************************************************************************/
#ifndef __DAC6571_mV_H__
#define __DAC6571_mV_H__

void DAC6571mV_Init(void);
void DAC6571mV_start(void);
void DAC6571mV_stop(void);
void DAC6571mV_write_byte(unsigned char bt);
void mV_Delay(unsigned int n);
void Set_mV(unsigned int mV_Value);	  
void PlaySound(unsigned char num);

#define         TRUE	1
#define         FALSE	0

#endif 