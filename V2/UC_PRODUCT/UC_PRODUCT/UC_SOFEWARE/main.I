
#line 1 "main.c" /0
  
#line 1 "C:\KEIL\C51\INC\MEGAWIN\MPC82G516.H" /0




 
 
 
 
 
 


 
 sfr P0       = 0x80;
 sfr SP       = 0x81;
 sfr DPL      = 0x82;
 sfr DPH      = 0x83;
 sfr SPISTAT  = 0x84;
 sfr SPICTL   = 0x85;
 sfr SPIDAT   = 0x86;
 sfr PCON     = 0x87;
 sfr TCON     = 0x88;
 sfr TMOD     = 0x89;
 sfr TL0      = 0x8A;
 sfr TL1      = 0x8B;
 sfr TH0      = 0x8C;
 sfr TH1      = 0x8D;
 sfr AUXR     = 0x8E;
 sfr STRETCH  = 0x8F;
 sfr P1       = 0x90;
 sfr P0M0     = 0x93;
 sfr P0M1     = 0x94;
 sfr P1M0     = 0x91;
 sfr P1M1     = 0x92;
 sfr P2M0     = 0x95;
 sfr P2M1     = 0x96;
 sfr EVRCR    = 0x97;
 sfr SCON     = 0x98;
 sfr SBUF     = 0x99;
 sfr S2BUF    = 0x9A;
 sfr P2       = 0xA0;
 sfr AUXR1    = 0xA2;
 sfr AUXR2    = 0xA6;
 sfr IE      = 0xA8;
 sfr SADDR   = 0xA9;
 sfr S2CON   = 0xAA;
 sfr AUXIE   = 0xAD;
 sfr AUXIP   = 0xAE;
 sfr AUXIPH  = 0xAF;
 sfr P3      = 0xB0;
 sfr P3M0    = 0xB1;
 sfr P3M1    = 0xB2;
 sfr P4M0    = 0xB3;
 sfr P4M1    = 0xB4;
 
 sfr IPH     = 0xB7;
 sfr IP      = 0xB8;
 sfr SADEN   = 0xB9;
 sfr S2BRT   = 0xBA;
 
 sfr ADCL    = 0xBE;
 sfr XICON   = 0xC0;
 sfr ADCTL   = 0xC5;
 sfr ADCH    = 0xC6;
 sfr ADC     = 0xC6;	
 sfr PCON2   = 0xC7;
 sfr T2CON   = 0xC8;
 sfr T2MOD   = 0xC9;
 sfr RCAP2L  = 0xCA;
 sfr RCAP2H  = 0xCB;
 sfr TL2     = 0xCC;
 sfr TH2     = 0xCD;
 
 sfr PSW     = 0xD0;
 sfr KBPATN  = 0xD5;
 sfr KBCON   = 0xD6;
 sfr KBMASK  = 0xD7;
 sfr CCON    = 0xD8;
 sfr CMOD    = 0xD9;
 sfr CCAPM0  = 0xDA;
 sfr CCAPM1  = 0xDB;
 sfr CCAPM2  = 0xDC;
 sfr CCAPM3  = 0xDD;
 sfr CCAPM4  = 0xDE;
 sfr CCAPM5  = 0xDF;
 
 sfr ACC     = 0xE0;
 sfr WDTCR     = 0xE1;
 sfr IFD       = 0xE2;
 sfr IFADRH    = 0xE3;
 sfr IFADRL    = 0xE4;
 sfr IFMT      = 0xE5;
 sfr SCMD      = 0xE6;
 sfr ISPCR     = 0xE7;
 sfr P4      = 0xE8;
 sfr CL      = 0xE9;
 sfr CCAP0L    = 0xEA;
 sfr CCAP1L    = 0xEB;
 sfr CCAP2L    = 0xEC;
 sfr CCAP3L    = 0xED;
 sfr CCAP4L    = 0xEE;
 sfr CCAP5L    = 0xEF;
 
 sfr B       = 0xF0;
 sfr PCAPWM0   = 0xF2;
 sfr PCAPWM1   = 0xF3;
 sfr PCAPWM2   = 0xF4;
 sfr PCAPWM3   = 0xF5;
 sfr PCAPWM4   = 0xF6;
 sfr PCAPWM5   = 0xF7;
 
 sfr CH        = 0xF9;
 sfr CCAP0H    = 0xFA;
 sfr CCAP1H    = 0xFB;
 sfr CCAP2H    = 0xFC;
 sfr CCAP3H    = 0xFD;
 sfr CCAP4H    = 0xFE;
 sfr CCAP5H    = 0xFF;


 
 sbit P0_0 = 0x80;
 sbit P0_1 = 0x81;
 sbit P0_2 = 0x82;
 sbit P0_3 = 0x83;
 sbit P0_4 = 0x84;
 sbit P0_5 = 0x85;
 sbit P0_6 = 0x86;
 sbit P0_7 = 0x87;


 
 sbit P1_0 = 0x90;
 sbit P1_1 = 0x91;
 sbit P1_2 = 0x92;
 sbit P1_3 = 0x93;
 sbit P1_4 = 0x94;
 sbit P1_5 = 0x95;
 sbit P1_6 = 0x96;
 sbit P1_7 = 0x97;
 
 
 sbit T2       = 0x90;
 sbit T2EX     = 0x91;
 sbit ECI      = 0x91;
 sbit S2RXD    = 0x92;
 sbit CEX0     = 0x92;
 sbit S2TXD    = 0x93;
 sbit CEX1     = 0x93;
 sbit SPI_SS   = 0x94;
 sbit CEX2     = 0x94;
 sbit SPI_MOSI = 0x95;
 sbit CEX3     = 0x95;
 sbit SPI_MISO = 0x96;
 sbit CEX4     = 0x96;
 sbit SPI_CLK  = 0x97;
 sbit CEX5     = 0x97;


 
 sbit P2_0 = 0xA0;
 sbit P2_1 = 0xA1;
 sbit P2_2 = 0xA2;
 sbit P2_3 = 0xA3;
 sbit P2_4 = 0xA4;
 sbit P2_5 = 0xA5;
 sbit P2_6 = 0xA6;
 sbit P2_7 = 0xA7;


 
 sbit P3_0 = 0xB0;
 sbit P3_1 = 0xB1;
 sbit P3_2 = 0xB2;
 sbit P3_3 = 0xB3;
 sbit P3_4 = 0xB4;
 sbit P3_5 = 0xB5;
 sbit P3_6 = 0xB6;
 sbit P3_7 = 0xB7;
 
 
 
 sbit RXD  = 0xB0;        
 sbit TXD  = 0xB1;        
 sbit INT0 = 0xB2;        
 sbit INT1 = 0xB3;        
 sbit T0   = 0xB4;        
 sbit T1   = 0xB5;        
 sbit WR   = 0xB6;        
 sbit RD   = 0xB7;        


 
 sbit P4_0 = 0xE8;
 sbit P4_1 = 0xE9;
 sbit P4_2 = 0xEA;
 sbit P4_3 = 0xEB;
 
 sbit INT3     = 0xEA;
 sbit INT2     = 0xEB;


 
 
 
 
 
 
 


 
 sbit IT0  = 0x88;
 sbit IE0  = 0x89;
 sbit IT1  = 0x8A;
 sbit IE1  = 0x8B;
 sbit TR0  = 0x8C;
 sbit TF0  = 0x8D;
 sbit TR1  = 0x8E;
 sbit TF1  = 0x8F;
 
 
 sbit IT2      = 0xC0;
 sbit IE2      = 0xC1;
 sbit EX2      = 0xC2;
 sbit PX2      = 0xC3;
 sbit IT3      = 0xC4;
 sbit IE3      = 0xC5;
 sbit EX3      = 0xC6;
 sbit PX3      = 0xC7;
 
 sbit CP_RL2   = 0xC8;
 sbit C_T2     = 0xC9;
 sbit TR2      = 0xCA;
 sbit EXEN2    = 0xCB;
 sbit TCLK     = 0xCC;
 sbit RCLK     = 0xCD;
 sbit EXF2     = 0xCE;
 sbit TF2      = 0xCF;


 
 
 
 
 
 
 
 
 
 
 


 
 sbit RI   = 0x98;
 sbit TI   = 0x99;
 sbit RB8  = 0x9A;
 sbit TB8  = 0x9B;
 sbit REN  = 0x9C;
 sbit SM2  = 0x9D;
 sbit SM1  = 0x9E;
 sbit SM0  = 0x9F;
 sbit FE   = 0x9F;
 
 


 
 sbit EX0  = 0xA8;        
 sbit ET0  = 0xA9;        
 sbit EX1  = 0xAA;        
 sbit ET1  = 0xAB;        
 sbit ES   = 0xAC;        
 sbit ET2  = 0xAD;        
 
 sbit EA   = 0xAF;        
 
 
 


 
 sbit PX0  = 0xB8;
 sbit PT0  = 0xB9;
 sbit PX1  = 0xBA;
 sbit PT1  = 0xBB;
 sbit PS   = 0xBC;
 sbit PT2  = 0xBD;


 
 sbit P    = 0xD0;
 sbit F1   = 0xD1;
 sbit OV   = 0xD2;
 sbit RS0  = 0xD3;
 sbit RS1  = 0xD4;
 sbit F0   = 0xD5;
 sbit AC   = 0xD6;
 sbit CY   = 0xD7;
 
 
 sbit CCF0   = 0xD8;
 sbit CCF1   = 0xD9;
 sbit CCF2   = 0xDA;
 sbit CCF3   = 0xDB;
 sbit CCF4   = 0xDC;
 sbit CCF5   = 0xDD;
 sbit CR     = 0xDE;
 sbit CF     = 0xDF;



 
 
 
 
 
 
 
 
