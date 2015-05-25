/***********************************************
  PRODUCT FOR NEWCAL MIX_TEMP FUNCTION
   CPU : MPC82G516
   BEGIN DATE: 2013.11.01
   FINISHED  : 2014.01.25
   WRITEBY   :JOHNSON LIN
   AD111  setup   SET 1001 0000 FOR A0 TYPE 
    8CH =  pga =1 ,32767BITS
**************************************************/
#include <MG82FE564.H>
#include <intrins.h>
#include <IO_DEFINE.h>
#include <LED.h>
#include <AD3421.h>
#include <DAC6571_mV.h>
#include <DAC6571_mA.h>
#include <MCP79411.h>
#include <EEPROM.H>
#include <STDLIB.H>
#include <TYPE_SLOPE.H>

#define   BASE_TEMP		32	 //F & C Transfor Data
#define   MAX_TEMP		3240     //F 1800C
#define   MAX_VOLT		2048	 //mV
#define   EEP_START		60
#define   EEP_END		2000
#define   JOHNSON       0x5a
#define   LIN           0xa5

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
#define	SETUP_FUNCTION	4
#define	CLEAR_FUNCTION	5

#define   ON    1
#define   OFF   0

//timer out work select
#define	DISPLAY_SEND_TIME  0	 // DISPLAY TIME  
#define	ADC_READ_TIME      1     //	ADC_READ_TIME
#define	RTC_READ_TIME      2     //	RTC_READ_TIME
#define	RTC_SEND_TIME      3     //	RTC_SEND_TIME
#define UART_SEND_TIME     4	 //	UART_SEND_TIME
#define MV_SEND_TIME       5	 // mV_OUT_ TIME
#define	SETUP_TIMEOUT      6	 //	FAIL_TIMEOUT
#define	TIMEUP_TIME        7	 //


#define NOMAL_FUNCTION    0
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
#define SEC_DATE_CAL      19
#define PRODUCT_RESET     20
#define  SQWE           0x40            //  SQWE = b6  
#define  MFP_01H        0x00 
#define  OSC_EN         0x80			// day bit 7

#define  sec     0x00  
#define  min   	 0x01 
#define  hour	 0x02
#define  week	 0x03
#define  day	 0x04
#define  month   0x05
#define  year	 0x06
#define  ctl	 0x07
	           
#define  Mode_Select 18    //EEP Address
#define  C_F_Select  19
#define  Type_Select 20
#define  TC_Zero     22	  
#define  TC_Span     24
#define  RTD_Zero    26
#define  RTD_Span    28
#define  mV_Zero     30									  
#define  mV_Span     32
#define  mA_Zero     34
#define  mA_Span     36
#define  Alarm_Low   38
#define  Alarm_Hi    40
#define  Year_Date   42
#define  Mon_Date    43
#define  Day_Date    44
#define  Week_Date   45
#define  Hour_Date   46
#define  Min_Date    47
#define  sec_Date    48
#define  Status_flag 50
#define  TC_Span_Per 52
#define  RTD_Span_Per 54
#define  mV_Span_Per 56
#define  mA_Span_Per 58
#define  EEP_ADR     60
//===============================
extern unsigned char key = 0,key_bak = 0;
extern unsigned char AV_COD ;
extern unsigned char NP_COD ;
unsigned char NG_COD,ADD_COD;
unsigned char OVER_COD = 0 ;
idata unsigned char Soft_Timer[8] = {16,16,4,2,59,2,20,30};
idata unsigned char T0_cnt,T2_cnt, T1_cnt;
idata unsigned int   Data_Value[10] ;
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
unsigned char  use_flag;
unsigned char  use_year = 0x14;
unsigned char  use_mon  = 0x01;
unsigned char  use_day  = 0x01;
unsigned char  use_week = 0x03;
unsigned char  use_hour = 0x12;
unsigned char  use_min  = 0x01;
unsigned char  use_sec  = 0x01;
unsigned char  eep_count;
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
/***************************************
	   Port In/Out Setting
*****************************************/
void PORT_Init(void)
{
	P0M0 = 0xFF;	  //00=Qb,01=pull output, 10= input only,11=open drain
 	P0M1 = 0x00;	 //P0= ALL INPUT
	P0   = 0xff;

	P1M0 = 0x00;	 //P1= ALL OUTPUT
	P1M1 |= 0xFF;     //SETUP P1 ALL LO //  define P1.3 P1.4 P1.5 as push-pull
    P1   = 0x00;

	P2M0 = 0x04;	 //P2= ALL OUTOUT
	P2M1 = 0xFF; 	 //SETUP P2 ALL LO
	P2   = 0x00;

    P3M0 = 0xED;	 //
	P3M1 = 0x13;
	P3   = 0x2C;
}
/*******************************************
     interrupt   0
*******************************************/
void ex_int0(void) interrupt 0
{;
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
	Value_code = SBUF;
	TH0 = 0x0B;	 //0b
	TL0 = 0xDC;
	TR0 = 1;
}

