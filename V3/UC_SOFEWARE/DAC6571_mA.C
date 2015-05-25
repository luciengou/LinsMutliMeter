/***********************************************
  PRODUCT FOR NEWCAL MIX_TEMP FUNCTION
   CPU : MPC82G516
   BEGIN DATE: 2013.11.01
   FINISHED  : 2014.01.25
   WRITEBY   :JOHNSON LIN
   DAC6571mA  setup   SET 1001 0000 FOR A0 TYPE 
    8CH =  pga =1 ,32767BITS
**************************************************/
#include <MPC82G516.h>
#include <DAC6571_mA.h>

#define   mA_COM  0x98    //    10011000

sbit mA_SDA   = P2^2;
sbit mA_SCL   = P2^4;

sbit BEEP_OUT   = P3^4;
unsigned char  _mA_ack;      // bit array of error types

extern unsigned char Value_Hi,Value_Lo;
extern void delay(unsigned int i);
extern idata unsigned char Soft_Timer[8];

/********************************************************/
void _mABitDly(void)               // wait 4.7uS, or thereabouts
{                                   // tune to xtal. This works at 11.0592MHz
	unsigned char	i;
	
	for (i=0; i<0x12; i++);
}
/*****************************************************/
void DAC6571mA_Init(void)
{
	unsigned int i;
	mA_SCL = 1 ;
	_mABitDly();
	mA_SDA = 1 ;
 	_mABitDly();
	_mABitDly();
	_mABitDly();
	_mABitDly();
	mA_SDA = 0;

	for(i = 0; i < 0x100; i++);    
}
/*********************************************************************/
void DAC6571mA_start(void)
{
	mA_SDA = 1 ;
	_mABitDly();
	mA_SCL = 1 ;
	_mABitDly();
   mA_SDA = 0 ;
   _mABitDly();
   mA_SCL = 0 ;
}
/*************************************/
void DAC6571mA_stop(void)
{
	mA_SCL = 1 ;
	_mABitDly();
    mA_SDA = 1 ;
	_mABitDly();
}
/********************************************/
void DAC6571mA_write_byte(unsigned char bt)
{
	idata unsigned char i;

	_mA_ack = TRUE;						//default have ack
  
	for (i=0; i<8; i++)
	{
		if (bt & 0x80)
		mA_SDA = 1;                      // send each bit, MSB first
		else
			mA_SDA = 0;
		mA_SCL = 1;
		_mABitDly();
		mA_SCL = 0;
		_mABitDly();
		bt <<= 1;
	}

	mA_SDA = 1;                       // change input and listen for ACK
	mA_SCL = 1;
	_mABitDly();
	if (mA_SDA)
		_mA_ack = FALSE;             		// ack didn't happen, may be nothing out there
	mA_SCL = 0;
	_mABitDly();
}
/********************************************************/
void Set_mA(unsigned int mA_Value)
{
 unsigned int mA_CODE;
 unsigned char HI_CODE, LO_CODE;			// 0000 00 dd dddd dddd
     
	     mA_CODE = mA_Value;
		 HI_CODE = mA_CODE >> 6 ;			// 0000 dddd dddd ddxx 

		 mA_CODE = mA_Value;
		 LO_CODE = mA_CODE << 2;
		 LO_CODE = LO_CODE & 0xfc;

	 DAC6571mA_start();								//send start bit
	 DAC6571mA_write_byte(mA_COM);
	 DAC6571mA_write_byte(HI_CODE);               //send hi address
	 DAC6571mA_write_byte(LO_CODE);               //send lo address
	 DAC6571mA_stop();                              //stop
}
/*****************************************************/
void mA_Delay(unsigned int n)
{
 	while(n--);
}
/****************************************/
