# WiFiSV模块说明文档

## 1. 模块概述
这玩意儿是机械臂项目的WiFi通信模块，主要功能是：
- 建立WiFi连接
- 提供Web接口控制机械臂
- 处理颜色数据交互

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
- 参数：WiFi名称和密码
- 功能：连接指定WiFi并输出IP地址

### 3.2 Web接口
提供以下API端点：
- `/` - 验证接口
- `/getdata` - 小程序从这里获取颜色数据(JSON格式)
- `/putdata` - 小程序发送颜色数据到这里

### 3.3 回调机制
```cpp
void Web_putdata(void ESPGetColor());
```
- 当收到颜色数据时自动调用ESPGetColor回调函数

### 3.4 Web_init集体传参
```cpp
void Web_init(const char *doc, void ESPGetColor());
```
- 参数：颜色JSON数据和回调函数
- 功能：初始化Web服务器并一同给`Web_getdata`,`Web_putdata`传参

## 4. 使用示例

### 4.1 初始化
```cpp
// main.cpp中示例
const char *ssid = "507";
const char *password = "507507507507";

void setup() {
  wifi_init(ssid, password);
  Web_init(doc, ESPGetColor); // doc是颜色JSON数据
}
```

### 4.2 处理颜色数据
```cpp
// 回调函数示例
// 全局变量color数组
void ESPGetColor() {
  Serial.println(color[0]); // 起始颜色
  Serial.println(color[1]); // 结束颜色
}
```   