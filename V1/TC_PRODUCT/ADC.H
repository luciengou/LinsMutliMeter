#ifndef	_ADC_H_ 
#define	_ADC_H_ 


void Init_ADC(void);
void Get_ADC_Value(void);

unsigned int WaterOverHot_warning(void);
unsigned int PowerOverHot_warning(void);

#endif