/*******************************************
     interrupt   3
*******************************************/
void time1(void) interrupt  3   //    T=1/16 sec 
{
	TR1 = 0;
	T0_cnt++;							

	if (Soft_Timer[DISPLAY_SEND_TIME] != 0)		Soft_Timer[DISPLAY_SEND_TIME]--;
	if (Soft_Timer[ADC_READ_TIME] != 0)         Soft_Timer[ADC_READ_TIME]--;
	if ((T0_cnt%8)==0)	
	  {
//	  if (Soft_Timer[DISPLAY_SEND_TIME] != 0)		Soft_Timer[DISPLAY_SEND_TIME]--;
	  if (Soft_Timer[RTC_READ_TIME] != 0)	Soft_Timer[RTC_READ_TIME]--;
	    f_half_sec = 1;
	  }
	if (T0_cnt == 15)
	{
		T0_cnt = 0;
		if (Soft_Timer[UART_SEND_TIME] != 0)	Soft_Timer[UART_SEND_TIME]--;
		if (Soft_Timer[MV_SEND_TIME] != 0)	    Soft_Timer[MV_SEND_TIME]--;
		if (Soft_Timer[SETUP_TIMEOUT] != 0)     Soft_Timer[SETUP_TIMEOUT]--;	
		if (Soft_Timer[TIMEUP_TIME] != 0)		Soft_Timer[TIMEUP_TIME]--;
	}	    	
	TH1 = 0x0B;
	TL1 = 0xDC;
	TR1 = 1;
 }		
/*******************************************/
void T0_Init(void)
{
	TR0 = 1;
	TMOD = 0x11;
	TH0 = 0x0B;		
	TL0 = 0xDC;	
	T0_cnt = 0;
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
 }
