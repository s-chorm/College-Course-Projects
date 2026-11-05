#include <iostream>
#include <string>
#include "S_Chorm_Lab1.h"

using namespace std;

int main()
{
    int binNum = -1;
    string addRem;

    InventoryBin bins[10] = {
        {"Valve", 10},
        {"Bearing", 5},
        {"Bushing", 15},
        {"Coupling", 21},
        {"Flange", 7},
        {"Gear", 5},
        {"Gear Housing", 5},
        {"Vacuum Gripper", 25},
        {"Cable", 18},
        {"Rod", 12},
    };

    while (binNum != 0) {
        binNum = display_inventory(bins);

        if (binNum != 0 && binNum < 11) {
            cout << "Add or Remove Parts (A or R)? ";
            cin >> addRem;

            while (addRem != "A" && addRem != "R") {
                cout << "ERROR: Invalid input. Enter 'A' to Add or 'R' to Remove: ";
                cin >> addRem;
            }

            if (addRem == "A") {
                add_parts(binNum, bins);
            }
            else if (addRem == "R") {
                remove_parts(binNum, bins);
            }
        }
    }

    cin.ignore();
    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}

/*
PSEUDOCODE:
    1. DISPLAY all Bin Info, 1-10
    2. PROMPT user; enter 0 to quit OR bin #
        2A. If ANSWER == "A", then PROMPT how many parts to add (AMOUNTADD == #)
        2B. Else if ANSWER == "R", then PROMPT how many parts to remove (AMOUNTREMOVE == #)
    3. ERRORS: If ANSWER IS NOT "A" or "R", then REPROMPT user
        3A. AMOUNT ERRORS: If AMOUNTADD is negative, REPROMPT user (cannot enter negative #)
        3B. If AMOUNTREMOVE is more than the # of items in a bin, REPROMPT user (invalid amount)
        3C. If the amount exceeds 30 parts in a bin, REPROMPT user (invalid amount; cannot exceed 30 parts)
    4. Once 2 and 3 are complete, OUTPUT new Bin Info based on what user answered

FOR ORGANIZATION:
    In MAIN: structures, while loop for prompting user
    In HEADER: functions
*/
