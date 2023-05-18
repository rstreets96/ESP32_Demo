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
#define RGB_LED_GPIO 	48


typedef enum
{
	APP_STARTED = 0,
	HTTP_SERVER_STARTED,
	CONNECTED,
	DISCONNECTED
}wifi_status_e;

/*
 * Function to initialize the LRGB LED strip object
 * @return: Returns the LEDstrip object
 */
led_strip_t initLedStrip(void);

/*
* Function to set LED Color to indicate WiFi Status
* @params:	ledStrip	  	pointer to the led strip object
* 			status			Choose value from the wifi_status_e enum to be indicated
*/

void setLEDWifiStatus(wifi_status_e status);



#endif /* MAIN_RGB_LED_H_ */
