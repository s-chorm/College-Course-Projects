/*
Samantha Chorm CSE 110 - Lab 3
Due Date: 2/22/26
Instructor: Dr. Anne C. Pinder
Description: This program computes the subtotal, sales tax, and total amount for a pizza parlor.

Requirements:
1. The program will prompt the user to enter 1 , 2, or 3 for small, medium, or large.
2. It will then prompt the user for the number of pizzas (must be > 0).
3. The program will validate the input and if invalid data is entered the program will output “Invalid Data” and end, otherwise it will compute the values.
4. Validation of input; use of a named constant for sales tax const double SALES_TAX = 0.07; output as shown using setw(x) and format specifiers (pages 113-120), and dollar signs

Test-suit: This is to check multiple parts of the program. Example: Normal: if the user types a number that works as a radius(not less then or equal to zero)should calculate everything.Rating:SuccessExample: Boundary: Should loop if the radius is less than or equal to zero.Rating:SuccesExample:  Extreme: types in a big number like 1000 and works.Rating:Success
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const double SALES_TAX = 0.07;
    const double smallPizzaPrice = 12.50;
    const double mediumPizzaPrice = 14.75;
    const double largePizzaPrice = 16.50;

    int pizzaChoice;
    int pizzaNum;
    double subtotal;
    double tax;
    double total;


    cout << "Enter 1 for Small, 2 for Medium, or 3 for Large: ";
    cin >> pizzaChoice;

    if (pizzaChoice < 1 || pizzaChoice > 3) {
        cout << "Invalid Data";
        return 0;
    }

    cout << "Enter the number of pizzas: ";
    cin >> pizzaNum;

    if (pizzaNum <= 0) {
        cout << "Invalid Data";
        return 0;
    }

    if (pizzaChoice == 1) {
        subtotal = smallPizzaPrice * pizzaNum;
    } else if (pizzaChoice == 2) {
        subtotal = mediumPizzaPrice * pizzaNum;
    } else if (pizzaChoice == 3) {
        subtotal = largePizzaPrice * pizzaNum;
    }

    tax = SALES_TAX * subtotal;
    total = subtotal + tax;

    cout << setprecision(2) << fixed << "\n";

    cout << setw(12) << "Subtotal"
        << setw(7) << "$"
        << setw(6) << subtotal << endl;

    cout << setw(12) << "Sales Tax"
        << setw(7) << "$"
        << setw(6) << tax << endl;

    cout << setw(25) << "----------" << endl;

    cout << setw(12) << "Total"
        << setw(7) << "$"
        << setw(6) << total << endl;

    cin.ignore();
    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}
