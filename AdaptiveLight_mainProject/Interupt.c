#include "gpio.h"
#include "interupt.h"
void intr_driver(void){
    CLR_BIT(EICRA,ISC01);
    SET_BIT(EICRA,ISC00);
    SET_BIT(EIMSK,INT0);
    CLR_BIT(EICRA,ISC01);
    SET_BIT(EICRA,ISC10);
    SET_BIT(EIMSK,INT1);
    sei();
    FLAG_BIT.SW1=0;//SW1
    FLAG_BIT.SW2=0;//SW2
}

//Mode Selection SW
ISR(INT0_vect)
{
    cli();
    FLAG_BIT.SW1=~FLAG_BIT.SW1;

    if(FLAG_BIT.SW1==0){ //Auto Mode
        SET_BIT(PORTD,PD1);
    }
    else{
        CLR_BIT(PORTD,PD1);
    }

    sei();
}

//Beam Selection SW
ISR(INT1_vect)
{
    cli();
    FLAG_BIT.SW2=~FLAG_BIT.SW2;
    sei();
}



