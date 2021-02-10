# include "gpio.h"
#include "adc.h"
#include "applicatio.h"
int duty_cycle=75;


void LightCond(){
        adc_read();
        if(FLAG_BIT.SW1==0){ //Auto Mode
            if(adc_result>=0 && adc_result<=50){
                duty_cycle=191;//75% Duty Cycle
                pwm(duty_cycle);
            }
            else if(adc_result>=51 && adc_result<=150){
                duty_cycle=128;//50% Duty Cycle
                pwm(duty_cycle);
            }
             else if(adc_result>=151 && adc_result<=250){
                duty_cycle=64;//25% Duty Cycle
                pwm(duty_cycle);
             }
            else if(adc_result>250){
                duty_cycle=0;//0% Duty Cycle
                pwm(0);
            }

        }
        if(FLAG_BIT.SW1==1){ //Manual Mode

            if(FLAG_BIT.SW2==1){// HIGH BEAM
                duty_cycle=191;// 75% Duty Cycle
                pwm(duty_cycle);
            }
            else{//LOW BEAM OFF
                duty_cycle=128; //50% Duty Cycle
                pwm(duty_cycle);
            }
        }

}
void diagonstic(void)
{
    adc_read();
     if(FLAG_BIT.SW1==0){

            if(adc_result>=0 && adc_result<=50 && duty_cycle!=191){
               SET_BIT(PORTD,PD7);//MIL ON
            }
            else if(adc_result>=51 && adc_result<=150 && duty_cycle!=128 ){
                SET_BIT(PORTD,PD7);//MIL ON
            }
            else if(adc_result>=151 && adc_result<=250 && duty_cycle!=64 ){
                SET_BIT(PORTD,PD7);//MIL ON
            }
            else if(adc_result>250 && duty_cycle!=0){
                SET_BIT(PORTD,PD7);//MIL ON
            }

        }
}


