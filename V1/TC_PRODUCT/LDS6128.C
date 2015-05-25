/*
*********************************************************************************************************
* Copyright 2010 IDT Technology, Inc. ALL RIGHTS RESERVED.
* This software is provided under license and contains proprietary and
* confidential material which is the property of IDT Technology, Inc.
*
* FileName     : LDS6100.c
* Description  : LDS6100 ctrl & function code.
*
* Version control:
*  $Revision: 0.1 $    Date: 2010/01/01 12:00:00   ue.fu@idt.com
*      first implemetation
*
*********************************************************************************************************
*/
#include "i2c.h"
#include "lds6128.h"
/*
*********************************************************************************************************
*
*                                              GLOBAL Value
*
*********************************************************************************************************
*/

Bool lds6128_connect;


/*************************************************/
U32 LDS6128_key_status(void)
 {
	U32   key_status; 

	//key_status = ((U32)i2c_read_word(LDS6100_ADDR, 0x0046) << 16) | i2c_read_word(LDS6100_ADDR, 0x0045);
	key_status = i2c_read_word(LDS6100_ADDR, 0x0045);
	//			   11 1111	                    0000 0000 1100 0000				               1 1111
	key_status = (key_status & 0x003f) | ((key_status & 0x0300) >> 2) | ((i2c_read_word(LDS6100_ADDR, 0x0046) & 0x001f) << 8);

	return key_status ;
 }

