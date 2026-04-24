#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

#include "class_car.h"

class ElectricCar : public Car {
private:
    int batteryCapacity;

public:
    ElectricCar(string b, string m, double p, int cap)
        : Car(b, m, p), batteryCapacity(cap) {
        cout << "Constructor ElectricCar" << endl;
    }

    int getType() const override { return 2; }
    double getExtra() const override { return getCapacity(); }

    virtual ~ElectricCar() {
        cout << "Destructor ElectricCar" << endl;
    }

    void showInfo() const override final{
        Car::showInfo();
        cout << endl << " Type: Electric "<< endl <<" Capacity: " << batteryCapacity << " kWh";
    }

    string getDescribe() const override {
        return "Electric Car - " + brand + " " + model;
    }

    double tCost(int days) const override final{
        return priceday * days * 0.8; // Electric cars have 20% discount
    }

    void performMain() const override {
        cout << "Battery check" << endl;
    }

    void nonVirtual() const {}

    int getCapacity() const { return batteryCapacity; }
};

#endif