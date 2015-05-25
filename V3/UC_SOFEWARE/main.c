/***********************************************
  PRODUCT FOR NEWCAL MIX_TEMP FUNCTION
   CPU : MPC82G516
   BEGIN DATE: 2013.11.01
   FINISHED  : 2014.01.25
   WRITEBY   :JOHNSON LIN
   AD111  setup   SET 1001 0000 FOR A0 TYPE 
    8CH =  pga =1 ,32767BITS
**************************************************/
#include <MPC82G516.h>
#include <intrins.h>
#include <LED.h>
#include <AD3421.h>
#include <DAC6571_mV.h>
#include <DAC6571_mA.h>
#include <RTC3130.h>
#include <EEPROM.H>
#include <STDLIB.H>
#include <TYPE_SLOPE.H>

#define   BASE_TEMP		32		 //F & C Transfor Data
#define   MAX_TEMP		3240     //F 1800C
#define   MAX_VOLT		4400	 //mV
#define   EEP_START		60
#define   EEP_END			20000
#define   JOHNSON             0x5a
#define   LIN                 0xa5

#define   K_TYPE		0		//2466F   54.807mV	P0=0x00
#define   J_TYPE		1		//1368F   42.922mV
#define   T_TYPE   	    2		//360F    9.286mV
#define   E_TYPE		3		//1440F   61.022mV
#define   R_TYPE		4		//2880F   18.842mV
#define   S_TYPE		5		//2880F   16.771mV
#define   B_TYPE		6		//3240F   13.585mV
#define   N_TYPE	    7		//?       ?

#define	TC_FUNCTION		0
#define	RTD_FUNCTION	1
#define	mV_FUNCTION		2
#define	mA_FUNCTION		3
#define	RESET_FUNCTION	4
#define	SETUP_FUNCTION	5

#define   ON    1
#define   OFF   0


#define	DISPLAY_SEND_TIME  0	   //timer out work select
#define	DATA_SAVE_TIME     1
#define	DATA_SEND_TIME     2
#define	SETUP_TIMEOUT      3
#define	TIMEUP_TIME        4

#define ITEM              0
#define MODE_CAL          1
#define C_F_CAL           2
#define TYPE_CAL          3
#define TC_ZERO_CAL       4
#define TC_SPAN_CAL       5
#define RTD_ZERO_CAL      6
#define RTD_SPAN_CAL      7
#define mV_ZERO_CAL       8
#define mV_SPAN_CAL       9
#define mA_ZERO_CAL       10
#define mA_SPAN_CAL       11
#define ALARM_LO_CAL      12
#define ALARM_HI_CAL      13
#define YEAR_DATE_CAL     14
#define MON_DATE_CAL      15
#define DAY_DATE_CAL      16
#define HOUR_DATE_CAL     17
#define MIN_DATE_CAL      18
#define PRODUCT_RESET     19
#define NOMAL_FUNCTION    0

	           
#define  Mode_Select 18    //EEP Address
#define  C_F_Select  19
#define  Type_Select 20
#define  TC_Zero     21	  
#define  TC_Span     23
#define  RTD_Zero    25
#define  RTD_Span    27
#define  mV_Zero     29									  
#define  mV_Span     31
#define  mA_Zero     33
#define  mA_Span     35
#define  Alarm_Low   37
#define  Alarm_Hi    39
#define  Year_Date   41
#define  Mon_Date    42
#define  Day_Date    43
#define  Week_Date   44
#define  Hour_Date   45
#define  Min_Date    46
#define  EEP_ADR     50

sbit TC_C    = P0^0;	//k=0x00;j=0x01;t=0x02;e=0x03; 
sbit RTD_C   = P0^1;	//r=0x04;s=0x05;b=0x06;n=0x07;
sbit mV_C    = P0^2;
sbit mA_C    = P0^3;	 //tc= 000 00xxx;  rtd=000 01xxx;    mV=000 10xxx
sbit mV_OUT  = P0^4;	 //mA= 000 11xxx;
sbit mA_OUT  = P0^5;
sbit UP_KEY   = P0^6;
sbit DOWN_KEY = P0^7;

sbit LED1_SCL = P1^0;
sbit LED1_LE  = P1^1;
sbit LED2_SCL = P1^2;
sbit LED2_LE  = P1^3;
sbit NONE_8   = P1^4;
sbit NONE_1   = P1^5;
sbit NONE_2   = P1^6;
sbit NONE_3   = P1^7;

