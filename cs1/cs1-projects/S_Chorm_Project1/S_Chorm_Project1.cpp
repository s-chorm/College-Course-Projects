/*
Samantha Chorm CSE 110 - Project 1
Due Date: 3/29/26
Instructor: Dr. Anne C. Pinder
Description: This program computes car loan information using input values read from a file called loan Data.txt.

Requirements:
1. The program must have at least four (4) functions in a header file:
    * A void function for opening the files with file failure conditions
    * A double function to compute and return the payment amount
    * A void function to compute the total interest paid-in and the total payback amount
    * At least one void function for the output. The loop that reads data and calls the functions should be in main.
2. Create the input file (data below) named “loan Data.txt.” The input and output streams must be declared in main and passed as needed to functions.
3. The program must read the data from the data file “loan Data.txt.” There shall be a loop in main that reads data and calls the functions to compute the values and calls the output function, then reads another set of data etc. until the end of file is reached
4. The program shall produce the required output to the console window and to a file “your_ name .txt.” The output shall be as shown below both in the console window and the output file
5. Main will close both of the files before returning zero. Output “Project #1 and your name” at the top as shown below. Use “\t”, and setw(x) as needed.

Test-suit: This is to check multiple parts of the program. Example: Normal: if the user types a number that works as a radius(not less then or equal to zero)should calculate everything.Rating:SuccessExample: Boundary: Should loop if the radius is less than or equal to zero.Rating:SuccesExample:  Extreme: types in a big number like 1000 and works.Rating:Success
*/

#include <iostream>
#include "S_Chorm_Project1.h"
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    ifstream inFile;
    ofstream outFile;
    double loanAmount, interestRate, monthlyPayment, totalInterest, paybackAmount;
    int durationMonths;

    open_files(inFile, outFile);

    display_banner(outFile);

    while (inFile >> loanAmount >> interestRate >> durationMonths)
    {
        monthlyPayment = compute_payment(loanAmount, interestRate, durationMonths);
        compute_totals(monthlyPayment, loanAmount, durationMonths, paybackAmount, totalInterest);
        display_output(outFile, monthlyPayment, loanAmount, paybackAmount, totalInterest);
    }

    inFile.close();
    outFile.close();

    cin.ignore();
    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}
