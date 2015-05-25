/*******************************************
          TC SLOPE AND RTD SLOPE

  用 K_type 做基礎校正歸零及最高基準校正
  放大倍數採最大輸入電壓 E TYPE 為最大倍數
  使精度為 0.1F/COUNT  G=53
  131072/65536
K_TYPE	0	//2466F //54.807mV	//24660 COUNT // 2.9431V
J_TYPE	1	//1368F //42.922mV	//13680 COUNT // 2.3049V
T_TYPE  2	//360F  //9.286mV	//3600  COUNT // 0.49866V
E_TYPE	3	//1440F //61.022mV	//14400 COUNT // 3.2768
R_TYPE	4	//2880F //18.842mV	//28800 COUNT //
S_TYPE	5	//2880F //16.771mV	//28800 COUNT //
B_TYPE	6	//3240F //13.585mV	//32400 COUNT //

    MCP 3421(18BITS ADC) READ ONLY
    FOR Value_read
    Count = 131071 ( Vin -(-Vin))/2.048V
******************************************/
#include <MG82FE564.H>
#include<TYPE_SLOPE.h>
#include <IO_DEFINE.h>
/**********************************/
#define	K_TYPE		0		//2466F   54.807mV	P0=0x00
#define	J_TYPE		1		//1368F   42.922mV
#define	T_TYPE   	2		//360F    9.286mV
#define	E_TYPE		3		//1440F   61.022mV
#define	R_TYPE		4		//2880F   18.842mV
#define	S_TYPE		5		//2880F   16.771mV
#define	B_TYPE		6		//3240F   13.585mV
#define	N_TYPE	    7		//?       ? 

