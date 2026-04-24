#ifndef RENTAL_SYSTEM_H
#define RENTAL_SYSTEM_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "class_car.h"
#include "class_gas_car.h"
#include "class_electric_car.h"
#include "class_client.h"

using namespace std;

// Власний клас для обробки винятків (замість stdexcept)
class CustomException {
private:
    string message;
public:
    CustomException(string msg) : message(msg) {}
    string getMessage() const { return message; }
};

class RentalSystem {
private:
    vector<Car*> cars;
    string adminPassword = "admin"; // Пароль адміністратора

    void loadCars();
    void saveCars();
    void logHistory(const Client& client, const Car* car, int days, double cost);
    void viewHistory();

    // Функція для очищення потоку вводу (замість <limits>)
    void clearInput();
    int getSafeInt();
    double getSafeDouble();

public:
    RentalSystem();
    ~RentalSystem();

    void run();
    void adminMenu();
    void userMenu();
};

#endif