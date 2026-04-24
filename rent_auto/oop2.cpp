#include <iostream>
#include <vector>
#include <fstream>
#include <string>


#include "class_car.h"
#include "class_gas_car.h"
#include "class_electric_car.h"
#include "class_client.h"

using namespace std;


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
    string adminPassword = "192837"; // password

    void loadCars();
    void saveCars();
    void logHistory(const Client& client, const Car* car, int days, double cost);
    void viewHistory();


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



RentalSystem::RentalSystem() {
    loadCars();
}

RentalSystem::~RentalSystem() {
    saveCars();
    for (Car* car : cars) {
        delete car;
    }
}

void RentalSystem::clearInput() {
    cin.clear();
    while (cin.get() != '\n') {
        continue;
    }
}

int RentalSystem::getSafeInt() {
    int val;
    cin >> val;
    if (cin.fail()) {
        clearInput();
        throw CustomException("Try again");
    }
    return val;
}

double RentalSystem::getSafeDouble() {
    double val;
    cin >> val;
    if (cin.fail()) {
        clearInput();
        throw CustomException("Try again");
    }
    return val;
}

void RentalSystem::loadCars() {
    ifstream file("cars.txt");
    if (file.is_open()) {
        int type;
        string brand, model;
        double price, extra;
        while (file >> type >> brand >> model >> price >> extra) {
            if (type == 1) cars.push_back(new GasCar(brand, model, price, extra));
            else if (type == 2) cars.push_back(new ElectricCar(brand, model, price, extra));
        }
        file.close();
    }
}

void RentalSystem::saveCars() {
    ofstream file("cars.txt");
    if (file.is_open()) {
        for (Car* car : cars) {
            file << car->getType() << " "
                 << car->getBrand() << " "
                 << car->getModel() << " "
                 << car->getPriceday() << " "
                 << car->getExtra() << "\n";
        }
        file.close();
    }
}

void RentalSystem::logHistory(const Client& client, const Car* car, int days, double cost) {
    ofstream file("history.txt", ios::app);
    if (file.is_open()) {
        file << "Client ID: " << client.getID() << " | " << client.getName()
             << " Rent by " << car->getDescribe()
             << " on " << days << " day. Total cost: " << cost << "$\n";
        file.close();
    }
}

void RentalSystem::viewHistory() {
    ifstream file("history.txt");
    if (file.is_open()) {
        string line;
        cout << "\n=== rent history ===\n";
        bool empty = true;
        while (getline(file, line)) {
            cout << line << endl;
            empty = false;
        }
        if (empty) cout << "empty history .\n";
        file.close();
    } else {
        cout << "file not found).\n";
    }
}

void RentalSystem::adminMenu() {
    string pass;
    cout << "Enter Password: ";
    cin >> pass;
    if (pass != adminPassword) {
        throw CustomException("wrong password!");
    }

    int choice = 0;
    while (choice != 4) {
        cout << "\n=== Admin menu ===\n";
        cout << "1. add gas car\n";
        cout << "2. add ell_car\n";
        cout << "3. Check rent history\n";
        cout << "4. exit\n";
        cout << "What do we do: ";

        try {
            choice = getSafeInt();
            if (choice == 1 || choice == 2) {
                string brand, model;
                double price, extra;

                cout << "Brand: "; cin >> brand;
                cout << "Model: "; cin >> model;
                cout << "Price: "; price = getSafeDouble();

                if (choice == 1) {
                    cout << "gas consuming (l/km): "; extra = getSafeDouble();
                    cars.push_back(new GasCar(brand, model, price, extra));
                    cout << "Gas car added\n";
                } else {
                    cout << "battery consuming (kWh): "; extra = getSafeDouble();
                    cars.push_back(new ElectricCar(brand, model, price, extra));
                    cout << "ell_car added\n";
                }
                saveCars();
            }
            else if (choice == 3) {
                viewHistory();
            }
        } catch (const CustomException& e) {
            cout << "error: " << e.getMessage() << endl;
        }
    }
}

void RentalSystem::userMenu() {
    cout << "\n=== customer ===\n";
    string name, email;
    int id;

    cout << "name: "; cin >> name;
    cout << "surname: "; cin >> email;
    cout << "ID: ";

    try {
        id = getSafeInt();
        Client client(name, email, id);

        int choice = 0;
        while (choice != 3) {
            cout << "\n=== Customer menu ===\n";
            cout << "1. all car\n";
            cout << "2. Rent auto\n";
            cout << "3. Exit\n";
            cout << "Your choice: ";

            choice = getSafeInt();

            if (choice == 1) {
                if (cars.empty()) cout << "sorry but we empty.\n";
                for (size_t i = 0; i < cars.size(); i++) {
                    cout << "\n--- Car #" << i + 1 << " ---";
                    cars[i]->showInfo();
                    cout << endl;
                }
            }
            else if (choice == 2) {
                if (cars.empty()) {
                    cout << "no car.\n";
                    continue;
                }

                cout << "enter car number (1-" << cars.size() << "): ";
                int carIndex = getSafeInt() - 1;

                if (carIndex < 0 || carIndex >= cars.size()) {
                    throw CustomException("wrong car number!");
                }

                cout << "how long? ";
                int days = getSafeInt();
                if (days <= 0) throw CustomException("must be greter than 0!");

                double cost = cars[carIndex]->tCost(days);
                client.rentCar();
                logHistory(client, cars[carIndex], days, cost);

                cout << "\ncar rented " << cars[carIndex]->getBrand()
                     << " on " << days << " day.\nTotal cost: " << cost << "$\n";
            }
        }
    } catch (const CustomException& e) {
        cout << "error: " << e.getMessage() << endl;
    }
}

void RentalSystem::run() {
    int choice = 0;
    while (choice != 3) {
        cout << "\n=================================\n";
        cout << "           Rent system          \n";
        cout << "=================================\n";
        cout << "1. enter like admin\n";
        cout << "2. enter like customer\n";
        cout << "3. exit\n";
        cout << "";

        try {
            choice = getSafeInt();
            if (choice == 1) adminMenu();
            else if (choice == 2) userMenu();
            else if (choice == 3) cout << "";
            else throw CustomException("wrong choice!");
        } catch (const CustomException& e) {
            cout << "error: " << e.getMessage() << endl;
        }
    }
}


int main() {
 

    RentalSystem app;
    app.run();

    return 0;
}