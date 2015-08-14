/*************************************
 SLOPE FOR PER TYPE AND GAIN 

**************************************/
#ifndef	SLOPE_h_ 
#define	SLOPE_h_ 

unsigned int Get_K_Slope(unsigned  int kt);
unsigned int Get_J_Slope(unsigned  int jt);
unsigned int Get_T_Slope(unsigned  int ts);
unsigned int Get_E_Slope(unsigned  int et);
unsigned int Get_R_Slope(unsigned  int rt);
unsigned int Get_S_Slope(unsigned  int st);
unsigned int Get_B_Slope(unsigned  int bt);
unsigned int Get_N_Slope(unsigned  int nt); 
unsigned int Get_RTD_Slope(unsigned int rtd);
unsigned int DO_RTD_TYPE(void);
unsigned int Read_AD3421_Value(void);
unsigned int Check_Type_Offset(unsigned int ss);
#endif