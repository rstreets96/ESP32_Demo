/*
 * rgb_led.c
 *
 *  Created on: May 17, 2023
 *      Author: rstre
 */

#include "rgb_led.h"

extern led_strip_t ledStrip;

//Colors for RGB LED
//static rgb_t LEDoff = {.r = 0, .g = 0, .b = 0};
//static rgb_t blue = {.r = 0, .g = 0, .b = 255};
static rgb_t red = {.r = 255, .g = 0, .b = 0};
//static rgb_t green = {.r = 0, .g = 255, .b = 0};
static rgb_t pink = {.r = 255, .g = 102, .b = 255};
static rgb_t yellow = {.r = 204, .g = 255, .b = 51};
static rgb_t mint = {.r = 0, .g = 255, .b = 153};

/*
 * Function to set LED to a given color
 * @params:	ledStrip 	LED strip object,
 * 			color 		desired color to set the LED to. Choose from list above or add new ones
 */
static void setLED(led_strip_t *strip, rgb_t color)
{
	ESP_ERROR_CHECK(led_strip_set_pixel(strip, 0, color));
	ESP_ERROR_CHECK(led_strip_flush(strip));
}



led_strip_t initLedStrip(void)
{
	led_strip_install();
	led_strip_t strip =
	{
			.type = LED_STRIP_WS2812,
			.length = 1,
			.gpio = RGB_LED_GPIO,
			.buf = NULL,
			.brightness = 50
	};
	ESP_ERROR_CHECK(led_strip_init(&strip));

	return strip;
}


void setLEDWifiStatus(wifi_status_e status)
{
	rgb_t color;
	switch(status)
	{
		case APP_STARTED:
			color = pink;
			break;

		case HTTP_SERVER_STARTED:
			color = yellow;
			break;

		case CONNECTED:
			color = mint;
			break;

		case DISCONNECTED:
			color = red;
			break;

		default:
			break;
	}

	setLED(&ledStrip, color);
}


