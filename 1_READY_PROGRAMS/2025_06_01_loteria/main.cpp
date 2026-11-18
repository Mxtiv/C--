// ======================================================================
// INF.04-01-25.06-SG (and AG) - loteria: n zestawów po 6 RÓŻNYCH liczb z <1, 49>,
// tablica dwuwymiarowa n x 6 (vector, bo n z klawiatury), zliczenie wystąpień 1..49.
// Funkcje: wypełniająca i wyświetlająca (bez zmiennych globalnych). Spec + key: README.md
// ======================================================================
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

/**********************************************
nazwa funkcji:  losujZestawy
opis funkcji:   wypełnia każdy wiersz tablicy sześcioma różnymi liczbami z przedziału 1..49
parametry:      zestawy - tablica dwuwymiarowa n x 6 na wyniki losowań
zwracany typ i opis: brak
autor:          00000000000
***********************************************/
void losujZestawy(vector<vector<int>> &zestawy)
{
    for (int w = 0; w < (int)zestawy.size(); w++)
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
            if (!powtorka)
            {
                zestawy[w][wylosowane] = liczba;
                wylosowane++;
            }
        }
    }
}

void wyswietlZestawy(const vector<vector<int>> &zestawy)
{
    for (int w = 0; w < (int)zestawy.size(); w++)
    {
        cout << "Zestaw " << w + 1 << ": ";
        for (int k = 0; k < 6; k++)
        {
            cout << zestawy[w][k] << " ";
        }
        cout << endl;
    }
}

void wyswietlWystapienia(const vector<vector<int>> &zestawy)
{
    int wystapienia[50] = {0};                  // indeksy 1..49
    for (int w = 0; w < (int)zestawy.size(); w++)
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
    srand((unsigned)time(0));
    int n;
    cout << "Ile zestawow wylosowac? ";
    cin >> n;
    if (n < 1)
    {
        cout << "Liczba zestawow musi byc dodatnia" << endl;
        return 0;
    }

    vector<vector<int>> zestawy(n, vector<int>(6));
    losujZestawy(zestawy);
    wyswietlZestawy(zestawy);
    wyswietlWystapienia(zestawy);
    return 0;
}
