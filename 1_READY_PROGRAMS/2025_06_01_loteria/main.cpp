// ======================================================================
// INF.04-01-25.06-SG (and AG) - loteria: n zestawów po 6 RÓŻNYCH liczb z <1, 49>,
// tablica dwuwymiarowa n x 6 (n z klawiatury, 1..100), zliczenie wystąpień 1..49.
// Funkcje: wypełniająca i wyświetlająca (bez zmiennych globalnych). Spec + key: README.md
// ======================================================================
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAKS_ZESTAWOW = 100;

/**********************************************
nazwa funkcji:  losujZestawy
opis funkcji:   wypełnia każdy wiersz tablicy sześcioma różnymi liczbami z przedziału 1..49
parametry:      zestawy - tablica dwuwymiarowa n x 6 na wyniki losowań
                n - liczba zestawów (wierszy)
zwracany typ i opis: brak
autor:          00000000000
***********************************************/
void losujZestawy(int zestawy[][6], int n)
{
    for (int w = 0; w < n; w++)
    {
        int wylosowane = 0;
        while (wylosowane < 6)
        {
            int liczba = rand() % 49 + 1;
            bool powtorka = false;
            for (int k = 0; k < wylosowane; k++)
            {
                if (zestawy[w][k] == liczba)
                {
                    powtorka = true;
                }
            }
            if (powtorka == false)
            {
                zestawy[w][wylosowane] = liczba;
                wylosowane++;
            }
        }
    }
}

void wyswietlZestawy(int zestawy[][6], int n)
{
    for (int w = 0; w < n; w++)
    {
        cout << "Zestaw " << w + 1 << ": ";
        for (int k = 0; k < 6; k++)
        {
            cout << zestawy[w][k] << " ";
        }
        cout << endl;
    }
}

void wyswietlWystapienia(int zestawy[][6], int n)
{
    int wystapienia[50] = {0};                  // same zera, używane indeksy 1..49
    for (int w = 0; w < n; w++)
    {
        for (int k = 0; k < 6; k++)
        {
            wystapienia[zestawy[w][k]]++;
        }
    }
    cout << "Liczba wystapien kazdej liczby:" << endl;
    for (int liczba = 1; liczba <= 49; liczba++)
    {
        cout << liczba << ": " << wystapienia[liczba] << endl;
    }
}

int main()
{
    srand(time(0));
    int zestawy[MAKS_ZESTAWOW][6];
    int n;
    do
    {
        cout << "Ile zestawow wylosowac? (1 - " << MAKS_ZESTAWOW << "): ";
        cin >> n;
    } while (n < 1 || n > MAKS_ZESTAWOW);

    losujZestawy(zestawy, n);
    wyswietlZestawy(zestawy, n);
    wyswietlWystapienia(zestawy, n);
    return 0;
}
