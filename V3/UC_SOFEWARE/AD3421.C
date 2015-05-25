/***********************************************
  PRODUCT FOR NEWCAL MIX_TEMP FUNCTION
   CPU : MPC82G516
   BEGIN DATE: 2013.11.01
   FINISHED  : 2014.01.25
   WRITEBY   :JOHNSON LIN
   AD3421  setup   SET 1001 0000 FOR A0 TYPE 
    8CH =  pga =1 ,32767BITS
**************************************************/
#include <MPC82G516.h>
#include <AD3421.h>

#define   read_com  0x91    //    10010001
#define   write_com 0x90    //    10010000
#define   ic_com    0x8C    //    define PGA and counter

sbit Value_SDA  = P2^0;
sbit Value_SCL  = P2^1;
sbit BEEP       = P3^4;	 //for relay

unsigned char  ad_ack;      // bit array of error types

extern unsigned char Value_Hi,Value_Lo;
extern void delay(unsigned int i);
extern idata unsigned char Soft_Timer[8];

/********************************************************/
unsigned int Get_AD3421_Value(void)
{
 idata unsigned int res;
  res = 0;
  AD3421_Init();
  AD3421_write_com(write_com,ic_com);
  AD3421_read_com(read_com,ic_com);
  return(res);
}
/*******************************************************************/
void AD_BitDly(void)               // wait 4.7uS, or thereabouts
{                                   // tune to xtal. This works at 11.0592MHz
	unsigned char	i;
	
	for (i=0; i<0x12; i++);
}
/*****************************************************/
void AD3421_Init(void)
{
	unsigned int i;
	Value_SCL = 1 ;
	AD_BitDly();
	Value_SDA = 1 ;
 	AD_BitDly();
	AD_BitDly();
	AD_BitDly();
	AD_BitDly();
	Value_SDA = 0;

	for(i = 0; i < 0x100; i++);    
}
/*********************************************************************/
void AD3421_start(void)
{
	Value_SDA = 1 ;
	AD_BitDly();
	Value_SCL = 1 ;
	AD_BitDly();
   Value_SDA = 0 ;
   AD_BitDly();
   Value_SCL = 0 ;
}
/*************************************/
void AD3421_stop(void)
{
	Value_SCL = 1 ;
	AD_BitDly();
    Value_SDA = 1 ;
	AD_BitDly();
}
/********************************************/
void AD3421_write_byte(unsigned char bt)
{
	idata unsigned char i;

	ad_ack = TRUE;						//default have ack
  
	for (i=0; i<8; i++)
	{
		if (bt & 0x80)
		Value_SDA = 1;                      // send each bit, MSB first
		else
			Value_SDA = 0;
		Value_SCL = 1;
		AD_BitDly();
		Value_SCL = 0;
		AD_BitDly();
		bt <<= 1;
	}

	Value_SDA = 1;                       // change input and listen for ACK
	Value_SCL = 1;
	AD_BitDly();
	if (Value_SDA)
		ad_ack = FALSE;             		// ack didn't happen, may be nothing out there
	Value_SCL = 0;
	AD_BitDly();
}
/********************************************************/
unsigned char AD3421_read_byte(unsigned char lastbyte) 	// lastone == 1 for last byte
{
  	idata unsigned char i, res;
	res = 0;
	Value_SDA = 1;
	for (i=0; i<8; i++)                 // each bit at a time, MSB first
	{
		Value_SCL = 1;
		AD_BitDly();
		res <<= 1;
		if (Value_SDA)		res |= 1;
		Value_SCL = 0;
		AD_BitDly();
	}
	Value_SDA = lastbyte;              	// send ACK according to 'lastone'
	Value_SCL = 1;
	AD_BitDly();
	Value_SCL = 0;
	Value_SDA = 1;
	AD_BitDly();
	return(res);
}
/********************************************************/
void AD3421_write_com(unsigned char dev_id, unsigned char reg_addr)
{
	 AD3421_start();								//send start bit
	 AD3421_write_byte((dev_id));
	 AD3421_write_byte(reg_addr);               //send high address
	 AD3421_stop();                              //stop
}
/*****************************************************/
unsigned int AD3421_read_com(unsigned char dev_id, unsigned char reg_addr)
{
	unsigned int i;

	 AD3421_start();							        //send start bit
	 AD3421_write_byte(dev_id);					        //send address byte
	i = ((unsigned int)  AD3421_read_byte(0)) << 8;     //get high data
	i |=  AD3421_read_byte(1);						    //get low data
	AD3421_write_byte(reg_addr);
	AD3421_stop();                                      //stop
    
	return i;
}
/************************************/
/********************************/
void AD_Delay(unsigned int n)
{
 	while(n--);
}
/****************************************/
