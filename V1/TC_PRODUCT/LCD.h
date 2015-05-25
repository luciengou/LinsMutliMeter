#ifndef __LCD_H_
#define __LCD_H_


#define ON   1
#define OFF  0

#define LCD_Data P0
#define uchar unsigned char
#define  Lcm_max_line 0x29  //41


#define Purified  0x08
/************************/
#define Alkaline  0x01
#define Acidic    0x02
#define Error     0x03
#define WorkTable 0x04
/***********************/
#define C_wendu   0x01
#define SEC       0x02
#define __SHOW_LPM__	0x03


/***  COLOR SELECT  *******/
#define NOCOLOR   0x00
#define PURPLE    0x01	   //J4
#define BLUENESS  0x02      //J2
#define WHITE     0x03	   //J1
#define YELLOW    0x04	   //S1
#define BLUE      0x05	   //J3
#define ORANGE    0x06	   //S2
#define GREEN     0x07	   //Z
#define RED       0x08	   //no


void delay(int i);
void MoreDelay(int i);
void LCD_Latch_Write(void);
void PowerControlSet();
void PageAddressSet();

void ColumnAddressSet(unsigned char ColumnAddress);
void EnterModeSet();
void DutyModeSet();
void FinishModeSet();
void DisplayAllPointsOFF();
void DisplayAllPointsON();
void DisplayDataWrite(unsigned char Value);
void Lcd_Display_Count(unsigned long value);
void Lcd_Display_H(unsigned char value);
void Lcd_Backlight(unsigned char BacklightValue);

void LCDInit();
void lcd_all_off(void);
void lcd_display(unsigned char ColumnAddressBegin,unsigned ColumnAddressLast,unsigned char DisPlayValue);

void Lcd_DisplayFilterLife(unsigned long DisplayValue,unsigned char count,unsigned char status,unsigned char K_status);	//显示滤芯寿命
void Lcd_DisplayLock(bit status);   //显示lock
void Lcd_DisplayVolume(unsigned char Volume,bit status);   //显示音量大小
void Lcd_DisplayErrorWorkTable(unsigned char mode,unsigned char value,bit status);   //Error Or WorkTable
void Lcd_DisplayCSECLmin(unsigned char mode,unsigned int value,bit status);   //C SEC L/MIN
void Lcd_DisplayValue(unsigned char mode,unsigned long value,bit status,bit value_flag); //ph orp tds day,mv,ppm
void Lcd_DisplayPicture(unsigned char Value,bit status);   //r1 r2 r3 r4 r5 r6 

#endif
