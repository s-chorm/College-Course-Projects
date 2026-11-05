/*
Samantha Chorm CSE 110 - Project 2
Due Date: 4/12/26
Instructor: Dr. Anne C. Pinder
Description: This program reads in a series of sales dollar amounts and cost dollar amounts from a file that are tab separated (tab delimited), and store the amounts in two (2) vectors.

Requirements:
1. Sort both of the vectors from lowest to highest. The price and cost will coincide when sorted.
2. Output the sorted lists of sales and costs to the console window, in two (2) columns right aligned, and the sum for each column. Use “\t”, setw(x), and include dollar signs and precision as appropriate. The totals may be computed in the output function.
    a. EXTRA CREDIT (10 Points): Compute the profit for each sale and output to a third column in the console window along with the sum of the profit. The profits may be computed in the output function.
3. Required functions called from main and included in a header file:
    a. Opening the input file with error handling (shown)
    b. Reading the input and storing the values in vectors
    c. Output to the console window.
    * Sort may be called from main using the vector sort function shown below. The function definitions are to be in the header file.
4. Create the input file named “sales_and_cost_amounts.txt” and add the following values in the order that they appear in two (2) columns with a tab between them. The sale price is in the left column and cost is to the right. Use them to compute profit for extra credit.

Test-suit: This is to check multiple parts of the program. Example: Normal: if the user types a number that works as a radius(not less then or equal to zero)should calculate everything.Rating:SuccessExample: Boundary: Should loop if the radius is less than or equal to zero.Rating:SuccesExample:  Extreme: types in a big number like 1000 and works.Rating:Success
*/

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include "S_Chorm_Project2.h"

using namespace std;

int main()
{
    ifstream inFile;
    vector<double> saleAmounts;
    vector<double> costAmounts;

    open_files(inFile);
    store_values(inFile, saleAmounts, costAmounts);

    sort(saleAmounts.begin(), saleAmounts.end());
    sort(costAmounts.begin(), costAmounts.end());

    display_output(saleAmounts, costAmounts);

    inFile.close();

    cin.ignore();
    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}