#line 1 "main.c" /0
 
  
#line 1 "C:\KEIL\C51\INC\INTRINS.H" /0






 
 
 
 
 
 extern void          _nop_        (void);
 extern bit           _testbit_    (bit);
 extern unsigned char _cror_      (unsigned char, unsigned char);
 extern unsigned int  _iror_      (unsigned int,  unsigned char);
 extern unsigned long _lror_      (unsigned long, unsigned char);
 extern unsigned char _crol_      (unsigned char, unsigned char);
 extern unsigned int  _irol_      (unsigned int,  unsigned char);
 extern unsigned long _lrol_      (unsigned long, unsigned char);
 extern unsigned char _chkfloat_  (float);
 extern void           _push_      (unsigned char _sfr);
 extern void           _pop_       (unsigned char _sfr);
 
 
 
#line 2 "main.c" /0
 
  
#line 1 "LCM.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void LCM_Backlight(unsigned char BacklightValue);
 void LCM_all_point_on(void);
 void LCM_Init(void);
 void LCM_Cls(void);
 void LCM_Fill(void);
 void test(unsigned char column, unsigned char c);
 void LCM_Disp_Acid(unsigned char c);
 void LCM_Disp_Alka(unsigned char c);
 void LCM_Disp_PH_and_R(unsigned char *c);
 void LCM_Disp_KL(unsigned int VL, unsigned char mode);
 void LCM_Disp_WaterFlow(unsigned int i);
 void LCM_Disp_VOL_K2K3(void);
 void LCM_Disp_WashLiter(unsigned char c, unsigned char mode);
 void LCM_Disp_ORP(unsigned int ORP_Value, unsigned char ORP_Sign);
 void LCM_Disp_I_add(unsigned char c, unsigned char mode);
 void LCM_Disp_Error(unsigned char c, unsigned int t);
 void LCM_ClrL(void);
 void LCM_Disp_Version(unsigned char YY, unsigned int MD);
 
#line 3 "main.c" /0
 
  
#line 1 "LED.h" /0
 
 
 
 void LED_Disp(unsigned char led_status);
 void LED_Init(void);
 
 
#line 4 "main.c" /0
 
  
#line 1 "I2C.h" /0
















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void I2C_Init(void);
 void EEPROM_write_byte(unsigned char reg_addr, unsigned char reg_data);
 void DAC_write(unsigned char ch_id, unsigned int ma);
 void LDS6128_init(void);
 void PlaySound(unsigned char num);
 void Clear_key_delay(void);
 
 unsigned char	EEPROM_read_byte(unsigned char reg_addr);
 unsigned char KeyScan(void);
 unsigned char voicePlay(unsigned char id, unsigned char vol);
 unsigned char Get_Key(void);
 
 
 
 
 
#line 5 "main.c" /0
 
  
#line 1 "MCP4011.h" /0
 
 
 
 void Decrement_R(unsigned char value_up);          
 void Increment_R(unsigned char value_down);	  
 
 
#line 6 "main.c" /0
 
  
#line 1 "COUNTER.H" /0
 
 
 
 void Start_SleepCounter(unsigned char sec);
 void Stop_SleepCounter(void);
 unsigned char Check_SleepCounter_Start(void);
 unsigned char Is_SleepCounter_CountDown_Finish(void);
 
 void Start_KeyholdCounter(unsigned char sec);
 void Stop_KeyholdCounter(void);
 unsigned char Check_KeyholdCounter_Start(void);
 unsigned char Is_KeyholdCounter_CountDown_Finish(void);	
 
 void Start_Ph_reflashCounter(unsigned char sec);
 void Stop_Ph_reflashCounter(void);
 unsigned char Check_Ph_reflashCounter_Start(void);
 unsigned char Is_Ph_reflashCounter_CountDown_Finish(void);	
 
 void Start_WaterLackCounter(unsigned char sec);
 void Stop_WaterLackCounter(void);
 unsigned char Check_WaterLackCounter_Start(void);
 unsigned char Is_WaterLackCounter_CountDown_Finish(void);
 
 void Start_VoiceWaitCounter(unsigned char sec);
 void Stop_VoiceWaitCounter(void);
 unsigned char Check_VoiceWaitCounter_Start(void);
 unsigned char Is_VoiceWaitCounter_CountDown_Finish(void);
 
 
#line 7 "main.c" /0
 
  
#line 1 "LANGUAGE.H" /0
 
 
 
 
 
 
 
 const unsigned char code LAN0[5] = {18,14,19,6,18};    
 const unsigned char code LAN1[5] = {18,12,16,1,18};    
 const unsigned char code LAN2[5] = {18,15,15,10,18};   
 
 const unsigned char code *LANGUAGE_STRING[2] = {LAN0, LAN2};
 const unsigned char code  Machine_ID = 0x71;    
 
 
#line 8 "main.c" /0
 
  
#line 1 "ADC.H" /0
 
 
 
 
 void Init_ADC(void);
 void Get_ADC_Value(void);
 unsigned int WaterOverHot_warning(void);
 unsigned int PowerOverHot_warning(void);
 
 
