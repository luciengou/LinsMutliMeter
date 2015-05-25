/********************************
**          RTC.DEVICE	   **
*********************************/
#ifndef __RTC3130_H
#define __RTC3130_H
void RTC_Delay(unsigned int i);
void RTC_BitDly(void);	
//void RTC_Init(void);
void RTC_start0(void);	
void RTC_stop0(void);
void RTC_restart0(void);
void RTC_write_byte0(unsigned char bt);
void RTC_write_byte(unsigned char reg_addr,unsigned char reg_data);
void RTC_write_word(unsigned char addr, unsigned int intdata);
unsigned char RTC_read_byte0(void);
unsigned char RTC_read_byte(unsigned char reg_addr);
unsigned int  RTC_read_word(unsigned char addr);
void RTC_WRITE_SET(void);
void RTC_READ_SET(void);
void RTC_ON(void);
void RTC_Write_Default(void);

#endif