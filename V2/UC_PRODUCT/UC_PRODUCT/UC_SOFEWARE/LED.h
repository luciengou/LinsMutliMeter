#ifndef	LED_h_ 
#define	LED_h_ 


void LED_Disp(unsigned char LEDs, unsigned long int disp_value);
void SETUP_LED_Disp(unsigned char SETUP_SELECT, unsigned int disp_value);
void LED_DATA_Write(unsigned char prt,unsigned char D5,unsigned char D4,unsigned char D3,unsigned char D2,unsigned char D1,unsigned char D0);
void _BitDly(void);
void LED_Init(void);
void LED_Cls(void);
void LED_Fill(void);
#endif