// ======================================================================
// BUILDING BLOCKS: input / output (wczytywanie i wypisywanie)
// HOW TO USE: copy the comment box + code under a //@ line, up to the next //@ line.
// The //@ line itself tells you: ID | what it does | which #include it needs.
// The DEMO main() at the bottom is only a test - don't copy it.
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

//@ IO-01 | read an int from a range min..max, ask again until it fits (do-while) | <iostream> <string>
/********************************************************
 * nazwa funkcji: wczytajLiczbe
 * opis funkcji: wyświetla komunikat i wczytuje liczbę całkowitą z zakresu min..max;
 *               pyta ponownie, dopóki liczba nie mieści się w zakresie
 * parametry: komunikat - tekst wyświetlany użytkownikowi
 *            min - najmniejsza dopuszczalna wartość
 *            max - największa dopuszczalna wartość
 * zwracany typ i opis: int - poprawna liczba podana przez użytkownika
 * autor: <numer zdającego>
 ********************************************************/
int wczytajLiczbe(string komunikat, int min, int max)
{
    int liczba;
    do
    {
        cout << komunikat;
        cin >> liczba;
    } while (liczba < min || liczba > max);
    return liczba;
}

//@ IO-02 | read a real number (double) from a range min..max, ask again until it fits | <iostream> <string>
/********************************************************
 * nazwa funkcji: wczytajLiczbeRzeczywista
 * opis funkcji: wyświetla komunikat i wczytuje liczbę rzeczywistą z zakresu min..max;
 *               pyta ponownie, dopóki liczba nie mieści się w zakresie
 * parametry: komunikat - tekst wyświetlany użytkownikowi
 *            min - najmniejsza dopuszczalna wartość
 *            max - największa dopuszczalna wartość
 * zwracany typ i opis: double - liczba podana przez użytkownika
 * autor: <numer zdającego>
 ********************************************************/
double wczytajLiczbeRzeczywista(string komunikat, double min, double max)
{
    double liczba;
    do
    {
        cout << komunikat;
        cin >> liczba;
    } while (liczba < min || liczba > max);
    return liczba;
}

//@ IO-03 | read a whole line of text (with spaces) - after an earlier cin >> call cin.ignore(); first | <iostream> <string>
/********************************************************
 * nazwa funkcji: wczytajTekst
 * opis funkcji: wyświetla komunikat i wczytuje cały wiersz tekstu (razem ze spacjami)
 * parametry: komunikat - tekst wyświetlany użytkownikowi
 * zwracany typ i opis: string - wczytany tekst
 * autor: <numer zdającego>
 ********************************************************/
string wczytajTekst(string komunikat)
{
    string tekst;
    cout << komunikat;
    getline(cin, tekst);    // if there was a cin >> before: write cin.ignore(); before calling this
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
bool zapytajTakNie(string pytanie)
{
    char odp;
    do
    {
        cout << pytanie;
        cin >> odp;
    } while (odp != 't' && odp != 'T' && odp != 'n' && odp != 'N');

    if (odp == 't' || odp == 'T')
    {
        return true;
    }
    return false;
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
        cin >> wybor;

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

//@ IO-07 | print a separator line, e.g. ---------- | <iostream>
/********************************************************
 * nazwa funkcji: wypiszLinie
 * opis funkcji: wypisuje linię złożoną z podanego znaku
 * parametry: znak - znak, z którego składa się linia
 *            dlugosc - liczba znaków
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void wypiszLinie(char znak, int dlugosc)
{
    for (int i = 0; i < dlugosc; i++)
    {
        cout << znak;
    }
    cout << endl;
}

// ====================== DEMO (don't copy) ======================
int main()
{
    int wiek = wczytajLiczbe("Podaj wiek (0-120): ", 0, 120);
    double wzrost = wczytajLiczbeRzeczywista("Podaj wzrost w m (0.5-2.5): ", 0.5, 2.5);
    cin.ignore();                                   // remove the Enter left by cin >>
    string imie = wczytajTekst("Podaj imie i nazwisko: ");
    wypiszLinie('=', 40);
    cout << imie << ", wiek " << wiek << ", wzrost " << wzrost << " m" << endl;
    wypiszLinie('-', 40);
    if (zapytajTakNie("Pokazac menu? (t/n): "))
    {
        menu();
    }
    return 0;
}
