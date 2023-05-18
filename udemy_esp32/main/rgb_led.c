/*
 * rgb_led.c
 *
 *  Created on: May 17, 2023
 *      Author: rstre
 */
#include "rgb_led.h"

void setLED(led_strip_t *ledStrip, rgb_t color)
{
	ESP_ERROR_CHECK(led_strip_set_pixel(ledStrip, 0, color));
	ESP_ERROR_CHECK(led_strip_flush(ledStrip));
}


