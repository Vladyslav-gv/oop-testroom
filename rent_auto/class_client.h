#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>

using namespace std;

class Client {
private:
    string name;
    int age;

public:

    Client(string n = "Unknown", int a = 18)
        : name(n), age(a) {}

    void showInfo() const {
        cout << "Client: " << name
             << " Age: " << age << endl;
    }
};

#endif