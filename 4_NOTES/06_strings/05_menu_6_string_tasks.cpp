// ======================================================================
// switch menu with 6 std::string tasks; string& to read several values, by value to print;
// cin.ignore() before getline
// Original file: unsorted/stringi/stringZadania.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

// & - the function fills THREE variables of the caller
void wczytajSamochod(string &marka, string &model, string &rok)
{
    cout << "Enter the brand of the car: ";
    getline(cin, marka);
    cout << "Enter the model of the car: ";
    getline(cin, model);
    cout << "Enter the year of production of the car: ";
    getline(cin, rok);
}

// by value - the function only reads them
void wypiszSamochod(string marka, string model, string rok)
{
    cout << "\nCar Details:\n";
    cout << "Brand: " << marka << endl;
    cout << "Model: " << model << endl;
    cout << "Year of Production: " << rok << endl;
}

void wczytajTrzySlowa(string &slowo1, string &slowo2, string &slowo3)
{
    cout << "Enter first word: ";
    getline(cin, slowo1);
    cout << "Enter second word: ";
    getline(cin, slowo2);
    cout << "Enter third word: ";
    getline(cin, slowo3);
}

bool czyRowne(string tekst1, string tekst2)
{
    return tekst1 == tekst2;
}

void pozycjaFragmentu(string fragment, string tekst)
{
    if (tekst.find(fragment) != string::npos)
    {
        cout << fragment << " is a substring of " << tekst
             << " starting at position " << tekst.find(fragment) << endl;
    }
    else
    {
        cout << fragment << " is not a substring of " << tekst << endl;
    }
}

void skopiujDrugiDoPierwszego(string &tekst1, string tekst2)
{
    tekst1 = tekst2;
}

int main()
{
    int wybor;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Input Car Details and Print\n";
        cout << "2. Input Three Words and Print\n";
        cout << "3. Compare Strings\n";
        cout << "4. Find Substring Position\n";
        cout << "5. Input Full Place Name\n";
        cout << "6. Copy Second to First\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> wybor;
        cin.ignore();       // remove the Enter left after cin >> (before getline!)

        string tekst1;
        string tekst2;
        string tekst3;
        switch (wybor)
        {
        case 1:
            wczytajSamochod(tekst1, tekst2, tekst3);
            wypiszSamochod(tekst1, tekst2, tekst3);
            break;
        case 2:
            wczytajTrzySlowa(tekst1, tekst2, tekst3);
            cout << tekst1 << " " << tekst2 << " " << tekst3 << endl;
            break;
        case 3:
            cout << "Enter first string: ";
            getline(cin, tekst1);
            cout << "Enter second string: ";
            getline(cin, tekst2);
            if (czyRowne(tekst1, tekst2))
            {
                cout << "Strings are equal" << endl;
            }
            else
            {
                cout << "Strings are not equal" << endl;
            }
            break;
        case 4:
            cout << "Enter substring: ";
            getline(cin, tekst1);
            cout << "Enter string to search in: ";
            getline(cin, tekst2);
            pozycjaFragmentu(tekst1, tekst2);
            break;
        case 5:
            cout << "Enter full name of the place: ";
            getline(cin, tekst1);
            cout << tekst1 << endl;
            break;
        case 6:
            cout << "Enter first string: ";
            getline(cin, tekst1);
            cout << "Enter second string: ";
            getline(cin, tekst2);
            skopiujDrugiDoPierwszego(tekst1, tekst2);
            cout << "First string after copying: " << tekst1 << endl;
            break;
        case 7:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 7.\n";
            break;
        }
    } while (wybor != 7);

    return 0;
}
