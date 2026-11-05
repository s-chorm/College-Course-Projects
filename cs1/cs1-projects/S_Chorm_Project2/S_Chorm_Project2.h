#ifndef S_CHORM_PROJECT2_H_INCLUDED
#define S_CHORM_PROJECT2_H_INCLUDED

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

void open_files(ifstream& in_stream)
{
    in_stream.open("sales_and_cost_amounts.txt");

    if (in_stream.fail())
    {
        cout << "Input data file opening failed.";
        exit(1);
    }
}

void store_values(ifstream& in_stream, vector<double>& sales, vector<double>& costs)
{
    double saleTemp, costTemp;

    while (in_stream >> saleTemp >> costTemp)
    {
        sales.push_back(saleTemp);
        costs.push_back(costTemp);
    }
}

void display_output(vector<double>& sales, vector<double>& costs)
{
    cout << fixed << setprecision(2);

    cout << "\t Project #2 - Samantha Chorm" << "\n\n";
    cout << "\t The number of sales in the file is: " << sales.size() << endl;
    cout << "\t Amounts sorted from lowest to highest:" << "\n\n";
    cout << "\t " << left << setw(17) << "Sale Price"
         << right << setw(6) << "Cost"
         << setw(16) << "Profit" << "\n\n";

    double totalSales = 0, totalCost = 0, totalProfit = 0;

    for (int i = 0; i < sales.size(); i++)
    {
        double currentProfit = sales[i] - costs[i];

        cout << "\t$ " << right << setw(6) << sales[i] << "\t"
             << "$ " << setw(6) << costs[i] << "\t"
             << "$ " << setw(6) << currentProfit << endl;

        //Find sum for each
        totalSales += sales[i];
        totalCost += costs[i];
        totalProfit += currentProfit;
    }

    //Output of sums
    cout << "\t--------\t--------\t--------\t" << endl;
    cout << "\t$ " << setw(6) << totalSales << "\t"
         << "$ " << setw(6) << totalCost << "\t"
         << "$ " << setw(6) << totalProfit << endl;
}

//void display_output()

#endif // S_CHORM_PROJECT2_H_INCLUDED
