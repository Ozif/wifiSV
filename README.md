# WiFiSV模块说明文档

## 1. 模块概述
这是机械臂项目的小程序通信模块，主要功能是：
- 建立局域网连接
- 提供API接口控制机械臂

## 2. 文件结构
```
Project/
├── include/
│   └── wifiSV.h       # 模块头文件
├── src/
│   ├── wifiSV.cpp     # 模块实现
│   └── main.cpp       # 主程序
```

## 3. 核心功能

### 3.1 WiFi初始化
```cpp
void wifi_init(const char *ssid, const char *password);
```
| 参数名 | 类型 | 是否必填 | 说明 |
|--------|------|----------|------|
| ssid | const char* | 是 | WiFi名称 |
| password | const char* | 是 | WiFi密码 |

- 功能：初始化WiFi连接，建立局域网
- 注意：需与小程序在同个WiFi下，在`setup()`函数中调用

### 3.2 Web_init集体传参
```cpp
void Web_init(void ESPGetColor());
```
| 参数名 | 类型 | 是否必填 | 说明 |
|--------|------|----------|------|
| function | void function() | 是 | 回调函数 |

- 功能：初始化API服务并给`Web_putdata`传参

#### 3.2.1 API接口

| 路径 | 类型 | 说明 |
|------|------|------|
| `/` | GET | 验证接口，返回"open"字符串表示服务正常 |
| `/putdata` | POST | 小程序发送颜色数据的接口，参数：<br>`color` - 目标颜色<br>`dir` - 颜色方位 |

### 3.2.1.1 全局变量`Web_API_get`和`/putdata`的回调机制
```cpp
extern int Web_API_get[2]; // 全局变量
```
```cpp
// 源码
void Web_putdata(void ESPGetColor()); //Web_init传参的函数，后边写为ESPGetColor()，可自行改
```
***全局变量`Web_API_get`***
- 用于存储从Web接口接收到的颜色数据，在`Web_putdata`中处理（接收`color`和`dir`的值），在`ESPGetColor`函数执行前赋值，`ESPGetColor`函数执行时使用
- 格式：`Web_API_get[0]` - 目标颜色，`Web_API_get[1]` - 方位

***`/putdata`的回调机制***
- `ESPGetColor()`Web_init传参的函数，可自行改
- 当收到颜色数据时自动调用`ESPGetColor`回调函数

## 4. 使用示例
```cpp
#include "wifiSV.h"

const char *ssid = WiFi_SSID;
const char *password = WiFi_Password;

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
```

### 4.1 初始化
```cpp
// main.cpp中示例
const char *ssid = wifi_ssid;
const char *password = wifi_password;

void setup() {
  wifi_init(ssid, password);
  Web_init(ESPGetColor);
}
```

### 4.2 处理颜色数据
```cpp
// 回调函数示例
// 全局变量color数组
void ESPGetColor() {
  Serial.println(Web_API_get[0]); // 打印目标颜色
  Serial.println(Web_API_get[1]); // 打印颜色方位
}
```

### 4.3 loop循环
```cpp
void loop() {
  Web_loop();   // 循环处理Web请求
}
```     