sbit AD_SDA   = P2^0;
sbit AD_SCL   = P2^1;
sbit ALL_SDA  = P2^2;
sbit EEP_SCL  = P2^3;
sbit OUT_SCL  = P2^4;
sbit RTC_SCL  = P2^5;
sbit NONE_4   = P2^6;
sbit NONE_5   = P2^7;

sbit R485_RX           = P3^0;
sbit R485_TX           = P3^1;
sbit FUNCTION_KEY      = P3^2;
sbit OFFSET_KEY        = P3^3;
sbit BEEP_OUT          = P3^4;	 //for relay
sbit R485_DE_RE        = P3^5;
sbit NONE_6            = P3^6;
sbit NONE_7            = P3^7;
//===============================
extern unsigned int KX;	
extern unsigned int R;	
extern unsigned int	TC_type_zero[8];	 
extern unsigned int	TC_type_span[8];
extern unsigned char key_delay[16];

idata unsigned char Soft_Timer[8] = {0,0,0,0,0,0,0,0};
idata unsigned char T0_cnt, T1_cnt;

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
unsigned char  use_year;
unsigned char  use_mon;
unsigned char  use_day;
unsigned char  use_week;
unsigned char  use_hour;
unsigned char  use_min;
unsigned char  eep_count;
unsigned int   Disp_year;
unsigned int  TempValue;

unsigned int  LeftLiter;
unsigned int left_FlowCnt, UseSec, UseHour;

unsigned char tmp1;
unsigned char C_F_Type;
unsigned char ADH;
unsigned char ADL;
unsigned char Soft_Timer_Enable = 0;
unsigned char Key_backup, ReceiveDate;
unsigned char WashLiter, r_step, r_step_max, r_step_cnt;

bit f_half_sec, f_key_hold, f_water_out, f_alarm_no_water,f_Power_on,f_reflash;
bit ReceiveFlag=0,f_acid3=0, f_clean=0, f_lock, f_show_orp=0;


const unsigned char code TC_tab_offset[10] = {10, 15, 20, 30, 40, 60, 80};
const unsigned char code TC_tab_slope[10] = {4, 3, 2, 1, 17, 6, 7, 5};
const unsigned char code TC_tab_type[8] = {0x02, 0x0B, 0x2D, 0x36, 0x00};

const unsigned char code RTD_tab_offset[10] = {10, 15, 20, 30, 40, 60, 80};
const unsigned char code RTD_tab_slop[10] = {4, 3, 2, 1, 17, 6, 7, 5};

const int code tab_k[22] = {
     4, 800, 1150, 1500, 1800, 2150, 2500, 2800,
	1500, 1850, 2200, 2500, 2850, 3200, 3500,
	2000, 2350, 2700, 3000, 3350, 3700, 4000
};
const int code tab_j[22] = {
     0, 800, 1150, 1500, 1800, 2150, 2500, 2800,
	1500, 1850, 2200, 2500, 2850, 3200, 3500,
	2000, 2350, 2700, 3000, 3350, 3700, 4000
};
const int code tab_t[22] = {
     0, 800, 1150, 1500, 1800, 2150, 2500, 2800,
	1500, 1850, 2200, 2500, 2850, 3200, 3500,
	2000, 2350, 2700, 3000, 3350, 3700, 4000
};
const int code tab_e[22] = {
     0, 800, 1150, 1500, 1800, 2150, 2500, 2800,
	1500, 1850, 2200, 2500, 2850, 3200, 3500,
	2000, 2350, 2700, 3000, 3350, 3700, 4000
};
const int code tab_r[22] = {
     0, 800, 1150, 1500, 1800, 2150, 2500, 2800,
	1500, 1850, 2200, 2500, 2850, 3200, 3500,
	2000, 2350, 2700, 3000, 3350, 3700, 4000
};
const int code tab_s[22] = {
     0, 800, 1150, 1500, 1800, 2150, 2500, 2800,
	1500, 1850, 2200, 2500, 2850, 3200, 3500,
	2000, 2350, 2700, 3000, 3350, 3700, 4000
};
const int code tab_b[22] = {
     0, 800, 1150, 1500, 1800, 2150, 2500, 2800,
	1500, 1850, 2200, 2500, 2850, 3200, 3500,
	2000, 2350, 2700, 3000, 3350, 3700, 4000
};
const int code tab_n[22] = {
     0, 800, 1150, 1500, 1800, 2150, 2500, 2800,
	1500, 1850, 2200, 2500, 2850, 3200, 3500,
	2000, 2350, 2700, 3000, 3350, 3700, 4000
};
const int code tab_rtd[22] = {
     0, 800, 1150, 1500, 1800, 2150, 2500, 2800,
	1500, 1850, 2200, 2500, 2850, 3200, 3500,
	2000, 2350, 2700, 3000, 3350, 3700, 4000
};
/***************************************
	   Port In/Out Setting
*****************************************/
void PORT_Init(void)
{
	P0M0 = 0xFF;	  //00=Qb,01=pull output, 10= input only,11=open drain
 	P0M1 = 0x00;	 //P0= ALL INPUT

	P1M0 = 0x00;	 //P1= ALL OUTPUT
	P1M1 = 0xFF;     //SETUP P1 ALL LO //  define P1.3 P1.4 P1.5 as push-pull
	P2M0 = 0x00;	 //P2= ALL OUTOUT
	P2M1 = 0xFF; 	 //SETUP P2 ALL LO
    P3M0 = 0xFF;	 //
	P3M1 = 0xff;
	P0 = 0xff;
	P1 = 0x00;
	P2 = 0x00; 
	P3 = 0x00;
}
/*******************************************
     interrupt   0
*******************************************/
void ex_int0(void) interrupt 0
{
;	
}
/*******************************************
     interrupt   1
*******************************************/
void time0(void) interrupt  1     //   T=1/16 sec 
{
 unsigned int Value_code;
	TR0 = 0;
	T1_cnt++;
	if ((T1_cnt%8)==0)
	SBUF = Value_code;
	TH0 = 0x0B;
	TL0 = 0xDC;
	TR0 = 1;
}

