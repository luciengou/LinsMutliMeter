/******************************************
    ADS1110 (16BITS ADC) READ ONLY
    FOR Value_read
    Count = 65536 X ( Vin -(-Vin))/2.048V

********************************************/
#ifndef	_VALUE_CODE_H_ 
#define	_VALUE_CODE_H_ 


void Init_ADC(void);
unsigned int Get_ADC_Value(void);

unsigned int WaterOverHot_warning(void);
unsigned int PowerOverHot_warning(void);

#endif