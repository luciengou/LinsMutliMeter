/*******************************************
/*  	Project : A705-2
/*	David Chen
/*	2012/05/17
/*******************************************/

#include <MPC82G516.h>
#include <LCM.h>
#include <intrins.h>


//#define LCD_DATA 	P0
// Define control I/O for LCM back light
#define program_display  19
#define program_temp     35
#define program_Value    35
sbit BL_RED	    = P1^3;	// LCM back light control for red color using PCA module 1
sbit BL_GREEN	= P1^5;	// LCM back light control for green color using PCA module 2
sbit BL_BLUE	= P1^4;	// LCM back light control for blue color using PCA module 3

// Define Data[8], Data Latch, A0, CS, WR I/O signals of LCM
#define LCM_Data 	P0
sbit LCM_DataLE	= P2^0; 
sbit LCM_CS		= P2^6; 
sbit LCM_A0		= P3^4;
sbit LCM_WR		= P2^7;

const unsigned char code tab_8_to_15[23] = {
	0xAF,0xA0,0x6D,0xE9,0xE2,0xCB,0xCF,0xA1,0xEF,0xEB,0xE7,0xEF,0x0F,0xAF,0x4F,0x47,0xE6,0x67,0x00, 0xA7, 0x0E, 0x40, 0xAE  };
//     0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F    H    P BLANK    n    L     -	 U

const unsigned char code tab_1_to_5[11] = {
	0xAF,0xA0,0xCB,0xE9,0xE4,0x6D,0x6F,0xA8,0xEF,0xED,0x00};
//     0    1    2    3    4    5    6    7    8    9  BLANK

const unsigned char code tab_16[4] = {
	0x00, 0x85, 0xBE, 0x9F};
//   Blank    1     2     3

const unsigned char code tab_17[5] = {
	0x00, 0x05, 0xB6, 0x97, 0x47};
//   Blank   1     2     3     4

const unsigned char code tab_6_to_7[11] = {0x5F,0x50,0x6B,0x79,0x74,0x3D,0x3F,0x58,0x7F,0x7D,0x6E};//0x7E,0x37,0x0F,0x73,0x2F,0x2E};
//                               dp bgc afed
#define FC_PerSec_of_OneLiterPerMin 50

// Define DDRAM mapping of LCM
unsigned int KX=0x03F8;  // for K1~K9 and X1~X4 of LCM
unsigned int R=0;	// for R1~R6 , 9SP, 12SP
unsigned char S41=0;
unsigned char  first_power=1;
/*******************************************************/
/***************************************************************/
void RGB(unsigned char r, unsigned char g, unsigned char b) 
{ 
	CCAP1L=CCAP1H=~r;   CCAP2L=CCAP2H=~b;   CCAP3L=CCAP3H=~g;

	CMOD=0x00; 
	CL=0x00;
	CH=0x00;

	CCAPM1=0x42; 	//PCA module 1
	CCAPM2=0x42; 	//PCA module 2
	CCAPM3=0x42; 	//PCA module 3

	CR=1;
	CCON= 0x1f;
	CR=1;
	
}
/****************************************************/
void LCM_Backlight(unsigned char BacklightValue)
{
	switch(BacklightValue)
	{
		case BL_NoColor:			//0
			RGB(0,0,0);
			CR = 0;
			break;
	
		case BL_Purple:			//1
			RGB(95,0,220);
			break;
	
		case BL_BrightBlue:		     //2
			RGB(30,0,255);      //00,0,255);
			break;
	
		case BL_Blue:				//3
			RGB(15,0,255);      //(15,10,170);
			break;
	
		case BL_DarkBlue:			//4
			RGB(0,0,255);       //  000,010,60);
			break;
	
		case BL_Green:				//5
			RGB(0,255,0);
			break;

		case BL_Yellow:			//6
			RGB(255,255,0);    //100,180,000
			break;
	
		case BL_Orange:			//7
			RGB(255,180,0);     //255,255,0);
			break;
	
		case BL_Red:				//8
			RGB(255,0,0);
			break;
	}
}
/*****************************************/
void LCM_CMD_Write(unsigned char Value)
{
     LCM_DataLE=1;
     LCM_Data=Value;
	_nop_();
	_nop_();
   	_nop_();
	_nop_();
	LCM_DataLE=0;

	LCM_A0=1;
	_nop_();
	LCM_CS=0;
	_nop_();
	LCM_WR=0;
	_nop_();
	_nop_();
	_nop_();
	LCM_WR=1;
	_nop_();
	_nop_();
	LCM_CS=1;
	_nop_();
	_nop_();
}
/************************************************/
void LCM_DATA_Write(unsigned char Value)
{
     LCM_DataLE=1;
     LCM_Data=Value;
	_nop_();
	_nop_();
	_nop_();
   	_nop_();
	LCM_DataLE=0;

	LCM_A0=0;
	_nop_();
	LCM_CS=0;
	_nop_();
	LCM_WR=0;
	_nop_();
	_nop_();
	_nop_();
	LCM_WR=1;
	_nop_();
	_nop_();
	LCM_CS=1;
	_nop_();
	_nop_();
}
/*************************************************/
void LCM_ColumnAddress(unsigned char address)
{

    LCM_CMD_Write(0x10+(address>>4)); 	//X6 X5 X4  
    _nop_();
    _nop_();
    LCM_CMD_Write(address&0x0f);     	//X3 X2 X1 X0
    _nop_();
    _nop_();
}
/**********************************************/
void LCM_Fill(void)
{
	unsigned char c;

	LCM_CMD_Write(0xB0);	//PageAddressSet();

	LCM_ColumnAddress(0x00);
	for (c=0; c<=41; c++)
		LCM_DATA_Write(0xff);
}
/************************************************/
void LCM_Cls(void)
{
	unsigned char c;

	LCM_CMD_Write(0xB0);	//PageAddressSet();

	LCM_ColumnAddress(0x00);
	for (c=0; c<=41; c++)
		LCM_DATA_Write(0x00);
}
/****************************************************/
void LCM_Init(void)
{
	LCM_CS=1;
	LCM_WR=1;	
	_nop_();
	LCM_CMD_Write(0x2F);	//PowerControlSet();

	LCM_CMD_Write(0xB0);	//PageAddressSet();

	LCM_ColumnAddress(0x00);
	LCM_CMD_Write(0xF1);	//EnterModeSet();

	LCM_CMD_Write(0xAC);	//DutyModeSet();

	LCM_CMD_Write(0xF0);	//FinishModeSet();

	LCM_CMD_Write(0xA4);	//DisplayAllPointsOFF();

	LCM_CMD_Write(0xAF);	//DisplayON();

	LCM_CMD_Write(0xA6);	//DisplayNormal();

	LCM_CMD_Write(0xA1);	//SegmentDriverDirectionSelect();

	LCM_CMD_Write(0xC0);	//CommonDriverDirectionSelect();

	LCM_Cls();
}