/*
*********************************************************************************************************
* LDS6100_init()
* Description   : 
*
* Arguments    :
* Returns        : TRUE / FALSE
*********************************************************************************************************
*/
Bool LDS6128_init(void)
{
        // ***********************************
        // LDS6100 - IDT Touch Initial Code
        // ***********************************

        // COLD RESET, must be the same for this command
        // WR 0x0000 0x0000
        i2c_write_word(LDS6100_ADDR, 0x0000, 0x0000);      

        // TOUCH DISABLE, just disable first then write below config.
        // WR 0x0040 0x0030
        i2c_write_word(LDS6100_ADDR, 0x0040, 0x0030);      

        // DCM CONFIG, if not used DCM output need write 0x0000
        // WR 0x000A 0x0000
        i2c_write_word(LDS6100_ADDR, 0x000A, 0x0000);      

        // SCROLL CONFIG, if you board not have scroll, please write 0x0000 and don't care this register
        // WR 0x0074 0x801F
        i2c_write_word(LDS6100_ADDR, 0x0074, 0x0000);      //disable  07/12 11

        // PSEL, this register depend on your schematic. if connect touch sensor pad please setting '1'
        // WR 0x0041 0x03FF
        // WR 0x0042 0x0001
        i2c_write_word(LDS6100_ADDR, 0x0041, 0x033f);       
        i2c_write_word(LDS6100_ADDR, 0x0042, 0x001f);       

        // INTERRUPT, should be the same 0x41/0x42
        // WR 0x0043 0x03FF
        // WR 0x0044 0x0001
        i2c_write_word(LDS6100_ADDR, 0x0043, 0x033f);       
        i2c_write_word(LDS6100_ADDR, 0x0044, 0x001f);       

        // INTERRUPT PIN DEFINE, this register default only send 2usec pulse, so must be setting for latch-mode(01) or read-reset-mode(1x)
        // WR 0x0008 0x0002
        i2c_write_word(LDS6100_ADDR, 0x0008, 0x0002);      
        //i2c_write_word(LDS6100_ADDR, 0x0008, 0x0001);   

        // disable all led
        i2c_write_word(LDS6100_ADDR, 0x003f, 0x0000);               
        i2c_write_word(LDS6100_ADDR, 0x003e, 0x0000);

        // Ambient Config, don't care just write the same.
        // WR 0x0051 0x0A1F
        i2c_write_word(LDS6100_ADDR, 0x0051, 0x0a1f);       
        //i2c_write_word(LDS6100_ADDR, 0x0051, 0x1f1f);     
        
        // Recalib Config, don't care just write the same.
        // WR 0x0052 0x07FF 
        i2c_write_word(LDS6100_ADDR, 0x0052, 0x00bf);  // 19.96 Sec
        
        // Long Touch, don't care just write the same.
        // WR 0x0053 0x07FF
        i2c_write_word(LDS6100_ADDR, 0x0053, 0x07ff);        
        
        // SELC_Unit Configuration, don't care just writer the same.
        // WR 0x004E 0x5000
        //i2c_write_word(LDS6100_ADDR, 0x004e, 0x5001);   //org 5000               
        i2c_write_word(LDS6100_ADDR, 0x004e, 0x5000);   //org 5000          
        
        // Button Thershold:  all enable channel should be initial threshold value. if you don't know this value just all write 0x0020 should be ok.
#if 0
        i2c_write_word(LDS6100_ADDR, 0x005f, 0x0001);       
        i2c_write_word(LDS6100_ADDR, 0x0060, 0x0032);//0=32   ,1=52,2=32
        i2c_write_word(LDS6100_ADDR, 0x0061, 0x0032);      
        i2c_write_word(LDS6100_ADDR, 0x0062, 0x0032);      
        i2c_write_word(LDS6100_ADDR, 0x0063, 0x0032);      
        i2c_write_word(LDS6100_ADDR, 0x0064, 0x0032);      
        i2c_write_word(LDS6100_ADDR, 0x0065, 0x0032);      
        i2c_write_word(LDS6100_ADDR, 0x0068, 0x0032);      
        i2c_write_word(LDS6100_ADDR, 0x0069, 0x0032);      
        i2c_write_word(LDS6100_ADDR, 0x006a, 0x0032);      
        i2c_write_word(LDS6100_ADDR, 0x006b, 0x0032);      
        i2c_write_word(LDS6100_ADDR, 0x006c, 0x0032);      
        i2c_write_word(LDS6100_ADDR, 0x006d, 0x0032);      
        i2c_write_word(LDS6100_ADDR, 0x006e, 0x0032);      
#else
        i2c_write_word(LDS6100_ADDR, 0x005f, 0x0001);       
        i2c_write_word(LDS6100_ADDR, 0x0060, 0x0040);//0=32   ,1=52,2=32
        i2c_write_word(LDS6100_ADDR, 0x0061, 0x0040);      
        i2c_write_word(LDS6100_ADDR, 0x0062, 0x0040);      
        i2c_write_word(LDS6100_ADDR, 0x0063, 0x0040);      
        i2c_write_word(LDS6100_ADDR, 0x0064, 0x0040);      
        i2c_write_word(LDS6100_ADDR, 0x0065, 0x0040);      
        i2c_write_word(LDS6100_ADDR, 0x0068, 0x0040);      
        i2c_write_word(LDS6100_ADDR, 0x0069, 0x0040);      
        i2c_write_word(LDS6100_ADDR, 0x006a, 0x0040);      
        i2c_write_word(LDS6100_ADDR, 0x006b, 0x0040);      
        i2c_write_word(LDS6100_ADDR, 0x006c, 0x0040);      
        i2c_write_word(LDS6100_ADDR, 0x006d, 0x0040);      
        i2c_write_word(LDS6100_ADDR, 0x006e, 0x0040);      

#endif

#if 1
        // Button Thershold:  ambient setting
        i2c_write_word(LDS6100_ADDR, 0x005f, 0x0002);       
        i2c_write_word(LDS6100_ADDR, 0x0060, 0x0010);      //default = 0x0a, change to 0x14
        i2c_write_word(LDS6100_ADDR, 0x0061, 0x0010);      
        i2c_write_word(LDS6100_ADDR, 0x0062, 0x0010);      
        i2c_write_word(LDS6100_ADDR, 0x0063, 0x0010);      
        i2c_write_word(LDS6100_ADDR, 0x0064, 0x0010);      
        i2c_write_word(LDS6100_ADDR, 0x0065, 0x0010);      
        i2c_write_word(LDS6100_ADDR, 0x0068, 0x0010);      
        i2c_write_word(LDS6100_ADDR, 0x0069, 0x0010);      
        i2c_write_word(LDS6100_ADDR, 0x006a, 0x0010);      
        i2c_write_word(LDS6100_ADDR, 0x006b, 0x0010);      
        i2c_write_word(LDS6100_ADDR, 0x006c, 0x0010);      
        i2c_write_word(LDS6100_ADDR, 0x006d, 0x0010);      
        i2c_write_word(LDS6100_ADDR, 0x006e, 0x0010);      

        // Button Minus Noise Level
        i2c_write_word(LDS6100_ADDR, 0x005f, 0x0003);       
        i2c_write_word(LDS6100_ADDR, 0x0060, 0x0004);
        i2c_write_word(LDS6100_ADDR, 0x0061, 0x0004);      
        i2c_write_word(LDS6100_ADDR, 0x0062, 0x0004);      
        i2c_write_word(LDS6100_ADDR, 0x0063, 0x0004);      
        i2c_write_word(LDS6100_ADDR, 0x0064, 0x0004);      
        i2c_write_word(LDS6100_ADDR, 0x0065, 0x0004);      
        i2c_write_word(LDS6100_ADDR, 0x0068, 0x0004);      
        i2c_write_word(LDS6100_ADDR, 0x0069, 0x0004);      
        i2c_write_word(LDS6100_ADDR, 0x006a, 0x0004);      
        i2c_write_word(LDS6100_ADDR, 0x006b, 0x0004);      
        i2c_write_word(LDS6100_ADDR, 0x006c, 0x0004);      
        i2c_write_word(LDS6100_ADDR, 0x006d, 0x0004);      
        i2c_write_word(LDS6100_ADDR, 0x006e, 0x0004);      


        // Button Plus Noise Level
        i2c_write_word(LDS6100_ADDR, 0x005f, 0x0004);       
        i2c_write_word(LDS6100_ADDR, 0x0060, 0x0004);
        i2c_write_word(LDS6100_ADDR, 0x0061, 0x0004);      
        i2c_write_word(LDS6100_ADDR, 0x0062, 0x0004);      
        i2c_write_word(LDS6100_ADDR, 0x0063, 0x0004);      
        i2c_write_word(LDS6100_ADDR, 0x0064, 0x0004);      
        i2c_write_word(LDS6100_ADDR, 0x0065, 0x0004);      
        i2c_write_word(LDS6100_ADDR, 0x0068, 0x0004);      
        i2c_write_word(LDS6100_ADDR, 0x0069, 0x0004);      
        i2c_write_word(LDS6100_ADDR, 0x006a, 0x0004);      
        i2c_write_word(LDS6100_ADDR, 0x006b, 0x0004);      
        i2c_write_word(LDS6100_ADDR, 0x006c, 0x0004);      
        i2c_write_word(LDS6100_ADDR, 0x006d, 0x0004);      
        i2c_write_word(LDS6100_ADDR, 0x006e, 0x0004);      
#endif
        //Debounce & Hysteresis, if you don't care just follow up below setting
        // WR 0x0057 0x1000
        // WR 0x0075 0x0002
        i2c_write_word(LDS6100_ADDR, 0x0057, 0x3000);      // 0=1000 ;1=2000,2=1000
        i2c_write_word(LDS6100_ADDR, 0x0075, 0x0003);      //0=0002 ,1=0008,2= 0003
        
        // Guard channel setting 
        i2c_write_word(LDS6100_ADDR, 0x007c, 0x0000);              
        i2c_write_word(LDS6100_ADDR, 0x007d, 0x0000);              
        i2c_write_word(LDS6100_ADDR, 0x007e, 0x0000);              
        i2c_write_word(LDS6100_ADDR, 0x007f, 0x0000);               

        //i2c_write_word(LDS6100_ADDR, 0x0077, 0xFFFF); //NOISE  DISABLE
        // TOUCH ENABLE, must be setting enable after config
        // WR 0x0040 0x8038
        i2c_write_word(LDS6100_ADDR, 0x0040, 0xb038);     //org  8038       

        // SOFT RESET, must be the same when finish setting
        // WR 0x0001 0x0000
        i2c_write_word(LDS6100_ADDR, 0x0001, 0x0000);      

        return TRUE;
}
