/***********************************************
  PRODUCT FOR NEWCAL MIX_TEMP FUNCTION
   CPU : MPC82G516
   BEGIN DATE: 2013.11.01
   FINISHED  : 2014.01.25
   WRITEBY   :JOHNSON LIN
   DAC6571mV  setup   SET 1001 0000 FOR A0 TYPE 
    8CH =  pga =1 ,32767BITS
**************************************************/
#include <MPC82G516.h>
#include <DAC6571_mV.h>

#define   ADDR_CODE 0x9A    //    10011010


sbit mV_SDA   = P2^2;
sbit mV_SCL   = P2^4;

sbit BEEP_OUT   = P3^4;
unsigned char  _mV_ack;      // bit array of error types

extern unsigned char Value_Hi,Value_Lo;
extern void delay(unsigned int i);
extern idata unsigned char Soft_Timer[8];

/*******************************************************************/
void _mVBitDly(void)               // wait 4.7uS, or thereabouts
{                                   // tune to xtal. This works at 11.0592MHz
	unsigned char	i;
	
	for (i=0; i<0x12; i++);
}
/*****************************************************/
void DAC6571mV_Init(void)
{
	unsigned int i;
	mV_SCL = 1 ;
	_mVBitDly();
	mV_SDA = 1 ;
 	_mVBitDly();
	_mVBitDly();
	_mVBitDly();
	_mVBitDly();
	mV_SDA = 0;

	for(i = 0; i < 0x100; i++);    
}
/*********************************************************************/
void DAC6571mV_start(void)
{
	mV_SDA = 1 ;
	_mVBitDly();
	mV_SCL = 1 ;
	_mVBitDly();
   mV_SDA = 0 ;
   _mVBitDly();
   mV_SCL = 0 ;
}
/*************************************/
void DAC6571mV_stop(void)
{
	mV_SCL = 1 ;
	_mVBitDly();
    mV_SDA = 1 ;
	_mVBitDly();
}
/********************************************/
void DAC6571mV_write_byte(unsigned char bt)
{
	idata unsigned char i;

	_mV_ack = TRUE;						//default have ack
  
	for (i=0; i<8; i++)
	{
		if (bt & 0x80)
		mV_SDA = 1;                      // send each bit, MSB first
		else
			mV_SDA = 0;
		mV_SCL = 1;
		_mVBitDly();
		mV_SCL = 0;
		_mVBitDly();
		bt <<= 1;
	}

	mV_SDA = 1;                       // change input and listen for ACK
	mV_SCL = 1;
	_mVBitDly();
	if (mV_SDA)
		_mV_ack = FALSE;             		// ack didn't happen, may be nothing out there
	mV_SCL = 0;
	_mVBitDly();
}
/********************************************************/
void Set_mV(unsigned int mV_Value)
{
 unsigned int mV_CODE;
 unsigned char HI_CODE,LO_CODE;			// 0000 00 dd dddd dddd
     
	     mV_CODE = mV_Value;
		 HI_CODE = mV_CODE >> 6 ;			// 0000 dddd dddd ddxx 
		 mV_CODE = mV_Value;
		 LO_CODE = mV_CODE<<2;
		 LO_CODE = LO_CODE & 0xfc;

	 DAC6571mV_start();								//send start bit
	 DAC6571mV_write_byte(ADDR_CODE);
	 DAC6571mV_write_byte(HI_CODE);               //send hi address
	 DAC6571mV_write_byte(LO_CODE);               //send lo address
	 DAC6571mV_stop();                              //stop
}
/************************************/
void mV_Delay(unsigned int n)
{
 	while(n--);
}
/****************************************/
void PlaySound(unsigned char n)
{
	if(n==1)
	  { BEEP_OUT = 1;}
	  else 
	   { BEEP_OUT = 0 ;}
} 