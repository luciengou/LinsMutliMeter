
#line 1 "main.c" /0








 
  
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
#line 10 "main.c" /0
 
  
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
 
 
#line 11 "main.c" /0
 
  
#line 1 "LED.h" /0
 
 
 
 
 void LED_Disp(unsigned char LEDs, unsigned  int disp_value);
 void SETUP_LED_Disp(unsigned char SETUP_SELECT, unsigned int disp_value);
 void LED_DATA_Write(unsigned char prt,unsigned char D5,unsigned char D4,unsigned char D3,unsigned char D2,unsigned char D1,unsigned char D0);
 void DAY_LED_Disp(unsigned char DD,unsigned char HH, unsigned char MM);
 void LED_Init(void);
 void LED_Cls(void);
 void LED_Fill(void);
 
#line 12 "main.c" /0
 
  
#line 1 "AD3421.h" /0






 
 
 
 
 
 void AD3421_Init(void);
 void AD3421_start(void);
 void AD3421_stop(void);
 void AD3421_write_byte(unsigned char bt);
 unsigned char AD3421_read_byte(unsigned char lastbyte); 	
 void AD3421_write_com(unsigned char dev_id, unsigned char reg_addr);
 unsigned char AD3421_read_com(unsigned char dev_id);
 void S_Delay(unsigned int n);
 unsigned char Get_AD3421_Value(void);
 
 unsigned int  SetmA(unsigned int mA_Value);
 unsigned int  SetmV(unsigned int mV_Value);	  
 
 
 void DAC_write(unsigned char ch_id, unsigned int ma);
 void Clear_key_delay(void);
 unsigned char EEPROM_write(unsigned char reg_addr, unsigned int reg_data);
 unsigned char	EEPROM_read_byte(unsigned char reg_addr);
 unsigned char KeyScan(void);
 unsigned char voicePlay(unsigned char id, unsigned char vol);
 unsigned char Get_Key(void);
 
 
 
 
 
#line 13 "main.c" /0
 
  
#line 1 "DAC6571_mV.h" /0






 
 
 
 
 void DAC6571mV_Init(void);
 void DAC6571mV_start(void);
 void DAC6571mV_stop(void);
 void DAC6571mV_write_byte(unsigned char bt);
 void mV_Delay(unsigned int n);
 void Set_mV(unsigned int mV_V);	  
 
 
 
 
 
#line 14 "main.c" /0
 
  
#line 1 "DAC6571_mA.h" /0






 
 
 
 
 
 void DAC6571mA_Init(void);
 void DAC6571mA_start(void);
 void DAC6571mA_stop(void);
 void DAC6571mA_write_byte(unsigned char bt);
 void mA_Delay(unsigned int n);
 void Set_mA(unsigned int mA_Value);
 
 
 
 
 
#line 15 "main.c" /0
 
  
#line 1 "MCP79411.h" /0


 
 
 
 
 void RTC_Delay(unsigned int i);
 void RTC_BitDly(void);	
 
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
 
 
#line 16 "main.c" /0
 
  
#line 1 "EEPROM.H" /0


 
 
 
 
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
 
 
#line 17 "main.c" /0
 
  
#line 1 "C:\KEIL\C51\INC\STDLIB.H" /0






 
 
 
 
 
 
 
 
 typedef unsigned int size_t;
 
 
 
 
 
 
 
 
 
 typedef char wchar_t;
 
 
 
 
 
 
 #pragma SAVE
 #pragma REGPARMS
 
 extern int    abs  (int   val);
 extern long  labs  (long  val);
 
 extern float atof (char *s1);
 extern long  atol (char *s1);
 extern int   atoi (char *s1);
 extern int   rand ();
 extern void  srand (int);
 
 extern float         strtod  (char *, char **);
 extern long          strtol  (char *, char **, unsigned char);
 extern unsigned long strtoul (char *, char **, unsigned char);
 
 
 
 extern void init_mempool          (void xdata *p, unsigned int size);
 extern void xdata *malloc  (unsigned int size);
 extern void free                  (void xdata *p);
 extern void xdata *realloc (void xdata *p, unsigned int size);
 extern void xdata *calloc  (unsigned int size, unsigned int len);
 
 #pragma RESTORE
 
 
#line 18 "main.c" /0
 
  
#line 1 "TYPE_SLOPE.H" /0



 
 
 
 
 unsigned int Get_K_Slope(unsigned  int kt);
 unsigned int Get_J_Slope(unsigned  int jt);
 unsigned int Get_T_Slope(unsigned  int ts);
 unsigned int Get_E_Slope(unsigned  int et);
 unsigned int Get_R_Slope(unsigned  int rt);
 unsigned int Get_S_Slope(unsigned  int st);
 unsigned int Get_B_Slope(unsigned  int bt);
 unsigned int Get_N_Slope(unsigned  int nt); 
 unsigned int Get_RTD_Slope(unsigned int rtd);
 unsigned int DO_RTD_TYPE(void);
 unsigned int Read_AD3421_Value(void);
 unsigned int Check_Type_Offset(unsigned int ss);
 