#line 9 "main.c" /0
 
  
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
 
 
#line 10 "main.c" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 extern unsigned int KX;	
 extern unsigned int R;	
 extern unsigned char key_delay[16];
 
 sbit LCM_DataLE	    = P2^0; 
 sbit LED_DataLE	    = P2^1;
 sbit IO_DataLE		= P2^2;
 sbit IO_DataOE		= P3^5;
 sbit V_DETECT		= P1^0;
 unsigned char main_switch  = 1;
 unsigned char Operation_Mode;
 unsigned char electrolysis_type;
 idata unsigned char T0_cnt, T1_cnt;
 unsigned int Flow_Count = 0;
 unsigned int Flow_Speed = 0 ;   
 unsigned char tmp1;
 unsigned char VP02 = 0;
 unsigned char ADH;
 unsigned char ADL;
 idata unsigned char Soft_Timer[8]={0,0,0,0,0,0,0,0};
 unsigned char Soft_Timer_Enable = 0;
 unsigned char SleepEnable, Key_backup;
 unsigned char PVoice = 0;
 unsigned char Volume;
 unsigned char Language, WashLiter, r_step, r_step_max, r_step_cnt;
 
 bit f_half_sec, f_key_hold, f_water_out, f_alarm_no_water,f_Power_on,f_reflash;
 bit f_acid3=0, f_clean=0, f_lock, f_show_orp=0;
 
 const unsigned char code PH_tab[11][5] = {
 {17,16,1,0,8}, {17,16,18,9,5}, {17,16,18,9,0}, {17,16,18,8,0}, {17,16,18,7,0},
 
 {17,16,18,5,5}, {17,16,18,3,5}, {17,16,18,2,5}, {12,20,14,10,19}, {18,18,18,18,18},
 
 {17,20,22,5,18}
 };
 const unsigned char code tab_wash[7] = {10, 15, 20, 30, 40, 60, 80};
 const unsigned char code tab_voice[8] = {
 4, 3, 2, 1, 17, 6, 7, 5};
 const unsigned char code tab_graph[5] = {
 0x02, 0x0B, 0x2D, 0x36, 0x00};
 
 const int code tab_current[8] = {
 1800, 1600, 50, 10, 0, 600, 1200, 5000};
 
 const int code tab_i[8][7] = {
 {1700, 2050, 2400, 2700, 3050, 3400, 3700},
 { 800, 1150, 1500, 1800, 2150, 2500, 2800},
 {   0,  350,  700, 1000, 1370, 1700, 2000},
 {   0,  200,  400,  600,  950, 1300, 1600},
 {   0,    0,    0,    0,    0,    0,    0},    
 { 800, 1150, 1500, 1800, 2150, 2500, 2800},
 {1500, 1850, 2200, 2500, 2850, 3200, 3500},
 {2000, 2350, 2700, 3000, 3350, 3700, 4000}
 };
 
 const int code i_multiply[8] = {100,100,100,100,1,100,100,100};
 unsigned int code iORPValue[8] = {835,375,200,125,300,650,850,990};
 unsigned char code iORPValue_Falg[8] = {1,1,1,1,0,0,0,0};
 unsigned int xdata iORPValue_Disp[8] = {0,0,0,0,0,0,0,0};
 
 int kk, I_add_t, I_add[8];
 unsigned int Liter, left_FlowCnt, UseSec, UseHour;
 
 void delay(unsigned int i)
 {
 unsigned char j;
 for (; i>0; i--)
 for (j=0; j<255; j++);
 }
 
 void Buzzer(unsigned char status)
 {
 if (status)
 VP02 |= 0x20;
 else
 VP02 &= ~0x20;
 P0 = VP02;
 IO_DataLE = 1;
 _nop_();
 _nop_();
 _nop_();
 IO_DataLE=0;
 }
 
 void Acid_Polar(unsigned char status)
 {
 if (status)
 VP02 |= 0x40;
 else
 VP02 &= ~0x40;
 P0 = VP02;
 IO_DataLE = 1;
 _nop_();
 _nop_();
 _nop_();
 IO_DataLE=0;
 }
 
 void ex_int0(void) interrupt 0
 {
 Flow_Count++;	
 }
 
 void time0(void) interrupt  1      
 {
 TR0 = 0;
 T1_cnt++;
 if ((T1_cnt%8)==0)
 Get_ADC_Value();
 TH0 = 0x0B;
 TL0 = 0xDC;
 TR0 = 1;
 }
 
 void time1(void) interrupt   3    
 {
 TR1 = 0;
 T0_cnt++;
 
 if (Soft_Timer[4]!=0)		Soft_Timer[4]--;
 
 if ((T0_cnt%8)==0)
 f_half_sec = 1;
 
 if (T0_cnt == 16)
 {
 T0_cnt = 0;
 if (Soft_Timer[0]!=0)			    Soft_Timer[0]--;	
 if (Soft_Timer[1]!=0)			Soft_Timer[1]--;	
 if (Soft_Timer[2]!=0)		Soft_Timer[2]--;	
 if (Soft_Timer[3]!=0)			Soft_Timer[3]--;
 Flow_Speed = Flow_Count;
 if(Flow_Count>= 10) 
 {
 f_water_out = 1;
 }
 else 
 {
 f_water_out = 0 ;
 }
 }  	
 TH1 = 0x0B;
 TL1 = 0xDC;
 TR1 = 1;	
 }
 
 void T0_Init(void)
 {
 TR0 = 0;
 TMOD = 0x11;
 TH0 = 0x0B;
 TL0 = 0xDC;
 T0_cnt = 0;
 ET0 = 1;
 TR0 = 1;
 }
 
 void T1_Init(void)
 {
 TR1 = 0;
 TMOD = 0x11;
 TH1 = 0x0B;
 TL1 = 0xDC;
 T1_cnt = 0;
 Init_ADC();
 ET1 = 1;
 TR1 = 1;
 }
 
 void INT0_Init(void)
 {
 INT0 = 1;	 
 IE0  = 0;		   
 IT0  = 1;
 EX0  = 1;	  
 }
 
 void EEPROM_write_word(unsigned char addr, unsigned int intdata)
 {
 EEPROM_write_byte(addr++, (unsigned char)(intdata));
 EEPROM_write_byte(addr, (unsigned char)(intdata>>8));
 }
 
 unsigned int EEPROM_read_word(unsigned char addr)
 {
 unsigned int rdata;
 
 rdata = (unsigned int)(EEPROM_read_byte(addr+1));
 rdata <<= 8;
 rdata += (unsigned int)(EEPROM_read_byte(addr));
 
 return(rdata);	
 }
 
 void EEPROM_WriteDefault(void)
 {
 EEPROM_write_byte(18, 0);
 EEPROM_write_byte(19, 3);	
 EEPROM_write_byte(20, 1);
 EEPROM_write_word(21, 0);
 EEPROM_write_word(23, 0);
 EEPROM_write_word(25, 0);
 EEPROM_write_word(27, 0);
 EEPROM_write_byte(30, 20);	 
 EEPROM_write_byte(31, 20);	 
 EEPROM_write_byte(32, 20);	 
 EEPROM_write_byte(33, 20);	 
 EEPROM_write_byte(34, 20);	 
 EEPROM_write_byte(35, 20);	 
 EEPROM_write_byte(36, 20);	 
 EEPROM_write_byte(37, 20);	 
 
 }
 
 unsigned char Filter_time_is_up(void)
 {
 unsigned int i, reti;
 
 reti = 0;
 KX |= 0x1F0;
 i = UseHour/24;
 if (i >= 73)	KX &= ~0x0100;
 if (i >= 146)	KX &= ~0x0080;
 if (i >= 219)	KX &= ~0x0040;
 if (i >= 292)	KX &= ~0x0020;
 if (i >= 365)
 {
  KX &= ~0x0010;
 reti = 1;
 }
 return(reti);	 
 }
 
 void Disp_Alak(unsigned char c)
 {
  KX |= 0x2000;
  KX &= ~0x4000;
 LCM_Disp_Acid(0);
  KX |= 0x8000;
  R |= 0x0080;
 LCM_Disp_PH_and_R(PH_tab[4-c]);
 LCM_Disp_Alka(c);
 if (! f_alarm_no_water)
 LCM_Backlight(5-c);
 if (Operation_Mode == 1)   
 {
 LED_Disp ((5-c)|0x10);
 }
 else 
 {
 LED_Disp (5-c);
 }
 }
 
 void PORT_Init(void)
 {
 LCM_DataLE = 0;
 LED_DataLE = 0;
 IO_DataLE = 0;
 IO_DataOE	= 1;
 P0M1 = 0xFF;
 P1M0 = 0x01;
 P1M1 = 0x38;    
 P2M1 = 0xC7; 
 P3M1 = 0xF0;
 P3M0 = 0x04;
 P3 = 0;
 P0 = 0;	
 IO_DataLE = 1;
 _nop_();
 _nop_();
 _nop_();
 IO_DataLE=0;
 IO_DataOE = 0;  
 V_DETECT = 1;  
 P3_6 = 0;
 }
 
 void Disp_Filter(void)
 {
  KX |= 0x4000;
  KX &= ~0x2000;
  KX |= 0x8000;
  R |= 0x0080;
 LCM_Disp_Acid(0);
 LCM_Disp_Alka(0);
 LCM_Disp_PH_and_R(PH_tab[4]);
 if (! f_alarm_no_water)
 LCM_Backlight(5);
 
 if (Operation_Mode == 1)   
 {
 LED_Disp (0x15);
 }
 else
 {
 LED_Disp (0x05);
 }
 }
 
 void Disp_Clean(unsigned char c)
 {
  KX &= ~0x4000;
  KX &= ~0x2000;
  R &= ~0x0080;
 LCM_Disp_Acid(0);
 LCM_Disp_Alka(0);
 LCM_Disp_PH_and_R(PH_tab[8]);
 if (c)
 LCM_Backlight(7);
 else
 LCM_Backlight(5);
 }
 
 void Disp_Acid(unsigned char c)
 {
  KX &= ~0x4000;
  KX &= ~0x2000;
  KX |= 0x8000;
  R |= 0x0080;
 LCM_Disp_Alka(0);
 LCM_Disp_Acid(c);
 LCM_Disp_PH_and_R(PH_tab[c+4]);
 if (! f_alarm_no_water)
 LCM_Backlight(c+5);
 LED_Disp (c+5);
 if (Operation_Mode == 1)    
 {
 LED_Disp ((c+5)|0x10);
 }
 else
 {
 LED_Disp (c+5);
 }
 }
 
 void Init_Volt_Detect(void)
 {
 r_step = 0;
 r_step_max = 0;
 r_step_cnt = 0;
 Decrement_R(64);
 delay(1000);
 }
 
 void SetCurrent(int current)		 
 {
 int d[4];
 
 if (current >= 400)
 current+=100;
 if ((current > 0)&&(current <= 25))
 current = 20;
 else if ((current > 25)&&(current <= 42))
 current = 30;
 else if ((current > 42)&&(current <= 80))
 current = 40;
 else if ((current > 80)&&(current <= 100))
 current = 50;
 else if ((current > 100)&&(current <= 150))
 current = 60;
 else if ((current > 150)&&(current <= 200))
 current = 70;
 else if ((current > 200)&&(current <= 250))
 current = 80;
 else if ((current > 250)&&(current <= 300))
 current = 85;
 else if ((current > 300)&&(current <= 350))
 current = 90;
 else if ((current > 350)&&(current <= 400))
 current = 110;
 
 d[0] = d[1] = d[2] = d[3] = current/4;	 
 
 DAC_write(0, d[0]);
 delay(100);
 DAC_write(1, d[1]);
 delay(100);
 DAC_write(2, d[2]);
 delay(100);
 DAC_write(3, d[3]);
 Init_Volt_Detect();
 }
 
 void Disp_electrolysis_type(unsigned char type)
 {
 switch (type)
 {
 case 1:	Disp_Alak(4);			break;
 case 2:	Disp_Alak(3);			break;
 case 3:	Disp_Alak(2);			break;
 case 4:	Disp_Alak(1);			break;
 case 5:	Disp_Filter();			break;
 case 6:	Disp_Acid(1);			break;
 case 7:	Disp_Acid(2);			break;
 case 8:	Disp_Acid(3);			break;
 }
 }
 
 unsigned char CurrentSeg(unsigned int i)
 {
 unsigned char retc;
 
 if (i < 12)
 retc = 0;
 else if (i < 15)
 retc = 1;
 else if (i < 18)
 retc = 2;
 else if (i < 22)
 retc = 3;
 else if (i < 25)
 retc = 4;
 else if (i < 28)
 retc = 5;
 else
 retc = 6;
 
 return retc;
 }
 
 
 void Disp_test(void)
 {
 char i;
 for (i=0; i<8; i++)
 {
 while(! f_half_sec);
 f_half_sec = 0;
 if(i == 0)
 {
 LED_Disp(0x11);
 }
 else
 {
 LED_Disp(i+1);
 }
 LCM_Backlight(i+1);
 }
 }
 
 void do_reset(void)
 {
 unsigned char c=0, key;
 
 Clear_key_delay();	
 LCM_Backlight(5);
 LCM_Fill();
 PlaySound(29);
 Soft_Timer[4] = 16*5;
 key = Get_Key();
 while (key)
 key = Get_Key();
 
 while (Soft_Timer[4])
 {
 key = Get_Key();	
 if (key == 12)
 {
 PlaySound(30);
 EEPROM_WriteDefault();	
 Disp_test();
 main_switch = 0 ;
 break;
 }
 if ((Soft_Timer[4]/10)%2)
 LCM_Fill();	
 else
 LCM_Cls();			
 }
 Operation_Mode = 0;
 LCM_Cls();	
 }
 
 void Volt_Ctrl(void)
 {
 if (V_DETECT)
 {
 if (r_step_cnt < 200)
 {
 Increment_R(1);
 r_step++;
 }
 }
 else
 {
 if (r_step > r_step_max)
 {
 r_step_max = r_step;
 r_step_cnt = 0;
 Decrement_R(1);
 r_step--;
 }
 else
 {
 if (r_step == r_step_max)
 {
 r_step_cnt++;
 Decrement_R(1);
 r_step--;
 }			
 }
 }
 delay(50);
 }
 
 void Disp_FlowGraph(unsigned char GraphStep, unsigned char *PH_String)
 {
 unsigned int iTemp;
 unsigned char ORP_factor, vsp12;
 
 if (f_show_orp == 1)		 
 {
 vsp12 = 0;
 if (R & 0x0080)	vsp12 = 1;
 R = tab_graph[GraphStep];
  R |= 0x0100;
  R |= 0x0200;
 if (electrolysis_type == 5)
 iORPValue_Disp[electrolysis_type-1]=iORPValue[electrolysis_type-1];
 else
 {
 ORP_factor = (unsigned char)(rand()%100);
 iTemp = iORPValue[electrolysis_type-1]/20;
 if (ORP_factor >= 50)
 {
 ORP_factor = ORP_factor-50;
 iTemp = iTemp*ORP_factor/50;
 iORPValue_Disp[electrolysis_type-1] = iORPValue[electrolysis_type-1]+iTemp;
 }
 else
 {
 ORP_factor = 50-ORP_factor;
 iTemp = iTemp*ORP_factor/50;
 iORPValue_Disp[electrolysis_type-1] = iORPValue[electrolysis_type-1]-iTemp;
 }
 }
 if (iORPValue_Disp[electrolysis_type-1] > 999)
 iORPValue_Disp[electrolysis_type-1] = 999;
 LCM_Disp_ORP(iORPValue_Disp[electrolysis_type-1],iORPValue_Falg[electrolysis_type-1]);  
 if (vsp12)
  R |= 0x0080;
 }
 else
 {
 R = (R & 0x0080)? (tab_graph[GraphStep]|0x80) : tab_graph[GraphStep];
 LCM_Disp_PH_and_R(PH_String);
 }
 }
 
 void do_standby(void)
 {
 unsigned char key=0;
 unsigned char rr1=0, rr2=0, rr=0;
 unsigned int  LeftLiter;
 
 f_alarm_no_water = 0;
 f_water_out = 0 ;
 LeftLiter = 9000-Liter;
 Clear_key_delay();	
 key_delay[15-1] = 10;
 key_delay[10-1]   = 5;
 key_delay[11-1]   = 3;
 key_delay[16-1]  = 5;
 key_delay[14-1]  = 5;
 LED_Disp(electrolysis_type & 0xEF);	   
 Disp_electrolysis_type(electrolysis_type);
 
 if (f_lock){KX |= 0x0004;} 	else {KX &= ~0x0004;}
 
 LCM_Disp_VOL_K2K3();
 Filter_time_is_up();
 LCM_Disp_KL(9000-Liter, 0);
 LCM_Disp_WaterFlow(0);      	
 EX0 = 0;
 Flow_Count = 0;	
 Soft_Timer[4] = 16;
 EX0 = 1;
 
 while (Operation_Mode == 0)
 {
 key = Get_Key();
 
 if (key == 0)
 {
 if((f_reflash)&&(Operation_Mode == 0))		     
 {
 if (! Check_Ph_reflashCounter_Start())
 {
 Start_Ph_reflashCounter(160);		 
 }
 else
 {
 if (Is_Ph_reflashCounter_CountDown_Finish())    
 {
 Stop_Ph_reflashCounter();
 f_reflash = 0;
 
 if (! f_lock)
 {
 electrolysis_type = 2;
 Disp_electrolysis_type(electrolysis_type);
 }
 }
 }
 }
 else if (! SleepEnable)			 
 {
 if (! Check_SleepCounter_Start())
 Start_SleepCounter(60);		 
 else
 {
 if (Is_SleepCounter_CountDown_Finish())
 {
 Stop_SleepCounter();
 Operation_Mode = 2;
 }
 }
 } 
 if (f_water_out == 1)
 {
 Operation_Mode = 1;
 }
 }
 else
 {
 Stop_SleepCounter();		 
 
 switch (key)
 {
 case 10:
 Operation_Mode = 3;
 break;				
 
 case 14:
 PlaySound(30);
 LeftLiter = 9000;
  KX |= 0x0010;
  KX |= 0x0020;		
  KX |= 0x0040;
  KX |= 0x0080;		
  KX |= 0x0100;		
 LCM_Disp_KL(LeftLiter,0);
 EEPROM_write_word(21, 0);	 
 delay(300);
 EEPROM_write_word(23, 0);	 
 delay(300);
 EEPROM_write_word(25, 0);	 
 delay(300);
 EEPROM_write_word(27, 0);	 
 left_FlowCnt = 0;		
 Liter = 0;			
 UseSec = 0;			
 UseHour = 0;			
 break;
 
 case 16:
 Operation_Mode = 6;
 break;
 
 case 11:
 f_lock = ~f_lock;
 if (f_lock)
 {
 EEPROM_write_byte(18, 0x80+electrolysis_type); 
  KX |= 0x0004;
 PlaySound(Language+8);
 }
 else
 {
 EEPROM_write_byte(18, 0); 
  KX &= ~0x0004;
 PlaySound(Language+9);
 }
 LCM_Disp_VOL_K2K3();	 
 break;
 
 case 2:
 if (f_lock == 0)
 {
 electrolysis_type = 1;
 Disp_electrolysis_type(electrolysis_type);
 Stop_Ph_reflashCounter();
 f_reflash = 1;
 }
 break;
 
 case 3:
 if (f_lock== 0)
 {
 electrolysis_type = 2;
 Disp_electrolysis_type(electrolysis_type);
 f_reflash = 0;
 }
 break;	
 
 case 4:
 if (f_lock== 0)
 {
 electrolysis_type = 3;
 Disp_electrolysis_type(electrolysis_type);
 Stop_Ph_reflashCounter();
 f_reflash = 1;
 }
 break;
 
 case 5:
 if (f_lock== 0)
 {
 electrolysis_type = 4;
 Disp_electrolysis_type(electrolysis_type);
 Stop_Ph_reflashCounter();
 f_reflash = 1;
 }
 break;
 
 case 6:
 if (f_lock==0)
 {
 electrolysis_type = 5;
 Disp_electrolysis_type(electrolysis_type);
 Stop_Ph_reflashCounter();
 f_reflash = 1;
 }
 break;
 
 case 7:
 if (f_lock==0)
 {
 electrolysis_type = 6;
 Disp_electrolysis_type(electrolysis_type);
 Stop_Ph_reflashCounter();
 f_reflash = 1;
 }
 break;
 
 case 8:
 if (f_lock==0)
 {
 electrolysis_type = 7;
 Disp_electrolysis_type(electrolysis_type);
 Stop_Ph_reflashCounter();
 f_reflash = 1;
 }
 break;
 
 case 9:
 if (f_lock==0)
 {
 electrolysis_type = 8;
 Disp_electrolysis_type(electrolysis_type);
 Stop_Ph_reflashCounter();
 f_reflash = 1;
 }
 break;
 
 case 13:
 Volume++;
 Volume &= 0x03;
 PlaySound(0x30+Volume);
 if (Volume==0)
 {
  KX &= ~0x0400;		KX &= ~0x0800;		KX &= ~0x1000;
 }
 if (Volume==1)
 {
  KX |= 0x0400;		KX &= ~0x0800;		KX &= ~0x1000;
 }
 if (Volume==2)
 {
  KX |= 0x0400;		KX |= 0x0800;		KX &= ~0x1000;
 }
 if (Volume==3)
 {
  KX |= 0x0400;		KX |= 0x0800;		KX |= 0x1000;
 }
 LCM_Disp_VOL_K2K3();
 PlaySound(28);
 break;
 }
 }
 if (PowerOverHot_warning())
 {
 Operation_Mode = 5;
 }
 if (f_water_out == 1)
 {
 
 
 if ((electrolysis_type >= 1)&&(electrolysis_type < 8)&&(f_acid3))
 {
 Operation_Mode = 4;
 }
 else
 {
 if (f_clean)
 {
 Operation_Mode = 4;
 }
 else
 {
 Operation_Mode = 1;
 }
 }
 }
 LED_Disp(electrolysis_type);
 }
 }
 
 
 void do_electrolyze(void)
 {
 int set_i;
 unsigned char key=0;					 
 unsigned char rr=0, rr1=0;
 unsigned int LeftLiter, flow_cnt_tmp[2]={0,0};
 unsigned char Time_of_NoWater=0;
 unsigned char NoWaterVoice_Counter=0;
 unsigned char seg0=0, seg1;
 bit rr2=0;
 
 f_half_sec = 0;
 Soft_Timer_Enable |= 0x10;	
 LED_Disp(electrolysis_type | 0x10);				
 f_alarm_no_water = 0;
 LeftLiter = 9000-Liter;
 PVoice = tab_voice[electrolysis_type-1];
 Clear_key_delay();	
 key_delay[11-1] = 3;
 
 if (electrolysis_type > 5) {Acid_Polar(1);}
 EX0 = 0;
 Soft_Timer[4] = 16;             
 EX0 = 1;
 
 while (Operation_Mode == 1) 
 {
 Volt_Ctrl();
 key = Get_Key();
 
 if (electrolysis_type != 8)
 {
 if (f_lock == 0)
 { 
 switch (key)
 {
 case 2:
 
 Acid_Polar(0);
 electrolysis_type = 1;
 Disp_electrolysis_type(electrolysis_type);
 PVoice = tab_voice[electrolysis_type-1];
 seg0 = 7;
 
 break;
 
 case 3:
 
 Acid_Polar(0);
 electrolysis_type = 2;
 Disp_electrolysis_type(electrolysis_type);
 PVoice = tab_voice[electrolysis_type-1];
 seg0 = 7;
 
 break;	
 
 case 4:
 
 Acid_Polar(0);
 electrolysis_type = 3;
 Disp_electrolysis_type(electrolysis_type);
 PVoice = tab_voice[electrolysis_type-1];
 seg0 = 7;
 
 break;
 
 case 5:
 
 Acid_Polar(0);
 electrolysis_type = 4;
 Disp_electrolysis_type(electrolysis_type);
 PVoice = tab_voice[electrolysis_type-1];
 seg0 = 7;
 
 break;		
 
 case 6:
 
 Acid_Polar(0);
 electrolysis_type = 5;
 Disp_electrolysis_type(electrolysis_type);
 PVoice = tab_voice[electrolysis_type-1];
 seg0 = 7;
 
 break;
 
 case 7:
 
 Acid_Polar(1);
 electrolysis_type = 6;
 Disp_electrolysis_type(electrolysis_type);
 PVoice = tab_voice[electrolysis_type-1];
 seg0 = 7;
 
 break;
 
 case 8:
 
 Acid_Polar(1);
 electrolysis_type = 7;
 Disp_electrolysis_type(electrolysis_type);
 PVoice = tab_voice[electrolysis_type-1];
 seg0 = 7;
 
 break;
 }
 }
 switch(key)
 {
 case 11:
 f_lock = ~f_lock;
 
 if (f_lock)
 {
 EEPROM_write_byte(18, 0x80+electrolysis_type); 
  KX |= 0x0004;
 PlaySound(Language+8);
 }
 else
 {
 EEPROM_write_byte(18, 0); 
  KX &= ~0x0004;
 PlaySound(Language+9);
 }
 LCM_Disp_VOL_K2K3();	 
 break;
 
 case 10:
 if (! f_show_orp)
 {
 f_show_orp = 1;
  R |= 0x0200;
  R |= 0x0100;
 }
 else
 {
 f_show_orp = 0;
  R &= ~0x0200;
  R &= ~0x0100;
 }
 break;
 
 case 13:
 Volume++;
 Volume &= 0x03;
 PlaySound(0x30+Volume);
 if (Volume==0){ KX &= ~0x0400; KX &= ~0x0800; KX &= ~0x1000;	}
 if (Volume==1){ KX |= 0x0400;	KX &= ~0x0800; KX &= ~0x1000;	}
 if (Volume==2){ KX |= 0x0400;	KX |= 0x0800; KX &= ~0x1000;	}
 if (Volume==3){ KX |= 0x0400;	KX |= 0x0800; KX |= 0x1000;	}
 LCM_Disp_VOL_K2K3();
 PlaySound(28);
 break;
 }
 }
 
 if (f_half_sec)	
 {
 Disp_FlowGraph(rr, PH_tab[electrolysis_type-1]);
 
 if (! f_alarm_no_water)		 
 {	
 if (rr==4)
 rr = 0;
 else
 rr++;
 }
 else
 {
 rr = 4;
 if (KX & 0x0002)
  KX &= ~0x0002;
 else	
  KX |= 0x0002;
 LCM_Disp_VOL_K2K3();	 
 }
 if (LeftLiter > 0)
 rr1 &= ~0x02;
 else							 
 {
 if (rr2)
 rr1 |= 0x02;
 else      
 rr1 &= ~0x02;
 }
 if (! Filter_time_is_up())
 rr1 &= ~0x01;
 else							 
 {
 if (rr2)
 rr1 |= 0x01;
 else
 rr1 &= ~0x01;
 }
 rr2 = ~rr2;
 LCM_Disp_KL(LeftLiter, rr1);		 
 
 if ((PowerOverHot_warning())||(WaterOverHot_warning()))
 {
 Operation_Mode = 5;
 key = 17;
 }
 f_half_sec = 0;
 }
 
 if (Soft_Timer[4]==0)	 
 {
 EX0 = 0;
 
 flow_cnt_tmp[1] = Flow_Count;
 Flow_Count = 0;
 Soft_Timer[4] = 16;
 EX0 = 1;
 
 left_FlowCnt += flow_cnt_tmp[1];
 
 Flow_Speed = (flow_cnt_tmp[1]+flow_cnt_tmp[0])*10/128; 
 LCM_Disp_WaterFlow(Flow_Speed); 
 }
 
 if (flow_cnt_tmp[1] > 6)
 {
 seg1 = CurrentSeg(Flow_Speed);
 if (seg1 != seg0)
 {				
 set_i = tab_i[electrolysis_type-1][seg1]; 
 if (set_i < 0)
 set_i = 0;
 if (set_i > 5000)
 set_i = 5000;
 SetCurrent(set_i);
 seg0 = seg1;
 }
 }
 if (Liter < 9000)
 {
 if (left_FlowCnt >= 770)
 {
 Liter++;
 if (Liter%WashLiter==0)
 f_clean = 1;
 left_FlowCnt %= 770;
 }
 }
 LeftLiter = 9000-Liter;
 
 if (UseHour < 8760)
 {
 UseSec++;
 if (UseSec >= 3600)
 {
 UseSec %= 3600;
 UseHour++;
 }
 }
 if (Flow_Speed < 6)
 {
 f_water_out = 0;
 SetCurrent(0);	
 seg0 = 7;
 }
 else
 {
 f_water_out = 1;
 flow_cnt_tmp[0] = flow_cnt_tmp[1];
 }
 
 
 
 
 
 
 
 
 if (PVoice != 0)
 {
 PlaySound(Language+PVoice);
 PVoice = 0;
 }
 
 if ((f_water_out == 0)&&(Soft_Timer[4]==1))	               
 {
 key = 17;	
 Operation_Mode = 0;
 }
 else				            
 {
 Time_of_NoWater=0;
 NoWaterVoice_Counter = 0;
 Stop_WaterLackCounter();
 
 if (f_alarm_no_water)		 
 {
 f_alarm_no_water = 0;
  KX &= ~0x0002;
 LCM_Disp_VOL_K2K3();
 PVoice = tab_voice[electrolysis_type-1];
 LCM_Backlight(electrolysis_type);
 Soft_Timer_Enable &= ~0x10;
 EX0 = 0;
 PVoice = 0;
 }
 if ((LeftLiter < 90)||(UseHour > 7884))		 
 {
 if ((LeftLiter == 0) || (UseHour == 8760))
 PVoice = 13;		                  
 else 
 PVoice = 12;		                  
 PlaySound(Language+PVoice);	             
 PVoice = 0;
 delay(15000);
 }
 }
 }
 R &= 0xC0;	 
 LCM_Disp_PH_and_R(PH_tab[electrolysis_type-1]);
 LED_Disp(electrolysis_type & 0xef);
 LCM_Disp_WaterFlow(0);       
 Flow_Count = 0;
  KX &= ~0x0002;
 LCM_Disp_VOL_K2K3();
 
 Decrement_R(64);
 SetCurrent(0);
 Acid_Polar(0);
 EEPROM_write_word(21, left_FlowCnt);
 EEPROM_write_word(23, Liter);
 EEPROM_write_word(25, UseSec);
 EEPROM_write_word(27, UseHour);
 
 if (Operation_Mode != 5)
 {
 LED_Disp(electrolysis_type & 0xef);
 Operation_Mode = 0;
 PlaySound(Language+25);		 
 f_Power_on = 0; 
 }
 if (electrolysis_type == 8)
 {
 f_acid3 = 1;
 f_show_orp = 0;
 Stop_WaterLackCounter();
 }
 }
 
 void do_clean(unsigned char c)  
 {
 unsigned char rr1=0, rr=0;
 unsigned int LeftLiter;
 unsigned char NoWaterVoice_Counter=0;
 unsigned char Time_of_NoWater=0;
 unsigned int i1=3000;
 bit rr2=0;
 
 
 EX0 = 0;
 f_half_sec = 0;
 
 Soft_Timer_Enable |= 0x10;					
 Flow_Count = 0;
 Soft_Timer[4] = 16;
 EX0 = 1;
 
 f_alarm_no_water = 0;
 LeftLiter = 9000-Liter;
 
 Disp_Clean(c);
 
 PVoice = 16;						 
 Start_SleepCounter(60);
 if (c)
 {
 Acid_Polar(1);
 SetCurrent(i1);
 }
 
 while (1)		 
 {
 KeyScan();
 if (c)
 Volt_Ctrl();
 
 if (Is_SleepCounter_CountDown_Finish())		 
 {
 Stop_SleepCounter();
 break;   		 
 }
 
 if (f_half_sec)		 
 {
 if (! f_alarm_no_water)		 
 {
 Disp_FlowGraph(rr++, PH_tab[8]);
 if (rr==4)	rr = 0;
 }
 else						
 {
 if (KX & 0x0002)
  KX &= ~0x0002;
 else	
  KX |= 0x0002;
 LCM_Disp_VOL_K2K3();	 
 }
 
 
 
 if (LeftLiter > 0)
 rr1 &= ~0x02;
 else
 {
 if (rr2)
 rr1 |= 0x02;
 else
 rr1 &= ~0x02;
 }
 if (! Filter_time_is_up())
 rr1 &= ~0x01;
 else	
 {
 if (rr2)
 rr1 |= 0x01;
 else
 rr1 &= ~0x01;
 }
 rr2 = ~rr2;
 LCM_Disp_KL(LeftLiter, rr1);
 
 if ((PowerOverHot_warning())||(WaterOverHot_warning()))
 {
 Operation_Mode = 5;
 break;
 }
 
 f_half_sec = 0;
 }
 
 if (Soft_Timer[4]==0)	 
 {
 EX0 = 0;
 left_FlowCnt += Flow_Count;
 
 LCM_Disp_WaterFlow(Flow_Speed*24/128);
 
 if (Flow_Count < 6)	   
 f_water_out = 0;
 else
 f_water_out = 1;
 Flow_Count = 0;
 Soft_Timer[4] = 16;
 EX0 = 1;
 
 if (Liter < 9000)
 {
 if (left_FlowCnt >= 770)
 {
 Liter++;
 left_FlowCnt %= 770;
 }
 }
 LeftLiter = 9000-Liter;
 
 if (f_water_out == 1)
 {
 if (UseHour < 8760)
 {
 UseSec++;
 if (UseSec >= 3600)
 {
 UseSec %= 3600;
 UseHour++;
 }
 }
 }
 }
 
 if (f_water_out == 0)	 
 {
 Stop_SleepCounter();
 break;   		 
 }
 else				 
 {
 if (PVoice != 0)
 {
 PlaySound(Language+PVoice);
 PVoice = 0;
 }
 if (c)
 {
 if (i1== 0)
 {
 SetCurrent(3000);
 i1 = 3000;
 }	
 }			
 }
 }										 
 Soft_Timer_Enable &= ~0x10;
 EX0 = 0;
 
 PVoice = 0;
 if ((LeftLiter < 90) || (UseHour > 7884))
 {
 if ((LeftLiter == 0) || (UseHour == 8760))
 PVoice = 13;
 else
 PVoice = 12;
 PlaySound(Language+PVoice);
 PVoice = 0;
 delay(15000);
 }
 
 R &= 0xC0;	 
 LCM_Disp_PH_and_R(PH_tab[electrolysis_type-1]);
 Flow_Count = 0;
 LCM_Disp_WaterFlow(0);	 
  KX &= ~0x0002;
 LCM_Disp_VOL_K2K3();
 Stop_WaterLackCounter();
 Stop_VoiceWaitCounter();
 SetCurrent(0);
 Acid_Polar(0);
 EEPROM_write_word(21, left_FlowCnt);
 EEPROM_write_word(23, Liter);
 EEPROM_write_word(25, UseSec);
 EEPROM_write_word(27, UseHour);
 
 
 if (Operation_Mode != 5)
 {
 Operation_Mode = 0;
 PlaySound(Language+22);						 
 }
 
 
 if (c)
 f_clean = 0;
 else
 f_acid3 = 0;
 }
 
 void do_sleep(void)
 {
 if(f_water_out == 0)
 {
 LCM_Backlight(0);
 LCM_Cls();
 LED_Disp(0x00);
 Clear_key_delay();
 
 if(Get_Key() != 0);
 {
 Operation_Mode = 0;
 }
 }
 else
 {
 
 Operation_Mode = 1;
 }
 }
 
 
 
 void do_setup(void)
 {
 unsigned char tmp, tmp1, vx3;
 
 unsigned char item             = 0;
 unsigned char PH_FUNCTION      = 1;
 unsigned char CURRENT_FUNCTION = 2;
 unsigned char LANG_FUNCTION    = 3;
 unsigned char CLEAN_FUNCTION   = 4;
 unsigned char SETUP_FUNCTION   = 5;
 unsigned char NOMAL_FUNCTION   = 0;
 
 unsigned char cExit;
 unsigned char key=0, rr=0;
 unsigned int LeftLiter;
 
 
 PlaySound(28);
  R &= ~0x0080;
 vx3 = 0;
 if (KX & 0x0800)	vx3 = 1;
  KX &= ~0x0800;
  R &= ~0x0100;
  KX &= ~0x8000;
  KX &= ~0x2000;
  KX &= ~0x4000;
 LCM_Backlight(5);
 Clear_key_delay();
 key_delay[10-1] = 5;
 
 while (item < SETUP_FUNCTION)
 {
 if (item == NOMAL_FUNCTION)
 {
 LCM_Cls();
  KX &= ~0x8000;
 tmp = EEPROM_read_byte(30);
 LCM_Disp_PH_and_R(PH_tab[10]);
 LCM_Disp_I_add(tmp, 1);
 
 cExit = 0;
 
 while (! cExit)
 {
 key = Get_Key();
 if (f_half_sec)
 {
 if (rr == 0)
 LCM_Disp_I_add(tmp, 1);
 else 
 LCM_Disp_I_add(tmp, 0);
 
 rr++;
 rr &= 0x01;
 f_half_sec = 0;
 }
 switch (key)
 {
 case 10:
 cExit = 1;	 
 item = SETUP_FUNCTION;		 
 break;		
 
 case 12:
 PlaySound(31);
 cExit = 1;	 
 item = PH_FUNCTION;
 I_add_t = tmp;
 EEPROM_write_byte(30, tmp);
 break;
 
 case 13:
 
 if (tmp > 0)
 {
 PlaySound(30);
 tmp--;
 LCM_Disp_I_add(tmp, 1);
 }
 break;
 
 case 11:
 if (tmp < 40)
 {
 PlaySound(30);
 tmp++;
 LCM_Disp_I_add(tmp, 1);
 }
 break;
 
 }
 
 }
 
 }
 if (item == PH_FUNCTION)
 {
 LCM_Cls();
 rr = 1;
  KX &= ~0x8000;
 tmp = 1;
 tmp1 = 1;
 cExit = 0;
  R |= 0x0080;
  KX |= 0x2000;
 LCM_Disp_Alka(3);
 LCM_Disp_Acid(0);
 LCM_Disp_PH_and_R(PH_tab[tmp]);
 
 while (! cExit)
 {
 key = Get_Key();
 if (f_half_sec)
 {
 if (rr == 0)
 {
  R |= 0x0080;
 LCM_Disp_PH_and_R(PH_tab[tmp1]);
 }
 else 
 {
  R &= ~0x0080;
 LCM_Disp_PH_and_R(PH_tab[9]);		 
 }
 
 rr++;
 rr &= 0x01;
 f_half_sec = 0;
 }
 
 switch (key)
 {
 case 10:
 cExit = 1;	 
 item = SETUP_FUNCTION;		 
 break;		
 
 case 12:
 PlaySound(31);
 cExit = 1;	 
 item = CURRENT_FUNCTION;
 break;
 
 case 13:
 PlaySound(30);
 if (tmp == 0)
 tmp = 6;
 else
 tmp--;
 if (tmp > 3)
 {
 tmp1 = tmp+1;							
  KX &= ~0x2000;
 LCM_Disp_Alka(0);
 LCM_Disp_Acid(tmp-3);
 }
 else
 {
 tmp1 = tmp;
  KX |= 0x2000;
 LCM_Disp_Alka(4-tmp);
 LCM_Disp_Acid(0);
 }
  R |= 0x0080;
 LCM_Disp_PH_and_R(PH_tab[tmp1]);
 break;
 
 
 case 11:
 PlaySound(30);
 tmp++;
 if (tmp == 7)	tmp = 0;
 if (tmp > 3)
 {
 tmp1 = tmp+1;							
  KX &= ~0x2000;
 LCM_Disp_Alka(0);
 LCM_Disp_Acid(tmp-3);
 }
 else
 {
 tmp1 = tmp;
  KX |= 0x2000;
 LCM_Disp_Alka(4-tmp);
 LCM_Disp_Acid(0);
 }
  R |= 0x0080;
 LCM_Disp_PH_and_R(PH_tab[tmp1]);
 break;
 }
 }
 
 }
 if (item == CURRENT_FUNCTION)
 {
  R |= 0x0080;
 LCM_Disp_PH_and_R(PH_tab[tmp1]);
 tmp1 = EEPROM_read_byte(31+tmp);
  KX &= ~0x8000;
 LCM_Disp_I_add(tmp1, 1);
 
 cExit = 0;
 
 while (! cExit)
 {
 key = Get_Key();
 if (f_half_sec)
 {
 if (rr == 0)
 LCM_Disp_I_add(tmp1, 1);
 else 
 LCM_Disp_I_add(tmp1, 0);
 
 rr++;
 rr &= 0x01;
 f_half_sec = 0;
 }
 switch (key)
 {
 case 10:
 cExit = 1;	 
 item = SETUP_FUNCTION;		 
 break;		
 
 case 12:
 PlaySound(31);
 cExit = 1;	 
 item = LANG_FUNCTION;
 EEPROM_write_byte(31+tmp, tmp1);
 if (tmp > 3)
 tmp++;
 I_add[tmp] = tmp1;
 break;
 
 case 13:
 
 if (tmp1 > 0)
 {
 PlaySound(30);
 tmp1--;
 LCM_Disp_I_add(tmp1, 1);
 }
 break;
 
 case 11:
 if (tmp1 < 40)
 {
 PlaySound(30);
 tmp1++;
 LCM_Disp_I_add(tmp1, 1);
 }
 break;
 
 }
 }
 }
 if (item == LANG_FUNCTION)
 {
 LCM_Cls();
  KX &= ~0x2000;
 LCM_Disp_Alka(0);
 LCM_Disp_Acid(0);
  KX &= ~0x8000;
  R &= ~0x0080;
 tmp = Language/64;
 LCM_Disp_PH_and_R(LANGUAGE_STRING[tmp]);
 
 cExit = 0;
 
 while (! cExit)
 {
 key = Get_Key();
 if (f_half_sec)
 {
 if (rr == 0)
 LCM_Disp_PH_and_R(LANGUAGE_STRING[tmp]);
 else 
 LCM_Disp_PH_and_R(PH_tab[9]);		 
 
 rr++;
 rr &= 0x01;
 f_half_sec = 0;
 }
 
 switch (key)
 {
 case 10:
 cExit = 1;	 
 item = SETUP_FUNCTION;		 
 break;		
 
 case 12:
 PlaySound(31);
 cExit = 1;	 
 item = CLEAN_FUNCTION;
 EEPROM_write_byte(20, tmp);
 Language = tmp*64;
 break;
 
 case 13:
 case 11:
 PlaySound(30);
 tmp++;
 tmp &= 0x01;
 LCM_Disp_PH_and_R(LANGUAGE_STRING[tmp]);
 break;
 }
 }
 }
 if (item == CLEAN_FUNCTION)
 {
 tmp = EEPROM_read_byte(19);
 LCM_Cls();
 LCM_Disp_PH_and_R(PH_tab[8]);
 Filter_time_is_up();
 LeftLiter = 9000-Liter;
 LCM_Disp_KL(LeftLiter, 0);
 LCM_Disp_WashLiter(tab_wash[tmp], 1);
 
 cExit = 0;
 rr = 0;
 
 while (! cExit)
 {
 key = Get_Key();
 
 if (f_half_sec)
 {
 if (rr)
 LCM_Disp_WashLiter(tab_wash[tmp], 1);
 else
 LCM_Disp_WashLiter(tab_wash[tmp], 0);
 rr++;
 rr &= 0x01;
 f_half_sec = 0;
 }
 
 switch (key)
 {
 case 10:
 cExit = 1;	 
 item = SETUP_FUNCTION;		 
 break;			
 
 case 12:
 PlaySound(31);
 cExit = 1;	 
 item = NOMAL_FUNCTION;
 EEPROM_write_byte(19, tmp);
 WashLiter = tab_wash[tmp];
 break;
 
 case 13:
 PlaySound(30);
 if (tmp == 0)
 tmp = 6;
 else	
 tmp--;
 LCM_Disp_WashLiter(tab_wash[tmp], 1);
 break;
 
 case 11:
 PlaySound(30);
 tmp++;
 if (tmp == 7)
 tmp = 0;
 LCM_Disp_WashLiter(tab_wash[tmp], 1);
 break;
 }
 }
 }
 }
 
 PlaySound(28);
 if (vx3)
  KX |= 0x0800;
 Operation_Mode = 0;	
 }
 
 
 void do_warning(void)
 {
 unsigned char ErrCode, voice;
 unsigned int t0, t1;
 
 LCM_Cls();
 LCM_Backlight(8);
 
 t0 = PowerOverHot_warning();
 if (t0)
 {
 ErrCode = 1;
 voice = 21;
 LCM_Disp_Error(ErrCode, t0);
 }
 t1 = WaterOverHot_warning();
 if (t1)
 {
 ErrCode = 2;
 voice = 19;
 LCM_Disp_Error(ErrCode, t1);
 }
 PlaySound(Language+voice);		 
 Start_SleepCounter(59);		 
 while (1)
 {
 if (Is_SleepCounter_CountDown_Finish())
 {
 Stop_SleepCounter();
 break;
 }
 if (((Soft_Timer[0] % 10)==0)&&(Soft_Timer[0]>40))
 PlaySound(Language+voice);		 
 }	
 Operation_Mode = 2;	
 }
 
 main(void)
 {
 PORT_Init();
 I2C_Init();
 LED_Init();
 LCM_Init();
 LCM_Fill();
 LCM_Disp_KL(31320,0);          
 T0_Init();
 T1_Init();
 INT0_Init();
 LDS6128_init();
 EA = 1;
 LCM_Backlight(3);
 SetCurrent(0);
 Decrement_R(64);
 Buzzer(0);
 f_key_hold = 0;
 f_water_out = 0;
 SleepEnable = 1;
 Key_backup = 0;
 Soft_Timer_Enable = 0;
 EX0 = 0;
  KX |= 0x0200;
  KX |= 0x0400;
  KX |= 0x0800;
 KX &= ~0x1F0;		
 
 
 if ((EEPROM_read_byte(0) != 'A')||(EEPROM_read_byte(1) != 90)||(EEPROM_read_byte(2) != 2)||(EEPROM_read_byte(3) != 0x5a)||(EEPROM_read_byte(4) != 0xa5))
 {
 EEPROM_write_byte(0, 'A');	
 EEPROM_write_byte(1, 90);
 EEPROM_write_byte(2, 2);
 EEPROM_write_byte(3, 0x5a);	
 EEPROM_write_byte(4, 0xa5);	
 EEPROM_WriteDefault();	
 }
 
 Volume = EEPROM_read_byte(18);
 if (Volume & 0x80)		              
 {
 electrolysis_type = Volume & 0x7F;
 f_lock = 1;
 }
 else
 {
 electrolysis_type = 2;
 f_lock = 0;
 }
 
 Volume = 2;
 PlaySound(0x30+Volume);
 Disp_test();                                 
 PlaySound(29);                               
 
 LCM_Cls();
 WashLiter = tab_wash[EEPROM_read_byte(19)];	 
 Language = (EEPROM_read_byte(20))*0x00;		 
 left_FlowCnt = EEPROM_read_word(21);		 
 Liter = EEPROM_read_word(23);				 
 UseSec = EEPROM_read_word(25);			     
 UseHour = EEPROM_read_word(27);			     
 LCM_Disp_VOL_K2K3();
 Filter_time_is_up();
 LCM_Disp_KL(9000-Liter, 0);
 
 I_add_t  = EEPROM_read_byte(30);
 I_add[0] = EEPROM_read_byte(31);
 I_add[1] = EEPROM_read_byte(32);
 I_add[2] = EEPROM_read_byte(33);
 I_add[3] = EEPROM_read_byte(34);
 I_add[4] = 0;
 I_add[5] = EEPROM_read_byte(35);
 I_add[6] = EEPROM_read_byte(36);
 I_add[7] = EEPROM_read_byte(37);
 Init_ADC();
 
 Operation_Mode = 0;
 
 
 while (1)
 {
 switch (Operation_Mode)
 {
 case 0:
 do_standby();
 break;
 
 case 1:
 do_electrolyze();
 break;
 
 case 2:
 do_sleep();
 break;
 
 case 4:
 if (f_acid3)
 do_clean(0);
 else if (f_clean)
 do_clean(1);
 break;
 
 case 5:
 do_warning();
 break;
 
 case 6:
 do_reset();
 break;
 
 case 3:
 do_setup();
 break;				
 }
 }
 }
