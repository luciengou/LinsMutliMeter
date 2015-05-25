/************************************************************************
* FileName     : i2c.h
* Description  : Default MPC82G516 to ctrl AD111A0 IC function.
*
*
* Version control:
***************************************************************************/
#ifndef __AD3421_H__
#define __AD3421_H__


void AD3421_Init(void);
void AD3421_start(void);
void AD3421_stop(void);
void AD3421_write_byte(unsigned char bt);
unsigned char AD3421_read_byte(unsigned char lastbyte); 	
void AD3421_write_com(unsigned char dev_id, unsigned char reg_addr);
unsigned int AD3421_read_com(unsigned char dev_id, unsigned char reg_addr);
void S_Delay(unsigned int n);
unsigned int Get_AD3421_Value(void);

unsigned int  SetmA(unsigned int mA_Value);
unsigned int  SetmV(unsigned int mV_Value);	  


void DAC_write(unsigned char ch_id, unsigned int ma);
void Clear_key_delay(void);
unsigned char EEPROM_write(unsigned char reg_addr, unsigned int reg_data);
unsigned char	EEPROM_read_byte(unsigned char reg_addr);
unsigned char KeyScan(void);
unsigned char voicePlay(unsigned char id, unsigned char vol);
unsigned char Get_Key(void);

#define         TRUE	1
#define         FALSE	0

#endif 