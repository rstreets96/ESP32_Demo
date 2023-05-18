#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "led_strip.h"
#include "rgb_led.h"







void app_main(void)
{
	led_strip_install();
	static led_strip_t strip =
	{
			.type = LED_STRIP_WS2812,
			.length = 1,
			.gpio = RGB_LED_GPIO,
			.buf = NULL,
			.brightness = 50
	};

	ESP_ERROR_CHECK(led_strip_init(&strip));



    while (true) {
        setLED(&strip, blue);
        sleep(1);
        setLED(&strip, red);
		sleep(1);
		setLED(&strip, green);
		sleep(1);
		setLED(&strip, LEDoff);
		sleep(1);
    }
}
