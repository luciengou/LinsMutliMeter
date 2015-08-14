#include <MG82FE564.H>
#include <IO_DEFINE.h>
#include <LED.h>


//const unsigned char code tab_LED[23] = {
//	0xAF,0xA0,0x6D,0xE9,0xE2,0xCB,0xCF,0xA1,0xEF,0xEB,0xE7,0xEF,0x0F,0xAF,0x4F,0x47,0xE6,0x67,0x00, 0xA7, 0x0E, 0x40, 0xAE  };
//     0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F    H    P BLANK    n    L     -	    U
const unsigned char code tab_LED[28] = {
	0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x27,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x76,0x73,0x00, 0x37, 0x38, 0x40, 0x3e,0x78,0x58,0x70,0x54,0x1e };
//     0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F    H    P BLANK    N    L     -	    U	t	 c	  r
//const unsigned char code Point_tab_LED[23] = {
//	0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0xA7,0xFF,0xEF,0xF7,0xFC,0xB9,0xDE,0xF9,0xF1,0xF6,0xF3,0x00, 0xC7, 0xB8, 0xC0, 0xBE  };
//     0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F    H    P BLANK    N    L     -	    U
extern unsigned char AV_COD;
extern unsigned char NP_COD;
extern unsigned char Work_Type;
extern unsigned char ng_flog ;
unsigned char Disp_Show;
unsigned char Disp_Bits;
unsigned char Dot_Addr;
extern unsigned long int disp_value ;
/**************************************************************************************/
void LED_Disp(unsigned char LEDs, unsigned long int disp_value)	   // unsigned long int disp_value
{
	unsigned char Dot_Addr = LEDs;
	unsigned char D0 = 0;
	unsigned char D1 = 0;
	unsigned char D2 = 0;
	unsigned char D3 = 0;
	unsigned char D4 = 0;
	unsigned char D5 = 0;
	unsigned long int D_value;
	
	  D_value = disp_value;		//65536		131072
	  if (Disp_Bits == 4){D_value = D_value/10;}
	  if (Disp_Bits == 3){D_value = D_value/100;}
	  if (Disp_Bits <= 2){D_value = D_value/1000;}
      if (AV_COD == 1)
	   {
	             D0 = tab_LED[18]; 
		         D1 = tab_LED[18];  
		         D2 = tab_LED[18];
	             D3 = tab_LED[21];
	             D4 = tab_LED[(D_value%100)/10];
	             D5 = tab_LED[D_value%10];
			 if (D_value >= 100)
	           {
			     D2 = tab_LED[21];
	             D3 = tab_LED[(D_value%1000)/100];
			   }
			 if (D_value >= 1000 )
	           { 
			     D1 = tab_LED[21];
		         D2 = tab_LED[(D_value%10000)/1000];
			   }
			 if (D_value >= 10000 )
	           {
			     D0 = tab_LED[21];
		         D1 = tab_LED[(D_value%100000)/10000];  
			   }
			  if(Dot_Addr == 6) { D0 = D0 + 0x80;}
		      else if(Dot_Addr == 5) { D1 = D1 + 0x80;}
		      else if(Dot_Addr == 4) { D2 = D2 + 0x80;}
		      else if(Dot_Addr == 3) { D3 = D3 + 0x80;}
		      else if(Dot_Addr <= 2) { D4 = D4 + 0x80;}

	   }
	  else
	   {
	     if(Disp_Show == 1)
	       {     D0 = tab_LED[0]; 
		         D1 = tab_LED[0];  
		         D2 = tab_LED[0];
	             D3 = tab_LED[0];
				 D4 = tab_LED[(D_value%100)/10] ;
	             D5 = tab_LED[D_value%10];
		   }
		  else
		   {
		         D0 = tab_LED[18]; 
		         D1 = tab_LED[18];  
		         D2 = tab_LED[18];
	             D3 = tab_LED[18];
	             D4 = tab_LED[(D_value%100)/10] ;
	             D5 = tab_LED[D_value%10];
		   }
			if (D_value >= 100)
	           {
	             D3 = tab_LED[(D_value%1000)/100];
			   }
			 if (D_value >= 1000 )
	           { 
		         D2 = tab_LED[(D_value%10000)/1000];
			   }
			 if (D_value >= 10000 )
	           {
		         D1 = tab_LED[(D_value%100000)/10000];  
			   }
			  if (D_value >= 100000 )
	           {
		         D0 = tab_LED[(D_value/100000)];  
			   }
			   if(Dot_Addr == 6) { D0 = D0 + 0x80;}
		      else if(Dot_Addr == 5) { D1 = D1 + 0x80;}
		      else if(Dot_Addr == 4) { D2 = D2 + 0x80;}
		      else if(Dot_Addr == 3) { D3 = D3 + 0x80;}
		      else if(Dot_Addr <= 2) { D4 = D4 + 0x80;}
	   }
		  
	LED_DATA_Write(D5,D4,D3,D2,D1,D0);
}
/***********************************************************************/
void SETUP_LED_Disp(unsigned char SETUP_SELECT, unsigned long int disp_value)
{
	unsigned char setup_status;
	unsigned char D0 = 0;
	unsigned char D1 = 0;
	unsigned char D2 = 0;
	unsigned char D3 = 0;
	unsigned char D4 = 0;
	unsigned char D5 = 0;
  	unsigned long int D_Count;

	  setup_status = SETUP_SELECT;
	   D_Count = disp_value;
//===========================================
	  if (setup_status == 0)		   //PSxSEC
	    { 
	       D0 =	tab_LED[17];
		   D1 = tab_LED[5] ;
		   D2 = tab_LED[18];
		   D3 =	tab_LED[5];
		   D4 =	tab_LED[14];
		   D5 =	tab_LED[12];
		}
//==========================================
     else if (setup_status == 1)		  //Mode_selec	
	    {
		  if(D_Count <= 9)
	      {
		    D0 =	tab_LED[15]; 
		    D1 =    tab_LED[12];
		    D2 =    tab_LED[18];
		    D3 =	tab_LED[18];
		    D4 =	tab_LED[0];
		    D5 = tab_LED[D_Count];
		  }
		else
	      {
		    D0 =    tab_LED[15];  
		    D1 =    tab_LED[12] ;
		    D2 =    tab_LED[18];
		    D3 =	tab_LED[18];
	    	D4 =    tab_LED[D_Count/10];	
		    D5 =    tab_LED[D_Count%10];
		  }
	     
	    }
//==========================================
	   else if (setup_status == 2)		  //c_f	
	    {
		  if(D_Count == 0)
	      {
		     D0 =   tab_LED[18];
		     D1 =	tab_LED[18];
	         D2 =   tab_LED[18];
		     D3 =	tab_LED[18];
		     D4 =	tab_LED[18];
		     D5 =	tab_LED[12];
		  }
		else
	      {
		     D0 =   tab_LED[18];
		     D1 =	tab_LED[18];
	         D2 =   tab_LED[18];
		     D3 =	tab_LED[18];
		     D4 =	tab_LED[18];
		     D5 =	tab_LED[15];

		  }
	     
	    }
//========================================
      else if (setup_status ==  3)		//TC_SELECT 
	    {
	     if(D_Count == 0)
	       { D0 =	tab_LED[17]; // K
		     D1 = tab_LED[3] ;
		     D2 = tab_LED[18];
		     D3 =	tab_LED[18];
		     D4 = 0x74;//	tab_LED[12];
		     D5 =	tab_LED[18];
		   }
		 if(D_Count == 1)
	       { D0 =	tab_LED[17];  //J
		     D1 = tab_LED[3] ;
		     D2 = tab_LED[18];
		     D3 =	tab_LED[18];
		     D4 =	tab_LED[27];
		     D5 =	tab_LED[18];
		   }
		 if(D_Count == 2)
	       { D0 =	tab_LED[17]; // T
		     D1 = tab_LED[3] ;
		     D2 = tab_LED[18];
		     D3 =	tab_LED[18];
		     D4 =	tab_LED[23];
		     D5 =	tab_LED[18];
		   }
		 if(D_Count == 3)
	       { D0 =	tab_LED[17]; // E
		     D1 = tab_LED[3] ;
		     D2 = tab_LED[18];
		     D3 =	tab_LED[18];
		     D4 =	tab_LED[14];
		     D5 =	tab_LED[18];
		   }
		 if(D_Count == 4)
	       { D0 =	tab_LED[17]; // TC_R
		     D1 = tab_LED[3] ;
		     D2 = tab_LED[18];
		     D3 =	tab_LED[18];
		     D4 =	tab_LED[25];
		     D5 =	tab_LED[18];
		   }
		 if(D_Count == 5)
	       { D0 =	tab_LED[17]; // TC_S
		     D1 = tab_LED[3] ;
		     D2 = tab_LED[18];
	  	     D3 =	tab_LED[18];
		     D4 = 0x6d; //	tab_LED[12];
		     D5 =	tab_LED[18];
		    }

		 if(D_Count == 6)
	       { D0 =	tab_LED[17]; // TC_B
		     D1 = tab_LED[3] ;
		     D2 = tab_LED[18];
		     D3 =	tab_LED[18];
		     D4 =	tab_LED[12];
		     D5 =	tab_LED[18];
		   }
		 if(D_Count == 7)
	       { D0 =	tab_LED[17]; // TC_N
		     D1 = tab_LED[3] ;
		     D2 = tab_LED[18];
		     D3 =	tab_LED[18];
		     D4 =	tab_LED[12];
		     D5 =	tab_LED[18];
		   }		
		 }
//================fill  disp ==================
	  else if (setup_status == 4)
	  	 {    
		        if (AV_COD == 1)
	       {
	             D0 = tab_LED[18]; 
		         D1 = tab_LED[18];  
		         D2 = tab_LED[18];
	             D3 = tab_LED[21];
	             D4 = tab_LED[(D_Count%100)/10];
	             D5 = tab_LED[D_Count%10];
			 if (D_Count >= 100)
	           {
			     D2 = tab_LED[21];
	             D3 = tab_LED[(D_Count%1000)/100];
			   }
			 if (D_Count >= 1000 )
	           { 
			     D1 = tab_LED[21];
		         D2 = tab_LED[(D_Count%10000)/1000];
			   }
			 if (D_Count >= 10000 )
	           {
			     D0 = tab_LED[21];
		         D1 = tab_LED[(D_Count%100000)/10000];  
			   }
/*		  if(Disp_Show == 1)
		   {

		      if(Disp_Bits == 6) { D0 = D0 + 0x80;}
		      else if(Disp_Bits == 5) { D1 = D1 + 0x80;}
		      else if(Disp_Bits == 4) { D2 = D2 + 0x80;}
		      else if(Disp_Bits == 3) { D3 = D3 + 0x80;}
		      else if(Disp_Bits <= 2) { D4 = D4 + 0x80;}
		   }
*/
	   }
	  else
	   {
	             D0 = tab_LED[0]; 
		         D1 = tab_LED[0];  
		         D2 = tab_LED[0];
	             D3 = tab_LED[0];
	             D4 = tab_LED[(D_Count%100)/10];
	             D5 = tab_LED[D_Count%10];
			if (D_Count >= 100)
	           {
	             D3 = tab_LED[(D_Count%1000)/100];
			   }
			 if (D_Count >= 1000 )
	           { 
		         D2 = tab_LED[(D_Count%10000)/1000];
			   }
			 if (D_Count >= 10000 )
	           {
		         D1 = tab_LED[(D_Count%100000)/10000];  
			   }
			  if (D_Count >= 100000 )
	           {
		         D0 = tab_LED[(D_Count/100000)];  
			   }
/*		  if(Disp_Show == 1)
		   {

		      if(Disp_Bits == 6) { D0 = D0 + 0x80;}
		      else if(Disp_Bits == 5) { D1 = D1 + 0x80;}
		      else if(Disp_Bits == 4) { D2 = D2 + 0x80;}
		      else if(Disp_Bits == 3) { D3 = D3 + 0x80;}
		      else if(Disp_Bits <= 2) { D4 = D4 + 0x80;}
		   }
*/
	   }
	}
//====================== set  Dot ======================
       else if (setup_status == 5)		   
	     {	  
		if (D_Count >= 10 && D_Count < 100)
	   	  { 
			D2 = tab_LED[18];
		    D3 = tab_LED[18];
			if(NP_COD == 0) {D4 = tab_LED[D_Count/10] + 0x80;} else {D4 = tab_LED[D_Count/10];}
			D5 = tab_LED[D_Count%10];
		  }
	    if (D_Count >=100 && D_Count < 1000)
	   	  {
			D2 = tab_LED[18];
			D3 = tab_LED[D_Count/100]; //987 
			if(NP_COD == 0) {D4 = tab_LED[(D_Count%100)/10] + 0x80;} else {D4 = tab_LED[(D_Count%100)/10];}
			D5 = tab_LED[D_Count%10];
		  }
	    if (D_Count >=1000 && D_Count < 10000)
	   	  {
			D2 = tab_LED[D_Count/1000];	//9876
		    D3 = tab_LED[(D_Count%1000)/100];
			if(NP_COD == 0) {D4 = tab_LED[(D_Count%100)/10] + 0x80;} else {D4 = tab_LED[(D_Count%100)/10];}
			D5 = tab_LED[D_Count%10];
		  }
		if (D_Count >= 10000 && D_Count < 100000)
	   	  {
		    D1 = tab_LED[D_Count/10000];   //98765
			D2 = tab_LED[(D_Count%10000)/1000];	
		    D3 = tab_LED[(D_Count%1000)/100];   
			if(NP_COD == 0){D4 = tab_LED[(D_Count%100)/10] + 0x80;} else {D4 = tab_LED[(D_Count%100)/10];}		
			D5 = tab_LED[D_Count%10];		
		  }
	  }
//=============selec  disp  ==================
     else if (setup_status >= 6)		   
	     {	  
	             D0 = tab_LED[18]; 
		         D1 = tab_LED[18];  
		         D2 = tab_LED[18];
	             D3 = tab_LED[18];
	             D4 = tab_LED[18];
	             D5 = tab_LED[D_Count%10];

			  if (D_Count >= 10)
				{ D4 = tab_LED[(D_Count%100)/10];}
			if (D_Count >= 100)
	           { D3 = tab_LED[(D_Count%1000)/100];}
			 if (D_Count >= 1000 )
	           { D2 = tab_LED[(D_Count%10000)/1000];}
			 if (D_Count >= 10000 )
	           { D1 = tab_LED[(D_Count%100000)/10000];}
			  if (D_Count >= 100000 )
	           { D0 = tab_LED[(D_Count/100000)]; }
	  }
	 LED_DATA_Write(D5,D4,D3,D2,D1,D0);
}
/**********************************************************
void DAY_LED_Disp(unsigned char DD,unsigned char HH, unsigned char MM)	   // unsigned long int disp_value
{
	unsigned char D0 = 0;
	unsigned char D1 = 0;
	unsigned char D2 = 0;
	unsigned char D3 = 0;
	unsigned char D4 = 0;
	unsigned char D5 = 0;
	unsigned char D_FD,H_FH,M_FM ;

			M_FM = MM ;
			D5 = Point_tab_LED[(M_FM&0x0f)];
			M_FM = (M_FM >> 4)&0x0f;
			D4 = tab_LED[M_FM];

			H_FH  = HH ;
			D3 = Point_tab_LED[(H_FH&0x0f)];
			H_FH = (H_FH >> 4)&0x0f;
			D2 = tab_LED[H_FH];

			D_FD = DD ;
			D1 = Point_tab_LED[(D_FD&0x0f)];
   		    D_FD = (D_FD >> 4)&0x0f;
		    D0 = tab_LED[D_FD];

   	 LED_DATA_Write(D5,D4,D3,D2,D1,D0);
}
/************************************************/
void LED_Fill(void)
{
   unsigned char D0,D1,D2,D3,D4,D5;

            D0 = tab_LED[8] + 0x80;
	 	    D1 = tab_LED[8] + 0x80;
			D2 = tab_LED[8] + 0x80;	
		    D3 = tab_LED[8] + 0x80;   
			D4 = tab_LED[8] + 0x80;		
			D5 = tab_LED[8] + 0x80;


	    LED_DATA_Write(D5,D4,D3,D2,D1,D0);
}
/*********************************************************/
void _BitDly(void)               // wait 4.7uS, or thereabouts
{                                   // tune to xtal. This works at 11.0592MHz
	unsigned char	k;
	
	for (k=0; k<0x12; k++);
}
/*********************************/
void LED_Init(void)
{
	unsigned int i;
 
 	LED1_LE  = 0;
	LED2_LE  = 0;
	LED1_SCL = 0;
	LED1_SDA = 0;
	LED2_SCL = 0;
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
}
/**********************************/
void  LED_DATA_Write(unsigned char D5,unsigned char D4,unsigned char D3,unsigned char D2,unsigned char D1,unsigned char D0)
{
    unsigned char  DISP_CODE, D_count, D_time ;

				 DISP_CODE = D0 ;
		         LED1_LE = 0 ;		// off led

		     for(D_time = 0; D_time < 2; D_time++)
		       {
		         LED1_SCL = 0;
				 LED1_SDA = 0;
			     for(D_count = 0; D_count < 8; D_count++)
			        {
					  LED1_SDA = 0;
		              _BitDly();
 		              LED1_SCL = 1 ;
			          _BitDly();
		  	  	      LED1_SCL = 0;
				    }
			   }
				       LED1_SCL = 1 ;
			          _BitDly();
		  	  	      LED1_SCL = 0;
		     for(D_time = 0; D_time < 6;D_time++)
		       {
		         LED1_SCL = 0;
				 LED1_SDA = 0;
			     for(D_count = 0; D_count < 8; D_count++)
			       {
		             if(DISP_CODE & 0x80){LED1_SDA = 1;}		  //d7 - d0
		               _BitDly();
 		               LED1_SCL = 1 ;
			           _BitDly();
					   LED1_SDA = 0;
		  	  	       LED1_SCL = 0;
			           DISP_CODE = DISP_CODE << 1;
				   }
				 if (D_time  == 0)  DISP_CODE = D1;
				 else if (D_time  == 1)  DISP_CODE = D2;
				 else if (D_time  == 2)  DISP_CODE = D3;
				 else if (D_time  == 3)  DISP_CODE = D4;
				 else if (D_time  == 4)  DISP_CODE = D5;
			    }
			  LED1_LE  = 1 ;	   //on led

 }	