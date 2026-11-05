/*
Samantha Chorm CSE 110 - Project 3
Due Date: 4/30/26
Instructor: Dr. Anne C. Pinder
Description: This program computes an Evacuation Status for the International Space Station (ISS) based upon the size and distance of a Meteor coming toward the station. The program will accept a meteor size in meters and distance from the station in miles, and output to the console the Meteor Data and Status of Evacuation as shown.

Requirements:
1. This Project requires creating a header file for the functions. Refer to creating header files and multi-file programming information.
2. Prompt the user for meteor size in meters, and the distance from ISS in miles using a void function in the header file.
    a. Validate the input…must be > 0
3. Determine the following two values using a single function located in the header file:
    a. The speed of the meteor (size in meters * 120 mph)
    b. Time to impact (distance /speed in mpm)
4. Determine this value using a function in the header file that returns a string
    a. The Evacuation Status (based on the criteria provided)
5. Display the results as shown below using an output function in the header file
6. Create a loop in main to run the program multiple times and clear the screen between runs using system(“CLS”)

Test-suit: This is to check multiple parts of the program. Example: Normal: if the user types a number that works as a radius(not less then or equal to zero)should calculate everything.Rating:SuccessExample: Boundary: Should loop if the radius is less than or equal to zero.Rating:SuccesExample:  Extreme: types in a big number like 1000 and works.Rating:Success
*/

#include <iostream>
#include <windows.h>
#include "S_Chorm_Project3.h"

using namespace std;

int main()
{
    double meteorSize, meteorDistance, meteorSpeed, meteorTimeImpact;
    string evacuationStatus;
    char userResponse = 'y';

    while (userResponse == 'y' || userResponse == 'Y')
    {
        system("CLS");

        prompt_user(meteorSize, meteorDistance);
        calculate_data(meteorSize, meteorDistance, meteorSpeed, meteorTimeImpact);
        evacuationStatus = get_status(meteorTimeImpact);
        output_result(meteorSize, meteorDistance, meteorSpeed, meteorTimeImpact, evacuationStatus);

        cout << "Enter Y to run another, any other key to quit. ";
        cin >> userResponse;
    }

    cin.ignore();
    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}
