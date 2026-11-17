// ======================================================================
// count a letter by looping until '\0'; strchr version
// Original file: unsorted/Cstrings/nikodemst/3) Szukanie literki w imieniu/main.cpp
// FIXED - the bug was: literkaWnapisie2 returns the index of the first occurrence (not a count) and crashes when the letter is missing
// ======================================================================

#include <iostream>
#include <cstring>
using namespace std;
int literkaWnapisie(char napis[30], char literka)
{
    int licznik = 0;
    for (short i = 0; napis[i] != '\0'; i++)
    {
        if (napis[i] == literka)
        {
            licznik++;
            cout << i << ", ";
        }
    }
    return licznik;
}
int literkaWnapisie2(char napis[30], char literka)
{
    int licznik = 0;
    for (char *p = strchr(napis, literka); p != nullptr; p = strchr(p + 1, literka))
        licznik++;
    return licznik;
}
int main()
{
    char tablicaZnakow[30], literka;

    cout << "podej imie i nazwisko" << endl;
    cin.get(tablicaZnakow, 30);
    cin.ignore(50, '\n');
    cout << "podej literke";
    cin >> literka;
    cout << "pozycje: ";
    int ile = literkaWnapisie(tablicaZnakow, literka);
    cout << endl << "liczba wystapien: " << ile << " (strchr: " << literkaWnapisie2(tablicaZnakow, literka) << ")" << endl;
    return 0;
}