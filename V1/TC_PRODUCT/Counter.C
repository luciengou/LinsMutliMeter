#include <MPC82G516.h>
#include <COUNTER.H>


extern unsigned char Soft_Timer_Enable;
extern idata unsigned char Soft_Timer[8];
/*====================================================
  Sleep Counter function  
  Soft_Timer[0] for sleep counter, unit:sec
=====================================================*/ 
void Start_SleepCounter(unsigned char sec)
{
	Soft_Timer[0] = sec;				  // sec seconds	

	Soft_Timer_Enable = (Soft_Timer_Enable | 0x01);			  // enable Soft_Timer[0]

}
//=====================================
void Stop_SleepCounter(void)		
{
	Soft_Timer_Enable &= ~0x01;	   // set to  0
	Soft_Timer[0] = 0;
}

unsigned char Is_SleepCounter_CountDown_Finish(void)
{
	unsigned k;

	   if( Soft_Timer[0] > 0)
	     { k = 1;}
	   else
	     { k =0; }
 //	c = (Soft_Timer[0])? 1 : 0;

	return k;
}

unsigned char Check_SleepCounter_Start(void)		// if sleep counter is started return 1
{
	unsigned c;

	   if((Soft_Timer_Enable & 0x01) == 1)
	      {c=1;} else{ c=0 ;}

	return c;
}
/*=======================================================
  Keyhold Counter function  
  Soft_Timer[1] for key hold counter, unit:sec
=========================================================*/	
void Start_KeyholdCounter(unsigned char sec)
{																			   
	Soft_Timer[1] = sec;		// sec seconds	
	Soft_Timer_Enable |= 0x02;	// enable Soft_Timer[1]
} 

void Stop_KeyholdCounter(void)
{
	Soft_Timer_Enable &= ~0x02;
	Soft_Timer[1] = 0;
} 
unsigned char Check_KeyholdCounter_Start(void)		// if key hold counter is started return 1
{
	unsigned c;

	c = (Soft_Timer_Enable & 0x02)? 1 : 0;

	return c;
}
unsigned char Is_KeyholdCounter_CountDown_Finish(void)
{
	unsigned c;
	
	c = (Soft_Timer[1]==0)? 1 : 0;

	return c;
}
/*=============================================
  VoiceWait Counter function  
  Soft_Timer[2] for water lack counter, unit:sec
================================================*/

void Start_VoiceWaitCounter(unsigned char sec)
{
	Soft_Timer[2] = sec;		// sec seconds	
	Soft_Timer_Enable |= 0x04;	// enable Soft_Timer[0]
} 
void Stop_VoiceWaitCounter(void)
{
	Soft_Timer_Enable &= ~0x04;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
	Soft_Timer[2] = 0;
} 
unsigned char Check_VoiceWaitCounter_Start(void)		// if water lack counter is started return 1
{
	unsigned c;

	c = (Soft_Timer_Enable & 0x04)? 1 : 0;

	return c;
}
unsigned char Is_VoiceWaitCounter_CountDown_Finish(void)
{
	unsigned c;
	
	c = (Soft_Timer[2]==0)? 1 : 0;

	return c;
}
/*====================================================
  WaterLack Counter function  
  Soft_Timer[3] for water lack counter, unit:sec
=====================================================*/
void Start_WaterLackCounter(unsigned char sec)
{
	Soft_Timer[3] = sec;		// sec seconds	
	Soft_Timer_Enable |= 0x08;	// enable Soft_Timer[0]
} 
void Stop_WaterLackCounter(void)
{
	Soft_Timer_Enable &= ~0x08;
	Soft_Timer[3] = 0;
} 
unsigned char Check_WaterLackCounter_Start(void)		// if water lack counter is started return 1
{
	unsigned c;

	c = (Soft_Timer_Enable & 0x08)? 1 : 0;

	return c;
}

unsigned char Is_WaterLackCounter_CountDown_Finish(void)
{
	unsigned c;
	
	c = (Soft_Timer[3]==0)? 1 : 0;

	return c;
}  
/*=========================================================
  LCM_RETURN PH95 Counter function  
  Soft_Timer[4] for LCM_RETURN PH95 counter, unit:sec
=========================================================*/
void Start_Ph_reflashCounter(unsigned char sec)
{																			   
	Soft_Timer[4] = sec;		   // sec seconds	
	Soft_Timer_Enable |= 0x10;	   // enable Soft_Timer[4]
} 

void Stop_Ph_reflashCounter(void)
{
	Soft_Timer_Enable &= ~0x10;
	Soft_Timer[4] = 0;
} 
unsigned char Check_Ph_reflashCounter_Start(void)		
{
	unsigned c;

	c = (Soft_Timer_Enable & 0x10)? 1 : 0;

	return c;
}
unsigned char Is_Ph_reflashCounter_CountDown_Finish(void)
{
	unsigned c;
	
	c = (Soft_Timer[4]==0)? 1 : 0;

	return c;
}
//==============================================================