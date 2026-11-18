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
    if (wielkie)
    {
        znaki = znaki + "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
    if (cyfry)
    {
        znaki = znaki + "0123456789";
    }
    if (specjalne)
    {
        znaki = znaki + "!@#$%^&*()_+-=";
    }

    int ileZnakow = znaki.length();
    string haslo = "";
    for (int i = 0; i < dlugosc; i++)
    {
        haslo = haslo + znaki[rand() % ileZnakow];
    }
    return haslo;
}

/********************************************************
 * nazwa funkcji: zapytajTakNie
 * opis funkcji: zadaje pytanie tak długo, aż użytkownik odpowie t albo n
 * parametry: pytanie - tekst pytania
 * zwracany typ i opis: bool - true dla 't', false dla 'n'
 * autor: <numer zdającego>
 ********************************************************/
bool zapytajTakNie(string pytanie)
{
    char odpowiedz;
    do
    {
        cout << pytanie;
        cin >> odpowiedz;
    } while (odpowiedz != 't' && odpowiedz != 'n');

    if (odpowiedz == 't')
    {
        return true;
    }
    return false;
}

int main()
{
    srand(time(0));

    int dlugosc;
    do
    {
        cout << "Dlugosc hasla (4-32): ";
        cin >> dlugosc;
    } while (dlugosc < 4 || dlugosc > 32);

    bool wielkie = zapytajTakNie("Wielkie litery? (t/n): ");
    bool cyfry = zapytajTakNie("Cyfry? (t/n): ");
    bool specjalne = zapytajTakNie("Znaki specjalne? (t/n): ");

    int ile;
    do
    {
        cout << "Ile hasel wygenerowac? (1-10): ";
        cin >> ile;
    } while (ile < 1 || ile > 10);

    for (int i = 1; i <= ile; i++)
    {
        cout << "Haslo " << i << ": " << generujHaslo(dlugosc, wielkie, cyfry, specjalne) << endl;
    }
    return 0;
}
