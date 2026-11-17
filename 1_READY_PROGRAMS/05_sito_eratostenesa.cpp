// ======================================================================
// READY PROGRAM 05: sieve of Eratosthenes - all primes from 2 to n
// Original file: inf04/4)Algorytm.cpp
// Blocks used: NUM-02, IO-01
// ======================================================================
//
// Treść zadania: Program pobiera liczbę n (2..10000) i wypisuje wszystkie liczby
// pierwsze z przedziału 2..n wyznaczone algorytmem sita Eratostenesa oraz ich liczbę.
// Algorytm: zakładamy, że wszystkie liczby są pierwsze; dla kolejnych liczb pierwszych
// i (dopóki i*i <= n) wykreślamy ich wielokrotności, zaczynając od i*i.

#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

/********************************************************
 * nazwa funkcji: sitoEratostenesa
 * opis funkcji: wyznacza liczby pierwsze nie większe od n metodą sita Eratostenesa
 * parametry: n - górna granica przedziału
 * zwracany typ i opis: vector<int> - liczby pierwsze z przedziału 2..n
 * autor: <numer zdającego>
 ********************************************************/
vector<int> sitoEratostenesa(int n)
{
    vector<bool> czyPierwsza(n + 1, true);     // vector<bool> instead of bool tab[n+1]
    vector<int> pierwsze;
    for (int i = 2; i <= n; i++)
    {
        if (!czyPierwsza[i]) continue;
        pierwsze.push_back(i);
        for (long long j = (long long)i * i; j <= n; j += i)
            czyPierwsza[j] = false;              // cross out multiples of i
    }
    return pierwsze;
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
    int n = wczytajLiczbe("Podaj gorna granice przedzialu n (2-10000): ", 2, 10000);
    vector<int> pierwsze = sitoEratostenesa(n);

    cout << "Liczby pierwsze z przedzialu 2.." << n << ":" << endl;
    for (size_t i = 0; i < pierwsze.size(); i++)
    {
        cout << pierwsze[i] << " ";
        if ((i + 1) % 15 == 0) cout << endl;     // 15 numbers per line
    }
    cout << endl << "Liczba znalezionych liczb pierwszych: " << pierwsze.size() << endl;
    return 0;
}
