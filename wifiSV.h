#ifndef WIFISV_H
#define WIFISV_H

#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h> // 引入 ArduinoJson 库

extern WebServer server;  // 定义server为WebServer 开启web服务器
extern JsonDocument doc;  // 定义doc为JsonDocument 用来传输数据
extern String color[2];   // 定义color为String[2] 用来沟通main

/* WiFi初始化; */
/**
 * @brief WiFi初始化;
 * @param ssid 网络名称;
 * @param password 网络密码;
*/
void wifi_init(const char* ssid,const char* password);

/* API初始化 */
/**
 * @brief API初始化;
 * @brief Web_open: 验证接口;                  //在init里调用
 * @brief Web_getdata: 颜色数据接口;            //在init里调用
 * @param jsonDoc 颜色json数据;                 //直接修改doc就行，不需要传参，函数内部会自动修改doc的值，所以不需要返回值
 * @brief Web_putdata: 颜色数据传输接口;         //在init里调用
 * @brief Web_init: http初始化;
 * @brief Web_loop: 循环处理;
*/
void Web_open();
void Web_getdata(JsonDocument& jsonDoc);
void Web_putdata();
void Web_init();
void Web_loop();

#endif