# See the build system documentation in IDF programming guide
# for more information about component CMakeLists.txt files.

idf_component_register(
    SRCS main.c rgb_led.c wifi_app.c http_server.c   		
    INCLUDE_DIRS "."
    REQUIRES led_strip esp_wifi nvs_flash esp_http_server app_update
    EMBED_FILES webpage/app.css webpage/app.js webpage/favicon.ico webpage/index.html webpage/jquery-3.3.1.min.js
)
