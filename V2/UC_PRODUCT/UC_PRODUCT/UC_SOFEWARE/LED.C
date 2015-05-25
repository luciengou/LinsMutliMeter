#include <MPC82G516.h>
#include <intrins.h>
#include <LED.h>

sbit LED1_SCL = P1^0;
sbit LED1_SDA = P1^1;
sbit LED1_OE  = P1^2;
sbit LED2_SCL = P1^3;
sbit LED2_SDA = P1^4;
sbit LED2_OE  = P1^5;


//const unsigned char code tab_LED[23] = {
//	0xAF,0xA0,0x6D,0xE9,0xE2,0xCB,0xCF,0xA1,0xEF,0xEB,0xE7,0xEF,0x0F,0xAF,0x4F,0x47,0xE6,0x67,0x00, 0xA7, 0x0E, 0x40, 0xAE  };
//     0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F    H    P BLANK    n    L     -	    U
const unsigned char code tab_LED[23] = {
	0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE4,0xFE,0xF6,0xEE,0x3E,0x9C,0x7A,0x9E,0x8E,0x6E,0xCE,0x00, 0xEC, 0x1C, 0x02, 0x7C  };
//     0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F    H    P BLANK    N    L     -	    U
const unsigned char code Point_tab_LED[23] = {
	0xFD,0x61,0xDB,0xF3,0x67,0xB7,0xBF,0xE5,0xFF,0xF7,0xEF,0x3F,0x9D,0x7B,0x9F,0x8F,0x6F,0xCF,0x01, 0xED, 0x1D, 0x03, 0x7D  };
