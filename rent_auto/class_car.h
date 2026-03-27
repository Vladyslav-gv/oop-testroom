#ifndef CAR_H
#define CAR_H

#include "class_vehicle.h"

class Car : public Vehicle {
protected:
    string model;
    static int allcar;
public:
    Car(string b = "Unknown", string m = "Unknown", double p = 0)
        : Vehicle(b, p), model(m) {
        allcar++;
        cout << "Constructor Car " << endl;
    }

    // Copy constructor
    Car(const Car& other) : Vehicle(other.brand, other.priceday), model(other.model) {
        allcar++;
        cout << "Copy Constructor Car" << endl;
    }

    // Move constructor
    Car(Car&& other) noexcept : Vehicle(move(other.brand), other.priceday), model(move(other.model)) {
        cout << "Move Constructor Car" << endl;
    }

    // Operator=
    Car& operator=(const Car& other) {
        if (this != &other) {
            brand = other.brand;
            model = other.model;
            priceday = other.priceday;
        }
        return *this;
    }

    virtual ~Car() {
        allcar--;
        cout << "Destructor Car" << endl;
    }

    static int getCarCount() { return allcar; }
    void setPrice(double p) { this->priceday = p; }

    Car operator-() const {
        Car temp = *this;
        temp.priceday *= 0.9;
        return temp;
    }

    virtual void showInfo() const {
        cout << brand << " " << model << " | Price: " << priceday << "$";
    }
};

#endif