/*******************************************
    
*******************************************/
void T2_Init(void)
{
	TR2 = 1;
	T2MOD = 0x11;  //11  
	TH2 = 0x0B;
	TL2 = 0xDC;
	T2_cnt = 0;
}
/*******************************************
    
*******************************************/
void INT0_Init(void)
{
    INT0 = 1;
	INT1 = 1;	 
	IE0  = 1;		   
	IT0  = 1;
	EX0  = 0;	  
}
/*******************************************/
void InitUart()	   //InitUart use timer2
{
   SCON |= 0x50;			  /* uart in mode 1 (8 bit), REN=1 50 */
   T2CON &= 0xF0;               /* EXEN2=0; TR2=0; C/T2#=0; CP/RL2#=0; */
   T2CON |= 0x30;               /* RCLK = 1; TCLK=1; */
   TH2=0xFF;                    /* init value */
   TL2=0xD0;                    /* init value */
   RCAP2H=0xFF;                 /* reload value, 9600 Bds at 11.059MHz */
   RCAP2L=0xDC;                /* reload value, 9600 Bds at 11.059MHz */
   ES = 1; 						     /* Enable serial interrupt */
   TR2 = 1;                     /* Timer 2 run */
}
/*************************************************/
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
/****************************************
 	  if(tran == 0)
	    {
	     tran = 1 ; 
	    }		   
	 else
	  { 
	    Data_Value = Data_Value >> 8 ;
	    tran = 0;
    	Soft_Timer[UART_SEND_TIME] = 59 ;
	  } 
   SBUF = Data_Value;
}
/****************************************/
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
  	   if(P00 == 0)                //tc
	     {
		     Work_Type = 0x00;
			 Func_Type = 0x00;
			 PCB_SETUP = 0x01;
		     if(P04 == 0)	    //mV_out
		       {PCB_SETUP = 0x11 ;}
  	         if(P05 == 0)	//mA_out
		       {PCB_SETUP = 0x21 ;}
			 if(use_flag == 0x01) { NG_COD = 1;}
		 }
	   else if(P01 == 0)	       //rtd
		 {
			  Work_Type = 0x01;
			  Func_Type = 0x01;
			    PCB_SETUP = 0x02 ;
		      if(P04 == 0)	//mV_out
		        {PCB_SETUP = 0x12 ;}
		      if(P05 == 0)	//mA_out
		        {PCB_SETUP = 0x22 ;}
			   if(use_flag == 0x02) { NG_COD = 1;}
		 }
	  else if(P02 == 0)	     //mV
		 {
			 Work_Type = 0x02 ;
			 Func_Type = 0x02;
			  PCB_SETUP = 0x04 ;
			  if(P04 == 0)	//mV_out
		        {PCB_SETUP = 0x14 ;}
		      if(P05 == 0)	//mA_out
		        {PCB_SETUP = 0x24 ;}
			   if(use_flag == 0x04) { NG_COD = 1;}
		 } 
	  else if(P03 == 0)	        //mA
		 { 
		     Work_Type = 0x03 ;
			 Func_Type = 0x03;
			   PCB_SETUP = 0x08 ;
			 if(P04 == 0)	        //mV_out
		       {PCB_SETUP = 0x18 ;}
		     if(P05 == 0)	//mA_out
		       {PCB_SETUP = 0x28 ;}
			 if(use_flag == 0x08) { NG_COD = 1;}  
		 }
}
/***********************************************/
unsigned int TEMP_F_TO_C(unsigned int tc_tmp)
{
 unsigned int ttmp;

	  if(NP_COD == 0)
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
		   if(AV_COD == 1)
			 {
	           ttmp = (320+tc_tmp)/1.8;
             }
		   else
		     {
			  ttmp = (320-tc_tmp)/1.8;
			 AV_COD = 1 ;
			 }
		 }
	   }
	  else
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
		   if(AV_COD == 1)
			 {
	           ttmp = (32+tc_tmp)/1.8;
             }
		   else
		     {
			  ttmp = (32-tc_tmp)/1.8;
			  AV_COD = 1 ;
			 }
		  }

       } 
       return(ttmp);
}
/**********************************************/
void Volt_Ctrl(void)
{
}
/***********************************************/
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
/************************************************/
unsigned  int DO_TC_TYPE(void)
{
    unsigned int Code_Value,TC_Value;
	 unsigned char key;

      key = Get_Key();
	 
	  if(key == 0x01)
	  {
	     Func_Type = 4;
	  }
   else
    {
		if (Soft_Timer[ADC_READ_TIME] == 0) 
		   {
		      Soft_Timer[ADC_READ_TIME] = 16;
	   		  Code_Value =  Read_AD3421_Value();
	  
			 if((NG_COD == 1)&&(AV_COD == 1))
			   {
					  if( Code_Value >= TC_Zero_offset)
					    {
					     Code_Value = Code_Value - TC_Zero_offset;
						}
					   else
					    {
						 Code_Value = TC_Zero_offset -Code_Value;
						 AV_COD = 0;
						}
				}
			  else if((NG_COD == 1)&&(AV_COD == 0))
			    {
				   Code_Value = Code_Value + TC_Zero_offset;   // ?
			    } 		
     		  else if((NG_COD == 0)&&(AV_COD == 1))
			    {
				   Code_Value = Code_Value + TC_Zero_offset;
			    }   
			  else if((NG_COD == 0)&&(AV_COD == 0))
			    {
				       if( Code_Value >= TC_Zero_offset)
					    {
					     Code_Value = Code_Value - TC_Zero_offset;
						}
					   else
					    {
						 Code_Value = TC_Zero_offset - Code_Value;
					     AV_COD = 1 ;
						}
				} 
				   if(ADD_COD == 1 )   //Code_Value < 0xc8ca)   //ADD_COD == 1)
					 { Code_Value = Code_Value -(Code_Value/TC_Span_Value); }
				  else
					 { Code_Value = Code_Value + (Code_Value/TC_Span_Value);}  
//					  Code_Value = 0xc8ca ;	 //   1200.0 
					if(OVER_COD == 1) Code_Value = 0xffff;
	  	    if (TC_Type == K_TYPE)
              {
   	            TC_Value  = Get_K_Slope(Code_Value);

				if (C_F_Type == 0) TC_Value = TEMP_F_TO_C(TC_Value);
	          }
            else if (TC_Type == J_TYPE)
              {
   	            TC_Value = Get_J_Slope(Code_Value);
				if (C_F_Type == 0) TC_Value = TEMP_F_TO_C(TC_Value); 
	          }
            else if (TC_Type == T_TYPE)
              {
  	            TC_Value = Get_T_Slope(Code_Value);
				if (C_F_Type == 0) TC_Value = TEMP_F_TO_C(TC_Value); 
	          }
            else if (TC_Type == E_TYPE)
              {
   	           TC_Value = Get_E_Slope(Code_Value); 
			   if (C_F_Type == 0) TC_Value = TEMP_F_TO_C(TC_Value);
	          }
            else if (TC_Type == R_TYPE)
              {
			    NP_COD = 1;
  	            TC_Value = Get_R_Slope(Code_Value); 
				if (C_F_Type == 0)  TC_Value = TEMP_F_TO_C(TC_Value);
	          }
            else if (TC_Type == S_TYPE)
              {
			     NP_COD = 1;
   	            TC_Value = Get_S_Slope(Code_Value);
				if (C_F_Type == 0) 	TC_Value = TEMP_F_TO_C(TC_Value); 
	          }
/*
            else if (TC_Type == B_TYPE)
              {
			    NP_COD = 1;
//	            Code_Value  = Code_Value*(Code_Value/(TC_Span_offset- TC_Zero_offset));
   	            TC_Value = Get_B_Slope(Code_Value); 
				if (C_F_Type == 0)	TC_Value = TEMP_F_TO_C(TC_Value);
	          }
           else if (TC_Type == N_TYPE)
              {
			     NP_COD = 1;
//	            Code_Value  = Code_Value*(Code_Value/(TC_Span_offset- TC_Zero_offset));
   	            TC_Value = Get_N_Slope(Code_Value); 
				if (C_F_Type == 0)	TC_Value = TEMP_F_TO_C(TC_Value);
	          }
*/
		  }
	    if (Soft_Timer[RTC_READ_TIME] == 0)
	       {
		         RTC_READ_SET();
 		         Soft_Timer[RTC_READ_TIME] = 8;
		   }
	    if (Soft_Timer[DISPLAY_SEND_TIME] == 0)
	      {
		     Soft_Timer[DISPLAY_SEND_TIME] = 16;	
			   LED_Disp(1,TC_Value);

	   	    if ((TC_Value > alarm_Low_set)&&(TC_Value < alarm_Hi_set))
	          { BEEP_OUT = 1; }
			else
			  { BEEP_OUT = 0; }
		  }
//		  else if (Soft_Timer[DISPLAY_SEND_TIME] == 8)
//	      {
//		     DAY_LED_Disp(use_day,use_hour,use_min);
//		  }
	    if (Soft_Timer[MV_SEND_TIME] == 0)
	     {
		   if( P04 == 0) Set_mV(TC_Value);
		   if( P05 == 0) Set_mA(TC_Value);
		   Soft_Timer[MV_SEND_TIME] = 16;
		 }
	    if (Soft_Timer[UART_SEND_TIME] == 0)
	     {
		  if(tran == 0)
		    {
			SBUF = TC_Value ;
			 tran = 1 ;
			 Soft_Timer[UART_SEND_TIME] = 1;
	       }
	     else
	      { 
	        SBUF = TC_Value >> 8 ;
	        tran = 0;
			Soft_Timer[UART_SEND_TIME] = 59 ;
		  }
	    	TI = 1;
	  }
	}
    return  TC_Value;
}
/***********************************************
RTD=  2	27.6	40	48	56	58
131072					
3200 2600 1950	  950  40
1300 2200  3250	 4100	 5000 5750	6450
7350 7950  8700	 9300  9900	10500	 11150
11700 12300	12850	13400 
*************************************************/
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
		if (Soft_Timer[ADC_READ_TIME] == 0) 
		   {
			 Soft_Timer[ADC_READ_TIME] = 16;

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

 //					   RTD_Value = 0x44e4 ;	// 800.0

				 if(OVER_COD == 1) RTD_Value = 0xffff;
              RTD_Value = Get_RTD_Slope(RTD_Value);
 
	         if (C_F_Type == 0)	RTD_Value = TEMP_F_TO_C(RTD_Value);
	       }
         if (Soft_Timer[DISPLAY_SEND_TIME] == 0)
          {
	           LED_Disp(1,RTD_Value);
	           Soft_Timer[DISPLAY_SEND_TIME] = 16 ;

			 if ((RTD_Value > alarm_Low_set)&&(RTD_Value < alarm_Hi_set))
	          { BEEP_OUT = 1; }
			else
			  { BEEP_OUT = 0; }
		  }
