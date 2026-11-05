#ifndef S_CHORM_PROJECT3_H_INCLUDED
#define S_CHORM_PROJECT3_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void prompt_user(double& sizeofmeteor, double& distanceofmeteor)
{
    cout << "Enter the meteor size in meters: ";
    cin >> sizeofmeteor;
    while (sizeofmeteor <= 0)
    {
        cout << "Invalid input";
        cout << "\n\nEnter the meteor size in meters: ";
        cin >> sizeofmeteor;
    }

    cout << "\nEnter the meteor's distance from ISS in miles: ";
    cin >> distanceofmeteor;
    while (distanceofmeteor <= 0)
    {
        cout << "Invalid input";
        cout << "\n\nEnter the meteor's distance from ISS in miles: ";
        cin >> distanceofmeteor;
    }
}

void calculate_data(double sizeofmeteor, double distanceofmeteor, double& speed, double& timetoimpact)
{
    double temp_mpm;

    speed = sizeofmeteor * 120;
    temp_mpm = speed / 60;
    timetoimpact = distanceofmeteor / temp_mpm;
}

string get_status(double timetoimpact)
{
    if (timetoimpact <= 45) {
        return "Evacuation CANNOT BE COMPLETED";
    } else if (timetoimpact > 45 && timetoimpact <= 90) {
        return "Evacuation is POSSIBLE";
    } else {
        return "Evacuation is PROBABLE";
    }
}

void output_result(double sizeofmeteor, double distanceofmeteor, double speed, double timetoimpact, string status)
{
    cout << setprecision(2) << fixed;

    cout << "\nMeteor Data:" << endl;
    cout << "\tDiameter: " << sizeofmeteor << " meters" << endl;
    cout << "\tDistance from ISS: " << distanceofmeteor << " miles" << endl;
    cout << "\tSpeed in Miles per hour: " << speed << " mph" << endl;
    cout << "\tTime to Impact: " << timetoimpact << " Minutes" << endl << endl;
    cout << "Evacuation Status: ";

    if (timetoimpact <= 45) {
        SetConsoleTextAttribute(hConsole, 12);
    } else if (timetoimpact > 45 && timetoimpact <= 90) {
        SetConsoleTextAttribute(hConsole, 14);
    } else {
        SetConsoleTextAttribute(hConsole, 10);
    }

    cout << status << endl << endl << endl;

    SetConsoleTextAttribute(hConsole, 15);
}

#endif // S_CHORM_PROJECT3_H_INCLUDED
