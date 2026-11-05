/*
Samantha Chorm CSE 110 - Lab 7
Due Date: 4/5/26
Instructor: Dr. Anne C. Pinder
Description: This program reads in a series of 13 sales dollar amounts from a file, stores the amounts in an array, sorts the array, and outputs to a file named “yourname.txt” and the console the number of sales amounts (the program must count them), the lowest amount, the highest amount, and a complete list of the amounts in order from lowest to highest, and the sum of the amounts.

Requirements:
1. Declare an array of doubles of size 13 using a constant. Read in the amounts and store them, stopping at the end of the file.
2. Required void functions called from main and located in a header file:
    a. Opening the files with error handling
    b. Reading the input and storing the values
    c. Sorting the array
    d. Writing to a file named yourName.txt and displaying the output – the output can be in separate functions.
3. Create an input file named “salesAmounts.txt” with the following values in the order that they appear below vertically in the file. Read until the end-of-file.
    a. 1.06   3.55   12.34   21.40   2.67   3.89   8.98   24.99   6.33   4.99   9.45   0.79   9.95
4. Main should only have declarations for the variables and array, function calls, and file closing. Streams must be declared inside main and passed as needed.

Test-suit: This is to check multiple parts of the program. Example: Normal: if the user types a number that works as a radius(not less then or equal to zero)should calculate everything.Rating:SuccessExample: Boundary: Should loop if the radius is less than or equal to zero.Rating:SuccesExample:  Extreme: types in a big number like 1000 and works.Rating:Success
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "S_Chorm_Lab7.h"

using namespace std;

int main()
{
    ifstream in_stream;
    ofstream out_stream;
    const int SIZE = 13;
    double amounts[SIZE], lowestNum, highestNum, sum;

    open_files(in_stream, out_stream);
    display_banner(out_stream);
    fill_array(in_stream, amounts, SIZE);
    sort_array(amounts, SIZE, lowestNum, highestNum, sum);
    display_output(out_stream, amounts, SIZE, lowestNum, highestNum, sum);

    in_stream.close();
    out_stream.close();

    cin.ignore();
    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}
