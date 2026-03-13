#ifndef class_client_H
#define class_client_H

#include <iostream>
#include <string>
using namespace std;

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

#endif