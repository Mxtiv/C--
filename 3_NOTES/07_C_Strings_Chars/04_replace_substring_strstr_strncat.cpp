// ======================================================================
// replace a substring using strstr + strncat (build the result in a new array);
// repeat with do-while
// Original file: unsorted/Cstrings/cstringAppend.cpp
// ======================================================================

#include <iostream>
#include <cstring>
using namespace std;

const int DLUGOSC = 100;

void wczytajNapisy(char tekst[], char stary[], char nowy[])
{
    cout << "Enter the initial string: ";
    cin.getline(tekst, DLUGOSC);
    cout << "Enter the string to replace: ";
    cin.getline(stary, DLUGOSC);
    cout << "Enter the new string: ";
    cin.getline(nowy, DLUGOSC);
}

void zamienFragment(char tekst[], char stary[], char nowy[])
{
    char *gdzie = strstr(tekst, stary);     // where the old fragment starts (or NULL)
    if (gdzie == NULL)
    {
        cout << "String to replace not found in the initial string." << endl;
        return;
    }

    char wynik[3 * DLUGOSC];
    wynik[0] = '\0';                        // start with an empty C-string

    int ileZnakowPrzed = gdzie - tekst;
    strncat(wynik, tekst, ileZnakowPrzed);  // 1) part BEFORE the old fragment (strncat = at most n chars)
    strcat(wynik, nowy);                    // 2) the new fragment
    strcat(wynik, gdzie + strlen(stary));   // 3) part AFTER the old fragment

    cout << "Modified string: " << wynik << endl;
}

int main()
{
    char tekst[DLUGOSC];
    char stary[DLUGOSC];
    char nowy[DLUGOSC];
    char wybor;

    do
    {
        wczytajNapisy(tekst, stary, nowy);
        zamienFragment(tekst, stary, nowy);

        cout << "Do you want to run the code again? (Y/N): ";
        cin >> wybor;
        cin.ignore();       // remove the Enter before the next cin.getline
    } while (wybor == 'Y' || wybor == 'y');

    cout << "Goodbye!" << endl;
    return 0;
}
