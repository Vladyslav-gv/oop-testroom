#include "iostream"
#include "Classes.h"
int main() {

    Car carinfo("Koenigsegg", "Agera R", 2011);
    Client clientinfo("Gitol Valet", "+0862846368", 14);
    Rental rentalinfo(5, 17000.0);

    carinfo.display();
    clientinfo.display();
    rentalinfo.display();

    return 0;
}