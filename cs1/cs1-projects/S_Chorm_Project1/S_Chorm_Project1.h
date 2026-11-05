#ifndef S_CHORM_PROJECT1_H_INCLUDED
#define S_CHORM_PROJECT1_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

void display_banner(ofstream& outFile)
{
    cout << "\tProject #1 - Samantha Chorm" << endl << endl;
    cout << "\t   Loan\t\t  Monthly\t   Total\t  Payback\n";
    cout << "\t  Amount\t  Payment\t  Interest\t  Amount\n";
    cout << "\t----------------------------------------------------------\n";

    outFile << "\tProject #1 - Samantha Chorm" << endl << endl;
    outFile << "\t   Loan\t\t  Monthly\t   Total\t  Payback\n";
    outFile << "\t  Amount\t  Payment\t  Interest\t  Amount\n";
    outFile << "\t----------------------------------------------------------\n";
}

void open_files(ifstream& inFile, ofstream& outFile)
{
    inFile.open("loanData.txt");

    if (inFile.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    outFile.open("SamanthaChorm.txt");

    if (outFile.fail())
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }
}

double compute_payment(double loan, double interest, int duration)
{
    double monthlyPayment;
    double effectiveInterest;
    int negDuration;

    if (interest == 0)
    {
        monthlyPayment = loan / duration;
    }
    else
    {
        effectiveInterest = 0.01 * (interest / 12.0);
        negDuration = duration * -1;
        monthlyPayment = loan * (effectiveInterest / (1 - (pow(1 + effectiveInterest, negDuration))));
    }

    return monthlyPayment;
}

void compute_totals(double payment, double loan, int duration, double& payBack, double& totalInterest)
{
    payBack = payment * duration;
    totalInterest = payBack - loan;
}

void display_output(ofstream& outFile, double payment, double loan, double payBack, double totalInterest)
{
    cout << fixed << setprecision(2) << right;
    outFile << fixed << setprecision(2) << right;

    cout << endl << "\t$ " << setw(8) << loan
         << "\t$ "<< setw(8) << payment
         << "\t$ " << setw(8) << totalInterest
         << "\t$ " << setw(8) << payBack << endl;

    outFile << endl << "\t$ " << setw(8) << loan
            << "\t$ " << setw(8) << payment
            << "\t$ " << setw(8) << totalInterest
            << "\t$ " << setw(8) << payBack << endl;
}

#endif // S_CHORM_PROJECT1_H_INCLUDED
