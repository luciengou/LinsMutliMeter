/***********************************************
  PRODUCT FOR NEWCAL MIX_TEMP FUNCTION
   CPU : MPC82G516
   BEGIN DATE: 2013.11.01
   FINISHED  : 2014.01.25
   WRITEBY   :JOHNSON LIN
   AD3421  setup   SET 1001 0000 FOR A0 TYPE 
    8CH =  pga =1 ,32767BITS
**************************************************/
#include <MG82FE564.H>
#include <AD3421.h>
#include <IO_DEFINE.h>
#define   read_com  0xd1    //    11010001
#define   write_com 0xd0    //    10010000
#define   ic_com    0x9C    //    define PGA and counter

unsigned char  ad_ack;      // bit array of error types

extern unsigned char AD_Hi,AD_Mid,AD_Lo;
extern unsigned char AD_Status;
extern void delay(unsigned int i);
extern idata unsigned char Soft_Timer[8];

/********************************************************/
unsigned char Get_AD3421_Value(void)
{
 idata unsigned char res;
  res = 0;
  AD3421_Init();
  AD3421_write_com(write_com,ic_com);
  AD3421_read_com(read_com);
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
	unsigned char i;
	Value_SCL = 1 ;
	AD_BitDly();
	Value_SDA = 1 ;
 	AD_BitDly();
	AD_BitDly();
	AD_BitDly();
	AD_BitDly();
	Value_SDA = 0;

	for(i = 0; i < 0xfe; i++);    
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
		  {Value_SDA = 1;}                      // send each bit, MSB first
		else
		 {Value_SDA = 0;}

		Value_SCL = 1;
		AD_BitDly();
		Value_SCL = 0;
		AD_BitDly();
		bt = bt << 1;
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
		res = res << 1;
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
unsigned char AD3421_read_com(unsigned char dev_id)
{
  unsigned char i; 
	 AD3421_start();				  //send start bit
	 AD3421_write_byte(dev_id);		  //send address byte
	 AD_Hi = AD3421_read_byte(0);      //get high data
	 AD_Mid = AD3421_read_byte(0);	  //get high data
	 AD_Lo =  AD3421_read_byte(0);	  //get low data
	 AD_Status =  AD3421_read_byte(1);
	 AD3421_stop(); 
	 i = AD_Status & 0x80 ;
	return i; 
}
/************************************/