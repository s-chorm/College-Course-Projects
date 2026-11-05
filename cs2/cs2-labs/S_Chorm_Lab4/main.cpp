#include <iostream>
#include <fstream>
#include <iomanip>
#include "DivSales.h"

using namespace std;

int main()
{
    ifstream inputFile;
    int userDivision;

    cout << setprecision(2) << fixed;

    inputFile.open("SalesFile.txt");
    if (!(inputFile.is_open())) {
        cout << "ERROR OPENING FILE";
        return 1;
    }

    DivSales divisions[6];

    for (int i = 0; i < 6; i++) {
        for (int q = 0; q < 4; q++) {
            double quarterSale;
            inputFile >> quarterSale;

            divisions[i].qtrs[q] = quarterSale;
            divisions[i].setDivSales(quarterSale);
            divisions[i].setCorpSales(quarterSale);
        }
    }

    cout << "\nEnter a division (1-6), or 0 to quit: ";
    cin >> userDivision;

    while(userDivision != 0) {
        int index = userDivision - 1;

        if (userDivision >= 1 && userDivision <= 6) {
            cout << "\tDivision #" << userDivision << "\tQuarter 1 sales: $" << divisions[index].qtrs[0] << endl;
            cout << "\tDivision #" << userDivision << "\tQuarter 2 sales: $" << divisions[index].qtrs[1] << endl;
            cout << "\tDivision #" << userDivision << "\tQuarter 3 sales: $" << divisions[index].qtrs[2] << endl;
            cout << "\tDivision #" << userDivision << "\tQuarter 4 sales: $" << divisions[index].qtrs[3] << endl;

            cout << "\n\tDivision #" << userDivision << " total sales are: $" << divisions[index].getDivSales() << endl;
        }
        else {
            cout << "\tInvalid input; please enter a number from 1 to 6." << endl;
        }

        cout << "\n\nEnter a division (1-6), or 0 to quit: ";
        cin >> userDivision;
    }

    cout << "\n\tTotal corporate sales: $" << divisions[0].getCorpSales() << endl;

    inputFile.close();

    cin.ignore();
    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}
