#include "wifiSV.h"

// WiFi信息
const char *ssid = "507";
const char *password = "507507507507";

// 先创建个Json对象
JsonDocument doc;

// getcolor  回调函数，给Web_init传给Web_putdata，可以自己改
void ESPGetColor()
{
  Serial.println(color[0]);
  Serial.println(color[1]);
}

void setup()
{
  // 给Web_init传给Web_getdata，可以自己改
  // 给Json对象赋值
  const char *color = "{\"color\":[\"red\",\"green\",\"blue\",\"pink\"]}";
  DeserializationError error = deserializeJson(doc, color);
  if (error)
  {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }
  
  wifi_init(ssid, password);
  Web_init(doc, ESPGetColor);
}

void loop()
{
  Web_loop();
}