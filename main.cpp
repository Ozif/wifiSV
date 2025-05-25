#include "wifiSV.h"

// WiFi信息
const char *ssid = "507";
const char *password = "507507507507";


void setup()
{
  const char *color = "{\"color\":[\"red\",\"green\",\"blue\",\"pink\"]}";
  DeserializationError error = deserializeJson(doc, color);
  if (error)
  {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }
  wifi_init(ssid, password);
  Web_init();
}

void loop()
{
  Web_loop();
}