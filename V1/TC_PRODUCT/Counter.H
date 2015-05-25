#ifndef __COUNTER_H__
#define __COUNTER_H__

void Start_SleepCounter(unsigned char sec);
void Stop_SleepCounter(void);
unsigned char Check_SleepCounter_Start(void);
unsigned char Is_SleepCounter_CountDown_Finish(void);

void Start_KeyholdCounter(unsigned char sec);
void Stop_KeyholdCounter(void);
unsigned char Check_KeyholdCounter_Start(void);
unsigned char Is_KeyholdCounter_CountDown_Finish(void);	

void Start_Ph_reflashCounter(unsigned char sec);
void Stop_Ph_reflashCounter(void);
unsigned char Check_Ph_reflashCounter_Start(void);
unsigned char Is_Ph_reflashCounter_CountDown_Finish(void);	

void Start_WaterLackCounter(unsigned char sec);
void Stop_WaterLackCounter(void);
unsigned char Check_WaterLackCounter_Start(void);
unsigned char Is_WaterLackCounter_CountDown_Finish(void);

void Start_VoiceWaitCounter(unsigned char sec);
void Stop_VoiceWaitCounter(void);
unsigned char Check_VoiceWaitCounter_Start(void);
unsigned char Is_VoiceWaitCounter_CountDown_Finish(void);

#endif