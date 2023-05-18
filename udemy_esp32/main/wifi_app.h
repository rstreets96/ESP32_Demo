/*
 * wifi_app.h
 *
 *  Created on: May 18, 2023
 *      Author: rstre
 */

#ifndef MAIN_WIFI_APP_H_
#define MAIN_WIFI_APP_H_

#include "esp_netif.h"
#include "freertos/FreeRTOS.h"

//Wifi app settings
#define WIFI_AP_SSID				"ESP32_AP"					// Wifi Name
#define WIFI_AP_PASSWORD			"password"					// Password for AP
#define WIFI_AP_CHANNEL				1							// Channel 1 selection
#define WIFI_AP_SSID_HIDDEN			0							// Select visible for AP visibility
#define WIFI_AP_MAX_CONNECTIONS		5							// Max number of devices that can connect simultaneously
#define WIFI_AP_BEACON_INTERVAL		100							// 100 ms time between Beacons, recommended as default
#define WIFI_AP_IP					"192.168.0.1"				// AP default IP
#define WIFI_AP_GATEWAY				"192.168.0.1"				// AP default gateway, same as IP
#define WIFI_AP_NETMASK				"255.255.255.0"				// AP Netmask
#define WIFI_AP_BANDWIDTH			WIFI_BW_HT20				// Bandwidth set to 20 MHz (40 MHz is the other option)
#define WIFI_STA_POWER_SAVE			WIFI_PS_NONE				// Power Save not used
#define MAX_SSID_LENGTH				32							//IEEE Standard Maximum
#define MAX_PASSWORD_LENGTH			64							//IEEE Standard Maximum
#define MAX_CONNECTION_RETRIES		5							//Retry number on disconnect


//Netif object for the Station and Access Point
extern esp_netif_t* esp_netif_sta;
extern esp_netif_t* esp_netif_ap;


//Message IDs for the Wifi application task
typedef enum wifi_app_message
{
	WIFI_APP_MSG_START_HTTP_SERVER = 0,
	WIFI_APP_MSG_CONNECTING_FROM_HTTP_SERVER,
	WIFI_APP_MSG_STA_CONNECTED_GOT_IP
}wifi_app_message_e;


//Structure for the message queue
typedef struct wifi_app_queue_message
{
	wifi_app_message_e msgID;
}wifi_app_queue_message_t;


/*
 * Sends a message to the queue
 * @param 	msgID 		message ID from the wifi_app_message_e enum
 * @return	pdTRUE if successful, else return pdFALSE
 */
BaseType_t wifi_app_send_message(wifi_app_message_e msgID);


/*
 * Starts the WiFi RTOS task
 */
void wifi_app_start(void);

#endif /* MAIN_WIFI_APP_H_ */
