#ifndef RENTAL_H
#define RENTAL_H

#include "class_car.h"
#include "class_client.h"

class Rental {
private:
    Car car;
    Client client;
    int days;

public:

    Rental(Car c, Client cl, int d)
        : car(c), client(cl), days(d) {}

    double totalcost() const {
        return days * 50;
    }

    void showInfo() const {

        client.showInfo();
        car.showInfo();

        cout << "Days: " << days << endl;
        cout << "Total cost: " << totalcost() << endl;
    }
};

#endif