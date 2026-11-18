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
using namespace std;

const int MAX_N = 10000;

/********************************************************
 * nazwa funkcji: sitoEratostenesa
 * opis funkcji: wyznacza liczby pierwsze nie większe od n metodą sita Eratostenesa
 *               i zapisuje je do tablicy pierwsze
 * parametry: n - górna granica przedziału
 *            pierwsze - tablica, do której trafiają znalezione liczby pierwsze
 * zwracany typ i opis: int - liczba znalezionych liczb pierwszych
 * autor: <numer zdającego>
 ********************************************************/
int sitoEratostenesa(int n, int pierwsze[])
{
    bool czyPierwsza[MAX_N + 1];
    for (int i = 0; i <= n; i++)
    {
        czyPierwsza[i] = true;
    }

    int ile = 0;
    for (int i = 2; i <= n; i++)
    {
        if (czyPierwsza[i])
        {
            pierwsze[ile] = i;
            ile++;
            for (int j = i * i; j <= n; j = j + i)
            {
                czyPierwsza[j] = false;          // cross out multiples of i
            }
        }
    }
    return ile;
}

int main()
{
    int n;
    do
    {
        cout << "Podaj gorna granice przedzialu n (2-10000): ";
        cin >> n;
    } while (n < 2 || n > MAX_N);

    int pierwsze[MAX_N];
    int ile = sitoEratostenesa(n, pierwsze);

    cout << "Liczby pierwsze z przedzialu 2.." << n << ":" << endl;
    for (int i = 0; i < ile; i++)
    {
        cout << pierwsze[i] << " ";
        if ((i + 1) % 15 == 0)
        {
            cout << endl;                        // 15 numbers per line
        }
    }
    cout << endl << "Liczba znalezionych liczb pierwszych: " << ile << endl;
    return 0;
}
