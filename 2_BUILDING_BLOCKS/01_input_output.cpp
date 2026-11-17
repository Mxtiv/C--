// ======================================================================
// BUILDING BLOCKS: input / output (wczytywanie i wypisywanie)
// HOW TO USE: copy the comment box + code under a //@ line, up to the next //@ line.
// The //@ line itself tells you: ID | what it does | which #include it needs.
// The DEMO main() at the bottom is only a test - don't copy it.
// ======================================================================

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

//@ IO-01 | read an int from a range, ask again until the input is valid (letters too) | <iostream> <string> <limits>
/********************************************************
 * nazwa funkcji: wczytajLiczbe
 * opis funkcji: wyświetla komunikat i wczytuje liczbę całkowitą z zakresu min..max;
 *               pyta ponownie, dopóki użytkownik nie poda poprawnej wartości
 * parametry: komunikat - tekst wyświetlany użytkownikowi
 *            min - najmniejsza dopuszczalna wartość
 *            max - największa dopuszczalna wartość
 * zwracany typ i opis: int - poprawna liczba podana przez użytkownika
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
        cout << "Niepoprawna wartosc. Podaj liczbe od " << min << " do " << max << "." << endl;
        cin.clear();                                            // reset the error (e.g. after letters)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');   // throw away the rest of the line
    }
}

//@ IO-02 | read a real number (double), ask again on wrong input | <iostream> <string> <limits>
/********************************************************
 * nazwa funkcji: wczytajLiczbeRzeczywista
 * opis funkcji: wyświetla komunikat i wczytuje liczbę rzeczywistą; pyta ponownie przy błędzie
 * parametry: komunikat - tekst wyświetlany użytkownikowi
 * zwracany typ i opis: double - liczba podana przez użytkownika
 * autor: <numer zdającego>
 ********************************************************/
double wczytajLiczbeRzeczywista(const string &komunikat)
{
    double liczba;
    cout << komunikat;
    while (!(cin >> liczba))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "To nie jest liczba. " << komunikat;
    }
    return liczba;
}

//@ IO-03 | read a whole line of text (with spaces), safe after a previous cin >> | <iostream> <string>
/********************************************************
 * nazwa funkcji: wczytajTekst
 * opis funkcji: wyświetla komunikat i wczytuje cały wiersz tekstu (razem ze spacjami)
 * parametry: komunikat - tekst wyświetlany użytkownikowi
 * zwracany typ i opis: string - wczytany tekst
 * autor: <numer zdającego>
 ********************************************************/
string wczytajTekst(const string &komunikat)
{
    string tekst;
    cout << komunikat;
    getline(cin >> ws, tekst);   // ws skips the '\n' left by an earlier cin >> (and leading spaces)
    return tekst;
}

//@ IO-04 | yes/no question (t/n) -> bool; use as: do { ... } while (zapytajTakNie("Jeszcze raz? (t/n): ")); | <iostream> <string>
/********************************************************
 * nazwa funkcji: zapytajTakNie
 * opis funkcji: zadaje pytanie i czeka na odpowiedź t/n (wielkość liter nie ma znaczenia)
 * parametry: pytanie - tekst pytania
 * zwracany typ i opis: bool - true dla odpowiedzi 't', false dla 'n'
 * autor: <numer zdającego>
 ********************************************************/
bool zapytajTakNie(const string &pytanie)
{
    char odp;
    while (true)
    {
        cout << pytanie;
        if (!(cin >> odp)) return false;      // end of input -> treat as "no"
        if (odp == 't' || odp == 'T') return true;
        if (odp == 'n' || odp == 'N') return false;
        cout << "Wpisz t lub n." << endl;
    }
}

//@ IO-05 | menu loop: do-while + switch, ends on 0 (put your function calls in the cases) | <iostream>
/********************************************************
 * nazwa funkcji: menu
 * opis funkcji: wyświetla menu i wykonuje wybraną opcję, dopóki użytkownik nie wybierze 0
 * parametry: brak
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void menu()
{
    int wybor;
    do
    {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Opcja pierwsza" << endl;
        cout << "2. Opcja druga" << endl;
        cout << "0. Koniec" << endl;
        cout << "Wybierz: ";
        if (!(cin >> wybor)) wybor = 0;       // end of input / letters -> exit

        switch (wybor)
        {
        case 1:
            cout << "Wybrano opcje 1" << endl;   // <- call your function here
            break;
        case 2:
            cout << "Wybrano opcje 2" << endl;
            break;
        case 0:
            cout << "Koniec programu." << endl;
            break;
        default:
            cout << "Nie ma takiej opcji." << endl;
        }
    } while (wybor != 0);
}

//@ IO-06 | print one aligned "label   value" row with 2 decimal places (tables of results) | <iostream> <iomanip> <string>
/********************************************************
 * nazwa funkcji: wypiszWiersz
 * opis funkcji: wypisuje etykietę i wartość w równych kolumnach, z dwoma miejscami po przecinku
 * parametry: etykieta - opis wartości
 *            wartosc - liczba do wypisania
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void wypiszWiersz(const string &etykieta, double wartosc)
{
    cout << left << setw(22) << etykieta
         << right << setw(12) << fixed << setprecision(2) << wartosc << endl;
    cout.unsetf(ios::fixed);                 // restore default number formatting
    cout << setprecision(6);
}

//@ IO-07 | print a separator line, e.g. ---------- | <iostream>
/********************************************************
 * nazwa funkcji: wypiszLinie
 * opis funkcji: wypisuje linię złożoną z podanego znaku
 * parametry: znak - znak, z którego składa się linia
 *            dlugosc - liczba znaków
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void wypiszLinie(char znak = '-', int dlugosc = 40)
{
    for (int i = 0; i < dlugosc; i++) cout << znak;
    cout << endl;
}

// ====================== DEMO (don't copy) ======================
int main()
{
    int wiek = wczytajLiczbe("Podaj wiek (0-120): ", 0, 120);
    double wzrost = wczytajLiczbeRzeczywista("Podaj wzrost w m: ");
    string imie = wczytajTekst("Podaj imie i nazwisko: ");
    wypiszLinie('=');
    cout << imie << ", wiek " << wiek << endl;
    wypiszWiersz("Wzrost [m]:", wzrost);
    wypiszWiersz("Wiek za 10 lat:", wiek + 10);
    wypiszLinie();
    if (zapytajTakNie("Pokazac menu? (t/n): "))
        menu();
    return 0;
}
