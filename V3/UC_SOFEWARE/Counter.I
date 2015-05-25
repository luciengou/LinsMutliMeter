
#line 1 "Counter.C" /0
  
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



 
 
 
 
 
 
 
 
#line 1 "Counter.C" /0
 
  
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
 
 
#line 2 "Counter.C" /0
 
 
 
 extern unsigned char Soft_Timer_Enable;
 extern idata unsigned char Soft_Timer[8];



 
 void Start_SleepCounter(unsigned char sec)
 {
 Soft_Timer[0] = sec;				   
 Soft_Timer_Enable |= 0x01;			   
 }
 
 void Stop_SleepCounter(void)		
 {
 Soft_Timer_Enable &= ~0x01;
 Soft_Timer[0] = 0;
 }
 
 unsigned char Is_SleepCounter_CountDown_Finish(void)
 {
 unsigned c;
 
 c = (Soft_Timer[0]==0)? 1 : 0;
 
 return c;
 }
 
 unsigned char Check_SleepCounter_Start(void)		 
 {
 unsigned c;
 
 c = (Soft_Timer_Enable & 0x01)? 1 : 0;
 
 return c;
 }



 
 void Start_KeyholdCounter(unsigned char sec)
 {																			   
 Soft_Timer[1] = sec;		 
 Soft_Timer_Enable |= 0x02;	 
 } 
 
 void Stop_KeyholdCounter(void)
 {
 Soft_Timer_Enable &= ~0x02;
 Soft_Timer[1] = 0;
 } 
 unsigned char Check_KeyholdCounter_Start(void)		 
 {
 unsigned c;
 
 c = (Soft_Timer_Enable & 0x02)? 1 : 0;
 
 return c;
 }
 unsigned char Is_KeyholdCounter_CountDown_Finish(void)
 {
 unsigned c;
 
 c = (Soft_Timer[1]==0)? 1 : 0;
 
 return c;
 }



 
 
 void Start_VoiceWaitCounter(unsigned char sec)
 {
 Soft_Timer[2] = sec;		 
 Soft_Timer_Enable |= 0x04;	 
 } 
 void Stop_VoiceWaitCounter(void)
 {
 Soft_Timer_Enable &= ~0x04;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
 Soft_Timer[2] = 0;
 } 
 unsigned char Check_VoiceWaitCounter_Start(void)		 
 {
 unsigned c;
 
 c = (Soft_Timer_Enable & 0x04)? 1 : 0;
 
 return c;
 }
 unsigned char Is_VoiceWaitCounter_CountDown_Finish(void)
 {
 unsigned c;
 
 c = (Soft_Timer[2]==0)? 1 : 0;
 
 return c;
 }



 
 void Start_WaterLackCounter(unsigned char sec)
 {
 Soft_Timer[3] = sec;		 
 Soft_Timer_Enable |= 0x08;	 
 } 
 void Stop_WaterLackCounter(void)
 {
 Soft_Timer_Enable &= ~0x08;
 Soft_Timer[3] = 0;
 } 
 unsigned char Check_WaterLackCounter_Start(void)		 
 {
 unsigned c;
 
 c = (Soft_Timer_Enable & 0x08)? 1 : 0;
 
 return c;
 }
 
 unsigned char Is_WaterLackCounter_CountDown_Finish(void)
 {
 unsigned c;
 
 c = (Soft_Timer[3]==0)? 1 : 0;
 
 return c;
 }  



 
 void Start_Ph_reflashCounter(unsigned char sec)
 {																			   
 Soft_Timer[4] = sec;		    
 Soft_Timer_Enable |= 0x10;	    
 } 
 
 void Stop_Ph_reflashCounter(void)
 {
 Soft_Timer_Enable &= ~0x10;
 Soft_Timer[4] = 0;
 } 
 unsigned char Check_Ph_reflashCounter_Start(void)		
 {
 unsigned c;
 
 c = (Soft_Timer_Enable & 0x10)? 1 : 0;
 
 return c;
 }
 unsigned char Is_Ph_reflashCounter_CountDown_Finish(void)
 {
 unsigned c;
 
 c = (Soft_Timer[4]==0)? 1 : 0;
 
 return c;
 }
 
