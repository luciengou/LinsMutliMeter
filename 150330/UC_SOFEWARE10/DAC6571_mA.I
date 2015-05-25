
#line 1 "DAC6571_mA.C" /0









 
  
#line 1 "C:\KEIL\C51\INC\MEGAWIN\MG82FE564.H" /0
 
 sfr ACC       = 0xE0;
 sfr B         = 0xF0;
 sfr SP        = 0x81;
 sfr DPL       = 0x82;
 sfr DPH       = 0x83;
 sfr PSW       = 0xD0;
 
 
 sfr IE        = 0xA8;
 sfr EIE1      = 0xAD;
 sfr AUXIE     = 0xAD;
 sfr XICON     = 0xC0;
 sfr IP0L      = 0xB8;
 sfr IP        = 0xB8;
 sfr IP0H      = 0xB7;
 sfr IPH       = 0xB7;
 sfr EIP1L     = 0xAE;
 sfr AUXIP     = 0xAE;
 sfr EIP1H     = 0xAF;
 sfr AUXIPH    = 0xAF;
 
 
 sfr P0        = 0x80;
 sfr P1        = 0x90;
 sfr P2        = 0xA0;
 sfr P3        = 0xB0;
 sfr P4        = 0xE8;
 sfr P5        = 0xF8;
 sfr P6        = 0xC8;                             
 sfr P0M0      = 0x93;
 sfr P0M1      = 0x94;
 sfr P1M0      = 0x91;
 sfr P1M1      = 0x92;
 sfr P2M0      = 0x95;
 sfr P2M1      = 0x96;
 sfr P3M0      = 0xB1;
 sfr P3M1      = 0xB2;
 sfr P4M0      = 0xB3;
 sfr P4M1      = 0xB4;
 sfr P5M0      = 0xB5;
 sfr P5M1      = 0xB6;
 
 
 sfr TCON      = 0x88;
 sfr TMOD      = 0x89;
 sfr T2CON     = 0xC8;
 sfr T2MOD     = 0xC9;
 sfr RCAP2L    = 0xCA;
 sfr RCAP2H    = 0xCB;
 sfr TL0       = 0x8A;
 sfr TL1       = 0x8B;
 sfr TH0       = 0x8C;
 sfr TH1       = 0x8D;
 sfr TL2       = 0xCC;
 sfr TH2       = 0xCD;
 
 
 sfr SCON      = 0x98;
 sfr SCON0     = 0x98;
 sfr SCON1     = 0x98;                             
 sfr SBUF      = 0x99;
 sfr SBUF0     = 0x99;
 sfr SBUF1     = 0x99;                             
 sfr SADDR     = 0xA9;
 sfr SADEN     = 0xB9;
 sfr SCFG      = 0x9A;
 sfr S1BRT     = 0x9A;
 sfr S2BUF     = 0x9A;                             
 
 
 sfr ADCON     = 0xC5;
 sfr ADCTL     = 0xC5;
 sfr ADCV      = 0xC6;
 sfr ADCH      = 0xC6;
 sfr ADCVL     = 0xBE;
 sfr ADCL      = 0xBE;
 
 
 sfr KBCON     = 0xD6;
 sfr KBPATN    = 0xD5;
 sfr KBMASK    = 0xD7;
 
 
 sfr SPSTAT    = 0x84;
 sfr SPCON     = 0x85;
 sfr SPDAT     = 0x86;
 sfr SPISTAT   = 0x84;
 sfr SPICON    = 0x85;
 sfr SPIDAT    = 0x86;
 sfr SPCTL     = 0x85;
 sfr SPICTL    = 0x85;
 
 
 sfr CCON      = 0xD8;
 sfr CMOD      = 0xD9;
 sfr CL        = 0xE9;
 sfr CH        = 0xF9;
 sfr CCAPM0    = 0xDA;
 sfr CCAPM1    = 0xDB;
 sfr CCAPM2    = 0xDC;
 sfr CCAPM3    = 0xDD;
 sfr CCAPM4    = 0xDE;
 sfr CCAPM5    = 0xDF;
 sfr CCAP0H    = 0xFA;
 sfr CCAP0L    = 0xEA;
 sfr CCAP1H    = 0xFB;
 sfr CCAP1L    = 0xEB;
 sfr CCAP2H    = 0xFC;
 sfr CCAP2L    = 0xEC;
 sfr CCAP3H    = 0xFD;
 sfr CCAP3L    = 0xED;
 sfr CCAP4H    = 0xFE;
 sfr CCAP4L    = 0xEE;
 sfr CCAP5H    = 0xFF;
 sfr CCAP5L    = 0xEF;
 sfr PCAPWM0   = 0xF2;
 sfr PCAPWM1   = 0xF3;
 sfr PCAPWM2   = 0xF4;
 sfr PCAPWM3   = 0xF5;
 sfr PCAPWM4   = 0xF6;
 sfr PCAPWM5   = 0xF7;
 
 
 sfr PCON      = 0x87;
 sfr PCON0     = 0x87;
 sfr PCON1     = 0x97;
 sfr EVRCR     = 0x97;
 sfr PCON2     = 0xC7;
 sfr AUXR      = 0x8E;
 sfr AUXR0     = 0x8E;
 sfr AUXR1     = 0xA2;
 sfr AUXR2     = 0xA6;
 sfr STRETCH   = 0x8F;
 sfr WDTCR     = 0xE1;
 sfr TSTWD     = 0x97;
 sfr SFRPI     = 0xAC;
 
 
 sfr ISPCR     = 0xE7;
 sfr IFMT      = 0xE5;
 sfr IFD       = 0xE2;
 sfr IFADRH    = 0xE3;
 sfr IFADRL    = 0xE4;
 sfr SCMD      = 0xE6;
 
 
 sbit CY       = PSW^7;
 sbit AC       = PSW^6;
 sbit F0       = PSW^5;
 sbit RS1      = PSW^4;
 sbit RS0      = PSW^3;
 sbit OV       = PSW^2;
 sbit F1       = PSW^1;
 sbit P        = PSW^0;
 
 
 sbit EA       = IE^7;
 sbit GF4      = IE^6;
 sbit ET2      = IE^5;
 sbit ES       = IE^4;
 sbit ES0      = IE^4;
 sbit ET1      = IE^3;
 sbit EX1      = IE^2;
 sbit ET0      = IE^1;
 sbit EX0      = IE^0;
 
 
 sbit PX3L     = IP0L^7;
 sbit PX2L     = IP0L^6;
 sbit PT2L     = IP0L^5;
 sbit PSL      = IP0L^4;
 sbit PT1L     = IP0L^3;
 sbit PX1L     = IP0L^2;
 sbit PT0L     = IP0L^1;
 sbit PX0L     = IP0L^0;
 
 sbit PT2      = IP^5;
 sbit PS       = IP^4;
 sbit PT1      = IP^3;
 sbit PX1      = IP^2;
 sbit PT0      = IP^1;
 sbit PX0      = IP^0;
 
 
 sbit FE       = SCON0^7;
 sbit SM00     = SCON0^7;
 sbit SM10     = SCON0^6;
 sbit SM20     = SCON0^5;
 sbit REN0     = SCON0^4;
 sbit TB80     = SCON0^3;
 sbit RB80     = SCON0^2;
 sbit TI0      = SCON0^1;
 sbit RI0      = SCON0^0;
 
 sbit SM0      = SCON^7;
 sbit SM1      = SCON^6;
 sbit SM2      = SCON^5;
 sbit REN      = SCON^4;
 sbit TB8      = SCON^3;
 sbit RB8      = SCON^2;
 sbit TI       = SCON^1;
 sbit RI       = SCON^0;
 
 
 sbit SM01     = SCON1^7;
 sbit SM11     = SCON1^6;
 sbit SM21     = SCON1^5;
 sbit REN1     = SCON1^4;
 sbit TB81     = SCON1^3;
 sbit RB81     = SCON1^2;
 sbit TI1      = SCON1^1;
 sbit RI1      = SCON1^0;
 
 
 sbit TF1      = TCON^7;
 sbit TR1      = TCON^6;
 sbit TF0      = TCON^5;
 sbit TR0      = TCON^4;
 sbit IE1      = TCON^3;
 sbit IT1      = TCON^2;
 sbit IE0      = TCON^1;
 sbit IT0      = TCON^0;
 
 
 sbit TF2      = T2CON^7;
 sbit EXF2     = T2CON^6;
 sbit RCLK     = T2CON^5;
 sbit TCLK     = T2CON^4;
 sbit EXEN2    = T2CON^3;
 sbit TR2      = T2CON^2;
 sbit C_T2     = T2CON^1;
 sbit CP_RL2   = T2CON^0;
 
 
 sbit CF       = CCON^7;
 sbit CR       = CCON^6;
 sbit CCF5     = CCON^5;
 sbit CCF4     = CCON^4;
 sbit CCF3     = CCON^3;
 sbit CCF2     = CCON^2;
 sbit CCF1     = CCON^1;
 sbit CCF0     = CCON^0;
 
 
 sbit PX3      = XICON^7;
 sbit IT3H     = XICON^7;
 sbit EX3      = XICON^6;
 sbit IE3      = XICON^5;
 sbit IT3      = XICON^4;
 sbit PX2      = XICON^3;
 sbit IT2H     = XICON^3;
 sbit EX2      = XICON^2;
 sbit IE2      = XICON^1;
 sbit IT2      = XICON^0;
 
 
 sbit P07      = P0^7;
 sbit P06      = P0^6;
 sbit P05      = P0^5;
 sbit P04      = P0^4;
 sbit P03      = P0^3;
 sbit P02      = P0^2;
 sbit P01      = P0^1;
 sbit P00      = P0^0;
 
 
 sbit P17      = P1^7;
 sbit P16      = P1^6;
 sbit P15      = P1^5;
 sbit P14      = P1^4;
 sbit P13      = P1^3;
 sbit P12      = P1^2;
 sbit P11      = P1^1;
 sbit P10      = P1^0;
 
 
 sbit P27      = P2^7;
 sbit P26      = P2^6;
 sbit P25      = P2^5;
 sbit P24      = P2^4;
 sbit P23      = P2^3;
 sbit P22      = P2^2;
 sbit P21      = P2^1;
 sbit P20      = P2^0;
 
 
 sbit P37      = P3^7;
 sbit P36      = P3^6;
 sbit P35      = P3^5;
 sbit P34      = P3^4;
 sbit P33      = P3^3;
 sbit P32      = P3^2;
 sbit P31      = P3^1;
 sbit P30      = P3^0;
 
 
 sbit P47      = P4^7;
 sbit P46      = P4^6;
 sbit P45      = P4^5;
 sbit P44      = P4^4;
 sbit P43      = P4^3;
 sbit P42      = P4^2;
 sbit P41      = P4^1;
 sbit P40      = P4^0;
 
 
 sbit P53      = P5^3;
 sbit P52      = P5^2;
 sbit P51      = P5^1;
 sbit P50      = P5^0;
 
 
 sbit P61      = P6^1;
 sbit P60      = P6^0;
 
 
 sbit T2EX     = P1^1;
 sbit T2       = P1^0;
 sbit S2TXD    = P1^3;
 sbit S2RXD    = P1^2;
 
 sbit SPI_CLK  = P1^7;
 sbit SPI_MISO = P1^6;
 sbit SPI_MOSI = P1^5;
 sbit SPI_SS   = P1^4;
 
 sbit CEX5     = P1^7;
 sbit CEX4     = P1^6;
 sbit CEX3     = P1^5;
 sbit CEX2     = P1^4;
 sbit CEX1     = P1^3;
 sbit CEX0     = P1^2;
 sbit ECI      = P1^1;
 
 sbit AIN7     = P1^7;
 sbit AIN6     = P1^6;
 sbit AIN5     = P1^5;
 sbit AIN4     = P1^4;
 sbit AIN3     = P1^3;
 sbit AIN2     = P1^2;
 sbit AIN1     = P1^1;
 sbit AIN0     = P1^0;
 
 
 sbit KBI7     = P2^7;
 sbit KBI6     = P2^6;
 sbit KBI5     = P2^5;
 sbit KBI4     = P2^4;
 sbit KBI3     = P2^3;
 sbit KBI2     = P2^2;
 sbit KBI1     = P2^1;
 sbit KBI0     = P2^0;
 
 
 sbit RD       = P3^7;
 sbit WR       = P3^6;
 sbit T1       = P3^5;
 sbit T0       = P3^4;
 sbit INT1     = P3^3;
 sbit INT0     = P3^2;
 sbit TXD      = P3^1;
 sbit RXD      = P3^0;
 sbit T1CKO    = P3^5;
 sbit T0CKO    = P3^4;
 
 
 sbit INT2     = P4^3;
 sbit INT3     = P4^2;
 
 sbit ALE      = P4^6;
 
 
 sbit CKO      = P6^0;
 sbit XOUT     = P6^0;
 sbit XIN      = P6^1;
