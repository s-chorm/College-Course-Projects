#ifndef S_CHORM_LAB1_H_INCLUDED
#define S_CHORM_LAB1_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct InventoryBin {
    string bin_type;
    int bin_quantity;
};

// Note: Assumes numeric input

int display_inventory(const InventoryBin index[]) {
    int choice = -1;

    cout << "\nWarehouse Inventory" << endl;

    for (int i = 0; i < 10; i++) {
        cout << " Bin #" << setw(3) << (i + 1) << ",   Part: " << index[i].bin_type
             << ", Quantity: " << index[i].bin_quantity << endl;
    }

    cout << "\nEnter 0 to quit, or choose a bin Number: ";
    cin >> choice;

    while (choice < 0 || choice > 10) {
        cout << "ERROR: Choice must be between 0 and 10.";
        cout << "\nEnter 0 to quit, or choose a bin Number: ";
        cin >> choice;
    }

    if (choice == 0) {
        return 0;
    }

    return choice;
}

void add_parts(int binNumber, InventoryBin index[]) {
    int addAmount;
    int currentQty = index[binNumber - 1].bin_quantity;

    cout << "How many parts to add? ";
    cin >> addAmount;

    while (addAmount < 0 || (currentQty + addAmount) > 30) {
        if (addAmount < 0) {
            cout << "ERROR: Cannot add negative number of parts.\n";
        }
        else {
            cout << "ERROR: Bin capacity cannot exceed 30 parts.\n";
        }
        cout << "How many parts to add? ";
        cin >> addAmount;
    }

    index[binNumber - 1].bin_quantity += addAmount;
}

void remove_parts(int binNumber, InventoryBin index[]) {
    int removeAmount;
    int currentQty = index[binNumber - 1].bin_quantity;

    cout << "How many parts to remove? ";
    cin >> removeAmount;

    while (removeAmount < 0 || removeAmount > currentQty) {
        if (removeAmount < 0) {
            cout << "ERROR: Cannot remove negative number of parts.\n";
        }
        else {
            cout << "ERROR: Cannot remove more parts than amount currently in the bin.\n";
        }

        cout << "How many parts to remove? ";
        cin >> removeAmount;
    }

    index[binNumber - 1].bin_quantity -= removeAmount;
}

#endif // S_CHORM_LAB1_H_INCLUDED
