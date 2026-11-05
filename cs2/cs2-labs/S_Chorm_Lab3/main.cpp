#include <iostream>
#include <iomanip>
#include "Circle.h"

using namespace std;

int main()
{
    double radius = 0;

    while (radius <= 0) {
        cout << "Enter the circle's radius: ";
        cin >> radius;

        if (radius <= 0) {
            cout << "That is not a valid radius." << endl << endl;
        }
    }

    Circle userCircle(radius);

    cout << setprecision(2) << fixed;

    cout << "Radius: " << userCircle.getRadius() << endl;
    cout << "Area: " << userCircle.getArea() << endl;
    cout << "Diameter: " << userCircle.getDiameter() << endl;
    cout << "Circumference: " << userCircle.getCircumference() << endl;

    cin.ignore();
    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}

// **********************************
//  Circle
// **********************************
//  - radius : double
//  - pi : double
// **********************************
//  + Circle()
//  + Circle(r : double)
//  + setRadius(r : double) : void
//  + getRadius() : double
//  + getArea() : double
//  + getDiameter() : double
//  + getCircumference() : double
// **********************************