#line 19 "main.c" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 extern unsigned char key = 0,key_bak = 0;
 extern unsigned char AV_COD ;
 extern unsigned char NP_COD ;
 unsigned char NG_COD,ADD_COD;
 unsigned char OVER_COD = 0 ;
 idata unsigned char Soft_Timer[9] = {16,16,4,2,59,2,20,30,2};
 idata unsigned char T0_cnt,T2_cnt, T1_cnt;
 idata unsigned char Temp_Flag = 3 ;
 idata unsigned int   Data_Value[10] ;
 unsigned int  Temp_sp = 0 ;
 unsigned char MAIN_SW;
 unsigned char Work_Type;
 unsigned char C_F_Type;
 unsigned char TC_Type;
 unsigned int  TC_Zero_offset;
 unsigned int  TC_Span_offset;
 unsigned int  RTD_Zero_offset;
 unsigned int  RTD_Span_offset;
 unsigned int  mV_Zero_offset;
 unsigned int  mV_Span_offset;
 unsigned int  mA_Zero_offset;
 unsigned int  mA_Span_offset;
 unsigned int  alarm_Low_set;
 unsigned int  alarm_Hi_set;
 unsigned int  TC_Span_Value = 0;
 unsigned int  RTD_Span_Value = 0;
 unsigned int  mV_Span_Value = 0;
 unsigned int  mA_Span_Value = 0;
 unsigned int  Temp_offset = 0 ; 
 unsigned int  Temp_m = 0 ;  
 unsigned int  use_flag;
 unsigned char  use_year = 0x14;
 unsigned char  use_mon  = 0x01;
 unsigned char  use_day  = 0x01;
 unsigned char  use_week = 0x03;
 unsigned char  use_hour = 0x12;
 unsigned char  use_min  = 0x01;
 unsigned char  use_sec  = 0x01;
 
 unsigned int   Disp_year;
 unsigned char  n_code = 0 ;
 unsigned char CAIT = 0x01;
 unsigned char Func_Type;
 unsigned char AD_Hi;
 unsigned char AD_Mid;
 unsigned char AD_Lo;
 unsigned char AD_Status;
 unsigned char PCB_SETUP;
 unsigned char Soft_Timer_Enable = 0;
 unsigned char Key_backup, ReceiveDate;
 
 bit f_half_sec;
 bit ReceiveFlag = 0;
 bit tran = 0 ;
 bit Zero_f = 0 ;


 
 void PORT_Init(void)
 {
 P0M0 = 0xFF;	   
 P0M1 = 0x00;	  
 P0   = 0xff;
 
 P1M0 = 0x00;	  
 P1M1 = 0xFF;      
 P1   = 0x00;
 
 P2M0 = 0x04;	  
 P2M1 = 0xDF; 	  
 P2   = 0x00;
 
 P3M0 = 0xED;	  
 P3M1 = 0x13;
 P3   = 0x2C;
 }


 
 void ex_int0(void) interrupt 0
 {;
 }


 
 void time0(void) interrupt  1      
 {
 unsigned int Value_code;
 TR0 = 0;
 T1_cnt++;
 if ((T1_cnt%8)==0)
 Value_code = SBUF;
 TH0 = 0x0B;	  
 TL0 = 0xDC;
 TR0 = 1;
 }
 


 
 void time1(void) interrupt  3    
 {
 TR1 = 0;
 T0_cnt++;							
 
 if (Soft_Timer[0] != 0)		Soft_Timer[0]--;
 if (Soft_Timer[1] != 0)         Soft_Timer[1]--;
 if ((T0_cnt%8)==0)	
 {
 if (Soft_Timer[2] != 0)	Soft_Timer[2]--;
 f_half_sec = 1;
 }
 if (T0_cnt == 15)
 {
 T0_cnt = 0;
 if (Soft_Timer[4] != 0)	Soft_Timer[4]--;
 if (Soft_Timer[5] != 0)	    Soft_Timer[5]--;
 if (Soft_Timer[6] != 0)     Soft_Timer[6]--;	
 if (Soft_Timer[7] != 0)		Soft_Timer[7]--;
 if (Soft_Timer[8] != 0)		    Soft_Timer[8]--;
 }	    	
 TH1 = 0x0B;
 TL1 = 0xDC;
 TR1 = 1;
 }		
 
 void T0_Init(void)
 {
 TR0 = 1;
 TMOD = 0x11;
 TH0 = 0x0B;		
 TL0 = 0xDC;	
 T0_cnt = 0;
 }


 
 void T1_Init(void)
 {
 TR1 = 0;
 TMOD = 0x11;  
 TH1 = 0x0B;
 TL1 = 0xDC;
 T1_cnt = 0;
 }


 
 void T2_Init(void)
 {
 TR2 = 1;
 T2MOD = 0x11;   
 TH2 = 0x0B;
 TL2 = 0xDC;
 T2_cnt = 0;
 }


 
 void INT0_Init(void)
 {
 INT0 = 1;
 INT1 = 1;	 
 IE0  = 1;		   
 IT0  = 1;
 EX0  = 0;	  
 }
 
 void InitUart()	    
 {
 SCON |= 0x50;			   
 T2CON &= 0xF0;                
 T2CON |= 0x30;                
 TH2=0xFF;                     
 TL2=0xD0;                     
 RCAP2H=0xFF;                  
 RCAP2L=0xDC;                 
 ES = 1; 						      
 TR2 = 1;                      
 }
 
 void serial() interrupt 4
 {
 if(TI==1)
 {
 TI = 0 ;
 }		   
 if(RI==1)
 {
 RI=0;
 ReceiveDate = SBUF;
 ReceiveFlag = 1;
 }
 }
 
 void delay(unsigned int i)
 {
 unsigned char j;
 for (; i>0; i--)
 for (j=0; j<255; j++);
 }


 
 void Buzzer(unsigned char status)
 {
 if (status)
 P3 = 	P3 |= 0x10;
 else
 P3 = P3 &= ~0x10;
 }


 
 void Check_PCB(void)
 {
 if(P00 == 0)                 
 {
 Work_Type = 0x00;
 Func_Type = 0x00;
 PCB_SETUP = 0x01;
 if(P04 == 0)	     
 {PCB_SETUP = 0x11 ;}
 if(P05 == 0)	 
 {PCB_SETUP = 0x21 ;}
 if(use_flag == 0x0001) { NG_COD = 1;}
 }
 else if(P01 == 0)	        
 {
 Work_Type = 0x01;
 Func_Type = 0x01;
 PCB_SETUP = 0x02 ;
 if(P04 == 0)	 
 {PCB_SETUP = 0x12 ;}
 if(P05 == 0)	 
 {PCB_SETUP = 0x22 ;}
 if(use_flag == 0x0002) { NG_COD = 1;}
 }
 else if(P02 == 0)	      
 {
 Work_Type = 0x02 ;
 Func_Type = 0x02;
 PCB_SETUP = 0x04 ;
 if(P04 == 0)	 
 {PCB_SETUP = 0x14 ;}
 if(P05 == 0)	 
 {PCB_SETUP = 0x24 ;}
 if(use_flag == 0x0004) { NG_COD = 1;}
 } 
 else if(P03 == 0)	         
 { 
 Work_Type = 0x03 ;
 Func_Type = 0x03;
 PCB_SETUP = 0x08 ;
 if(P04 == 0)	         
 {PCB_SETUP = 0x18 ;}
 if(P05 == 0)	 
 {PCB_SETUP = 0x28 ;}
 if(use_flag == 0x0008) { NG_COD = 1;}  
 }
 }
 
 unsigned int TEMP_F_TO_C(unsigned int tc_tmp)
 {
 unsigned int ttmp;
 
 if(NP_COD == 1)
 {
 if(tc_tmp >= 32)
 {
 if(AV_COD == 0)
 {
 ttmp = (tc_tmp-32)/1.8;
 }
 else
 {
 ttmp = (tc_tmp+32)/1.8; 
 }
 }
 else
 {
 if(AV_COD == 0)
 {
 ttmp = (32-tc_tmp)/1.8;
 AV_COD = 1 ;
 }
 else
 {
 ttmp = (32+tc_tmp)/1.8;
 
 }
 }
 }
 else
 {		  
 if(tc_tmp >= 320)
 {
 if(AV_COD == 0)
 {
 ttmp = (tc_tmp-320)/1.8;
 }
 else
 {
 ttmp = (tc_tmp+320)/1.8; 
 }
 }
 else
 {
 if(AV_COD == 0)
 {
 ttmp = (320-tc_tmp)/1.8;
 AV_COD = 1 ;
 }
 else
 {
 ttmp = (320+tc_tmp)/1.8;
 }
 }
 }
 return(ttmp);
 }
 
 void Volt_Ctrl(void)
 {
 }





 
 unsigned int Temp_Read(void)
 {
 unsigned int Temp_Count,P_count;
 TEMP = 1;
 P_count = 0;
 delay(1);
 while(TEMP)
 { ; P_count = P_count + 1 ;}	  
 TEMP = 0 ;
 if(P_count >= 0x7010){Temp_Count = 0;}	  
 else{ Temp_Count = ( 0x7010 - P_count)/19.4;  
 if(Temp_Count > 121)
 { Temp_Count = Temp_Count-(Temp_Count-120)/12 ;  
 if(Temp_Count > 252)
 { Temp_Count = Temp_Count + (Temp_Count-251)/20 ;
 if(Temp_Count > 281)
 { Temp_Count = Temp_Count-(Temp_Count-280)/18 ;
 if(Temp_Count > 401)			   
 { Temp_Count = Temp_Count + (Temp_Count-400)/28;
 if(Temp_Count > 541)
 { Temp_Count = Temp_Count+(Temp_Count-540)/15; 
 if(Temp_Count > 641)
 { Temp_Count = Temp_Count+(Temp_Count-640)/16;
 if(Temp_Count > 731)						   
 { Temp_Count = Temp_Count+(Temp_Count-730)/11;	 
 if(Temp_Count > 861)
 { Temp_Count = Temp_Count+(Temp_Count-860)/8;
 if(Temp_Count > 941)
 { Temp_Count = Temp_Count+(Temp_Count-940)/14;
 if(Temp_Count > 1011)
 { Temp_Count = Temp_Count+(Temp_Count-1010)/10; 
 if(Temp_Count > 1041)
 { Temp_Count = Temp_Count-(Temp_Count-1040)/14;
 if(Temp_Count > 1081)
 { Temp_Count = Temp_Count+(Temp_Count-1080)/5;
 if(Temp_Count > 1181)
 { Temp_Count = Temp_Count+(Temp_Count-1180)/9;
 if(Temp_Count > 1271)
 { Temp_Count = Temp_Count+(Temp_Count-1270)/10;
 if(Temp_Count > 1361)
 { Temp_Count = Temp_Count+(Temp_Count-1360)/6;
 if(Temp_Count > 1491)
 { Temp_Count = Temp_Count + (Temp_Count-1490)/8;
 if(Temp_Count > 1541)
 { Temp_Count = Temp_Count + (Temp_Count-1540)/4;
 if(Temp_Count > 1726)
 { Temp_Count = Temp_Count+(Temp_Count-1720)/10;
 }}}}}}}}}} }}}}}}} }
 }
 return(Temp_Count);
 }
 
 unsigned char Get_Key(void)
 {
 if(FUNCTION_KEY == 1 && OFFSET_KEY == 1 && UP_KEY == 1 && DOWN_KEY == 1) 
 {
 key_bak  =  0;
 key = 0 ; 
 }
 else if(FUNCTION_KEY == 0 )
 {
 if(key_bak == 0)
 {
 key_bak = 1 ;
 key = key |= 0x01 ;
 }
 else
 {
 key = key &= 0xfe ;
 }
 }
 else if(OFFSET_KEY == 0)
 {
 if(key_bak == 0)
 {
 key = key |= 0x02 ;
 key_bak = 1; 
 }
 else
 {
 key = key &= 0xfd ;
 }
 }
 else if(UP_KEY == 0)
 {
 if(key_bak == 0)
 {
 key = key |= 0x04 ;
 key_bak = 1; 
 }
 else
 {
 key = key &= 0xfb ;
 }
 }
 else if(DOWN_KEY == 0)
 {
 if(key_bak == 0)
 {
 key = key |= 0x08;
 key_bak = 1; 
 }
 else
 {
 key = key &= 0xf7 ;
 }
 }
 
 return key;
 }


 
 unsigned  int DO_TC_TYPE(void)
 {
 unsigned int Code_Value,TC_Value,TT_Value,TA_Value ;
 unsigned char key;
 key = Get_Key();
 if(key == 0x01)
 { Func_Type = 4;
 if(Temp_Flag != 0)  Func_Type = 0;
 }
 else
 { 
 if(Temp_Flag != 0 ){Temp_m = Temp_offset;}
 if (Soft_Timer[8] == 0)
 {
 Soft_Timer[8] = 8;
 Data_Value[n_code] = Temp_Read() ;
 if(n_code < 4){n_code++;}
 else{ Temp_m = (Data_Value[3]+Data_Value[2]+Data_Value[1]+Data_Value[0])/4 ;
 n_code = 0 ;
 if(Temp_Flag != 0){Temp_Flag-- ;} }
 }
 if (Soft_Timer[1] == 0) 
 {
 Soft_Timer[1] = 8;
 Code_Value =  Read_AD3421_Value();
 
 if (TC_Type == 0)
 { 
 Temp_sp = (Temp_m*24)/10;
 TT_Value = Check_Type_Offset(Code_Value); 
 TC_Value = Get_K_Slope(TT_Value);
 TT_Value = TC_Value/48.8 ;
 TA_Value = (TC_Value/38+163) ;
 if (C_F_Type == 0) TC_Value = TEMP_F_TO_C(TC_Value);  
 }
 else if (TC_Type == 1)
 {	
 Temp_sp = (Temp_m*30)/10;	  
 TT_Value = Check_Type_Offset(Code_Value);
 TC_Value = Get_J_Slope(TT_Value);
 TT_Value = TC_Value/27.4 ;
 TA_Value = (TC_Value/21.4+163) ;
 if (C_F_Type == 0) TC_Value = TEMP_F_TO_C(TC_Value);  
 }
 else if (TC_Type == 2)
 {
 Temp_sp = (Temp_m*24)/10;	   
 TT_Value = Check_Type_Offset(Code_Value);
 TC_Value = Get_T_Slope(TT_Value);
 TT_Value = TC_Value/7.5 ;
 TA_Value = (TC_Value/6+163) ;
 if (C_F_Type == 0) TC_Value = TEMP_F_TO_C(TC_Value);  
 }
 else if (TC_Type == 3)
 {	
 Temp_sp = (Temp_m*36)/10;    
 TT_Value = Check_Type_Offset(Code_Value);
 TC_Value = Get_E_Slope(TT_Value);
 TT_Value = TC_Value/28.3 ;
 TA_Value = (TC_Value/22.5+163) ;
 if (C_F_Type == 0) TC_Value = TEMP_F_TO_C(TC_Value);	  
 }
 else if (TC_Type == 4)
 { 	NP_COD = 1;
 Temp_sp = (Temp_m*4)/10; 
 TT_Value = Check_Type_Offset(Code_Value);
 TC_Value = Get_R_Slope(TT_Value);
 TT_Value = TC_Value/56.8 ;
 TA_Value = (TC_Value/44.5+163) ;
 if (C_F_Type == 0)  TC_Value = TEMP_F_TO_C(TC_Value);
 }
 else if (TC_Type == 5)
 {	   NP_COD = 1;
 Temp_sp = (Temp_m*4)/10; 
 TT_Value = Check_Type_Offset(Code_Value);
 TC_Value = Get_S_Slope(TT_Value);
 TT_Value = TC_Value/56.8 ;
 TA_Value = (TC_Value/44.5+163) ;
 if (C_F_Type == 0) 	TC_Value = TEMP_F_TO_C(TC_Value); 
 }
 }
 if (Soft_Timer[2] == 0)
 {
 RTC_READ_SET();
 Soft_Timer[2] = 8;
 }
 if (Soft_Timer[0] == 0)
 {
 Soft_Timer[0] = 32;	
 LED_Disp(1,TC_Value);
 
 if ((TC_Value > alarm_Low_set)&&(TC_Value < alarm_Hi_set))
 { BEEP_OUT = 1; }
 else
 { BEEP_OUT = 0; }
 }
 if (Soft_Timer[5] == 0)
 {
 if( P04 == 0) Set_mV(TT_Value);
 
 if( P05 == 0) Set_mA(TA_Value);
 Soft_Timer[5] = 16;
 }
 if (Soft_Timer[4] == 0)
 {
 if(tran == 0)
 {
 SBUF = TC_Value ;
 tran = 1 ;
 Soft_Timer[4] = 1;
 }
 else
 { 
 SBUF = TC_Value >> 8 ;
 tran = 0;
 Soft_Timer[4] = 59 ;
 }
 TI = 1;
 }
 }
 return  TC_Value;
 }
 
 unsigned int Check_Type_Offset(unsigned int Code_Value)
 {
 if (NG_COD == 0)
 {
 if (AV_COD == 0)
 {
 if(Code_Value >= TC_Zero_offset)	   
 {
 if((Code_Value - TC_Zero_offset) >= Temp_sp)
 { Code_Value = (Code_Value - TC_Zero_offset) - Temp_sp ;}
 else
 { Code_Value = (Temp_sp + TC_Zero_offset)- Code_Value; AV_COD = 1 ; }
 }
 else
 {   
 if((TC_Zero_offset - Code_Value) >= Temp_sp)
 { Code_Value = TC_Zero_offset - (Code_Value + Temp_sp);AV_COD = 1 ;}
 else
 { Code_Value =  (Temp_sp + TC_Zero_offset) - Code_Value; AV_COD = 1 ; }
 }
 }
 else	   
 {















 
 Code_Value = (Code_Value + TC_Zero_offset) + Temp_sp;
 }
 }
 else
 {
 if(AV_COD == 0)   
 {
 if(Code_Value >= TC_Zero_offset)
 {
 if((Code_Value - TC_Zero_offset) >= Temp_sp)
 { Code_Value = (Code_Value + Temp_sp) + TC_Zero_offset ;}
 else
 { Code_Value = Code_Value + (Temp_sp  + TC_Zero_offset) ;}
 }
 else
 {
 if((TC_Zero_offset - Code_Value) >= Temp_sp)
 { Code_Value = (TC_Zero_offset + Temp_sp) - Code_Value; AV_COD = 1;}
 else
 { Code_Value = (TC_Zero_offset + Temp_sp) - Code_Value; AV_COD = 1;}
 }
 }
 else	   
 {
 if(Code_Value >= TC_Zero_offset)
 {
 if((Code_Value - TC_Zero_offset) >= Temp_sp)
 { Code_Value = (Code_Value - Temp_sp) - TC_Zero_offset;}
 else
 { Code_Value = Temp_sp - ( Code_Value - TC_Zero_offset);AV_COD = 0;}
 }
 else
 {
 if(( TC_Zero_offset - Code_Value) >= Temp_sp)
 { Code_Value =  TC_Zero_offset - (Temp_sp + Code_Value);AV_COD = 0;}
 else
 { Code_Value = ( TC_Zero_offset +  Temp_sp) - Code_Value;AV_COD = 0;}
 }
 }
 }
 
 if(ADD_COD == 1 ) 
 { Code_Value = Code_Value - (Code_Value/70); }	   
 else
 { Code_Value = Code_Value + (Code_Value/70);}
 
 if(OVER_COD == 1){ Code_Value = 0xffff;}
 
 return Code_Value;
 }







 
 unsigned int DO_RTD_TYPE(void)
 {
 unsigned int RTD_Value; 
 unsigned char key;	 
 
 key = Get_Key();
 
 if(key == 0x01)
 {
 Func_Type =  4;
 }
 else
 {
 if (Soft_Timer[1] == 0) 
 {
 Soft_Timer[1] = 16;
 
 RTD_Value = Read_AD3421_Value();
 
 if((NG_COD == 1)&&(AV_COD == 1))
 {
 if( RTD_Value >= RTD_Zero_offset)
 {
 RTD_Value = RTD_Value - RTD_Zero_offset;
 }
 else
 {
 RTD_Value = RTD_Zero_offset -RTD_Value;
 AV_COD = 0;
 }
 }
 else if((NG_COD == 1)&&(AV_COD == 0))
 {
 RTD_Value = RTD_Value + RTD_Zero_offset;
 } 			
 else if((NG_COD == 0)&&(AV_COD == 1))
 {
 RTD_Value = RTD_Value + RTD_Zero_offset;
 }   
 else if((NG_COD == 0)&&(AV_COD == 0))
 {
 if( RTD_Value >= RTD_Zero_offset)
 {
 RTD_Value = RTD_Value - RTD_Zero_offset;
 }
 else
 {
 RTD_Value = RTD_Zero_offset -RTD_Value;
 AV_COD = 1 ;
 }
 }
 if(RTD_Span_offset > 0x44e4)
 {  RTD_Value = RTD_Value +(RTD_Value/RTD_Span_Value);}
 else
 {  RTD_Value = RTD_Value - (RTD_Value/RTD_Span_Value);}
 if(OVER_COD == 1) RTD_Value = 0xffff;
 RTD_Value = Get_RTD_Slope(RTD_Value);
 
 if (C_F_Type == 0)	RTD_Value = TEMP_F_TO_C(RTD_Value);
 }
 if (Soft_Timer[0] == 0)
 {
 LED_Disp(1,RTD_Value);
 Soft_Timer[0] = 16 ;
 
 if ((RTD_Value > alarm_Low_set)&&(RTD_Value < alarm_Hi_set))
 { BEEP_OUT = 1; }
 else
 { BEEP_OUT = 0; }
 }
 if (Soft_Timer[5] == 0)
 {
 if( P04 == 0) Set_mV(RTD_Value);
 if( P05 == 0) Set_mA(RTD_Value);
 
 Soft_Timer[5] = 2;
 }
 if (Soft_Timer[2] == 0)
 {
 RTC_READ_SET();
 Soft_Timer[2] = 8 ;
 }
 if (Soft_Timer[4] == 0)
 {
 if(tran == 0)
 {
 SBUF = RTD_Value ;
 tran = 1 ;
 Soft_Timer[4] = 1;
 }
 else
 { 
 SBUF = RTD_Value >> 8 ;
 tran = 0;
 Soft_Timer[4] = 59 ;
 }
 TI = 1;
 }
 }
 return RTD_Value;
 }


 
 unsigned  int DO_mV_TYPE(void)
 {
 unsigned int mV_Value;
 unsigned char key;
 
 key = Get_Key();
 
 if(key == 0x01)
 {
 Func_Type = 4;
 }
 else 
 {
 if (Soft_Timer[1] == 0) 
 {
 Soft_Timer[1] = 16;
 
 mV_Value = Read_AD3421_Value();
 
 
 if((NG_COD == 1)&&(AV_COD == 1))
 {
 if( mV_Value > mV_Zero_offset)		
 {
 mV_Value = mV_Value - mV_Zero_offset;
 }
 else
 {
 mV_Value = mV_Zero_offset -mV_Value;
 AV_COD = 0;
 }
 }
 else if((NG_COD == 1)&&(AV_COD == 0))
 {
 mV_Value = mV_Value + mV_Zero_offset;
 } 			
 else if((NG_COD == 0)&&(AV_COD == 1))
 {
 mV_Value = mV_Value + mV_Zero_offset;
 }   
 else if((NG_COD == 0)&&(AV_COD == 0))
 {
 if( mV_Value >= mV_Zero_offset)
 {
 mV_Value = mV_Value - mV_Zero_offset;
 }
 else
 {
 mV_Value = mV_Zero_offset -mV_Value;
 AV_COD = 1 ;
 }
 }
 if(mV_Span_offset > 0x0c80)
 { mV_Value = mV_Value + (mV_Value/mV_Span_Value); }
 else
 { mV_Value = mV_Value - (mV_Value/mV_Span_Value); }
 
 
 
 
 mV_Value = mV_Value/3.2;
 
 if(OVER_COD == 1) mV_Value = 0xffff;	 
 }
 if (Soft_Timer[0] == 0)
 {
 LED_Disp(1,mV_Value);
 Soft_Timer[0] = 8 ;
 
 if ((mV_Value > alarm_Low_set)&&(mV_Value < alarm_Hi_set))
 { BEEP_OUT = 1; }
 else
 { BEEP_OUT = 0; }
 }
 if (Soft_Timer[5] == 0)
 {
 if( P04 == 0)  Set_mV(mV_Value);
 if( P05 == 0)  Set_mA(mV_Value);
 
 Soft_Timer[5] = 2;
 }
 if (Soft_Timer[2] == 0)
 {
 RTC_READ_SET();
 Soft_Timer[2] = 8 ;
 }
 if (Soft_Timer[4] == 0)
 {
 if(tran == 0)
 {
 SBUF = mV_Value ;
 tran = 1 ;
 Soft_Timer[4] = 1;
 }
 else
 { 
 SBUF = mV_Value >> 8 ;
 tran = 0;
 Soft_Timer[4] = 59 ;
 }
 TI = 1;
 }
 }
 return mV_Value ;
 }


 
 unsigned int DO_mA_TYPE(void)
 {
 unsigned int mA_Value;
 unsigned char key;
 
 key = Get_Key();
 
 if(key == 0x01)
 {
 Func_Type = 4 ;
 }
 else 
 {
 if (Soft_Timer[1] == 0) 
 {
 Soft_Timer[1] = 16;
 
 mA_Value = Read_AD3421_Value();
 
 if((NG_COD == 1)&&(AV_COD == 1))
 {
 if( mA_Value >= mA_Zero_offset)
 {
 mA_Value = mA_Value - mA_Zero_offset;
 }
 else
 {
 mA_Value = mA_Zero_offset -mA_Value;
 AV_COD = 0;
 }
 }
 else if((NG_COD == 1)&&(AV_COD == 0))
 {
 mA_Value = mA_Value + mA_Zero_offset;
 } 			
 else if((NG_COD == 0)&&(AV_COD == 1))
 {
 mA_Value = mA_Value + mA_Zero_offset;
 }   
 else if((NG_COD == 0)&&(AV_COD == 0))
 {
 if( mA_Value >= mA_Zero_offset)
 {
 mA_Value = mA_Value - mA_Zero_offset;
 }
 else
 {
 mA_Value = mA_Zero_offset -mA_Value;
 AV_COD = 1 ;
 }
 }
 if(mA_Span_offset >  0x1900)
 { mA_Value = mA_Value + (mA_Value/mA_Span_Value); }
 else
 { mA_Value = mA_Value - (mA_Value/mA_Span_Value); }
 
 mA_Value = mA_Value/3.2 ;
 
 if(OVER_COD == 1) mA_Value = 0xffff;
 }
 if (Soft_Timer[0] == 0)
 {
 LED_Disp(1,mA_Value);
 Soft_Timer[0] = 16 ;
 
 if ((mA_Value > alarm_Low_set)&&(mA_Value < alarm_Hi_set))
 { BEEP_OUT = 1; }
 else
 { BEEP_OUT = 0; }
 }
 if (Soft_Timer[5] == 0)
 {
 if( P04 == 0)  Set_mV(mA_Value);
 if( P05 == 0)  Set_mA(mA_Value);
 
 Soft_Timer[5] = 2;
 }
 if (Soft_Timer[2] == 0)
 {
 RTC_READ_SET();
 Soft_Timer[2] = 8 ;
 }
 if (Soft_Timer[4] == 0)
 {
 if(tran == 0)
 {
 SBUF = mA_Value ;
 tran = 1 ;
 Soft_Timer[4] = 1;
 }
 else
 { 
 SBUF = mA_Value >> 8 ;
 tran = 0;
 Soft_Timer[4] = 59 ;
 }
 TI = 1;
 }
 }
 return mA_Value;
 }
 
 unsigned int Read_AD3421_Value(void)
 {
 unsigned int  AD3421_Value;
 unsigned char ssta;
 
 ssta = Get_AD3421_Value();
 if (ssta == 0)
 {
 AD_Hi =  AD_Hi & 0x03;
 if(AD_Hi >= 2)
 {
 AV_COD = 1;
 AD3421_Value = AD_Hi & 0x03;	  
 AD3421_Value = AD3421_Value << 8 ;
 AD3421_Value = AD3421_Value + AD_Mid ;
 AD3421_Value = AD3421_Value << 7 ;
 AD_Lo = AD_Lo >> 1;
 AD3421_Value = AD3421_Value + AD_Lo ;  
 AD3421_Value = ~ AD3421_Value; 
 if( AD3421_Value >= 0xf000){OVER_COD = 1;} else{OVER_COD = 0;}
 }
 else
 {
 AV_COD = 0;
 AD3421_Value = AD_Hi & 0x03;	  
 AD3421_Value = AD3421_Value << 8 ;
 AD3421_Value = AD3421_Value + AD_Mid ;
 AD3421_Value = AD3421_Value << 7 ;
 AD_Lo = AD_Lo >> 1;
 AD3421_Value = AD3421_Value + AD_Lo;
 if( AD3421_Value >= 0xf000){OVER_COD = 1;} else{OVER_COD = 0;}
 }
 }
 return AD3421_Value;
 }
 
 void DO_SETUP_TYPE(void)
 {
 unsigned char set_key = 0, times = 0, Itemm = 0; 
 unsigned char item_key,confrom_key, up_key,don_key;
 unsigned int  value_cal = 0;
 
 
 SETUP_LED_Disp(Itemm,value_cal);
 
 while (CAIT)
 {
 set_key = Get_Key();
 
 if((set_key & 0x01) == 1)
 { item_key = 1 ;}
 else
 { item_key = 0 ;}
 
 if((set_key & 0x02) == 2)
 {confrom_key = 1 ;}
 else
 { confrom_key = 0 ;}
 
 if((set_key & 0x04) == 4)
 { up_key = 1 ;}
 else
 { up_key = 0 ;}
 
 if((set_key & 0x08) == 8)
 { don_key = 1 ;}
 else
 { don_key = 0 ;}
 
 if (item_key == 1) 
 {
 Itemm ++;
 times=0;
 }
 if (Itemm > 0x13)
 {
 Itemm = 0; 
 CAIT = 0;
 } 
 if(up_key == 1)   value_cal++;
 if(don_key == 1)  value_cal--;
 
 
 if ((Itemm >= 4)&&(Itemm <= 11))
 {
 if (Soft_Timer[1] == 0) 
 {
 Soft_Timer[1] = 4 ;
 Data_Value[n_code] = Read_AD3421_Value();
 if(n_code < 8)
 {n_code++;}
 else
 {
 Data_Value[9] = (Data_Value[7]+Data_Value[6]+Data_Value[5]+Data_Value[4]+Data_Value[3]+Data_Value[2]+Data_Value[1]+Data_Value[0])/8 ;
 n_code = 0 ;
 }
 }
 else
 {
 Data_Value[9] = Data_Value[n_code] ;
 }
 }
 if (Itemm == 1)			 
 {
 SETUP_LED_Disp(Itemm,Work_Type);
 Work_Type = Work_Type + value_cal;
 value_cal = 0;
 if(Work_Type >= 4)
 {
 Work_Type = 0;
 value_cal = 0;
 }	 
 if(confrom_key == 1)
 { 
 EEPROM_write_byte(18,Work_Type);
 SETUP_LED_Disp(22,0);
 delay(2500);
 times ++;
 }
 }
 else if (Itemm == 2)
 {
 if (Work_Type >= 2) {Itemm = Itemm + 1;}
 else{	SETUP_LED_Disp(Itemm,C_F_Type);
 C_F_Type = C_F_Type + value_cal;
 value_cal = 0;
 
 if(C_F_Type >= 2 )
 {
 C_F_Type = 0 ;
 value_cal = 0;
 }
 if(confrom_key == 1)
 { 
 EEPROM_write_byte(19,C_F_Type);   
 times ++; SETUP_LED_Disp(22,0);delay(2500);
 }
 }
 }
 else if (Itemm == 3)
 {
 if (Work_Type != 0)
 {	Itemm = Itemm + 1;}
 else{   TC_Type = TC_Type + value_cal; 
 value_cal = 0;
 if (TC_Type >= 6)
 {
 TC_Type = 0 ;
 value_cal = 0;
 }		   
 SETUP_LED_Disp(Itemm,TC_Type);
 
 if(confrom_key == 1)
 {
 EEPROM_write_byte(20,TC_Type);   
 times ++; SETUP_LED_Disp(22,0);delay(2500);
 }
 }
 }		
 else if (Itemm == 4)
 {
 if (Work_Type != 0){	Itemm = Itemm + 1;}
 else{
 SETUP_LED_Disp(Itemm, Data_Value[9]);
 if(confrom_key == 1)
 {
 Temp_Flag = 3 ;
 Temp_offset = Temp_m;
 if ((Temp_m*24)/10 >= Data_Value[9])
 {
 if( AV_COD == 1)
 { TC_Zero_offset = (Temp_m*24)/10 - Data_Value[9]; NG_COD = 0;use_flag = use_flag&0xfe;}
 else{ TC_Zero_offset = (Temp_m*24)/10 + Data_Value[9]; NG_COD =0;use_flag = use_flag&0xfe;}
 }
 else
 {  
 if( AV_COD == 1)
 { TC_Zero_offset = Data_Value[9]-(Temp_m*24)/10 ;  NG_COD = 1;use_flag = use_flag|0x01;}
 else {TC_Zero_offset = Data_Value[9] + (Temp_m*24)/10;  NG_COD = 0;use_flag = use_flag&0xfe;}
 }
 EEPROM_write_byte(50,(use_flag));
 EEPROM_write_word(22,TC_Zero_offset); 
 EEPROM_write_word(60,Temp_offset);										  
 delay(50);
 times ++; SETUP_LED_Disp(22,0);delay(2500);
 }
 }
 }
 else if (Itemm == 5)
 {
 if (Work_Type != 0) { Itemm = Itemm + 1; }
 else
 {
 SETUP_LED_Disp(Itemm,Data_Value[9]);
 if(confrom_key == 1)
 { 
 if( NG_COD == 1)
 {TC_Span_offset = Data_Value[9] + TC_Zero_offset;}
 else {TC_Span_offset = Data_Value[9] - TC_Zero_offset;}
 EEPROM_write_word(24,TC_Span_offset);  
 
 if(TC_Span_offset+TC_Zero_offset >= 0xc8ca )
 { TC_Span_Value = (TC_Span_offset+TC_Zero_offset) /((TC_Span_offset+TC_Zero_offset) - 0xc8ca);use_flag = use_flag|0x10;}
 else
 { TC_Span_Value = (TC_Span_offset+TC_Zero_offset) /(0xc8ca - (TC_Span_offset+TC_Zero_offset));use_flag = use_flag&0xef;}
 
 EEPROM_write_word(52,TC_Span_Value);
 delay(50);
 EEPROM_write_byte(50,use_flag);
 times ++; SETUP_LED_Disp(22,0);delay(2500);
 }
 }
 }
 else if (Itemm == 6)
 {
 if (Work_Type != 1)	{	Itemm = Itemm + 1;}
 else{
 if( AV_COD == 1){ NG_COD = 1;}else{ NG_COD = 0;}
 SETUP_LED_Disp(Itemm,Data_Value[9]);
 if(confrom_key == 1)
 {
 RTD_Zero_offset = Data_Value[9] ;
 EEPROM_write_word(26,RTD_Zero_offset);   
 delay(50);
 if( NG_COD == 1){ EEPROM_write_byte(50,(use_flag|0x02));}
 else { EEPROM_write_byte(50,(use_flag&0xfd));}
 times ++; SETUP_LED_Disp(22,0);delay(2500);
 }
 }
 }
 else if (Itemm == 7)
 {
 if (Work_Type != 1)	{Itemm = Itemm + 1;}
 else{	 
 SETUP_LED_Disp(Itemm,Data_Value[9]);
 if(confrom_key == 1)
 {
 RTD_Span_offset = Data_Value[9] ;
 EEPROM_write_word(28,RTD_Span_offset);   
 
 if( NG_COD == 1)
 { if ((RTD_Span_offset + RTD_Zero_offset) > 0x44e4 )
 { RTD_Span_Value = ((RTD_Span_offset + RTD_Zero_offset)/((RTD_Span_offset + RTD_Zero_offset)-0x44e4));}
 else
 { RTD_Span_Value = ((RTD_Span_offset + RTD_Zero_offset)/(0x44e4 - (RTD_Span_offset + RTD_Zero_offset)));}
 }
 else
 { if ((RTD_Span_offset - RTD_Zero_offset) > 0x44e4 )
 { RTD_Span_Value = ((RTD_Span_offset - RTD_Zero_offset)/((RTD_Span_offset - RTD_Zero_offset)-0x44e4));}
 else
 { RTD_Span_Value = ((RTD_Span_offset - RTD_Zero_offset)/(0x44e4 - (RTD_Span_offset - RTD_Zero_offset)));}
 }
 EEPROM_write_word(54,RTD_Span_Value);
 times ++;	SETUP_LED_Disp(22,0);delay(2500);
 }
 }
 }
 else if (Itemm == 8)
 {
 if (Work_Type != 2)	  {	Itemm = Itemm + 1;}
 else{
 if( AV_COD == 1){ NG_COD = 1;}else{ NG_COD = 0;}
 SETUP_LED_Disp(Itemm,Data_Value[9]);
 if(confrom_key == 1)
 {
 mV_Zero_offset = Data_Value[9] ;
 EEPROM_write_word(30,mV_Zero_offset);  
 delay(50);
 if( NG_COD == 1){ EEPROM_write_byte(50,(use_flag|0x04));}
 else { EEPROM_write_byte(50,(use_flag&0xfb));}
 times ++; SETUP_LED_Disp(22,0);	delay(2500);
 }
 }
 }
 else if (Itemm == 9)
 {
 if (Work_Type != 2) {	Itemm = Itemm + 1;}
 else{	
 SETUP_LED_Disp(Itemm,Data_Value[9]);
 if(confrom_key == 1)
 {
 mV_Span_offset = Data_Value[9] ;
 
 EEPROM_write_word(32,mV_Span_offset);  
 
 if( NG_COD == 1)
 { if ((mV_Span_offset + mV_Zero_offset) > 0x7d00 )		 
 { mV_Span_Value = ((mV_Span_offset + mV_Zero_offset)/((mV_Span_offset + mV_Zero_offset)-0x7d00));}
 else
 { mV_Span_Value = ((mV_Span_offset + mV_Zero_offset)/(0x7d00 - (mV_Span_offset + mV_Zero_offset)));}
 }
 else
 { if ((mV_Span_offset - mV_Zero_offset) > 0x7d00)
 { mV_Span_Value = ((mV_Span_offset - mV_Zero_offset)/((mV_Span_offset - mV_Zero_offset)-0x7d00));}
 else
 { mV_Span_Value = ((mV_Span_offset - mV_Zero_offset)/(0x7d00 - (mV_Span_offset - mV_Zero_offset)));}
 }
 EEPROM_write_word(56,mV_Span_Value);
 times ++;	SETUP_LED_Disp(22,0);delay(2500);
 }
 }
 }
 else if (Itemm == 10)
 {
 if (Work_Type != 3)  {	Itemm = Itemm + 1;}
 else{
 if( AV_COD == 1){ NG_COD = 1;}else{ NG_COD = 0;}
 SETUP_LED_Disp(Itemm,Data_Value[9]);
 if(confrom_key == 1)
 {
 delay(50);
 mA_Zero_offset = Data_Value[9];
 EEPROM_write_word(34,mA_Zero_offset);  
 delay(50);
 if( NG_COD == 1){ EEPROM_write_byte(50,(use_flag|0x08));}
 else { EEPROM_write_byte(50,(use_flag&0xf7));}
 times ++; SETUP_LED_Disp(22,0);delay(25000);
 }
 }
 }
 else if (Itemm == 11)
 {
 if (Work_Type != 3)  {Itemm = Itemm + 1;}
 else{
 SETUP_LED_Disp(Itemm,Data_Value[9] );
 if(confrom_key == 1)
 {
 mA_Span_offset = Data_Value[9] ; 
 EEPROM_write_word(36,mA_Span_offset);  
 delay(50);
 if( NG_COD == 1)
 { if ((mA_Span_offset + mA_Zero_offset) > 0x1900 )	
 { mA_Span_Value = ((mA_Span_offset + mA_Zero_offset)/((mA_Span_offset + mA_Zero_offset)- 0x1900));}
 else
 { mA_Span_Value = ((mA_Span_offset + mA_Zero_offset)/( 0x1900 - (mA_Span_offset + mA_Zero_offset)));}
 }
 else
 { if ((mA_Span_offset - mA_Zero_offset) > 0x1900 )
 { mA_Span_Value = ((mA_Span_offset - mA_Zero_offset)/((mA_Span_offset - mA_Zero_offset)- 0x1900));}
 else
 { mA_Span_Value = ((mA_Span_offset - mA_Zero_offset)/( 0x1900 - (mA_Span_offset - mA_Zero_offset)));}
 }
 EEPROM_write_word(58,mA_Span_Value);
 times ++; SETUP_LED_Disp(22,0);	delay(2500);
 }
 }
 }
 
 else if (Itemm == 12)
 {
 alarm_Low_set = alarm_Low_set + value_cal*10 ;
 value_cal = 0;
 SETUP_LED_Disp(Itemm,alarm_Low_set);
 if((up_key == 1)||(don_key == 1))
 {
 if(alarm_Low_set > 9999){value_cal = 0;alarm_Low_set = 0;}
 if(confrom_key == 1)
 {
 EEPROM_write_word(38,alarm_Low_set);   
 times ++; SETUP_LED_Disp(22,0);delay(2500);
 } 
 }
 }
 else if (Itemm == 13)
 { 
 alarm_Hi_set = alarm_Hi_set + value_cal*10 ;
 value_cal = 0;
 SETUP_LED_Disp(Itemm,alarm_Hi_set);
 if((up_key == 1)||(don_key == 1))
 {
 if(alarm_Hi_set > 9999){value_cal = 0;alarm_Hi_set = 0;}
 
 if(confrom_key == 1)
 {
 EEPROM_write_word(40,alarm_Hi_set);   
 times ++; SETUP_LED_Disp(22,0);delay(2500);
 }
 }
 }
 else if (Itemm == 14)
 {   
 if(value_cal >= 200)
 {
 if(use_year == 0) {use_year = 0x99; value_cal = 0 ;}
 else
 { if((use_year&0x0f) == 0){use_year = (((use_year-0x10)&0xf0)|0x09); value_cal = 0 ; }
 else { use_year = use_year -0x01; value_cal = 0 ;}
 }
 }
 else
 {
 if(value_cal == 1) 
 {
 if(use_year >= 0x9a) { use_year = 0; value_cal = 0;}
 else{if((use_year&0x0f) == 0x09) {use_year = ((use_year+0x10)&0xf0);value_cal = 0; } 
 else { use_year = use_year + 0x01; value_cal = 0;} } 
 } 
 }     
 SETUP_LED_Disp(Itemm,use_year + 0x2000);
 
 if(confrom_key == 1)
 {
 RTC_write_byte(6,use_year);
 EEPROM_write_byte(42,use_year); 
 times ++;SETUP_LED_Disp(22,0);delay(2500);
 }
 
 }
 else if (Itemm == 15)
 {
 if(value_cal >= 200)
 {
 if(use_mon <= 0x01){use_mon = 0x12; value_cal = 0 ;}
 else
 { if((use_mon&0x0f) == 0) {use_mon = (((use_mon-0x10)&0xf0)|0x09); value_cal = 0 ; }
 else{use_mon = use_mon - 0x01; value_cal = 0 ;}
 }
 }
 else
 {
 if(value_cal == 1) 
 {
 if(use_mon == 0x12){use_mon = 0x01; value_cal = 0 ;}
 else {if((use_mon&0x0f) == 0x09) {use_mon = ((use_mon+0x10)&0xf0); value_cal = 0;}
 else { use_mon = use_mon + 0x01; value_cal = 0 ;}}
 }
 }
 SETUP_LED_Disp(Itemm,use_mon);
 
 if(confrom_key == 1)
 {
 RTC_write_byte(5,use_mon);
 EEPROM_write_byte(43,use_mon);
 times ++;  SETUP_LED_Disp(22,0);delay(2500);
 }
 }
 else if (Itemm == 16)			 
 {
 if(value_cal >= 200)
 {
 if((use_day == 1)&&(use_mon == 0x02)&&(use_year%4 == 0)) { use_day = 0x29 ;  value_cal = 0 ; }
 else if((use_day == 1)&&(use_mon == 0x02)&&(use_year%4 != 0)) { use_day = 0x28 ; value_cal = 0 ; }
 else if((use_day == 1)&&((use_mon == 1)||(use_mon == 3)||(use_mon == 5)||(use_mon == 7)||(use_mon == 0x08)||(use_mon ==0x10)||(use_mon == 0x12))) { use_day =0x31;value_cal = 0;}
 else if((use_day == 1)&&((use_mon == 4)||(use_mon == 6)||(use_mon == 0x09)||(use_mon == 0x11))) { use_day = 0x30 ;  value_cal = 0 ; }
 else if((use_day&0x0f) == 0) {use_day = (((use_day-0x10)&0xf0)|0x09);value_cal = 0;}
 else {use_day = use_day -1; value_cal = 0;}
 }
 else
 {
 if(value_cal == 1)
 {
 if((use_mon == 2)&&(use_year%4 == 0)&&(use_day == 0x29)) { use_day = 1; value_cal = 0;}
 else if((use_mon == 2)&&(use_year%4 != 0)&&(use_day == 0x28)) { use_day = 1; value_cal = 0;}
 else if(((use_mon == 1)||(use_mon == 3)||(use_mon == 5)||(use_mon == 7)||(use_mon == 8)||(use_mon == 0x10)||(use_mon == 0x12))&&(use_day == 0x31)) { use_day = 1;value_cal = 0;}
 else if(((use_mon == 4)||(use_mon == 6)||(use_mon == 9)||(use_mon == 0x11))&&(use_day == 0x30)) { use_day = 1; value_cal = 0;}
 else if((use_day&0x0f) == 0x09) {use_day = ((use_day + 0x10)&0xf0); value_cal = 0;}
 else{use_day = use_day + 1; value_cal = 0;}                 
 }
 }
 SETUP_LED_Disp(Itemm,use_day);
 
 if(confrom_key == 1)
 {
 RTC_write_byte(4,use_day);
 EEPROM_write_byte(44,use_day);
 times ++;	SETUP_LED_Disp(22,0);delay(250);
 }
 }
 else if (Itemm == 17)
 {
 if(value_cal >= 200)
 {
 if (use_hour == 0){use_hour = 0x23; value_cal = 0;}
 else 
 { if((use_hour&0x0f) == 0x00) {use_hour = ((use_hour-0x10)&0xf0)|0x09; value_cal = 0;}  
 else {use_hour = use_hour - 0x01; value_cal = 0;}
 }
 }
 else
 {
 if(value_cal == 1)
 {
 if(use_hour == 0x23) {use_hour = 0; value_cal = 0;}
 else
 { if((use_hour&0x0f) == 0x09) {use_hour = (use_hour+0x10)&0xf0; value_cal = 0;}
 else {use_hour = use_hour + 0x01; value_cal = 0;}
 }    
 }
 }
 SETUP_LED_Disp(Itemm,use_hour);
 if(confrom_key == 1)
 {
 RTC_write_byte(2,use_hour);
 EEPROM_write_byte(46,use_hour);
 times ++;	SETUP_LED_Disp(22,0);delay(250);
 }
 }
 else if (Itemm == 18)
 {
 if(value_cal >= 200)
 {
 if(use_min == 0) { use_min = 0x59; value_cal = 0;}
 else 
 {
 if((use_min&0x0f) == 0) {use_min = ((use_min - 0x10)&0xf0)|0x09; value_cal = 0;} 
 else	{ use_min = use_min - 0x01; value_cal = 0;}
 }
 }
 else
 {	
 if (value_cal == 1) 
 {
 if(use_min == 0x59) {use_min = 0; value_cal = 0;}
 else
 {  if((use_min&0x0f) == 0x09) {use_min = (use_min+0x10)&0xf0; value_cal = 0;}
 else { use_min = use_min + 0x01; value_cal = 0;}
 }
 }
 }
 SETUP_LED_Disp(Itemm,use_min );
 if(confrom_key == 1)
 {
 RTC_write_byte(1,use_min );
 EEPROM_write_byte(47,use_min);
 times ++;SETUP_LED_Disp(22,0); delay(250);
 }
 }
 else if (Itemm >= 19)
 { 
 Itemm = 0 ;
 CAIT  = 0 ;
 }
 }
 Check_PCB();		 	
 }
 
 void RTC_ON(void)
 { 
 use_week = RTC_read_byte(0x03);
 RTC_write_byte(0x07,0x40);
 RTC_write_byte(0x03,use_week|0x08);	  
 
 if((use_week&0x80) == 0x80) {;}        
 else
 { 
 RTC_write_byte(0x06,use_year)   ;      
 RTC_write_byte(0x05,use_mon)    ;      
 RTC_write_byte(0x04,use_day)    ;      
 RTC_write_byte(0x03,use_week|0x08);
 RTC_write_byte(0x02,use_hour)   ;      
 RTC_write_byte(0x01,use_min)    ;      
 RTC_write_byte(0x00,use_sec|0x80) ;
 } 
 
 }
 
 void RTC_WRITE_SET(void)
 {
 
 RTC_write_byte(0x00,(use_sec|0x80));
 
 RTC_write_byte(0x01,use_min);
 
 RTC_write_byte(0x02,use_hour);
 
 RTC_write_byte(0x03,use_week|0x08);
 
 RTC_write_byte(0x04,use_day);
 
 RTC_write_byte(0x05,use_mon);
 
 RTC_write_byte(0x06,use_year);
 
 RTC_write_byte(0x07,0x40);
 }
 
 void RTC_READ_SET(void)
 { 
 use_sec  = RTC_read_byte(0x00)&0x7f ;
 use_min  = RTC_read_byte(0x01) ;
 use_hour = RTC_read_byte(0x02) ;
 use_week = RTC_read_byte(0x03)&0x07 ;
 use_day  = RTC_read_byte(0x04);
 use_mon  = RTC_read_byte(0x05);
 use_year = RTC_read_byte(0x06);
 
 if((use_mon&0x03) == 0x01)
 { 
 EEPROM_write_byte(42,use_year);
 EEPROM_write_byte(43, use_mon);
 EEPROM_write_byte(44, use_day);
 EEPROM_write_byte(45, use_week);
 EEPROM_write_byte(46,use_hour);
 EEPROM_write_byte(47, use_min);
 EEPROM_write_byte(48, use_sec);
 }
 }
 
 void EEPROM_WriteDefault(void)
 {
 Check_PCB();
 EEPROM_write_byte(18,Work_Type);  
 EEPROM_write_byte(19, 0);   
 EEPROM_write_byte(20,0);   
 
 EEPROM_write_word(22, 0);	
 EEPROM_write_word(24, 1400);
 EEPROM_write_word(26, 0);
 EEPROM_write_word(28, 850);
 EEPROM_write_word(30, 0);
 EEPROM_write_word(32, 5000);
 EEPROM_write_word(34, 40);	
 EEPROM_write_word(36, 200);
 EEPROM_write_word(38, 0);
 EEPROM_write_word(40, 5000);
 
 EEPROM_write_byte(42,0x15);
 EEPROM_write_byte(43, 0x01);
 EEPROM_write_byte(44, 0x01);
 EEPROM_write_byte(45,0x04);
 EEPROM_write_byte(46,0x12);
 EEPROM_write_byte(47, 0x01);
 EEPROM_write_byte(48, 0x01);
 EEPROM_write_byte(50, 0);
 EEPROM_write_word(52, 1);
 EEPROM_write_word(54, 1);
 EEPROM_write_word(56, 1);
 EEPROM_write_word(58, 1);
 EEPROM_write_word(60,0);
 EEPROM_write_word(64, 64);		 
 RTC_ON();
 }
 
 void DO_RESET_TYPE(void)
 {
 EEPROM_WriteDefault();
 LED_Fill();                                      
 Work_Type = EEPROM_read_byte(18);
 C_F_Type = EEPROM_read_byte(19);
 TC_Type = EEPROM_read_byte(20);        
 TC_Zero_offset = EEPROM_read_word(22);	
 TC_Span_offset = EEPROM_read_word(24);
 RTD_Zero_offset = EEPROM_read_word(26);
 RTD_Span_offset = EEPROM_read_word(28);
 mA_Zero_offset = EEPROM_read_word(34);
 mA_Span_offset = EEPROM_read_word(36);
 
 mV_Zero_offset = EEPROM_read_word(30);	
 mV_Span_offset = EEPROM_read_word(32);
 alarm_Low_set = EEPROM_read_word(38);
 alarm_Hi_set = EEPROM_read_word(40);
 use_year = EEPROM_read_word(42);
 
 use_mon =  EEPROM_read_byte(43);
 use_day =  EEPROM_read_byte(44);
 use_week = EEPROM_read_byte(45);
 use_hour = EEPROM_read_byte(46);
 use_min =  EEPROM_read_byte(47);
 use_sec =  EEPROM_read_byte(48);
 use_flag =	EEPROM_read_byte(50);
 TC_Span_Value = EEPROM_read_word(52);
 RTD_Span_Value = EEPROM_read_word(54);
 mV_Span_Value = EEPROM_read_word(56);
 mA_Span_Value = EEPROM_read_word(58);
 Temp_offset  = EEPROM_read_word(60);
 
 }


 
 main(void)
 {
 TR0 = 0;
 TMOD = TMOD |= 0x01;
 TH0  = 0xDC;  
 TL0  = 0;
 TF0  = 0; 
 
 IFMT = 0x07 ;  
 SCMD = 0x46;  
 SCMD = 0xB9;  
 IFD  = IFD |= 0x08;  
 IFMT = 0x06;   
 SCMD = 0x46;  
 SCMD = 0xB9;  
 TR0  = 1 ;   
 while( ~TF0 ) 
 {   }
 TF0 = 0;   
 TR0  = 0;  
 IFMT = 0x07 ;  
 SCMD = 0x46 ;  
 SCMD = 0xB9 ;  
 IFD	= IFD |= 0x03 ;
 IFMT = 0x06;  
 SCMD = 0x46;  
 SCMD = 0xB9;  
 IFMT = 0x07;  
 SCMD = 0x46;  
 SCMD = 0xB9;  
 IFD = IFD &= 0xFB;  
 IFMT = 0x06;  
 SCMD = 0x46;  
 SCMD = 0x0B9;  
 
 PORT_Init();
 RTC_SCL = 1;
 RTC_SDA = 1;
 EEPROM_Init();
 LED_Init();
 T0_Init();
 T1_Init();
 AD3421_Init();
 InitUart();
 Set_mA(0);
 LED_Fill();
 Set_mV(0);
 Buzzer(0);
 Soft_Timer_Enable = 0;
 
 if((EEPROM_read_byte(0) != 'N')||(EEPROM_read_byte(1) != 'E')||(EEPROM_read_byte(2) != 'W')||(EEPROM_read_byte(3) != 0x5a)||(EEPROM_read_byte(4) != 0xa5))
 {
 EEPROM_write_byte(0, 'N');	
 EEPROM_write_byte(1, 'E');
 EEPROM_write_byte(2, 'W');
 EEPROM_write_byte(3, 0x5a);	
 EEPROM_write_byte(4, 0xa5);
 RTC_ON();	
 EEPROM_WriteDefault();
 }
 LED_Fill(); 
 Work_Type = EEPROM_read_byte(18);   	
 C_F_Type = EEPROM_read_byte(19);
 TC_Type  = EEPROM_read_byte(20);        
 TC_Zero_offset = EEPROM_read_word(22);	
 TC_Span_offset = EEPROM_read_word(24);
 RTD_Zero_offset = EEPROM_read_word(26);
 RTD_Span_offset = EEPROM_read_word(28);
 mV_Zero_offset = EEPROM_read_word(30);
 mV_Span_offset = EEPROM_read_word(32);
 mA_Zero_offset = EEPROM_read_word(34);	
 mA_Span_offset = EEPROM_read_word(36);
 alarm_Low_set = EEPROM_read_word(38);
 alarm_Hi_set = EEPROM_read_word(40);
 use_year = EEPROM_read_byte(42);
 use_mon = EEPROM_read_byte(43);
 use_day = EEPROM_read_byte(44);
 use_hour = EEPROM_read_byte(46);
 use_min = EEPROM_read_byte(47);
 use_sec = EEPROM_read_byte(48);
 
 use_flag =	EEPROM_read_byte(50);
 
 TC_Span_Value = EEPROM_read_word(52);
 RTD_Span_Value = EEPROM_read_word(54);
 mV_Span_Value = EEPROM_read_word(56);
 mA_Span_Value = EEPROM_read_word(58);
 Temp_offset  = EEPROM_read_word(60);
 
 Disp_year = use_year+0x2000;
 RTC_ON();
 
 
 ET0 = 1;
 TR0 = 1;
 ET1 = 1;
 TR1 = 1;
 EA  = 1;
 MAIN_SW = 1 ;
 
 Check_PCB();
 
 if(Work_Type == 0)
 { if(use_flag & 0x01) NG_COD = 1 ;}
 else if(Work_Type == 1)
 { if(use_flag & 0x02) NG_COD = 1 ;}
 else if(Work_Type == 2)
 { if(use_flag &0x04)  NG_COD = 1 ;}
 else if(Work_Type == 3)
 { if(use_flag & 0x08) NG_COD = 1 ;}
 
 
 while (1)
 {
 switch (Func_Type)
 {
 case 0:
 if(Work_Type == 0)
 { if(use_flag & 0x0010) {ADD_COD = 1;}else{ADD_COD = 0;}}
 DO_TC_TYPE();
 break;
 
 case 1:
 DO_RTD_TYPE();
 break;
 
 case 2:
 DO_mV_TYPE();
 break;
 
 case 3:
 DO_mA_TYPE();
 break;
 
 case 4:
 CAIT = 1 ;
 DO_SETUP_TYPE();
 
 break;
 
 case 5:
 DO_RESET_TYPE();
 break;
 }
 }
 }
