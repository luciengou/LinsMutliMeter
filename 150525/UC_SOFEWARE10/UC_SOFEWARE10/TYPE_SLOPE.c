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
unsigned char NP_COD = 0;
//unsigned char NG_COD ;
unsigned char ng_flog = 0;
xdata unsigned char K_Slope[11] = {0,36,48,56,64,76,88,104,120,200,250};
xdata unsigned char J_Slope[9] = {0,32,40,48,52,112,160,200,255};//32//40//48//52//256//112
xdata unsigned char T_Slope[10] = {7,8,10,16,24,32,48,56,64,72}; //8/10/16/24/48/56/64/72
xdata unsigned char E_Slope[12] = {0,16,32,40,48,56,64,96,108,128,180,225}; //16 32	40	48	56	64 96 104 256 148
xdata unsigned char R_Slope[16] = {0,10,14,19,20,22,27,35,38,42,52,60,64,70,80,106};

xdata unsigned char S_Slope[16] = {10,13,16,18,28,32,40,52,55,57,59,64,66,90,132,250};
//xdata unsigned char B_Slope[11] = {0,16,32,40,48,56,64,96,108,128,255};
//xdata unsigned char N_Slope[11] = {0,16,32,40,48,56,64,96,108,128,255};
xdata unsigned char RTD_Slope[8] = {0,44,46,50,54,58,62,77};
/***********************************************
     K_TYPE 2466F   54.807mV	P0=0x00
************************************************/
unsigned int Get_K_Slope(unsigned int Code_Value) 
{
   unsigned int out_Value;

	   NP_COD = 0;
     if ( AV_COD == 1 )
	  {
		  if(Code_Value <= 736)   //791
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
	     if((Code_Value > 760)&&(ng_flog == 0))  	//1203	 760
	      {
	         out_Value = out_Value + (Code_Value-730)/K_Slope[6] ;  
	      }
	     if((Code_Value > 2000)&&(ng_flog == 0))		//860 2436
	      {
	        out_Value = out_Value+(Code_Value-1950)/K_Slope[8] ;
		  }
	   }
	else
	  {
			out_Value = 320 + Code_Value/2.32;	//2.21

	 if(Code_Value > 760)  	//1203	 760
	   {
	    out_Value = out_Value-(Code_Value-730)/K_Slope[6] ;  
	   }
	  if(Code_Value > 2000)		//860 2436
	   {
	    out_Value = out_Value-(Code_Value-1950)/K_Slope[8] ;
	   }
	 if(Code_Value > 3168)	 //2480
	   {
	   out_Value =out_Value+(Code_Value-3150)/K_Slope[8];
	   }
	 if(Code_Value > 3550)   //4460
	   {
	   out_Value =out_Value-(Code_Value-3500)/K_Slope[8]; 
	   }
   	 if(Code_Value > 4850)   //5360 
	   {
	   out_Value =out_Value+(Code_Value-4800)/K_Slope[7];  //
	   }
	 if(Code_Value > 6980)  //6260 
	   {
	   out_Value =out_Value+(Code_Value-6900)/K_Slope[8];
	   }
	 if(Code_Value > 9343)  //7520  
	   {
	   out_Value =out_Value-(Code_Value-9220)/K_Slope[9];
	   }
	 if(Code_Value > 10420) //9140 
	   {
	   out_Value =out_Value-(Code_Value-10360)/K_Slope[8];
	   }
	 if(Code_Value > 12540) //9140 
	   {
	   out_Value =out_Value-(Code_Value-12500)/K_Slope[9];
	   }
     if(Code_Value >14250)
	   {
	   out_Value = out_Value-(Code_Value-14200)/K_Slope[10];																																					
	   }

	 if(Code_Value > 16800)	   //14900
	   {
	   out_Value =out_Value-(Code_Value-16750)/K_Slope[10];
	   }
	 if(Code_Value > 18250)	//18140
	   {
	   out_Value =out_Value+(Code_Value-18200)/K_Slope[10];
	   }
   	 if(Code_Value > 19450)	 //19220
	   {
	   out_Value =out_Value-(Code_Value-19400)/K_Slope[9];
	   }
	 if(Code_Value > 21450)	//20300
	   {
	   out_Value =out_Value-(Code_Value-21400)/K_Slope[10]; 
	   }
	 if(Code_Value > 22920)	  //22100
	   {
	   out_Value =out_Value+(Code_Value-22840)/K_Slope[9];
	   }
	 if(Code_Value > 25350)	   //23360
	   {
	   out_Value =out_Value-(Code_Value-25300)/K_Slope[10];
	   }
	 if(Code_Value > 26860)	   //24080
	   {
	   out_Value =out_Value+(Code_Value-26800)/K_Slope[9];
	   }
	 if(Code_Value > 28760)	   //24080
	   {
	   out_Value =out_Value+(Code_Value-28500)/K_Slope[10];
	   }
	   if(Code_Value > 30300)	   //24080
	   {
	   out_Value =out_Value-(Code_Value-30200)/K_Slope[10];
	   }
	   if(Code_Value > 31350)	   //24080
	   {
	   out_Value =out_Value+(Code_Value-31250)/K_Slope[8];
	   }
	   if(Code_Value > 33950)	   //24080
	   {
	   out_Value =out_Value+(Code_Value-33900)/K_Slope[10];
	   }
	   if(Code_Value > 35950)	   //24080
	   {
	   out_Value =out_Value+(Code_Value-35900)/K_Slope[9];
	   }
	   if(Code_Value > 37050)	   //24080
	   {
	   out_Value =out_Value+(Code_Value-37000)/K_Slope[10];
	   }
	   if(Code_Value > 39150)	   //24080
	   {
	   out_Value =out_Value+(Code_Value-39100)/K_Slope[10];
	   }
	   if(Code_Value > 40550)	   //24080
	   {
	   out_Value =out_Value+(Code_Value-40500)/K_Slope[10];
	   } 
	   if(Code_Value > 42150)	   //24080
	   {
	   out_Value =out_Value+(Code_Value-42000)/K_Slope[10];
	   }
	   if(Code_Value > 43450)	   //24080
	   {
	   out_Value =out_Value+(Code_Value-43400)/K_Slope[10];
	   }
	   if(Code_Value > 44950)	   //24080
	   {
	   out_Value =out_Value+(Code_Value-44800)/K_Slope[9];
	   }
	   if(Code_Value > 46650)	   //24080
	   {
	   out_Value =out_Value+(Code_Value-46600)/K_Slope[9];
	   }
	   if(Code_Value > 48250)	   //24080
	   {
	   out_Value =out_Value+(Code_Value-48200)/K_Slope[8];
	   }
	   if(Code_Value > 50650)	   //24080
	   {
	   out_Value =out_Value+(Code_Value-50600)/K_Slope[7];
	   }
	   if(Code_Value > 52550)	   //24080
	   {
	   out_Value =out_Value+(Code_Value-52500)/K_Slope[7];
	   }
	   if(Code_Value > 53550)	   //24080
	   {
       out_Value =out_Value+(Code_Value-53500)/K_Slope[9];
	   }
	   if(Code_Value > 55050)	   //24080
	   {
       out_Value =out_Value+(Code_Value-55000)/K_Slope[7];
	   }
	   if(Code_Value > 56350)	   //24080
	   {
       out_Value =out_Value+(Code_Value-56300)/K_Slope[8];
	   }
	   if(Code_Value > 61000)	   //24080
	   {
       out_Value = 65535;
	   }	   	   	   	   	   	   	   	   	   	   	    
   }
      
	      return out_Value;					  // 20240 2530	  920 176
}
/**********************************************
     J_TYPE	1368F 42.922mV P0=0X01
***********************************************/
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
	
	         if(Code_Value > 1050) 	//864
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
/**********************************************
     T_TYPE   	2		//360F    9.286mV
***********************************************/
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
/***********************************************
             E_Slope
************************************************/
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
	    out_Value =out_Value-(Code_Value-26440)/E_Slope[10] ;  //
	   }
	 if(Code_Value > 28280)
	   {
	    out_Value =out_Value+(Code_Value-28240)/E_Slope[11] ;  //
	   }
	 if(Code_Value > 29750)
	   {
	    out_Value =out_Value-(Code_Value-29700)/E_Slope[10] ;  //
	   }
	 if(Code_Value > 33680)
	   {
	    out_Value =out_Value+(Code_Value-33640)/E_Slope[10] ;  //
	   }
 	 if(Code_Value > 34480)
	   {
	    out_Value =out_Value-(Code_Value-34440)/E_Slope[9];  //
	   }
 	 if(Code_Value > 36480)
	   {
	    out_Value =out_Value+(Code_Value-36440)/E_Slope[11] ;  //
	   }
 	 if(Code_Value > 37700)
	   {
	    out_Value =out_Value-(Code_Value-37650)/E_Slope[11] ;  //
	   }
 	 if(Code_Value > 40600)
	   {
	    out_Value =out_Value+(Code_Value-40550)/E_Slope[11] ;  //
	   }
 	 if(Code_Value > 41200)
	   {
	    out_Value =out_Value-(Code_Value-41150)/E_Slope[11] ;  //
	   }
 	 if(Code_Value > 42500)
	   {
	    out_Value =out_Value+(Code_Value-42450)/E_Slope[11] ;  //
	   }
 	 if(Code_Value > 44500)
	   {
	    out_Value =out_Value-(Code_Value-44450)/E_Slope[11] ;  //
	   }
 	 if(Code_Value > 47700)
	   {
	    out_Value =out_Value+(Code_Value-47650)/E_Slope[10] ;  //
	   }
 	 if(Code_Value > 49270)
	   {
        out_Value =out_Value-(Code_Value-49250)/E_Slope[7] ;  //
	   }
 	 if(Code_Value > 50000)
	   {
        out_Value =out_Value+(Code_Value-49980)/E_Slope[7] ;  //
	   }
 	 if(Code_Value > 51860)
	   {
        out_Value =out_Value-(Code_Value-51820)/E_Slope[11] ;  //
	   }
 	 if(Code_Value > 52560)
	   {
        out_Value =out_Value+(Code_Value-52520)/E_Slope[11] ;  //
	   }
 	 if(Code_Value > 53560)
	   {
        out_Value =out_Value-(Code_Value-53520)/E_Slope[11] ;  //
	   }
 	 if(Code_Value > 54960)
	   {
        out_Value =out_Value+(Code_Value-54920)/E_Slope[11] ;  //
	   }
 	 if(Code_Value > 58160)
	   {
        out_Value =out_Value+(Code_Value-58120)/E_Slope[11] ;  //
	   }
 	 if(Code_Value > 59020)
	   {
        out_Value =out_Value-(Code_Value-59000)/E_Slope[9] ;  //
	   }
 	 if(Code_Value > 60060)
	   {
        out_Value =out_Value+(Code_Value-60020)/E_Slope[11] ;  //
	   }
 	 if(Code_Value > 62260)
	   {
        out_Value =out_Value-(Code_Value-62220)/E_Slope[11] ;  //
	   }
 	 if(Code_Value > 62460)
	   {
        out_Value =out_Value+(Code_Value-62420)/E_Slope[10] ;  //
	   }

 	 if(Code_Value > 654000)
	   {
        out_Value = 65536 ;  //
	   }
	}
   return out_Value;

}
/**********************************************
       R_Slope
***********************************************/
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
/***********************************************
               S_Slope
*************************************************/
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
/***********************************************

************************************************
unsigned int Get_B_Slope(unsigned  int Code_Value)
{
   unsigned int out_Value;

 		Code_Value = 320 + Code_Value/2.82;
	
	   out_Value = Code_Value;
	   NP_COD = 1;

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
************************************************
unsigned int Get_N_Slope(unsigned int Code_Value)
{
   unsigned int out_Value;

		Code_Value = 320 + Code_Value/2.82;
	
	   out_Value = Code_Value;
		 NP_COD = 1;
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
unsigned int Get_RTD_Slope(unsigned  int Code_Value) 
{
   unsigned int RTD_Value;
   unsigned int out_Value;

     	    	NP_COD = 0;

     if ( AV_COD == 1 )
	 {
		  if(Code_Value <= 394)  	//394	   432
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