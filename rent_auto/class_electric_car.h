#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

#include "class_car.h"

class ElectricCar : public Car {
private:
    int batteryCapacity;
public:
    ElectricCar(string b, string m, double p, int cap)
        : Car(b, m, p), batteryCapacity(cap) {
    }
    ~ElectricCar() {}

    void showInfo() const override {
        Car::showInfo();
        cout << " | Type: Electro | Capacity: " << batteryCapacity << " kWh" << endl;
    }
};

#endif