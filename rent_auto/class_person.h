#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person {protected:
    string name;
    string email;

public:
    Person(string n, string e) : name(n), email(e) {
        cout << "Constructor Person" << endl;
    }

    virtual ~Person() {
        cout << "Destructor Person" << endl;
    }

    virtual void displayInfo() const {
        cout << " Name: " << name << endl << " Email: " << email;
    }

    string getName() const { return name; }
    string getEmail() const { return email; }
};

#endif