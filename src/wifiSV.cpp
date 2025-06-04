#include "wifiSV.h"

WebServer server(80);  // 启动端口
String Web_API_get[2]; // 小程序获取起止颜色

// wifi初始化
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

// 处理 / 请求的函数
void Web_open()
{
  server.send(200, "text/plain", "open");
  Serial.println("open");
}

// 处理 /putdata 请求的函数
void Web_putdata(void ESPGetColor())
{
  String color = server.arg("color");
  String dir = server.arg("dir");
  Web_API_get[0] = color;
  Web_API_get[1] = dir;
  ESPGetColor();
}

// 初始化 HTTP 服务器
void Web_init(void ESPGetColor())
{
  server.on("/", []()
            { Web_open(); });
  server.on("/putdata", [&]()
            { Web_putdata(ESPGetColor); });
  server.onNotFound([]()
                    { server.send(404, "text/html;charset=UTF-8", "你访问的接口不存在"); });
  server.begin();
};

// 循环处理请求
void Web_loop()
{
  server.handleClient();
}