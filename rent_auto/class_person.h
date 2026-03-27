#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n = "Unknown", int a = 0) : name(n), age(a) {
        cout << "Constructor Person" << endl;
    }
    virtual ~Person() {
        cout << "Destructor Person" << endl;
    }

    void showPersonInfo() const {
        cout << "Name: " << name << ", Age: " << age;
    }
};

#endif