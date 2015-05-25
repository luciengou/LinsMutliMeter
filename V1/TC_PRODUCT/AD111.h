/************************************************************************
* FileName     : i2c.h
* Description  : Default MPC82G516 to ctrl AD111A0 IC function.
*
*
* Version control:
***************************************************************************/
#ifndef __AD111_H__
#define __AD111_H__


//..void _i2cBitDly(void);
void AD111_Init(void);
void AD111_start(void);
void AD111_stop(void);
void AD111_write_byte(unsigned char bt);
unsigned char AD111_read_byte(unsigned char lastbyte); 	
void AD111_write_com(unsigned char dev_id, unsigned char reg_addr);
unsigned int AD111_read_com(unsigned char dev_id, unsigned char reg_addr);
void S_Delay(unsigned int n);
unsigned int Get_AD111_Value(void);

void  SetmA(void);
void  SetmV(void);	  


void DAC_write(unsigned char ch_id, unsigned int ma);
void LDS6128_init(void);
void PlaySound(unsigned char num);
void Clear_key_delay(void);
unsigned char EEPROM_write(unsigned char reg_addr, unsigned int reg_data);
unsigned char	EEPROM_read_byte(unsigned char reg_addr);
unsigned char KeyScan(void);
unsigned char voicePlay(unsigned char id, unsigned char vol);
unsigned char Get_Key(void);

#define         TRUE	1
#define         FALSE	0

#endif 