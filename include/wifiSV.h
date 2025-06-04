#ifndef WIFISV_H
#define WIFISV_H

#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

extern WebServer server;            // 定义server为WebServer 开启web服务器
extern String Web_API_get[2];       // 定义color为String[2] 用来沟通main，在ESPGetColor函数调用前改变，可在ESPGetColor函数调里直接使用

/* WiFi初始化; */
/**
 * @brief wifi_init: WiFi初始化;
 * @param ssid WiFi名称;
 * @param password WiFi密码;
 * @SerialPrint 输出ip地址用小程序连接;
 */
void wifi_init(const char *ssid, const char *password);

/* API初始化 */
/**
 * @brief Web_open: 验证接口;               //在init里调用
 *
 * @brief Web_putdata: 数据传输接口;         //在init里调用
 * @param ESPGetColor 回调函数;             //ESPGetColor为回调函数，方便main处理颜色数据
 *
 * @brief Web_init: http初始化;
 * @param ESPGetColor 回调函数; (给Web_putdata传参);  //ESPGetColor为回调函数，方便main处理颜色数据
 *
 * @brief Web_loop: 循环处理;
 */
// void Web_open();
// void Web_putdata(void ESPGetColor());
void Web_init(void ESPGetColor());
void Web_loop();

#endif