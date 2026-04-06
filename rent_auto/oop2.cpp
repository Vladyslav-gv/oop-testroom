#include <iostream>
#include "class_car.h"
#include "class_gas_car.h"
#include "class_electric_car.h"
#include "class_client.h"

using namespace std;

int main() {

    // Create different car types
    GasCar gasCar("Koenigsegg", "Agera R", 50.0, 8.5);
    ElectricCar electricCar("Tesla", "Cybertruck", 60.0, 75);

    cout << endl << "Car info" << endl;
    gasCar.showInfo();
    cout << endl;
    electricCar.showInfo();
    cout << endl << endl;

    // Polymorphic behavior with pointers
    Car* car1 = &gasCar;
    Car* car2 = &electricCar;

    int rentalDays = 6;
    cout << "Gas Car rental for " << rentalDays << " days: $" << car1->tCost(rentalDays) << endl;
    cout << "Electric Car rental for " << rentalDays << " days: $" << car2->tCost(rentalDays) << endl << endl;

    // Virtual function calls
    cout << "Capacity check" << endl;
    car1->performMain();
    car2->performMain();
    cout << endl;

    // Static binding demonstration
    car1->nonVirtual();
    car2->nonVirtual();
    cout << endl;

    // Person and Client polymorphism
    cout << "Clients" << endl;
    Client client1("John Doe", "john@example.com", 6401);
    Client client2("Jane Smith", "jane@example.com", 2624);

    client1.displayInfo();
    client2.displayInfo();

    // Simulate rentals
    client1.rentCar();
    client1.rentCar();
    client2.rentCar();

    cout << endl << "Refresh statistic" << endl;
    client1.displayInfo();
    client2.displayInfo();
    cout << endl;
    return 0;
}