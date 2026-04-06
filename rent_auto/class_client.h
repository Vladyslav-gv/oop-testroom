#ifndef CLIENT_H
#define CLIENT_H

#include "class_person.h"

class Client : public Person {
private:
    int clientID;
    int rentalCount;

public:
    Client(string n, string e, int id)
        : Person(n, e), clientID(id), rentalCount(0) {
        cout << "Constructor Client" << endl;
    }

    virtual ~Client() {
        cout << "Destructor Client" << endl;
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << endl << " Client ID: " << clientID << endl << " Rentals: " << rentalCount << endl;
    }

    void rentCar() { rentalCount++; }

    int getID() const { return clientID; }
    int getRent() const { return rentalCount; }
};

#endif