/*****************************************************/
void LCM_Disp_Program_display(unsigned char c, unsigned int t)
{
	unsigned char c1, tmp;

	LCM_ColumnAddress(program_display);  
	LCM_DATA_Write(0x01);
	tmp = tab_6_to_7[10];
	LCM_DATA_Write(tmp);
	LCM_DATA_Write(tmp>>4);
	tmp = tab_6_to_7[c%10];
	LCM_DATA_Write(tmp);
	LCM_DATA_Write(tmp>>4);

	c1 = (unsigned char) (t/100);
	LCM_ColumnAddress(program_temp);
	tmp = tab_8_to_15[c1];
	LCM_DATA_Write(tmp);
	LCM_DATA_Write(tmp>>4);
	tmp = tab_8_to_15[(unsigned char) ((t/10)%10)];
	tmp |= 0x10;
	LCM_DATA_Write(tmp);
	LCM_DATA_Write(tmp>>4);

	tmp = tab_8_to_15[(unsigned char) (t%10)];
	LCM_DATA_Write(tmp);
	LCM_DATA_Write(tmp>>4);

	LCM_ColumnAddress(41);
	LCM_DATA_Write(0x02);	//C
}

/*********************************************************/
void LCM_Disp_VOL_K2K3(void)
{
	unsigned char tmp;

	LCM_ColumnAddress(5);
	tmp = 0;
	if (K3)	tmp |= 0x01;
	if (X1)	tmp |= 0x02;
	LCM_DATA_Write(tmp);		// Speak5
	tmp = (X2)?	0x02 : 0;
	LCM_DATA_Write(tmp);		// S6
	tmp = (X3)?	0x02 : 0;
	if (ORP)
		tmp |= 0x04;
	LCM_DATA_Write(tmp);		// S7
	tmp = (X4)?	0x02 : 0;
	if (K2)	tmp |= 0x08;
	LCM_DATA_Write(tmp);		// S8
}
/*******************************/
/*     display c,sec,L_min     */
/*******************************/
void LCM_Disp_S41(void)	   //temp c
{
	unsigned char tmp;

	LCM_ColumnAddress(41);	// S41
	tmp = S41;
	if (L_MIN)
		S41 |= 0x02;   //0x08
	else
		S41 &= ~0x02;
	if (R4)
		S41 |= 0x01;   //0x01
	else
		S41 &= ~0x01;
		
	LCM_DATA_Write(S41);
}
//======================================
void LCM_Disp_WaterFlow(unsigned int i) 
{
	unsigned char tmp, c1;

	SET_SP9();
	c1 = (unsigned char) (i/100);
	LCM_ColumnAddress(35);
	tmp = (c1)?	tab_8_to_15[c1] : 0;
	LCM_DATA_Write(tmp);
	LCM_DATA_Write(tmp>>4);
	tmp = tab_8_to_15[(unsigned char) ((i/10)%10)];
	if (SP9)
		tmp |= 0x10;
	LCM_DATA_Write(tmp);
	LCM_DATA_Write(tmp>>4);
	tmp = tab_8_to_15[(unsigned char) (i%10)];
	LCM_DATA_Write(tmp);
	LCM_DATA_Write(tmp>>4);
	CLR_SP9();

	SET_L_MIN();
	LCM_Disp_S41();				
}
/********************************************************/
void LCM_Disp_I_add(unsigned char c, unsigned char mode)
{	
	unsigned char c1, c2, c3;;

	LCM_ColumnAddress(program_Value);		
	if (mode == 0)				// all 7-seg off
	{
		LCM_DATA_Write(0);
		LCM_DATA_Write(0);
		LCM_DATA_Write(0);
		LCM_DATA_Write(0);
		LCM_DATA_Write(0);	
		LCM_DATA_Write(0);
	}
	else
	{
		if (c > 20)
		{
			if (c < 30)
			{
				c1 = 0;
				c2 = 0x40;
				c3 = tab_8_to_15[c%10];
			}
			else
			{
				c1 = 0x40;
				c = c-20;
				c2 = tab_8_to_15[c/10];
				c3 = tab_8_to_15[c%10];
			}
		}
		else
		{
			if (c > 10)
			{
				c1 = c2 = 0;
				c3 = tab_8_to_15[20-c];
			}
			else
			{
				c1 = 0;
				c = 20-c;
				c2 = tab_8_to_15[c/10];
				c3 = tab_8_to_15[c%10];
			}
		}

		LCM_DATA_Write(c1);
		LCM_DATA_Write(c1>>4);
		LCM_DATA_Write(c2);
		LCM_DATA_Write(c2>>4);
		LCM_DATA_Write(c3);
		LCM_DATA_Write(c3>>4);
	}
}
/**********************************************************/
void LCM_Disp_WashLiter(unsigned char c, unsigned char mode)
{	
	unsigned char tmp;

	LCM_ColumnAddress(34);	//35	
	if (mode == 0)				// all 7-seg off
	{
		LCM_DATA_Write(9);
		LCM_DATA_Write(9);
		LCM_DATA_Write(9);
		LCM_DATA_Write(9);
//		LCM_DATA_Write(14);		//'L'
		LCM_DATA_Write(9);
	}
	else
	{
		tmp = tab_8_to_15[(unsigned char) (c/10)];
		LCM_DATA_Write(tmp);
		LCM_DATA_Write(tmp>>4);
		tmp = tab_8_to_15[(unsigned char) (c%10)];
		LCM_DATA_Write(tmp);
		LCM_DATA_Write(tmp>>4);
//		LCM_DATA_Write(14);		//'L'
//		LCM_DATA_Write(0);			
	}
}

