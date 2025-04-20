#ifndef ARDUINO_CALCULUS_H
#define ARDUINO_CALCULUS_H

#include <Arduino.h>

class ArduinoCalculus {
public:
    // Integration
    static float integrate(float (*f)(float), float a, float b, float eps = 1e-5);
    static float integrateArray(const float x[], const float y[], int n);

    // Differentiation
    static float differentiate(float (*f)(float), float x, float h = 0.001, bool highAccuracy = true);
    static float secondDerivative(float (*f)(float), float x, float h = 0.001);

    // Average & RMS
    static float averageValue(float (*f)(float), float a, float b);
    static float rootMeanSquare(float (*f)(float), float a, float b);

private:
    static float adaptiveSimpson(float (*f)(float), float a, float b, float eps, float S);
    static float simpson(float (*f)(float), float a, float b);
    static float currentFunc(float x);
    static float (*savedFunc)(float);
};

#endif
