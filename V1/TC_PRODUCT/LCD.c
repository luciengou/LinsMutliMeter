/*******************************************
/*  JAPAN PROJECT  "JA-1 "
/*
/*
/*******************************************/

#include<MPC82G516.h>
#include<LCD.h>






const  unsigned char code Machine_ID[5][5] = {{18,20,3,0,5},		//PL305
											  {18,20,5,0,5},		//PL505
											  {23,10,18,10,22},	//JAPAN
											  {18,20,9,0,5},		//PL905
											  {23,10,16,1,17},	//JA-1
											};

// ----------------------------     0    1    2    3    4    5    6    7    8    9    A    B    C    D    E	   F	-	BLANK, P,  H,   L,   U,   n	   J
const  unsigned char code NUM5[24]={0x5F,0x50,0x3D,0x79,0x72,0x6B,0x6F,0x51,0x7F,0x7B,0x77,0x6E,0x0F,0x7C,0x2F,0x27,0x20,0x00,0x37,0x76,0x0e,0x5E,0x57,0x58};  //c/sec/min/ph


// ----------------------------0    1    2  3   4   5   6   7   8   9   A   B	C	D	E	F	-	BLANK  U

const unsigned char code NUM4[19]={0x5F,0x50,0x6B,0x79,0x74,0x3D,0x3F,0x58,0x7F,0x7D,0x7E,0x37,0x0F,0x73,0x2F,0x2E,0x20,0x00,0x57};  //容量



// ----------------------------0    1    2  3   4   5   6   7   8   9   A	B	C	D	E	F	-	BLANK

const unsigned char code NUM1[18]={0x5F,0x50,0x6B,0x79,0x74,0x3D,0x3F,0x58,0x7F,0x7D,0x7E,0x37,0x0F,0x73,0x2F,0x2E,0x20,0x00};  //Er Work TABLE





void RGB(unsigned char r,unsigned char g,unsigned char b) ;
//unsigned char iDisplayValue[5];



unsigned char idata x1=0,k3=0,x3=0,orp=0,x4=0,tds=0,k2=0,
              k4=0, ErrorWork1=0,
              Alkaline_flag=0,r6=0,Acidic_flag=0,
              Filtered_flag=0,Alkaline1=0,
              Er=0,day=0,mv=0,ppm=0,
              r4=0,c1=0,sec1=0,min1=0,
              r1=0,r3=0,r5=0,r2=0;
              picture1=0,picture2=0,picture3=0,picture4=0,picture5=0,picture6=0;	

 
 

void RGB(unsigned char r,unsigned char g,unsigned char b) 

{ 
unsigned char temp;

//	red_	=1;
//	green_	=1;
//	blue_	=1;
	
	
	
	//Pre_color=Color;
#if 0	
	CCAP0L=CCAP0H=r;   
	CCAP1L=CCAP1H=g;   
	CCAP2L=CCAP2H=b;
#else
// 20120201 arnold
temp = r;
	//CCAP0L=CCAP0H=~r;
	CCAP1L=CCAP1H=~g;   
	CCAP2L=CCAP2H=~b;
#endif	
	
	CMOD=0x00; 
	CL=0x00;
	CH=0x00;
	
	
	//CCAPM0=0x42; 
	CCAPM1=0x42; 
	CCAPM2=0x42; 
	
	CR=1;
	CCON= 0x0E;
	CR=1;
	
} 				  
/*  /#if China
void WriteLCD(uchar Value)
{
    LCD_Data=Value;
    LCD_A0=1;
    _nop_();
    LCD_CS=1;
    _nop_();
    LCD_WR=1;
    _nop_();
    _nop_();
    LCD_WR=0;
    _nop_();
    LCD_CS=0;
 }

void DisplayDataWrite(uchar Value)
{
    LCD_Data=Value;
    LCD_A0=0;
    _nop_();
    LCD_CS=1;
    _nop_();
    LCD_WR=1;
    _nop_();
    LCD_WR=0;
    _nop_();
    LCD_CS=0;
}


//#endif

//#if TW
*/
void WriteLCD(uchar Value)
{
    LCD_Control_LE2=0;
     LCD_Data_LE1=1;
	_nop_();
       LCD_Data=Value;
	_nop_();
   	_nop_();
    LCD_Data_LE1=0;
	_nop_();
   	_nop_();
#if 0
    //LCD_A0=1;
    LCD_Control_LE2=1;
	_nop_();
   	_nop_();
    Set_LCM_Control_A0_();
        _nop_();
	 _nop_();
	P0=LCM_Control;
    //LCD_CS=0;
    Clr_LCM_Control_CSn();
     	_nop_();
     	_nop_();
	P0=LCM_Control;
    //    LCD_WR=0;
    Clr_LCM_Control_WR();
    	_nop_();
    	_nop_();
	_nop_();
	P0=LCM_Control;
    //    LCD_WR=1;
     Set_LCM_Control_WR();
    	_nop_();
       _nop_();
	_nop_();
	P0=LCM_Control;
   //    LCD_CS=1;
	Set_LCM_Control_CSn();
	_nop_();
       _nop_();
	_nop_();
	P0=LCM_Control;
	_nop_();
       _nop_();
	_nop_();
	_nop_();
       _nop_();
	_nop_();
	_nop_();
       _nop_();
	_nop_();
	_nop_();
       _nop_();
	_nop_();
	_nop_();
       _nop_();
	_nop_();
	_nop_();
       _nop_();
	_nop_();
	_nop_();
       _nop_();
	_nop_();
	_nop_();
       _nop_();
	_nop_();
	LCD_Control_LE2=0;
	
#else
    LCD_A0=1;
    _nop_();
    LCD_CS=0;
    _nop_();
    LCD_WRn=0;
    _nop_();
    _nop_();
    LCD_WRn=1;
    _nop_();
    LCD_CS=1;
#endif
	
 }

