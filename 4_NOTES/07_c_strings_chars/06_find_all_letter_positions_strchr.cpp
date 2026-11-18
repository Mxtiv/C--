// ======================================================================
// find all positions of a letter with a strchr loop
// Original file: unsorted/Cstrings/letterFinder.cpp
// ======================================================================

#include <iostream>
#include <cstring>
using namespace std;

void znajdzWystapienia(char tekst[], char litera)
{
    int ile = 0;
    cout << "Pozycje litery '" << litera << "' (od 1): ";

    char *wskaznik = strchr(tekst, litera);        // first occurrence or NULL
    while (wskaznik != NULL)
    {
        cout << wskaznik - tekst + 1 << " ";
        ile++;
        wskaznik = strchr(wskaznik + 1, litera);   // search again AFTER the found one
    }
    cout << endl;
    cout << "Liczba wystąpień litery '" << litera << "' w napisie: " << ile << endl;
}

int main()
{
    char wybor;
    do
    {
        char tekst[50];
        cout << "Podaj dane do analizy: ";
        cin.getline(tekst, 50);

        char litera;
        cout << "Podaj literę do znalezienia w napisie: ";
        cin >> litera;

        znajdzWystapienia(tekst, litera);

        cout << "Czy chcesz wyszukać ponownie? (T/N): ";
        cin >> wybor;
        cin.ignore();       // remove the Enter before the next cin.getline
    } while (wybor == 'T' || wybor == 't');

    return 0;
}
