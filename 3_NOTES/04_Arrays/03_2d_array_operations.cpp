// ======================================================================
// ADDED (gap-fill): 2D arrays - declare, init, pass to function, row/column sums,
// max element with position, diagonal
// Not from your original repo - written to fill a missing topic.
// ======================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int WIERSZE = 3;
const int KOLUMNY = 4;

// When passing a 2D array, every dimension except the first must be given.
void wypelnij(int tab[][KOLUMNY], int wiersze)
{
    for (int w = 0; w < wiersze; w++)
    {
        for (int k = 0; k < KOLUMNY; k++)
        {
            tab[w][k] = rand() % 10;
        }
    }
}

void wypisz(int tab[][KOLUMNY], int wiersze)
{
    for (int w = 0; w < wiersze; w++)
    {
        for (int k = 0; k < KOLUMNY; k++)
        {
            cout << tab[w][k] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    srand(time(0));

    // ---------------- declaration + initialization ----------------
    int stala[2][3] = { {1, 2, 3},
                        {4, 5, 6} };
    cout << "stala[1][2] = " << stala[1][2] << endl;     // row 1, column 2 -> 6

    int tab[WIERSZE][KOLUMNY];
    wypelnij(tab, WIERSZE);
    wypisz(tab, WIERSZE);

    // ---------------- row sums ----------------
    for (int w = 0; w < WIERSZE; w++)
    {
        int sumaWiersza = 0;
        for (int k = 0; k < KOLUMNY; k++)
        {
            sumaWiersza = sumaWiersza + tab[w][k];
        }
        cout << "row " << w << " sum = " << sumaWiersza << endl;
    }

    // ---------------- column sums (swap the loops) ----------------
    for (int k = 0; k < KOLUMNY; k++)
    {
        int sumaKolumny = 0;
        for (int w = 0; w < WIERSZE; w++)
        {
            sumaKolumny = sumaKolumny + tab[w][k];
        }
        cout << "col " << k << " sum = " << sumaKolumny << endl;
    }

    // ---------------- max with its position ----------------
    int maxW = 0;
    int maxK = 0;
    for (int w = 0; w < WIERSZE; w++)
    {
        for (int k = 0; k < KOLUMNY; k++)
        {
            if (tab[w][k] > tab[maxW][maxK])
            {
                maxW = w;
                maxK = k;
            }
        }
    }
    cout << "max " << tab[maxW][maxK] << " at [" << maxW << "][" << maxK << "]" << endl;

    // ---------------- square matrix diagonal ----------------
    int kw[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int przekatna = 0;
    int drugaPrzekatna = 0;
    for (int i = 0; i < 3; i++)
    {
        przekatna = przekatna + kw[i][i];               // main diagonal
        drugaPrzekatna = drugaPrzekatna + kw[i][2 - i]; // other diagonal
    }
    cout << "diagonal sum " << przekatna << ", anti-diagonal sum " << drugaPrzekatna << endl;

    return 0;
}
