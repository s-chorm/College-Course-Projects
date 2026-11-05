#ifndef S_CHORM_LAB2_H_INCLUDED
#define S_CHORM_LAB2_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void open_file(const string& input, ifstream& file) {
    file.open(input);

    if (file.is_open()) {
        cout << "\nFile opened successfully.\n" << endl;
    }
    else if (file.fail()) {
        cout << "\nFile failed to open." << endl;
    }
}

void display_file(ifstream& file) {
    string line;
    int lineCount = 0;

    while (getline(file, line)) {
        lineCount++;
        cout << setw(3) << lineCount << ": " << line << endl;

        if (lineCount % 24 == 0) {
            cout << "\tPress ENTER to continue...";
            cin.get();
        }
    }
}

#endif // S_CHORM_LAB2_H_INCLUDED
