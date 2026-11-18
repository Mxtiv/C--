// ======================================================================
// factorial with a loop (iterative)
// Original file: unsorted/sprawdzian/rekurencja2.cpp
// ======================================================================

#include <iostream>
using namespace std;

// Funkcja do obliczania silni przy użyciu pętli
long long silniaPetla(int n)
{
    long long wynik = 1;
    for (int i = 1; i <= n; i++)
    {
        wynik = wynik * i;
    }
    return wynik;
}

int main()
{
    int liczba;
    do
    {
        cout << "Podaj liczbę (0-20): ";
        cin >> liczba;
    } while (liczba < 0 || liczba > 20);

    cout << "Silnia liczby " << liczba << " wynosi (petla): " << silniaPetla(liczba) << endl;
    return 0;
}
