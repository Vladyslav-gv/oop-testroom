#ifndef CLIENT_H
#define CLIENT_H

#include "class_person.h"

class Client : public Person {
private:
    string phoneNumber;
public:
    Client(string n = "Unknown", int a = 18, string phone = "None")
        : Person(n, a), phoneNumber(phone) {
        cout << "Constructor Client " << endl;
    }

    ~Client() {
        cout << "Destructor Client" << endl;
    }

    void showInfo() const {
        cout << "Client: " << name << ", Age: " << age << ", phone: " << phoneNumber << endl;
    }
};

#endif