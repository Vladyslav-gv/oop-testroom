#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    string brand;
    double priceday;

public:
    Vehicle(string b = "Unknown", double p = 0) : brand(b), priceday(p) {
        cout << "Constructor Vehicle" << endl;
    }

    virtual ~Vehicle() {
        cout << "Destructor Vehicle" << endl;
    }

    // Virtual functions for polymorphism
    virtual void showInfo() const {
        cout << "Brand: " << brand << endl << " Price per day: " << priceday << "$";
    }

    virtual string getDescribe() const {
        return "Generic Vehicle";
    }

    // Pure virtual function - makes this class abstract
    virtual double tCost(int days) const = 0;

    virtual void performMain() const {}

    string getBrand() const { return brand; }
    double getPriceday() const { return priceday; }
};

#endif