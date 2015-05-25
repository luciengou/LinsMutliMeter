/************************************
**    EEPROM FOR 24C08 DEVICE	   **
*************************************/
#include <MPC82G516.H>
#include <EEPROM.h>

#define  EEPROM_ADDR  0xA0

#define  TRUE   1
#define  FALSE  0

sbit EEPROM_SDA		= P2^5;
sbit EEPROM_SCL 	= P2^4;

unsigned char  EEPROM_ack ;
/*******************************/
void EEPROM_Delay(unsigned int i)
{
   unsigned char j;
 for (; i>0; i--)
 for (j=0; j<255; j++);
}
//==============================
void EEPROM_BitDly(void)               // wait 4.7uS, or thereabouts
{                                   // tune to xtal. This works at 11.0592MHz
	unsigned char	i;
	
	for (i=0; i<0x12; i++);
}
//============================
void EEPROM_Init(void)
{
	unsigned int i;

	EEPROM_SCL = 1;
	EEPROM_BitDly();
	EEPROM_BitDly();
	EEPROM_BitDly();
	EEPROM_BitDly();
	EEPROM_SDA = 0;
//	EEPROM_SCL = 0;
	for(i = 0; i < 0x100; i++); 
 
}
//===================================
void EEPROM_start0(void)
{
	EEPROM_SDA = 1;
	EEPROM_BitDly();
	EEPROM_SDA = 0;
	EEPROM_BitDly();
	EEPROM_SCL = 0;
	EEPROM_BitDly();
}
//====================================
void EEPROM_stop0(void)
{
	EEPROM_SDA = 0;
	EEPROM_BitDly();
	EEPROM_SCL = 1;
	EEPROM_BitDly();
	EEPROM_SDA = 1;
	EEPROM_BitDly();
}
//====================================
void EEPROM_restart0(void)
{
	EEPROM_SDA = 1;
	EEPROM_BitDly();
	EEPROM_SCL = 1;
	EEPROM_BitDly();
	EEPROM_SDA = 0;
	EEPROM_BitDly();
	EEPROM_SCL = 0;
	EEPROM_BitDly();  
}
//====================================
void EEPROM_write_byte0(unsigned char bt)
{
	idata unsigned char i;

	EEPROM_ack = TRUE;						//default have ack
  
	for (i=0; i<8; i++)
	{
		if (bt & 0x80)
		   EEPROM_SDA = 1;         // send each bit, MSB first
		else
		   EEPROM_SDA = 0;
		   EEPROM_SCL = 1;
		   EEPROM_BitDly();
		   EEPROM_SCL = 0;
		   EEPROM_BitDly();
		   bt <<= 1;
	}

	EEPROM_SDA = 1;                                // change input and listen for ACK
	EEPROM_SCL = 1;
	EEPROM_BitDly();

	if (EEPROM_SDA)
		EEPROM_ack = FALSE;             		// ack didn't happen, may be nothing out there
	    EEPROM_SCL = 0;
	    EEPROM_BitDly();
}
//======================================
unsigned char EEPROM_read_byte0(void) 	        // lastone == 1 for last byte
{
  	idata unsigned char i, res;
	res = 0;
	EEPROM_SDA = 1;

	for (i=0; i<8; i++)                 // each bit at a time, MSB first
	{
		EEPROM_SCL = 1;
	    EEPROM_BitDly();
		      res <<= 1;
		if (EEPROM_SDA)		res |= 1;
		    EEPROM_SCL = 0;
		    EEPROM_BitDly();
	}
	EEPROM_SDA = 1;                 	// send ACK according to 'lastone'
	EEPROM_SCL = 1;
	EEPROM_BitDly();
	EEPROM_SCL = 0;
	EEPROM_SDA = 1;
	EEPROM_BitDly();
	return(res);
}
//==========================================
void EEPROM_write_byte(unsigned char reg_addr, unsigned char reg_data)
{
	EEPROM_start0();						//send start bit
	EEPROM_write_byte0(EEPROM_ADDR);
	EEPROM_write_byte0(reg_addr);			//send low address
	EEPROM_write_byte0(reg_data);			//send low data
	EEPROM_stop0();						//stop
	EEPROM_Delay(100);						    // wait for write cycle time
}
//=====================================================
unsigned char EEPROM_read_byte(unsigned char reg_addr)
{
	unsigned char retb;

	EEPROM_start0();										//send start bit
	EEPROM_write_byte0(EEPROM_ADDR);					//send address byte
	EEPROM_write_byte0(reg_addr);               		//send high address
  
	EEPROM_restart0();
	EEPROM_write_byte0(EEPROM_ADDR+1);					//send address byte
	retb = EEPROM_read_byte0();               		//get high data
	EEPROM_stop0();                              		//stop    
    
	return retb;
}
/***************************************************/