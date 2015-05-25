/*******************************************
          TC SLOPE AND RTD SLOPE

  用 K_type 做基礎校正歸零及最高基準校正
  放大倍數採最大輸入電壓 E TYPE 為最大倍數
  使精度為 0.1F/COUNT  G=53
  65536/32768
K_TYPE	0	//2466F //54.807mV	//24660 COUNT // 2.9431V
J_TYPE	1	//1368F //42.922mV	//13680 COUNT // 2.3049V
T_TYPE  2	//360F  //9.286mV	//3600  COUNT // 0.49866V
E_TYPE	3	//1440F //61.022mV	//14400 COUNT // 3.2768
R_TYPE	4	//2880F //18.842mV	//28800 COUNT //
S_TYPE	5	//2880F //16.771mV	//28800 COUNT //
B_TYPE	6	//3240F //13.585mV	//32400 COUNT //

    ADS1110 (16BITS ADC) READ ONLY
    FOR Value_read
    Count = 65536 X ( Vin -(-Vin))/2.048V

******************************************/
#include<MPC82G516.h>
#include<TYPE_SLOPE.h>

/**********************************/
#define	K_TYPE		0		//2466F   54.807mV	P0=0x00
#define	J_TYPE		1		//1368F   42.922mV
#define	T_TYPE   	2		//360F    9.286mV
#define	E_TYPE		3		//1440F   61.022mV
#define	R_TYPE		4		//2880F   18.842mV
#define	S_TYPE		5		//2880F   16.771mV
#define	B_TYPE		6		//3240F   13.585mV
#define	N_TYPE	    7		//?       ? 