void DisplayDataWrite(uchar Value)
{
    LCD_Control_LE2=0;  
	LCD_Data_LE1=1;
	_nop_();
    	LCD_Data=Value;
	_nop_();
   	_nop_();
    LCD_Data_LE1=0;
	_nop_();
   	_nop_();

	#if 0
    LCD_Control_LE2=1;
//    LCD_A0=0;
    Clr_LCM_Control_A0_();
        _nop_();
	 _nop_();
	P0=LCM_Control;
    //LCD_CS=0;
    Clr_LCM_Control_CSn();
     	_nop_();
     	_nop_();
	P0=LCM_Control;
    //    LCD_WR=0;
    Clr_LCM_Control_WR();
    	_nop_();
    	_nop_();
	_nop_();
	P0=LCM_Control;
    //    LCD_WR=1;
     Set_LCM_Control_WR();
    	_nop_();
       _nop_();
	_nop_();
	P0=LCM_Control;
   //    LCD_CS=1;
	Set_LCM_Control_CSn();
	_nop_();
       _nop_();
	_nop_();
	P0=LCM_Control;
	_nop_();
       _nop_();
	_nop_();
	_nop_();
       _nop_();
	_nop_();
	_nop_();
       _nop_();
	_nop_();
	_nop_();
       _nop_();
	_nop_();
	_nop_();
       _nop_();
	_nop_();
	_nop_();
       _nop_();
	_nop_();
	_nop_();
       _nop_();
	_nop_();
	_nop_();
       _nop_();
	_nop_();
	LCD_Control_LE2=0;
	#else
  LCD_A0=0;
	  _nop_();
  LCD_CS=0;
    _nop_();
  LCD_WRn=0;
    _nop_();
  LCD_WRn=1;
    _nop_();
  LCD_CS=1;
    _nop_();
	#endif

}

/*
unsigned char DisplayDataRead(void)
{
    unsigned char i;
    //LCD_Data=Value;
    LCD_A0=0;
    _nop_();
    LCD_CS=0;
    _nop_();
    LCD_RD=1;
    _nop_();
    LCD_RD=0;
    _nop_();
    i=LCD_Data;
    _nop_();
    LCD_CS=1;
    return(i);
}
*/
//#endif

void DisplayON()
{
   WriteLCD(0xaf);
} 
/*void DisplayOFF()
{
   WriteLCD(0xae);
}
*/
void DisplayNormal()
{
   WriteLCD(0xa6);
}
/*
void DisplayReverse()
{
   WriteLCD(0xa7);
}

void DisplayAllPointsON()
{
   WriteLCD(0xa5);
}
*/
void DisplayAllPointsOFF()     //normal display
{
   WriteLCD(0xa4);
}

void PowerControlSet()  //This command sets the on-chip power supply function ON/OFF.
{
   WriteLCD(0x2f);
}

