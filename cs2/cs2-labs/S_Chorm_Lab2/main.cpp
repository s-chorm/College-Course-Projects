/*
PSEUDOCODE (ALSO IN IPO)

OUTPUT "Enter the file name: "
INPUT userFile

CALL FUNCTION open_file(userFile, inFile)

WHILE (!inFile.is_open()) {
	OUTPUT "ERROR: File not found"
	OUTPUT "Enter the file name: "
	INPUT userFile
	CALL open_file(userFile, inFile)
}

CALL FUNCTION display_file(inFile)

END return 0
*/

#include <iostream>
#include <fstream>
#include <string>
#include "S_Chorm_Lab2.h"

using namespace std;

int main()
{
    string userFile;
    ifstream inFile;

    cout << "Enter the file name: ";
    cin >> userFile;

    open_file(userFile, inFile);

    while (!inFile.is_open()) {
        cout << "ERROR: File not found\n" << endl;
        cout << "Enter the file name: ";
        cin >> userFile;

        open_file(userFile, inFile);
    }

    cin.ignore();
    display_file(inFile);

    inFile.close();

    cin.ignore();
    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}
