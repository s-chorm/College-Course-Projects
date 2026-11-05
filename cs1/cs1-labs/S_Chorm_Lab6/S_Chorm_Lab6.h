#ifndef S_CHORM_LAB6_H_INCLUDED
#define S_CHORM_LAB6_H_INCLUDED

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void print_banner()
{
    cout << "\t*** This program computes car loan information.          ***" << endl;
    cout << "\t*** Enter the Loan Amount, Interest Rate, and Duration.  ***" << endl << endl << endl;
}

void get_input(double& loan, double& interest, int& duration)
{
    cout << "\t\t" << left << setw(35) << "Amount of Loan";
    cin >> loan;
    while (loan <= 0 || loan >= 120000)
    {
        cout << "\t\t\tInvalid loan amount" << endl;
        cout << "\t\t" << left << setw(35) << "Amount of Loan";
        cin >> loan;
    }

    cout << "\t\t" << left << setw(35) << "Interest Rate (4 for 4%)";
    cin >> interest;
    while (interest < 0 || interest > 12)
    {
        cout << "\t\t\tInvalid interest rate" << endl;
        cout << "\t\t" << left << setw(35) << "Interest Rate (4 for 4%)";
        cin >> interest;
    }

    cout << "\t\t" << left << setw(35) << "Duration of the loan (months)";
    cin >> duration;
    while (duration <= 0 || duration > 72)
    {
        cout << "\t\t\tInvalid duration" << endl;
        cout << "\t\t" << left << setw(35) << "Duration of the loan (months)";
        cin >> duration;
    }
}

double compute_payment(double loan, double interest, int duration)
{
    double effectiveInterest;
    int negDuration;
    double payment;

    effectiveInterest = 0.01 * (interest / 12.0);
    negDuration = duration * -1;
    payment = loan * (effectiveInterest / (1 - (pow(1 + effectiveInterest, negDuration))));

    return payment;
}

void compute_totals(double payment, double loan, int duration, double& payBack, double& totalInterest)
{
    payBack = payment * duration;
    totalInterest = payBack - loan;
}

void display_output(double payment, double loan, int duration, double payBack, double totalInterest)
{
    cout << fixed << setprecision(2);

    cout << "\n\t\t" << left << setw(25) << "Monthly Payment:"
         << right << "$" << setw(10) << payment;
    cout << "\n\n\t\t" << left << setw(25) << "Total Payback Amount:"
         << right << "$" << setw(10) << payBack;
    cout << "\n\n\t\t" << left << setw(25) << "Total Interest paid:"
         << right << "$" << setw(10) << totalInterest << endl;
}

#endif // S_CHORM_LAB6_H_INCLUDED