#line 11 "DAC6571_mA.C" /0
 
  
#line 1 "DAC6571_mA.h" /0






 
 
 
 
 
 void DAC6571mA_Init(void);
 void DAC6571mA_start(void);
 void DAC6571mA_stop(void);
 void DAC6571mA_write_byte(unsigned char bt);
 void mA_Delay(unsigned int n);
 void Set_mA(unsigned int mA_Value);
 
 
 
 
 
#line 12 "DAC6571_mA.C" /0
 
  
#line 1 "IO_DEFINE.h" /0
 
 
 
 sbit TC_C    = P0^0;	 
 sbit RTD_C   = P0^1;	 
 sbit mV_C    = P0^2;
 sbit mA_C    = P0^3;	  
 sbit mV_OUT  = P0^4;	  
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
 sbit TEMP    = P2^5;
 sbit NONE_4   = P2^6;
 sbit NONE_5   = P2^7;
 sbit RTC_SDA  = P2^2;
 
 sbit R485_RX           = P3^0;
 sbit R485_TX           = P3^1;
 sbit FUNCTION_KEY      = P3^2;
 sbit OFFSET_KEY        = P3^3;
 sbit BEEP_OUT          = P3^4;	  
 sbit R485_DE_RE        = P3^5;
 sbit NONE_6            = P3^6;
 sbit NONE_7            = P3^7;
 
 sbit EEPROM_SDA	= P2^2;
 sbit EEPROM_SCL	= P2^3;
 
 sbit Value_SDA  = P2^0;
 sbit Value_SCL  = P2^1;
 sbit BEEP       = P3^4;	  
 
 sbit mV_SDA   = P2^2;
 sbit mV_SCL   = P2^4;
 sbit mA_SDA   = P2^2;
 sbit mA_SCL   = P2^4;
 
 
