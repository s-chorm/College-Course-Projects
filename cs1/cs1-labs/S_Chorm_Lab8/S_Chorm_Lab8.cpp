/*
Samantha Chorm CSE 110 - Lab 8
Due Date: 4/19/26
Instructor: Dr. Anne C. Pinder
Description: This program requests a word or phrase from the user, and inspects the input for the number of words, digits, uppercase letters, lowercase letters, spaces, and other characters.

Requirements:
1. Assume that there will never be multiple spaces together.
2. Allow the user to enter another without restarting the program.
3. At the end of main, add your Test Cases (10 points) as comments in the code.
4. Required functions called from main and located in a header file:
    a. Prompt for and getting input - use getline(cin, var)
    b. Inspecting the input and displaying the contents

Test-suit: This is to check multiple parts of the program. Example: Normal: if the user types a number that works as a radius(not less then or equal to zero)should calculate everything.Rating:SuccessExample: Boundary: Should loop if the radius is less than or equal to zero.Rating:SuccesExample:  Extreme: types in a big number like 1000 and works.Rating:Success
*/

#include <iostream>
#include <string>
#include "S_Chorm_Lab8.h"

using namespace std;

int main()
{
    string userInput;
    char again = 'y';

    while (again == 'y' || again == 'Y')
    {
        userInput = "";
        get_input(userInput);
        inspect_input(userInput);
        cout << "\nEnter Y to run again: ";
        cin >> again;
        cin.ignore();
        cout << "\n";
    }

    cin.ignore();
    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}

/*
TEST CASES


Engineer Name: Samantha Chorm

Project/program description: This program requests a word or phrase from the user, and inspects the input for the number of words, digits, uppercase letters, lowercase letters, spaces, and other characters.


Test Case #1: Check if userInput successfully gets input.
    * In header and in void get_input, add "cout << word;" to see user's input.
    * Expected Results: Console shows user's input without any errors.
Results (Update when successful; edit if test fails): SUCCESS


Test Case #2: Check that the function inspect_input scans every character and counts correctly.
    * While in Command Prompt, enter multiple different inputs after each reset (e.g. salad, Pizza, Hot dog, Word and }|L:", etc.) and make sure the count for each category updates correctly.
    * Expected Results: Entering anything will not give an error and update each count accurately.
Results: SUCCESS


Test Case #3: Check that the output matches the format (screenshot in requirements)
    * While in Command Prompt, enter words and redo with 'Y' as needed, with multiple examples as listed previously. Make sure everything is in order and has no errors.
Results: SUCCESS
*/
