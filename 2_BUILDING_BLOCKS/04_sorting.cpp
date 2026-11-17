// ======================================================================
// BUILDING BLOCKS: sorting (sortowanie) - bubble, selection, insertion (ascending
// and descending), quicksort, counting sort, std::sort
// HOW TO USE: copy the comment box + code under a //@ line, up to the next //@ line.
// Descending = flip the comparison sign (marked with  <-  in every block).
// ======================================================================

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

//@ SORT-01 | bubble sort ASCENDING (stops early when nothing was swapped) | <utility>
/********************************************************
 * nazwa funkcji: sortujBabelkowo
 * opis funkcji: sortuje tablicę rosnąco metodą bąbelkową - porównuje sąsiednie elementy
 *               i zamienia je miejscami; kończy, gdy w przebiegu nie było zamiany
 * parametry: tab - tablica do posortowania
 *            n - liczba elementów tablicy
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void sortujBabelkowo(int tab[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool zamiana = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (tab[j] > tab[j + 1])            // <-  > ascending,  < descending
            {
                swap(tab[j], tab[j + 1]);
                zamiana = true;
            }
        }
        if (!zamiana) break;
    }
}

//@ SORT-02 | bubble sort DESCENDING | <utility>
/********************************************************
 * nazwa funkcji: sortujBabelkowoMalejaco
 * opis funkcji: sortuje tablicę malejąco metodą bąbelkową
 * parametry: tab - tablica do posortowania
 *            n - liczba elementów tablicy
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void sortujBabelkowoMalejaco(int tab[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool zamiana = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (tab[j] < tab[j + 1])            // <-
            {
                swap(tab[j], tab[j + 1]);
                zamiana = true;
            }
        }
        if (!zamiana) break;
    }
}

//@ SORT-03 | selection sort ASCENDING (find the minimum, put it at position i) | <utility>
/********************************************************
 * nazwa funkcji: sortujPrzezWybieranie
 * opis funkcji: sortuje tablicę rosnąco przez wybieranie - w każdym kroku wyszukuje
 *               najmniejszy element nieposortowanej części i zamienia go z elementem i
 * parametry: tab - tablica do posortowania
 *            n - liczba elementów tablicy
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void sortujPrzezWybieranie(int tab[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int indeksMin = i;
        for (int j = i + 1; j < n; j++)
            if (tab[j] < tab[indeksMin])         // <-  < ascending,  > descending
                indeksMin = j;
        swap(tab[i], tab[indeksMin]);
    }
}

//@ SORT-04 | selection sort DESCENDING (find the maximum) | <utility>
/********************************************************
 * nazwa funkcji: sortujPrzezWybieranieMalejaco
 * opis funkcji: sortuje tablicę malejąco przez wybieranie - w każdym kroku wyszukuje
 *               największy element nieposortowanej części i zamienia go z elementem i
 * parametry: tab - tablica do posortowania
 *            n - liczba elementów tablicy
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void sortujPrzezWybieranieMalejaco(int tab[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int indeksMax = i;
        for (int j = i + 1; j < n; j++)
            if (tab[j] > tab[indeksMax])         // <-
                indeksMax = j;
        swap(tab[i], tab[indeksMax]);
    }
}

//@ SORT-05 | insertion sort ASCENDING (shift bigger elements right, insert the key) | -
/********************************************************
 * nazwa funkcji: sortujPrzezWstawianie
 * opis funkcji: sortuje tablicę rosnąco przez wstawianie - kolejny element jest wstawiany
 *               we właściwe miejsce posortowanej części tablicy
 * parametry: tab - tablica do posortowania
 *            n - liczba elementów tablicy
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void sortujPrzezWstawianie(int tab[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int klucz = tab[i];
        int j = i - 1;
        while (j >= 0 && tab[j] > klucz)        // <-  > ascending,  < descending
        {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = klucz;
    }
}

//@ SORT-06 | quicksort (fast, recursive) - call: sortujSzybko(tab, 0, n - 1) | <utility>
/********************************************************
 * nazwa funkcji: sortujSzybko
 * opis funkcji: sortuje rosnąco fragment tablicy algorytmem szybkiego sortowania (quicksort)
 * parametry: tab - tablica do posortowania
 *            lewy - indeks pierwszego elementu fragmentu
 *            prawy - indeks ostatniego elementu fragmentu
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void sortujSzybko(int tab[], int lewy, int prawy)
{
    if (lewy >= prawy) return;
    int pivot = tab[(lewy + prawy) / 2];
    int i = lewy, j = prawy;
    while (i <= j)
    {
        while (tab[i] < pivot) i++;
        while (tab[j] > pivot) j--;
        if (i <= j)
        {
            swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }
    sortujSzybko(tab, lewy, j);
    sortujSzybko(tab, i, prawy);
}

//@ SORT-07 | counting sort - for small value ranges (e.g. grades 1..6, dice) | <vector>
/********************************************************
 * nazwa funkcji: sortujPrzezZliczanie
 * opis funkcji: sortuje rosnąco tablicę liczb z przedziału min..max przez zliczanie
 *               wystąpień każdej wartości
 * parametry: tab - tablica do posortowania
 *            n - liczba elementów tablicy
 *            min - najmniejsza możliwa wartość
 *            max - największa możliwa wartość
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void sortujPrzezZliczanie(int tab[], int n, int min, int max)
{
    vector<int> licznik(max - min + 1, 0);
    for (int i = 0; i < n; i++)
        licznik[tab[i] - min]++;
    int k = 0;
    for (int w = min; w <= max; w++)
        for (int ile = 0; ile < licznik[w - min]; ile++)
            tab[k++] = w;
}

//@ SORT-08 | library sort std::sort - ascending / descending (when the task doesn't require your own algorithm) | <algorithm> <functional>
/********************************************************
 * nazwa funkcji: sortujBiblioteka
 * opis funkcji: sortuje tablicę funkcją std::sort rosnąco lub malejąco
 * parametry: tab - tablica do posortowania
 *            n - liczba elementów tablicy
 *            malejaco - true = sortowanie malejące, false = rosnące
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void sortujBiblioteka(int tab[], int n, bool malejaco)
{
    if (malejaco)
        sort(tab, tab + n, greater<int>());
    else
        sort(tab, tab + n);                  // vector: sort(v.begin(), v.end());
}

// ====================== DEMO (don't copy) ======================
void pokaz(const char *nazwa, const int tab[], int n)
{
    cout << nazwa;
    for (int i = 0; i < n; i++) cout << tab[i] << " ";
    cout << endl;
}

int main()
{
    const int N = 9;
    const int dane[N] = {29, 3, 72, 15, 3, 88, 41, 0, 6};
    int t[N];

    copy(dane, dane + N, t); sortujBabelkowo(t, N);               pokaz("babelkowo:          ", t, N);
    copy(dane, dane + N, t); sortujBabelkowoMalejaco(t, N);       pokaz("babelkowo malejaco: ", t, N);
    copy(dane, dane + N, t); sortujPrzezWybieranie(t, N);         pokaz("wybieranie:         ", t, N);
    copy(dane, dane + N, t); sortujPrzezWybieranieMalejaco(t, N); pokaz("wybieranie malejaco:", t, N);
    copy(dane, dane + N, t); sortujPrzezWstawianie(t, N);         pokaz("wstawianie:         ", t, N);
    copy(dane, dane + N, t); sortujSzybko(t, 0, N - 1);           pokaz("szybkie:            ", t, N);
    copy(dane, dane + N, t); sortujBiblioteka(t, N, true);        pokaz("std::sort malejaco: ", t, N);
    int oceny[] = {4, 2, 6, 1, 4, 3, 5, 2};
    sortujPrzezZliczanie(oceny, 8, 1, 6);                         pokaz("zliczanie:          ", oceny, 8);
    return 0;
}
