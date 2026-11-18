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
#include <cstdlib>
#include <ctime>
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
    {
        kostki[i] = rand() % 6 + 1;
    }
}

/********************************************************
 * nazwa funkcji: wyswietlKostki
 * opis funkcji: wyświetla wyniki rzutu w postaci "Kostka <nr>: <wartość>"
 * parametry: kostki - tablica wyników
 *            n - liczba kostek
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void wyswietlKostki(int kostki[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Kostka " << i + 1 << ": " << kostki[i] << endl;
    }
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
int policzPunkty(int kostki[], int n)
{
    int ile[7];                        // ile[w] = how many dice show w (index 0 unused)
    for (int w = 0; w < 7; w++)
    {
        ile[w] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        ile[kostki[i]]++;
    }

    int punkty = 0;
    for (int w = 1; w <= 6; w++)
    {
        if (ile[w] >= 2)
        {
            punkty = punkty + ile[w] * w;
        }
    }
    return punkty;
}

int main()
{
    srand(time(0));
    int kostki[10];
    char odpowiedz;

    do
    {
        int n;
        do
        {
            cout << "\nIloma kostkami chcesz rzucic? (3-10): ";
            cin >> n;
        } while (n < 3 || n > 10);

        rzucKostkami(kostki, n);
        wyswietlKostki(kostki, n);
        cout << "Liczba uzyskanych punktow: " << policzPunkty(kostki, n) << endl;

        do
        {
            cout << "Jeszcze raz? (t/n): ";
            cin >> odpowiedz;
        } while (odpowiedz != 't' && odpowiedz != 'n');
    } while (odpowiedz == 't');

    cout << "Koniec gry." << endl;
    return 0;
}
