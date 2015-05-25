/**************************************************************



***************************************************************/
#include <MPC82G516.h>
#include <intrins.h>
#include <LED.h>
#include <AD111.h>
#include <MCP4011.h>
#include <EEPROM.H>
#include <STDLIB.H>
#include <TYPE_SLOPE.H>

#define   BASE_TEMP			32		 //F & C Transfor Data
#define   MAX_TEMP			3240     //F 1800C
#define   MAX_VOLT			4400	 //mV
#define   EEP_START			60
#define   EEP_END			20000
#define JOHNSON             0x5a
#define LIN                 0xa5

#define	K_TYPE		0		//2466F   54.807mV	P0=0x00
#define	J_TYPE		1		//1368F   42.922mV
#define	T_TYPE   	2		//360F    9.286mV
#define	E_TYPE		3		//1440F   61.022mV
#define	R_TYPE		4		//2880F   18.842mV
#define	S_TYPE		5		//2880F   16.771mV
#define	B_TYPE		6		//3240F   13.585mV
#define	N_TYPE	    7		//?       ?

#define	TC_FUNCTION		0
#define	RTD_FUNCTION	1
#define	mV_FUNCTION		2
#define	mA_FUNCTION		3
#define	SETUP_FUNCTION	4
#define	RESET_FUNCTION	5


//#define	TC_ZERO_CAL   	0
//#define	RTD_ZERO_CAL	1
//#define	mV_ZERO_CAL		2
//#define	mA_ZERO_CAL		3


#define	DISPLAY_SEND_TIME  0	   //timer out work select
#define	DATA_SAVE_TIME     1
#define	DATA_SEND_TIME     2
#define	SETUP_TIMEOUT      3
#define	TIMEUP_TIME        4

#define  C_F_Select  18	            //EEP Address
#define  Type_Select 19
#define  TC_Zero    20	  
#define  TC_Span    22
#define  RTD_Zero   24
#define  RTD_Span   26
#define  mA_Zero    28									  
#define  mA_Span    30
#define  mV_Zero    32
#define  mV_Span    34
#define  Alarm_Low  36
#define  Alarm_Hi   38
#define  Year_Date  40
#define  Mon_Date   42
#define  Day_Date   44
#define  Hour_Date  46
#define  Min_Date   48
#define  EEP_ADR    50

sbit TC_SW1    = P0^0;	//k=0x00;j=0x01;t=0x02;e=0x03; 
sbit TC_SW2    = P0^1;	//r=0x04;s=0x05;b=0x06;n=0x07;
sbit TC_SW3    = P0^2;

sbit TYPE_SW1  = P0^3;	 //tc= 000 00xxx;  rtd=000 01xxx;    mV=000 10xxx
sbit TYPE_SW2  = P0^4;	 //mA= 000 11xxx;
sbit TYPE_SW3  = P0^5;

sbit NONE_06   = P0^6;
sbit NONE_07   = P0^7;

sbit LED1_SCL = P1^0;
sbit LED1_SDA = P1^1;
sbit LED2_SCL = P1^2;
sbit LED2_SDA = P1^3;
sbit LED3_SCL = P1^4;
sbit LED3_SDA = P1^5;
sbit RTC_SCL  = P1^6;
sbit RTC_SDA  = P1^7;

sbit mV_SCL   = P2^0;
sbit mV_SDA   = P2^1;
sbit mA_SCL   = P2^2;
sbit mA_SDA   = P2^3;
sbit EEP_SCL  = P2^4;
sbit EEP_SDA  = P2^5;
sbit Value_SCL  = P2^6;
sbit Value_SDA  = P2^7;

sbit R485_RX           = P3^0;
sbit R485_TX           = P3^1;
sbit FUNCTION_SELECT   = P3^2;
sbit OFFSET_SELECT     = P3^3;
sbit BEEP_OUT          = P3^4;	 //for relay
sbit R485_DE_RE        = P3^5;
sbit NOME_36           = P3^6;
sbit NOME_37           = P3^7;
//===============================
extern unsigned int KX;	
extern unsigned int R;	
extern unsigned int	TC_type_zero[8];
extern unsigned int	TC_type_span[8];
extern unsigned char key_delay[16];

