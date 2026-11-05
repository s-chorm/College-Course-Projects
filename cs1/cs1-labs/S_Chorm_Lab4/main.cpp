/*
Samantha Chorm CSE 110 - Lab 4
Due Date: 3/1/26
Instructor: Dr. Anne C. Pinder
Description: This program simulates stretching a cable until its breaking point by adding one pound of tension at a time.

Requirements:
1. The program will prompt the user for the length of the cable in feet (must be a positive number) and the cable thickness in inches (from 0.1 up to 2.5) and validate the input. If invalid input is entered, explain the specific input value that is incorrect and prompt   the user to enter it again using a loop.
2. When valid input has been entered, use a loop in the program to increase the tension on the cable one (1) pound at a time from zero (0) pounds to the breaking point, and simulate stretching the cable. The program will display the tension applied to the cable in pounds and the current length of the cable as it stretches each time a pound of tension is added until it breaks. Then the program will announce that the cable has broken.
3. The cable will stretch its’ thickness * 0.28 feet for each pound of tension applied, up to its’ breaking point. The cable will break when its length is 112% of the original length. When the program ends, output your name and Lab #4.
4. The code should be neat, sectioned appropriately, indented, and be easy to follow and see the flow of control, and of course run and produce the correct output. Testing should be comprehensive.

Test-suit: This is to check multiple parts of the program. Example: Normal: if the user types a number that works as a radius(not less then or equal to zero)should calculate everything.Rating:SuccessExample: Boundary: Should loop if the radius is less than or equal to zero.Rating:SuccesExample:  Extreme: types in a big number like 1000 and works.Rating:Success
*/

#include <iostream>

using namespace std;

int main()
{
    double cableLength;
    double cableThickness;
    double stretchPerPound;
    double currentLength;
    double breakingLength;
    int tension;

    cout << "Enter the length of the cable in feet: ";
    cin >> cableLength;

    while (cableLength <= 0) {
        cout << endl << "  " << cableLength << " is not a valid length." << endl;
        cout << endl << "Enter the length of the cable in feet: ";
        cin >> cableLength;
    }

    cout << endl << "Enter the thickness of the cable up to 2.5 inches: ";
    cin >> cableThickness;

    while (cableThickness < 0.1 || cableThickness > 2.5) {
        cout << endl << "  " << cableThickness << " is not a valid thickness.";
        cout << endl << "The thickness must be between 0.1 and 2.5 inches." << endl;
        cout << endl << "Enter the thickness of the cable up to 2.5 inches: ";
        cin >> cableThickness;
    }

    stretchPerPound = cableThickness * 0.28;
    currentLength = cableLength;
    breakingLength = cableLength * 1.12;
    tension = 0;

    while (currentLength < breakingLength) {
        tension++;
        currentLength += stretchPerPound;
        cout << endl << "The tension on the cable is: " << tension << " lbs";
        cout << endl << "The length of the cable is: " << currentLength << " feet" << endl;
    }

    cout << endl << endl << "The Cable has broken.";
    cout << endl << endl << "Samantha Chorm - Lab #4" << endl;

    cin.ignore();
    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}
