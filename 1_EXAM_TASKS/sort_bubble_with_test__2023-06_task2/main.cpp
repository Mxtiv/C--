// ======================================================================
// INF.04-02-23.06-SG - sortowanie bąbelkowe ROSNĄCO tablicy 100 liczb pseudolosowych,
// bez gotowych funkcji sortowania i zamiany (swap). Funkcja: argument tablica, void.
// Część III: test w programie głównym, liczby 0..1000; jego kopia = plik test.cpp
// (sheet: "Test zapisz w folderze testy, w pliku o nazwie test").
// Spec + key checklist: README.md in this folder.
// ======================================================================
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROZMIAR = 100;

void sortujBabelkowo(int tablica[], int rozmiar)
{
    for (int i = 0; i < rozmiar - 1; i++)
    {
        for (int j = 0; j < rozmiar - 1 - i; j++)
        {
            if (tablica[j] > tablica[j + 1])
            {
                int pomocnicza = tablica[j];      // zamiana bez std::swap
                tablica[j] = tablica[j + 1];
                tablica[j + 1] = pomocnicza;
            }
        }
    }
}

int main()
{
    srand(time(0));

    // ===== test (the same code is in test.cpp) =====
    int tablica[ROZMIAR];
    for (int i = 0; i < ROZMIAR; i++)
    {
        tablica[i] = rand() % 1001;                // liczby całkowite dodatnie 0..1000
    }

    sortujBabelkowo(tablica, ROZMIAR);

    cout << "Tablica posortowana rosnaco:" << endl;
    for (int i = 0; i < ROZMIAR; i++)
    {
        cout << tablica[i] << " ";
    }
    cout << endl;

    bool posortowana = true;
    for (int i = 0; i < ROZMIAR - 1; i++)
    {
        if (tablica[i] > tablica[i + 1])
        {
            posortowana = false;
        }
    }
    if (posortowana)
    {
        cout << "Test sortowania: OK - tablica jest posortowana" << endl;
    }
    else
    {
        cout << "Test sortowania: BLAD" << endl;
    }
    // ===== end of test =====
    return 0;
}
