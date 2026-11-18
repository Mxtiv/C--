// ======================================================================
// READY PROGRAM 16: password generator - length + options (uppercase, digits,
// special characters), generates several passwords
// (new - console version of the INF.04 desktop "generator hasel" logic)
// Blocks used: RND-07, IO-01, IO-04
// ======================================================================
//
// Treść zadania (wariant): Program pyta o długość hasła (4..32), o to, czy hasło ma
// zawierać wielkie litery, cyfry i znaki specjalne (małe litery są zawsze), oraz ile
// haseł wygenerować. Następnie wyświetla wygenerowane hasła.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

/********************************************************
 * nazwa funkcji: generujHaslo
 * opis funkcji: generuje hasło o podanej długości z małych liter oraz wybranych grup
 *               znaków; każdy znak losowany jest z puli dozwolonych znaków
 * parametry: dlugosc - liczba znaków hasła
 *            wielkie - czy dodać wielkie litery
 *            cyfry - czy dodać cyfry
 *            specjalne - czy dodać znaki specjalne
 * zwracany typ i opis: string - wygenerowane hasło
 * autor: <numer zdającego>
 ********************************************************/
string generujHaslo(int dlugosc, bool wielkie, bool cyfry, bool specjalne)
{
    string znaki = "abcdefghijklmnopqrstuvwxyz";
    if (wielkie)   znaki += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (cyfry)     znaki += "0123456789";
    if (specjalne) znaki += "!@#$%^&*()_+-=";

    string haslo;
    for (int i = 0; i < dlugosc; i++)
        haslo += znaki[rand() % znaki.length()];
    return haslo;
}

/********************************************************
 * nazwa funkcji: wczytajLiczbe
 * opis funkcji: wczytuje liczbę całkowitą z zakresu min..max, ponawiając pytanie przy błędzie
 * parametry: komunikat - tekst wyświetlany użytkownikowi
 *            min - najmniejsza dopuszczalna wartość
 *            max - największa dopuszczalna wartość
 * zwracany typ i opis: int - poprawna liczba
 * autor: <numer zdającego>
 ********************************************************/
int wczytajLiczbe(const string &komunikat, int min, int max)
{
    int liczba;
    while (true)
    {
        cout << komunikat;
        if (cin >> liczba && liczba >= min && liczba <= max)
            return liczba;
        cout << "Podaj liczbe od " << min << " do " << max << "." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

/********************************************************
 * nazwa funkcji: zapytajTakNie
 * opis funkcji: zadaje pytanie i czeka na odpowiedź t lub n
 * parametry: pytanie - tekst pytania
 * zwracany typ i opis: bool - true dla 't', false dla 'n'
 * autor: <numer zdającego>
 ********************************************************/
bool zapytajTakNie(const string &pytanie)
{
    char odp;
    while (true)
    {
        cout << pytanie;
        if (!(cin >> odp)) return false;
        if (odp == 't' || odp == 'T') return true;
        if (odp == 'n' || odp == 'N') return false;
    }
}

int main()
{
    srand(time(0));
    int dlugosc = wczytajLiczbe("Dlugosc hasla (4-32): ", 4, 32);
    bool wielkie = zapytajTakNie("Wielkie litery? (t/n): ");
    bool cyfry = zapytajTakNie("Cyfry? (t/n): ");
    bool specjalne = zapytajTakNie("Znaki specjalne? (t/n): ");
    int ile = wczytajLiczbe("Ile hasel wygenerowac? (1-10): ", 1, 10);

    for (int i = 1; i <= ile; i++)
        cout << "Haslo " << i << ": " << generujHaslo(dlugosc, wielkie, cyfry, specjalne) << endl;
    return 0;
}
