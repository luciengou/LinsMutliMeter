#include <MPC82G516.h>

unsigned char adc_ch = 0;
unsigned char adc_val[2] = {200, 200};
unsigned char code tmp0_tab[15] = {	128, 116, 105, 94, 84, 75, 67, 59, 53, 47, 41, 37, 33, 29, 26};
unsigned char code tmp1_tab[15] = {	128, 114, 101, 89, 78, 68, 59, 52, 45, 39, 34, 29, 25, 22, 19};

void Init_ADC(void)
{
	ADCTL = (0xC8 | (adc_ch+1));
}

void Get_ADC_Value(void)
{
	if (ADCTL & 0x10)
	{
		adc_val[adc_ch] = ADCH;
		adc_ch++;
		adc_ch &= 0x01;
		ADCTL = (0xC8 | (adc_ch+1));
	}
}

unsigned int Get_tmp0(unsigned char val)
{
	unsigned char c=0;
	unsigned int reti;

	while (tmp0_tab[c] > val)
		c++;
	reti = (25+c*5)*10;

	return(reti);
}

unsigned int Get_tmp1(unsigned char val)
{
	unsigned char c=0;
	unsigned int reti;

	while (tmp1_tab[c] > val)
		c++;
	reti = (25+c*5)*10;

	return(reti);
}

unsigned int WaterOverHot_warning(void)
{
	unsigned char c;
	unsigned int reti;

	c = adc_val[0];
	if (c < 94)
		reti = Get_tmp0(c);
	else
		reti = 0;

	return(reti);
}

unsigned int PowerOverHot_warning(void)
{
	unsigned char c;
	unsigned int reti;

	c = adc_val[1];
	if (c < 39)
		reti = Get_tmp1(c);
	else
		reti = 0;

	return(reti);
}