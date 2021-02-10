# include "gpio.h"
//GPIO pin mode setup
void gpio_init(void){
    SET_BIT(DDRD,PD1);//Auto mode indication
    CLR_BIT(DDRD,PD2);//SW1 Mode switch
    SET_BIT(PORTD,PD2);//PULL UP
    CLR_BIT(DDRD,PD3);//SW2 Beam Selection
    SET_BIT(PORTD,PD3);//PULL UP
    CLR_BIT(DDRC,PC5);//ADC
    SET_BIT(DDRD,PD6);//CRO

}