void PageAddressSet()
{
   WriteLCD(0xb0);	  //

}

void ColumnAddressSet(unsigned char ColumnAddress)
{

    WriteLCD(0x10+(ColumnAddress>>4)); //X6 X5 X4  
    _nop_();
    _nop_();
    WriteLCD(ColumnAddress&0x0f);     //X3 X2 X1 X0
    _nop_();
    _nop_();
}

void SegmentDriverDirectionSelect()    //seg0-seg95
{
#if old_LCM
  WriteLCD(0xa0);
#endif

#if new_LCM
  WriteLCD(0xa1);
#endif


}
void CommonDriverDirectionSelect()    //com0-com3
{
//  WriteLCD(0xc0); //old Lcm
//  WriteLCD(0xc8); //new Lcm

#if old_LCM
  WriteLCD(0xc0);
#endif

#if new_LCM
  WriteLCD(0xc0);
#endif


}

void EnterModeSet()
{
  WriteLCD(0xf1);
}

void DutyModeSet()       // 1/4duty
{
  WriteLCD(0xac);
}

void FinishModeSet()
{
  WriteLCD(0xf0);
}


void delay(int i)
{
   while(i)i--;
}


void MoreDelay(int i)
{
	while(i--){
	   delay(10000);
	}
}



void LCDInit()
{
//unsigned char idata LCM_Control   ;
/* 
     LCM_Control Define 
      bit 0 LCM Reset 
     bit 1 LCM /CS
     bit 2 LCM A0
     bit 3 LCM W/R
     bit 4 LCM E
     bit 5 H+ ON/OFF
     bit 6 CO2 ON/Off 
     bit 7 xx
 */
//	LCD_RETB = 1;
//	delay(5000);
//	LCD_RETB = 0;
//	delay(5000);
//   delay(DElay0_num);
 
#if China
   //LCD_CS = 1;
   //LCD_WR=0;
   // LCD_RD=0;
Set_LCM_Control_CSn();
Clr_LCM_Control_WR();
Clr_LCM_Control_LCD_E();
LCD_Latch_Write();
#endif

#if TW
#if 1
//LCD_CS = 1;
  LCD_WRn=1;
   // LCD_RD=1;
#else
   P0=LCM_Control;
   LCD_Control_LE2=1;
	_nop_();
   	_nop_();
	//LCD_CS = 0;
    //Clr_LCM_Control_CSn();
        _nop_();
	 _nop_();
	
//  LCD_WR=1;         //QianShan
    Set_LCM_Control_WR();
	 _nop_();
	 _nop_();
	 P0=LCM_Control;
 //LCD_RD=1;           //QianShan
    Set_LCM_Control_LCD_E();
	 _nop_();
	 _nop_();
	 P0=LCM_Control;
	_nop_();
	_nop_();
	 LCD_Control_LE2=0;
#endif
#endif
    delay(DElay0_num);
    PowerControlSet();
    delay(DElay0_num);
    PageAddressSet();
    delay(DElay0_num);
    ColumnAddressSet(0x00);
    EnterModeSet();
    delay(DElay0_num);
    DutyModeSet();
    delay(DElay0_num);
    FinishModeSet();
    delay(DElay0_num);
    DisplayAllPointsOFF();
    delay(DElay0_num);
    DisplayON();
    delay(DElay0_num);
    DisplayNormal();
    delay(DElay0_num);
    SegmentDriverDirectionSelect();
    delay(DElay0_num);
    CommonDriverDirectionSelect();
    delay(DElay0_num);
}


void lcd_all_off(void)
{
   unsigned char LCMaddr=0;
   PageAddressSet();
   ColumnAddressSet(0x00);
   for(LCMaddr=0;LCMaddr<=Lcm_max_line;LCMaddr++)
   {
      DisplayDataWrite(0x00);
      c
   }
   
   x1=0;k3=0;x3=0;orp=0;x4=0;tds=0;k2=0;
   k4=0; ErrorWork1=0;
   Alkaline_flag=0;r6=0;Acidic_flag=0;
 Filtered_flag=0;Alkaline1=0;
 Er=0;day=0;mv=0;ppm=0;
r4=0;c1=0;sec1=0;min1=0;
r1=0;r3=0;r5=0;r2=0;
picture1=0,picture2=0,picture3=0,picture4=0,picture5=0,picture6=0;
  
} 


