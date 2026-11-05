/*
Samantha Chorm CSE 110 - Lab 6
Due Date: 3/15/26
Instructor: Dr. Anne C. Pinder
Description: This is a multi-file program for a car dealer that calculates the monthly payment and total payback amount for the inputs of loan amount, interest rate, and loan duration in months.

Requirements:
1. Allow the user to run it multiple times without restarting the program. This loop should be in main.
2. A function for getting and validating the input as follows:
    a. loan amount – must be > than zero and < than $120,000 (double)
    b. interest rate – must be >= 0 and = 12% (double)
    c. duration – must be > 0 and <= 72 months (integer)
3. A function to compute and return the monthly payment amount.
4. A function to compute the total interest paid-in and the total payback amount.
5. A function to produce the output with the amounts right aligned.

Test-suit: This is to check multiple parts of the program. Example: Normal: if the user types a number that works as a radius(not less then or equal to zero)should calculate everything.Rating:SuccessExample: Boundary: Should loop if the radius is less than or equal to zero.Rating:SuccesExample:  Extreme: types in a big number like 1000 and works.Rating:Success
*/

#include <windows.h>
#include <iostream>
#include "S_Chorm_Lab6.h"

using namespace std;

int main()
{
    double loan, interestRate, monthlyPayment, totalInterest, totalPayback;
    int duration;
    char runAgain = 'Y';

    while (runAgain == 'Y' || runAgain == 'y')
    {
        system("CLS");

        print_banner();
        get_input(loan, interestRate, duration);
        monthlyPayment = compute_payment(loan, interestRate, duration);
        compute_totals(monthlyPayment, loan, duration, totalPayback, totalInterest);
        display_output(monthlyPayment, loan, duration, totalPayback, totalInterest);

        cout << "\n\n\t\t\tEnter Y to run again: ";
        cin >> runAgain;
    }

    cin.ignore();
    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}
