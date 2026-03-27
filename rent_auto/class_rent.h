#ifndef RENT_H
#define RENT_H

#include "class_client.h"
#include "class_gas_car.h"
#include "class_electric_car.h"

class Rent {
private:
    // Композиція: Rent включає в себе об'єкти інших класів
    Client client;
    Car car;
    int days;

public:
    Rent(Client cl, Car c, int d) : client(cl), car(c), days(d) {}

    void displayContract() const {
        cout << "\nRent" << endl;
        client.showInfo();
        car.showInfo();
        cout << "\nTime: " << days << " day." << endl;
    }
};

#endif