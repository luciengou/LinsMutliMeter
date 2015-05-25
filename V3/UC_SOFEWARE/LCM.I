
#line 1 "LCM.c" /0




 
 
  
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



 
 
 
 
 
 
 
 
#line 7 "LCM.c" /0
 
  
#line 1 "LCM.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
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
 
#line 8 "LCM.c" /0
 
  
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
 
 
 
#line 9 "LCM.c" /0
 
 
 
 
 
 
 sbit BL_RED	    = P1^3;	 
 sbit BL_GREEN	= P1^5;	 
 sbit BL_BLUE	= P1^4;	 
 
 
 
 sbit LCM_DataLE	= P2^0; 
 sbit LCM_CS		= P2^6; 
 sbit LCM_A0		= P3^4;
 sbit LCM_WR		= P2^7;
 
 const unsigned char code tab_8_to_15[23] = {
 0xAF, 0xA0,0x6D,0xE9,0xE2,0xCB,0xCF,0xA1,0xEF,0xEB,0xE7,0xEF,0x0F,0xAF,0x4F,0x47,0xE6,0x67,0x00, 0xA7, 0x0E, 0x40, 0xAE  };
 
 
 const unsigned char code tab_1_to_5[11] = {
 0xAF, 0xA0,0xCB,0xE9,0xE4,0x6D,0x6F,0xA8,0xEF,0xED,0x00};
 
 
 const unsigned char code tab_16[4] = {
 0x00, 0x85, 0xBE, 0x9F};
 
 
 const unsigned char code tab_17[5] = {
 0x00, 0x05, 0xB6, 0x97, 0x47};
 
 
 const unsigned char code tab_6_to_7[10] = {0x5F,0x50, 0x6B, 0x79, 0x74, 0x3D, 0x3F, 0x58, 0x7F, 0x7D};
 
 
 
 
 unsigned int KX=0x03F8;   
 
 unsigned int R=0;	 
 
 unsigned char S41=0;
 unsigned char  first_power=1;
 
 void LCM_CMD_Write(unsigned char Value)
 {
 LCM_DataLE=1;
  P0=Value;
 _nop_();
 _nop_();
 _nop_();
 _nop_();
 LCM_DataLE=0;
 
 LCM_A0=1;
 _nop_();
 LCM_CS=0;
 _nop_();
 LCM_WR=0;
 _nop_();
 _nop_();
 _nop_();
 LCM_WR=1;
 _nop_();
 _nop_();
 LCM_CS=1;
 _nop_();
 _nop_();
 }
 
 void LCM_DATA_Write(unsigned char Value)
 {
 LCM_DataLE=1;
  P0=Value;
 _nop_();
 _nop_();
 _nop_();
 _nop_();
 LCM_DataLE=0;
 
 LCM_A0=0;
 _nop_();
 LCM_CS=0;
 _nop_();
 LCM_WR=0;
 _nop_();
 _nop_();
 _nop_();
 LCM_WR=1;
 _nop_();
 _nop_();
 LCM_CS=1;
 _nop_();
 _nop_();
 }
 
 
 void LCM_ColumnAddress(unsigned char address)
 {
 
 LCM_CMD_Write(0x10+(address>>4)); 	 
 _nop_();
 _nop_();
 LCM_CMD_Write(address&0x0f);     	 
 _nop_();
 _nop_();
 }






 
 void LCM_Fill(void)
 {
 unsigned char c;
 
 LCM_CMD_Write(0xB0);	 
 
 LCM_ColumnAddress(0x00);
 for (c=0; c<=41; c++)
 LCM_DATA_Write(0xff);
 }
 
 void LCM_Cls(void)
 {
 unsigned char c;
 
 LCM_CMD_Write(0xB0);	 
 
 LCM_ColumnAddress(0x00);
 for (c=0; c<=41; c++)
 LCM_DATA_Write(0x00);
 }
 
 void LCM_Init(void)
 {
 LCM_CS=1;
 LCM_WR=1;	
 _nop_();
 LCM_CMD_Write(0x2F);	 
 
 LCM_CMD_Write(0xB0);	 
 
 LCM_ColumnAddress(0x00);
 LCM_CMD_Write(0xF1);	 
 
 LCM_CMD_Write(0xAC);	 
 
 LCM_CMD_Write(0xF0);	 
 
 LCM_CMD_Write(0xA4);	 
 
 LCM_CMD_Write(0xAF);	 
 
 LCM_CMD_Write(0xA6);	 
 
 LCM_CMD_Write(0xA1);	 
 
 LCM_CMD_Write(0xC0);	 
 
 LCM_Cls();
 }
 
 void RGB(unsigned char r, unsigned char g, unsigned char b) 
 { 
 CCAP1L=CCAP1H=~r;   CCAP2L=CCAP2H=~b;   CCAP3L=CCAP3H=~g;
 
 CMOD=0x00; 
 CL=0x00;
 CH=0x00;
 
 CCAPM1=0x42; 	 
 CCAPM2=0x42; 	 
 CCAPM3=0x42; 	 
 
 CR=1;
 CCON= 0x1f;
 CR=1;
 
 }
 
 void LCM_Disp_Error(unsigned char c, unsigned int t)
 {
 unsigned char c1, tmp;
 
 LCM_ColumnAddress(19);
 LCM_DATA_Write(0x01);
 tmp = tab_6_to_7[c/10];
 LCM_DATA_Write(tmp);
 LCM_DATA_Write(tmp>>4);
 tmp = tab_6_to_7[c%10];
 LCM_DATA_Write(tmp);
 LCM_DATA_Write(tmp>>4);
 
 c1 = (unsigned char) (t/100);
 LCM_ColumnAddress(35);
 tmp = tab_8_to_15[c1];
 LCM_DATA_Write(tmp);
 LCM_DATA_Write(tmp>>4);
 tmp = tab_8_to_15[(unsigned char) ((t/10)%10)];
 tmp |= 0x10;
 LCM_DATA_Write(tmp);
 LCM_DATA_Write(tmp>>4);
 tmp = tab_8_to_15[(unsigned char) (t%10)];
 LCM_DATA_Write(tmp);
 LCM_DATA_Write(tmp>>4);
 LCM_ColumnAddress(41);
 LCM_DATA_Write(0x02);
 }
 
 void LCM_Backlight(unsigned char BacklightValue)
 {
 switch(BacklightValue)
 {
 case 0:			 
 RGB(0,0,0);
 CR = 0;
 break;
 
 case 1:			 
 RGB(95,0,220);
 break;
 
 case 2:		      
 RGB(30,0,255);       
 break;
 
 case 3:				 
 RGB(15,0,255);       
 break;
 
 case 4:			 
 RGB(0,0,255);        
 break;
 
 case 5:				 
 RGB(0,255,0);
 break;
 
 case 6:			 
 RGB(255,255,0);     
 break;
 
 case 7:			 
 RGB(255,180,0);      
 break;
 
 case 8:				 
 RGB(255,0,0);
 break;
 }
 }
 
 void LCM_Disp_VOL_K2K3(void)
 {
 unsigned char tmp;
 
 LCM_ColumnAddress(5);
 tmp = 0;
 if (KX & 0x0004)	tmp |= 0x01;
 if (KX & 0x0200)	tmp |= 0x02;
 LCM_DATA_Write(tmp);		 
 tmp = (KX & 0x0400)?	0x02 : 0;
 LCM_DATA_Write(tmp);		 
 tmp = (KX & 0x0800)?	0x02 : 0;
 if (R & 0x0100)
 tmp |= 0x04;
 LCM_DATA_Write(tmp);		 
 tmp = (KX & 0x1000)?	0x02 : 0;
 if (KX & 0x0002)	tmp |= 0x08;
 LCM_DATA_Write(tmp);		 
 }
 
 void LCM_Disp_S41(void)
 {
 unsigned char tmp;
 
 LCM_ColumnAddress(41);	 
 tmp = S41;
 if (KX & 0x8000)
 S41 |= 0x08;
 else
 S41 &= ~0x08;
 if (R & 0x0008)
 S41 |= 0x01;
 else
 S41 &= ~0x01;
 
 LCM_DATA_Write(S41);
 }
 
 
 void LCM_Disp_WaterFlow(unsigned int i) 
 {
 unsigned char tmp, c1;
 
  R |= 0x0040;
 c1 = (unsigned char) (i/100);
 LCM_ColumnAddress(35);
 tmp = (c1)?	tab_8_to_15[c1] : 0;
 LCM_DATA_Write(tmp);
 LCM_DATA_Write(tmp>>4);
 tmp = tab_8_to_15[(unsigned char) ((i/10)%10)];
 if (R & 0x0040)
 tmp |= 0x10;
 LCM_DATA_Write(tmp);
 LCM_DATA_Write(tmp>>4);
 tmp = tab_8_to_15[(unsigned char) (i%10)];
 LCM_DATA_Write(tmp);
 LCM_DATA_Write(tmp>>4);
  R &= ~0x0040;
 
  KX |= 0x8000;
 LCM_Disp_S41();				
 }
 
 void LCM_Disp_I_add(unsigned char c, unsigned char mode)
 {	
 unsigned char c1, c2, c3;;
 
 LCM_ColumnAddress(35);		
 if (mode == 0)				 
 {
 LCM_DATA_Write(0);
 LCM_DATA_Write(0);
 LCM_DATA_Write(0);
 LCM_DATA_Write(0);
 LCM_DATA_Write(0);	
 LCM_DATA_Write(0);
 }
 else
 {
 if (c > 20)
 {
 if (c < 30)
 {
 c1 = 0;
 c2 = 0x40;
 c3 = tab_8_to_15[c%10];
 }
 else
 {
 c1 = 0x40;
 c = c-20;
 c2 = tab_8_to_15[c/10];
 c3 = tab_8_to_15[c%10];
 }
 }
 else
 {
 if (c > 10)
 {
 c1 = c2 = 0;
 c3 = tab_8_to_15[20-c];
 }
 else
 {
 c1 = 0;
 c = 20-c;
 c2 = tab_8_to_15[c/10];
 c3 = tab_8_to_15[c%10];
 }
 }
 
 LCM_DATA_Write(c1);
 LCM_DATA_Write(c1>>4);
 LCM_DATA_Write(c2);
 LCM_DATA_Write(c2>>4);
 LCM_DATA_Write(c3);
 LCM_DATA_Write(c3>>4);
 }
 }
 
 void LCM_Disp_WashLiter(unsigned char c, unsigned char mode)
 {	
 unsigned char tmp;
 
 LCM_ColumnAddress(35);		
 if (mode == 0)				 
 {
 LCM_DATA_Write(0);
 LCM_DATA_Write(0);
 LCM_DATA_Write(0);
 LCM_DATA_Write(0);
 LCM_DATA_Write(14);		 
 LCM_DATA_Write(0);
 }
 else
 {
 tmp = tab_8_to_15[(unsigned char) (c/10)];
 LCM_DATA_Write(tmp);
 LCM_DATA_Write(tmp>>4);
 tmp = tab_8_to_15[(unsigned char) (c%10)];
 LCM_DATA_Write(tmp);
 LCM_DATA_Write(tmp>>4);
 LCM_DATA_Write(14);		 
 LCM_DATA_Write(0);			
 }
 }
 
 void LCM_Disp_Acid(unsigned char c)
 {
 unsigned char tmp;
 
 LCM_ColumnAddress(0);
 tmp = tab_16[c];
 LCM_DATA_Write(tmp);
 LCM_DATA_Write(tmp>>4);
 }
 
 void LCM_Disp_ORP(unsigned int ORP_Value, unsigned char ORP_Sign)
 {
 unsigned char tmp;
 
 LCM_ColumnAddress(4);
 tmp = 0;
 if (R & 0x0020)						 
 tmp |= 0x01;
 if (KX & 0x2000)						 
 tmp |= 0x04;
 LCM_DATA_Write(tmp);
 
 LCM_ColumnAddress(7);			 
 tmp = (KX & 0x0800)? 0x02 : 0;
 if (R & 0x0100) tmp |= 0x04;
 LCM_DATA_Write(tmp);
 
 LCM_ColumnAddress(9);			 
 if (ORP_Sign)
 tmp = tab_8_to_15[21];
 else
 tmp = 0;
 if (R & 0x0001)
 tmp |= 0x10;
 LCM_DATA_Write(tmp);
 LCM_DATA_Write(tmp>>4);
 
 tmp = tab_8_to_15[ORP_Value/100];	 
 if (R & 0x0004)
 tmp |= 0x10;
 LCM_DATA_Write(tmp);
 LCM_DATA_Write(tmp>>4);
 
 tmp = tab_8_to_15[(ORP_Value/10)%10];	 
 if (R & 0x0010)
 tmp |= 0x10;
 LCM_DATA_Write(tmp);
 LCM_DATA_Write(tmp>>4);
 
 tmp = tab_8_to_15[ORP_Value%10];	 
 if (R & 0x0080)
 tmp |= 0x10;
 LCM_DATA_Write(tmp);
 LCM_DATA_Write(tmp>>4);
 
 tmp = 0;						 
 if (R & 0x0002)
 tmp |= 0x10;
 LCM_DATA_Write(tmp);
 LCM_DATA_Write(tmp>>4);
 
 if (R & 0x0200)	tmp = 0x04;
 LCM_DATA_Write(tmp);		 
 
 LCM_Disp_S41();
 }
 
 
 void LCM_Disp_PH_and_R(unsigned char *c)
 {
 unsigned char tmp;
 
 LCM_ColumnAddress(4);
 tmp = 0;
 if (R & 0x0020)				 
 tmp |= 0x01;
 if (KX & 0x2000)				 
 tmp |= 0x04;
 LCM_DATA_Write(tmp);
 
 LCM_ColumnAddress(7);			 
 tmp = (KX & 0x0800)? 0x02 : 0;
 if (R & 0x0100) tmp |= 0x04;
 LCM_DATA_Write(tmp);
 
 LCM_ColumnAddress(9);	 
 tmp = tab_8_to_15[*c++];
 if (R & 0x0001)
 tmp |= 0x10;
 LCM_DATA_Write(tmp);
 LCM_DATA_Write(tmp>>4);
 
 tmp = tab_8_to_15[*c++];	 
 if (R & 0x0004)
 tmp |= 0x10;
 LCM_DATA_Write(tmp);
 LCM_DATA_Write(tmp>>4);
 
 tmp = tab_8_to_15[*c++];	 
 if (R & 0x0010)
 tmp |= 0x10;
 LCM_DATA_Write(tmp);
 LCM_DATA_Write(tmp>>4);
 
 tmp = tab_8_to_15[*c++];	 
 if (R & 0x0080)
 tmp |= 0x10;
 LCM_DATA_Write(tmp);
 LCM_DATA_Write(tmp>>4);
 
 tmp = tab_8_to_15[*c++];	 
 if (R & 0x0002)
 tmp |= 0x10;
 LCM_DATA_Write(tmp);
 LCM_DATA_Write(tmp>>4);
 
 tmp = (R & 0x0200)? 0x04 : 0;
 LCM_DATA_Write(tmp);		 
 
 LCM_Disp_S41();
 }





 
 void LCM_Disp_KL(unsigned int VL, unsigned char mode)
 {
 unsigned char c;
 unsigned int  i;
 if(first_power ==1)
 {
 LCM_ColumnAddress(23);
 c = (mode & 0x01)?	0 : 0x0f;		 
 LCM_DATA_Write(c);
 first_power=0;
 }
 else
 {
 LCM_ColumnAddress(23);
 c = (mode & 0x01)?	0 : 0x08;		 
 LCM_DATA_Write(c);
 }
 
 c = (unsigned char)(VL/10000);
 i = VL%10000;
 c = ((c==0)||(mode & 0x02))? 0 : tab_1_to_5[c];
 if (KX & 0x0010)
 c |= 0x10;
 LCM_DATA_Write(c);				 
 LCM_DATA_Write(c>>4);			 
 
 c = (unsigned char)(i/1000);
 i = VL%1000;
 c = (mode & 0x02)?	0 : tab_1_to_5[c];
 if (KX & 0x0020)
 c |= 0x10;
 LCM_DATA_Write(c);				 
 LCM_DATA_Write(c>>4);			 
 
 c = (unsigned char)(i/100);
 i = i%100;
 c = (mode & 0x02)?	0 : tab_1_to_5[c];
 if (KX & 0x0040)
 c |= 0x10;
 LCM_DATA_Write(c);				 
 LCM_DATA_Write(c>>4);			 
 
 c = (unsigned char)(i/10);
 i = i%10;
 c = (mode & 0x02)?	0 : tab_1_to_5[c];
 if (KX & 0x0080)
 c |= 0x10;
 LCM_DATA_Write(c);				 
 LCM_DATA_Write(c>>4);			 
 
 c = (unsigned char)(i);
 c = (mode & 0x02)?	0 : tab_1_to_5[c];
 if (KX & 0x0100)
 c |= 0x10;
 LCM_DATA_Write(c);				 
 LCM_DATA_Write(c>>4);			 
 LCM_DATA_Write(0x01);			 
 }
 
 void LCM_Disp_Alka(unsigned char c)
 {
 unsigned char tmp;
 
 LCM_ColumnAddress(2);
 tmp = tab_17[c];
 if (KX & 0x4000)			 
 tmp |= 0x08;
 LCM_DATA_Write(tmp);
 LCM_DATA_Write(tmp>>4);
 tmp = 0;
 if (R & 0x0020)				 
 tmp |= 0x01;
 if (KX & 0x2000)				 
 tmp |= 0x04;
 LCM_DATA_Write(tmp);
 }
 