void Lcd_DisplayFilterLife(unsigned long DisplayValue,unsigned char count,unsigned char status,unsigned char K_status)
{
   
	unsigned char a5,a4,a3,a2,a1;
	unsigned char k5,k6,k7,k8,k9,flag,flag1,L_flag = 0;    // 2011/04/19
	unsigned long temp;
	
	
	switch(count)
	{
		case 0:k5=0;k6=0;k7=0;k8=0;k9=0;break;
		case 1:k5=1;k6=0;k7=0;k8=0;k9=0;break;
		case 2:k5=1;k6=1;k7=0;k8=0;k9=0;break;
		case 3:k5=1;k6=1;k7=1;k8=0;k9=0;break;
		case 4:k5=1;k6=1;k7=1;k8=1;k9=0;break;
		case 5:k5=1;k6=1;k7=1;k8=1;k9=1;break;
	} 

	switch (K_status){
		case 0:
			k4=0;
			flag1=0xfe;
			break;
		case 1:
			k4=1;
			flag1=0xff;
			break;
		case 2:
			k4=0;
			flag1=0xff;
			break;
		default:
			k4=0;
			flag1=0xfe;
			break;
	}

	if(status==0){
		flag1 &= 0x01;
		flag=0x00;
		L_flag=0;
	}else{
		flag1 |= 0xfe;
		flag=0xff;
		L_flag=1;
	}

	if(status==1){     //normal display
		temp = DisplayValue;
		a5 = (unsigned char)(temp/10000);
		temp = DisplayValue % 10000;
		a4=(unsigned char)(temp/1000);
		temp = DisplayValue % 1000;
		a3=(unsigned char)(temp/100);
		temp = DisplayValue % 100;
		a2=(unsigned char)(temp/10);
		temp = DisplayValue % 10;
		a1=(unsigned char)temp;  
	}else if(status==2){             //display volage
		a5=17;        //bank
		a4=(unsigned char)(DisplayValue/10);
		a3=(unsigned char)(DisplayValue%10);
		a2=17;    //bank
		a1=18;   //"U" 
		k4=0;k5=0;k6=0;k7=0;k8=0;k9=0; 
		L_flag=0;  
	}else if(status==3){
		a5=16;        //"-"
		temp = DisplayValue % 10000;
		a4=(unsigned char)(temp/1000);
		temp = DisplayValue % 1000;
		a3=(unsigned char)(temp/100);
		temp = DisplayValue % 100;
		a2=(unsigned char)(temp/10);
		temp = DisplayValue % 10;
		a1=(unsigned char)temp;  
	}else if(status==4){     //work display
		temp = DisplayValue;
		a5=(unsigned char)(temp/10000);
		temp = DisplayValue % 10000;
		a4=(unsigned char)(temp/1000);
		temp = DisplayValue % 1000;
		a3=(unsigned char)(temp/100);
		temp = DisplayValue % 100;
		a2=(unsigned char)(temp/10);
		temp = DisplayValue % 10;
		a1=(unsigned char)temp;  
		L_flag=0;  
	}
 
	    PageAddressSet();
	    ColumnAddressSet(0x17);                                   //seg23
	    DisplayDataWrite((k4<<3)|ErrorWork1);                     //K4
	
     	DisplayDataWrite((NUM4[a5]&0x00)&flag);            // k5,5
    	DisplayDataWrite(((NUM4[a5]&0x00)>>3|k5)&0x01);

        DisplayDataWrite((NUM4[a4]&0x00)&flag);            // k6,4
     	DisplayDataWrite(((NUM4[a4]&0x00)>>3|k6)&0x01);
	
     	DisplayDataWrite((NUM4[a3]&0x00)&flag);            // k7,3
    	DisplayDataWrite(((NUM4[a3]&0x00)>>3|k7)&0x01);
	
     	DisplayDataWrite((NUM4[a2]&0x00)&flag);            // k8,2
    	DisplayDataWrite(((NUM4[a2]&0x00)>>3|k8)&0x01);
	
    	DisplayDataWrite((NUM4[a1]&0x00)&flag);            // k9.1
    	DisplayDataWrite(((NUM4[a1]&0x00)>>3|k9)&0x01);

}


void Lcd_DisplayLock(bit status)
{
	k3=status;
	PageAddressSet();
	ColumnAddressSet(0x05);
	DisplayDataWrite((x1<<1)|k3);  //k3
}




