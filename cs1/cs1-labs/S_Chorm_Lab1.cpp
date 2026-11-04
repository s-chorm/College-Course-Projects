/*
Samantha Chorm CSE 110 - Lab 1
Due Date: 2/15/26
Instructor: Dr. Anne C. Pinder
Description: This program computes gross receipts using tickets sold
Requirements:

1. The program will output a request (prompt) for the input of the number of tickets sold
2. The program will compute the gross receipts from the event.
3. The program will compute the profit from the event using the variable for event cost
4. The program will output to the console window the number of tickets sold, gross receipts, and profit formatted as shown below.

Test-suit: This is to check multiple parts of the program. Example: Normal: if the user types a number that works as a radius(not less then or equal to zero)should calculate everything.Rating:SuccessExample: Boundary: Should loop if the radius is less than or equal to zero.Rating:SuccesExample:  Extreme: types in a big number like 1000 and works.Rating:Success
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int ticketsSold;
    double grossReceipts;
    double eventProfit;

    cout << "Enter the number of tickets sold: ";
    cin >> ticketsSold;

    grossReceipts = ticketsSold * 29.0;
    eventProfit = grossReceipts - 1450;

    cout << fixed << setprecision(2);

    cout << endl << "Tickets sold = " << ticketsSold << endl;
    cout << "Gross receipts = $" << grossReceipts << endl;
    cout << "Event profit = $" << eventProfit << endl;

    return 0;
}
