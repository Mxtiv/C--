// ======================================================================
// insert a middle name: strchr, strncpy, strcat
// Original file: unsorted/Cstrings/cstringImieNazwisko.cpp
// ======================================================================

#include <iostream>
#include <cstring>
using namespace std;

const int DLUGOSC = 100;

void wstawDrugieImie(char imieNazwisko[], char drugieImie[])
{
    // strchr - pointer to the first space (after the first name), or NULL
    char *spacja = strchr(imieNazwisko, ' ');
    if (spacja == NULL)
    {
        cout << "Invalid format. Enter first name and last name separated by space." << endl;
        return;
    }

    char wynik[2 * DLUGOSC + 2];
    int dlugoscImienia = spacja - imieNazwisko;

    strncpy(wynik, imieNazwisko, dlugoscImienia);   // copy only the first name
    wynik[dlugoscImienia] = '\0';                   // strncpy does not add '\0' here - add it yourself

    strcat(wynik, " ");
    strcat(wynik, drugieImie);
    strcat(wynik, spacja);                          // " Nazwisko" (starts with the space)

    cout << "Full name with middle name: " << wynik << endl;
}

int main()
{
    char imieNazwisko[DLUGOSC];
    char drugieImie[DLUGOSC];

    cout << "Enter first name and last name (e.g. 'Mariusz Pudzianowski'): ";
    cin.getline(imieNazwisko, DLUGOSC);
    cout << "Enter middle name: ";
    cin.getline(drugieImie, DLUGOSC);

    wstawDrugieImie(imieNazwisko, drugieImie);

    return 0;
}
