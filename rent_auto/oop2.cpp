#include "class_car.h"
#include "class_client.h"
#include "class_rent.h"

int main() {

    Car car1("Koenigsegg", "Agera R", 17000);

    // Copy constructor
    Car car2 = car1;

    // Move constructor
    Car car3 = move(car2);

    car1.setPrice(17000);

    const Car car4("Mazda", "RX7", 12000);
    car4.showInfo();

    cout << "Cars in stack: " << Car::getCarCount() << endl;

    Car cheapCar = -car1;

    cout << cheapCar << endl;


    Car userCar;

    cin >> userCar;

    cout << userCar << endl;

    Client client("Bred", 36);

    Rental rent(car1, client, 3);

    rent.showInfo();

    return 0;
}