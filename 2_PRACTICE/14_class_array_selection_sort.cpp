// ======================================================================
// READY PROGRAM 02: class with a STATIC array of 10 numbers - random fill, display,
// selection sort ascending AND descending, smallest / largest value
// (your INF.04 group A: "sortowanie przez wybieranie malejąco + wartość najmniejsza")
// Original file: inf04/7)selectionSorting.cpp + inf04/10)experimental.cpp
// Blocks used: CLS-04, SORT-03, SORT-04, ARR-05, ARR-06, ARR-02
// ======================================================================
//
// Treść zadania (wariant): klasa z polem - tablicą 10 liczb całkowitych. Metody:
// wypełniająca tablicę liczbami pseudolosowymi z zakresu 1..100, wyświetlająca tablicę,
// sortująca tablicę przez wybieranie (rosnąco / malejąco), zwracająca wartość
// najmniejszą i największą. Program wyświetla tablicę przed i po sortowaniu.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROZMIAR = 10;

/********************************************************
 * nazwa klasy: Tablica
 * opis klasy: przechowuje tablicę 10 liczb całkowitych i sortuje ją przez wybieranie
 * pola: tab - tablica ROZMIAR liczb całkowitych
 * autor: <numer zdającego>
 ********************************************************/
class Tablica
{
private:
    int tab[ROZMIAR];

public:
    /********************************************************
     * nazwa funkcji: wypelnij
     * opis funkcji: wypełnia tablicę liczbami pseudolosowymi z przedziału min..max
     * parametry: min - najmniejsza losowana wartość
     *            max - największa losowana wartość
     * zwracany typ i opis: brak
     * autor: <numer zdającego>
     ********************************************************/
    void wypelnij(int min, int max)
    {
        for (int i = 0; i < ROZMIAR; i++)
        {
            tab[i] = rand() % (max - min + 1) + min;
        }
    }

    /********************************************************
     * nazwa funkcji: wyswietl
     * opis funkcji: wyświetla elementy tablicy w jednym wierszu
     * parametry: brak
     * zwracany typ i opis: brak
     * autor: <numer zdającego>
     ********************************************************/
    void wyswietl()
    {
        for (int i = 0; i < ROZMIAR; i++)
        {
            cout << tab[i] << " ";
        }
        cout << endl;
    }

    /********************************************************
     * nazwa funkcji: sortujRosnaco
     * opis funkcji: sortuje tablicę rosnąco metodą przez wybieranie - w każdym kroku
     *               wyszukuje najmniejszy element nieposortowanej części i zamienia go
     *               z pierwszym elementem tej części
     * parametry: brak
     * zwracany typ i opis: brak
     * autor: <numer zdającego>
     ********************************************************/
    void sortujRosnaco()
    {
        for (int i = 0; i < ROZMIAR - 1; i++)
        {
            int indeksMin = i;
            for (int j = i + 1; j < ROZMIAR; j++)
            {
                if (tab[j] < tab[indeksMin])
                {
                    indeksMin = j;
                }
            }
            int pomocnicza = tab[i];
            tab[i] = tab[indeksMin];
            tab[indeksMin] = pomocnicza;
        }
    }

    /********************************************************
     * nazwa funkcji: sortujMalejaco
     * opis funkcji: sortuje tablicę malejąco metodą przez wybieranie - w każdym kroku
     *               wyszukuje największy element nieposortowanej części
     * parametry: brak
     * zwracany typ i opis: brak
     * autor: <numer zdającego>
     ********************************************************/
    void sortujMalejaco()
    {
        for (int i = 0; i < ROZMIAR - 1; i++)
        {
            int indeksMax = i;
            for (int j = i + 1; j < ROZMIAR; j++)
            {
                if (tab[j] > tab[indeksMax])
                {
                    indeksMax = j;
                }
            }
            int pomocnicza = tab[i];
            tab[i] = tab[indeksMax];
            tab[indeksMax] = pomocnicza;
        }
    }

    /********************************************************
     * nazwa funkcji: minimum
     * opis funkcji: wyszukuje najmniejszą wartość w tablicy
     * parametry: brak
     * zwracany typ i opis: int - najmniejsza wartość
     * autor: <numer zdającego>
     ********************************************************/
    int minimum()
    {
        int min = tab[0];
        for (int i = 1; i < ROZMIAR; i++)
        {
            if (tab[i] < min)
            {
                min = tab[i];
            }
        }
        return min;
    }

    /********************************************************
     * nazwa funkcji: maksimum
     * opis funkcji: wyszukuje największą wartość w tablicy
     * parametry: brak
     * zwracany typ i opis: int - największa wartość
     * autor: <numer zdającego>
     ********************************************************/
    int maksimum()
    {
        int max = tab[0];
        for (int i = 1; i < ROZMIAR; i++)
        {
            if (tab[i] > max)
            {
                max = tab[i];
            }
        }
        return max;
    }
};

int main()
{
    srand(time(0));
    Tablica tablica;
    tablica.wypelnij(1, 100);

    cout << "Tablica nieposortowana: ";
    tablica.wyswietl();

    tablica.sortujMalejaco();
    cout << "Tablica posortowana malejaco: ";
    tablica.wyswietl();

    tablica.sortujRosnaco();
    cout << "Tablica posortowana rosnaco: ";
    tablica.wyswietl();

    cout << "Najmniejsza wartosc w tablicy: " << tablica.minimum() << endl;
    cout << "Najwieksza wartosc w tablicy: " << tablica.maksimum() << endl;
    return 0;
}
