#ifndef Classes_h
#define Classes_h

#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    string model;
    int year;

public:
    // конструкто
    Car() : Car("brand name", "model name", 2000) {}

    Car(string b, string m, int y) : brand(b), model(m), year(y) {
        cout << "constructor1 called\n";
    }

    // деконструктор
    ~Car() {
        cout << "destructor1 called\n";
    }
    //вивід без зміни об'єктів
    void display() const {
        cout << "Car: " << brand << " " << model << " (" << year << ")" << endl;
    }
};

class Client {
private:
    string name;
    string phone;
    int clientId;

public:

    Client() : Client("name", "+**********", 0) {}

    Client(string n, string p, int id) : name(n), phone(p), clientId(id) {
        cout << "constructor2 called\n";
    }

    ~Client() {
        cout << "destructor2 called\n";
    }

    void display() const {
        cout << "Client: " << name << ", Phone: " << phone << ", ID: " << clientId << endl;
    }
};

class Rental {
private:
    int rentdays;
    double cost;

public:

    Rental() : Rental(1, 0.0) {}


    Rental(int days, double priceday): rentdays(days), cost(days * priceday) {
        cout << "constructor3 called\n";
    }

    ~Rental() {
        cout << "destructor3 called\n";
    }

    void display() const {
        cout << "Days: " << rentdays << ", Total cost: " << cost << "$" << endl;
    }
};
#endif