#line 13 "DAC6571_mA.C" /0
 
 
 
 unsigned char  _mA_ack;       
 extern unsigned char  NP_COD ;
 extern unsigned char Value_Hi,Value_Lo;
 extern void delay(unsigned int i);
 extern idata unsigned char Soft_Timer[8];
 
 
 void _mABitDly(void)                
 {                                    
 unsigned char	k;
 
 for (k=0; k<0x12; k++);
 }
 
 void DAC6571mA_Init(void)
 {
 unsigned int i;
 mA_SCL = 1 ;
 _mABitDly();
 mA_SDA = 1 ;
 _mABitDly();
 _mABitDly();
 _mABitDly();
 _mABitDly();
 mA_SDA = 0;
 
 for(i = 0; i < 0x100; i++);    
 }
 
 void DAC6571mA_start(void)
 {
 mA_SDA = 1 ;
 _mABitDly();
 mA_SCL = 1 ;
 _mABitDly();
 mA_SDA = 0 ;
 _mABitDly();
 mA_SCL = 0 ;
 }
 
 void DAC6571mA_stop(void)
 {
 mA_SCL = 1 ;
 _mABitDly();
 mA_SDA = 1 ;
 _mABitDly();
 }
 
 void DAC6571mA_write_byte(unsigned char bt)
 {
 idata unsigned char i;
 
 _mA_ack = 1;						 
 
 for (i=0; i<8; i++)
 {
 if (bt & 0x80)
 mA_SDA = 1;                       
 else
 mA_SDA = 0;
 mA_SCL = 1;
 _mABitDly();
 mA_SCL = 0;
 _mABitDly();
 bt = bt << 1;
 }
 
 mA_SDA = 1;                        
 mA_SCL = 1;
 _mABitDly();
 if (mA_SDA)
 _mA_ack = 0;             		 
 mA_SCL = 0;
 _mABitDly();
 }
 
 void Set_mA(unsigned int mA_Value)
 {
 unsigned char HI_CODE, LO_CODE;			 
 
 if(NP_COD == 0) 
 {mA_Value = mA_Value/10;}   
 
 LO_CODE = mA_Value ;
 HI_CODE = mA_Value >> 8 ;			 
 HI_CODE = HI_CODE &0x0f;
 DAC6571mA_start();								 
 DAC6571mA_write_byte(0x98);
 DAC6571mA_write_byte(HI_CODE);                
 DAC6571mA_write_byte(LO_CODE);                
 DAC6571mA_stop();                               
 }
 
 void mA_Delay(unsigned int n)
 {
 while(n--);
 }
 