idata unsigned char Soft_Timer[8] = {0,0,0,0,0,0,0,0};
idata unsigned char T0_cnt, T1_cnt;

unsigned char MAIN_SWITCH ;
unsigned char C_F_Type;
unsigned char Work_Type;

unsigned int  TC_Zero_offset;
unsigned int  TC_Span_offset;
unsigned int  RTD_Zero_offset;
unsigned int  RTD_Span_offset;
unsigned int  mA_Zero_offset;
unsigned int  mA_Span_offset;
unsigned int  mV_Zero_offset;
unsigned int  mV_Span_offset;
unsigned int  alarm_Low_set;
unsigned int  alarm_Hi_set;
unsigned int  use_year;
unsigned int  use_mon;
unsigned int  use_day;
unsigned int  use_hour;
unsigned int  use_min;
unsigned int  eep_count;

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
//	Get_AD111_Value(Value_code);
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
	AD111_Init();
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
   TL2=0xDC;                    /* init value */
   RCAP2H=0xFF;                 /* reload value, 9600 Bds at 11.059MHz */
   RCAP2L=0xDC;                 /* reload value, 9600 Bds at 11.059MHz */
   ES = 1; 						     /* Enable serial interrupt */
   TR2 = 1;                     /* Timer 2 run */
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

    EEPROM_write_byte(C_F_Select, 0);
	EEPROM_write_byte(Type_Select,0);  //Type define k=0.j=1,t=2
	EEPROM_write_word(TC_Zero, 0);	
	EEPROM_write_word(TC_Span, 0);
	EEPROM_write_word(RTD_Zero, 0);
	EEPROM_write_word(RTD_Span, 0);
	EEPROM_write_word(mA_Zero, 0);
	EEPROM_write_word(mA_Span, 0);
	EEPROM_write_word(mV_Zero, 0);	
    EEPROM_write_word(mV_Span, 0);
	EEPROM_write_word(Alarm_Low, 0);
	EEPROM_write_word(Alarm_Hi, 5000);
    EEPROM_write_word(Year_Date, 2014);
    EEPROM_write_word(Mon_Date, 1);
    EEPROM_write_word(Day_Date, 1);
    EEPROM_write_word(Hour_Date, 12);
    EEPROM_write_word(Min_Date, 0);
	EEPROM_write_word(EEP_ADR, 60);
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
//	Decrement_R(64);
	delay(1000);
}
//===========================================
void SetCurrent(int  crunt)        		// current in mA
{
 crunt = 0;
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
void SetmV(void)
{
}
/************************************************/
void SetmA(void)
{
}
/**********************************************/
void Volt_Ctrl(void)
{
}
/************************************************/
void Disp_test(void)
{
}
/************************************************/
void LED_Fill(void)
{
}
/***********************************************/
unsigned char Get_Key(void)
{
    unsigned char key = 0;
  	unsigned char key_bak = 0;					// key1為了記錄按鍵是否被釋放過
	  




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
  
     Code_Value = Get_AD111_Value();

    if (Work_Type == 0)
      {
	   Code_Value = Code_Value - TC_Zero_offset;
   	   TC_Value = Get_K_Slope(Code_Value);
	  }
   else if (Work_Type == 1)
      {
	   Code_Value = Code_Value - TC_Zero_offset;
   	   TC_Value = Get_J_Slope(Code_Value); 
	  }
   else if (Work_Type == 2)
      {
	   Code_Value = Code_Value - TC_Zero_offset;
   	   TC_Value = Get_T_Slope(Code_Value); 
	  }
   else if (Work_Type == 3)
      {
	   Code_Value = Code_Value - TC_Zero_offset;
   	   TC_Value = Get_E_Slope(Code_Value); 
	  }
   else if (Work_Type == 4)
      {
	   Code_Value = Code_Value - TC_Zero_offset;
   	   TC_Value = Get_R_Slope(Code_Value); 
	  }
   else if (Work_Type == 5)
      {
	   Code_Value = Code_Value - TC_Zero_offset;
   	   TC_Value = Get_S_Slope(Code_Value); 
	  }
   else if (Work_Type == 6)
      {
	   Code_Value = Code_Value - TC_Zero_offset;
   	   TC_Value = Get_B_Slope(Code_Value); 
	  }
   else if (Work_Type == 7)
      {
	   Code_Value = Code_Value - TC_Zero_offset;
   	   TC_Value = Get_N_Slope(Code_Value); 
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
  
     Code_Value = Get_AD111_Value();
	
	 Code_Value = Code_Value - RTD_Zero_offset;

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

   return RTD_Value;

}
/************************************************/
void DO_mV_TYPE(void)
{
     unsigned int Code_Value,mV_Value;
  
     Code_Value = Get_AD111_Value();
     mV_Value = Code_Value - mV_Zero_offset;
}
/************************************************/
void DO_mA_TYPE(void)
{
     unsigned int Code_Value,mA_Value;
  
     Code_Value = Get_AD111_Value();
     mA_Value = Code_Value - mA_Zero_offset;
}

/*************************************************/	
void DO_SETUP_TYPE(void)
{
#define ITEM              0
#define C_F_CAL           1
#define TYPE_CAL          2
#define TC_ZERO_CAL       3
#define TC_SPAN_CAL       4
#define RTD_ZERO_CAL      5
#define RTD_SPAN_CAL      6
#define mV_ZERO_CAL       7
#define mV_SPAN_CAL       8
#define mA_ZERO_CAL       9
#define mA_SPAN_CAL       10
#define ALARM_LO_CAL      11
#define ALARM_HI_CAL      12
#define YEAR_DATE_CAL     13
#define MON_DATE_CAL      14
#define DAY_DATE_CAL      15
#define HOUR_DATE_CAL     16
#define MIN_DATE_CAL      17
#define PRODUCT_RESET     18
#define NOMAL_FUNCTION    0

	unsigned int  zero_cal = 0;
	unsigned int  span_cal = 0;
 	unsigned char cExit;
	unsigned char key=0,  times = 0;

	PlaySound(1);

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
				key = Get_Key();
			 }
		}
	    if (ITEM == C_F_CAL)
		{	}
		if (ITEM == TYPE_CAL)
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
		if (ITEM == DAY_DATE_CAL)
		{   }
		if (ITEM == HOUR_DATE_CAL)
		{   }
		if (ITEM == MIN_DATE_CAL)
		{   }
	 }
}
//*******************************
void DO_RESET_TYPE(void)
{
	
     EEPROM_WriteDefault();
     Disp_test();                                     //  LED all light
	 C_F_Type = EEPROM_read_byte(C_F_Select);
 	 Work_Type = EEPROM_read_byte(Type_Select);       //Type define k=0.j=1,t=2
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
     use_hour = EEPROM_read_word(Hour_Date);
     use_min = EEPROM_read_word(Min_Date);
	 eep_count = EEPROM_read_word(EEP_ADR);
}
/**************************************
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
	AD111_Init();
	InitUart();
	EA = 1;

//	SetmA();
	SetmV();
	Buzzer(0);
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

      Disp_test();                                     //  LED all light

     Work_Type = P0 & 0x1f ;   
	    	
	 C_F_Type = EEPROM_read_byte(C_F_Select);
 	 Work_Type = EEPROM_read_byte(Type_Select);       //Type define k=0.j=1,t=2
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
     use_hour = EEPROM_read_word(Hour_Date);
     use_min = EEPROM_read_word(Min_Date);
	 eep_count =EEPROM_read_word(EEP_ADR);

	 MAIN_SWITCH = 1 ;

  if (C_F_Type & 0x01)		             // 0 = C , 1 = F
	  {	
	  	TempValue  = (TempValue * 9 /5) + 32 ;								   
	  }
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
			
			case SETUP_FUNCTION:
				DO_SETUP_TYPE();	 //
				break;

			case RESET_FUNCTION:	  //ok
				DO_RESET_TYPE();
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