/*******************************************
     interrupt   3
*******************************************/
void time1(void) interrupt   3   //    T=1/16 sec 
{
	TR1 = 0;
	T0_cnt++;

	if (Soft_Timer[DISPLAY_SEND_TIME] != 0)		Soft_Timer[DISPLAY_SEND_TIME]--;

	if ((T0_cnt%8)==0)		  f_half_sec = 1;
			
	if (T0_cnt == 16)
	{
		T0_cnt = 0;
		if (Soft_Timer[DATA_SAVE_TIME] != 0)    Soft_Timer[DATA_SAVE_TIME]--;	
		if (Soft_Timer[DATA_SEND_TIME] != 0)	Soft_Timer[DATA_SEND_TIME]--;
		if (Soft_Timer[SETUP_TIMEOUT] != 0)       Soft_Timer[SETUP_TIMEOUT]--;	
		if (Soft_Timer[TIMEUP_TIME] != 0)		Soft_Timer[TIMEUP_TIME]--;
	}	    	
	TH1 = 0x0B;
	TL1 = 0xDC;
	TR1 = 1;
 		
}
//	DISPLAY_SEND_TIME  0	   //timer out work select
//	DATA_SAVE_TIME     1
//	DATA_SEND_TIME     2
//	SETUP_TIMEOUT      3
//	OTHER_SEND_TIME    4
/*******************************************
    
*******************************************/
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
/*******************************************
    
*******************************************/
void T1_Init(void)
{
	TR1 = 0;
	TMOD = 0x11;
	TH1 = 0x0B;
	TL1 = 0xDC;
	T1_cnt = 0;
//	AD111_Init();
	ET1 = 1;
	TR1 = 1;
}
/*******************************************
    
*******************************************/
void INT0_Init(void)
{
    INT0 = 1;	 
	IE0  = 0;		   
	IT0  = 1;
	EX0  = 1;	  
}
/*******************************************/
void InitUart()	   //InitUart use timer2
{
   SCON |= 0x50;			  /* uart in mode 1 (8 bit), REN=1 */
   T2CON &= 0xF0;               /* EXEN2=0; TR2=0; C/T2#=0; CP/RL2#=0; */
   T2CON |= 0x30;               /* RCLK = 1; TCLK=1; */
   TH2=0xFF;                    /* init value */
   TL2=0xD0;                    /* init value */
   RCAP2H=0xFF;                 /* reload value, 9600 Bds at 11.059MHz */
   RCAP2L=0xDC;                 /* reload value, 9600 Bds at 11.059MHz */
   ES = 1; 						     /* Enable serial interrupt */
   TR2 = 1;                     /* Timer 2 run */
}
/******************************************
void InitUart()	             //InitUart use timer2
{
   SCON |= 0x50;			    // uart in mode 1 (8 bit), REN=1 
   T2CON &= 0xF0;               // EXEN2=0; TR2=0; C/T2#=0; CP/RL2#=0; 
   T2CON |= 0x30;               // RCLK = 1; TCLK=1; 
   TH2=0xFF;                    // init value 
   TL2=0xDC;                    // init value 
   RCAP2H=0xFF;                 // reload value, 9600 Bds at 11.059MHz 
   RCAP2L=0xDC;                 // reload value, 9600 Bds at 11.059MHz 
   ES = 1; 						// Enable serial interrupt 
   TR2 = 1;                     // Timer 2 run 
}
/*************************************************/
void serial() interrupt 4
{
	if(TI==1)
	{
	   TI=0;
	}
	if(RI==1)
	{
	   RI=0;
	   ReceiveDate = SBUF;
	   ReceiveFlag = 1;
	}
}
/*******************************************/
void sendchar(unsigned char SendData)
{
   SBUF = SendData;
}
/******************************************
   Delay Time  250uS*i
*******************************************/
void delay(unsigned int i)
{
	unsigned char j;
	for (; i>0; i--)
		for (j=0; j<255; j++);
}
/*******************************************
    
*******************************************/
void Buzzer(unsigned char status)
{
	if (status)
      P2 = 	P2 |= 0x20;
	else
	  P2 = P2 &= ~0x20;
}
/*******************************************
      CHECK PCB TYPE
*******************************************/
void Check_PCB(void)
{
   unsigned char PCB_TYPE,PCB_SELECT,PCB_SETUP;

       PCB_TYPE = P0;
	   if(PCB_SELECT == PCB_TYPE & 0x01)	    //tc
	     {
		     PCB_SETUP = 0x01;
		   
		     if(PCB_SELECT == PCB_TYPE & 0x010)	//mV_out
		       {PCB_SETUP = 0x11 ;}
		  	 else if(PCB_SELECT == PCB_TYPE & 0x020)	//mA_out
		           {PCB_SETUP = 0x21 ;}
		 }
	   else if(PCB_SELECT == PCB_TYPE & 0x02)	//rtd
		     {
			    PCB_SETUP = 0x02 ;

		      if(PCB_SELECT == PCB_TYPE & 0x010)	//mV_out
		        {PCB_SETUP = 0x21 ;}
		  	 else if(PCB_SELECT == PCB_TYPE & 0x020)	//mA_out
		           {PCB_SETUP = 0x22 ;}
		     }
	  else if(PCB_SELECT == PCB_TYPE & 0x04)	//mV
		     {
			  PCB_SETUP = 0x04 ;

			  if(PCB_SELECT == PCB_TYPE & 0x010)	//mV_out
		        {PCB_SETUP = 0x41 ;}
		  	 else if(PCB_SELECT == PCB_TYPE & 0x020)	//mA_out
		           {PCB_SETUP = 0x42 ;}
		     } 
	  else if(PCB_SELECT == PCB_TYPE & 0x08)	//mA
		    { 
			   PCB_SETUP = 0x08 ;

			 if(PCB_SELECT == PCB_TYPE & 0x010)	//mV_out
		        {PCB_SETUP = 0x81 ;}
		  	 else if(PCB_SELECT == PCB_TYPE & 0x020)	//mA_out
		           {PCB_SETUP = 0x82 ;}  
		    }
}
//==============================================
void EEPROM_write_word(unsigned char addr, unsigned int intdata)
{
	EEPROM_write_byte(addr++, (unsigned char)(intdata));
	EEPROM_write_byte(addr, (unsigned char)(intdata>>8));
}
//======================================
unsigned int EEPROM_read_word(unsigned char addr)
{
	unsigned int rdata;

	rdata = (unsigned int)(EEPROM_read_byte(addr+1));
	rdata <<= 8;
	rdata += (unsigned int)(EEPROM_read_byte(addr));

	return(rdata);	
}
//===========================================
void EEPROM_WriteDefault(void)
{
   unsigned char switch_status;
    
	 switch_status = P2 & 0x1f;

    EEPROM_write_byte(Mode_Select,5);
    EEPROM_write_byte(C_F_Select, 0);
	EEPROM_write_byte(Type_Select,0);  //Type define k=0.j=1,t=2
	EEPROM_write_word(TC_Zero, 0);	
	EEPROM_write_word(TC_Span, 0);
	EEPROM_write_word(RTD_Zero, 0);
	EEPROM_write_word(RTD_Span, 0);
	EEPROM_write_word(mV_Zero, 0);
	EEPROM_write_word(mV_Span, 0);
	EEPROM_write_word(mA_Zero, 0);	
    EEPROM_write_word(mA_Span, 0);
	EEPROM_write_word(Alarm_Low, 0);
	EEPROM_write_word(Alarm_Hi, 5000);
    EEPROM_write_byte(Year_Date, 2014);
    EEPROM_write_byte(Mon_Date, 1);
    EEPROM_write_byte(Day_Date, 1);
	EEPROM_write_byte(Week_Date, 3);
    EEPROM_write_byte(Hour_Date, 12);
    EEPROM_write_byte(Min_Date, 0);
	EEPROM_write_word(EEP_ADR, 50);
}
//==============================
unsigned char Setup_time_is_up(void)
{
	unsigned int i, reti;

	reti = 0;
	i = UseHour/24;
 	return(reti);	 
}
//======================================
void Init_Volt_Detect(void)
{
	r_step = 0;
	r_step_max = 0;
	r_step_cnt = 0;
	delay(1000);
}
//==================================
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
/************************************************/
void do_reset(void)
{
}
/************************************************/
void Volt_Ctrl(void)
{
}
/***********************************************/
unsigned char Get_Key(void)
{
    unsigned char key = 0;
  	unsigned char key_bak ;					// key1為了記錄按鍵是否被釋放過

  if(FUNCTION_KEY == 0)
    {
	 if(key_bak == 0)
	   {
	     key = (key |0x01);
	     key_bak = (key |0x01); 
	   }
	  else
	   {
		key = (key & 0xfe) ;
	   }
	 }
   if(OFFSET_KEY == 0)
    {
	 if(key_bak == 0)
	   {
	     key = (key |0x02);
	     key_bak = (key |0x02); 
	   }
	  else
	   {
		key = (key & 0xfd) ;
	   }
	 }
   if(UP_KEY == 0)
    {
	 if(key_bak == 0)
	   {
	     key = (key |0x04);
	     key_bak = (key |0x04); 
	   }
	  else
	   {
		key = (key & 0xfb) ;
	   }
	 }
   if(DOWN_KEY == 0)
    {
	 if(key_bak == 0)
	   {
	     key = (key |0x08);
	     key_bak = (key |0x08); 
	   }
	  else
	   {
		key = (key & 0xf7) ;
	   }
	 }

   return key;
}
/************************************************/
void do_electrolyze(void)
{
	unsigned char key=0;					// key1為了記錄按鍵是否被釋放過
	unsigned char rr=0, rr1=0;
	unsigned char Time_of_NoWater=0;
	unsigned char NoWaterVoice_Counter=0;
	unsigned char seg0=0,off_cut=0;
	bit rr2=0;
}
/************************************************/
unsigned int DO_TC_TYPE(void)
{
     unsigned int Code_Value,TC_Value;
	 unsigned char key;

      key = Get_Key();
	 
	  if(key == 0x01)
	  {
	     Work_Type = 5;
	  }
   else
     {
        Code_Value = Get_AD3421_Value();

       if (TC_Type == K_TYPE)
         {
	        Code_Value  = Code_Value*(Code_Value/(TC_Span_offset- TC_Zero_offset)); 
   	        TC_Value = Get_K_Slope(Code_Value);
	      }
        else if (TC_Type == J_TYPE)
          {
	         Code_Value  = Code_Value*(Code_Value/(TC_Span_offset- TC_Zero_offset));
   	         TC_Value = Get_J_Slope(Code_Value); 
	      }
        else if (TC_Type == T_TYPE)
          {
	         Code_Value  = Code_Value*(Code_Value/(TC_Span_offset- TC_Zero_offset));
   	         TC_Value = Get_T_Slope(Code_Value); 
	      }
        else if (TC_Type == E_TYPE)
          {
	         Code_Value  = Code_Value*(Code_Value/(TC_Span_offset- TC_Zero_offset));
   	         TC_Value = Get_E_Slope(Code_Value); 
	      }
        else if (TC_Type == R_TYPE)
          {
	         Code_Value  = Code_Value*(Code_Value/(TC_Span_offset- TC_Zero_offset));
   	         TC_Value = Get_R_Slope(Code_Value); 
	      }
        else if (TC_Type == S_TYPE)
          {
	         Code_Value  = Code_Value*(Code_Value/(TC_Span_offset- TC_Zero_offset));
   	         TC_Value = Get_S_Slope(Code_Value); 
	      }
        else if (TC_Type == B_TYPE)
          {
	         Code_Value  = Code_Value*(Code_Value/(TC_Span_offset- TC_Zero_offset));
   	         TC_Value = Get_B_Slope(Code_Value); 
	      }
        else if (TC_Type == N_TYPE)
          {
	         Code_Value  = Code_Value*(Code_Value/(TC_Span_offset- TC_Zero_offset));
   	         TC_Value = Get_N_Slope(Code_Value); 
	      }
      }

    return TC_Value;
}
/************************************************/
unsigned int Get_K_Slope(unsigned int Code_Value)
{
   unsigned int out_Value;


	 if((Code_Value > 1000) && (Code_Value < 2000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }    
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

   return out_Value;

}
/************************************************/
unsigned int Get_J_Slope(unsigned int Code_Value)
{
   unsigned int out_Value;


	 if((Code_Value > 1000) && (Code_Value < 2000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }    
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

   return out_Value;

}
/************************************************/
unsigned int Get_T_Slope(unsigned int Code_Value)
{
   unsigned int out_Value;


	 if((Code_Value > 1000) && (Code_Value < 2000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }    
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

   return out_Value;

}
/************************************************/
unsigned int Get_E_Slope(unsigned int Code_Value)
{
   unsigned int out_Value;


	 if((Code_Value > 1000) && (Code_Value < 2000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }    
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

   return out_Value;

}
/************************************************/
unsigned int Get_R_Slope(unsigned int Code_Value)
{
   unsigned int out_Value;


	 if((Code_Value > 1000) && (Code_Value < 2000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }    
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

   return out_Value;

}
/************************************************/
unsigned int Get_S_Slope(unsigned int Code_Value)
{
   unsigned int out_Value;


	 if((Code_Value > 1000) && (Code_Value < 2000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }    
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

   return out_Value;

}
/************************************************/
unsigned int Get_B_Slope(unsigned int Code_Value)
{
   unsigned int out_Value;


	 if((Code_Value > 1000) && (Code_Value < 2000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }    
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

   return out_Value;

}
/************************************************/
unsigned int Get_N_Slope(unsigned int Code_Value)
{
   unsigned int out_Value;


	 if((Code_Value > 1000) && (Code_Value < 2000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }    
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }
	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

	else if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   }

   return out_Value;

}

/************************************************/
unsigned int DO_RTD_TYPE(void)
{
     unsigned int Code_Value,RTD_Value;
	 unsigned char key;

      key = Get_Key();
	 
	  if(key == 0x01)
	  {
	     Work_Type = 5;
	  }
	else
	 {
       Code_Value = Get_AD3421_Value();
	   Code_Value  = Code_Value*(Code_Value/(TC_Span_offset- TC_Zero_offset)); 
   	   RTD_Value = Code_Value*(Code_Value/(RTD_Span_offset- RTD_Zero_offset)); 


	 if((RTD_Value > 1000) && (RTD_Value < 2000))
	   {
	   }
	else if((RTD_Value > 2000) && (RTD_Value < 3000))
	   {
	   }    
	else if((RTD_Value > 2000) && (RTD_Value < 3000))
	   {
	   }
	else if((RTD_Value > 2000) && (RTD_Value < 3000))
	   {
	   }
	else if((RTD_Value > 2000) && (RTD_Value < 3000))
	   {
	   }
	else if((RTD_Value > 2000) && (RTD_Value < 3000))
	   {
	   }
	else if((RTD_Value > 2000) && (RTD_Value < 3000))
	   {
	   }
	}
   return RTD_Value;
}
/************************************************/
unsigned int DO_mV_TYPE(void)
{
     unsigned int Code_Value,mV_Value;
	 unsigned char key;

      key = Get_Key();
	 
	  if(key == 0x01)
	    {
	      Work_Type = 5;
	    }
  	 else
	   {
         Code_Value = Get_AD3421_Value();
         mV_Value = Code_Value*( Code_Value/(mV_Span_offset - mV_Zero_offset));
	   }
	 return mV_Value ;
}
/************************************************/
unsigned int DO_mA_TYPE(void)
{
     unsigned int Code_Value,mA_Value;
	 unsigned char key;

      key = Get_Key();
	 
	  if(key == 0x01)
	    {
	      Work_Type = 5;
	    }
  	 else
	   {
         Code_Value = Get_AD3421_Value();
         mA_Value = Code_Value*(Code_Value/(mA_Span_offset - mA_Zero_offset));
	   }
	 return mA_Value;
}
/************************************************/
void RTC_WRITE_SET()
{
RTC_write_byte(0,0x02);
RTC_write_byte(3,use_min);
RTC_write_byte(4,use_hour);
RTC_write_byte(5,use_week);
RTC_write_byte(6,use_day);
RTC_write_byte(7,use_mon);
RTC_write_byte(8,use_year);
RTC_write_byte(0,0);
}

/************************************************/
void RTC_READ_SET()
{
 RTC_write_byte(0,0x01);
 use_min = RTC_read_byte(3);
 use_hour = RTC_read_byte(4);
 use_week = RTC_read_byte(5);
 use_day = RTC_read_byte(6);
 use_mon = RTC_read_byte(7);
 use_mon = RTC_read_byte(8);
 RTC_write_byte(0,0);
}

/*************************************************/	
void DO_SETUP_TYPE(void)
{
	unsigned int  zero_cal = 0;
	unsigned int  span_cal = 0;
 	unsigned char cExit;
	unsigned char set_key = 0,  times = 0;
	unsigned char confrom_key,up_key,don_key,item_key;

	
    	while (ITEM < PRODUCT_RESET)
	         {
		       if (ITEM == NOMAL_FUNCTION)
		         {
			       SETUP_LED_Disp(0,0);
			       tmp1 = EEPROM_read_byte(C_F_Select);  //sbit FUNCTION_SELECT   = P3^2;sbit OFFSET_SELECT     = P3^3;
			       SETUP_LED_Disp(0,tmp1);
			       cExit = 0;

			       while (! cExit)
			            {
				          set_key = Get_Key();

						  if((set_key & 0x01) == 1) item_key = 1 ; else item_key = 0 ;
						  if((set_key & 0x02) == 1) confrom_key = 1 ; else confrom_key = 0 ;
						  if((set_key & 0x04) == 1) up_key = 1 ;  else up_key = 0 ;
			              if((set_key & 0x08) == 1) don_key = 1 ; else don_key = 0 ;
		                }

	   	                  if (ITEM == TYPE_CAL)
		                     {	}
	                      if (ITEM == C_F_CAL)
		                     {	}
 	                      if (ITEM == TC_ZERO_CAL)
		                     {   }
	                      if (ITEM == TC_SPAN_CAL)
		                     {  	}
	                      if (ITEM == RTD_ZERO_CAL)
		                     {   }
		                  if (ITEM == RTD_SPAN_CAL)
		                     {   }
		                  if (ITEM == mV_ZERO_CAL)
		                     {   }
		                  if (ITEM == mV_SPAN_CAL)
		                     {   }
		                  if (ITEM == mA_ZERO_CAL)
		                     {   }
		                  if (ITEM == mA_SPAN_CAL)
		                     {   }
		                  if (ITEM == ALARM_LO_CAL)
		                     {   }
		                  if (ITEM == ALARM_HI_CAL)
		                     {   }
		                  if (ITEM == YEAR_DATE_CAL)
		                     {   }
		                  if (ITEM == MON_DATE_CAL)
		                     {   }
		                  if (ITEM == DAY_DATE_CAL)			//add week setup
		                     {   }
		                  if (ITEM == HOUR_DATE_CAL)
		                     {   }
	                      if (ITEM == MIN_DATE_CAL)
		                     {   }
					}
			 }

		if( MAIN_SW == OFF)
  	      {
	         Work_Type = EEPROM_read_byte(Mode_Select); 
	      }
}
//*******************************
void DO_RESET_TYPE(void)
{
	
     EEPROM_WriteDefault();
     LED_Fill();                                     //  LED all light
	 Work_Type = EEPROM_read_byte(Mode_Select);
	 C_F_Type = EEPROM_read_byte(C_F_Select);
	 TC_Type = EEPROM_read_byte(Type_Select);       //Type define k=0.j=1,t=2
	 TC_Zero_offset = EEPROM_read_word(TC_Zero);	
	 TC_Span_offset = EEPROM_read_word(TC_Span);
	 RTD_Zero_offset = EEPROM_read_word(RTD_Zero);
	 RTD_Span_offset = EEPROM_read_word(RTD_Span);
	 mA_Zero_offset = EEPROM_read_word(mA_Zero);
	 mA_Span_offset = EEPROM_read_word(mA_Span);
	 mV_Zero_offset = EEPROM_read_word(mV_Zero);	
     mV_Span_offset = EEPROM_read_word(mV_Span);
	 alarm_Low_set = EEPROM_read_word(Alarm_Low);
	 alarm_Hi_set = EEPROM_read_word(Alarm_Hi);
     use_year = EEPROM_read_word(Year_Date);
     use_mon = EEPROM_read_word(Mon_Date);
     use_day = EEPROM_read_word(Day_Date);
	 use_week = EEPROM_read_word(Week_Date);
     use_hour = EEPROM_read_word(Hour_Date);
     use_min = EEPROM_read_word(Min_Date);
	 eep_count = EEPROM_read_word(EEP_ADR);
}
/***********************************
****      System_Start          ****
***********************************/ 
main(void)
{
	PORT_Init();
	EEPROM_Init();
	LED_Init();
    LED_Fill();
 	T0_Init();
	T1_Init();
	INT0_Init();
	AD3421_Init();
	InitUart();
    Set_mA(0);
	Set_mV(0);
	Buzzer(OFF);
	Soft_Timer_Enable = 0;
	EX0 = 0;

 	if ((EEPROM_read_byte(0) != 'N')||(EEPROM_read_byte(1) != 'E')||(EEPROM_read_byte(2) != 'W')||(EEPROM_read_byte(3) != JOHNSON)||(EEPROM_read_byte(4) != LIN))
	  {
		EEPROM_write_byte(0, 'N');	
		EEPROM_write_byte(1, 'E');
		EEPROM_write_byte(2, 'W');
		EEPROM_write_byte(3, JOHNSON);	
		EEPROM_write_byte(4, LIN);	
		EEPROM_WriteDefault();
      }

      LED_Fill();                                     //  LED all light
	
	 Check_PCB();

	 Work_Type = EEPROM_read_byte(Mode_Select);   	
	 C_F_Type = EEPROM_read_byte(C_F_Select);
 	 TC_Type  = EEPROM_read_byte(Type_Select);       //Type define k=0.j=1,t=2
	 TC_Zero_offset = EEPROM_read_word(TC_Zero);	
	 TC_Span_offset = EEPROM_read_word(TC_Span);
	 RTD_Zero_offset = EEPROM_read_word(RTD_Zero);
	 RTD_Span_offset = EEPROM_read_word(RTD_Span);
	 mA_Zero_offset = EEPROM_read_word(mV_Zero);
	 mA_Span_offset = EEPROM_read_word(mV_Span);
	 mV_Zero_offset = EEPROM_read_word(mA_Zero);	
     mV_Span_offset = EEPROM_read_word(mA_Span);
	 alarm_Low_set = EEPROM_read_word(Alarm_Low);
	 alarm_Hi_set = EEPROM_read_word(Alarm_Hi);
     use_year = EEPROM_read_byte(Year_Date);
     use_mon = EEPROM_read_byte(Mon_Date);
     use_day = EEPROM_read_byte(Day_Date);
     use_hour = EEPROM_read_byte(Hour_Date);
     use_min = EEPROM_read_byte(Min_Date);
	 eep_count =EEPROM_read_word(EEP_ADR);
	 Disp_year = use_year+1911;
 	 EA = 1;
	 MAIN_SW = 1 ;
	 RTC_WRITE_SET();
 // if ((C_F_Type & 0x01) != 1)		             // 0 = C , 1 = F
//	  {	
//	  	TempValue  = ((TempValue - 320)*5/9) ;								   
//	  }
	 Work_Type = EEPROM_read_byte(Type_Select);  //Type define k=0.j=1,t=2

//***************************************
	while (1)
	{
		switch (Work_Type)
		  {
			case TC_FUNCTION:
				DO_TC_TYPE();
				break;

			case RTD_FUNCTION:
		    	DO_RTD_TYPE();
				break;

			case mV_FUNCTION:
				DO_mV_TYPE();
				break;

			case mA_FUNCTION:
			    DO_mA_TYPE();
				break;
			
			case RESET_FUNCTION:	  //ok
				DO_RESET_TYPE();
				break;

			 case SETUP_FUNCTION:
				DO_SETUP_TYPE();	 //
				break;
	
	     }
	 }
/*	  
#define	K_TYPE		0		//2466F   54.807mV	P0=0x00
#define	J_TYPE		1		//1368F   42.922mV
#define	T_TYPE   	2		//360F    9.286mV
#define	E_TYPE		3		//1440F   61.022mV
#define	R_TYPE		4		//2880F   18.842mV
#define	S_TYPE		5		//2880F   16.771mV
#define	B_TYPE		6		//3240F   13.585mV
#define	N_TYPE	    7		//?       ?
sbit TC_SW1    = P0^0;	//k=0x00;j=0x01;t=0x02;e=0x03; 
sbit TC_SW2    = P0^1;	//r=0x04;s=0x05;b=0x06;n=0x07;
sbit TC_SW3    = P0^2;

sbit TYPE_SW1  = P0^3;	 //tc= 000 00xxx;  rtd=000 01xxx;    mV=000 10xxx
sbit TYPE_SW2  = P0^4;	 //mA= 000 11xxx;
sbit TYPE_SW3  = P0^5;
*/
}