void Lcd_DisplayVolume(unsigned char Volume,bit status)   //显示音量大小
{
   
    uchar x2;
    x1=status;
    switch(Volume)
   {
     case 0:x2=0;x3=0;x4=0;break;
     case 1:x2=status;x3=0;x4=0;break;
     case 2:x2=status;x3=status;x4=0;break;
     case 3:x2=status;x3=status;x4=status;break;
   }

   PageAddressSet();
   ColumnAddressSet(0x05);
   
 
   DisplayDataWrite((x1<<1)|k3); //X1
   DisplayDataWrite(x2<<1); //X2
   DisplayDataWrite((x3<<1)|(orp<<2)); //X3
   DisplayDataWrite((x4<<1)|(tds<<2)|(k2<<3)); //X4 
   
   
}



/*****************************************/
void  Lcd_DisplayErrorWorkTable(unsigned char mode,unsigned char value,bit status)   //Error Or WorkTable
{
	unsigned char a1,a2,k1,flag;
	
	if(status==0)	
	{
		Er=0;
		ErrorWork1=0;
		k1=0;
		flag=0x00;
	}else{
		flag=0xff;
	}


         a2=value/10;
         a1=value%10;
         if(mode==Error)   //Error table
    	 {
            Er=status;
            PageAddressSet();
            ColumnAddressSet(0x13);
            DisplayDataWrite(Er|(day<<1)|(mv<<2)|(ppm<<3));  //Er
        	k1=0;
    	 }
         if(mode==WorkTable)      //WorkTable
    	 {
            k1=status;
            PageAddressSet();
            ColumnAddressSet(0x15);
            DisplayDataWrite(k1<<3);  //K1
    		if (value == 0)
			{a2=17;a1=17;}	
    	 }
         PageAddressSet();
         ColumnAddressSet(0x14);
         DisplayDataWrite((NUM1[a2]&0x0f)&flag);    		 
         DisplayDataWrite((((NUM1[a2]&0xf0)>>4)|(k1<<3))&flag);

         DisplayDataWrite((NUM1[a1]&0x0f)&flag);			 
         DisplayDataWrite(((NUM1[a1]&0xf0)>>4)&flag|(k4<<3));

         ErrorWork1=((NUM1[a1]&0xf0)>>4)&flag;
}
/***************************************************/
void  Lcd_DisplayCSECLmin(unsigned char mode,unsigned int value,bit status)   //C SEC L/MIN
{
       unsigned char a1,a2,a3,flag,flag1=1;
       
       	 	
        if(status==0)	
        {
           c1=0;
           sec1=0;
           min1=0;
           flag=0x00;

           a3=value/100;
           a2=value/10%10;
           a1=value%10;
        }
        else flag=0xff;
         
		 if(mode==C_wendu)   //C_wendu
    	 {
            c1=status;
            PageAddressSet();
            ColumnAddressSet(0x29);
            DisplayDataWrite(r4|(c1<<1)); 
            picture4=c1<<1; 

            a3=value/100;
           a2=value/10%10;
           a1=value%10;
    	 }
         if(mode==SEC)    //SEC
    	 {
            sec1=status;
            PageAddressSet();
            ColumnAddressSet(0x29);
            DisplayDataWrite(r4|(sec1<<2)); 
            picture4=sec1<<2;

            a3=value/100;
            a2=value/10%10;
            a1=value%10;
    	 }
         if(mode==__SHOW_LPM__)   //Lmin
    	 {
            min1=status;
            PageAddressSet();
            ColumnAddressSet(0x29);
            DisplayDataWrite(r4|(min1<<3)); // Display Lmin  
            picture4=min1<<3;
            a3=value/100;
            a2=value/10%10;
            a1=value%10;
    	 }
         if(mode==4)   // no display dan wei
    	 {
    	
            PageAddressSet();
            ColumnAddressSet(0x29);
            DisplayDataWrite(r4); 
            picture4=0;
            flag1=0;
			a3 = value/100;
            a2=value/10%10;
           a1=value%10;
    	 }
         if(mode==5)  //display  current
    	 {
            a3=10;
           a2=value/10;
           a1=value%10;
    	 }
         if(mode==6) //display "ALL"
    	 {
             
            PageAddressSet();
            ColumnAddressSet(0x29);
            DisplayDataWrite(r4); 
            picture4=0;
            flag1=0;
            a3=10;
            a2=20;
           a1=20;
    	 }
         if(mode==7)   //display  30.L
    	 {
            PageAddressSet();
            ColumnAddressSet(0x29);
            DisplayDataWrite(r4); 
            picture4=0;
            a3=value/10;
            a2=value%10;
            a1=20;
    	 }
         PageAddressSet();
         ColumnAddressSet(0x23);
         DisplayDataWrite((NUM5[a3]&0x0f)&flag);    		 
         DisplayDataWrite(((NUM5[a3]&0xf0)>>3)&flag);

         
         DisplayDataWrite((NUM5[a2]&0x0f)&flag);			 
         DisplayDataWrite(((NUM5[a2]&0xf0)>>3|flag1)&flag);
  	 
         DisplayDataWrite((NUM5[a1]&0x0f)&flag);    		 
         DisplayDataWrite(((NUM5[a1]&0xf0)>>3)&flag);
      
}
/*************************************************************/
void Lcd_Display_H(uchar koop)    
{
         uchar Loop, a5,a4,a3,a2,a1 ;
         Loop = koop ;

	    
 	 if (Loop == 5)	{a5=19,a4=16,a3=16,a2=16,a1=16 ;}
	 if (Loop == 4)	{a5=16,a4=19,a3=16,a2=16,a1=16 ;}  
	 if (Loop == 3)	{a5=16,a4=16,a3=19,a2=16,a1=16 ;}  
	 if (Loop == 2)	{a5=16,a4=16,a3=16,a2=19,a1=16 ;}  
	 if (Loop == 1)	{a5=16,a4=16,a3=16,a2=16,a1=19 ;} 

	   PageAddressSet();
       ColumnAddressSet(0x07); 
         
        PageAddressSet();
       ColumnAddressSet(0x09);
       DisplayDataWrite((NUM5[a5]&0x0f));
       DisplayDataWrite(((NUM5[a5]&0xf0)>>3)&0x0f);
       picture1=(((NUM5[a5]&0xf0)>>3)&0x0f);

       DisplayDataWrite((NUM5[a4]&0x0f));
       DisplayDataWrite(((NUM5[a4]&0xf0)>>3)&0x0f);
       picture3=(((NUM5[a4]&0xf0)>>3)&0x0f);

       DisplayDataWrite((NUM5[a3]&0x0f));
       DisplayDataWrite(((NUM5[a3]&0xf0)>>3)&0x0f); 		 
       picture5=(((NUM5[a3]&0xf0)>>3)&0x0f);         
       		 
       DisplayDataWrite((NUM5[a2]&0x0f));     	 
       DisplayDataWrite((NUM5[a2]&0xf0)>>3);
    	 
      DisplayDataWrite((NUM5[a1]&0x0f));       	 
      DisplayDataWrite(((NUM5[a1]&0xf0)>>3));
      picture2=((NUM5[a1]&0xf0)>>3);
}
/*************************************************************/
void  Lcd_Display_Count(unsigned long value)   //ph 
{
       uchar  a5,a4,a3,a2,a1;
	    unsigned long temp;
 
        
		    a5= 17 ;      //blank  
	      temp=value;
        
		  a4=(uchar)(temp/100);
          
		  a3=(uchar)(temp/10%10);
          
		  a2=(uchar)(temp%10);
          
		  a1=17;
   	      ppm = 0;
		  tds = 0;

       PageAddressSet();
       ColumnAddressSet(0x07);
   
       PageAddressSet();
       ColumnAddressSet(0x09);
       DisplayDataWrite((NUM5[a5]&0x0f));
       DisplayDataWrite(((NUM5[a5]&0xf0)>>3)&0x0f);
       picture1=(((NUM5[a5]&0xf0)>>3)&0x0f);

       DisplayDataWrite((NUM5[a4]&0x0f));
       DisplayDataWrite(((NUM5[a4]&0xf0)>>3)&0x0f);
       picture3=(((NUM5[a4]&0xf0)>>3)&0x0f);

       DisplayDataWrite((NUM5[a3]&0x0f));
       DisplayDataWrite(((NUM5[a3]&0xf0)>>3)&0x0f); 		 
       picture5=(((NUM5[a3]&0xf0)>>3)&0x0f);         
       		 
       DisplayDataWrite((NUM5[a2]&0x0f));     	 
       DisplayDataWrite((NUM5[a2]&0xf0)>>3);
    	 
      DisplayDataWrite((NUM5[a1]&0x0f));       	 
      DisplayDataWrite(((NUM5[a1]&0xf0)>>3));
      picture2=((NUM5[a1]&0xf0)>>3);
}
/**************************************************/
void  Lcd_DisplayValue(unsigned char mode,unsigned long value,bit status,bit value_flag)   //ph 
{
	uchar a5,a4,a3,a2,a1,flag,flag1=1;
	unsigned long temp;

	if(status==0)
	{
		flag=0x00;
	}
	else
	{
		flag=0xff;
		orp=0;
		day=0;
		
	}		       


	switch(mode)
	{
		case 1:		//display japan
		{
			flag1=0 ;//dot for d4
			orp=0 ;
			day=0 ;
			
			a5=23;   //J	   23,10,18,10,22
			a4=10;   //A
			a3=18;   //P
			a2=10;   //A
			a1=22;   //N
			ppm =0;
			tds =0;	
		}
		break; 
		
		/****************************************/		  
		case 4:		//display orp
		{
			if(value_flag==1)  
			{
				a5=16;   // fu "-"
			}
			else
			{	
				a5= 17;  //blank        zhen
			}
			
			flag1=0;
			orp=1;
			day=0;
			
			if(value >= 999){ value = 999 ;}
			temp=value;
			a4=(uchar)(temp/100);
			a3=(uchar)(temp/10%10);
			a2=(uchar)(temp%10);
			a1=17;
			ppm = 0;
			tds = 0;
		}  
		break;
	
		/*********************************/
		case 7:		 //display day
		{
			orp=0;
			day=1;
			flag1=0;
			temp = value;
			a5=17; //  blank
			temp = value;
			a4=(unsigned char)(temp/1000);
			temp = value % 1000;
			a3=(unsigned char)(temp/100);
			temp = value % 100;
			a2=(unsigned char)(temp/10);
			temp = value % 10;
			a1=(unsigned char)temp;
			ppm = 0;
			tds = 0;
		}
		break;
		/*******************************/
		case 8:	   // show TDS
		{
			orp=0;
			day=0;
			ppm = 1;
			tds = 1;
			flag1=0;
			a1=17; // blank
			a5=17; // blank
			temp = value;
			a4=(unsigned char)(temp/100);
			temp = value % 100;
			a3=(unsigned char)(temp/10);
			temp = value % 10;
			a2=(unsigned char)temp;
		}
		break;
		/***************************************/
		case 9:	     // show Language
		{
			orp=0;
			day=0;
			ppm = 0;
			tds = 0;
			flag1=0;
			a4 =17;
			a5 =17;
		
			switch(value)
			{
				case __MENU_LANG_JPN__:   //JPN
					a3=23;
					a2=18;
					a1=22;
					break;
				case __MENU_LANG_ENG__:   //ENG
					a3=14;
					a2=22;
					a1=6;
					break;
				case __MENU_LANG_CHT__:   //CHI
					a3=12;
					a2=19;
					a1=1;
					break;
			}
		}
		break;
		/****************************************/
		case __MENY_MACHINE_ID__:		// show Machine_ID

			flag1=0;
			orp=0;
			day=0;
			
			a5=Machine_ID[value][0] ;
			a4=Machine_ID[value][1] ;
			a3=Machine_ID[value][2] ;
			a2=Machine_ID[value][3] ;
			a1=Machine_ID[value][4] ; 
			
			ppm = 0;
			tds = 0;

			break;
		/****************************************/	 
		case 11:  //work 11 display SAVE

			orp=0;
			flag1=0;
			day=0;
			a5=5;    //  S
			a4=10;   //  A
			a3=21;   //  U
			a2=14;   //  E
			a1=17;   //  BLANK
			ppm = 0;
			tds = 0;
	
			break;
		/*************************************/
		case 12:  //Ajust 6 display CLEAN

			orp=0;
			flag1=0;
			day=0;
			a5=12; //  C
			a4=20; //  L
			a3=14; //  E
			a2=10; //  A
			a1=22; //  N
			ppm = 0;
			tds = 0;

			break;
	}
	/*********  DISPLAY  FUNCTION  **************/
	
	PageAddressSet();
	ColumnAddressSet(0x13);
	DisplayDataWrite(Er|(day<<1)|(mv<<2)|(ppm<<3));  //day
	
	PageAddressSet();
	ColumnAddressSet(0x07);
	
	//       DisplayDataWrite((x3<<1)|(orp<<2));              //orp
	//       DisplayDataWrite((x4<<1)|(tds<<2)|(k2<<3));      //tds
	
	PageAddressSet();
	ColumnAddressSet(0x09);
	DisplayDataWrite((NUM5[a5]&0x0f)&flag);
	DisplayDataWrite((((NUM5[a5]&0xf0)>>3)&0x0f&flag)|r1);
	picture1=((NUM5[a5]&0xf0)>>3)&0x0f&flag;
	//---------------------------------------------
	DisplayDataWrite((NUM5[a4]&0x0f)&flag);
	DisplayDataWrite((((NUM5[a4]&0xf0)>>3)&0x0f&flag)|r3);
	picture3=((NUM5[a4]&0xf0)>>3)&0x0f&flag;
	//---------------------------------------------
	
	DisplayDataWrite((NUM5[a3]&0x0f)&flag);
	DisplayDataWrite(((NUM5[a3]&0xf0)>>3)&0x0f&flag|r5); 		 
	picture5=((NUM5[a3]&0xf0)>>3)&0x0f&flag;         
	
	DisplayDataWrite((NUM5[a2]&0x0f)&flag);     	 
	DisplayDataWrite(((NUM5[a2]&0xf0)>>3|flag1)&flag);
	
	DisplayDataWrite((NUM5[a1]&0x0f)&flag);       	 
	DisplayDataWrite((((NUM5[a1]&0xf0)>>3)&flag)|r2);
	picture2=((NUM5[a1]&0xf0)>>3)&flag;
	
}
	
	

