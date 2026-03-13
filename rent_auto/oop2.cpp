#include "Class_rent.h"
#include "class_client.h"
#include "class_car.h"

int main() {

    Car carinfo("Koenigsegg", "Agera R", 2011);
    Client clientinfo("Gitol Valet", "+0862846368", 14);
    Rental rentalinfo(5, 17000.0);

    carinfo.display();
    clientinfo.display();
    rentalinfo.display();

    return 0;
}