// ======================================================================
// INF.04-01-22.06-SG - przeszukiwanie tablicy Z WARTOWNIKIEM
// 50 liczb losowych 1..100, szukana wartość z klawiatury, wynik: indeks albo komunikat.
// Spec + key checklist: README.md in this folder.
// ======================================================================
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROZMIAR = 50;

void wypelnijTablice(int tablica[], int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        tablica[i] = rand() % 100 + 1;
    }
}

/******************************************************
nazwa funkcji:  szukajZWartownikiem
argumenty:      tablica - tablica liczb z jednym wolnym miejscem na końcu (rozmiar + 1)
                rozmiar - liczba elementów z danymi
                szukana - wartość, której szukamy
typ zwracany:   int, indeks pierwszego wystąpienia; rozmiar oznacza "nie znaleziono"
informacje:     wyszukiwanie liniowe z wartownikiem - szukana wartość jest wstawiana
                za ostatnim elementem, dzięki temu pętla nie wychodzi poza tablicę
autor:          00000000000
*****************************************************/
int szukajZWartownikiem(int tablica[], int rozmiar, int szukana)
{
    tablica[rozmiar] = szukana;          // wartownik na pozycji n+1
    int i = 0;
    while (tablica[i] != szukana)
    {
        i++;
    }
    return i;
}

void wyswietlTablice(int tablica[], int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        cout << tablica[i];
        if (i < rozmiar - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}

int main()
{
    srand(time(0));
    int tablica[ROZMIAR + 1];            // +1 = miejsce na wartownika
    wypelnijTablice(tablica, ROZMIAR);

    // test działania aplikacji
    int szukana;
    cout << "Podaj liczbe do wyszukania (1..100): ";
    cin >> szukana;

    int indeks = szukajZWartownikiem(tablica, ROZMIAR, szukana);

    cout << "Zawartosc tablicy: ";
    wyswietlTablice(tablica, ROZMIAR);
    if (indeks == ROZMIAR)
    {
        cout << "Liczby " << szukana << " nie ma w tablicy" << endl;
    }
    else
    {
        cout << "Liczba " << szukana << " znajduje sie pod indeksem " << indeks << endl;
    }
    return 0;
}
