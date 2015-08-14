/************************************
**          RTC3130 DEVICE	       **
 00h = control code
   WRITE_COM = 02H must change to 00H when finished
   READ_COM  = 01H must change to 00H when finished
 00h= sec        0-59	BCD CODE
 01h= min   	   59
 02h= hour	       24
 03h= week	        7
 04h= day	       31
 05h= month		   12
 06h= year	    00-99
 07h= control code = 80H

 08h= alarm min
 09h= alarm hour

 0ch= alarm day
 0dh= alarm year
 0eh= control code	00H

*************************************/
#include <MG82FE564.H>
#include <MCP79411.h>
#include <IO_DEFINE.h>

#define  RTC_WRITE_COM  0xDE
#define  RTC_READ_COM   0xDF
#define  EEP_WRITE_COM  0xAE
#define  EEP_READ_COM   0xAF
#define  FINISHED_COM   0

#define  TRUE   1
#define  FALSE  0

unsigned char  RTC_ack ;
/*******************************/
void RTC_Delay(unsigned int i)
{
   unsigned char j;
  if(i>0) i--;
 for (j=0; j<250; j++);
}
//==============================
void RTC_BitDly(void)               // wait 4.7uS, or thereabouts
{                                   // tune to xtal. This works at 11.0592MHz
	unsigned char	i;
	
	for (i=0; i<0x12; i++);
}
//==============================
void RTC_Init(void)
{
	unsigned int i;

	RTC_SCL = 1;
	RTC_BitDly();
	RTC_BitDly();
	RTC_BitDly();
	RTC_SDA = 0;
	for(i = 0; i < 0x100; i++); 
}
//===================================
void RTC_start0(void)
{
 	RTC_SDA = 1;
	RTC_BitDly();
	RTC_SDA = 0;
	RTC_BitDly();
	RTC_SCL = 0;
	RTC_BitDly();
}
//====================================
void RTC_stop0(void)
{
	RTC_SDA = 0;
	RTC_BitDly();
	RTC_SCL = 1;
	RTC_BitDly();
	RTC_SDA = 1;
	RTC_BitDly();
}
//====================================
void RTC_restart0(void)
{
	RTC_SDA = 1;
	RTC_BitDly();
	RTC_SCL = 1;
	RTC_BitDly();
	RTC_SDA = 0;
	RTC_BitDly();
	RTC_SCL = 0;
	RTC_BitDly();  
}
//====================================
void RTC_write_byte0(unsigned char bt)
{
	idata unsigned char i;

     	RTC_ack = TRUE;						//default have ack
  
	for (i=0; i<8; i++)
	{
	     	if (bt & 0x80)
	     	   RTC_SDA = 1;         // send each bit, MSB first
		    else
		      RTC_SDA = 0;
		      RTC_BitDly();
		      RTC_SCL = 1;
		      RTC_BitDly();
		      RTC_SCL = 0;
		      RTC_BitDly();
		   bt <<= 1;
	}
	RTC_SDA = 1; 
	RTC_BitDly();	                               // change input and listen for ACK
	RTC_SCL = 1;
	RTC_BitDly();

	if (RTC_SDA){RTC_ack = FALSE;}             		// ack didn't happen, may be nothing out there
	    RTC_SCL = 0;
	    RTC_BitDly();
}
//======================================
unsigned char RTC_read_byte0(void) 	        // lastone == 1 for last byte
{
  	idata unsigned char i, res;
	res = 0;
	RTC_SDA = 1;

	for (i=0; i<8; i++)                 // each bit at a time, MSB first
	{
		RTC_SCL = 1;
	    RTC_BitDly();
		      res <<= 1;
		if (RTC_SDA)		res |= 1;
		    RTC_SCL = 0;
		    RTC_BitDly();
	}
	RTC_SDA = 1;                 	// send ACK according to 'lastone'
	RTC_SCL = 1;
	RTC_BitDly();
	RTC_SCL = 0;
	RTC_SDA = 1;
	RTC_BitDly();
	return(res);
}
//==========================================
void RTC_write_byte(unsigned char reg_addr, unsigned char reg_data)
{
	RTC_start0();						//send start bit
	RTC_write_byte0(RTC_WRITE_COM);
	RTC_write_byte0(reg_addr);			//send low address
	RTC_write_byte0(reg_data);			//send low data
	RTC_stop0();						//stop
	RTC_Delay(100);						    // wait for write cycle time
}
//=====================================================
unsigned char RTC_read_byte(unsigned char reg_addr)
{
	unsigned char retb;

	RTC_start0();										//send start bit
	RTC_write_byte0(RTC_WRITE_COM);					//send address byte
	RTC_write_byte0(reg_addr);               		//send high address
	RTC_restart0();
	RTC_write_byte0(RTC_READ_COM);					//send address byte
	retb = RTC_read_byte0();               		//get high data
	RTC_stop0();                              		//stop    
    
	return retb;
}
/***************************************************/