// ======================================================================
// INF.04-01-23.06-SG - sito Eratostenesa dla n = 100, według pseudokodu z arkusza.
// Wypełnianie tablicy w OSOBNEJ funkcji: argument = tablica, nic nie zwraca (void).
// Spec + key checklist: README.md in this folder.
// ======================================================================
#include <iostream>
using namespace std;

const int N = 100;

/*******************************************************
nazwa funkcji:  wypelnijSito
parametry wejściowe: A - tablica logiczna o indeksach 0..N, true = liczba pierwsza
wartość zwracana: brak
informacje:     wypełnia tablicę wartościami true, a następnie wykreśla (false)
                wielokrotności kolejnych liczb - sito Eratostenesa
autor:          00000000000
****************************************************/
void wypelnijSito(bool A[])
{
    for (int i = 2; i <= N; i++)
    {
        A[i] = true;
    }
    for (int i = 2; i * i <= N; i++)            // i nie większe niż pierwiastek z n
    {
        if (A[i] == true)
        {
            for (int j = 2 * i; j <= N; j += i)  // j = 2i, 3i, 4i, ... <= n
            {
                A[j] = false;
            }
        }
    }
}

int main()
{
    bool A[N + 1];
    wypelnijSito(A);

    cout << "Liczby pierwsze z przedzialu 2.." << N << ": ";
    for (int i = 2; i <= N; i++)
    {
        if (A[i] == true)
        {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
