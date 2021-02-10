#include "gpio.h"
#include "adc.h"

int main(void)
{
    gpio_init();
    intr_driver();
    adc_driver();
    timer_driver();
    while(1){
      LightCond();
    }
    return 0;
}
