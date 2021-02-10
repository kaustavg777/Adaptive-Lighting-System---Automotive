#include "pwm.h"

void pwm(int DutyCycle){
    TCCR0A |=(1<<COM0A1)|(1<<WGM01)|(1<<WGM00);
    OCR0A=DutyCycle;
    TCCR0B|=(1<<CS00);
}

