#ifndef GASCAR_H
#define GASCAR_H

#include "class_car.h"

class GasCar : public Car {
private:
    double fuelConsumption;

public:
    GasCar(string b, string m, double p, double cons)
        : Car(b, m, p), fuelConsumption(cons) {
        cout << "Constructor GasCar" << endl;
    }

    virtual ~GasCar() {
        cout << "Destructor GasCar" << endl;
    }

    void showInfo() const override {
        Car::showInfo();
        cout << endl << " Type: Gas " << endl << " Consumption: " << fuelConsumption << " l/100km";
    }

    string getDescribe() const override {
        return "Gas Car - " + brand + " " + model;
    }

    double tCost(int days) const override {
        return priceday * days * 1.1; // Gas cars have 10% surcharge
    }

    void performMain() const override {
        cout << "Fuel system check" << endl;
    }

    void nonVirtual() const {}

    double getFuel() const { return fuelConsumption; }
};

#endif