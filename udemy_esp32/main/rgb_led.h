/*
 * rgb_led.h
 *
 *  Created on: May 17, 2023
 *      Author: rstre
 */

#ifndef MAIN_RGB_LED_H_
#define MAIN_RGB_LED_H_

#include "led_strip.h"

//Addressable RGB LED GPIO
#define RGB_LED_GPIO 48

//Colors for RGB LED
static rgb_t LEDoff = {.r = 0, .g = 0, .b = 0};
static rgb_t blue = {.r = 0, .g = 0, .b = 255};
static rgb_t red = {.r = 255, .g = 0, .b = 0};
static rgb_t green = {.r = 0, .g = 255, .b = 0};
static rgb_t pink = {.r = 5, .g = 5, .b = 255};
static rgb_t yellow = {.r = 5, .g = 5, .b = 255};
static rgb_t mint = {.r = 5, .g = 5, .b = 255};

//Function
extern void setLED(led_strip_t *, rgb_t);


#endif /* MAIN_RGB_LED_H_ */
