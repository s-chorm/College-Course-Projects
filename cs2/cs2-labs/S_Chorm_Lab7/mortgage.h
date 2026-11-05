#ifndef MORTGAGE_H_INCLUDED
#define MORTGAGE_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Mortgage
{
    private:
        // Private member data
        double loanAmt,              // loan amount
            annIntRate,           // annual interest rate
            moIntRate;            // monthy interest rate

        int years;                // length of the loan in years
        int numPmts;              // number of monthly payments

        // Private member function
        double term() const; 	// used in calculation of mo. payment

    public:
        // Constructor
        Mortgage()
        { loanAmt = annIntRate = moIntRate = years = numPmts = 0; }

        // Mutators
        void set_loan_amt(double);
        void set_rate(double);
        void set_years(int);

        // Accessors
        double get_monthly() const;
        double get_payback() const;
        double get_total_interest() const;
        string add_commas(double num);
        void display_payment_info();

};




//***************************************
// get_monthly member function           *
//***************************************

double Mortgage::get_monthly() const
{
    double monthlyPayment = 0;

    if (moIntRate == 0.0)
        monthlyPayment = loanAmt / numPmts;
    else
        monthlyPayment = (loanAmt * (moIntRate) * term()) / (term() - 1);

    return monthlyPayment;
}

//***************************************
// term member function                 *
//***************************************

double Mortgage::term() const
{
    double trm = pow(1 + (moIntRate), numPmts);

    return trm;
}

//***************************************
// get_payback member function           *
//***************************************

double Mortgage::get_payback() const
{
   return (get_monthly() * numPmts);
}

//***************************************
// set_loan_amt member function           *
//***************************************

void Mortgage::set_loan_amt(double amt)
{
   if (amt < 0)
   {
      cout << "Invalid loan amount.\n";
      exit(EXIT_FAILURE);
   }

   loanAmt = amt;
}

//***************************************
// set_rate member function              *
//***************************************

void Mortgage::set_rate(double rate)
{
   if (rate < 0)
   {
      cout << "Invalid interest rate.\n";
      exit(EXIT_FAILURE);
   }

   annIntRate = rate/100;
   moIntRate = rate/12/100;
}

//***************************************
// set_years member function             *
//***************************************

void Mortgage::set_years(int yrs)
{
   if (yrs <= 0)
   {
      cout << "Invalid number of years.\n";
      exit(EXIT_FAILURE);
   }

   years = yrs;
   numPmts = yrs * 12;
}


//***************************************
// get_total_interest member function             *
//***************************************
double Mortgage::get_total_interest() const
{
    double paybk = get_payback();
    double totInt = paybk - loanAmt;

    return totInt;

}


//***************************************
// add_commas member function             *
//***************************************
string Mortgage::add_commas(double num)
{
    std::stringstream stream;
    stream << std::fixed << setprecision(2) << num;

    string numString = stream.str();

    //cout << "numString is " << numString << endl << endl;

    for (int i = numString.length() - 6; i > 0; i = i - 3)
        numString.insert(i, ",");

    //cout << "Converted numString is " << numString << endl << endl;

    return numString;
}


void Mortgage::display_payment_info()
{

    // Display payment information
    cout << fixed << showpoint << setprecision(2);
    cout << "\n\tLoan Amount:\t\t\t $" << setw(11) << add_commas(loanAmt) << endl << endl;
    cout << "\tInterest Rate:\t\t\t       %" << setw(5) << annIntRate * 100 << endl << endl;
    cout << "\tLoan duration in years:\t\t    " << setw(9) << years << endl << endl;

    cout << "\tMonthly Payment:\t\t $" << setw(11) << add_commas(get_monthly()) << endl << endl;
    cout << "\tTotal Pay Back Amount:\t\t $"  << setw(11) << add_commas(get_payback()) << endl << endl;
    cout << "\tTotal Interest Paid-in\t\t $" << setw(11) << add_commas(get_total_interest()) << endl << endl;
}



#endif // MORTGAGE_H_INCLUDED
