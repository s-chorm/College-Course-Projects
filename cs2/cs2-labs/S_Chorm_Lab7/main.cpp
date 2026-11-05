// Chapter 13, Programming Challenge 15: Mortgage Payments - modified

/*
Corrected Errors (Total = 15):

    In Main:

    1. Missing semicolon in main.cpp, double annIntRate
    2. Added "years" in main when calling get_input()
    3. Fixed typo for mort.set_loan_amt(loan)
    4. Added missing & in void get_input(double& loan, double& annIntRate, int& years)
    5. Changed loan to years when getting length of the loan in years, cin  >> years
    6. Fixed conditional statement when getting loan amount, while (loan <= 0)
    7. Fixed typo when calling mort.display_payment_info()

    In "mortgage.h":

    1. Missing semicolon in accessors double display_payment_info()
    2. Corrected to loanAmt in "mortgage.h", constructor
    3. Added parameter "int" in public section in void set_years(int)
    4. Changed void get_payback() to double
    5. Fixed conditional statement in set_years(int yrs), if (yrs <= 0)
    6. Fixed typo in display_payment_info(), add_commas(get_total_interest())
    7. Removed dot operator "mort" in void Mortgage::display_payment_info()
    8. Changed double to void in public section in void display_payment_info()
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "mortgage.h"

using namespace std;

void get_input(double& loan, double& annIntRate, int& years);

int main()
{
    double loan;          	// Amount of the loan
    double annIntRate;   	// Annual interest rate

    int years;        	// Length of the loan in years

    Mortgage mort;    		// Create a Mortgage object.

    get_input(loan, annIntRate, years);


	// Process the data.
    mort.set_loan_amt(loan);          // sets amount of the loan
    mort.set_rate(annIntRate);       // sets annual interest rate
    mort.set_years(years);           // sets length of the loan in years

    mort.display_payment_info();

    cin.ignore();
    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}

void get_input(double& loan, double& annIntRate, int& years)
{
	loan = 0;
	annIntRate = 0;
	years = 0;

	// Get the loan amount.
    while (loan <= 0)
    {
	cout << "\n Mortgage amount must be > 0.";
    	cout << "\n Enter the amount of the mortgage: $";
        cin  >> loan;
    }

	// Get the annual interest rate. Must be positive.
    while (annIntRate <= 0)
    {
        cout << "\n Interest rate must be > 0.";
	cout << "\n Enter the annual interest rate (example 3.5% as 3.5): % ";
        cin  >> annIntRate;
    }

	// Get the length of the loan in years. Must be > 10.
    while (years < 10)
    {
        cout << "\n Years must be 10 or more.";
	cout << "\n Enter the duration in years: ";
        cin  >> years;
    }
}
