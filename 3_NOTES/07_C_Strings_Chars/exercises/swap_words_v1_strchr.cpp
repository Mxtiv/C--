// ======================================================================
// swap the first words of two 2-word phrases (strchr + strncpy + strcat)
// Original file: unsorted/Cstrings/cstringSwap.cpp
// FIXED - the bug was: strcpy into overlapping parts of the same arrays printed garbage;
//         now each result is built in its own array (same result as swap_words_v4_strtok.cpp)
// ======================================================================

#include <iostream>
#include <cstring>
using namespace std;

const int DLUGOSC = 100;

int main()
{
    char pierwszy[DLUGOSC];
    char drugi[DLUGOSC];

    cout << "Podaj pierwszy dwuczłonowy napis: ";
    cin.getline(pierwszy, DLUGOSC);
    cout << "Podaj drugi dwuczłonowy napis: ";
    cin.getline(drugi, DLUGOSC);

    // strchr - pointer to the space in each phrase
    char *spacja1 = strchr(pierwszy, ' ');
    char *spacja2 = strchr(drugi, ' ');
    if (spacja1 == NULL || spacja2 == NULL)
    {
        cout << "Oba napisy muszą mieć spację." << endl;
        return 0;
    }

    char wynik1[2 * DLUGOSC];
    char wynik2[2 * DLUGOSC];

    // wynik1 = first word of drugi + " ogon" of pierwszy
    strncpy(wynik1, drugi, spacja2 - drugi);
    wynik1[spacja2 - drugi] = '\0';
    strcat(wynik1, spacja1);

    // wynik2 = first word of pierwszy + " ogon" of drugi
    strncpy(wynik2, pierwszy, spacja1 - pierwszy);
    wynik2[spacja1 - pierwszy] = '\0';
    strcat(wynik2, spacja2);

    cout << "Mixed 1: " << wynik1 << endl;
    cout << "Mixed 2: " << wynik2 << endl;
    return 0;
}