unsigned char AV_COD = 0;
unsigned char NG_COD = 0;
unsigned char NP_COD = 0;
unsigned char ng_flog = 0;
unsigned int VA_TEST ;
xdata unsigned char K_Slope[10] = {0,36,48,56,64,76,88,104,120,200};
xdata unsigned char J_Slope[9] = {0,32,40,48,52,112,160,200,255};//32//40//48//52//256//112
xdata unsigned char T_Slope[10] = {7,8,10,16,24,32,48,56,64,72}; //8/10/16/24/48/56/64/72
xdata unsigned char E_Slope[11] = {0,16,32,40,48,56,64,96,104,148,255}; //16 32	40	48	56	64 96 104 256 148
xdata unsigned char R_Slope[11] = {0,16,32,40,48,56,64,96,104,148,255};
xdata unsigned char S_Slope[11] = {0,16,32,40,48,56,64,96,104,148,255};
xdata unsigned char B_Slope[11] = {0,16,32,40,48,56,64,96,104,148,255};
xdata unsigned char N_Slope[11] = {0,16,32,40,48,56,64,96,104,148,255};
xdata unsigned char RTD_Slope[11] = {0,16,32,40,48,56,64,96,104,148,255};
/***********************************************
     K_TYPE 2466F   54.807mV	P0=0x00
************************************************/
unsigned int Get_K_Slope(unsigned long int Code_Value) 
{
   unsigned int out_Value;
//   unsigned int reg_Value;

			Code_Value = 320 + Code_Value/2.21;

			VA_TEST = Code_Value ;

	   	    out_Value = Code_Value;	

	 if(Code_Value > 760)  	//1203	 
	   {
	    out_Value = out_Value-(Code_Value-700)/K_Slope[1] ;  //ok
	   }
	  if(Code_Value > 1350)		//860 2436
	   {
	    out_Value = out_Value-(Code_Value-1250)/K_Slope[5] ;//
	   }
	 if(Code_Value > 2450)	  //1400
	   {	
	   out_Value =out_Value+(Code_Value-2350)/K_Slope[3] ; //
	   }
	 if(Code_Value > 3268)	 //2480
	   {
	   out_Value =out_Value+(Code_Value-3150)/K_Slope[2];
	   }
	 if(Code_Value > 4200)	 //3200
	   {
	   out_Value =out_Value-(Code_Value-4100)/K_Slope[6];
	   }
	 if(Code_Value > 4950)   //4460
	   {
	   out_Value =out_Value-(Code_Value-4800)/K_Slope[4]; 
	   }
	 if(Code_Value > 5500)   //4460
	   {
	   out_Value =out_Value-(Code_Value-5450)/K_Slope[6];
	   }
   	 if(Code_Value > 6586)   //5360 
	   {
	   out_Value =out_Value-(Code_Value-6460)/K_Slope[5];  //
	   }
	 if(Code_Value > 7680)  //6260 
	   {
	   out_Value =out_Value-(Code_Value-7600)/K_Slope[8];
	   }
	 if(Code_Value > 9343)  //7520  
	   {
	   out_Value =out_Value-(Code_Value-9220)/K_Slope[9];
	   }
	 if(Code_Value > 11120) //9140 
	   {
	   out_Value =out_Value+(Code_Value-11030)/K_Slope[9];
	   }
	 if(Code_Value > 12310) //9140 
	   {
	   out_Value =out_Value+(Code_Value-12240)/K_Slope[10];
	   }
     if(Code_Value > 12860)	//11480
	   {
	   out_Value =out_Value+(Code_Value-12680)/K_Slope[8]; 
	   }
	 if(Code_Value > 13780)	 //12920
	   {
	   out_Value =out_Value+(Code_Value-13540)/K_Slope[8];
	   }
	 if(Code_Value > 14330)	 //12920
	   {
	   out_Value =out_Value+(Code_Value-14300)/K_Slope[9];
	   }
	 if(Code_Value > 15050)	  //14000
	   {
	   out_Value =out_Value+(Code_Value-14900)/K_Slope[7];																																					
	   }
	 if(Code_Value > 15850)	  //14000
	   {
	   out_Value =out_Value+(Code_Value-15660)/K_Slope[6];																																					
	   }
	 if(Code_Value > 16704)	   //14900
	   {
	   out_Value =out_Value+(Code_Value-16580)/K_Slope[6];
	   }
	 if(Code_Value > 17480)	 //15980																															
	   {
	   out_Value =out_Value+(Code_Value-17280)/K_Slope[6];
	   }
	 if(Code_Value > 18250)	 //17240
	   {
	   out_Value =out_Value+(Code_Value-18100)/K_Slope[5];
	   }
	 if(Code_Value > 19246)	//18140
	   {
	   out_Value =out_Value+(Code_Value-19160)/K_Slope[4];
	   }
   	 if(Code_Value > 20126)	 //19220
	   {
	   out_Value =out_Value+(Code_Value-20100)/K_Slope[6];
	   }
	 if(Code_Value > 20810)	//20300
	   {
	   out_Value =out_Value+(Code_Value-20740)/K_Slope[2]; 
	   }
	 if(Code_Value > 21810)	//20300
	   {
	   out_Value =out_Value+(Code_Value-21760)/K_Slope[3]; 
	   }
	 if(Code_Value > 22570)	  //21200
	   {
	   out_Value =out_Value+(Code_Value-22480)/K_Slope[3];
	   }
	 if(Code_Value > 23020)	  //22100
	   {
	   out_Value =out_Value+(Code_Value-22840)/K_Slope[5];
	   }
	 if(Code_Value > 23556)	  // 22820
	   {
	   out_Value =out_Value+(Code_Value-23440)/K_Slope[2];//
	   }
	 if(Code_Value > 24350)	   //23360
	   {
	   out_Value =out_Value+(Code_Value-24300)/K_Slope[3];
	   }
	 if(Code_Value > 24560)	   //24080
	   {
	   out_Value =out_Value+(Code_Value-24420)/K_Slope[3];
	   }
	   if(Code_Value > 25000)	   //24080
	   {
	   out_Value =out_Value-(Code_Value-24860)/K_Slope[4];
	   }
	      return out_Value;					  // 20240 2530	  920 176
}
/**********************************************
     J_TYPE	1368F 42.922mV P0=0X01
***********************************************/
unsigned int Get_J_Slope(unsigned long int Code_Value)  
{
   unsigned int out_Value;
		
		Code_Value = 320 + Code_Value/2.82;
	
		VA_TEST = Code_Value ;

	   out_Value = Code_Value;	

	 if(Code_Value > 854) 	//864
	   {
	   out_Value =out_Value-(Code_Value-730)/J_Slope[1] ;
	   }
	 if(Code_Value > 1340) 	//864
	   {
	   out_Value =out_Value-(Code_Value-1250)/J_Slope[3] ;
	   }      
	 if(Code_Value > 1610) //
	   {
	   out_Value =out_Value-(Code_Value-1530)/J_Slope[6] ;
	   }
	 if(Code_Value > 2445)
	   {
	   out_Value =out_Value-(Code_Value-2330)/J_Slope[4] ;
	   }
     if(Code_Value > 3698)
	   {
	   out_Value =out_Value-(Code_Value-3550)/J_Slope[5] ;
	   }
	   if(Code_Value > 5668)
	   {
	   out_Value = out_Value + (Code_Value-5450)/J_Slope[7] ; 
	   }
	 if(Code_Value > 7260) 
	   {
	   out_Value =out_Value + (Code_Value-7160)/J_Slope[8] ;
	   }
	 if(Code_Value > 8430)
	   {
	   out_Value =out_Value-(Code_Value-8260)/J_Slope[6] ;
	   }
	   if(Code_Value > 9550)
	   {
	   out_Value =out_Value-(Code_Value-9450)/J_Slope[5];
	   }
	 if(Code_Value > 10550)
	   {
	   out_Value =out_Value-(Code_Value-10470)/J_Slope[5];
	   }
	 if(Code_Value > 10950) 
	   {
	   out_Value =out_Value-(Code_Value-10850)/J_Slope[5];
	   }
	   if(Code_Value > 11550) 
	   {
	   out_Value =out_Value-(Code_Value-11480)/J_Slope[4];
	   }
	 if(Code_Value > 12355) 
	   {
	   out_Value =out_Value-(Code_Value-12240)/J_Slope[4];
	   }
	 if(Code_Value > 13193)
	   {
	   out_Value =out_Value-(Code_Value-13050)/J_Slope[4];	
	   }
	 if(Code_Value > 14050)
	   {
	   out_Value =out_Value-(Code_Value-13950)/J_Slope[3] ;	
	   }
 	 if(Code_Value > 14920) 
	   {
	   out_Value =out_Value-(Code_Value-14750)/J_Slope[5] ;	 //3
	   }
   return out_Value;

}
/**********************************************
     T_TYPE   	2		//360F    9.286mV
***********************************************/
unsigned int Get_T_Slope(unsigned long int Code_Value) 
{
   unsigned int outlo_Value;
   unsigned int outhi_Value;
   unsigned int out_Value;
   unsigned int neg_Value;

   		out_Value =  Code_Value ;
		outhi_Value =  Code_Value >> 16 ;

   if (outhi_Value != 0 )
	 {
	  NP_COD = 1;
		out_Value = ~out_Value;

	 	outlo_Value = out_Value ; 

		  if(out_Value <= 694)  
		    {
		      outlo_Value =320-(out_Value/2.17);

			  outlo_Value = outlo_Value-(231-outlo_Value)/24;
			  neg_Value = outlo_Value;
			  ng_flog = 1;

			   AV_COD = 0;
			}   		 
		  else
		    {
		     outlo_Value =(out_Value/2.17)-320;

			 outlo_Value = outlo_Value+(outlo_Value+231)/24;
			 ng_flog = 0;

			 AV_COD = 1;
 	    	}
 	  	
	   if((outlo_Value >110)&&(ng_flog == 0)) 
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
		outlo_Value =outlo_Value+(outlo_Value-1300)/T_Slope[5];
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
		outlo_Value =outlo_Value+(outlo_Value-1900)/T_Slope[3];
	    }
	   if((outlo_Value > 2180)&&(ng_flog == 0))
	    {
	     outlo_Value =outlo_Value+(outlo_Value-2160)/T_Slope[3];
	    }
	  if((outlo_Value > 2280)&&(ng_flog == 0))
	    {
	     outlo_Value =outlo_Value+(outlo_Value-2270)/T_Slope[3];
	    }
	  if((outlo_Value > 2550)&&(ng_flog == 0))
	    {
	     outlo_Value =outlo_Value+(outlo_Value-2520)/T_Slope[5];
	    }
	  if((outlo_Value > 2720)&&(ng_flog == 0))
	    {
	     outlo_Value =outlo_Value+(outlo_Value-2600)/T_Slope[3];
	    }
	  if((outlo_Value > 2890)&&(ng_flog == 0))
	    {
	     outlo_Value =outlo_Value+(outlo_Value-2850)/T_Slope[2]; 
	    }
	  if((outlo_Value > 2970)&&(ng_flog == 0))
	    {
	     outlo_Value =outlo_Value+(outlo_Value-2840)/T_Slope[6]; 
	    }
	  if((outlo_Value > 3150)&&(ng_flog == 0))
	    {
	     outlo_Value =outlo_Value+(outlo_Value-3130)/T_Slope[2];//
	    }
	  if(outlo_Value > 5000) outlo_Value = 0;
	}	
   else
    {
	 if ((outhi_Value == 0) && (out_Value <= 11000))
	   {
	      AV_COD = 0;
		  NP_COD = 0;
		  outlo_Value = out_Value ;

	     outlo_Value = 320 + out_Value/2.18;

	     if(outlo_Value > 680)
	      {
	       outlo_Value =outlo_Value-(outlo_Value-610)/T_Slope[5] ;
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
		 if(outlo_Value > 11000) outlo_Value = 0;
	  }
   }
 	      return outlo_Value;
}
/***********************************************
             E_Slope
************************************************/
unsigned int Get_E_Slope(unsigned long int Code_Value)
{
   unsigned int out_Value;

		Code_Value = 320 + Code_Value/2.82;
	
		VA_TEST = Code_Value ;

	   out_Value = Code_Value;	

	 if(Code_Value > 684)
	   {
	    out_Value = Code_Value ;										  
	   }
	 if(Code_Value  > 1058)
	   { 
	   out_Value = out_Value-(Code_Value-560)/E_Slope[6] ; 
	   }    
	 if(Code_Value  > 1443)
	   { 
	   out_Value = out_Value-(Code_Value-780)/E_Slope[6] ; 
	   }
	 if(Code_Value > 2042)
	   {
	   out_Value = out_Value-(Code_Value-1390)/E_Slope[6];
	   }
	 if(Code_Value  > 2250)
	   {
	   out_Value = out_Value-(Code_Value-1390)/E_Slope[6];
	   }
	 if(Code_Value  > 3250)
	   {
	   out_Value = out_Value-(Code_Value-1390)/E_Slope[6];
	   }
	 if(Code_Value > 4100)
	   {
	   out_Value = out_Value-(Code_Value-1390)/E_Slope[6];
	   }
	 if(Code_Value > 5300)
	   {
	   out_Value = out_Value-(Code_Value-1390)/E_Slope[6];
	   }
	 if(Code_Value > 6750)
	  {
	  out_Value = out_Value-(Code_Value-1390)/E_Slope[6];
	   }
	 if(Code_Value > 7800)
	   {
	   out_Value = out_Value-(Code_Value-1390)/E_Slope[6];
	   }
	 if(Code_Value > 9100)
	   {
	   out_Value = out_Value-(Code_Value-1390)/E_Slope[6];
	   }
	 if(Code_Value > 11400)
	   {
	   out_Value = out_Value-(Code_Value-1390)/E_Slope[6];
	   }
	 if(Code_Value > 14500)
	   {
	   out_Value = out_Value-(Code_Value-1390)/E_Slope[6];				   
	   }
	 if(Code_Value > 16700)
	   {
	   out_Value = out_Value-(Code_Value-1390)/E_Slope[6];
	   }
	 if(Code_Value > 17600)
	   {
	   out_Value = out_Value-(Code_Value-1390)/E_Slope[6];
	   }
	 if(Code_Value > 18000)
	   {
	    out_Value =out_Value-(Code_Value-3870)/E_Slope[6] ;
	   }
   return out_Value;

}
/**********************************************
       R_Slope
***********************************************/
unsigned int Get_R_Slope(unsigned long int Code_Value)
{
   unsigned int out_Value;

		Code_Value = 320 + Code_Value/2.82;
	
		VA_TEST = Code_Value ;

	   out_Value = Code_Value;

	 if(Code_Value > 580)
	   {
		out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	 if(Code_Value > 1040)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }    
     if(Code_Value > 1360)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
      if(Code_Value > 1920)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	if(Code_Value > 2320)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	 if(Code_Value > 2900)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	 if(Code_Value > 3600)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	 if(Code_Value > 5460)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	 if(Code_Value > 6400)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	 if(Code_Value > 7500)
	   {
		out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	 if(Code_Value > 8500)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	 if(Code_Value > 9900)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
       if(Code_Value > 11100)
	   {
		out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	 if(Code_Value > 12100)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	 if(Code_Value >13100)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	 if(Code_Value > 14600)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	 if(Code_Value > 16200)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	 if(Code_Value > 17200)
	   {
	  out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	 if(Code_Value > 19100)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
     if(Code_Value > 21100)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	 if(Code_Value > 22600)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	if(Code_Value > 24500)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	 if(Code_Value > 26600)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	 if(Code_Value > 28600)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	 if(Code_Value > 31000)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	if(Code_Value >33400)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	if(Code_Value > 36600)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	 if(Code_Value > 39700)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	 if(Code_Value > 43800)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	 if(Code_Value > 48700)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	 if(Code_Value > 59300)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
	 if(Code_Value > 62000)
	   {
	   out_Value =out_Value-(Code_Value-3870)/R_Slope[6] ;
	   }
   return out_Value;

}
/***********************************************
               S_Slope
*************************************************/
unsigned int Get_S_Slope(unsigned long int Code_Value)
{
   unsigned int out_Value;
		Code_Value = 320 + Code_Value/2.82;
	
		VA_TEST = Code_Value ;

	   out_Value = Code_Value;

	 if(Code_Value >= 610)
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;
	   }
	 if(Code_Value >= 1000)
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;
	   }
	 if(Code_Value >= 1420)
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;
	   }
     if(Code_Value >= 1860)  
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;
	   }
	 if(Code_Value >= 2480)	
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;
	   }
	 if(Code_Value >= 3280)
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;
	   }
	 if(Code_Value >= 4300)
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;
	   }
	 if(Code_Value >= 5400) 
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;
	   }
	 if(Code_Value >= 6600) 
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;
	   }
	 if(Code_Value >= 8100)
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;
	   }
	 if(Code_Value >= 9550)
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;
	   }
	 if(Code_Value >= 11600) 
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;
	   }									 
	 if(Code_Value >= 13800) 
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;
	   }
	 if(Code_Value >= 16500) 
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;
	   }
	 if(Code_Value >= 18500)
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;
	   }
	 if(Code_Value >= 20450)
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;
	   }
	 if(Code_Value >= 22700)
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;
	   }
	 if(Code_Value >= 25200)
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;
	   }
	 if(Code_Value >= 27500)
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;
	   }
	 if(Code_Value >= 30300) 
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;
	   }
	 if(Code_Value >= 33200)
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;
	   }
	 if(Code_Value >= 36300)
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;
	   }
	 if(Code_Value >= 39700) 
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;								  
	   }
	 if(Code_Value >= 50800) 
	   {
	   out_Value =out_Value-(Code_Value-3870)/S_Slope[6] ;
	   }
   return out_Value;

}
/***********************************************

************************************************/
unsigned int Get_B_Slope(unsigned long int Code_Value)
{
   unsigned int out_Value;

 		Code_Value = 320 + Code_Value/2.82;
	
		VA_TEST = Code_Value ;

	   out_Value = Code_Value;


	 if((Code_Value > 1000) && (Code_Value < 2000))
	   {
	   out_Value =out_Value-(Code_Value-3870)/B_Slope[6] ;
	   }
	 if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   out_Value =out_Value-(Code_Value-3870)/B_Slope[6] ;
	   }    
	 if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   out_Value =out_Value-(Code_Value-3870)/B_Slope[6] ;
	   }
	 if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   out_Value =out_Value-(Code_Value-3870)/B_Slope[6] ;
	   }
	 if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   out_Value =out_Value-(Code_Value-3870)/B_Slope[6] ;
	   }
	 if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   out_Value =out_Value-(Code_Value-3870)/B_Slope[6] ;
	   }
	 if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   out_Value =out_Value-(Code_Value-3870)/B_Slope[6] ;
	   }
	 if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   out_Value =out_Value-(Code_Value-3870)/B_Slope[6] ;
	   }
	 if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   out_Value =out_Value-(Code_Value-3870)/B_Slope[6] ;
	   }

	 if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   out_Value =out_Value-(Code_Value-3870)/B_Slope[6] ;
	   }

   return out_Value;

}
/***********************************************
	 N_Slope
************************************************/
unsigned int Get_N_Slope(unsigned long int Code_Value)
{
   unsigned int out_Value;

		Code_Value = 320 + Code_Value/2.82;
	
		VA_TEST = Code_Value ;

	   out_Value = Code_Value;

	 if((Code_Value > 1000) && (Code_Value < 2000))
	   {
	   out_Value =out_Value-(Code_Value-3870)/N_Slope[6] ;
	   }
	 if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   out_Value =out_Value-(Code_Value-3870)/N_Slope[6] ;
	   }    
	 if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   out_Value =out_Value-(Code_Value-3870)/N_Slope[6] ;
	   }
	 if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   out_Value =out_Value-(Code_Value-3870)/N_Slope[6] ;
	   }
	 if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   out_Value =out_Value-(Code_Value-3870)/N_Slope[6] ;
	   }
	 if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   out_Value =out_Value-(Code_Value-3870)/N_Slope[6] ;
	   }
	 if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   out_Value =out_Value-(Code_Value-3870)/N_Slope[6] ;
	   }
	 if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   out_Value =out_Value-(Code_Value-3870)/N_Slope[6] ;
	   }
	 if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   out_Value =out_Value-(Code_Value-3870)/N_Slope[6] ;
	   }
	 if((Code_Value > 2000) && (Code_Value < 3000))
	   {
	   out_Value =out_Value-(Code_Value-3870)/N_Slope[6] ;
	   }

   return out_Value;

}

