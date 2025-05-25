#include "wifiSV.h"

WebServer server(80); // 启动端口
JsonDocument doc;     // Json
String color[2];
void wifi_init(const char *ssid, const char *password)
{
  WiFi.begin(ssid, password);
  Serial.begin(9600);
  Serial.println("start wifi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println(".");
    delay(1000);
  }
  Serial.print("\n");
  Serial.println("wifi connected");
  Serial.print("IP:");
  Serial.println(WiFi.localIP());
  Serial.print("\n");
};

// open验证接口
void Web_open()
{
  server.send(200, "text/plain", "open");
  Serial.println("open");
}

// getdata颜色数据接口
void Web_getdata(JsonDocument &jsonDoc)
{
  String output;
  serializeJson(jsonDoc, output);
  server.send(200, "application/json", output);
}

// 处理 /putdata 请求的函数
void Web_putdata()
{
  String start = server.arg("start");
  String stop = server.arg("stop");
  color[0] = start;
  color[1] = stop;
}
void Web_init()
{
  server.on("/", []()
            { Web_open(); });
  server.on("/getdata", [&]()
            { Web_getdata(doc); });
  server.on("/putdata", []()
            { Web_putdata(); });
  server.onNotFound([]()
                    { server.send(404, "text/html;charset=UTF-8", "你访问的接口不存在"); });
  server.begin();
};

// 循环处理请求
void Web_loop()
{
  server.handleClient();
}