//		 else if (Soft_Timer[DISPLAY_SEND_TIME] == 8)
//	      {
//		     DAY_LED_Disp(use_day,use_hour,use_min);
//		  }
	    if (Soft_Timer[MV_SEND_TIME] == 0)
	      {
		   if( P04 == 0) Set_mV(RTD_Value);
		   if( P05 == 0) Set_mA(RTD_Value);

   		   Soft_Timer[MV_SEND_TIME] = 2;
		  }
	    if (Soft_Timer[RTC_READ_TIME] == 0)
	     {
		   RTC_READ_SET();
		   Soft_Timer[RTC_READ_TIME] = 8 ;
		 }
	    if (Soft_Timer[UART_SEND_TIME] == 0)
	      {
		   if(tran == 0)
		    {
			SBUF = RTD_Value ;
			 tran = 1 ;
			 Soft_Timer[UART_SEND_TIME] = 1;
	       }
	     else
	      { 
	        SBUF = RTD_Value >> 8 ;
	        tran = 0;
			Soft_Timer[UART_SEND_TIME] = 59 ;
		  }
	    	TI = 1;
	   }
    }
   return RTD_Value;
}
/***********************************************

************************************************/
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
		 if (Soft_Timer[ADC_READ_TIME] == 0) 
		  {
		    Soft_Timer[ADC_READ_TIME] = 16;

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

//					mV_Value = 0x7d00 ;
//				  		mV_Value = 0 ;
                 
				mV_Value = mV_Value/3.2;
//     			mV_Value = mV_Value/5.29;
			if(OVER_COD == 1) mV_Value = 0xffff;	 
		 }
	   if (Soft_Timer[DISPLAY_SEND_TIME] == 0)
	     {
		    LED_Disp(1,mV_Value);
		    Soft_Timer[DISPLAY_SEND_TIME] = 8 ;

			 if ((mV_Value > alarm_Low_set)&&(mV_Value < alarm_Hi_set))
	          { BEEP_OUT = 1; }
			else
			  { BEEP_OUT = 0; }
	     }
	   if (Soft_Timer[MV_SEND_TIME] == 0)
	     {
		   if( P04 == 0)  Set_mV(mV_Value);
		   if( P05 == 0)  Set_mA(mV_Value);

		   Soft_Timer[MV_SEND_TIME] = 2;
		 }
	  if (Soft_Timer[RTC_READ_TIME] == 0)
	    {
		  RTC_READ_SET();
		  Soft_Timer[RTC_READ_TIME] = 8 ;
		}
	   if (Soft_Timer[UART_SEND_TIME] == 0)
	     {
		   if(tran == 0)
		    {
			SBUF = mV_Value ;
			 tran = 1 ;
			 Soft_Timer[UART_SEND_TIME] = 1;
	       }
	     else
	      { 
	        SBUF = mV_Value >> 8 ;
	        tran = 0;
			Soft_Timer[UART_SEND_TIME] = 59 ;
		  }
	    	TI = 1;
		 }
	  }
	 return mV_Value ;
}
/***********************************************

*************************************************/
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
		 if (Soft_Timer[ADC_READ_TIME] == 0) 
		   {
			     Soft_Timer[ADC_READ_TIME] = 16;

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
	   if (Soft_Timer[DISPLAY_SEND_TIME] == 0)
	     {
		    LED_Disp(1,mA_Value);
		    Soft_Timer[DISPLAY_SEND_TIME] = 16 ;

			 if ((mA_Value > alarm_Low_set)&&(mA_Value < alarm_Hi_set))
	          { BEEP_OUT = 1; }
			else
			  { BEEP_OUT = 0; }
	     }
	   if (Soft_Timer[MV_SEND_TIME] == 0)
	     {
		   if( P04 == 0)  Set_mV(mA_Value);
		   if( P05 == 0)  Set_mA(mA_Value);

		   Soft_Timer[MV_SEND_TIME] = 2;
		 }
	   if (Soft_Timer[RTC_READ_TIME] == 0)
	    {
		  RTC_READ_SET();
		  Soft_Timer[RTC_READ_TIME] = 8 ;
		}
	   if (Soft_Timer[UART_SEND_TIME] == 0)
	     {
		   if(tran == 0)
		    {
			SBUF = mA_Value ;
			 tran = 1 ;
			 Soft_Timer[UART_SEND_TIME] = 1;
	       }
	     else
	      { 
	        SBUF = mA_Value >> 8 ;
	        tran = 0;
			Soft_Timer[UART_SEND_TIME] = 59 ;
		  }
	    	TI = 1;
		 }
	 }
  return mA_Value;
}
/*************************************************/
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
//		   AV_COD = 0;				//tt
// 		   AD3421_Value = 0x7d00 ;		//tt
	   }
   return AD3421_Value;
}
/*************************************************/	
void DO_SETUP_TYPE(void)
{
	unsigned char set_key = 0, times = 0, Itemm = 0,hin= 0,lon=0; 
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


	                if ((Itemm >= TC_ZERO_CAL)&&(Itemm <= mA_SPAN_CAL))
		             {
					   if (Soft_Timer[ADC_READ_TIME] == 0) 
					     {
						  Soft_Timer[ADC_READ_TIME] = 4 ;
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
		        if (Itemm == MODE_CAL)			//tc,rtd,mV,mA
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
								  EEPROM_write_byte(Mode_Select,Work_Type);
								  SETUP_LED_Disp(22,0);
								  delay(2500);
								  times ++;
								}
					}
				else if (Itemm == C_F_CAL)
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
								   EEPROM_write_byte(C_F_Select,C_F_Type);  //C,F
								   times ++; SETUP_LED_Disp(22,0);delay(2500);
								}
						   }
					}
	   	         else if (Itemm == TYPE_CAL)
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
								   EEPROM_write_byte(Type_Select,TC_Type);  //K,J,T,E,R,B,S,N
								   times ++; SETUP_LED_Disp(22,0);delay(2500);
								 }
						     }
					 }		
				else if (Itemm == TC_ZERO_CAL)
					  {
					   if (Work_Type != 0){	Itemm = Itemm + 1;}
					 else{
						   if( AV_COD == 1){ NG_COD = 1;}else{ NG_COD = 0;}

					   		    SETUP_LED_Disp(Itemm, Data_Value[9]);

							   if(confrom_key == 1)
							    {
								 TC_Zero_offset =  Data_Value[9] ;

								 EEPROM_write_word(TC_Zero,TC_Zero_offset); 
								   delay(50);
								 if( NG_COD == 1){ EEPROM_write_byte(Status_flag,(use_flag|0x01));}
								 else { EEPROM_write_byte(Status_flag,(use_flag&0xfe));}
								 times ++; SETUP_LED_Disp(22,0);delay(2500);
								}
						   }
					   }
	              else if (Itemm == TC_SPAN_CAL)
		              {
					    if (Work_Type != 0) { Itemm = Itemm + 1; }
						else
						 {
							  SETUP_LED_Disp(Itemm,Data_Value[9]);
							  if(confrom_key == 1)
							    {
								 TC_Span_offset = Data_Value[9];

								 EEPROM_write_word(TC_Span,TC_Span_offset);  

								 if( NG_COD == 1)
								   { if ((TC_Span_offset + TC_Zero_offset) > 0xc8ca )
								        { TC_Span_Value = ((TC_Span_offset + TC_Zero_offset)/((TC_Span_offset + TC_Zero_offset)-0xc8ca));
										use_flag = use_flag|0x10;}
									 else
									    { TC_Span_Value = ((TC_Span_offset + TC_Zero_offset)/(0xc8ca - (TC_Span_offset + TC_Zero_offset)));
										use_flag = use_flag&0xef;}
								   }
								 else
								   { if ((TC_Span_offset - TC_Zero_offset) > 0xc8ca )
								        { TC_Span_Value = ((TC_Span_offset - TC_Zero_offset)/((TC_Span_offset - TC_Zero_offset)-0xc8ca));
										 use_flag = use_flag|0x10;}
									 else
									    { TC_Span_Value = ((TC_Span_offset - TC_Zero_offset)/(0xc8ca - (TC_Span_offset - TC_Zero_offset)));
										 use_flag = use_flag&0xef;}
								   }
								    EEPROM_write_word(TC_Span_Per,TC_Span_Value);
									delay(50);
									EEPROM_write_byte(Status_flag,use_flag);
								 times ++; SETUP_LED_Disp(22,0);delay(2500);
						        }
						  }
					   }
	              else if (Itemm == RTD_ZERO_CAL)
		              {
					    if (Work_Type != 1)	{	Itemm = Itemm + 1;}
						else{
							 if( AV_COD == 1){ NG_COD = 1;}else{ NG_COD = 0;}
							  SETUP_LED_Disp(Itemm,Data_Value[9]);
							  if(confrom_key == 1)
							    {
								  RTD_Zero_offset = Data_Value[9] ;
								 EEPROM_write_word(RTD_Zero,RTD_Zero_offset);  //rtd
								  delay(50);
								 if( NG_COD == 1){ EEPROM_write_byte(Status_flag,(use_flag|0x02));}
								 else { EEPROM_write_byte(Status_flag,(use_flag&0xfd));}
								 times ++; SETUP_LED_Disp(22,0);delay(2500);
								}
						    }
					  }
		           else if (Itemm == RTD_SPAN_CAL)
		              {
					    if (Work_Type != 1)	{Itemm = Itemm + 1;}
						else{	 
							  SETUP_LED_Disp(Itemm,Data_Value[9]);
							  if(confrom_key == 1)
							    {
								 RTD_Span_offset = Data_Value[9] ;
								 EEPROM_write_word(RTD_Span,RTD_Span_offset);  //rtd

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
								    EEPROM_write_word(RTD_Span_Per,RTD_Span_Value);
								 times ++;	SETUP_LED_Disp(22,0);delay(2500);
								}
						   }
					 }
		            else if (Itemm == mV_ZERO_CAL)
		               {
					    if (Work_Type != 2)	  {	Itemm = Itemm + 1;}
						else{
							 if( AV_COD == 1){ NG_COD = 1;}else{ NG_COD = 0;}
							  SETUP_LED_Disp(Itemm,Data_Value[9]);
							  if(confrom_key == 1)
							    {
								 mV_Zero_offset = Data_Value[9] ;
								 EEPROM_write_word(mV_Zero,mV_Zero_offset);  
								  delay(50);
								 if( NG_COD == 1){ EEPROM_write_byte(Status_flag,(use_flag|0x04));}
								 else { EEPROM_write_byte(Status_flag,(use_flag&0xfb));}
								 times ++; SETUP_LED_Disp(22,0);	delay(2500);
								}
						   }
					  }
		            else if (Itemm == mV_SPAN_CAL)
		                 {
						   if (Work_Type != 2) {	Itemm = Itemm + 1;}
						  else{	
							  SETUP_LED_Disp(Itemm,Data_Value[9]);
							  if(confrom_key == 1)
							    {
								  mV_Span_offset = Data_Value[9] ;

								 EEPROM_write_word(mV_Span,mV_Span_offset);  

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
								    EEPROM_write_word(mV_Span_Per,mV_Span_Value);
								 times ++;	SETUP_LED_Disp(22,0);delay(2500);
								}
						   }
					 }
		           else if (Itemm == mA_ZERO_CAL)
		               {
					     if (Work_Type != 3)  {	Itemm = Itemm + 1;}
						else{
							  if( AV_COD == 1){ NG_COD = 1;}else{ NG_COD = 0;}
							  SETUP_LED_Disp(Itemm,Data_Value[9]);
							  if(confrom_key == 1)
							    {
                                   delay(50);
								 mA_Zero_offset = Data_Value[9];
								 EEPROM_write_word(mA_Zero,mA_Zero_offset);  
								   delay(50);
								if( NG_COD == 1){ EEPROM_write_byte(Status_flag,(use_flag|0x08));}
								 else { EEPROM_write_byte(Status_flag,(use_flag&0xf7));}
								 times ++; SETUP_LED_Disp(22,0);delay(2500);
								}
						   }
					 }
		            else if (Itemm == mA_SPAN_CAL)
		                {
						  if (Work_Type != 3)  {Itemm = Itemm + 1;}
						else{
							 SETUP_LED_Disp(Itemm,Data_Value[9] );
							  if(confrom_key == 1)
							    {
								 mA_Span_offset = Data_Value[9] ; 
								 EEPROM_write_word(mA_Span,mA_Span_offset);  
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
									 EEPROM_write_word(mA_Span_Per,mA_Span_Value);
								     times ++; SETUP_LED_Disp(22,0);	delay(2500);
								}
						   }
					   }
					 
		           else if (Itemm == ALARM_LO_CAL)
		                 {
                               alarm_Low_set = alarm_Low_set + value_cal*10 ;
									  value_cal = 0;
							  SETUP_LED_Disp(Itemm,alarm_Low_set);
							  if((up_key == 1)||(don_key == 1))
							    {
							     if(alarm_Low_set > 9999){value_cal = 0;alarm_Low_set = 0;}
								 if(confrom_key == 1)
							      {
					                EEPROM_write_word(Alarm_Low,alarm_Low_set);  //alarm
									times ++; SETUP_LED_Disp(22,0);delay(2500);
								  } 
							    }
						}
		             else if (Itemm == ALARM_HI_CAL)
		                { 
							   alarm_Hi_set = alarm_Hi_set + value_cal*10 ;
							    value_cal = 0;
							   SETUP_LED_Disp(Itemm,alarm_Hi_set);
							  if((up_key == 1)||(don_key == 1))
							    {
								  if(alarm_Hi_set > 9999){value_cal = 0;alarm_Hi_set = 0;}

								  if(confrom_key == 1)
							      {
					                EEPROM_write_word(Alarm_Hi,alarm_Hi_set);  //alarm
									times ++; SETUP_LED_Disp(22,0);delay(2500);
								  }
							    }
						}
		             else if (Itemm == YEAR_DATE_CAL)
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
								EEPROM_write_byte(Year_Date,use_year); 
									times ++;SETUP_LED_Disp(22,0);delay(2500);
							   }
						     
					   }
		           else if (Itemm == MON_DATE_CAL)
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
								 EEPROM_write_byte(Mon_Date,use_mon);
								 times ++;  SETUP_LED_Disp(22,0);delay(2500);
							   }
						}
		           else if (Itemm == DAY_DATE_CAL)			//add week setup
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
							 EEPROM_write_byte(Day_Date,use_day);
								 times ++;	SETUP_LED_Disp(22,0);delay(2500);
						   }
					}
		          else if (Itemm == HOUR_DATE_CAL)
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
								EEPROM_write_byte(Hour_Date,use_hour);
								 times ++;	SETUP_LED_Disp(22,0);delay(2500);
							 }
					 }
	               else if (Itemm == MIN_DATE_CAL)
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
								 EEPROM_write_byte(Min_Date,use_min);
								 times ++;SETUP_LED_Disp(22,0); delay(2500);
							}
				      }
				    else if (Itemm >= PRODUCT_RESET)
					   { 
							  Itemm = 0 ;
							  CAIT  = 0 ;
					   }
				 }
		Check_PCB();		 	
}
//*******************************
void RTC_ON(void)
{ 
   use_week = RTC_read_byte(0x03);
   RTC_write_byte(0x07,SQWE);
   RTC_write_byte(0x03,use_week|0x08);	  
                             
    if((use_week&OSC_EN) == OSC_EN) {;}       // if oscillator = already running, do nothing. 
    else
	 { 
       RTC_write_byte(0x06,use_year)   ;     // initialize YEAR  register           
       RTC_write_byte(0x05,use_mon)    ;     // initialize MONTH register  
       RTC_write_byte(0x04,use_day)    ;     // initialize DATE  register  
       RTC_write_byte(0x03,use_week|0x08);
       RTC_write_byte(0x02,use_hour)   ;     // initialize HOUR  register  
       RTC_write_byte(0x01,use_min)    ;     // initialize MIN   register  
       RTC_write_byte(0x00,use_sec|0x80) ;
	 } 
 
}
/************************************************/
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
/*****************************************/
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
   EEPROM_write_byte(Year_Date,use_year);
   EEPROM_write_byte(Mon_Date, use_mon);
   EEPROM_write_byte(Day_Date, use_day);
   EEPROM_write_byte(Week_Date, use_week);
   EEPROM_write_byte(Hour_Date,use_hour);
   EEPROM_write_byte(Min_Date, use_min);
   EEPROM_write_byte(sec_Date, use_sec);
 }
}
//*******************************
void EEPROM_WriteDefault(void)
{
    Check_PCB();
    EEPROM_write_byte(Mode_Select,Work_Type); //setup mode
    EEPROM_write_byte(C_F_Select, 0);  //c
	EEPROM_write_byte(Type_Select,0);  //Type define k=0.j=1,t=2

	EEPROM_write_word(TC_Zero, 0);	
	EEPROM_write_word(TC_Span, 1400);
	EEPROM_write_word(RTD_Zero, 0);
	EEPROM_write_word(RTD_Span, 850);
	EEPROM_write_word(mV_Zero, 0);
	EEPROM_write_word(mV_Span, 5000);
	EEPROM_write_word(mA_Zero, 40);	
    EEPROM_write_word(mA_Span, 200);
	EEPROM_write_word(Alarm_Low, 0);
	EEPROM_write_word(Alarm_Hi, 5000);

    EEPROM_write_byte(Year_Date,0x14);
    EEPROM_write_byte(Mon_Date, 0x01);
    EEPROM_write_byte(Day_Date, 0x01);
	EEPROM_write_byte(Week_Date,0x03);
    EEPROM_write_byte(Hour_Date,0x12);
    EEPROM_write_byte(Min_Date, 0x01);
	EEPROM_write_byte(sec_Date, 0x01);
	EEPROM_write_byte(Status_flag, 0);
	EEPROM_write_word(TC_Span_Per, 1);
	EEPROM_write_word(RTD_Span_Per, 1);
	EEPROM_write_word(mV_Span_Per, 1);
	EEPROM_write_word(mA_Span_Per, 1);
	EEPROM_write_word(EEP_ADR, 60);		//eep start code
    RTC_ON();
}
/*****************************************************/
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

     use_mon =  EEPROM_read_byte(Mon_Date);
     use_day =  EEPROM_read_byte(Day_Date);
	 use_week = EEPROM_read_byte(Week_Date);
     use_hour = EEPROM_read_byte(Hour_Date);
     use_min =  EEPROM_read_byte(Min_Date);
	 use_sec =  EEPROM_read_byte(sec_Date);
	 use_flag =	EEPROM_read_byte(Status_flag);
	 TC_Span_Value = EEPROM_read_word(TC_Span_Per);
	 RTD_Span_Value = EEPROM_read_word(RTD_Span_Per);
	 mV_Span_Value = EEPROM_read_word(mV_Span_Per);
	 mA_Span_Value = EEPROM_read_word(mA_Span_Per);
	 eep_count = EEPROM_read_byte(EEP_ADR);
}
/***********************************
****      System_Start          ****
***********************************/ 
main(void)
{
   TR0 = 0;
   TMOD = TMOD |= 0x01;
   TH0  = 0xDC; //use timer0 to delay 5ms
   TL0  = 0;
   TF0  = 0; 

   IFMT = 0x07 ; //#AUXRA_Rd ;set read AUXRA command
   SCMD = 0x46; //h
   SCMD = 0xB9; //h
   IFD  = IFD |= 0x08; //;
   IFMT = 0x06;  // #AUXRA_Wr ;set write AUXRA command
   SCMD = 0x46; // #46h
   SCMD = 0xB9; //h
   TR0  = 1 ;  //;timer0 run
   while( ~TF0 ) 
      {   }
   TF0 = 0;  //
   TR0  = 0; //;timer0 stop
   IFMT = 0x07 ; //#AUXRA_Rd ;set read AUXRA command
   SCMD = 0x46 ; //h
   SCMD = 0xB9 ; //h
   IFD	= IFD |= 0x03 ;
   IFMT = 0x06; // #AUXRA_Wr ;set write AUXRA command
   SCMD = 0x46; // h
   SCMD = 0xB9; //h
   IFMT = 0x07; //#AUXRA_Rd ;set read AUXRA command
   SCMD = 0x46; //h
   SCMD = 0xB9; //h
   IFD = IFD &= 0xFB; //
   IFMT = 0x06; //, #AUXRA_Wr ;set write AUXRA command
   SCMD = 0x46; //h
   SCMD = 0x0B9; //h

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
	Buzzer(OFF);
	Soft_Timer_Enable = 0;

	if((EEPROM_read_byte(0) != 'N')||(EEPROM_read_byte(1) != 'E')||(EEPROM_read_byte(2) != 'W')||(EEPROM_read_byte(3) != JOHNSON)||(EEPROM_read_byte(4) != LIN))
     {
		EEPROM_write_byte(0, 'N');	
		EEPROM_write_byte(1, 'E');
		EEPROM_write_byte(2, 'W');
		EEPROM_write_byte(3, JOHNSON);	
		EEPROM_write_byte(4, LIN);
		RTC_ON();	
		EEPROM_WriteDefault();
     }
       LED_Fill(); 
	   Work_Type = EEPROM_read_byte(Mode_Select);   	
	   C_F_Type = EEPROM_read_byte(C_F_Select);
 	   TC_Type  = EEPROM_read_byte(Type_Select);       //Type define k=0.j=1,t=2
	   TC_Zero_offset = EEPROM_read_word(TC_Zero);	
	   TC_Span_offset = EEPROM_read_word(TC_Span);
	   RTD_Zero_offset = EEPROM_read_word(RTD_Zero);
	   RTD_Span_offset = EEPROM_read_word(RTD_Span);
	   mV_Zero_offset = EEPROM_read_word(mV_Zero);
	   mV_Span_offset = EEPROM_read_word(mV_Span);

	   mA_Zero_offset = EEPROM_read_word(mA_Zero);	
       mA_Span_offset = EEPROM_read_word(mA_Span);
	   alarm_Low_set = EEPROM_read_word(Alarm_Low);
	   alarm_Hi_set = EEPROM_read_word(Alarm_Hi);
       use_year = EEPROM_read_byte(Year_Date);
       use_mon = EEPROM_read_byte(Mon_Date);
       use_day = EEPROM_read_byte(Day_Date);
       use_hour = EEPROM_read_byte(Hour_Date);
       use_min = EEPROM_read_byte(Min_Date);
	   use_sec = EEPROM_read_byte(sec_Date);
	   use_flag =	EEPROM_read_byte(Status_flag);

	   TC_Span_Value = EEPROM_read_word(TC_Span_Per);
	   RTD_Span_Value = EEPROM_read_word(RTD_Span_Per);
	   mV_Span_Value = EEPROM_read_word(mV_Span_Per);
	   mA_Span_Value = EEPROM_read_word(mA_Span_Per);
	   eep_count = EEPROM_read_byte(EEP_ADR);
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

//***************************************
	while (1)
	{
		switch (Func_Type)
		  {
			case TC_FUNCTION:
	            if(Work_Type == 0)
	              { if(use_flag & 0x10) {ADD_COD = 1;}else{ADD_COD = 0;}}
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
					CAIT = 1 ;
				DO_SETUP_TYPE();
			
				break;

			case CLEAR_FUNCTION:
				DO_RESET_TYPE();
				break;
	       }
	 }
/************************************************ 
#define	K_TYPE		0		1370C /2466F   54.807mV	   57876        P0=0x00
#define	J_TYPE		1		 760C /1368F   42.922mV	   45188
#define	T_TYPE   	2		 200C /360F    9.286mV	   9806
#define	E_TYPE		3		800C  /1440F   61.022mV	   64439
#define	R_TYPE		4		1600C /2880F   18.842mV	   19837
#define	S_TYPE		5		1600C /2880F   16.771mV	   17657
#define	B_TYPE		6		1800C /3240F   13.585mV	   14346
#define	N_TYPE	    7		//?       ?
sbit TC_SW1    = P0^0;	//k=0x00;j=0x01;t=0x02;e=0x03; 
sbit TC_SW2    = P0^1;	//r=0x04;s=0x05;b=0x06;n=0x07;
sbit TC_SW3    = P0^2;
sbit TYPE_SW1  = P0^3;	//tc= 000 00xxx; rtd=000 01xxx; mV=000 10xxx; mA= 000 11xxx;
sbit TYPE_SW2  = P0^4;	 				 18577			32000		  32000
sbit TYPE_SW3  = P0^5;
*/
}