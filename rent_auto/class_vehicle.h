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
        cout << "Constructor Vehicle " << endl;
    }
    virtual ~Vehicle() {
        cout << "Destructor Vehicle" << endl;
    }
};

#endif