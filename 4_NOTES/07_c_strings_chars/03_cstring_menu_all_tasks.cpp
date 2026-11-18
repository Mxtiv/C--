// ======================================================================
// switch menu: cin.getline into char[], strcat, strcmp, strstr + position (ptr - base), strcpy
// Original file: unsorted/Cstrings/cstringExcerciseExamples.cpp
// FIXED: option 6 cut off everything after the replaced fragment - now the rest is kept
// ======================================================================

#include <iostream>
#include <cstring>
using namespace std;

const int DLUGOSC = 100;

void informacjeOSamochodzie()
{
    char marka[DLUGOSC];
    char model[DLUGOSC];
    char rok[DLUGOSC];

    cout << "Enter the brand of the car: ";
    cin.getline(marka, DLUGOSC);
    cout << "Enter the model of the car: ";
    cin.getline(model, DLUGOSC);
    cout << "Enter the production year of the car: ";
    cin.getline(rok, DLUGOSC);

    cout << "Brand: " << marka << endl;
    cout << "Model: " << model << endl;
    cout << "Production Year: " << rok << endl;
}

void polaczNapisy()
{
    char napis1[3 * DLUGOSC];       // big enough for all three
    char napis2[DLUGOSC];
    char napis3[DLUGOSC];

    cout << "Enter first string: ";
    cin.getline(napis1, DLUGOSC);
    cout << "Enter second string: ";
    cin.getline(napis2, DLUGOSC);
    cout << "Enter third string: ";
    cin.getline(napis3, DLUGOSC);

    strcat(napis1, " ");
    strcat(napis1, napis2);
    strcat(napis1, " ");
    strcat(napis1, napis3);

    cout << "Concatenated string: " << napis1 << endl;
}

void porownajNapisy()
{
    char tekst1[DLUGOSC];
    char tekst2[DLUGOSC];

    cout << "Enter first string: ";
    cin.getline(tekst1, DLUGOSC);
    cout << "Enter second string: ";
    cin.getline(tekst2, DLUGOSC);

    if (strcmp(tekst1, tekst2) == 0)
    {
        cout << "The strings are identical" << endl;
    }
    else
    {
        cout << "The strings are different" << endl;
    }
}

void znajdzFragment()
{
    char szukany[DLUGOSC];
    char tekst[DLUGOSC];

    cout << "Enter substring to find: ";
    cin.getline(szukany, DLUGOSC);
    cout << "Enter string to search in: ";
    cin.getline(tekst, DLUGOSC);

    char *gdzie = strstr(tekst, szukany);     // pointer to the match or NULL
    if (gdzie == NULL)
    {
        cout << "\"" << szukany << "\" is not a substring of \"" << tekst << "\"" << endl;
    }
    else
    {
        // index = pointer to the match - pointer to the start
        cout << "\"" << szukany << "\" found at position " << gdzie - tekst << endl;
    }
}

void podajMiasto()
{
    char miasto[DLUGOSC];
    cout << "Enter the name of the city: ";
    cin.getline(miasto, DLUGOSC);
    cout << "City: " << miasto << endl;
}

void zamienFragment()
{
    char tekst[2 * DLUGOSC];
    char stary[DLUGOSC];
    char nowy[DLUGOSC];
    char reszta[2 * DLUGOSC];

    cout << "Enter the original string: ";
    cin.getline(tekst, DLUGOSC);
    cout << "Enter the substring to replace: ";
    cin.getline(stary, DLUGOSC);
    cout << "Enter the new substring: ";
    cin.getline(nowy, DLUGOSC);

    char *gdzie = strstr(tekst, stary);
    if (gdzie != NULL)
    {
        strcpy(reszta, gdzie + strlen(stary));   // 1) remember what is AFTER the old fragment
        strcpy(gdzie, nowy);                     // 2) write the new fragment over the old one
        strcat(tekst, reszta);                   // 3) add the remembered rest back
        cout << "Modified string: " << tekst << endl;
    }
    else
    {
        cout << "\"" << stary << "\" not found in the original string." << endl;
    }
}

int main()
{
    int wybor;
    do
    {
        cout << "\n*** MENU ***" << endl;
        cout << "1. Display car information" << endl;
        cout << "2. Concatenate strings and display result" << endl;
        cout << "3. Compare two strings for equality" << endl;
        cout << "4. Find substring in a string" << endl;
        cout << "5. Display the entered city name" << endl;
        cout << "6. Modify a string by replacing a substring" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> wybor;
        cin.ignore();           // remove the Enter before cin.getline

        switch (wybor)
        {
        case 1:
            informacjeOSamochodzie();
            break;
        case 2:
            polaczNapisy();
            break;
        case 3:
            porownajNapisy();
            break;
        case 4:
            znajdzFragment();
            break;
        case 5:
            podajMiasto();
            break;
        case 6:
            zamienFragment();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number from the menu." << endl;
            break;
        }
    } while (wybor != 0);

    return 0;
}
