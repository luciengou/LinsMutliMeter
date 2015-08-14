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

//timer out work select
#define	DISPLAY_SEND_TIME  0	 // DISPLAY TIME  
#define	ADC_READ_TIME      1     //	ADC_READ_TIME
#define	RTC_READ_TIME      2     //	RTC_READ_TIME
#define	RTC_SEND_TIME      3     //	RTC_SEND_TIME
#define UART_SEND_TIME     4	 //	UART_SEND_TIME
#define MV_SEND_TIME       5	 // mV_OUT_ TIME
#define	SETUP_TIMEOUT      6	 //	FAIL_TIMEOUT
#define	TIMEUP_TIME        7	 //
#define	TEMP_TIME          8	 //
#define	KEY_TIME           9	 //


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
	           
//EEP Address
#define NOMAL_FUNCTION    0

#define C_F_CAL           6
#define TYPE_CAL          2
#define TC_ZERO_CAL       3
#define TC_SPAN_CAL       4
#define ALARM_LO_CAL      5
#define ALARM_HI_CAL      6
#define YEAR_DATE_CAL     14
#define MON_DATE_CAL      15
#define DAY_DATE_CAL      16
#define HOUR_DATE_CAL     17
#define MIN_DATE_CAL      18
#define PRODUCT_RESET     19

#define  C_F_Select  6
#define  Type_Select 7
#define  Zero        8	  
#define  Span        10
#define  Slope       12
#define  Year_Date   14
#define  Mon_Date    15
#define  Day_Date    16
#define  Hour_Date   17
#define  Min_Date    18
#define  Hi_Disp     20
#define  Lo_Disp     22
#define  Hi_Input    24
#define  Lo_Input    26
#define  Alarm_Hi    28
#define  Relay_HH    30
#define  Relay_LL    32
#define  Alarm_Low   34
#define  Dot_Point   36
#define  Flash_Disp  37
#define  Zero_Code   38
#define  Sample_Rate 40
#define  ID_Code     41
#define  Lo_Mask     42
#define  Count_Code  44
#define  Gain        45
#define  Transfor    46
#define  Disp_Hi     48
#define  Relay       50
#define	 Disp_Count	 51
#define	 Zero_Set    52
#define  Decode_Num  53
#define  Status_flag 54
#define  EEP_ADR     64
//===============================
extern unsigned char key = 0,key_bak = 0,key_d = 0;
extern unsigned char AV_COD ;
extern unsigned char NP_COD ;
unsigned long int value_cal;

idata unsigned char Soft_Timer[10] = {16,16,4,2,59,2,20,30,2,10};
idata unsigned char T0_cnt,T2_cnt , T1_cnt;
idata unsigned char Temp_Flag = 3 ;
idata unsigned char  t_code = 8 ;
idata unsigned char e0 = 0;
idata unsigned int  CRC_CODE;
idata unsigned char CRC_Hi;
idata unsigned char CRC_Lo;
idata unsigned int  Data_Value[15];
idata unsigned int  Show_Data;
unsigned int reg_crc = 0xffff; 
unsigned int  Temp_sp = 0 ;
unsigned int  Temp_offset = 0 ; 
unsigned int  Temp_m = 0 ;  
unsigned int  Disp_year;
unsigned char  use_flag;
unsigned char NG_COD,ADD_COD;
unsigned char OVER_COD = 0 ;
unsigned char MAIN_SW;
unsigned char Work_Type;
unsigned char C_F_Type;
unsigned char TC_Type;
unsigned int  Zero_offset;
unsigned int  Span_offset;
unsigned int  Span_Value ;
unsigned char  use_year ;
unsigned char  use_mon  ;
unsigned char  use_day  ;
unsigned char  use_week ;
unsigned char  use_hour ;
unsigned char  use_min  ;
unsigned char  use_sec  ;
idata unsigned int   Hi_Disp_Code;
idata unsigned int   Lo_Disp_Code;
idata unsigned int   Hi_Input_Code;
idata unsigned int   Lo_Input_Code;
idata unsigned int  alarm_Hi_set;
idata unsigned int  alarm_HH_set;
idata unsigned int  alarm_LL_set;
idata unsigned int  alarm_Low_set;
idata unsigned char Flash_Time;
idata unsigned int  Zero_Add;
idata unsigned char Uart_Rate;
idata unsigned char Uart_ID;
idata unsigned int  Low_Limit;
idata unsigned char Disp_Neg;
idata unsigned char Disp_Gain;
idata unsigned char Uart_tran;
idata unsigned int  Hi_Limit;
idata unsigned char Relay_ON_OFF;
extern unsigned char Dot_Addr;
extern unsigned char Disp_Bits;
extern unsigned char Disp_Show;
idata unsigned char Decode_Bit;
unsigned char  n_code = 0 ;
unsigned char CAIT = 0x01;
unsigned char Func_Type;
unsigned char AD_Hi;
unsigned char AD_Mid;
unsigned char AD_Lo;
unsigned char AD_Status;
unsigned char PCB_SETUP;
unsigned char Soft_Timer_Enable = 0;
unsigned char ReceiveDate[10];

