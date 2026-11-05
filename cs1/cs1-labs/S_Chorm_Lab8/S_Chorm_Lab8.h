#ifndef S_CHORM_LAB8_H_INCLUDED
#define S_CHORM_LAB8_H_INCLUDED

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void get_input(string& word)
{
    cout << "Enter a word or phrase for inspection: ";
    getline(cin, word);
}

void inspect_input(string word)
{
    int words = 0, digits = 0, upperLetters = 0, lowerLetters = 0, spaces = 0, other = 0;

    for (int i = 0; i < word.length(); i++)
    {
        if (isdigit(word[i]))
        {
            digits++;
        }
        else if (isupper(word[i]))
        {
            upperLetters++;
        }
        else if (islower(word[i]))
        {
            lowerLetters++;
        }
        else if (isspace(word[i]))
        {
            spaces++;
        }
        else
        {
            other++;
        }
    }

    if (word.length() > 0)
    {
        words = (spaces + 1);
        cout << "\tThe phrase content is:\n\n";
        cout << "\t\t" << words << " Word(s)." << endl;
    }
    else
    {
        cout << "\tThe word content is:\n\n";
    }

    cout << "\t\t" << digits << " Digit(s)." << endl
         << "\t\t" << upperLetters << " Upper case letter(s)." << endl
         << "\t\t" << lowerLetters << " Lower case letter(s)." << endl
         << "\t\t" << spaces << " Space(s)." << endl
         << "\t\t" << other << " Other character(s)." << endl;
}

#endif // S_CHORM_LAB8_H_INCLUDED