void LCM_Disp_Acid(unsigned char c)
{
	unsigned char tmp;

	LCM_ColumnAddress(0);
	tmp = tab_16[c];
	LCM_DATA_Write(tmp);
	LCM_DATA_Write(tmp>>4);
}
/*************************************************************/
void LCM_Disp_ORP(unsigned int ORP_Value, unsigned char ORP_Sign)
{
	unsigned char tmp;

	LCM_ColumnAddress(9);			//S9, S10
	if (ORP_Sign)
		tmp = tab_8_to_15[21];
	else
		tmp = 0;
	if (R1)
		tmp |= 0x10;
	LCM_DATA_Write(tmp);
	LCM_DATA_Write(tmp>>4);

	tmp = tab_8_to_15[ORP_Value/100];	//S11, S12
	if (R3)
		tmp |= 0x10;
	LCM_DATA_Write(tmp);
	LCM_DATA_Write(tmp>>4);

	tmp = tab_8_to_15[(ORP_Value/10)%10];	//S13, S14
	if (R5)
		tmp |= 0x10;
	LCM_DATA_Write(tmp);
	LCM_DATA_Write(tmp>>4);

	tmp = tab_8_to_15[ORP_Value%10];	//S15, S16
	if (SP12)
		tmp |= 0x10;
	LCM_DATA_Write(tmp);
	LCM_DATA_Write(tmp>>4);

	tmp = 0;						//S17, S18
	if (R2)
		tmp |= 0x10;
	LCM_DATA_Write(tmp);
	LCM_DATA_Write(tmp>>4);

	if (MV)	tmp = 0x04;
	LCM_DATA_Write(tmp);		// S19

	LCM_Disp_S41();
}
/******************************************/
void LCM_Disp_PH_and_R(unsigned int ORP_Value)
{
 	unsigned char tmp;

	LCM_ColumnAddress(9);			//S9, S10
	if (ORP_Value)
		tmp = tab_8_to_15[21];
//	else
//		tmp = 0;
	if (R1)
		tmp |= 0x10;
	LCM_DATA_Write(tmp);
	LCM_DATA_Write(tmp>>4);

	tmp = tab_8_to_15[(ORP_Value/1000)%10];	//S11, S12
	if (R3)
		tmp |= 0x10;
	LCM_DATA_Write(tmp);
	LCM_DATA_Write(tmp>>4);

	tmp = tab_8_to_15[(ORP_Value/100)%10];	//S13, S14
	if (R5)
		tmp |= 0x10;
	LCM_DATA_Write(tmp);
	LCM_DATA_Write(tmp>>4);

	tmp = tab_8_to_15[(ORP_Value/10)%10];	//S15, S16
	if (SP12)
		tmp |= 0x10;
	LCM_DATA_Write(tmp);
	LCM_DATA_Write(tmp>>4);
	tmp = tab_8_to_15[ORP_Value%10];	//S13, S14
	if (R5)
		tmp |= 0x10;
	LCM_DATA_Write(tmp);
	LCM_DATA_Write(tmp>>4);

	tmp = (MV)? 0x04 : 1;
	LCM_DATA_Write(tmp);		// S19

	LCM_Disp_S41();
}
/*=====================
mode = 0 : Normal Operation
mode = 1 : K4 = 0
mode = 2 : VL = 0
mode = 3 : K4, VL = 0
Display  setting temp
======================*/
void LCM_Disp_KL(unsigned int VL, unsigned char mode)
{
	unsigned char c;
	unsigned int  i;
   if(first_power ==1)
     {
	   LCM_ColumnAddress(23);
	   c = (mode & 0x01)?	0 : 0x0f;		// mode = 1 or 3
	   LCM_DATA_Write(c);
	   first_power=0;
	  }
	else
	  {
       LCM_ColumnAddress(23);
	   c = (mode & 0x01)?	0 : 0x08;		// mode = 1 or 3
	   LCM_DATA_Write(c);
	  }

	c = (unsigned char)(VL/10000);
	i = VL%10000;
	c = ((c==0)||(mode & 0x02))? 0 : tab_1_to_5[c];
	if (K5)
		c |= 0x00;
	LCM_DATA_Write(c);				// S30
	LCM_DATA_Write(c>>4);			// S25
	c = (unsigned char)(i/1000);
	i = VL%1000;
	c = (mode & 0x02)?	0 : tab_1_to_5[c];
		if (K6)
		c |= 0x00;
	LCM_DATA_Write(c);				// S30
	LCM_DATA_Write(c>>4);			// S27
	c = (unsigned char)(i/100);
	i = i%100;
	c = (mode & 0x02)?	0 : tab_1_to_5[c];
		if (K7)
		c |= 0x00;
	LCM_DATA_Write(c);				// S30
	LCM_DATA_Write(c>>4);			// S29

	c = (unsigned char)(i/10);
	i = i%10;
	c = (mode & 0x02)?	0 : tab_1_to_5[c];
	if (K8)
		c |= 0x00;
	LCM_DATA_Write(c);				// S30
	LCM_DATA_Write(c>>4);			// S31

	c = (unsigned char)(i);
	c = (mode & 0x02)?	0 : tab_1_to_5[c];
	if (K9)
		c |= 0x00;
	LCM_DATA_Write(c);				// S32
	LCM_DATA_Write(c>>4);			// S33
}
/**********************************************/
void LCM_Disp_Alka(unsigned char c)
{
	unsigned char tmp;

	LCM_ColumnAddress(2);
	tmp = tab_17[c];
	if (FILTER)			     // filter flag of LCM
		tmp |= 0x08;
	LCM_DATA_Write(tmp);
	LCM_DATA_Write(tmp>>4);
	tmp = 0;
	if (R6)				     // R6 flag of LCM
		tmp |= 0x01;
	if (ALKA)				// alkaline flag of LCM
		tmp |= 0x04;
	LCM_DATA_Write(tmp);
}
/************************************/ 