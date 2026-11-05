#ifndef S_CHORM_LAB5_SHIPCLASSES_H_INCLUDED
#define S_CHORM_LAB5_SHIPCLASSES_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

// Ship class

class Ship {
    private:
        string name;    // Ship name
        string yearBuilt;    // Year it was built
    public:
        Ship(string n, string y)    // Constructor
        {
            name = n;
            yearBuilt = y;
        }

        string getName()    // Accessors
        { return name; }

        string getYearBuilt()
        { return yearBuilt; }

        virtual void print()
        {
            cout << "Name: " << name << endl
            << "Year built: " << yearBuilt << endl;
        }

        virtual ~Ship() {}
};

class CruiseShip : public Ship {
    private:
        int maxPassengers;
    public:
        CruiseShip(string n, string y, int passengers) : Ship(n, y) {
            maxPassengers = passengers;
        }
        int getMaxPassengers() const { return maxPassengers; }
        void setMaxPassengers(int passengers) { maxPassengers = passengers; }

        void print() override {
            cout << "Name: " << getName() << endl
            << "Maximum passengers: " << maxPassengers << endl;
        }
};

class CargoShip : public Ship {
    private:
        int cargoCapacity;
    public:
        CargoShip(string n, string y, int capacity) : Ship(n, y) {
            cargoCapacity = capacity;
        }
        int getCargoCapacity() const { return cargoCapacity; }
        void setCargoCapacity(int capacity) { cargoCapacity = capacity; }

        void print() override {
            cout << "Name: " << getName() << endl
            << "Cargo capacity: " << cargoCapacity << " tons" << endl;
        }
};

#endif // S_CHORM_LAB5_SHIPCLASSES_H_INCLUDED
