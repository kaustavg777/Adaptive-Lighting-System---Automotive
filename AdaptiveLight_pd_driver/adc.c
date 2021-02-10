#include"adc.h"
void adc_read(void){
    //ADC conversion
    SET_BIT(ADCSRA,ADSC);
    while((ADSC==1));//loop for finish reading the value
    adc_result = ADCH;
    adc_result = adc_result << 8; //shift 8 to left
    adc_result = adc_result | ADCL;
}

//ADC driver set up
void adc_driver(void){
    CLR_BIT(ADMUX,REFS1);
    SET_BIT(ADMUX,REFS0);
    //CH 5 as i/p
    ADMUX |= ((ONE<<MUX2)|(ONE<<MUX0));//0101
    ADMUX &= ~((ONE<<MUX1)|(ONE<<MUX3));
    CLR_BIT(ADMUX,ADLAR);
    SET_BIT(ADCSRA,ADEN);
}

