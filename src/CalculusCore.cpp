#include "CalculusCore.h"
#include <math.h>

float (*ArduinoCalculus::savedFunc)(float) = nullptr;

float ArduinoCalculus::simpson(float (*f)(float), float a, float b) {
    float c = (a + b) / 2.0;
    return (b - a) / 6.0 * (f(a) + 4.0 * f(c) + f(b));
}

float ArduinoCalculus::adaptiveSimpson(float (*f)(float), float a, float b, float eps, float S) {
    float c = (a + b) / 2.0;
    float Sleft = simpson(f, a, c);
    float Sright = simpson(f, c, b);
    if (fabs(Sleft + Sright - S) <= 15 * eps) return Sleft + Sright + (Sleft + Sright - S) / 15.0;
    return adaptiveSimpson(f, a, c, eps / 2.0, Sleft) + adaptiveSimpson(f, c, b, eps / 2.0, Sright);
}

float ArduinoCalculus::integrate(float (*f)(float), float a, float b, float eps) {
    return adaptiveSimpson(f, a, b, eps, simpson(f, a, b));
}

float ArduinoCalculus::integrateArray(const float x[], const float y[], int n) {
    float integral = 0.0;
    for (int i = 0; i < n - 1; i++) {
        float h = x[i + 1] - x[i];
        integral += (h / 6.0) * (y[i] + 4 * ((y[i] + y[i + 1]) / 2.0) + y[i + 1]);
    }
    return integral;
}

float ArduinoCalculus::differentiate(float (*f)(float), float x, float h, bool highAccuracy) {
    if (highAccuracy) {
        return (-f(x + 2*h) + 8*f(x + h) - 8*f(x - h) + f(x - 2*h)) / (12*h);
    }
    return (f(x + h) - f(x - h)) / (2*h);
}

float ArduinoCalculus::secondDerivative(float (*f)(float), float x, float h) {
    return (f(x + h) - 2*f(x) + f(x - h)) / (h * h);
}

float ArduinoCalculus::averageValue(float (*f)(float), float a, float b) {
    float integral = integrate(f, a, b);
    return integral / (b - a);
}

float ArduinoCalculus::rootMeanSquare(float (*f)(float), float a, float b) {
    savedFunc = f;
    float meanSquare = integrate(currentFunc, a, b) / (b - a);
    return sqrt(meanSquare);
}

float ArduinoCalculus::currentFunc(float x) {
    float val = savedFunc(x);
    return val * val;
}
