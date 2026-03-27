#include "class_rent.h"

int Car::allcar = 0;

int main() {

    Client customer("Bred", 36, "0501112233");


    GasCar gascar("Koenigsegg", "Agera R", 2500, 10.5);
    ElectricCar elcar("Tesla", "Cybertruck", 3000, 77);


    Car discountedAudi = -gascar;


    Rent contract(customer, elcar, 3);
    contract.displayContract();


    cout << "Car count: " << Car::getCarCount() << endl;

    return 0;
}