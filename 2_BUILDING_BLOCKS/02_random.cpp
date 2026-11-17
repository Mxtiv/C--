// ======================================================================
// BUILDING BLOCKS: random numbers (liczby losowe)
// HOW TO USE: copy the comment box + code under a //@ line, up to the next //@ line.
// REMEMBER: srand(time(0)); ONCE at the start of main (never inside a loop or a function).
// ======================================================================

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
using namespace std;

//@ RND-01 | random int from min..max inclusive (rand) - needs srand(time(0)) once in main | <cstdlib> <ctime>
/********************************************************
 * nazwa funkcji: losujLiczbe
 * opis funkcji: losuje liczbę całkowitą z przedziału min..max (włącznie)
 * parametry: min - dolna granica przedziału
 *            max - górna granica przedziału
 * zwracany typ i opis: int - wylosowana liczba
 * autor: <numer zdającego>
 ********************************************************/
int losujLiczbe(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

//@ RND-02 | fill an array with random ints min..max (e.g. dice 1..6) | <cstdlib> <ctime>
/********************************************************
 * nazwa funkcji: wypelnijLosowo
 * opis funkcji: wypełnia tablicę liczbami pseudolosowymi z przedziału min..max
 * parametry: tab - tablica do wypełnienia
 *            n - liczba elementów tablicy
 *            min - najmniejsza losowana wartość
 *            max - największa losowana wartość
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void wypelnijLosowo(int tab[], int n, int min, int max)
{
    for (int i = 0; i < n; i++)
        tab[i] = rand() % (max - min + 1) + min;
}

//@ RND-03 | fill an array with random ints WITHOUT repeats (lotto: 6 of 1..49) | <cstdlib> <ctime>
/********************************************************
 * nazwa funkcji: losujBezPowtorzen
 * opis funkcji: wypełnia tablicę różnymi liczbami losowymi z przedziału min..max
 *               (przedział musi mieć co najmniej n liczb)
 * parametry: tab - tablica do wypełnienia
 *            n - liczba elementów do wylosowania
 *            min - dolna granica przedziału
 *            max - górna granica przedziału
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void losujBezPowtorzen(int tab[], int n, int min, int max)
{
    for (int i = 0; i < n; i++)
    {
        bool powtorka;
        do
        {
            tab[i] = rand() % (max - min + 1) + min;
            powtorka = false;
            for (int j = 0; j < i; j++)
                if (tab[j] == tab[i]) { powtorka = true; break; }
        } while (powtorka);
    }
}

//@ RND-04 | shuffle an array randomly (Fisher-Yates) | <cstdlib> <ctime> <algorithm>
/********************************************************
 * nazwa funkcji: tasujTablice
 * opis funkcji: losowo przestawia elementy tablicy (algorytm Fishera-Yatesa)
 * parametry: tab - tablica do potasowania
 *            n - liczba elementów tablicy
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void tasujTablice(int tab[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(tab[i], tab[j]);
    }
}

//@ RND-05 | random real number from min..max | <cstdlib> <ctime>
/********************************************************
 * nazwa funkcji: losujRzeczywista
 * opis funkcji: losuje liczbę rzeczywistą z przedziału min..max
 * parametry: min - dolna granica
 *            max - górna granica
 * zwracany typ i opis: double - wylosowana liczba
 * autor: <numer zdającego>
 ********************************************************/
double losujRzeczywista(double min, double max)
{
    return min + (max - min) * rand() / RAND_MAX;
}

//@ RND-06 | random character from a given set of characters | <cstdlib> <string>
/********************************************************
 * nazwa funkcji: losujZnak
 * opis funkcji: losuje jeden znak z podanego zbioru znaków
 * parametry: znaki - napis zawierający dozwolone znaki
 * zwracany typ i opis: char - wylosowany znak
 * autor: <numer zdającego>
 ********************************************************/
char losujZnak(const string &znaki)
{
    return znaki[rand() % znaki.length()];
}

//@ RND-07 | password generator: length + options (uppercase, digits, special chars) | <cstdlib> <string>
/********************************************************
 * nazwa funkcji: generujHaslo
 * opis funkcji: generuje hasło o podanej długości z małych liter oraz wybranych
 *               grup znaków (wielkie litery, cyfry, znaki specjalne)
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

//@ RND-08 | modern random int (mt19937) - better quality, no srand needed | <random>
/********************************************************
 * nazwa funkcji: losujNowoczesnie
 * opis funkcji: losuje liczbę całkowitą z przedziału min..max generatorem mt19937
 * parametry: min - dolna granica
 *            max - górna granica
 * zwracany typ i opis: int - wylosowana liczba
 * autor: <numer zdającego>
 ********************************************************/
int losujNowoczesnie(int min, int max)
{
    static mt19937 generator(random_device{}());     // created once, reused
    uniform_int_distribution<int> rozklad(min, max);
    return rozklad(generator);
}

// ====================== DEMO (don't copy) ======================
int main()
{
    srand(time(0));
    const int N = 10;
    int tab[N];

    cout << "kostka: " << losujLiczbe(1, 6) << ", rzeczywista: " << losujRzeczywista(0, 1)
         << ", znak: " << losujZnak("ABC") << ", mt19937: " << losujNowoczesnie(1, 100) << endl;

    wypelnijLosowo(tab, N, 1, 6);
    for (int i = 0; i < N; i++) cout << tab[i] << " ";
    cout << endl;

    int lotto[6];
    losujBezPowtorzen(lotto, 6, 1, 49);
    for (int x : lotto) cout << x << " ";
    cout << endl;

    tasujTablice(tab, N);
    for (int i = 0; i < N; i++) cout << tab[i] << " ";
    cout << endl;

    cout << "haslo: " << generujHaslo(12, true, true, true) << endl;
    return 0;
}
