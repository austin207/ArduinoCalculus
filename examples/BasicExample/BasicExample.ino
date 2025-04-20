#include <ArduinoCalculus.h>

float testFunc(float x) {
  return sin(x);
}

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.print("Avg sin(x) in [0, PI]: ");
  Serial.println(ArduinoCalculus::averageValue(testFunc, 0, PI), 6);

  Serial.print("RMS sin(x) in [0, PI]: ");
  Serial.println(ArduinoCalculus::rootMeanSquare(testFunc, 0, PI), 6);

  Serial.print("Second derivative of sin at PI/2: ");
  Serial.println(ArduinoCalculus::secondDerivative(testFunc, PI/2), 6);
}

void loop() {}