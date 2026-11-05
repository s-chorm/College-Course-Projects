#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    ifstream inFile("GasPrices.txt");
    ofstream outFile("S_Chorm.txt");

    string delim = ":";
    map<string, vector<double>> gasMap; // Stores all info from inFile

    string line;

    cout << setprecision(2) << fixed;
    outFile << setprecision(2) << fixed;

    if (!inFile.is_open()) {
        cout << "ERROR: Could not open inFile." << endl;
        return 1;
    }
    else if (!outFile.is_open()) {
        cout << "ERROR: Could not open outFile." << endl;
        return 1;
    }

    while (getline(inFile, line)) {
        int colonPos = line.find(delim);

        if (colonPos != string::npos) { // Checks if colonPos was found, then extracts year
            string dateStr = line.substr(0, colonPos);
            string year = dateStr.substr(dateStr.length() - 4);

            string priceStr = line.substr(colonPos + 1);
            double price = stod(priceStr);

            gasMap[year].push_back(price);
        }
    }

    for (auto element : gasMap) {
        string years = element.first;
        vector<double> prices = element.second;

        sort(prices.begin(), prices.end());

        double highest = prices.back();
        double lowest = prices.front();

        double sum = 0;
        for (double p : prices) {
            sum += p;
        }
        double average = sum / prices.size();

        cout << "Year: " << years << " - Gas Prices per Gallon" << endl
             << "Highest price: $" << setw(5) << highest << endl
             << "Lowest price:  $" << setw(5) << lowest << endl
             << "Average price: $" << setw(5) << average << endl << endl;

        outFile << "Year: " << years << " - Gas Prices per Gallon" << endl
                << "Highest price: $" << setw(5) << highest << endl
                << "Lowest price:  $" << setw(5) << lowest << endl
                << "Average price: $" << setw(5) << average << endl << endl;
    }

    inFile.close();
    outFile.close();

    cin.ignore();
    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}
