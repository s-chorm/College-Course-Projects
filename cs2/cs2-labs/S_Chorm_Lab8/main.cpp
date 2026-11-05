#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Product.h"

using namespace std;

void display_products(vector<Product> p);

int main()
{
    ifstream inFile("productInfo.txt");
    vector<Product> p;

    string name;
    double price;
    int units;

    string userNewName;
    char userChoice;
    double userNewPrice;

    if (!inFile.is_open()) {
        cout << "ERROR: File could not be opened.";
        return 1;
    }

    while (inFile >> name >> price >> units) {
        p.emplace_back(name, price, units);
    }

    inFile.close();

    display_products(p);

    cout << "\tName of product to change: ";
    cin >> userNewName;
    cout << "Enter p, u, or r to change price, units, or reorder point: ";
    cin >> userChoice;

    for (int i = 0; i < p.size(); i++) {
        if (p[i].getName() == userNewName) {
            if (userChoice == 'p' || userChoice == 'P') {
                double newPrice;
                cout << "What would you like to change it to? ";
                cin >> newPrice;
                p[i].setPrice(newPrice);
            }
            else if (userChoice == 'u' || userChoice == 'U') {
                int newUnits;
                cout << "What would you like to change it to? ";
                cin >> newUnits;
                p[i].setUnits(newUnits);
            }
            else if (userChoice == 'r' || userChoice == 'R') {
                int newReorder;
                cout << "What would you like to change it to? ";
                cin >> newReorder;
                p[i].setReorderPoint(newReorder);
            }
        }
    }

    display_products(p);

    cin.ignore();
    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}

void display_products(vector<Product> p)
{
    cout << "\tThe list of products is:" << endl << endl;
    cout << "   Name" << setw(12) << "Price" << setw(10) << "Units" << setw(15) << "Reorder Pt" << endl;

    for (int i = 0; i < p.size(); i++) {
        cout << "   " << left << setw(10) << p[i].getName()
             << right << fixed << setprecision(2) << setw(6) << p[i].getPrice()
             << setw(9) << p[i].getUnits()
             << setw(12) << p[i].getReorderPoint() << endl;
    }
    cout << endl;
}
