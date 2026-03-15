#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    string model;
    double priceday;

    static int allcar;

public:

    Car(string b = "Unknown", string m = "Unknown", double p = 0)
        : brand(b), model(m), priceday(p)
    {
        allcar++;
    }

    // Copy constructor
    Car(const Car& other)
        : brand(other.brand), model(other.model), priceday(other.priceday)
    {
        cout << "Copy constructor\n";
        allcar++;
    }

    // Move constructor
    Car(Car&& other) noexcept
        : brand(move(other.brand)), model(move(other.model)), priceday(other.priceday)
    {
        cout << "Move constructor\n";
    }

    // destructor
    ~Car() {
        allcar--;
    }

    // this
    void setPrice(double pricePerDay) {
        this->priceday = pricePerDay;
    }

    // const метод
    void showInfo() const {
        cout << brand << " " << model
             << " - Price: " << priceday << endl;
    }

    // static метод
    static int getCarCount() {
        return allcar;
    }

    // унарний оператор
    Car operator-() const {
        Car temp = *this;
        temp.priceday *= 0.8;
        return temp;
    }

    // бінарний оператор
    bool operator>(const Car& other) const {
        return priceday > other.priceday;
    }

    // stream operators
    friend ostream& operator<<(ostream& os, const Car& car) {
        os << car.brand << " " << car.model
           << " - Price per day: " << car.priceday;
        return os;
    }

    friend istream& operator>>(istream& is, Car& car) {
        cout << "Brand: ";
        is >> car.brand;

        cout << "Model: ";
        is >> car.model;

        cout << "Price per day: ";
        is >> car.priceday;

        return is;
    }
};

int Car::allcar = 0;

#endif