#ifndef class_rent_H
#define class_rent_H

#include <iostream>
#include <string>
using namespace std;

class Rental {
private:
    int rentdays;
    double cost;

public:

    Rental(int days, double priceday): rentdays(days), cost(days * priceday) {
        cout << "constructor3 called\n";
    }
    Rental() : Rental(1, 0.0) {}



    ~Rental() {
        cout << "destructor3 called\n";
    }

    void display() const {
        cout << "Days: " << rentdays << ", Total cost: " << cost << "$" << endl;
    }
};

#endif