/*****************************************************
       RTD_SLOPE
******************************************************/
unsigned int Get_RTD_Slope(unsigned long int Code_Value) 
{
   unsigned int RTD_Value;

   unsigned int out_Value;
		Code_Value = 320 + Code_Value/2.82;
	
		VA_TEST = Code_Value ;

	   out_Value = Code_Value;	
	   	
	   		RTD_Value = Code_Value;											
	 if((RTD_Value >= 3200) && (RTD_Value < 2600))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   }
	else if((RTD_Value >= 2600) && (RTD_Value <1950))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   }    
	else if((RTD_Value >= 1950) && (RTD_Value < 950))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   } 
	else if((RTD_Value >= 950) && (RTD_Value < 40))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   } 
	else if((RTD_Value >= 40) && (RTD_Value < 0))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   } 
	else if((RTD_Value >= 0) && (RTD_Value < 1300))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   } 
	else if((RTD_Value >= 1300) && (RTD_Value < 2200))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   } 
	else if((RTD_Value >= 2200) && (RTD_Value < 3250))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   } 
	else if((RTD_Value >= 3250) && (RTD_Value < 4100))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   } 
	else if((RTD_Value >= 4100) && (RTD_Value < 5000))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   } 
	else if((RTD_Value >= 5000) && (RTD_Value < 5750))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   } 
	else if((RTD_Value >= 5750) && (RTD_Value < 6450))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   } 
	else if((RTD_Value >= 6450) && (RTD_Value < 7350))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   } 
	else if((RTD_Value >= 7350) && (RTD_Value < 7950))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   } 
	else if((RTD_Value >= 7950) && (RTD_Value < 8700))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   } 
	else if((RTD_Value >= 8700) && (RTD_Value < 9300))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   } 
	else if((RTD_Value >= 9300) && (RTD_Value < 9900))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   } 
	else if((RTD_Value >= 9900) && (RTD_Value < 10500))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   } 
	else if((RTD_Value >= 10500) && (RTD_Value < 11500))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   } 
	else if((RTD_Value >= 11500) && (RTD_Value < 11700))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   } 
	else if((RTD_Value >= 11700) && (RTD_Value < 12300))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   } 
	else if((RTD_Value >= 12300) && (RTD_Value <12850))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   } 
	else if((RTD_Value >= 12850) && (RTD_Value < 13400))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   }
	else if((RTD_Value >= 13400) && (RTD_Value < 13600))
	   {
	   out_Value =out_Value-(Code_Value-3870)/T_Slope[6] ;
	   }
	   return RTD_Value ;
}