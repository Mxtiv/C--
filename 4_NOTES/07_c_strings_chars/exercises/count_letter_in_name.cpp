// ======================================================================
// count a letter by looping until '\0'; strchr version
// Original file: unsorted/Cstrings/nikodemst/3) Szukanie literki w imieniu/main.cpp
// FIXED - the bug was: literkaWnapisie2 returns the index of the first occurrence (not a count) and crashes when the letter is missing
// ======================================================================

#include <iostream>
#include <cstring>
using namespace std;

// Version 1: walk the char array until the '\0' terminator
int literkaWnapisie(char napis[], char literka)
{
    int licznik = 0;
    for (int i = 0; napis[i] != '\0'; i++)
    {
        if (napis[i] == literka)
        {
            licznik++;
            cout << i << ", ";
        }
    }
    return licznik;
}

// Version 2: jump from one match to the next with strchr
int literkaWnapisie2(char napis[], char literka)
{
    int licznik = 0;
    char *p = strchr(napis, literka);
    while (p != NULL)
    {
        licznik++;
        p = strchr(p + 1, literka);
    }
    return licznik;
}

int main()
{
    char napis[30];
    char literka;

    cout << "podaj imie i nazwisko: ";
    cin.get(napis, 30);
    cin.ignore(50, '\n');
    cout << "podaj literke: ";
    cin >> literka;

    cout << "pozycje: ";
    int ile = literkaWnapisie(napis, literka);
    cout << endl << "liczba wystapien: " << ile << " (strchr: " << literkaWnapisie2(napis, literka) << ")" << endl;
    return 0;
}
