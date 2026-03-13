#ifndef class_car_H
#define class_car_H

#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    string model;
    int year;

public:
    Car(string b, string m, int y) : brand(b), model(m), year(y) {
        cout << "constructor1 called\n";
    }
    // конструктоp
    Car() : Car("brand name", "model name", 2000) {}



    // деконструктор
    ~Car() {
        cout << "destructor1 called\n";
    }
    //вивід без зміни об'єктів
    void display() const {
        cout << "Car: " << brand << " " << model << " (" << year << ")" << endl;
    }
};

#endif