
#line 1 "TYPE_SLOPE.c" /0


















 
  
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
#line 20 "TYPE_SLOPE.c" /0
 
  
#line 1 "TYPE_SLOPE.h" /0



 
 
 
 
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
 
#line 21 "TYPE_SLOPE.c" /0
 
 
 
 
 
 
 
 
 
 
 
 
 unsigned char AV_COD = 0;
 unsigned char NP_COD = 0;
 
 unsigned char ng_flog = 0;
 xdata unsigned char K_Slope[11] = {0,36,48,56,64,76,88,104,120,200,250};
 xdata unsigned char J_Slope[9] = {0,32,40,48,52,112,160,200,255}; 
 xdata unsigned char T_Slope[10] = {7,8,10,16,24,32,48,56,64,72};  
 xdata unsigned char E_Slope[12] = {0,16,32,40,48,56,64,96,108,128,180,225};  
 xdata unsigned char R_Slope[16] = {0,10,14,19,20,22,27,35,38,42,52,60,64,70,80,106};
 
 xdata unsigned char S_Slope[16] = {10,13,16,18,28,32,40,52,55,57,59,64,66,90,132,250};
 
 
 xdata unsigned char RTD_Slope[8] = {0,44,46,50,54,58,62,77};


 
 unsigned int Get_K_Slope(unsigned int Code_Value) 
 {
 unsigned int out_Value;
 
 NP_COD = 0;
 if ( AV_COD == 1 )
 {
 if(Code_Value <= 736)    
 {
 out_Value = 320 - (Code_Value *10)/23;
 ng_flog = 1 ;
 AV_COD = 0;
 }
 else
 {
 out_Value = (Code_Value*10)/23-320;
 ng_flog = 0 ;
 }
 if((Code_Value > 760)&&(ng_flog == 0))  	 
 {
 out_Value = out_Value + (Code_Value-730)/K_Slope[6] ;  
 }
 if((Code_Value > 2000)&&(ng_flog == 0))		 
 {
 out_Value = out_Value+(Code_Value-1950)/K_Slope[8] ;
 }
 }
 else
 {
 out_Value = 320 + Code_Value/2.32;	 
 
 if(Code_Value > 760)  	 
 {
 out_Value = out_Value-(Code_Value-730)/K_Slope[6] ;  
 }
 if(Code_Value > 2000)		 
 {
 out_Value = out_Value-(Code_Value-1950)/K_Slope[8] ;
 }
 if(Code_Value > 3168)	  
 {
 out_Value =out_Value+(Code_Value-3150)/K_Slope[8];
 }
 if(Code_Value > 3550)    
 {
 out_Value =out_Value-(Code_Value-3500)/K_Slope[8]; 
 }
 if(Code_Value > 4850)    
 {
 out_Value =out_Value+(Code_Value-4800)/K_Slope[7];   
 }
 if(Code_Value > 6980)   
 {
 out_Value =out_Value+(Code_Value-6900)/K_Slope[8];
 }
 if(Code_Value > 9343)   
 {
 out_Value =out_Value-(Code_Value-9220)/K_Slope[9];
 }
 if(Code_Value > 10420)  
 {
 out_Value =out_Value-(Code_Value-10360)/K_Slope[8];
 }
 if(Code_Value > 12540)  
 {
 out_Value =out_Value-(Code_Value-12500)/K_Slope[9];
 }
 if(Code_Value >14250)
 {
 out_Value = out_Value-(Code_Value-14200)/K_Slope[10];																																					
 }
 
 if(Code_Value > 16800)	    
 {
 out_Value =out_Value-(Code_Value-16750)/K_Slope[10];
 }
 if(Code_Value > 18250)	 
 {
 out_Value =out_Value+(Code_Value-18200)/K_Slope[10];
 }
 if(Code_Value > 19450)	  
 {
 out_Value =out_Value-(Code_Value-19400)/K_Slope[9];
 }
 if(Code_Value > 21450)	 
 {
 out_Value =out_Value-(Code_Value-21400)/K_Slope[10]; 
 }
 if(Code_Value > 22920)	   
 {
 out_Value =out_Value+(Code_Value-22840)/K_Slope[9];
 }
 if(Code_Value > 25350)	    
 {
 out_Value =out_Value-(Code_Value-25300)/K_Slope[10];
 }
 if(Code_Value > 26860)	    
 {
 out_Value =out_Value+(Code_Value-26800)/K_Slope[9];
 }
 if(Code_Value > 28760)	    
 {
 out_Value =out_Value+(Code_Value-28500)/K_Slope[10];
 }
 if(Code_Value > 30300)	    
 {
 out_Value =out_Value-(Code_Value-30200)/K_Slope[10];
 }
 if(Code_Value > 31350)	    
 {
 out_Value =out_Value+(Code_Value-31250)/K_Slope[8];
 }
 if(Code_Value > 33950)	    
 {
 out_Value =out_Value+(Code_Value-33900)/K_Slope[10];
 }
 if(Code_Value > 35950)	    
 {
 out_Value =out_Value+(Code_Value-35900)/K_Slope[9];
 }
 if(Code_Value > 37050)	    
 {
 out_Value =out_Value+(Code_Value-37000)/K_Slope[10];
 }
 if(Code_Value > 39150)	    
 {
 out_Value =out_Value+(Code_Value-39100)/K_Slope[10];
 }
 if(Code_Value > 40550)	    
 {
 out_Value =out_Value+(Code_Value-40500)/K_Slope[10];
 } 
 if(Code_Value > 42150)	    
 {
 out_Value =out_Value+(Code_Value-42000)/K_Slope[10];
 }
 if(Code_Value > 43450)	    
 {
 out_Value =out_Value+(Code_Value-43400)/K_Slope[10];
 }
 if(Code_Value > 44950)	    
 {
 out_Value =out_Value+(Code_Value-44800)/K_Slope[9];
 }
 if(Code_Value > 46650)	    
 {
 out_Value =out_Value+(Code_Value-46600)/K_Slope[9];
 }
 if(Code_Value > 48250)	    
 {
 out_Value =out_Value+(Code_Value-48200)/K_Slope[8];
 }
 if(Code_Value > 50650)	    
 {
 out_Value =out_Value+(Code_Value-50600)/K_Slope[7];
 }
 if(Code_Value > 52550)	    
 {
 out_Value =out_Value+(Code_Value-52500)/K_Slope[7];
 }
 if(Code_Value > 53550)	    
 {
 out_Value =out_Value+(Code_Value-53500)/K_Slope[9];
 }
 if(Code_Value > 55050)	    
 {
 out_Value =out_Value+(Code_Value-55000)/K_Slope[7];
 }
 if(Code_Value > 56350)	    
 {
 out_Value =out_Value+(Code_Value-56300)/K_Slope[8];
 }
 if(Code_Value > 61000)	    
 {
 out_Value = 65535;
 }	   	   	   	   	   	   	   	   	   	   	    
 }
 
 return out_Value;					   
 }


 
 unsigned int Get_J_Slope(unsigned int Code_Value)  
 {
 unsigned int out_Value;
 
 NP_COD = 0;
 if ( AV_COD == 1 )
 {
 if(Code_Value <= 949)  
 {
 out_Value =320-(Code_Value/2.96);
 ng_flog = 1 ;
 AV_COD = 0;
 }   		 
 else
 {
 out_Value =(Code_Value/2.96)-320;
 ng_flog = 0 ;
 
 }
 }
 else
 {	
 out_Value = 320 + Code_Value/2.96;
 
 if(Code_Value > 1050) 	 
 {
 out_Value =out_Value-(Code_Value-1000)/J_Slope[5] ;
 }
 if(Code_Value > 2545)
 {
 out_Value =out_Value-(Code_Value-2530)/J_Slope[5] ;
 }
 if(Code_Value > 4358)
 {
 out_Value = out_Value-(Code_Value-4350)/J_Slope[6] ; 
 }
 if(Code_Value > 7750) 
 {
 out_Value =out_Value -(Code_Value-7680)/J_Slope[7] ;
 }
 if(Code_Value > 10650)
 {
 out_Value =out_Value-(Code_Value-10670)/J_Slope[7];
 }
 if(Code_Value > 11250)
 {
 out_Value =out_Value+(Code_Value-11200)/J_Slope[7] ;	
 }
 if(Code_Value > 14920) 
 {
 out_Value =out_Value-(Code_Value-14750)/J_Slope[7] ;	 
 }
 if(Code_Value > 15420) 
 {
 out_Value =out_Value+(Code_Value-15400)/J_Slope[6] ;	 
 }
 if(Code_Value > 17620) 
 {
 out_Value =out_Value-(Code_Value-17600)/J_Slope[8] ;	 
 }
 if(Code_Value > 18620) 
 {
 out_Value =out_Value+(Code_Value-18600)/J_Slope[6] ;	 
 }
 if(Code_Value > 20620) 
 {
 out_Value =out_Value-(Code_Value-20600)/J_Slope[7] ;	 
 }
 if(Code_Value > 22620) 
 {
 out_Value =out_Value+(Code_Value-22600)/J_Slope[6] ;	 
 }
 if(Code_Value > 24120) 
 {
 out_Value =out_Value-(Code_Value-24100)/J_Slope[6] ;	 
 }
 if(Code_Value > 26320) 
 {
 out_Value =out_Value+(Code_Value-26300)/J_Slope[8] ;	 
 }
 if(Code_Value > 27220) 
 {
 out_Value =out_Value-(Code_Value-27100)/J_Slope[7] ;	 
 }
 if(Code_Value > 29620) 
 {
 out_Value =out_Value-(Code_Value-29600)/J_Slope[7] ;	 
 }
 if(Code_Value > 32220) 
 {
 out_Value =out_Value-(Code_Value-32200)/J_Slope[7] ;	 
 }
 if(Code_Value > 34720) 
 {
 out_Value =out_Value-(Code_Value-34700)/J_Slope[6] ;	 
 }
 if(Code_Value > 36020) 
 {
 out_Value =out_Value-(Code_Value-36000)/J_Slope[7] ;	 
 }
 if(Code_Value > 38620) 
 {
 out_Value =out_Value-(Code_Value-38600)/J_Slope[7] ;	 
 }
 if(Code_Value > 39820) 
 {
 out_Value =out_Value-(Code_Value-39800)/J_Slope[6] ;	 
 }
 if(Code_Value > 43820) 
 {
 out_Value =out_Value-(Code_Value-43800)/J_Slope[5] ;	 
 }
 }
 
 return out_Value;
 
 }


 
 unsigned int Get_T_Slope(unsigned int Code_Value) 
 {
 unsigned int outlo_Value;
 unsigned int out_Value;
 
 out_Value = Code_Value;
 NP_COD = 0;
 
 if ( AV_COD == 1 )
 {
 if(Code_Value <= 706)  
 {
 outlo_Value =320-(Code_Value/2.22);
 ng_flog = 1 ;
 AV_COD = 0;
 }   		 
 else
 {
 outlo_Value =(Code_Value/2.2)-320;
 ng_flog = 0;
 AV_COD = 1;
 }
 
 if((outlo_Value > 110)&&(ng_flog == 0)) 
 {
 outlo_Value =outlo_Value+(outlo_Value-100)/T_Slope[3];
 }
 if((outlo_Value > 437)&&(ng_flog == 0))
 {
 outlo_Value =outlo_Value+(outlo_Value-420)/T_Slope[6];
 }
 if((outlo_Value > 600)&&(ng_flog == 0))
 {
 outlo_Value =outlo_Value+(outlo_Value-550)/T_Slope[5];
 }
 if((outlo_Value > 734)&&(ng_flog == 0))
 {
 outlo_Value =outlo_Value+(outlo_Value-710)/T_Slope[4];
 }
 if((outlo_Value > 960)&&(ng_flog == 0)) 
 {
 outlo_Value =outlo_Value+(outlo_Value-950)/T_Slope[5];
 }
 if((outlo_Value > 1150)&&(ng_flog == 0))
 {
 outlo_Value =outlo_Value+(outlo_Value-1100)/T_Slope[4];
 }
 if((outlo_Value > 1350)&&(ng_flog == 0))
 {
 outlo_Value =outlo_Value+(outlo_Value-1300)/T_Slope[4];
 }									 
 if((outlo_Value > 1540)&&(ng_flog == 0))
 {
 outlo_Value =outlo_Value+(outlo_Value-1520)/T_Slope[3];	
 }
 if((outlo_Value> 1780)&&(ng_flog == 0)) 
 {
 outlo_Value =outlo_Value+(outlo_Value-1750)/T_Slope[4];
 }
 if((outlo_Value > 1910)&&(ng_flog == 0)) 
 {
 outlo_Value =outlo_Value+(outlo_Value-1900)/T_Slope[4];
 }
 if((outlo_Value > 2120)&&(ng_flog == 0))
 {
 outlo_Value =outlo_Value+(outlo_Value-2110)/T_Slope[3];
 }
 if((outlo_Value > 2270)&&(ng_flog == 0))
 {
 outlo_Value =outlo_Value+(outlo_Value-2260)/T_Slope[3];
 }
 if((outlo_Value > 2550)&&(ng_flog == 0))
 {
 outlo_Value =outlo_Value+(outlo_Value-2520)/T_Slope[3];
 }
 if((outlo_Value > 2720)&&(ng_flog == 0))
 {
 outlo_Value =outlo_Value+(outlo_Value-2680)/T_Slope[3];
 }
 if((outlo_Value > 2890)&&(ng_flog == 0))
 {
 outlo_Value =outlo_Value+(outlo_Value-2850)/T_Slope[3]; 
 }
 if((outlo_Value > 2970)&&(ng_flog == 0))
 {
 outlo_Value =outlo_Value+(outlo_Value-2940)/T_Slope[3]; 
 }
 if((outlo_Value > 3110)&&(ng_flog == 0))
 {
 outlo_Value =outlo_Value+(outlo_Value-3100)/T_Slope[3];
 }
 if(outlo_Value > 4000) outlo_Value = 4990;
 }	
 else
 {
 outlo_Value = out_Value ;
 
 outlo_Value = 320 + out_Value/2.2;
 
 if(outlo_Value > 340)
 {
 outlo_Value =outlo_Value-(outlo_Value-330)/T_Slope[5] ;
 }
 if(outlo_Value > 570)
 {
 outlo_Value =outlo_Value-(outlo_Value-560)/T_Slope[4] ;
 }
 if(outlo_Value > 940)
 {
 outlo_Value =outlo_Value-(outlo_Value-910)/T_Slope[4] ;
 }
 if(outlo_Value > 1300) 
 {
 outlo_Value =outlo_Value-(outlo_Value-1270)/T_Slope[4] ;
 }
 if(outlo_Value > 1720)
 {
 outlo_Value =outlo_Value-(outlo_Value-1700)/T_Slope[4] ;
 }
 if(outlo_Value > 2170)
 {
 outlo_Value =outlo_Value-(outlo_Value-2150)/28 ;
 }
 if(outlo_Value > 2610)
 {
 outlo_Value =outlo_Value-(outlo_Value-2580)/T_Slope[5] ;	
 }
 if(outlo_Value > 2980)
 {
 outlo_Value =outlo_Value-(outlo_Value-2960)/T_Slope[5] ;	
 }
 if(outlo_Value > 3511) 
 {
 outlo_Value =outlo_Value-(outlo_Value-3410)/T_Slope[5] ;
 }
 if(outlo_Value > 3984) 
 {
 outlo_Value =outlo_Value-(outlo_Value-3870)/T_Slope[6] ;
 }
 if(outlo_Value > 5000) outlo_Value = 5999;
 }
 return outlo_Value;
 }


 
 unsigned int Get_E_Slope(unsigned int Code_Value)
 {
 unsigned int out_Value;
 
 out_Value = Code_Value;
 NP_COD = 0;
 if ( AV_COD == 1 )
 {
 if(out_Value <= 1109)  
 {
 out_Value =320-(Code_Value/3.46);
 ng_flog = 1 ;
 AV_COD = 0;
 }   		 
 else
 {
 out_Value =(Code_Value/3.46)-320;
 ng_flog = 0 ;
 }
 }
 else
 {
 out_Value = 320 + Code_Value/3.46;
 
 if(Code_Value  > 1158)
 { 
 out_Value = out_Value-(Code_Value-1100)/E_Slope[7] ; 
 }    
 if(Code_Value  > 2500)
 {
 out_Value = out_Value-(Code_Value-2450)/E_Slope[8];
 }
 if(Code_Value > 4740)
 {
 out_Value = out_Value-(Code_Value-4700)/E_Slope[7];
 }
 if(Code_Value > 5890)
 {
 out_Value = out_Value-(Code_Value-5860)/E_Slope[9];
 }
 if(Code_Value > 8050)
 {
 out_Value = out_Value-(Code_Value-8020)/E_Slope[9];
 }
 if(Code_Value > 10800)
 {
 out_Value = out_Value-(Code_Value-10750)/E_Slope[9];
 }
 if(Code_Value > 13350)
 {
 out_Value = out_Value-(Code_Value-13300)/E_Slope[10];				   
 }
 if(Code_Value > 15500)
 {
 out_Value = out_Value-(Code_Value-15490)/E_Slope[10];
 }
 if(Code_Value > 16300)
 {
 out_Value = out_Value+(Code_Value-16250)/E_Slope[10];
 }
 if(Code_Value > 17200)
 {
 out_Value =out_Value-(Code_Value-17150)/E_Slope[9] ;
 }
 if(Code_Value > 19280)
 {
 out_Value =out_Value+(Code_Value-19270)/E_Slope[10] ;
 }
 if(Code_Value > 20200)
 {
 out_Value =out_Value-(Code_Value-20150)/E_Slope[9] ;
 }
 if(Code_Value > 23180)
 {
 out_Value =out_Value-(Code_Value-23120)/E_Slope[10] ;
 }
 if(Code_Value > 24580)
 {
 out_Value =out_Value+(Code_Value-24540)/E_Slope[11] ;
 }
 if(Code_Value > 26480)
 {
 out_Value =out_Value-(Code_Value-26440)/E_Slope[10] ;   
 }
 if(Code_Value > 28280)
 {
 out_Value =out_Value+(Code_Value-28240)/E_Slope[11] ;   
 }
 if(Code_Value > 29750)
 {
 out_Value =out_Value-(Code_Value-29700)/E_Slope[10] ;   
 }
 if(Code_Value > 33680)
 {
 out_Value =out_Value+(Code_Value-33640)/E_Slope[10] ;   
 }
 if(Code_Value > 34480)
 {
 out_Value =out_Value-(Code_Value-34440)/E_Slope[9];   
 }
 if(Code_Value > 36480)
 {
 out_Value =out_Value+(Code_Value-36440)/E_Slope[11] ;   
 }
 if(Code_Value > 37700)
 {
 out_Value =out_Value-(Code_Value-37650)/E_Slope[11] ;   
 }
 if(Code_Value > 40600)
 {
 out_Value =out_Value+(Code_Value-40550)/E_Slope[11] ;   
 }
 if(Code_Value > 41200)
 {
 out_Value =out_Value-(Code_Value-41150)/E_Slope[11] ;   
 }
 if(Code_Value > 42500)
 {
 out_Value =out_Value+(Code_Value-42450)/E_Slope[11] ;   
 }
 if(Code_Value > 44500)
 {
 out_Value =out_Value-(Code_Value-44450)/E_Slope[11] ;   
 }
 if(Code_Value > 47700)
 {
 out_Value =out_Value+(Code_Value-47650)/E_Slope[10] ;   
 }
 if(Code_Value > 49270)
 {
 out_Value =out_Value-(Code_Value-49250)/E_Slope[7] ;   
 }
 if(Code_Value > 50000)
 {
 out_Value =out_Value+(Code_Value-49980)/E_Slope[7] ;   
 }
 if(Code_Value > 51860)
 {
 out_Value =out_Value-(Code_Value-51820)/E_Slope[11] ;   
 }
 if(Code_Value > 52560)
 {
 out_Value =out_Value+(Code_Value-52520)/E_Slope[11] ;   
 }
 if(Code_Value > 53560)
 {
 out_Value =out_Value-(Code_Value-53520)/E_Slope[11] ;   
 }
 if(Code_Value > 54960)
 {
 out_Value =out_Value+(Code_Value-54920)/E_Slope[11] ;   
 }
 if(Code_Value > 58160)
 {
 out_Value =out_Value+(Code_Value-58120)/E_Slope[11] ;   
 }
 if(Code_Value > 59020)
 {
 out_Value =out_Value-(Code_Value-59000)/E_Slope[9] ;   
 }
 if(Code_Value > 60060)
 {
 out_Value =out_Value+(Code_Value-60020)/E_Slope[11] ;   
 }
 if(Code_Value > 62260)
 {
 out_Value =out_Value-(Code_Value-62220)/E_Slope[11] ;   
 }
 if(Code_Value > 62460)
 {
 out_Value =out_Value+(Code_Value-62420)/E_Slope[10] ;   
 }
 
 if(Code_Value > 654000)
 {
 out_Value = 65536 ;   
 }
 }
 return out_Value;
 
 }


 
 unsigned int Get_R_Slope(unsigned int Code_Value)
 {
 unsigned int out_Value;
 unsigned int B_code;
 if ( AV_COD == 1 )
 {
 if(out_Value <= 103)  
 {
 out_Value =32-(Code_Value/2.17);
 ng_flog = 1 ;
 AV_COD = 0;
 }   		 
 else
 {
 ng_flog = 0 ;
 out_Value = 0;
 }
 }
 else
 {
 B_code = 32 + Code_Value/3.16;
 out_Value =	 B_code ;
 
 if(B_code >= 69)
 {
 out_Value = out_Value-(B_code-59)/R_Slope[1] ; 
 }  
 if(B_code >= 109)
 {
 out_Value = out_Value-(B_code-109)/R_Slope[2] ;
 }
 if(B_code >= 153)
 {
 out_Value = out_Value-(B_code-153)/R_Slope[3] ;
 }
 if(B_code >= 199)
 {
 out_Value = out_Value-(B_code-199)/R_Slope[4] ;
 }
 if(B_code >= 273)
 {
 out_Value = out_Value-(B_code-272)/R_Slope[5] ;
 }
 if(B_code >= 379)
 {
 out_Value = out_Value-(B_code-378)/R_Slope[3] ;
 }
 if(B_code >= 512)
 {
 out_Value = out_Value-(B_code-511)/R_Slope[6] ;
 }
 if(B_code >= 673)
 {
 out_Value = out_Value-(B_code-672)/R_Slope[7] ;
 }
 if(B_code >= 864)
 {
 out_Value = out_Value-(B_code-863)/R_Slope[8] ;
 }
 if(B_code >= 1098)
 {
 out_Value = out_Value-(B_code-1097)/R_Slope[9] ;
 }
 if(B_code >= 1378)
 {
 out_Value = out_Value-(B_code-1377)/R_Slope[10] ;
 }
 if(B_code >= 1705)
 {
 out_Value = out_Value-(B_code-1704)/R_Slope[11] ;
 }
 if(B_code >= 1968)
 {
 out_Value = out_Value-(B_code-1967)/R_Slope[13] ;
 }
 if(B_code >= 2278)
 {
 out_Value = out_Value-(B_code-2277)/R_Slope[12] ;
 }
 if(B_code >= 2598)
 {
 out_Value = out_Value-(B_code-2597)/R_Slope[13] ;
 }
 if(B_code >= 2971)
 {
 out_Value = out_Value-(B_code-2970)/R_Slope[14] ;
 }
 if(B_code >= 3400)
 {
 out_Value = out_Value-(B_code-3299)/R_Slope[14] ;
 }
 if(B_code >= 3843)
 {
 out_Value = out_Value-(B_code-3842)/R_Slope[14] ;
 }
 if(B_code >= 4438)
 {
 out_Value =out_Value-(B_code-4437)/R_Slope[15] ;
 }
 }
 return out_Value;
 
 }


 
 unsigned int Get_S_Slope(unsigned  int Code_Value)
 {
 unsigned int out_Value;
 unsigned int B_code;
 if ( AV_COD == 1 )
 {
 if(Code_Value <= 104)  
 {
 out_Value =32-(Code_Value/2.17);
 ng_flog = 1 ;
 AV_COD = 0;
 }   		 
 else
 {
 ng_flog = 0 ;
 out_Value = 0 ;
 }
 }
 else
 {
 B_code = 32 + Code_Value/3.2;
 
 out_Value = B_code ;
 
 if(B_code >= 50)
 {
 out_Value =out_Value-(B_code-50)/S_Slope[1] ;
 }
 if(B_code >= 109)
 {
 out_Value =out_Value-(B_code-109)/S_Slope[0] ;
 }
 if(B_code >= 174)
 {
 out_Value =out_Value-(B_code-174)/S_Slope[2] ;
 }
 if(B_code >= 248)  
 {
 out_Value =out_Value-(B_code-248)/S_Slope[3] ;
 }
 if(B_code >= 369)	
 {
 out_Value =out_Value-(B_code-369)/S_Slope[4] ;
 }
 if(B_code >= 456)
 {
 out_Value =out_Value-(B_code-456)/S_Slope[5] ;
 }
 if(B_code >= 591)
 {
 out_Value =out_Value-(B_code-591)/S_Slope[6] ;
 }
 if(B_code >= 796) 
 {
 out_Value =out_Value-(B_code-796)/S_Slope[6] ;
 }
 if(B_code >= 1010) 
 {
 out_Value =out_Value-(B_code-1010)/S_Slope[8] ;
 }
 if(B_code >= 1318)
 {
 out_Value =out_Value-(B_code-1318)/S_Slope[6] ;
 }
 if(B_code >= 1668)
 {
 out_Value =out_Value-(B_code-1668)/S_Slope[10] ;
 }
 if(B_code >= 2157) 
 {
 out_Value =out_Value-(B_code-2157)/S_Slope[8] ;
 }
 if(B_code >= 2413) 
 {
 out_Value =out_Value-(B_code-2413)/S_Slope[10] ;
 }
 if(B_code >= 2881) 
 {
 out_Value =out_Value-(B_code-2881)/S_Slope[9] ;
 }							
 if(B_code >= 3273)
 {
 out_Value =out_Value-(B_code-3273)/S_Slope[13] ;	
 }
 if(B_code >= 3717)
 {
 out_Value =out_Value-(B_code-3717)/S_Slope[14] ;
 }
 if(B_code >= 4380)
 {
 out_Value =out_Value-(B_code-4380)/S_Slope[14] ;
 }
 if(B_code >= 5078)
 {
 out_Value =out_Value+(B_code-5078)/S_Slope[14] ;
 }
 if(B_code >= 5298)
 {
 out_Value =out_Value+(B_code-5298)/S_Slope[14] ;
 }
 }
 return out_Value;
 
 }



















































































































 
 unsigned int Get_RTD_Slope(unsigned  int Code_Value) 
 {
 unsigned int RTD_Value;
 unsigned int out_Value;
 
 NP_COD = 0;
 
 if ( AV_COD == 1 )
 {
 if(Code_Value <= 394)  	 
 {
 RTD_Value =320-(Code_Value/1.38);
 ng_flog = 1 ;
 AV_COD = 0;
 }   		 
 else
 {
 RTD_Value =(Code_Value/1.38)-320;
 ng_flog = 0;
 AV_COD = 1;
 }
 
 out_Value = RTD_Value ;
 
 if((RTD_Value > 40)&&(ng_flog == 0)) 
 {
 out_Value =out_Value-(RTD_Value+40)/RTD_Slope[3];
 }
 if((RTD_Value > 950)&&(ng_flog == 0))
 {
 out_Value =out_Value-(RTD_Value-950)/RTD_Slope[2];
 }
 if((RTD_Value > 1950)&&(ng_flog == 0))
 {
 out_Value =out_Value-(RTD_Value-1950)/RTD_Slope[2];
 }
 if((RTD_Value > 2600)&&(ng_flog == 0))
 {
 out_Value =out_Value-(RTD_Value-2600)/RTD_Slope[2];
 }
 if((RTD_Value > 3200)&&(ng_flog == 0)) 
 {
 out_Value =out_Value-(RTD_Value-3200)/RTD_Slope[2];
 }
 }
 else
 {
 RTD_Value = 320 + Code_Value/1.38;
 
 out_Value = RTD_Value;	
 
 if(RTD_Value >= 1300) 
 {
 out_Value =out_Value+(RTD_Value-1280)/RTD_Slope[4];
 }
 if(RTD_Value >= 2200)
 {
 out_Value =out_Value+(RTD_Value-2200)/RTD_Slope[6];
 }    
 if(RTD_Value >= 3250)
 {
 out_Value =out_Value+(RTD_Value-3250)/RTD_Slope[4];
 } 											  
 if(RTD_Value >= 4100)
 {
 out_Value =out_Value+(RTD_Value-4100)/RTD_Slope[4];
 } 
 if(RTD_Value >= 5000) 
 {
 out_Value =out_Value+(RTD_Value-5000)/RTD_Slope[6];
 } 
 if(RTD_Value >=5800) 
 {
 out_Value =out_Value+(RTD_Value-5800)/RTD_Slope[6]; 
 } 
 if(RTD_Value >= 6400) 
 {
 out_Value =out_Value+(RTD_Value-6400)/RTD_Slope[5];
 }
 if(RTD_Value >= 7330) 
 {
 out_Value =out_Value + (RTD_Value-7330)/RTD_Slope[4];
 }
 if(RTD_Value >= 7950) 
 {
 out_Value =out_Value+(RTD_Value-7950)/RTD_Slope[4];
 } 
 if(RTD_Value >= 8700) 
 {
 out_Value =out_Value+(RTD_Value-8700)/RTD_Slope[4];
 } 
 if(RTD_Value >= 9450) 
 {
 out_Value =out_Value+(RTD_Value-9450)/RTD_Slope[5];	
 } 
 if(RTD_Value >= 9900) 
 {
 out_Value =out_Value+(RTD_Value-9900)/RTD_Slope[7];
 } 
 if(RTD_Value >= 10500) 
 {
 out_Value =out_Value+(RTD_Value-10500)/RTD_Slope[6];
 } 
 if(RTD_Value >= 10740) 
 {
 out_Value =out_Value+(RTD_Value-10740)/RTD_Slope[7];	
 }
 if(RTD_Value >= 11400) 
 {
 out_Value =out_Value+(RTD_Value-11400)/RTD_Slope[5];	
 } 	    
 if(RTD_Value >= 11800)
 {
 out_Value =out_Value+(RTD_Value-11800)/RTD_Slope[7];
 } 
 if(RTD_Value >= 12250) 
 {
 out_Value =out_Value+(RTD_Value-12250)/RTD_Slope[7];
 } 
 if(RTD_Value >= 12750) 
 {
 out_Value =out_Value+(RTD_Value-12750)/RTD_Slope[2];
 } 
 if(RTD_Value >= 13400) 
 {
 out_Value =out_Value+(RTD_Value-13400)/RTD_Slope[2];
 } 
 }
 return out_Value ;
 }
