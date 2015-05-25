/********************************
**          EEPROM.DEVICE	   **
*********************************/
#ifndef __EEPROM_H
#define __EEPROM_H

void EEPROM_Delay(unsigned int i);
void EEPROM_BitDly(void);
void EEPROM_Init(void);
void EEPROM_start0(void);
void EEPROM_stop0(void);
void EEPROM_restart0(void);

void EEPROM_write_byte0(unsigned char bt);
void EEPROM_write_byte(unsigned char reg_addr,unsigned char reg_data);
void EEPROM_write_word(unsigned char addr, unsigned int intdata);

unsigned char EEPROM_read_byte0(void);
unsigned char EEPROM_read_byte(unsigned char reg_addr);
unsigned int  EEPROM_read_word(unsigned char addr);
void EEPROM_Write_Default(void);

#endif