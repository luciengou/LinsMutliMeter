#ifndef	IO_DEFINE_h_ 
#define	IO_DEFINE_h_

sbit TC_C    = P0^0;	//k=0x00;j=0x01;t=0x02;e=0x03; 
sbit RTD_C   = P0^1;	//r=0x04;s=0x05;b=0x06;n=0x07;
sbit mV_C    = P0^2;
sbit mA_C    = P0^3;	 //tc= 000 00xxx;  rtd=000 01xxx;    mV=000 10xxx
sbit mV_OUT  = P0^4;	 //mA= 000 11xxx;
sbit mA_OUT  = P0^5;
sbit UP_KEY   = P0^6;
sbit DOWN_KEY = P0^7;

sbit LED1_SDA = P1^0;
sbit LED1_SCL = P1^2;
sbit LED1_LE  = P1^1;
sbit LED2_SDA  = P1^3;
sbit LED2_SCL  = P1^4;
sbit LED2_LE   = P1^5;
sbit RTC_SCL   = P1^6;
sbit non3      = P1^7;

sbit AD_SDA   = P2^0;
sbit AD_SCL   = P2^1;
sbit ALL_SDA  = P2^2;
sbit EEP_SCL  = P2^3;
sbit OUT_SCL  = P2^4;
sbit TEMP     = P2^5;
sbit NONE_4   = P2^6;
sbit NONE_5   = P2^7;
sbit RTC_SDA  = P2^2;

sbit R485_RX           = P3^0;
sbit R485_TX           = P3^1;
sbit FUNCTION_KEY      = P3^2;
sbit OFFSET_KEY        = P3^3;
sbit BEEP_OUT          = P3^4;	 //for relay
sbit R485_DE_RE        = P3^5;
sbit NONE_6            = P3^6;
sbit NONE_7            = P3^7;
//------------------------
sbit EEPROM_SDA	= P2^2;
sbit EEPROM_SCL	= P2^3;

sbit Value_SDA  = P2^0;
sbit Value_SCL  = P2^1;
sbit BEEP       = P3^4;	 //for relay

sbit mV_SDA   = P2^2;
sbit mV_SCL   = P2^4;
sbit mA_SDA   = P2^2;
sbit mA_SCL   = P2^4;

#endif
