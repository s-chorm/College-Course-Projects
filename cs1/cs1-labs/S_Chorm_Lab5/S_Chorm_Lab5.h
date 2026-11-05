#ifndef S_CHORM_LAB5_H_INCLUDED
#define S_CHORM_LAB5_H_INCLUDED

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

double getArea(double side1, double side2) {
    double area = side1 * side2;
    return area;
}

double getPerimeter(double side1, double side2) {
    double perimeter = 2 * (side1 + side2);
    return perimeter;
}

double getDiagonal(double side1, double side2) {
    double diagonal = sqrt(side1*side1 + side2*side2);
    return diagonal;
}

void displayResults(double area, double perimeter, double diagonal) {
    cout << setprecision(2) << fixed;

    cout << " " << left << setw(35) << "The area of the rectangle is:"
        << right << setw(10) << area << endl;
    cout << " " << left << setw(35) << "The perimeter of the rectangle is:"
        << right << setw(10) << perimeter << endl;
    cout << " " << left << setw(35) << "The diagonal of the rectangle is:"
        << right << setw(10) << diagonal << endl;
}

#endif // S_CHORM_LAB5_H_INCLUDED
