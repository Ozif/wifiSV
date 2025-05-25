#ifndef WIFISV_H
#define WIFISV_H

#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h> // 引入 ArduinoJson 库

extern WebServer server; // 定义server为WebServer 开启web服务器
extern String color[2];  // 定义color为String[2] 用来沟通main，在ESPGetColor函数调用前改变，可在ESPGetColor函数调里直接使用


/* WiFi初始化; */
/**
 * @param ssid 网络名称;
 * @param password 网络密码;
 * @return 无返回值;
 * @SerialPrint 输出ip用小程序连接;
 */
void wifi_init(const char *ssid, const char *password);

/* API初始化 */
/**
 * @brief Web_open: 验证接口;                  //在init里调用
 * 
 * @brief Web_getdata: 颜色数据接口;            //在init里调用
 * @param jsonDoc 颜色json数据;
 * 
 * @brief Web_putdata: 颜色数据传输接口;         //在init里调用
 * @param ESPGetColor 颜色数据回调函数;（不用管，init函数会自动给它传回调函数）; //ESPGetColor为回调函数，方便main处理颜色数据
 * 
 * @brief Web_init: http初始化;
 * @param jsonDoc 颜色json数据;                 //给Web_putdata函数用
 * @param ESPGetColor 颜色数据回调函数; (给Web_putdata函数传);  //ESPGetColor为回调函数，方便main处理颜色数据
 * 
 * @brief Web_loop: 循环处理;
 */
void Web_open();
void Web_getdata(JsonDocument &jsonDoc);
void Web_putdata(void ESPGetColor());
void Web_init(JsonDocument &jsonDoc, void ESPGetColor());
void Web_loop();

#endif