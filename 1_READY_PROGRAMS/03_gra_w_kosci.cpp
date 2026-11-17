// ======================================================================
// READY PROGRAM 03: dice game (gra w kości) - roll 3..10 dice, points = sum of the
// values that appeared at least twice, "play again? (t/n)"
// Original file: inf04/2)Kostki.cpp
// Blocks used: IO-01, IO-04, RND-02, ARR-19 (histogram idea)
// ======================================================================
//
// Treść zadania: Gracz podaje liczbę kostek (od 3 do 10). Program losuje wartości
// kostek (1..6), wyświetla je w postaci "Kostka <nr>: <wartość>", a następnie
// oblicza punkty: sumę oczek tych kostek, których wartość wystąpiła co najmniej
// dwa razy. Po rzucie program pyta, czy grać dalej (t/n).
// Przykład: 1 2 2 5 5 5 -> 2+2 + 5+5+5 = 19 punktów.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

/********************************************************
 * nazwa funkcji: rzucKostkami
 * opis funkcji: wypełnia tablicę wynikami rzutu kostkami (liczby pseudolosowe 1..6)
 * parametry: kostki - tablica wyników
 *            n - liczba kostek
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void rzucKostkami(int kostki[], int n)
{
    for (int i = 0; i < n; i++)
        kostki[i] = rand() % 6 + 1;
}

/********************************************************
 * nazwa funkcji: wyswietlKostki
 * opis funkcji: wyświetla wyniki rzutu w postaci "Kostka <nr>: <wartość>"
 * parametry: kostki - tablica wyników
 *            n - liczba kostek
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void wyswietlKostki(const int kostki[], int n)
{
    for (int i = 0; i < n; i++)
        cout << "Kostka " << i + 1 << ": " << kostki[i] << endl;
}

/********************************************************
 * nazwa funkcji: policzPunkty
 * opis funkcji: oblicza punkty - sumę oczek kostek, których wartość wystąpiła
 *               co najmniej dwa razy (zlicza wystąpienia każdej wartości 1..6)
 * parametry: kostki - tablica wyników
 *            n - liczba kostek
 * zwracany typ i opis: int - liczba punktów
 * autor: <numer zdającego>
 ********************************************************/
int policzPunkty(const int kostki[], int n)
{
    int ile[7] = {0};                  // ile[w] = how many dice show w (index 0 unused)
    for (int i = 0; i < n; i++)
        ile[kostki[i]]++;

    int punkty = 0;
    for (int w = 1; w <= 6; w++)
        if (ile[w] >= 2)
            punkty += ile[w] * w;
    return punkty;
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
    const int MAX_KOSTEK = 10;
    int kostki[MAX_KOSTEK];

    do
    {
        int n = wczytajLiczbe("\nIloma kostkami chcesz rzucic? (3-10): ", 3, 10);
        rzucKostkami(kostki, n);
        wyswietlKostki(kostki, n);
        cout << "Liczba uzyskanych punktow: " << policzPunkty(kostki, n) << endl;
    } while (zapytajTakNie("Jeszcze raz? (t/n): "));

    cout << "Koniec gry." << endl;
    return 0;
}
