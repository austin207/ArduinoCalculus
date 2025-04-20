# AutoTunePID

### 🧠 Real-time Auto-Tuning PID Controller for Arduino and ESP32  
**Author:** Antony Austin  
**Version:** 1.0.0

---

## 🚀 Overview

**AutoTunePID** is a production-level Arduino/ESP32-compatible library for real-time control using a PID controller that self-optimizes its gains.

It uses high-accuracy numerical differentiation and integration (from the `ArduinoCalculus` library) to tune PID parameters for various system models and feedback scenarios.

This library is ideal for robotics, automation, sensor-based systems, and anything that requires stable dynamic control — without manual tuning.

---

## 🎯 Features

- ✅ Automatic Kp, Ki, Kd tuning using simulated error minimization  
- ✅ Numerical integral and derivative support using calculus approximation  
- ✅ Clean C++ interface, compatible with Arduino and ESP32  
- ✅ Lightweight and optimized for embedded deployment  
- ✅ Fully open-source and modular

---

## 🔧 Installation

1. Download the ZIP or clone the GitHub repo.
2. Place it in your `Arduino/libraries/` directory.
3. Restart Arduino IDE.

> Will soon be available via **Arduino Library Manager**!

---

## 🧪 Example Usage

```cpp
#include <AutoTunePID.h>

float setpoint = 100;

// Simulated error signal
float errorFunction(float t) {
  return sin(t) + 0.2 * cos(2 * t);
}

AutoTunePID pid(errorFunction, setpoint);

void setup() {
  Serial.begin(115200);
  pid.tune(); // Automatically tunes Kp, Ki, Kd
}

void loop() {
  float currentValue = analogRead(A0);
  pid.update(currentValue, 0.01);
  float output = pid.getOutput();
  analogWrite(DAC1, output); // Example actuator output
  delay(10);
}