/**********  WATER MAP   ***************************/

void Lcd_DisplayPicture(unsigned char Value,bit status)   //r1 r2 r3 r4 r5 r6
{
    switch(Value)
   {
     case 5:r1=status;r2=status;r3=status;r4=status;r5=status;r6=status;break;

     case 1:r1=0;r2=status;r3=0;r4=0;r5=0;r6=0;break;

     case 2:r1=status;r2=status;r3=0;r4=status;r5=0;r6=0;break;

     case 3:r1=status;r2=0;r3=status;r4=status;r5=0;r6=status;break;

     case 4:r1=0;r2=status;r3=status;r4=0;r5=status;r6=status;break;

   }

   PageAddressSet();
   ColumnAddressSet(0x0a);
   DisplayDataWrite(picture1|r1);
 
   PageAddressSet();
   ColumnAddressSet(0x12);
   DisplayDataWrite(picture2|r2);
       
   PageAddressSet();
   ColumnAddressSet(0x0c);
   DisplayDataWrite(picture3|r3);
       
            							
   PageAddressSet();
   ColumnAddressSet(0x29);
   DisplayDataWrite(r4|picture4);  
    		
    PageAddressSet();
    ColumnAddressSet(0x0e);
    DisplayDataWrite(picture5|r5);  	
     

    PageAddressSet();
    ColumnAddressSet(0x04);
    DisplayDataWrite(picture6|r6); 
    	
}
/**********************************************/
void Lcd_Backlight(unsigned char BacklightValue)
{

	switch(BacklightValue)
	{
		case NOCOLOR:		  //dark  0
		
		RGB(0,0,0);
		//CCAPM0=0x40; 
		CCAPM1=0x40; 
		CCAPM2=0x40; 
//		red_   = 0;
//		green_ = 0;
//		blue_  = 0;
		break;
	
	case PURPLE: 		    //1
	   RGB(95,000,220);
	   break;
	
	case BLUENESS:		     //2
	   RGB(015,010,170);
	   break;
	
	case WHITE:			 //3
	   RGB(000,010,60);
	   break;
	
	case YELLOW:			 //4
	   RGB(255,0,255);
	   break;
	
	case  BLUE:			 //5
	   RGB(000,000,255);
	   break;
	
	case ORANGE: 
	   RGB(255,255,000); //6
	   break;
	
	
	case GREEN:			 //7
	   RGB(000,255,000);
	   break;
	
	case RED: 			  //8
		RGB(255,000,000);
		break;
	}

}
/************************************/ 