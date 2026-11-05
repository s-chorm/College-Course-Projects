/*
Samantha Chorm CSE 110 - Lab 5
Due Date: 3/8/26
Instructor: Dr. Anne C. Pinder
Description: This program prompts the user for the two (2) side lengths of a rectangle and computes the area, perimeter, and the diagonal of the rectangle using four (4) functions that are located in a header file.

Requirements:
1. The program will use two files. Main will contain the prompts for the user and calls to the functions. The header file (*.h) will contain the required functions. Output must be from the output function.
2. Four functions are required (and will be in the separate header file), and #include <cmath>.
3. Prompt for side length 1, then prompt for side length 2 in main
4. Call a function that computes the area of the rectangle and returns the value
5. Call another function that computes the perimeter and returns the value
6. Call another function that computes the diagonal and returns the value
7. Call a void output function that displays all of the values with descriptions as shown below with precision set to 2 places. This function does not return a value.

Test-suit: This is to check multiple parts of the program. Example: Normal: if the user types a number that works as a radius(not less then or equal to zero)should calculate everything.Rating:SuccessExample: Boundary: Should loop if the radius is less than or equal to zero.Rating:SuccesExample:  Extreme: types in a big number like 1000 and works.Rating:Success
*/

#include <iostream>
#include "S_Chorm_Lab5.h"

using namespace std;

int main()
{
    double sideLength1, sideLength2, area, perimeter, diagonal;

    cout << "Enter the length of side one: ";
    cin >> sideLength1;

    cout << "Enter the length of side two: ";
    cin >> sideLength2;

    if (sideLength1 <= 0 || sideLength2 <= 0) {
        cout << "That is not a valid side length." << endl;
    }
    else {
        cout << endl;

        area = getArea(sideLength1, sideLength2);
        perimeter = getPerimeter(sideLength1, sideLength2);
        diagonal = getDiagonal(sideLength1, sideLength2);
        displayResults(area, perimeter, diagonal);
    }

    cin.ignore();
    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}
