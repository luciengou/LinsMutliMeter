/***********************************************
  PRODUCT FOR NEWCAL MIX_TEMP FUNCTION
   CPU : MPC82G516
   BEGIN DATE: 2013.11.01
   FINISHED  : 2014.01.25
   WRITEBY   :JOHNSON LIN
   DAC6571mV  setup   SET 1001 0000 FOR A0 TYPE 
    8CH =  pga =1 ,32767BITS	0x98 0x10 dd dd
**************************************************/
#include <MG82FE564.H>
#include <DAC6571_mV.h>
#include <IO_DEFINE.h>
#define   ADDR_CODE 0x98    //   0x98 for 8571

unsigned char  _mV_ack;      // bit array of error types
unsigned char Value_Hi,Value_Lo;
extern unsigned char  NP_COD;
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
		   {mV_SDA = 1;}                      // send each bit, MSB first
		else
		   {mV_SDA = 0;}
		mV_SCL = 1;
		_mVBitDly();
		mV_SCL = 0;
		_mVBitDly();
		bt = bt << 1;
	}

	mV_SDA = 1;                       // change input and listen for ACK
	mV_SCL = 1;
	_mVBitDly();
	if (mV_SDA)
	  {_mV_ack = FALSE;}             		// ack didn't happen, may be nothing out there
	mV_SCL = 0;
	_mVBitDly();
}
/********************************************************/
void Set_mV(unsigned int mV_V)
{
    unsigned char HI_CODE;
    unsigned char LO_CODE; 

	 HI_CODE =0 ;  LO_CODE = 0;		//   0000   aaaa bbbb ccxx 

		if(NP_COD == 0)
		 LO_CODE = mV_V ;			
		 HI_CODE = mV_V >> 8;
//		 HI_CODE &= HI_CODE & 0x0f;

	 DAC6571mV_start();								//send start bit
	 DAC6571mV_write_byte(0x98);
	 DAC6571mV_write_byte(0x10);               //send hi address
	 DAC6571mV_write_byte(HI_CODE);               //send lo address
	 DAC6571mV_write_byte(LO_CODE); 
	 DAC6571mV_stop();                              //stop
}
/************************************/												 
void mV_Delay(unsigned int n)
{
 	while(n--);
}
/****************************************/