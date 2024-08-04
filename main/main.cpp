#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "LED.h"

LED led1(16); 
LED led2(17); 
LED led3(5); 
LED led4(18); 
LED led5(19); 
LED led6(21); 
LED led7(22); 
LED led8(23); 

LED leds[] = {led1, led2, led3, led4, led5, led6, led7, led8};

void ALL_LED_OFF()
{
    for(int i = 0; i < 8; ++i) {
        leds[i].OFF();
    }
}

extern "C" void app_main(void)
{
    while(1)
    {
        for(int i = 0; i < 4; ++i)
        {
            ALL_LED_OFF();
            leds[i].ON();
            leds[7 - i].ON();
            vTaskDelay(200 / portTICK_PERIOD_MS);
        }
        
        for(int i = 3; i >= 0; --i)
        {
            ALL_LED_OFF();
            leds[i].ON();
            leds[7 - i].ON();
            vTaskDelay(200 / portTICK_PERIOD_MS);
        }
    }
}
