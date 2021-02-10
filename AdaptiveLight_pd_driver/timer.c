#include "timer.h"
#include "gpio.h"


void timer_driver(void)
{
    TCCR0A=0x00;
    TCNT0=0x00;
    TCCR0B |=((1<<CS00)|(1<<CS02));
    TCCR0B &=~(1<<CS01);
    TIMSK0 |=(1<<TOIE0);

    sei();
    SET_BIT(DDRD,PD7);
    CLR_BIT(PORTD,PD7);
}

ISR(TIMER0_OVF_vect)
{
    counter++;
    if(counter >=305)
    {
        diagonstic();
    }

}

