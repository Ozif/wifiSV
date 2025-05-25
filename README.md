#  wifiSV使用说明

---

## 1.文件放置位置
`wifiSV.h`文件放置在`include`文件夹中;
`wifiSV.cpp`文件放置在有`main.cpp`存在的`src`文件夹中。
```plaintext
├── include\
│   └── wifiSV.h
├── src\
│   ├── main.cpp
│   └── wifiSV.cpp
```

---

## 2.使用方法

### 式例
```cpp
#include "wifiSV.h"

// WiFi信息
const char *ssid = "507";
const char *password = "507507507507";

// json
JsonDocument doc;

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
```
#### 解释
> 01.`#include "wifiSV.h"`引入wifiSV;
> 02.`wifi_init(ssid, password);`在`setup`调用，作用：wifi初始化,`ssid`为wifi名称,`password`为wifi密码;
> 03.`Web_init();`在`setup`调用，作用：API初始化;
> 04.`Web_loop();`开启服务需要在`loop()`中调用;

#### 注意
`main.cpp`中需要有名为`doc`的`JsonDocument`变量用于存储从`k210`获取来的颜色信息,`Web_init()`会自动获取`doc`给`Web_getdata`API使用。

---
## 微信小程序如`wx小程序`所示
