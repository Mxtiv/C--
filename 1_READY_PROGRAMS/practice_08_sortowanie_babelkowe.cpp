// ======================================================================
// READY PROGRAM 08: bubble sort - size from the user, random fill, display before /
// after, ascending and descending
// Based on: Arrays/Sort/bubblesort.cpp (your version had an out-of-range read - fixed here)
// Blocks used: SORT-01, SORT-02, RND-02, ARR-02, ARR-22, IO-01
// ======================================================================
//
// Treść zadania (wariant): Program pobiera liczbę elementów n (5..50), tworzy tablicę
// dynamiczną, wypełnia ją liczbami pseudolosowymi z zakresu 0..99, wyświetla ją,
// sortuje metodą bąbelkową rosnąco i wyświetla wynik, a następnie sortuje malejąco.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <utility>
using namespace std;

/********************************************************
 * nazwa funkcji: wypelnijLosowo
 * opis funkcji: wypełnia tablicę liczbami pseudolosowymi z przedziału min..max
 * parametry: tab - tablica do wypełnienia
 *            n - liczba elementów
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

/********************************************************
 * nazwa funkcji: wyswietlTablice
 * opis funkcji: wyświetla elementy tablicy oddzielone przecinkami
 * parametry: tab - tablica
 *            n - liczba elementów
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void wyswietlTablice(const int tab[], int n)
{
    for (int i = 0; i < n; i++)
        cout << tab[i] << (i < n - 1 ? ", " : "\n");
}

/********************************************************
 * nazwa funkcji: sortujBabelkowo
 * opis funkcji: sortuje tablicę metodą bąbelkową - porównuje sąsiednie elementy
 *               i zamienia je, jeśli są w złej kolejności; kończy, gdy w całym
 *               przebiegu nie było zamiany
 * parametry: tab - tablica do posortowania
 *            n - liczba elementów
 *            rosnaco - true: sortowanie rosnące, false: malejące
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void sortujBabelkowo(int tab[], int n, bool rosnaco)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool zamiana = false;
        for (int j = 0; j < n - 1 - i; j++)       // j + 1 < n: never past the end
        {
            bool zlaKolejnosc = rosnaco ? (tab[j] > tab[j + 1]) : (tab[j] < tab[j + 1]);
            if (zlaKolejnosc)
            {
                swap(tab[j], tab[j + 1]);
                zamiana = true;
            }
        }
        if (!zamiana) break;
    }
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

int main()
{
    srand(time(0));
    int n = wczytajLiczbe("Ile liczb wylosowac? (5-50): ", 5, 50);
    int *tab = new int[n];

    wypelnijLosowo(tab, n, 0, 99);
    cout << "Przed sortowaniem:   ";
    wyswietlTablice(tab, n);

    sortujBabelkowo(tab, n, true);
    cout << "Posortowane rosnaco: ";
    wyswietlTablice(tab, n);

    sortujBabelkowo(tab, n, false);
    cout << "Posortowane malejaco:";
    wyswietlTablice(tab, n);

    delete[] tab;
    return 0;
}