bit f_half_sec;
bit ReceiveFlag = 0;
unsigned char tran = 0 ;
bit Zero_f = 0 ;
/***************************************
	   Port In/Out Setting
*****************************************/
void PORT_Init(void)
{
	P0M0 = 0xFF;	  //00=Qb,01=pull output, 10= input only,11=open drain
 	P0M1 = 0x00;	 //P0= ALL INPUT  00
	P0   = 0xff;

	P1M0 = 0x00;	 //P1= ALL OUTPUT//00
	P1M1 = 0xFF;     //SETUP P1 ALL LO //  define P1.3 P1.4 P1.5 as push-pull
    P1   = 0x00;
    
	P2M0 = 0x24;	 //P2= ALL OUTOUT	 04 
	P2M1 |= 0xFF; 	 //SETUP P2 ALL LO	 df
	P2  =  P2|0x20;

    P3M0 = 0xED;	 //	ed  
	P3M1 = 0x13;	// 13
	P3   = 0x2C;	// 2c
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
		if (Soft_Timer[TEMP_TIME] != 0)		    Soft_Timer[TEMP_TIME]--;
		if (Soft_Timer[KEY_TIME] != 0)		    Soft_Timer[KEY_TIME]--;
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
  if(Uart_Rate == 0)
    { TH2=0xFE;                    /* init value */
      TL2=0x80;                    /* init value */
      RCAP2H=0xFE;                 /* reload value, 1200 Bds at 11.059MHz */
      RCAP2L=0x80;                 /* reload value, 1200 Bds at 11.059MHz */
	}
   else if(Uart_Rate == 1)
	{ TH2=0xFF;                    /* init value */
      TL2=0x70;                    /* init value */
      RCAP2H=0xFF;                 /* reload value, 2400 Bds at 11.059MHz */
      RCAP2L=0x70;                 /* reload value, 2400 Bds at 11.059MHz */
	}
   else if(Uart_Rate == 2)
	{ TH2=0xFF;                    /* init value */
      TL2=0xA0;                    /* init value */
      RCAP2H=0xFF;                 /* reload value, 4800 Bds at 11.059MHz */
      RCAP2L=0xA0;                 /* reload value, 4800 Bds at 11.059MHz */
	}
   else if(Uart_Rate == 3)
	{ TH2=0xFF;                    /* init value */
      TL2=0xD0;                    /* init value */
      RCAP2H=0xFF;                 /* reload value, 9600 Bds at 11.059MHz */
      RCAP2L=0xDC;                 /* reload value, 9600 Bds at 11.059MHz */
	}
   else if(Uart_Rate == 4)
	{ TH2=0xFF;                    /* init value */
      TL2=0xEE;                    /* init value */
      RCAP2H=0xFF;                 /* reload value, 19200 Bds at 11.059MHz */
      RCAP2L=0xEE;                 /* reload value, 19200 Bds at 11.059MHz */
	}								 
	ES = 1; 					 /* Enable serial interrupt */
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
	   ReceiveDate[tran] = SBUF;
	   tran++;
	   ReceiveFlag = 1;
	 }
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
      P3 = 	P3 |= 0x10;
	else
	  P3 = P3 &= ~0x10;
}
/*******************************************
      CHECK PCB TYPE
*******************************************/
void Check_PCB(void)
{
  	   if(P00 == 0)                 //tc
	     {
		     Work_Type = 0x00;
			 Func_Type = 0x00;
			 PCB_SETUP = 0x01;
		     if(P04 == 0)	        //mV_out
		       {PCB_SETUP = 0x11 ;}
  	         if(P05 == 0)	        //mA_out
		       {PCB_SETUP = 0x21 ;}
			 if(use_flag == 0x01) { NG_COD = 1;}
		 }
	   else if(P01 == 0)	        //rtd
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
	  else if(P02 == 0)	           //mV
		 {
			 Work_Type = 0x02 ;
			 Func_Type = 0x02;
			  PCB_SETUP = 0x04 ;
			  if(P04 == 0)	       //mV_out
		        {PCB_SETUP = 0x14 ;}
		      if(P05 == 0)	       //mA_out
		        {PCB_SETUP = 0x24 ;}
			   if(use_flag == 0x04) { NG_COD = 1;}
		 } 
	  else if(P03 == 0)	           //mA
		 { 
		     Work_Type = 0x03 ;
			 Func_Type = 0x03;
			   PCB_SETUP = 0x08 ;
			 if(P04 == 0)	        //mV_out
		       {PCB_SETUP = 0x18 ;}
		     if(P05 == 0)	        //mA_out
		       {PCB_SETUP = 0x28 ;}
			 if(use_flag == 0x08) { NG_COD = 1;}  
		 }
}
/***********************************************/
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
/**********************************************/
void Volt_Ctrl(void)
{
}
/*********************************
/***************   27763,58716**************/
unsigned int Temp_Read(void)
{
unsigned int Temp_Count,P_count;
             TEMP = 1;
		  P_count = 0;
		  delay(1);
		while(TEMP)
		   {  P_count = P_count + 1 ;}	  
		    TEMP = 0 ;
				P_count = 0x7d00 - P_count ;					 
		     if((P_count < 2329)||(P_count > 0x4fff)){Temp_Count = 0;}		
		   	 else{ Temp_Count = (P_count-2329)/36 ; 
			 	   if(Temp_Count > 181)
			        { Temp_Count = Temp_Count+(Temp_Count-178)/2 ;
				      if(Temp_Count > 252)
			            { Temp_Count = Temp_Count+(Temp_Count-250)/6 ;
				          if(Temp_Count > 341)
			                { Temp_Count = Temp_Count+(Temp_Count-340)/5 ;
				              if(Temp_Count > 430)			  //1212
			                     { Temp_Count = Temp_Count+(Temp_Count-430)/3 ;
				                  if(Temp_Count > 500)
			                         { Temp_Count = Temp_Count+(Temp_Count-500)/4;
				                      if(Temp_Count > 590)
			                            { Temp_Count = Temp_Count+(Temp_Count-590)/8;
				                         if(Temp_Count > 700)
			                                { Temp_Count = Temp_Count+(Temp_Count-690)/5;
				                              if(Temp_Count > 760)
			                                    { Temp_Count = Temp_Count+(Temp_Count- 760)/5;
				                                 if(Temp_Count > 840)
			                                       { Temp_Count = Temp_Count+(Temp_Count-840)/3;
				                                    if(Temp_Count > 912)
			                                          { Temp_Count = Temp_Count+(Temp_Count-910)/6;
				                                       if(Temp_Count > 1010)
			                                             { Temp_Count = Temp_Count+(Temp_Count-1005)/7;
				                                          if(Temp_Count > 1095)
			                                                { Temp_Count = Temp_Count+(Temp_Count-1094)/9; //?
															if(Temp_Count > 1180)
			                                                  { Temp_Count = Temp_Count+(Temp_Count-1180)/6;
				                                               if(Temp_Count > 1240)
			                                                     { Temp_Count = Temp_Count+(Temp_Count-1230)/4;
				                                                 if(Temp_Count > 1276)
			                                                       { Temp_Count = Temp_Count+(Temp_Count-1270)/4 ;
				                                                    if(Temp_Count > 1420)
			                                                          { Temp_Count = Temp_Count+(Temp_Count-1410)/5;
				                                                       if(Temp_Count > 1528)
			                                                             { Temp_Count = Temp_Count+(Temp_Count-1520)/5;
				                                                         if(Temp_Count > 1619)
			                                                                { Temp_Count = Temp_Count+(Temp_Count-1610)/4;
				                                                             if(Temp_Count > 1726)
			                                                                    { Temp_Count = Temp_Count+(Temp_Count-1720)/16;
																				}}}}}}}}}} }}}}}}}}	}
	    }
    return(Temp_Count);
}
/*																			  
unsigned int Temp_Read(void)
{
unsigned int P_count;
	 	  P_count = 37800; //60418; //7a00;		 //ec00
            TEMP = 1;
		  delay(1);
		while(TEMP)
		   { P_count--;}	
		    TEMP = 0 ;	
		     if(P_count > 32000){P_count = 0;} 
//				P_count = P_count/122 ;	  //27736
 		     if(P_count < 20500)
				 {    P_count = P_count/12 ;
					  P_count = P_count/(7-P_count/530);	
				 }	 
		   else if(P_count < 27200)		//26700			
			     {  P_count = P_count/10 ;
					   P_count = P_count/(9 -P_count/453);	
				 }
			else if(P_count < 29370)					
			     { P_count = P_count/9 ;
					  P_count = P_count/(12 -P_count/347);	
				 }
			else if(P_count < 30370)					
			     { P_count = P_count/8 ;
					   P_count = P_count/(16 -P_count/281);	
				 }
		   else if(P_count < 31000)					
			     { P_count = P_count/8 ;
					   P_count = P_count/(19 -P_count/230);	
				 }
			Temp_m =  P_count;
//		    Temp_m = ( P_count*5)/9;
    return(Temp_m);
}
/**********************************************
   M_BUS SYSYEM
**********************************************/
unsigned int CRC_CHECK(void)
{
	  unsigned char i=0, j;
		   tran = 6;
      if(tran)
        {
             reg_crc ^= ReceiveDate[i];
                      i ++;
             for (j = 0; j < 8; j++)
                {
                  if (reg_crc & 0x01)
                     reg_crc = (reg_crc >> 1) ^ 0xA001;
                 else
                     reg_crc = reg_crc >> 1;
                }
			   tran--;
        }
      return(reg_crc);
}
/************************************************/
unsigned char Get_Key(void)
{
   if(PRO_KEY == 1 && SHIFT_KEY == 1 && COUNT_KEY == 1 && SAVE_KEY == 1) 
     {
	    if(key_d == 1)
		  {key = 0x81 ;
		   key_d = 0;}
		else
		  {
	        key &= 0x80;
	        key_bak = 0;
	        Soft_Timer[KEY_TIME] = 3;
		  }
 	 }
    else
	 {
       if(PRO_KEY == 0)
         {																		  
		  if(key == 0)
	        {
	          if(Soft_Timer[KEY_TIME] == 0)

	               {
	                 key = 0xc0 ;
	                 key_bak = 1;
		             Soft_Timer[KEY_TIME] = 3;
	               }
	        }
	  	  else
		    {
	         if(key ==0x80)
	           {
			    if(key_bak == 1)
		          {if(Soft_Timer[KEY_TIME] == 0)
	                {
	                  key = 0x60 ;
	                  key_bak = 1;
					  key_d = 0 ;
		              Soft_Timer[KEY_TIME] = 3;
	                }
	              }
		        else
		          {
			        key_d = 1;
	                key_bak = 1;
	              }
	           }
	       }
	 }
   else if(SHIFT_KEY == 0)
     {
        if(key_bak == 0)

		  { if(key == 0x80)
              {
	           key = 0x82 ;
	           key_bak = 1; 
	          }
          }
		 else{key = 0x80;}
	 }
   else if(COUNT_KEY == 0)
     {
	      if(key_bak == 0)
	        {
		      if( key == 0x80 )
               {
	            key =  0x84;
	            key_bak = 1; 
	          }
	        }
		   else{key = 0x80;}
	 }
    else if(SAVE_KEY == 0)		 //SET ADC
     {
	    if(key_bak == 0)
	        {
		      if( key == 0x80 )
               {
	            key =  0x88;
	            key_bak = 1; 
	           }
		    else if( key == 0)
		       {
	             if(Soft_Timer[KEY_TIME] == 0)
	               {
	                 key = 0x10 ;
	                 key_bak = 1;
		             Soft_Timer[KEY_TIME] = 3;
	               }
			   }
		   }
	   }
   }
   return key;
}
/*******************************

********************************/
unsigned  int DO_TC_TYPE(void)
{
    unsigned int Code_Value,TC_Value,TT_Value,TA_Value ;
	 unsigned char key;

      key = Get_Key();

	  if(key == 0xc0)
	  {
	     Func_Type = 4;
	  }
	  if(key == 0x10)
	  {
	     Func_Type = 4;
	  }
   else
     { 
	  if(Temp_Flag != 0 ){Temp_m = Data_Value[n_code];}
      if (Soft_Timer[TEMP_TIME] == 0)
       	{
		  Soft_Timer[TEMP_TIME] = 4;
	      Data_Value[n_code] = Temp_Read() ;
	       if(n_code < 4){n_code++;}
	      else{ Temp_m = (Data_Value[3]/4+Data_Value[2]/4+Data_Value[1]/4+Data_Value[0]/4) ; //4
				  n_code = 0 ;
			     if(Temp_Flag != 0){Temp_Flag-- ;} }
		}
		if (Soft_Timer[ADC_READ_TIME] == 0) 
		  {
		      Soft_Timer[ADC_READ_TIME] = 16;
 			 Data_Value[t_code] = Read_AD3421_Value();

			 if(t_code < 13)
			    {t_code++; Code_Value = Data_Value[13];}
			 else{ Data_Value[13] = (Data_Value[12]/5+Data_Value[11]/5+Data_Value[10]/5+Data_Value[9]/5+Data_Value[8]/5) ;
				  t_code = 8;}


	  	    if (TC_Type == K_TYPE)
              { 
			    Temp_sp =  (Temp_m*13)/10;	  //24ok
			    TT_Value = Check_Type_Offset(Code_Value); 
			    TC_Value = Get_K_Slope(TT_Value);
				TT_Value = TC_Value/7.5 ;
				TA_Value = (TC_Value/38+163) ;
	          }
            else if (TC_Type == J_TYPE)
              {	
			    Temp_sp = (Temp_m*28)/10;	 //30 ok  20
			    TT_Value = Check_Type_Offset(Code_Value);
				TC_Value = Get_J_Slope(TT_Value);
			    TT_Value = TC_Value/7.5 ;
			    TA_Value = (TC_Value/21.4+163) ;
	          }
            else if (TC_Type == T_TYPE)
              {
			    Temp_sp = (Temp_m*12)/10;	  //231.044
			    TT_Value = Check_Type_Offset(Code_Value);
			    TC_Value = Get_T_Slope(TT_Value);
		        TT_Value = TC_Value/7.5 ;
				TA_Value = (TC_Value/6+163) ;
	          }
            else if (TC_Type == E_TYPE)
              {	
			    Temp_sp = (Temp_m*40)/10;   //35 1.54 /0k 14
		        TT_Value = Check_Type_Offset(Code_Value);
			    TC_Value = Get_E_Slope(TT_Value);
			    TT_Value = TC_Value/7.5 ;
			    TA_Value = (TC_Value/22.5+163) ;
	          }
            else if (TC_Type == R_TYPE)
             { 	NP_COD = 1;
			    Temp_sp = Temp_m/6; //Temp_offset/12;3
				TT_Value = Check_Type_Offset(Code_Value);
			    TC_Value = Get_R_Slope(TT_Value);
			    TT_Value = TC_Value/7.5 ;
			    TA_Value = (TC_Value/44.5+163) ;
	          }
            else if (TC_Type == S_TYPE)
              {	   NP_COD = 1;
			     Temp_sp = Temp_m/6; //Temp_offset/12;3
				 TT_Value = Check_Type_Offset(Code_Value);
				 TC_Value = Get_S_Slope(TT_Value);
			     TT_Value = TC_Value/7.5 ;
				 TA_Value = (TC_Value/44.5+163) ;
	          }
		    if (C_F_Type == 0) 	TC_Value = TEMP_F_TO_C(TC_Value);
		  }
	    if (Soft_Timer[RTC_READ_TIME] == 0)
	       {
		         RTC_READ_SET();
 		         Soft_Timer[RTC_READ_TIME] = 8;
		   }

	    if (Soft_Timer[DISPLAY_SEND_TIME] == 0)
	      {	 TC_Value = TC_Value - Zero_Add	;
		    if(Disp_Gain > 1){TC_Value = TC_Value * Disp_Gain;}

			 if(TC_Value > Hi_Limit){TC_Value = Hi_Limit;}
			 if(TC_Value < Low_Limit){TC_Value = Low_Limit;}
			 if(TC_Value > Hi_Input_Code){TC_Value = Hi_Input_Code;}
			 if(TC_Value < Lo_Input_Code){TC_Value = Lo_Input_Code;}
			 if(TC_Value > Hi_Disp_Code){TC_Value = Hi_Disp_Code;}
			 if(TC_Value < Lo_Disp_Code){TC_Value = Lo_Disp_Code;}

			  Soft_Timer[DISPLAY_SEND_TIME] = Flash_Time;
			   if(Disp_Show == 0 ){LED_Disp(1,TC_Value);}		 
			   else {LED_Disp(Dot_Addr,TC_Value);}
			 if(Relay_ON_OFF == 1)
			 {
	   	       if ((TC_Value < alarm_LL_set)||(TC_Value > alarm_HH_set))
	              { BEEP_OUT = 0; }
			 }
			else
			 {
			  if ((TC_Value > alarm_Low_set)||(TC_Value < alarm_Hi_set))
			     { BEEP_OUT = 1; }
			 }
		  }
	    if (Soft_Timer[MV_SEND_TIME] == 0)
		  {
		   if( P04 == 0) Set_mV(TT_Value);
		   if( P05 == 0) Set_mA(TA_Value);

		   Soft_Timer[MV_SEND_TIME] = 16;
		 }
	    if (Soft_Timer[UART_SEND_TIME] == 0)
	     {
	       if(Uart_tran > 1)
		    {
			 ReceiveDate[0] = Uart_tran;
			 ReceiveDate[1] = 0x06;
			 ReceiveDate[2] = 0;
			 ReceiveDate[3] = Uart_ID;
			 ReceiveDate[4] = TC_Value;
			 ReceiveDate[5] = TC_Value >> 8;
			 CRC_CODE = CRC_CHECK();
			 CRC_Lo = CRC_CODE ;
			 CRC_Hi = CRC_CODE	>> 8 ;
			 ReceiveDate[6] = CRC_Lo;
			 ReceiveDate[7] = CRC_Hi;

			 if(tran == 0)
		      {
			    SBUF = Uart_ID ;
			    tran = 1 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
			else if(tran == 1)
		      {
			    SBUF = 0x06 ;
			    tran = 2 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
			else if(tran == 2)
		      {
			    SBUF = 0 ;
			    tran = 3 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
			else if(tran == 3)
		      {
			    SBUF = Uart_ID ;
			    tran = 4 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
		    else if(tran == 4)
		      {
			    SBUF = TC_Value ;
			    tran = 5 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }  
			else if(tran == 5)
		      {
			    SBUF = TC_Value >> 8 ;
			    tran = 6 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
			else if(tran == 6)
		      {
			    SBUF = CRC_Lo ;
			    tran = 7 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
	        else if(tran == 7)
	          { 
	            SBUF = CRC_Hi;
	            tran = 0;
			    Soft_Timer[UART_SEND_TIME] = 59 ;
		      }
    	     TI = 1;
	       }
		   else{ Soft_Timer[UART_SEND_TIME] = 59 ;}
		 }
	 }
    return  TC_Value;
}
/*************************************************************************************/
unsigned int Check_Type_Offset(unsigned int Code_Value)
{
    unsigned int Count_Value;
     if (NG_COD == 0)
       {
	    if (AV_COD == 0)
		  {
		   if(Code_Value >= Zero_offset)	   
		     {
	            Count_Value = (Code_Value - Zero_offset) + Temp_sp ;
		     }
		   else	  
	         {
			    if((Temp_sp + Code_Value) >= Zero_offset)
		          { Code_Value = (Code_Value + Temp_sp) - Zero_offset ;}
                else	 
			      { Code_Value = ( Zero_offset - Code_Value) + Temp_sp; AV_COD = 1;}
			 }
		   }
		else   //AV_COD == 1
	       {
			 if(( Code_Value +  Zero_offset ) >= Temp_sp)
			   { Count_Value = (Code_Value + Zero_offset) - Temp_sp ;}
			 else
			   { Count_Value = (Temp_sp - Code_Value) - Zero_offset;
			     AV_COD = 0 ;} 
		   }														 
		}
       else
	    {
	     if(AV_COD == 0)  // AV_COD = 0	 NG_COD = 1
		   {
		      Count_Value = Code_Value + Zero_offset + Temp_sp;
		   }
          else	  // AV_COD = 1	 NG_COD = 1
	       {
		     if( Code_Value >= Zero_offset ) 
			   {
			    if((Temp_sp + Zero_offset ) >= Code_Value)
				  {
				     Count_Value = (Temp_sp + Zero_offset ) - Code_Value; AV_COD = 0;
				  }
				 else
			      { Count_Value = Code_Value - (Temp_sp + Zero_offset);} 
			   }
			 else
			   {
				 if(( Zero_offset - Code_Value ) >= Temp_sp  )
				   {
					 Count_Value = Zero_offset - (Temp_sp + Code_Value); AV_COD = 0;
				   } 
				 else
				   { Count_Value = (Zero_offset - Code_Value) + Temp_sp  ;  AV_COD = 0;}

			   }														   
		   }
	   }

   if(ADD_COD == 1 ) 
	 { Count_Value = Count_Value - (Count_Value/Span_Value); }	  //TC_Span_Value
   else
	 { Count_Value = Count_Value + (Count_Value/Span_Value);}
	   
	if(OVER_COD == 1){ Count_Value = 0xffff;}

  return Count_Value;
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
	 
	  if(key == 0xc0)
	  {
	     Func_Type =  4;
	  }
	 if(key == 0x10)
	  {
	     Func_Type = 4;
	  }
	else
	  {
	    if (Soft_Timer[ADC_READ_TIME] == 0) 
		  {
			 Soft_Timer[ADC_READ_TIME] = 16;

			  RTD_Value = Read_AD3421_Value();

			 if((NG_COD == 1)&&(AV_COD == 1))
			   {
					  if( RTD_Value >= Zero_offset)
					    {
					     RTD_Value = RTD_Value - Zero_offset;
						}
					   else
					    {
						 RTD_Value = Zero_offset -RTD_Value;
						 AV_COD = 0;
						}
				}
			  else if((NG_COD == 1)&&(AV_COD == 0))
			    {
					     RTD_Value = RTD_Value + Zero_offset;
			    } 			
			  else if((NG_COD == 0)&&(AV_COD == 1))
			    {
					     RTD_Value = RTD_Value + Zero_offset;
			    }   
			  else if((NG_COD == 0)&&(AV_COD == 0))
			    {
				       if( RTD_Value >= Zero_offset)
					    {
					     RTD_Value = RTD_Value - Zero_offset;
						}
					   else
					    {
						 RTD_Value = Zero_offset -RTD_Value;
					     AV_COD = 1 ;
						}
				}
				   if(Span_offset > 0x44e4)
					 {  RTD_Value = RTD_Value +(RTD_Value/Span_Value);}
				  else
					 {  RTD_Value = RTD_Value - (RTD_Value/Span_Value);}
				 if(OVER_COD == 1) RTD_Value = 0xffff;
              RTD_Value = Get_RTD_Slope(RTD_Value);
 
	         if (C_F_Type == 0)	RTD_Value = TEMP_F_TO_C(RTD_Value);
	       }
         if (Soft_Timer[DISPLAY_SEND_TIME] == 0)
           {	 
		     RTD_Value = RTD_Value - Zero_Add ;
			 if(Disp_Gain > 1){RTD_Value = RTD_Value * Disp_Gain;}
			 if(RTD_Value > Hi_Limit){RTD_Value = Hi_Limit;}
			 if(RTD_Value < Low_Limit){RTD_Value = Low_Limit;}
			 if(RTD_Value > Hi_Input_Code){RTD_Value = Hi_Input_Code;}
			 if(RTD_Value < Lo_Input_Code){RTD_Value = Lo_Input_Code;}
		     if(RTD_Value > Hi_Disp_Code){RTD_Value = Hi_Disp_Code;}
			 if(RTD_Value < Lo_Disp_Code){RTD_Value = Lo_Disp_Code;}
			 if(Disp_Show == 0 ){LED_Disp(1,RTD_Value);}		 
			 else {LED_Disp(Dot_Addr,RTD_Value);}
	           Soft_Timer[DISPLAY_SEND_TIME] = Flash_Time ;	

		    if(Relay_ON_OFF == 1)
			 {
	   	       if ((RTD_Value  < alarm_LL_set)||(RTD_Value  > alarm_HH_set))
	              { BEEP_OUT = 0; }
			 }
			else
			 {
			  if ((RTD_Value  > alarm_Low_set)||(RTD_Value  < alarm_Hi_set))
			     { BEEP_OUT = 1; }
		     }
		  }
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
		 if(Uart_tran > 1)
		    {
			 ReceiveDate[0] = Uart_tran;
			 ReceiveDate[1] = 0x06;
			 ReceiveDate[2] = 0;
			 ReceiveDate[3] = Uart_ID;
			 ReceiveDate[4] = RTD_Value;
			 ReceiveDate[5] = RTD_Value >> 8;
			 CRC_CODE = CRC_CHECK();
			 CRC_Lo = CRC_CODE ;
			 CRC_Hi = CRC_CODE	>> 8 ;
			 ReceiveDate[6] = CRC_Lo;
			 ReceiveDate[7] = CRC_Hi;

			 if(tran == 0)
		      {
			    SBUF = Uart_ID ;
			    tran = 1 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
			else if(tran == 1)
		      {
			    SBUF = 0x06 ;
			    tran = 2 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
			else if(tran == 2)
		      {
			    SBUF = 0 ;
			    tran = 3 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
			else if(tran == 3)
		      {
			    SBUF = Uart_ID ;
			    tran = 4 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
		    else if(tran == 4)
		      {
			    SBUF = RTD_Value ;
			    tran = 5 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }  
			else if(tran == 5)
		      {
			    SBUF = RTD_Value >> 8 ;
			    tran = 6 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
			else if(tran == 6)
		      {
			    SBUF = CRC_Lo ;
			    tran = 7 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
	        else if(tran == 7)
	          { 
	            SBUF = CRC_Hi;
	            tran = 0;
			    Soft_Timer[UART_SEND_TIME] = 59 ;
		      }
    	     TI = 1;
	       }
		   else{ Soft_Timer[UART_SEND_TIME] = 59 ;}
		 
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
	 
	  if(key == 0xc0)
	    {
	      Func_Type = 4;
	    }
	  if(key == 0x10)
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
					  if( mV_Value > Zero_offset)		
					    {
					     mV_Value = mV_Value - Zero_offset;
						}
					   else
					    {
						 mV_Value = Zero_offset -mV_Value;
						 AV_COD = 0;
						}
				}
			  else if((NG_COD == 1)&&(AV_COD == 0))
			    {
					     mV_Value = mV_Value + Zero_offset;
			    } 			
			  else if((NG_COD == 0)&&(AV_COD == 1))
			    {
					     mV_Value = mV_Value + Zero_offset;
			    }   
			  else if((NG_COD == 0)&&(AV_COD == 0))
			    {
				       if( mV_Value >= Zero_offset)
					    {
					     mV_Value = mV_Value - Zero_offset;
						}
					   else
					    {
						 mV_Value = Zero_offset -mV_Value;
					     AV_COD = 1 ;
						}
				}
				   if(Span_offset > 0x0c80)
					 { mV_Value = mV_Value + (mV_Value/Span_Value); }
				  else
					 { mV_Value = mV_Value - (mV_Value/Span_Value); }

			       mV_Value = mV_Value/3.2;
			if(OVER_COD == 1) mV_Value = 0xffff;	 
		 }
	   if (Soft_Timer[DISPLAY_SEND_TIME] == 0)
	     {	
		 	mV_Value = mV_Value - Zero_Add ;
		    if(Disp_Gain > 1){mV_Value = mV_Value * Disp_Gain;}
		  	if(mV_Value > Hi_Limit){mV_Value = Hi_Limit;}
			if(mV_Value < Low_Limit){mV_Value = Low_Limit;}
		    if(mV_Value > Hi_Input_Code){mV_Value = Hi_Input_Code;}
			if(mV_Value < Lo_Input_Code){mV_Value = Lo_Input_Code;}
		    if(mV_Value > Hi_Disp_Code){mV_Value = Hi_Disp_Code;}
			if(mV_Value < Lo_Disp_Code){mV_Value = Lo_Disp_Code;}
			 if(Disp_Show == 0){LED_Disp(1,mV_Value);}		 
			 else {LED_Disp(Dot_Addr,mV_Value);}
		    Soft_Timer[DISPLAY_SEND_TIME] = Flash_Time ;

		    if(Relay_ON_OFF == 1)
			 {
	   	       if ((mV_Value  < alarm_LL_set)||(mV_Value  > alarm_HH_set))
	              { BEEP_OUT = 0; }
			 }
			else
			 {
			  if ((mV_Value > alarm_Low_set)||(mV_Value  < alarm_Hi_set))
			     { BEEP_OUT = 1; }
		     }
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
		  if(Uart_tran > 1)
		    {
			 ReceiveDate[0] = Uart_tran;
			 ReceiveDate[1] = 0x06;
			 ReceiveDate[2] = 0;
			 ReceiveDate[3] = Uart_ID;
			 ReceiveDate[4] = mV_Value;
			 ReceiveDate[5] = mV_Value >> 8;
			 CRC_CODE = CRC_CHECK();
			 CRC_Lo = CRC_CODE ;
			 CRC_Hi = CRC_CODE	>> 8 ;
			 ReceiveDate[6] = CRC_Lo;
			 ReceiveDate[7] = CRC_Hi;

			 if(tran == 0)
		      {
			    SBUF = Uart_ID ;
			    tran = 1 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
			else if(tran == 1)
		      {
			    SBUF = 0x06 ;
			    tran = 2 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
			else if(tran == 2)
		      {
			    SBUF = 0 ;
			    tran = 3 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
			else if(tran == 3)
		      {
			    SBUF = Uart_ID ;
			    tran = 4 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
		    else if(tran == 4)
		      {
			    SBUF = mV_Value ;
			    tran = 5 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }  
			else if(tran == 5)
		      {
			    SBUF = mV_Value >> 8 ;
			    tran = 6 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
			else if(tran == 6)
		      {
			    SBUF = CRC_Lo ;
			    tran = 7 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
	        else if(tran == 7)
	          { 
	            SBUF = CRC_Hi;
	            tran = 0;
			    Soft_Timer[UART_SEND_TIME] = 59 ;
		      }
    	     TI = 1;
	       }
		   else{ Soft_Timer[UART_SEND_TIME] = 59 ;}
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
	 
	  if(key == 0xc0)
	    {
	      Func_Type = 4 ;
	    }
		if(key == 0x10)
	  {
	     Func_Type = 4;
	  }
  	  else 
	    {
		 if (Soft_Timer[ADC_READ_TIME] == 0) 
		   {
			     Soft_Timer[ADC_READ_TIME] = 16;

				 mA_Value = Read_AD3421_Value();

			 if((NG_COD == 1)&&(AV_COD == 1))
			   {
					  if( mA_Value >= Zero_offset)
					    {
					     mA_Value = mA_Value - Zero_offset;
						}
					   else
					    {
						 mA_Value = Zero_offset -mA_Value;
						 AV_COD = 0;
						}
				}
			  else if((NG_COD == 1)&&(AV_COD == 0))
			    {
					     mA_Value = mA_Value + Zero_offset;
			    } 			
			  else if((NG_COD == 0)&&(AV_COD == 1))
			    {
					     mA_Value = mA_Value + Zero_offset;
			    }   
			  else if((NG_COD == 0)&&(AV_COD == 0))
			    {
				       if( mA_Value >= Zero_offset)
					    {
					     mA_Value = mA_Value - Zero_offset;
						}
					   else
					    {
						 mA_Value = Zero_offset -mA_Value;
					     AV_COD = 1 ;
						}
				}
				   if(Span_offset >  0x1900)
					 { mA_Value = mA_Value + (mA_Value/Span_Value); }
				  else
					 { mA_Value = mA_Value - (mA_Value/Span_Value); }

				 mA_Value = mA_Value/3.2 ;

				 if(OVER_COD == 1) mA_Value = 0xffff;
		  }
	   if (Soft_Timer[DISPLAY_SEND_TIME] == 0)
	     { 	 
		     mA_Value = mA_Value - Zero_Add;
			 if(Disp_Gain > 1){mA_Value = mA_Value * Disp_Gain;}
		     if(mA_Value > Hi_Limit){mA_Value = Hi_Limit;}
			 if(mA_Value < Low_Limit){mA_Value = Low_Limit;}
			 if(mA_Value > Hi_Input_Code){mA_Value = Hi_Input_Code;}
			 if(mA_Value < Lo_Input_Code){mA_Value = Lo_Input_Code;}
		     if(mA_Value > Hi_Disp_Code){mA_Value = Hi_Disp_Code;}
			 if(mA_Value < Lo_Disp_Code){mA_Value = Lo_Disp_Code;}
			  if(Disp_Show == 0 ){LED_Disp(2,mA_Value);}		 
			 else {LED_Disp(Dot_Addr,mA_Value);}
		    Soft_Timer[DISPLAY_SEND_TIME] = Flash_Time ;

		    if(Relay_ON_OFF == 1)
			 {
	   	       if ((mA_Value  < alarm_LL_set)||(mA_Value  > alarm_HH_set))
	              { BEEP_OUT = 0; }
			 }
			else
			 {
			  if ((mA_Value > alarm_Low_set)||(mA_Value  < alarm_Hi_set))
			     { BEEP_OUT = 1; }
		     }
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
		  if(Uart_tran > 1)
		    {
			 ReceiveDate[0] = Uart_tran;
			 ReceiveDate[1] = 0x06;
			 ReceiveDate[2] = 0;
			 ReceiveDate[3] = Uart_ID;
			 ReceiveDate[4] = mA_Value;
			 ReceiveDate[5] = mA_Value >> 8;
			 CRC_CODE = CRC_CHECK();
			 CRC_Lo = CRC_CODE ;
			 CRC_Hi = CRC_CODE	>> 8 ;
			 ReceiveDate[6] = CRC_Lo;
			 ReceiveDate[7] = CRC_Hi;

			 if(tran == 0)
		      {
			    SBUF = Uart_ID ;
			    tran = 1 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
			else if(tran == 1)
		      {
			    SBUF = 0x06 ;
			    tran = 2 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
			else if(tran == 2)
		      {
			    SBUF = 0 ;
			    tran = 3 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
			else if(tran == 3)
		      {
			    SBUF = Uart_ID ;
			    tran = 4 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
		    else if(tran == 4)
		      {
			    SBUF = mA_Value ;
			    tran = 5 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }  
			else if(tran == 5)
		      {
			    SBUF = mA_Value >> 8 ;
			    tran = 6 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
			else if(tran == 6)
		      {
			    SBUF = CRC_Lo ;
			    tran = 7 ;
			    Soft_Timer[UART_SEND_TIME] = 1;
	          }
	        else if(tran == 7)
	          { 
	            SBUF = CRC_Hi;
	            tran = 0;
			    Soft_Timer[UART_SEND_TIME] = 59 ;
		      }
    	     TI = 1;
	       }
		   else{ Soft_Timer[UART_SEND_TIME] = 59 ;}
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
	   }
   return AD3421_Value;
}
/************************************************************
CP00     PS	使用權限密碼   SEC
         讀取環境溫度及設定  HS MODE
//------------------------------------------------------------
CP01 設定 C_F  
CP02 設定  TC TYPE
CP03 讀取 ZERO OFFSET值
CP04 讀取 SPAN OFFSET值
CP05 設定 YEAR_DATE	值
CP06 設定 MON_DATE	值
CP07 設定 DAY_DATE	值
CP08 設定 HOUR_DATE	值
CP09 設定 MIN_DATE	值

UP10 設定最高顯示值  HS
UP11 設定最低顯示值  LS
UP12 設定最高輸入值  RH
UP13 設定最低輸入值  RL
UP14 RELAY HI 啟動點 HI
UP15 RELAY HH 啟動點 HH
UP16 RELAY LL 啟動點 LL
UP17 RELAY LO 啟動點 LO
UP18 小數點位置顯示  D0 0=無 1=個位 2=拾位 3=百位...(無關顯示值)
UP19 顯示更新時間設定 DT  0 ~ 9S
UP20 零偏移值 設定  OF  +XXX ~ - XXX
UP21 SAMPLE RATE SET BU  0 ~4, 1200/2400/4800/9600/19200
UP22 ID CODE ID   0 ~99
UP23 低點遮蔽值  LD  
UP24 刻度進位設定值  CD	0 ~ 9
UP25 倍數顯示值設定  DB  00,01= 1   02= 2倍 03=3倍
UP26 主副機設定  MS  00 = 主機(不傳送), 01=副機(不傳送), 02=主機主動傳送,03=副機主動傳送
UP27 顯示最高值設定  HD  最高數值,
UP28 RELAY 啟動  RS	 1 = ON , 0 = OFF,
UP29 顯示位數設定 DS  2 ~ 6位
UP30 前導數顯示值設定 CL   1 = 不消0, 0=要消(剩下顯示 0.0~0.9)
UP31 顯示輸入解析值  RT  12/14/16 )
***************************************************************/ 
void DO_SETUP_TYPE(void)
{
	unsigned char set_key = 0, times = 5, cont1 = 0,Vert = 0, Itemm = 0, Flag_Read = 0; //
	unsigned char pro_key,sele_key,add_key,adc_key;

	        SETUP_LED_Disp(0,Itemm);

	 while (CAIT)
		 {
                set_key = Get_Key();	   //60,81,82,84,             //10

		          if((set_key & 0x60) == 0x60)  // pro key
			       {
				    CAIT=0;
			       }
		     	  else
			       {
			               if((set_key & 0x81) == 0x81)	  //set in & set out
			                 {
							    pro_key = 1;
							    if(Itemm == 0){Itemm = 1;}
				                else{Itemm = 2;}
			                 }
			               else
			                 { pro_key = 0 ;}
				         //==================================
			               if((set_key & 0x82) == 0x82)	   //shift 
			                 { sele_key = 1 ;}
			                else
			                 { sele_key = 0 ;}
			            //===================================
			               if((set_key & 0x84) == 0x84)	   //add /next item
						      { 
							   if(Itemm >= 1)
							     {
							      add_key = 1;
								 }
							   else
							     { 
								    if(Vert == 1)
									  {
									    if(cont1 >= 31){cont1 = 1;}
										  else{cont1++;}
									  }
						             if(Vert == 2)
									   {
									     if(cont1 >= 31){ cont1 = 10;}
			                          	  else{cont1++;}
									   } 
							     }
							   }
			                  else
			                  { add_key = 0;}
			   //==================================================
			               if((set_key & 0x88) == 0x88)	  //save
			                 { 
				                adc_key = 1;
				             }
			                else
			                 { adc_key = 0 ;}
//=======================================================================================
	      if(add_key == 1)
	       {										
	        if(times == 0){if((value_cal%10) == 9){ value_cal = value_cal- 9;}else{value_cal++;}}
 	       else if(times == 1){if((value_cal%100)/10 == 9){ value_cal = value_cal- 90;}else{ value_cal=value_cal+10;}}
	       else if(times == 2){if((value_cal%1000)/100 == 9){ value_cal = value_cal- 900;}else{  value_cal=value_cal+100;}}
	       else if(times == 3){if((value_cal%10000)/1000 == 9){ value_cal = value_cal- 9000;}else{  value_cal=value_cal+1000;}}
	       else if(times == 4){if((value_cal%100000)/10000 == 9){value_cal = value_cal- 90000;}else{  value_cal=value_cal+10000;}}
		   else if(times == 5){if((value_cal/100000) == 9){value_cal = value_cal- 900000;}else{  value_cal=value_cal+100000;}}
	      }
//PS ==============  security code  ==================================
			               if(cont1 == 0)
				             { if(sele_key == 1){ times--; if(times >= 6){times = 5;}}
							   if(Itemm == 1)
						        {  SETUP_LED_Disp(4,value_cal);}
				              else if(Itemm == 2) 
				                { 
								 if(value_cal == 999999){cont1 = 1; Itemm = 0; Vert = 1; value_cal=0;}      //company  
				                    else if(value_cal == 888888){cont1 = 5;  Vert = 2; Itemm = 0;value_cal=0;}  //age 
					                else{ cont1 = 0; Itemm = 0;CAIT=0;}
								  EEPROM_write_byte(60,Temp_m);
  				                }
							 }
//===========================comprny set up =======================================
			            if(((Work_Type == 0)&&((cont1 == 3)||(cont1 == 4)))||((Work_Type == 1)&&((cont1 == 3)||(cont1 == 4)))||((Work_Type == 2)&&((cont1 == 1)||(cont1 == 2)))||((Work_Type == 3)&&((cont1 == 1)||(cont1 == 2))))
					      {	 
					            if (Soft_Timer[ADC_READ_TIME] == 0) 
				                   {
					                 Soft_Timer[ADC_READ_TIME] = 4 ;
					                 Data_Value[t_code] = Read_AD3421_Value();
					                 if(t_code < 12)
						              {t_code++;}
					                 else
					                  {
					                    Data_Value[14] = (Data_Value[12]/5+Data_Value[11]/5+Data_Value[10]/5+Data_Value[9]/5+Data_Value[8]/5);
						                t_code = 8 ;
					                  }
				                    }
						          else
					                { Data_Value[14] = Data_Value[t_code] ; }
 						 }
//==========================   TC_CAL  6===============================
						  if(Work_Type == 0)
						      {
							    if(cont1 == 1)	// C_F_CAL
					              {
								     times = 0;
						             if(value_cal >= 2){value_cal = 0;}
							           if(Itemm == 1 )
						                 {	 	
								           SETUP_LED_Disp(2, value_cal);
							             }
							           else if(Itemm == 2)
						                 { 
								           Itemm = 0;
						                   EEPROM_write_byte(C_F_Select,value_cal);  //C,F
						                 }
							            else
							             { SETUP_LED_Disp(1,cont1);}
						          }
//--------------------------------------- eep 7------------------------------------------------
							    else if (cont1 == 2)	  // TYPE_CAL 7
							      {
								       times = 0;
						               if(value_cal >= 6){value_cal = 0;}
							           if (Itemm == 1 )
				                         {  SETUP_LED_Disp(3,value_cal); }
						             else if(Itemm == 2)
						                {	Itemm = 0 ;
						                    EEPROM_write_byte(Type_Select,value_cal);  //K,J,T,E,R,B,S
						                }
                                       else { SETUP_LED_Disp(1,cont1);}
								  }
//-------------------------------------eep 8----------------------------------------------------
								else if(cont1 == 3)		   // TC_ZERO_CAL  
				                  { 
					                 if(Itemm == 1 )
					                   { SETUP_LED_Disp(6, Data_Value[14]); }
	                                 else if(Itemm == 2)
					                   {  Itemm = 0 ;
							              Temp_Flag = 3 ;
							              Temp_offset = Temp_m;	  //negtive
						                 if (Data_Value[14] >= (Temp_m*13)/10) //-50-tm	
										   {
							                  if( AV_COD == 1)
							                    { Zero_offset =  Data_Value[14] - (Temp_m*13)/10; NG_COD = 1;use_flag = use_flag|0x01;}
							                 else{ Zero_offset = (Temp_m*13)/10 + Data_Value[14]; NG_COD = 0;use_flag = use_flag&0xfe;}
							               }						 
						                 else
							               {  
							   	               if( AV_COD == 1)
							                    { Zero_offset = (Temp_m*13)/10 - Data_Value[14] ;  NG_COD = 0;use_flag = use_flag&0xfe;}
							                  else {Zero_offset = Data_Value[14] + (Temp_m*13)/10 ;  NG_COD = 0;use_flag = use_flag&0xfe;}
							                    }
							                    EEPROM_write_byte(Status_flag,(use_flag));
							                    EEPROM_write_word(Zero,Zero_offset); 
						                }
						              else{SETUP_LED_Disp(1,cont1);}	
		                           }
//--------------------------------------eep 10---12-----------------------------------------
								 else if(cont1 == 4)//  TC_SPAN_CAL
		                           { 
							         if(Itemm == 1 )
							           { SETUP_LED_Disp(6,Data_Value[14]); }
				                    else if(Itemm == 2)
					                   {  Itemm = 0 ;
					                       if( NG_COD == 1)
					                        {
											   Span_offset = Data_Value[14] + Zero_offset + (Temp_m*13)/10;
											 }														   
					                       else
										     {
											   Span_offset = Data_Value[14] - Zero_offset + (Temp_m*13)/10;
											 }
					                        EEPROM_write_word(Span,Span_offset); 
											 
					                        if(Span_offset >= 0xc8ca )
					                          {Span_Value = (Span_offset-Zero_offset)/(Span_offset - 0xc8ca);use_flag = use_flag|0x10;}
					                        else
					                          {Span_Value = (Span_offset-Zero_offset)/(0xc8ca - Span_offset);use_flag = use_flag&0xef;}
					                          EEPROM_write_word(Slope,Span_Value);
						                      delay(50);
						                      EEPROM_write_byte(Status_flag,use_flag);
					                    }
							           else
							           { SETUP_LED_Disp(1,cont1);}
				                    }
								 }
//======================================eep 6===========   Rtd_CAL  =========================
							   else if(Work_Type == 1)
						          {
							        if(cont1 == 1)  // C_F_CAL
					                  {
								        times = 0;
						                if(value_cal >= 1){value_cal = 0;}
							            if(Itemm == 1 )
						                 {	 	
								           SETUP_LED_Disp(1,value_cal);
							             }
							           else if(Itemm == 2)
						                 { 
								           Itemm = 0;
						                   EEPROM_write_byte(C_F_Select,value_cal);  //C,F
						                 }
							            else
							             { SETUP_LED_Disp(1,cont1);}
						          }
//-------------------------------------eep 7-----------------------
							  else if (cont1 == 2)	  // TYPE_CAL
							      {
								       times = 0;
						               value_cal = 0x07;
						               if (Itemm == 1 )
				                         {  SETUP_LED_Disp(2,value_cal); }
						             else if(Itemm == 2)
						                {	Itemm = 0 ;
						                    EEPROM_write_byte(Type_Select,value_cal);  //rtd
						                }
                                       else { SETUP_LED_Disp(1,cont1);}
								  }
//------------------------------------eep 8------------------------------------
							   else if(cont1 == 3)	// RTD_ZERO_CAL
		                          {  times = 0;
						             if(Itemm == 1 )
							           {
						                 if( AV_COD == 1){ NG_COD = 1;}else{ NG_COD = 0;}
						                     SETUP_LED_Disp(6,Data_Value[14]);
							           }
						              else if(Itemm == 2)
						               { Itemm = 0;
						                 Zero_offset = Data_Value[14] ;
						                 EEPROM_write_word(Zero,Zero_offset);  //rtd
							            delay(50);
							          if( NG_COD == 1){ EEPROM_write_byte(Status_flag,(use_flag|0x02));}
							          else { EEPROM_write_byte(Status_flag,(use_flag&0xfd));}
						               }
							          else
							           { SETUP_LED_Disp(1,cont1);}
						        }
//-----------------------------------eep 10 ---12--------------------------------------------------------
							 else if(cont1 == 4)	//   RTD_SPAN_CA
		                        {  
								    times = 0;
						            if(Itemm == 1 )
							         { SETUP_LED_Disp(6,Data_Value[14]);  }
						          else if(Itemm == 2)
					                 { Itemm = 0;
							            Span_offset = Data_Value[14] ;
							            EEPROM_write_word(Span,Span_offset);  //rtd
							            if( NG_COD == 1)
							              { if ((Span_offset + Zero_offset) > 0x44e4 )
							                   { Span_Value = ((Span_offset + Zero_offset)/((Span_offset + Zero_offset)-0x44e4));}
									        else
									           { Span_Value = ((Span_offset + Zero_offset)/(0x44e4 - (Span_offset + Zero_offset)));}
								           }
								        else
								          { if ((Span_offset - Zero_offset) > 0x44e4 )
								               {Span_Value = ((Span_offset - Zero_offset)/((Span_offset - Zero_offset)-0x44e4));}
								            else
								               {Span_Value = ((Span_offset - Zero_offset)/(0x44e4 - (Span_offset - Zero_offset)));}
								          }
								           EEPROM_write_word(Slope,Span_Value);
							         }							
							       else
								    { SETUP_LED_Disp(1,cont1);}
						         }
						   }
//==============================   mV_ZERO_CAL  ===eep 8========================================================
						 else if(Work_Type == 2)
						    {
			                 if(cont1 == 1)
		                       {	
							    if(Itemm == 1 )
							      {
			                        if( AV_COD == 1){ NG_COD = 1;}else{ NG_COD = 0;}
						             SETUP_LED_Disp(6,Data_Value[14]);
							      }
						       else if(Itemm == 2)
						          { Itemm = 0 ;
							         Zero_offset = Data_Value[14] ;
							         EEPROM_write_word(Zero,Zero_offset);  
							         delay(50);
							          if( NG_COD == 1){ EEPROM_write_byte(Status_flag,(use_flag|0x04));}
							         else { EEPROM_write_byte(Status_flag,(use_flag&0xfb));}
						          }
						         else
						          { SETUP_LED_Disp(1,cont1);}
					          }
//-----------------------------------------------eep 10 -12------
 			              else if(cont1 == 2)	   //  mV_SPAN_CAL
		                      {
							    if(Itemm == 1 )
					              {   SETUP_LED_Disp(6,Data_Value[14]); }
					            else if(Itemm == 2)
					              {	Itemm = 0; 	cont1 = 4 ;
						             Span_offset = Data_Value[14] ;
						             EEPROM_write_word(Span,Span_offset);  
						            if( NG_COD == 1)
						              { if ((Span_offset + Zero_offset) > 0x7d00 )		 
						                  { Span_Value = ((Span_offset + Zero_offset)/((Span_offset + Zero_offset)-0x7d00));}
						                else
						                  { Span_Value = ((Span_offset + Zero_offset)/(0x7d00 - (Span_offset + Zero_offset)));}
						              }
					                else
					                  {  if((Span_offset - Zero_offset) > 0x7d00)
							               {Span_Value = ((Span_offset - Zero_offset)/((Span_offset - Zero_offset)-0x7d00));}
						                 else
						                   {Span_Value = ((Span_offset - Zero_offset)/(0x7d00 - (Span_offset - Zero_offset)));}
						              }
						                   EEPROM_write_word(Slope,Span_Value);
				                 }
					            else
					            { SETUP_LED_Disp(1,cont1);}
				              }
						 }
//===============================	 mA_ZERO_CAL  ==eep 8 ====================================
                      else if(Work_Type == 3)
			             {
						     if(cont1 == 1)
		                       { 																				    
					              if(Itemm == 1 )
					                {  if( AV_COD == 1){ NG_COD = 1;}else{ NG_COD = 0;}
							            SETUP_LED_Disp(6,Data_Value[14]);
						            }
					             else if(Itemm == 2)
						            { Itemm = 0; 
						              Zero_offset = Data_Value[14];
						              EEPROM_write_word(Zero,Zero_offset);  
						              delay(50);
							          if( NG_COD == 1){ EEPROM_write_byte(Status_flag,(use_flag|0x08));}
						              else { EEPROM_write_byte(Status_flag,(use_flag&0xf7));}
						            }
					               else
					                { SETUP_LED_Disp(1,cont1);}
					           }
//--------------------------------------eep 10   12 ------------
			               else if(cont1 == 2)	 // mA_SPAN_CAL 
		                     {	
					            if(Itemm == 1 )
					              {  SETUP_LED_Disp(6,Data_Value[14]);}
						        else if(Itemm == 2)
						          {	Itemm = 0; cont1 = 4;
						            Span_offset = Data_Value[14]; 
							        EEPROM_write_word(Span,Span_offset);  
							        if( NG_COD == 1)
							          {  if ((Span_offset + Zero_offset) > 0x1900 )	
							                { Span_Value = ((Span_offset + Zero_offset)/((Span_offset + Zero_offset)- 0x1900));}
								         else
								           { Span_Value = ((Span_offset + Zero_offset)/( 0x1900 - (Span_offset + Zero_offset)));}
							           }
						             else
							           {  if ((Span_offset - Zero_offset) > 0x1900 )
							                 {Span_Value = ((Span_offset - Zero_offset)/((Span_offset - Zero_offset)- 0x1900));}
								          else
								             {Span_Value = ((Span_offset - Zero_offset)/( 0x1900 - (Span_offset - Zero_offset)));}
							           }
							              EEPROM_write_word(Slope,Span_Value);
						           }
						          else
					               { SETUP_LED_Disp(1,cont1);}
				              }
						 }
//-------------------- YEAR_DATE_CAL ------eep14-------------------
			          if(cont1 == 5)
		                 { 	if(sele_key == 1){times--; if(times >= 2){times = 1;}}
				            if(Itemm == 1 )
					           {
							    if(value_cal <= 99)
								  {								
	                               use_year = value_cal; 
								  }
								 else{value_cal = 0;}
 					              SETUP_LED_Disp(6,use_year + 2000);
						      }
				            else if(Itemm == 2)
					          { Itemm = 0;
						        RTC_write_byte(6,use_year);
						        EEPROM_write_byte(Year_Date,use_year); 
					          }
					        else
					          { SETUP_LED_Disp(1,cont1);}
				       }
//------------------------MON_DATE_CAL ------eep 15---------
				 else if(cont1 == 6)
		          {	   times = 0;
				    if(Itemm == 1 )
				      {	 
					    if(value_cal >= 1) {use_mon++ ; value_cal = 0;}
					    if((use_mon > 12)||(use_mon == 0)) {use_mon = 1;}
			                SETUP_LED_Disp(6,use_mon);
					  }
				    else if(Itemm == 2)
				      {	
					    Itemm = 0;
					    RTC_write_byte(5,use_mon);
					    EEPROM_write_byte(Mon_Date,use_mon);
				     }
				   else
					 { SETUP_LED_Disp(1,cont1);}
				}
//------------------------ DAY_DATE_CAL ----16-------	//add week setup
			   else if(cont1 == 7)
		         {	 times = 0;
				    if(Itemm == 1 )
				      {		if(value_cal >= 1){use_day++; value_cal = 0 ;}
							 if((use_mon == 2)&&(use_year%4 == 0)&&(use_day > 29)) { use_day = 1; value_cal = 0;}
							else if((use_mon == 2)&&(use_year%4 != 0)&&(use_day > 28)){ use_day = 1; value_cal = 0;}
							 if(((use_mon == 1)||(use_mon == 3)||(use_mon == 5)||(use_mon == 7)||(use_mon == 8)||(use_mon == 10)||(use_mon == 12))&&(use_day > 31)) { use_day = 1;value_cal = 0;}
							else if(((use_mon == 4)||(use_mon == 6)||(use_mon == 9)||(use_mon == 0x11))&&(use_day > 30)) { use_day = 1; value_cal = 0;}
         
						     SETUP_LED_Disp(6,use_day);
					  }
					 else if(Itemm == 2)
					  {  Itemm = 0;						  
						 RTC_write_byte(4,use_day);
						 EEPROM_write_byte(Day_Date,use_day);
					  }
					 else
					 { SETUP_LED_Disp(1,cont1);}
			  }
//-------------------- HOUR_DATE_CAL  ------17-----------------
  			     else if(cont1 == 8)
		          {	  times = 0;
				      if(Itemm == 1 )
					    {
						   if(value_cal >= 1){use_hour++; value_cal = 0 ;}
						   if(use_hour > 23) {use_hour = 0; value_cal = 0;}
						   SETUP_LED_Disp(6,use_hour);
						}
					  else if(Itemm == 2)
						  {  Itemm = 0;
							 RTC_write_byte(2,use_hour);
							 EEPROM_write_byte(Hour_Date,use_hour);
						  }
						else
					      { SETUP_LED_Disp(1,cont1);}
				   }
//------------------  MIN_DATE_CAL  -------18------------
				 else if(cont1 == 9)
		           { times = 0;
				      if(Itemm == 1 )
						 {
						  if(value_cal >= 1){use_min++; value_cal = 0 ;}	
						  if(use_min > 59) {use_min = 0; value_cal = 0;}
     				        SETUP_LED_Disp(6,use_min );
					   }
				   else if(Itemm == 2)
					  { Itemm = 0;
						RTC_write_byte(1,use_min );
						EEPROM_write_byte(Min_Date,use_min);
					  }
					else
					  { SETUP_LED_Disp(1,cont1);}
				   }
//===================================eep20=============================
/*********************  設定最高顯示值  HS **********************/
			     else if(cont1 == 10)
		           {  if(sele_key == 1){times--; if(times >= 5){times = 4;}}
					  if(Itemm == 1 )
					    {  
						   if(value_cal > 65535){value_cal = 0;}     //  Disp_Show = 1 ;
				           SETUP_LED_Disp(6,value_cal);
					    }
				      else if(Itemm == 2)
					    {
						    Itemm = 0;
						 	EEPROM_write_word(Hi_Disp,value_cal);
							Flag_Read = 0;
						    value_cal = 0;
					    }
					  else
					    { SETUP_LED_Disp(1,cont1);
						   if(Flag_Read == 0){value_cal = EEPROM_read_word(Hi_Disp);Flag_Read = 1;}
						}
				   }
//---------------------   設定最低顯示值  LS -eep 22------------------------
			      else if(cont1 == 11)
		           {   if(sele_key == 1){ times--; if(times >= 5){times = 4;}}
					   if(Itemm == 1 )
					     { 
						  if(value_cal > 65535){value_cal = 0;}
						  SETUP_LED_Disp(6,value_cal);
						 }
				       else if(Itemm == 2)
					     { 
						    Itemm = 0;
						    EEPROM_write_word(Lo_Disp,value_cal);
						    Flag_Read = 0;
						    value_cal = 0;
					     }
					   else
					    { SETUP_LED_Disp(1,cont1);
						  if(Flag_Read == 0){value_cal = EEPROM_read_word(Lo_Disp);Flag_Read = 1;}
						}
				   }
//---------------------    設定最高輸入值  RH ---24----------------------
			       else if(cont1 ==12)
		            {  if(sele_key == 1){times--; if(times >= 5){times = 4;}}
					  if(Itemm == 1 )
					    {  
						   if(value_cal > 65535){value_cal = 0;}
						   SETUP_LED_Disp(6,value_cal);
					    }
				      else if(Itemm == 2)
					    {
						  Itemm = 0;
						  EEPROM_write_word(Hi_Input,value_cal);
						  Flag_Read = 0;
						  value_cal = 0;
					    }
					  else
					    { SETUP_LED_Disp(1,cont1);
						  if(Flag_Read == 0){value_cal = EEPROM_read_word(Hi_Input);Flag_Read = 1;}
						}
				   	}
//---------------------    設定最低輸入值  RL ---26----------------------
			       else if(cont1 == 13)
		            {  if(sele_key == 1){times--; if(times >= 5){times = 4;}}
					  if(Itemm == 1 )
					    {   
						   if(value_cal > 65535){value_cal = 0;}
						   SETUP_LED_Disp(6,value_cal);
						}
				      else if(Itemm == 2)
					    {
						  Itemm = 0;
						  EEPROM_write_word(Lo_Input,value_cal);
						 
					    }
					  else
					    { SETUP_LED_Disp(1,cont1);
						  if(Flag_Read == 0){value_cal = EEPROM_read_word(Lo_Input);Flag_Read = 1;}
						}
				   	}
//---------------------   RELAY HI 啟動點 HI ---28 ----------------------
			       else if(cont1 == 14)
		            { if(sele_key == 1){times--; if(times >= 5){times = 4;}}
					  if(Itemm == 1 )
					  {
					  	 if	(value_cal > 65535){value_cal = 0;}
					  	SETUP_LED_Disp(6,value_cal);

					  }
					else if(Itemm == 2)
					  {	Itemm = 0;
					     EEPROM_write_word(Alarm_Hi,value_cal);  //alarm
					  }
					else
				   	  { SETUP_LED_Disp(1,cont1);}
				 }
//---------------------   RELAY HH 啟動點 HH ----30---------------------
			    else if(cont1 == 15)
		         {  if(sele_key == 1){ times--; if(times >= 5){times = 4;}}
					 if(Itemm == 1 )
				      {	  
					     if	(value_cal > 65535){value_cal = 0;}
						 SETUP_LED_Disp(6,value_cal);
					  }
				   else if(Itemm == 2)
					  {	Itemm = 0;
					     EEPROM_write_word(Relay_HH,value_cal);  //alarm
					  }
					 else
					  { SETUP_LED_Disp(1,cont1);}
				 }
//---------------------   RELAY LL 啟動點 LL ---32----------------------
			   else if(cont1 == 16)
				{  if(sele_key == 1){ times--; if(times >= 5){times = 4;}}
					  if(Itemm == 1 )
					   { 
					     if	(value_cal > 65535){value_cal = 0;}
						  SETUP_LED_Disp(6,value_cal);
					   }
				    else if(Itemm == 2)
				      { Itemm = 0;
				         EEPROM_write_word(Relay_LL,value_cal);  //alarm
					  }
				    else
				      { SETUP_LED_Disp(1,cont1);}	 
				  }
//---------------------    RELAY LO 啟動點 LO---34----------------------
			    else if(cont1 == 17)
		          {	 if(sele_key == 1){ times--; if(times >= 5){times = 4;}}

					  if(Itemm == 1 )
					    { 
						    if	(value_cal > 65535){value_cal = 0;}
						    SETUP_LED_Disp(6,value_cal);
  				        }
				   else if(Itemm == 2)
					   {  Itemm = 0;
					      EEPROM_write_word(Alarm_Low,value_cal);  //alarm
					   }
					 else
					  { SETUP_LED_Disp(1,cont1);} 
			     }
//---------------------   小數點位置顯示  D0 0=無 1=個位 2=拾位 3=百位...(無關顯示值) --36-----------------------
			  else if(cont1 == 18)
				{       times = 0;
				       if(Itemm == 1 )
					  { 
			            if(value_cal >= 5){ value_cal = 0;}
						 SETUP_LED_Disp(6,value_cal);
					   }	   					
				   else if(Itemm == 2)
					  {
					    Itemm = 0;
					    EEPROM_write_byte(Dot_Point,value_cal);  //alarm
					  }
					else
					    { SETUP_LED_Disp(1,cont1);}
				   	}
//---------------------   顯示更新時間設定 DT  0 ~ 9S -----37--------------------
			       else if(cont1 == 19)
		            {   times = 0;
				      if(Itemm == 1 )
					    { 
			              if(value_cal > 9){ value_cal = 0;}
						 SETUP_LED_Disp(6,value_cal);
					    }
				      else if(Itemm == 2)
					    {  Itemm = 0;
					   	   EEPROM_write_byte(Flash_Disp,value_cal);  //alarm
					    }								

					  else
					   { SETUP_LED_Disp(1,cont1);}
				   	}
//---------------------    零偏移值 設定  OF  +XXX ~ - XXX ---38----------------------
			       else if(cont1 == 20)
		            { if(sele_key == 1){times--; if(times >= 5){times = 4;}}
					  if(Itemm == 1 )
					    {
						 if	(value_cal > 65535){value_cal = 0;}
						 SETUP_LED_Disp(6,value_cal);
                        }
				      else if(Itemm == 2)
					    {  Itemm = 0;
					       EEPROM_write_word(Zero_Code,value_cal);  //alarm
						}
					  else
					    { SETUP_LED_Disp(1,cont1);}
				   	}
//---------------------   SAMPLE RATE SET BU  0 ~4, 1200/2400/4800/9600/19200----40---------------------
			       else if(cont1 == 21)
		            {  times = 0;
					  if(Itemm == 1 )
					    {  	 if(value_cal >= 5){ value_cal = 0;}	
 						  	 if(value_cal == 0){ Show_Data = 1200;}	
							 if(value_cal == 1){ Show_Data = 2400;}	
							 if(value_cal == 2){ Show_Data = 4800;}	
							 if(value_cal == 3){ Show_Data = 9600;}
							 if(value_cal == 4){ Show_Data = 19200;}									
				      
						 SETUP_LED_Disp(6,Show_Data);
					   }
				      else if(Itemm == 2)
					    {Itemm = 0;
					       EEPROM_write_byte(Sample_Rate,value_cal);  //alarm
					    }
					  else
					    { SETUP_LED_Disp(1,cont1);}
				   	}
//---------------------    ID CODE ID   0 ~99 ----------------41---------
			       else if(cont1 == 22)
		            { if(sele_key == 1){times--; if(times >= 2){times = 1;}}
					  if(Itemm == 1 )
					    {
						  if(value_cal > 99){value_cal = 0;}
					     SETUP_LED_Disp(6,value_cal);
					    }
				      else if(Itemm == 2)
					    {Itemm = 0;
						 EEPROM_write_byte(ID_Code,value_cal);  //alarm
					    }
					  else
					    { SETUP_LED_Disp(1,cont1);}
				   	}
//---------------------    低點遮蔽值  LD --------------42-----------
			       else if(cont1 == 23)
		            {   if(sele_key == 1){times--; if(times >= 5){times = 4;}}
					  if(Itemm == 1 )
					     {if (value_cal > 65535){value_cal = 0;}
					        SETUP_LED_Disp(6,value_cal);
					     }
				      else if(Itemm == 2)
					    {Itemm = 0;
					      EEPROM_write_word(Lo_Mask,value_cal); }
					  else
					    { SETUP_LED_Disp(1,cont1);}
				   	}
//---------------------    刻度進位設定值  CD	0 ~ 9 ------------44-------------
			       else if(cont1 == 24)
		            {	times = 0 ;
					  if(Itemm == 1 )
					  	{
						  if(value_cal > 9){value_cal = 0;}
						 SETUP_LED_Disp(6,value_cal);
			            }
				      else if(Itemm == 2)
					    {Itemm = 0; EEPROM_write_byte(Count_Code,value_cal); 
					    }
					  else
					    { SETUP_LED_Disp(1,cont1);}
				   	}
//---------------------   倍數顯示值設定  DB  00,01= 1   02= 2倍 03=3倍 ------45-------------------
			       else if(cont1 == 25)
		            {		times = 0 ;
					  if(Itemm == 1 )
					    {
						  if(value_cal > 9){ value_cal = 0;}										
						    SETUP_LED_Disp(6,value_cal);
				        }
				      else if(Itemm == 2)
					    {Itemm = 0; EEPROM_write_byte(Gain,value_cal); 
					    }
					  else
					   { SETUP_LED_Disp(1,cont1);}
				   	}
//---------------------  主副機設定  MS  00 = 主機(不傳送), 01=副機(不傳送), 02=主機主動傳送,03=副機主動傳送 ----46---------------------
			       else if(cont1 == 26)
		            {  	times = 0 ;
					  if(Itemm == 1 )
					    { 
						  if(value_cal > 3){ value_cal = 0;}										
			          
						   SETUP_LED_Disp(6,value_cal);
					   }
				      else if(Itemm == 2)
					    {Itemm = 0; EEPROM_write_byte(Transfor,value_cal); 
					    }
					 else
					  { SETUP_LED_Disp(1,cont1);}
				   	}
//---------------------    顯示最高值設定  HD  最高數值 5位, ----------48---------------
			       else if(cont1 == 27)
		            {	 if(sele_key == 1){ times--; if(times >= 5){times = 4;}}
					  if(Itemm == 1 )
					    {   if(value_cal > 65535){value_cal = 0;}
						   SETUP_LED_Disp(6,value_cal);
					  }
				      else if(Itemm == 2)
					    {Itemm = 0;	 EEPROM_write_word(Disp_Hi,value_cal); 
					    }
					  else
					    { SETUP_LED_Disp(1,cont1);}
				   	}
//---------------------   RELAY 啟動  RS 1 = ON , 0 = OFF, --------------50-----------
			       else if(cont1 == 28)
		            { times = 0 ;
					  if(Itemm == 1 )
					    { 							
				            if(value_cal >= 2){ value_cal = 0;}
							SETUP_LED_Disp(6,value_cal);
					   }
				      else if(Itemm == 2)
					    {Itemm = 0;
						  EEPROM_write_byte(Relay,value_cal);  
					    }
					  else
					   { SETUP_LED_Disp(1,cont1);}
				   	}
//---------------------   顯示位數設定 DS  2 ~ 5位 -----------------51--------
			       else if(cont1 == 29)
		            {  times = 0 ;
					  if(Itemm == 1 )
					    { 
						     if(value_cal < 2){value_cal = 2;}
							 if(value_cal >= 6){value_cal = 2;}
						SETUP_LED_Disp(6,value_cal);										
					   }
				      else if(Itemm == 2)
					    {Itemm = 0;EEPROM_write_byte(Disp_Count,value_cal);
					    }
					  else
					   { SETUP_LED_Disp(1,cont1);}
				   	}
//---------------------   前導數顯示值設定 CL   0 = 不消, 1=要消(剩下顯示 0.0~0.9) ----------52---------------
			       else if(cont1 == 30)				  		
				    {  times = 0 ;
					  if(Itemm == 1 )
					    { 
				        
				          {										
				            if(value_cal >= 2){ value_cal = 0;}
						  }
 					      SETUP_LED_Disp(6,value_cal);
				         }
				       else if(Itemm == 2)
					     {Itemm = 0;EEPROM_write_byte(Zero_Set,value_cal);
					     }
					  else
					    { SETUP_LED_Disp(1,cont1);}
				   	}
//---------------------   顯示輸入最低值  RT  12/14/16 bit) -----------------53--------
			       else if(cont1 == 31)
		            {  times = 0 ;
					  if(Itemm == 1 )
					    { 
						    if(value_cal >= 3){ value_cal = 0;}
			                if(value_cal == 0){ Show_Data = 12;}
							if(value_cal == 1){ Show_Data = 14;}
							if(value_cal == 2){ Show_Data = 16;}
						//	if(value_cal == 3){ Show_Data = 18;}
						    SETUP_LED_Disp(6,Show_Data);
						}
				      else if(Itemm == 2)					 
					    { Itemm = 0;
						  EEPROM_write_byte(Decode_Num,value_cal);
					    }
					  else
					    { SETUP_LED_Disp(1,cont1);}
				       }
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
   EEPROM_write_byte(Hour_Date,use_hour);
   EEPROM_write_byte(Min_Date, use_min);
 }
}
/******************************************
  EEP_Default Value
******************************************/
void EEPROM_WriteDefault(void)
{
    EEPROM_write_byte(C_F_Select, 0);   //c
	EEPROM_write_byte(Type_Select,0);   //Type define k=0.j=1,t=2
	EEPROM_write_word(Zero, 0);			//
	EEPROM_write_word(Span, 50000);
	EEPROM_write_word(Slope, 1);
    EEPROM_write_byte(Year_Date,0x15);
    EEPROM_write_byte(Mon_Date, 0x01);
    EEPROM_write_byte(Day_Date, 0x01);
    EEPROM_write_byte(Hour_Date,0x12);
    EEPROM_write_byte(Min_Date, 0x01);

    EEPROM_write_word(Hi_Disp, 65535);
    EEPROM_write_word(Lo_Disp, 0);
    EEPROM_write_word(Hi_Input, 65535);
    EEPROM_write_word(Lo_Input, 0);
	EEPROM_write_word(Alarm_Hi, 5000);
	EEPROM_write_word(Relay_HH, 5000);
	EEPROM_write_word(Relay_LL,  0);
	EEPROM_write_word(Alarm_Low, 0);
	EEPROM_write_byte(Dot_Point,  0);
	EEPROM_write_byte(Flash_Disp, 0);
	EEPROM_write_word(Zero_Code,  0);
	EEPROM_write_byte(Sample_Rate, 3);
	EEPROM_write_byte(ID_Code,  0);
	EEPROM_write_word(Lo_Mask, 0);
	EEPROM_write_byte(Count_Code,  0);
	EEPROM_write_byte(Gain, 0);
	EEPROM_write_byte(Transfor, 0);
	EEPROM_write_word(Disp_Hi, 0);
	EEPROM_write_byte(Relay,  0);
	EEPROM_write_byte(Disp_Count, 5);
	EEPROM_write_byte(Zero_Set,  0);
	EEPROM_write_byte(Decode_Num,  2);
	EEPROM_write_byte(Status_flag, 0);
	EEPROM_write_word(60,0);
	EEPROM_write_word(EEP_ADR, 64);		//eep start code
    RTC_ON();
}
/*****************************************************/
void DO_RESET_TYPE(void)
{
     EEPROM_WriteDefault();
    LED_Fill();                                     //  LED all light
	C_F_Type =      EEPROM_read_byte(C_F_Select);
	TC_Type =       EEPROM_read_byte(Type_Select);       //Type define k=0.j=1,t=2
	Zero_offset =   EEPROM_read_word(Zero);	
	Span_offset =   EEPROM_read_word(Span);
 	Span_Value  =   EEPROM_read_word(Slope);
    use_year =      EEPROM_read_byte(Year_Date);
    use_mon =       EEPROM_read_byte(Mon_Date);
    use_day =       EEPROM_read_byte(Day_Date);
    use_hour =      EEPROM_read_byte(Hour_Date);
    use_min =       EEPROM_read_byte(Min_Date);
    Hi_Disp_Code =  EEPROM_read_word(Hi_Disp);
    Lo_Disp_Code =  EEPROM_read_word(Lo_Disp);
    Hi_Input_Code = EEPROM_read_word(Hi_Input);
    Lo_Input_Code = EEPROM_read_word(Lo_Input);
	alarm_Hi_set =  EEPROM_read_word(Alarm_Hi);
	alarm_HH_set =  EEPROM_read_word(Relay_HH);
	alarm_LL_set =  EEPROM_read_word(Relay_LL);
	alarm_Low_set = EEPROM_read_word(Alarm_Low);
	Dot_Addr =      EEPROM_read_byte(Dot_Point);
	Flash_Time =    EEPROM_read_byte(Flash_Disp);
	Zero_Add =      EEPROM_read_word(Zero_Code);
	Uart_Rate =     EEPROM_read_byte(Sample_Rate);
	Uart_ID =       EEPROM_read_byte(ID_Code);
	Low_Limit =     EEPROM_read_word(Lo_Mask);
	Disp_Neg =      EEPROM_read_byte(Count_Code);
	Disp_Gain =     EEPROM_read_byte(Gain);
	Uart_tran =     EEPROM_read_byte(Transfor);
	Hi_Limit =      EEPROM_read_word(Disp_Hi);
	Relay_ON_OFF =  EEPROM_read_byte(Relay);
	Disp_Bits =     EEPROM_read_byte(Disp_Count);
	Disp_Show =     EEPROM_read_byte(Zero_Set);
	Decode_Bit =    EEPROM_read_byte(Decode_Num);
    use_flag =	    EEPROM_read_byte(Status_flag);
 	Temp_offset  =  EEPROM_read_word(60);
//	 eep_count = EEPROM_read_byte(EEP_ADR);
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
   TR0  = 0;          //;timer0 stop
   IFMT = 0x07 ;      //#AUXRA_Rd ;set read AUXRA command
   SCMD = 0x46 ;      //h
   SCMD = 0xB9 ;      //h
   IFD	= IFD |= 0x03 ;
   IFMT = 0x06;       // #AUXRA_Wr ;set write AUXRA command
   SCMD = 0x46;       // h
   SCMD = 0xB9;       //h
   IFMT = 0x07;       //#AUXRA_Rd ;set read AUXRA command
   SCMD = 0x46;       //h
   SCMD = 0xB9;       //h
   IFD = IFD &= 0xFB; //
   IFMT = 0x06;       //, #AUXRA_Wr ;set write AUXRA command
   SCMD = 0x46;       //h
   SCMD = 0x0B9;      //h

	P0M0 = 0xFF;	  //00=Qb,01=pull output, 10= input only,11=open drain
 	P0M1 = 0x00;	 //P0= ALL INPUT  00
	P0   = 0xff;

	P1M0 = 0x00;	 //P1= ALL OUTPUT//00
	P1M1 = 0xFF;     //SETUP P1 ALL LO //  define P1.3 P1.4 P1.5 as push-pull
    P1   = 0x00;
    
	P2M0 = 0x24;	 //P2= ALL OUTOUT	 04 
	P2M1 = 0xFF; 	 //SETUP P2 ALL LO	 df
	P2  =  0x00;

    P3M0 = 0xED;	 //	ed  
	P3M1 = 0x13;	 // 13
	P3   = 0x2C; 	 // 2c

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
	 C_F_Type =     EEPROM_read_byte(C_F_Select);
	 TC_Type =      EEPROM_read_byte(Type_Select);       //Type define k=0.j=1,t=2
	 Zero_offset =  EEPROM_read_word(Zero);	
	 Span_offset =  EEPROM_read_word(Span);
 	 Span_Value  =  EEPROM_read_word(Slope);
     use_year =     EEPROM_read_byte(Year_Date);
     use_mon =      EEPROM_read_byte(Mon_Date);
     use_day =      EEPROM_read_byte(Day_Date);
     use_hour =     EEPROM_read_byte(Hour_Date);
     use_min =      EEPROM_read_byte(Min_Date);
     Hi_Disp_Code =  EEPROM_read_word(Hi_Disp);
     Lo_Disp_Code =  EEPROM_read_word(Lo_Disp);
     Hi_Input_Code = EEPROM_read_word(Hi_Input);
     Lo_Input_Code = EEPROM_read_word(Lo_Input);
	alarm_Hi_set =  EEPROM_read_word(Alarm_Hi);
	alarm_HH_set =  EEPROM_read_word(Relay_HH);
	alarm_LL_set =  EEPROM_read_word(Relay_LL);
	alarm_Low_set = EEPROM_read_word(Alarm_Low);
    Relay_ON_OFF =  EEPROM_read_byte(Relay);
	Dot_Addr =      EEPROM_read_byte(Dot_Point);
	Flash_Time =    EEPROM_read_byte(Flash_Disp);
	Zero_Add =      EEPROM_read_word(Zero_Code);
	Uart_Rate =     EEPROM_read_byte(Sample_Rate);	
	Uart_ID =       EEPROM_read_byte(ID_Code);		
	Low_Limit =     EEPROM_read_word(Lo_Mask);		
	Disp_Neg =      EEPROM_read_byte(Count_Code);  //
	Disp_Gain =     EEPROM_read_byte(Gain);
	Uart_tran =     EEPROM_read_byte(Transfor);	   
	Hi_Limit =      EEPROM_read_word(Disp_Hi);
	Disp_Bits =     EEPROM_read_byte(Disp_Count); 
	Disp_Show =     EEPROM_read_byte(Zero_Set);
	Decode_Bit =    EEPROM_read_byte(Decode_Num);	//
    use_flag =	    EEPROM_read_byte(Status_flag);
 	Temp_offset  =  EEPROM_read_word(60);
//	eep_count = EEPROM_read_byte(EEP_ADR);
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
}
