/***********************************************
  PRODUCT FOR NEWCAL MIX_TEMP FUNCTION
   CPU : MPC82G516
   BEGIN DATE: 2013.11.01
   FINISHED  : 2014.01.25
   WRITEBY   :JOHNSON LIN
   AD111  setup   SET 1001 0000 FOR A0 TYPE 
    8CH =  pga =1 ,32767BITS
**************************************************/
#include <MPC82G516.h>
#include <AD111.h>
#include <COUNTER.H>



#define   read_com  0x91    //    10010001
#define   write_com 0x90    //    10010000
#define   ic_com    0x8C    //    define PGA and counter

sbit Value_SCL  = P2^6;
sbit Value_SDA  = P2^7;
sbit BEEP       = P3^4;	 //for relay
unsigned char  _i2c_ack;      // bit array of error types

extern unsigned char Value_Hi,Value_Lo;
extern void delay(unsigned int i);
extern idata unsigned char Soft_Timer[8];

/********************************************************/
unsigned int Get_AD111_Value(void)
{
 idata unsigned int res;
  res = 0;
  AD111_Init();
  AD111_write_com(write_com,ic_com);
  AD111_read_com(read_com,ic_com);
  return(res);
}
/*******************************************************************/
void _i2cBitDly(void)               // wait 4.7uS, or thereabouts
{                                   // tune to xtal. This works at 11.0592MHz
	unsigned char	i;
	
	for (i=0; i<0x12; i++);
}
/*****************************************************/
void AD111_Init(void)
{
	unsigned int i;
	Value_SCL = 1 ;
	Value_SDA = 1 ;
    Value_SDA = 1 ;
	Value_SDA = 1 ;
	_i2cBitDly();
	_i2cBitDly();
	_i2cBitDly();
	_i2cBitDly();
	Value_SDA = 0;

	for(i = 0; i < 0x100; i++);    
}
/*********************************************************************/
void AD111_start(void)
{
	Value_SDA = 1 ;
	_i2cBitDly();
	Value_SCL = 1 ;
	_i2cBitDly();
   Value_SDA = 0 ;
   _i2cBitDly();
   Value_SCL = 0 ;
}
/*************************************/
void AD111_stop(void)
{
	Value_SCL = 1 ;
	_i2cBitDly();
    Value_SDA = 1 ;
	_i2cBitDly();
}
/********************************************/
void AD111_write_byte(unsigned char bt)
{
	idata unsigned char i;

	_i2c_ack = TRUE;						//default have ack
  
	for (i=0; i<8; i++)
	{
		if (bt & 0x80)
		Value_SDA = 1;                      // send each bit, MSB first
		else
			Value_SDA = 0;
		Value_SCL = 1;
		_i2cBitDly();
		Value_SCL = 0;
		_i2cBitDly();
		bt <<= 1;
	}

	Value_SDA = 1;                       // change input and listen for ACK
	Value_SCL = 1;
	_i2cBitDly();
	if (Value_SDA)
		_i2c_ack = FALSE;             		// ack didn't happen, may be nothing out there
	Value_SCL = 0;
	_i2cBitDly();
}
/********************************************************/
unsigned char AD111_read_byte(unsigned char lastbyte) 	// lastone == 1 for last byte
{
  	idata unsigned char i, res;
	res = 0;
	Value_SDA = 1;
	for (i=0; i<8; i++)                 // each bit at a time, MSB first
	{
		Value_SCL = 1;
		_i2cBitDly();
		res <<= 1;
		if (Value_SDA)		res |= 1;
		Value_SCL = 0;
		_i2cBitDly();
	}
	Value_SDA = lastbyte;              	// send ACK according to 'lastone'
	Value_SCL = 1;
	_i2cBitDly();
	Value_SCL = 0;
	Value_SDA = 1;
	_i2cBitDly();
	return(res);
}
/********************************************************/
void AD111_write_com(unsigned char dev_id, unsigned char reg_addr)
{
	 AD111_start();								//send start bit
	 AD111_write_byte((dev_id));
	 AD111_write_byte(reg_addr);               //send high address
	 AD111_stop();                              //stop
}
/*****************************************************/
unsigned int AD111_read_com(unsigned char dev_id, unsigned char reg_addr)
{
	unsigned int i;

	 AD111_start();										//send start bit
	 AD111_write_byte(dev_id);					//send address byte
	i = ((unsigned int)  AD111_read_byte(0)) << 8;     //get high data
	i |=  AD111_read_byte(1);						  //get low data
	AD111_write_byte(reg_addr);
	AD111_stop();                              //stop
    
	return i;
}
/************************************/





















/************************************/
void S_Delay(unsigned int n)
{
 	while(n--);
}
/****************************************/
void PlaySound(unsigned char n)
{
	if(n==1)
	  { BEEP = 1;}
	  else 
	   { BEEP = 0 ;}
} 