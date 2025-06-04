#include "wifiSV.h"

// WiFi信息
const char *ssid = "507";
const char *password = "507507507507";

// ESPGetColor  回调函数，给Web_init传给Web_putdata，可以自己改
void ESPGetColor()
{
  Serial.println(Web_API_get[0]);
  Serial.println(Web_API_get[1]);
}

void setup()
{
  wifi_init(ssid, password);
  Web_init(ESPGetColor);
}

void loop()
{
  Web_loop();
}