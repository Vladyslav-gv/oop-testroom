#ifndef GASCAR_H
#define GASCAR_H

#include "class_car.h"

class GasCar : public Car {
private:
    double fuelConsumption;
public:
    GasCar(string b, string m, double p, double cons)
        : Car(b, m, p), fuelConsumption(cons) {
    }
    ~GasCar() {}

    void showInfo() const override {
        Car::showInfo();
        cout << " | Тип: Gas | Consume: " << fuelConsumption << " l/100km" << endl;
    }
};

#endif