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
        cout << "Constructor Car" << endl;
    }

    // Copy constructor
    Car(const Car& other) : Vehicle(other.brand, other.priceday), model(other.model) {
        allcar++;
        cout << "Copy Constructor Car" << endl;
    }

    // Move constructor
    Car(Car&& other) noexcept : Vehicle(move(other.brand), other.priceday), model(move(other.model)) {
        allcar++;
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

    // Overriding virtual function
    virtual void showInfo() const override {
        cout << brand << " " << model << endl << " Price: " << priceday << "$";
    }

    virtual string getDescribe() const override {
        return "Car - " + brand + " " + model;
    }

    // Implementing pure virtual function
    virtual double tCost(int days) const override {
        return priceday * days;
    }

    virtual void performMain() const override {
        cout << "Car maintenance: Oil change, tire rotation, brake check" << endl;
    }

    // Non-virtual method - demonstrates static binding
    void nonVirtual() const {}

    string getModel() const { return model; }
};

int Car::allcar = 0;

#endif