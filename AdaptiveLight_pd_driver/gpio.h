#ifndef GPIO_H
#define GPIO_H

#include <avr/io.h>
#include <util/delay.h>
#include<avr/interrupt.h>
#include<stdint.h>

//Macros
#define SET_BIT(PORT,BIT) PORT|=  (1<<BIT)
#define CLR_BIT(PORT,BIT) PORT&= ~(1<<BIT)
#define ONE 1
struct {
  volatile unsigned int SW1:1;
  volatile unsigned int SW2:1;
}FLAG_BIT;

void gpio_init(void);

#endif

