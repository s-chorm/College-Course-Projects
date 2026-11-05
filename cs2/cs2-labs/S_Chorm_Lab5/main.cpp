#include <iostream>
#include "S_Chorm_Lab5_ShipClasses.h"

using namespace std;

int main() {

    // Create an array of Ship pointers, initialized with the addresses of 3 dynamically allocated objects.

    Ship *ships[3] = {
        new Ship("Lollipop", "1960"),
        new CruiseShip("Disney Magic", "1998", 2400),
        new CargoShip("Black Pearl", "1800", 50000)
    };

    for (int index=0; index < 3; index++) {    // call each object�s print function
        ships[index] -> print();
        cout << "----------------------------\n";
    }

    for (int index = 0; index < 3; index++) {    // free the dynamic memory
        delete ships[index];
    }

    cin.ignore();
    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;

}