//     0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F    H    P BLANK    N    L     -	    U
/**************************************************************************************/
void LED_Disp(unsigned char LEDs, unsigned long int disp_value)
{
	unsigned char c  = 0;
	unsigned char D0 = 0;
	unsigned char D1 = 0;
	unsigned char D2 = 0;
	unsigned char D3 = 0;
	unsigned char D4 = 0;
	unsigned char D5 = 0;
	unsigned long int D_value;
	
	  D_value = disp_value;
	  c = LEDs;

   if (D_value < 0)
	 { 
 		 D0 = tab_LED[22];   //negtive

		 if (D_value > -10 )
	   	  {
		    D1 = tab_LED[18];
			D2 = tab_LED[18];
		    D3 = tab_LED[18];
			D4 =  Point_tab_LED[0];
			D5 = tab_LED[D_value];
		  }
		else if (D_value <= -10 && D_value > -100)	  
	   	  {
		    D1 = tab_LED[18];
			D2 = tab_LED[18];
			D3 = tab_LED[18];
			D4 = Point_tab_LED[D_value/10];
			D5 = tab_LED[D_value%10];
		  }
		else if (D_value <= -100 && D_value > -1000)
	   	  { 
		    D1 = tab_LED[18];
			D2 = tab_LED[18];	  //987
			D3 = tab_LED[D_value/100];
			D4 = Point_tab_LED[(D_value%100)/10];
			D5 = tab_LED[D_value%10];
		  }
		else if(D_value <= -1000 && D_value > -10000)		
		  {
		    D1 = tab_LED[18];
			D2 = tab_LED[D_value/1000];
			D3 = tab_LED[(D_value%1000)/100];
			D4 = Point_tab_LED[(D_value%100)/10];
			D5 = tab_LED[D_value%10];
		  }
	  }
	 else
	  {
		 if( D_value < 10 )    	   //99999
		   {
		    D0 = tab_LED[18];
			D1 = tab_LED[18];
			D2 = tab_LED[18];
		    D3 = tab_LED[18];
			D4 = Point_tab_LED[0];
			D5 = tab_LED[D_value];
		  }
		else if (D_value >= 10 && D_value < 100)
	   	  { 
		    D0 = tab_LED[18];
			D1 = tab_LED[18];
			D2 = tab_LED[18];
		    D3 = tab_LED[18];
			D4 = Point_tab_LED[D_value/10];
			D5 = tab_LED[D_value%10];
		  }
	    else if (D_value >= 100 && D_value < 1000)
	   	  {
		    D0 = tab_LED[18];
		    D1 = tab_LED[18];
			D2 = tab_LED[18];
			D3 = tab_LED[D_value/100]; //987 
			D4 = Point_tab_LED[(D_value%100)/10];
			D5 = tab_LED[D_value%10];
		  }
	    else if(D_value >= 1000 && D_value < 10000)
	   	  {
		    D0 = tab_LED[18];
		    D1 = tab_LED[18];
			D2 = tab_LED[D_value/1000];	//9876
		    D3 = tab_LED[(D_value%1000)/100];
			D4 = Point_tab_LED[(D_value%100)/10];
			D5 = tab_LED[D_value%10];
		  }
		else if(D_value >= 10000 && D_value < 100000)
		  {
		    D0 = tab_LED[18];		   
			D1 = tab_LED[D_value/10000];   
			D2 = tab_LED[(D_value%10000)/1000];	
		    D3 = tab_LED[(D_value%1000)/100];   
			D4 = Point_tab_LED[(D_value%100)/10];		
			D5 = tab_LED[D_value%10];		
		  }
	 }
		LED_DATA_Write(c,D5,D4,D3,D2,D1,D0);
}
/***********************************************************************/
void SETUP_LED_Disp(unsigned char SETUP_SELECT, unsigned int disp_value)
{
	unsigned char setup_status, D0, D1, D2, D3, D4, D5;
	unsigned int D_Value;
	
	  setup_status = SETUP_SELECT;
	  D_Value = disp_value;

	  if (setup_status == 0)		//PxxSET
	    { 
	       D0 =	tab_LED[17];
		   D1 = tab_LED[1] ;
		   D2 = tab_LED[18];
		   D3 =	tab_LED[18];
		   D4 =	tab_LED[12];
		   D5 =	tab_LED[18];
		}
      else if (setup_status == 1)		//Mode_TYPE	
	   { 
	   if(D_Value == 0)
	     { D0 =	tab_LED[17]; // TC
		   D1 = tab_LED[1] ;
		   D2 = tab_LED[18];
		   D3 =	tab_LED[18];
		   D4 =	tab_LED[12];
		   D5 =	tab_LED[18];
		 }
		if(D_Value == 1)
	     { D0 =	tab_LED[17];  //RTD
		   D1 = tab_LED[1] ;
		   D2 = tab_LED[18];
		   D3 =	tab_LED[18];
		   D4 =	tab_LED[15];
		   D5 =	tab_LED[18];
		 }
		 if(D_Value == 2)
	     { D0 =	tab_LED[17]; // mV
		   D1 = tab_LED[1] ;
		   D2 = tab_LED[18];
		   D3 =	tab_LED[18];
		   D4 =	tab_LED[12];
		   D5 =	tab_LED[18];
		  }
		if(D_Value == 3)
	     { D0 =	tab_LED[17]; // mA
		   D1 = tab_LED[1] ;
		   D2 = tab_LED[18];
		   D3 =	tab_LED[18];
		   D4 =	tab_LED[12];
		   D5 =	tab_LED[18];
		  }
	   }
    else if(setup_status == 2)
   	   {
		if(D_Value == 0)
	     { D0 =	tab_LED[17]; // DISP_C
		   D1 = tab_LED[1] ;
		   D2 = tab_LED[18];
		   D3 =	tab_LED[18];
		   D4 =	tab_LED[12];
		   D5 =	tab_LED[18];
		 }
		else if(D_Value == 1)
	     { D0 =	tab_LED[17];  //DISP_F
		   D1 = tab_LED[1] ;
		   D2 = tab_LED[18];
		   D3 =	tab_LED[18];
		   D4 =	tab_LED[15];
		   D5 =	tab_LED[18];
		 }
	  }
   else if (setup_status ==  3)		//TC_SELECT 
	  {
	   if(D_Value == 0)
	     { D0 =	tab_LED[17]; // K
		   D1 = tab_LED[1] ;
		   D2 = tab_LED[18];
		   D3 =	tab_LED[18];
		   D4 =	tab_LED[12];
		   D5 =	tab_LED[18];
		 }
		if(D_Value == 1)
	     { D0 =	tab_LED[17];  //J
		   D1 = tab_LED[1] ;
		   D2 = tab_LED[18];
		   D3 =	tab_LED[18];
		   D4 =	tab_LED[15];
		   D5 =	tab_LED[18];
		 }
		 if(D_Value == 2)
	     { D0 =	tab_LED[17]; // T
		   D1 = tab_LED[1] ;
		   D2 = tab_LED[18];
		   D3 =	tab_LED[18];
		   D4 =	tab_LED[12];
		   D5 =	tab_LED[18];
		  }
		if(D_Value == 3)
	     { D0 =	tab_LED[17]; // E
		   D1 = tab_LED[1] ;
		   D2 = tab_LED[18];
		   D3 =	tab_LED[18];
		   D4 =	tab_LED[12];
		   D5 =	tab_LED[18];
		  }
		if(D_Value == 4)
	     { D0 =	tab_LED[17]; // TC_R
		   D1 = tab_LED[1] ;
		   D2 = tab_LED[18];
		   D3 =	tab_LED[18];
		   D4 =	tab_LED[12];
		   D5 =	tab_LED[18];
		  }
		 if(D_Value == 5)
	     { D0 =	tab_LED[17]; // TC_S
		   D1 = tab_LED[1] ;
		   D2 = tab_LED[18];
		   D3 =	tab_LED[18];
		   D4 =	tab_LED[12];
		   D5 =	tab_LED[18];
		  }
		  if(D_Value == 6)
	     { D0 =	tab_LED[17]; // TC_B
		   D1 = tab_LED[1] ;
		   D2 = tab_LED[18];
		   D3 =	tab_LED[18];
		   D4 =	tab_LED[12];
		   D5 =	tab_LED[18];
		 }
		 if(D_Value == 7)
	     { D0 =	tab_LED[17]; // TC_N
		   D1 = tab_LED[1] ;
		   D2 = tab_LED[18];
		   D3 =	tab_LED[18];
		   D4 =	tab_LED[12];
		   D5 =	tab_LED[18];
		 }
	   }
    else if (setup_status ==  4)		//TC_Zero_offset
        {
 	       D0 = tab_LED[17];
	 	   D1 = tab_LED[2];
		}
	else if (setup_status ==  5)		//TC_Span_offset
        {
 	       D0 = tab_LED[17];
	 	   D1 = tab_LED[2];
		}
	else if (setup_status ==  6)		//RTD_Zero_offset
        {
 	       D0 = tab_LED[17];
	 	   D1 = tab_LED[2];
		}
    else if (setup_status ==  7)		//RTD_Span_offset
        {
 	       D0 = tab_LED[17];
	 	   D1 = tab_LED[2];
		}
	else if (setup_status ==  8)		//mV_Zero_offset
        {
 	       D0 = tab_LED[17];
	 	   D1 = tab_LED[2];
		}
	else if (setup_status ==  9)		//mV_Span_offset
        {
 	       D0 = tab_LED[17];
	 	   D1 = tab_LED[2];
		}
	else if (setup_status ==  10)		//mA_Zero_OFFSET
        {
 	       D0 = tab_LED[17];
	 	   D1 = tab_LED[2];
		}
	else if (setup_status ==  11)		//mA_Span_OFFSET
        {
 	       D0 = tab_LED[17];
	 	   D1 = tab_LED[2];
		}
	else if (setup_status ==  12)		//Alarm_ Lo_Set
        {
 	       D0 = tab_LED[17];
	 	   D1 = tab_LED[2];
		}
	else if (setup_status ==  13)		//Alarm_HI_set
        {
 	       D0 = tab_LED[17];
	 	   D1 = tab_LED[2];
		}
	else if (setup_status ==  14)		//Year_set
        {
 	       D0 = tab_LED[17];
	 	   D1 = tab_LED[2];
		}
	else if (setup_status ==  15)		//Mon_set
        {
 	       D0 = tab_LED[17];
	 	   D1 = tab_LED[2];
		}
	 else if (setup_status ==  16)		//Day_set
        {
 	       D0 = tab_LED[17];
	 	   D1 = tab_LED[2];
		}
	 else if (setup_status ==  17)		//Hour_set
        {
 	       D0 = tab_LED[17];
	 	   D1 = tab_LED[2];
		}
	 
	 else if (setup_status ==  19)		//RESET_ ALL
        {
 	       D0 = tab_LED[17];
	 	   D1 = tab_LED[2];
  	    }
     if (D_Value >= 0  && D_Value < 10)		//   Show Value 99999
	   {
			D2 = tab_LED[18];
		    D3 = tab_LED[18];
			D4 = Point_tab_LED[0];
			D5 = tab_LED[D_Value%10];
		}
		if (D_Value >= 10 && D_Value < 100)
	   	  { 
			D2 = tab_LED[18];
		    D3 = tab_LED[18];
			D4 = Point_tab_LED[D_Value/10];
			D5 = tab_LED[D_Value%10];
		  }
	    if (D_Value >=100 && D_Value < 1000)
	   	  {
			D2 = tab_LED[18];
			D3 = tab_LED[D_Value/100]; //987 
			D4 = Point_tab_LED[(D_Value%100)/10];
			D5 = tab_LED[D_Value%10];
		  }
	    if (D_Value >=1000 && D_Value < 10000)
	   	  {
			D2 = tab_LED[D_Value/1000];	//9876
		    D3 = tab_LED[(D_Value%1000)/100];
			D4 = Point_tab_LED[(D_Value%100)/10];
			D5 = tab_LED[D_Value%10];
		  }
		if (D_Value >= 10000 && D_Value < 100000)
	   	  {
		    D1 = tab_LED[D_Value/10000];   //98765
			D2 = tab_LED[(D_Value%10000)/1000];	
		    D3 = tab_LED[(D_Value%1000)/100];   
			D4 = Point_tab_LED[(D_Value%100)/10];		
			D5 = tab_LED[D_Value%10];		
		  }
	 LED_DATA_Write(1,D5,D4,D3,D2,D1,D0);
	 LED_DATA_Write(2,D5,D4,D3,D2,D1,D0);
}
// ITEM              0
// MODE_CAL          1
// C_F_CAL           2
// TYPE_CAL          3
// TC_ZERO_CAL       4
// TC_SPAN_CAL       5
// RTD_ZERO_CAL      6
// RTD_SPAN_CAL      7
// mV_ZERO_CAL       8
// mV_SPAN_CAL       9
// mA_ZERO_CAL       10
// mA_SPAN_CAL       11
// ALARM_LO_CAL      12
// ALARM_HI_CAL      13
// YEAR_DATE_CAL     14
// MON_DATE_CAL      15
// DAY_DATE_CAL      16
// HOUR_DATE_CAL     17
// MIN_DATE_CAL      18
// PRODUCT_RESET     19
// NOMAL_FUNCTION    0
/************************************************/
void LED_Fill(void)
{
   unsigned char D0,D1,D2,D3,D4,D5;

            D0 = Point_tab_LED[8];
	 	    D1 = Point_tab_LED[8];
			D2 = Point_tab_LED[8];	
		    D3 = Point_tab_LED[8];   
			D4 = Point_tab_LED[8];		
			D5 = Point_tab_LED[8];		

	    LED_DATA_Write(1,D5,D4,D3,D2,D1,D0);
	    LED_DATA_Write(2,D5,D4,D3,D2,D1,D0);

}
/*********************************************************/
void _BitDly(void)               // wait 4.7uS, or thereabouts
{                                   // tune to xtal. This works at 11.0592MHz
	unsigned char	i;
	
	for (i=0; i<0x12; i++);
}
/*********************************/
void LED_Init(void)
{
	unsigned int i;
 
 	LED1_OE  = 1;
	LED2_OE  = 1;
	LED2_SCL = 0;
	LED1_SDA = 0;
	LED1_SCL = 0;
	LED2_SDA = 0;

	_BitDly();
	_BitDly();
	_BitDly();
	_BitDly();

	for(i = 0; i < 0x100; i++);   
}
/***********************************/
void LED_Cls(void)
{
	LED_Disp(1,0);
	LED_Disp(2,0);
}
/**********************************/
void  LED_DATA_Write(unsigned char prt,unsigned char D5,unsigned char D4,unsigned char D3,unsigned char D2,unsigned char D1,unsigned char D0)
{
    unsigned char c, DISP_CODE, D_count, D_time = 6;
 		            c = prt;  DISP_CODE = D0 ;
	  if (c == 1)
	    {
		   LED1_OE = 1 ;		// off led
		   if(D_time != 0)
		     {
			    D_count =  8;
		        LED1_SCL = 0;
				
			   if(D_count != 0)
			     {
		           if(DISP_CODE & 0x80) {LED1_SDA = 1;}		  //d7 - d0
		             _BitDly();
 		             LED1_SCL = 1 ;
			         _BitDly();
		  	  	     LED1_SCL = 0;
					 LED1_SDA = 0;
				     DISP_CODE = DISP_CODE << 1;
				     D_count--;
			     }
     			 D_time--;
				 if (D_time  == 5)  DISP_CODE = D1;
				 if (D_time  == 4)  DISP_CODE = D2;
				 if (D_time  == 3)  DISP_CODE = D3;
				 if (D_time  == 2)  DISP_CODE = D4;
				 if (D_time  == 1)  DISP_CODE = D5;
			   }
			   LED1_OE  = 0 ;	   //on led
         }
	    if(c == 2)
	     {
		      LED2_OE = 1;

		   if(D_time != 0)
		     {
			    D_count =  8;
		        LED2_SCL = 0;

			   if(D_count != 0)
			     {
		           if(DISP_CODE & 0x80) {LED2_SDA = 1;}
		             _BitDly();
 		             LED2_SCL = 1 ;
			         _BitDly();
		  	  	     LED2_SCL = 0;
					 LED2_SDA = 0;
				     DISP_CODE = DISP_CODE << 1;
				     D_count--;
			     }
     			 D_time--;
				 if (D_time  == 5)  DISP_CODE = D1;
				 if (D_time  == 4)  DISP_CODE = D2;
				 if (D_time  == 3)  DISP_CODE = D3;
				 if (D_time  == 2)  DISP_CODE = D4;
				 if (D_time  == 1)  DISP_CODE = D5;
			   }
			LED2_OE = 0;
        }
	
 }
