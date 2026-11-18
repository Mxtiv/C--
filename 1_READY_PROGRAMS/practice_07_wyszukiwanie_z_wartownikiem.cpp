// ======================================================================
// READY PROGRAM 07: linear search WITH A SENTINEL (wyszukiwanie z wartownikiem)
// Original file: inf04/6)Wartownik.cpp
// Blocks used: ARR-16, RND-02, ARR-02, IO-01
// ======================================================================
//
// Treść zadania: Tablica 50 liczb całkowitych wypełniona liczbami pseudolosowymi
// z zakresu 1..100. Program wyświetla tablicę, pobiera szukaną liczbę i wyszukuje ją
// metodą z wartownikiem: szukana wartość jest wstawiana na dodatkową pozycję za
// ostatnim elementem, dzięki czemu w pętli nie trzeba sprawdzać końca tablicy.
// Funkcja zwraca indeks pierwszego wystąpienia albo -1.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 50;

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
    {
        tab[i] = rand() % (max - min + 1) + min;
    }
}

/********************************************************
 * nazwa funkcji: wyswietlTablice
 * opis funkcji: wyświetla elementy tablicy w jednym wierszu
 * parametry: tab - tablica
 *            n - liczba elementów
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void wyswietlTablice(int tab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
}

/********************************************************
 * nazwa funkcji: szukajZWartownikiem
 * opis funkcji: wyszukuje wartość metodą z wartownikiem - szukana wartość jest
 *               wstawiana za ostatni element tablicy (pozycja n)
 * parametry: tab - tablica o rozmiarze co najmniej n + 1
 *            n - liczba elementów z danymi
 *            szukana - szukana wartość
 * zwracany typ i opis: int - indeks pierwszego wystąpienia lub -1, gdy nie znaleziono
 * autor: <numer zdającego>
 ********************************************************/
int szukajZWartownikiem(int tab[], int n, int szukana)
{
    tab[n] = szukana;              // wartownik
    int i = 0;
    while (tab[i] != szukana)
    {
        i++;
    }
    if (i < n)
    {
        return i;
    }
    return -1;                     // zatrzymano się na wartowniku
}

int main()
{
    srand(time(0));
    int tab[N + 1];                // + 1 = miejsce na wartownika

    wypelnijLosowo(tab, N, 1, 100);
    cout << "Zawartosc tablicy:" << endl;
    wyswietlTablice(tab, N);

    int szukana;
    do
    {
        cout << "Podaj szukana liczbe (1-100): ";
        cin >> szukana;
    } while (szukana < 1 || szukana > 100);

    int indeks = szukajZWartownikiem(tab, N, szukana);

    if (indeks != -1)
    {
        cout << "Znaleziono liczbe " << szukana << " pod indeksem " << indeks << endl;
    }
    else
    {
        cout << "Liczby " << szukana << " nie ma w tablicy (wynik: -1)" << endl;
    }
    return 0;
}
