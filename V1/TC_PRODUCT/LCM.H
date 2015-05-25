#ifndef	LCM_h_ 
#define	LCM_h_ 

#define JOHNSON         0x5a
#define LIN             0xa5
#define BL_NoColor      0
#define BL_Purple       1
#define BL_BrightBlue   2
#define BL_Blue         3
#define BL_DarkBlue     4
#define BL_Green        5
#define BL_Yellow       6
#define BL_Orange       7
#define BL_Red          8

#define K1	KX & 0x0001
#define K2	KX & 0x0002
#define K3	KX & 0x0004
#define K4	KX & 0x0008
#define K5	KX & 0x0010
#define K6	KX & 0x0020
#define K7	KX & 0x0040
#define K8	KX & 0x0080
#define K9	KX & 0x0100
#define X1	KX & 0x0200
#define X2	KX & 0x0400
#define X3	KX & 0x0800
#define X4	KX & 0x1000
#define ALKA	KX & 0x2000
#define FILTER	KX & 0x4000
#define L_MIN  KX & 0x8000

#define R1   R & 0x0001
#define R2	 R & 0x0002
#define R3	 R & 0x0004
#define R4	 R & 0x0008
#define R5	 R & 0x0010
#define R6	 R & 0x0020
#define SP9  R & 0x0040
#define SP12 R & 0x0080
#define ORP	 R & 0x0100
#define MV	 R & 0x0200

#define SET_K1()		KX |= 0x0001
#define SET_K2()		KX |= 0x0002
#define SET_K3()		KX |= 0x0004		//lock  
#define SET_K4()		KX |= 0x0008
#define SET_K5()		KX |= 0x0010
#define SET_K6()		KX |= 0x0020
#define SET_K7()		KX |= 0x0040
#define SET_K8()		KX |= 0x0080
#define SET_K9()		KX |= 0x0100
#define SET_X1()		KX |= 0x0200
#define SET_X2()		KX |= 0x0400
#define SET_X3()		KX |= 0x0800
#define SET_X4()		KX |= 0x1000
#define SET_ALKA()		KX |= 0x2000
#define SET_FILTER()	KX |= 0x4000
#define SET_L_MIN()		KX |= 0x8000	

#define CLR_K1()		KX &= ~0x0001
#define CLR_K2()		KX &= ~0x0002
#define CLR_K3()		KX &= ~0x0004
#define CLR_K4()		KX &= ~0x0008
#define CLR_K5()		KX &= ~0x0010
#define CLR_K6()		KX &= ~0x0020
#define CLR_K7()		KX &= ~0x0040
#define CLR_K8()		KX &= ~0x0080
#define CLR_K9()		KX &= ~0x0100
#define CLR_X1()		KX &= ~0x0200
#define CLR_X2()		KX &= ~0x0400
#define CLR_X3()		KX &= ~0x0800
#define CLR_X4()		KX &= ~0x1000
#define CLR_ALKA()		KX &= ~0x2000
#define CLR_FILTER()	KX &= ~0x4000
#define CLR_L_MIN()		KX &= ~0x8000

#define SET_R1()		R |= 0x0001
#define SET_R2()		R |= 0x0002
#define SET_R3()		R |= 0x0004
#define SET_R4()		R |= 0x0008
#define SET_R5()		R |= 0x0010
#define SET_R6()		R |= 0x0020
#define SET_SP9()		R |= 0x0040
#define SET_SP12()		R |= 0x0080
#define SET_ORP()		R |= 0x0100
#define SET_MV()		R |= 0x0200

#define CLR_R1()		R &= ~0x0001
#define CLR_R2()		R &= ~0x0002
#define CLR_R3()		R &= ~0x0004
#define CLR_R4()		R &= ~0x0008
#define CLR_R5()		R &= ~0x0010
#define CLR_R6()		R &= ~0x0020
#define CLR_SP9()		R &= ~0x0040
#define CLR_SP12()		R &= ~0x0080
#define CLR_ORP()		R &= ~0x0100
#define CLR_MV()		R &= ~0x0200




void LCM_Backlight(unsigned char BacklightValue);
void LCM_all_point_on(void);
void LCM_Init(void);
void LCM_Cls(void);
void LCM_Fill(void);
void test(unsigned char column, unsigned char c);
void LCM_Disp_Acid(unsigned char c);
void LCM_Disp_Alka(unsigned char c);
void LCM_Disp_PH_and_R(unsigned char *c);
void LCM_Disp_KL(unsigned int VL, unsigned char mode);
void LCM_Disp_WaterFlow(unsigned int i);
void LCM_Disp_VOL_K2K3(void);
void LCM_Disp_WashLiter(unsigned char c, unsigned char mode);
void LCM_Disp_ORP(unsigned int ORP_Value, unsigned char ORP_Sign);
void LCM_Disp_I_add(unsigned char c, unsigned char mode);
void LCM_Disp_Program_display(unsigned char c, unsigned int t);
void LCM_ClrL(void);
void LCM_Disp_Version(unsigned char YY, unsigned int MD);
#endif