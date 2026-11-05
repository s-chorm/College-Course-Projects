#ifndef S_CHORM_LAB7_H_INCLUDED
#define S_CHORM_LAB7_H_INCLUDED

#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

void display_banner(ofstream& outFile)
{
    cout << "Samantha Chorm - Lab #7" << endl;
    outFile << "Samantha Chorm - Lab #7" << endl;
}

void open_files(ifstream& inFile, ofstream& outFile)
{
    inFile.open("salesAmounts.txt");

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

void fill_array(ifstream& inFile, double sales[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        inFile >> sales[i];

    }
}

void sort_array(double sales[], int arraySize, double& lowestAmount, double& highestAmount, double& sum)
{
    for (int i = arraySize - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (sales[j] > sales[j+1])
            {
                double temp = sales[j+1];
                sales[j+1] = sales[j];
                sales[j] = temp;
            }

    lowestAmount = sales[0];
    highestAmount = sales[arraySize - 1];
    sum = 0;

    for (int i = 0; i < arraySize; i++)
    {
        sum += sales[i];
    }
}

void display_output(ofstream& outFile, double sales[], int arraySize, double lowestAmount, double highestAmount, double sum)
{
    cout << fixed << setprecision(2) << right;
    outFile << fixed << setprecision(2) << right;

    cout << "The lowest sales amount is: $" << lowestAmount << endl;
    cout << "The highest sales amount is: $" << highestAmount << endl;
    cout << "The list of sales amounts sorted from lowest to highest:\n\n";
    outFile << "The lowest sales amount is: $" << lowestAmount << endl;
    outFile << "The highest sales amount is: $" << highestAmount << endl;
    outFile << "The list of sales amounts sorted from lowest to highest:\n\n";

    for (int i = 0; i < arraySize; i++)
    {
        if (sales[i] < 10)
        {
            cout << "\t $ " << setw(5) << sales[i] << endl;
            outFile << "\t $ " << setw(5) << sales[i] << endl;
        }
        else
        {
            cout << "\t $" << setw(6) << sales[i] << endl;
            outFile << "\t $" << setw(6) << sales[i] << endl;
        }
    }

    cout << "\t ---------" << endl;
    cout << "\t $" << setw(6) << sum << endl;
    outFile << "\t ---------" << endl;
    outFile << "\t $" <<  setw(6) << sum << endl;
}

#endif // S_CHORM_LAB7_H_INCLUDED
