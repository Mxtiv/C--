// ======================================================================
// BUILDING BLOCKS: arrays (tablice) - display, sum, average, min/max, product,
// counting, searching (first / all / sentinel / binary), reverse, histogram, 2D
// HOW TO USE: copy the comment box + code under a //@ line, up to the next //@ line.
// INSIDE A CLASS (typical exam task): remove the (tab, n) parameters and use the
// class fields instead, e.g. tab -> tablica, n -> rozmiar. See CLS-03 and
// 1_READY_PROGRAMS/01_ for the class version of these methods.
// ======================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//@ ARR-01 | display every element as "index: value" (exam format) | <iostream>
/********************************************************
 * nazwa funkcji: wyswietlTablice
 * opis funkcji: wyświetla wszystkie elementy tablicy w postaci "<indeks>: <wartość>"
 * parametry: tab - tablica liczb całkowitych
 *            n - liczba elementów tablicy
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void wyswietlTablice(int tab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << ": " << tab[i] << endl;
    }
}

//@ ARR-02 | display the array in one line, separated by spaces | <iostream>
/********************************************************
 * nazwa funkcji: wyswietlWLinii
 * opis funkcji: wyświetla elementy tablicy w jednym wierszu, oddzielone spacjami
 * parametry: tab - tablica liczb całkowitych
 *            n - liczba elementów tablicy
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void wyswietlWLinii(int tab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
}

//@ ARR-03 | sum of all elements | -
/********************************************************
 * nazwa funkcji: suma
 * opis funkcji: oblicza sumę elementów tablicy
 * parametry: tab - tablica liczb całkowitych
 *            n - liczba elementów tablicy
 * zwracany typ i opis: int - suma elementów
 * autor: <numer zdającego>
 ********************************************************/
int suma(int tab[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s = s + tab[i];
    }
    return s;
}

//@ ARR-04 | average (double - no integer division) | -
/********************************************************
 * nazwa funkcji: srednia
 * opis funkcji: oblicza średnią arytmetyczną elementów tablicy
 * parametry: tab - tablica liczb całkowitych
 *            n - liczba elementów tablicy
 * zwracany typ i opis: double - średnia elementów (0 dla pustej tablicy)
 * autor: <numer zdającego>
 ********************************************************/
double srednia(int tab[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s = s + tab[i];
    }
    return (double)s / n;
}

//@ ARR-05 | smallest element (minimum) | -
/********************************************************
 * nazwa funkcji: minimum
 * opis funkcji: wyszukuje najmniejszą wartość w tablicy
 * parametry: tab - tablica liczb całkowitych
 *            n - liczba elementów tablicy (co najmniej 1)
 * zwracany typ i opis: int - najmniejsza wartość
 * autor: <numer zdającego>
 ********************************************************/
int minimum(int tab[], int n)
{
    int min = tab[0];
    for (int i = 1; i < n; i++)
    {
        if (tab[i] < min)
        {
            min = tab[i];
        }
    }
    return min;
}

//@ ARR-06 | largest element (maximum) | -
/********************************************************
 * nazwa funkcji: maksimum
 * opis funkcji: wyszukuje największą wartość w tablicy
 * parametry: tab - tablica liczb całkowitych
 *            n - liczba elementów tablicy (co najmniej 1)
 * zwracany typ i opis: int - największa wartość
 * autor: <numer zdającego>
 ********************************************************/
int maksimum(int tab[], int n)
{
    int max = tab[0];
    for (int i = 1; i < n; i++)
    {
        if (tab[i] > max)
        {
            max = tab[i];
        }
    }
    return max;
}

//@ ARR-07 | min AND max in one pass, "returned" through & parameters ("wartosci ekstremalne") | -
/********************************************************
 * nazwa funkcji: znajdzEkstrema
 * opis funkcji: wyszukuje najmniejszą i największą wartość w tablicy
 * parametry: tab - tablica liczb całkowitych
 *            n - liczba elementów tablicy (co najmniej 1)
 *            min - (wyjście) najmniejsza wartość
 *            max - (wyjście) największa wartość
 * zwracany typ i opis: brak (wyniki przez parametry referencyjne min i max)
 * autor: <numer zdającego>
 ********************************************************/
void znajdzEkstrema(int tab[], int n, int &min, int &max)
{
    min = tab[0];
    max = tab[0];
    for (int i = 1; i < n; i++)
    {
        if (tab[i] < min)
        {
            min = tab[i];
        }
        if (tab[i] > max)
        {
            max = tab[i];
        }
    }
}

//@ ARR-08 | INDEX of the smallest element | -
/********************************************************
 * nazwa funkcji: indeksMinimum
 * opis funkcji: wyszukuje indeks najmniejszego elementu tablicy
 * parametry: tab - tablica liczb całkowitych
 *            n - liczba elementów tablicy (co najmniej 1)
 * zwracany typ i opis: int - indeks najmniejszego elementu (pierwszego, jeśli jest ich kilka)
 * autor: <numer zdającego>
 ********************************************************/
int indeksMinimum(int tab[], int n)
{
    int indeks = 0;
    for (int i = 1; i < n; i++)
    {
        if (tab[i] < tab[indeks])
        {
            indeks = i;
        }
    }
    return indeks;
}

//@ ARR-09 | INDEX of the largest element | -
/********************************************************
 * nazwa funkcji: indeksMaksimum
 * opis funkcji: wyszukuje indeks największego elementu tablicy
 * parametry: tab - tablica liczb całkowitych
 *            n - liczba elementów tablicy (co najmniej 1)
 * zwracany typ i opis: int - indeks największego elementu (pierwszego, jeśli jest ich kilka)
 * autor: <numer zdającego>
 ********************************************************/
int indeksMaksimum(int tab[], int n)
{
    int indeks = 0;
    for (int i = 1; i < n; i++)
    {
        if (tab[i] > tab[indeks])
        {
            indeks = i;
        }
    }
    return indeks;
}

//@ ARR-10 | product of all elements (long long - big results) | -
/********************************************************
 * nazwa funkcji: iloczyn
 * opis funkcji: oblicza iloczyn wszystkich elementów tablicy
 * parametry: tab - tablica liczb całkowitych
 *            n - liczba elementów tablicy
 * zwracany typ i opis: long long - iloczyn elementów
 * autor: <numer zdającego>
 ********************************************************/
long long iloczyn(int tab[], int n)
{
    long long wynik = 1;
    for (int i = 0; i < n; i++)
    {
        wynik = wynik * tab[i];
    }
    return wynik;
}

//@ ARR-11 | display values divisible by k AND return how many there are (exam wording) | <iostream>
/********************************************************
 * nazwa funkcji: wyswietlPodzielne
 * opis funkcji: wyświetla wartości tablicy podzielne przez podany dzielnik i zlicza je
 * parametry: tab - tablica liczb całkowitych
 *            n - liczba elementów tablicy
 *            dzielnik - liczba, przez którą sprawdzana jest podzielność
 * zwracany typ i opis: int - liczba wartości podzielnych przez dzielnik
 * autor: <numer zdającego>
 ********************************************************/
int wyswietlPodzielne(int tab[], int n, int dzielnik)
{
    int ile = 0;
    for (int i = 0; i < n; i++)
    {
        if (tab[i] % dzielnik == 0)
        {
            cout << tab[i] << " ";
            ile++;
        }
    }
    cout << endl;
    return ile;
}

//@ ARR-12 | count elements meeting a condition (here: even) - change the if for other conditions | -
/********************************************************
 * nazwa funkcji: zliczParzyste
 * opis funkcji: zlicza parzyste elementy tablicy
 * parametry: tab - tablica liczb całkowitych
 *            n - liczba elementów tablicy
 * zwracany typ i opis: int - liczba elementów parzystych
 * autor: <numer zdającego>
 ********************************************************/
int zliczParzyste(int tab[], int n)
{
    int ile = 0;
    for (int i = 0; i < n; i++)
    {
        if (tab[i] % 2 == 0)        // odd: != 0, bigger than x: tab[i] > x, ...
        {
            ile++;
        }
    }
    return ile;
}

//@ ARR-13 | linear search: index of the FIRST occurrence or -1 | -
/********************************************************
 * nazwa funkcji: wyszukajPierwszy
 * opis funkcji: wyszukuje pierwsze wystąpienie wartości w tablicy (wyszukiwanie liniowe)
 * parametry: tab - tablica liczb całkowitych
 *            n - liczba elementów tablicy
 *            szukana - szukana wartość
 * zwracany typ i opis: int - indeks znalezionego elementu lub -1, gdy go nie ma
 * autor: <numer zdającego>
 ********************************************************/
int wyszukajPierwszy(int tab[], int n, int szukana)
{
    for (int i = 0; i < n; i++)
    {
        if (tab[i] == szukana)
        {
            return i;
        }
    }
    return -1;
}

//@ ARR-14 | ALL occurrences: writes indexes into indeksy[], returns how many (0 -> print -1) (exam: "zwraca indeksy lub -1") | -
/********************************************************
 * nazwa funkcji: wyszukajWszystkie
 * opis funkcji: wyszukuje wszystkie wystąpienia wartości w tablicy i zapisuje ich indeksy
 *               w tablicy indeksy
 * parametry: tab - tablica liczb całkowitych
 *            n - liczba elementów tablicy
 *            szukana - szukana wartość
 *            indeksy - (wyjście) tablica na znalezione indeksy (rozmiar co najmniej n)
 * zwracany typ i opis: int - liczba znalezionych indeksów (0 - brak, wtedy wypisujemy -1)
 * autor: <numer zdającego>
 ********************************************************/
int wyszukajWszystkie(int tab[], int n, int szukana, int indeksy[])
{
    int ile = 0;
    for (int i = 0; i < n; i++)
    {
        if (tab[i] == szukana)
        {
            indeksy[ile] = i;
            ile++;
        }
    }
    return ile;
}
// use:  int ile = wyszukajWszystkie(tab, n, 8, indeksy);
//       if (ile == 0) { cout << -1; }  else  print indeksy[0] .. indeksy[ile - 1]

//@ ARR-15 | how many times a value occurs | -
/********************************************************
 * nazwa funkcji: zliczWystapienia
 * opis funkcji: zlicza, ile razy podana wartość występuje w tablicy
 * parametry: tab - tablica liczb całkowitych
 *            n - liczba elementów tablicy
 *            wartosc - zliczana wartość
 * zwracany typ i opis: int - liczba wystąpień
 * autor: <numer zdającego>
 ********************************************************/
int zliczWystapienia(int tab[], int n, int wartosc)
{
    int ile = 0;
    for (int i = 0; i < n; i++)
    {
        if (tab[i] == wartosc)
        {
            ile++;
        }
    }
    return ile;
}

//@ ARR-16 | SENTINEL search (wartownik): array needs ONE free slot after the data (size n + 1) | -
/********************************************************
 * nazwa funkcji: wyszukajZWartownikiem
 * opis funkcji: wyszukuje wartość metodą z wartownikiem - szukana wartość jest wstawiana
 *               za ostatni element, dzięki czemu pętla nie sprawdza końca tablicy
 * parametry: tab - tablica o rozmiarze co najmniej n + 1
 *            n - liczba elementów z danymi
 *            szukana - szukana wartość
 * zwracany typ i opis: int - indeks znalezionego elementu lub -1, gdy go nie ma
 * autor: <numer zdającego>
 ********************************************************/
int wyszukajZWartownikiem(int tab[], int n, int szukana)
{
    tab[n] = szukana;            // the sentinel
    int i = 0;
    while (tab[i] != szukana)
    {
        i++;
    }
    if (i == n)                  // stopped on the sentinel -> not found
    {
        return -1;
    }
    return i;
}

//@ ARR-17 | BINARY search - the array MUST be sorted ascending | -
/********************************************************
 * nazwa funkcji: wyszukajBinarnie
 * opis funkcji: wyszukuje wartość w posortowanej rosnąco tablicy metodą połowienia przedziału
 * parametry: tab - tablica posortowana rosnąco
 *            n - liczba elementów tablicy
 *            szukana - szukana wartość
 * zwracany typ i opis: int - indeks znalezionego elementu lub -1, gdy go nie ma
 * autor: <numer zdającego>
 ********************************************************/
int wyszukajBinarnie(int tab[], int n, int szukana)
{
    int lewy = 0;
    int prawy = n - 1;
    while (lewy <= prawy)
    {
        int srodek = (lewy + prawy) / 2;
        if (tab[srodek] == szukana)
        {
            return srodek;
        }
        if (tab[srodek] < szukana)
        {
            lewy = srodek + 1;
        }
        else
        {
            prawy = srodek - 1;
        }
    }
    return -1;
}

//@ ARR-18 | reverse the array in place (manual swap) | -
/********************************************************
 * nazwa funkcji: odwrocTablice
 * opis funkcji: odwraca kolejność elementów tablicy
 * parametry: tab - tablica liczb całkowitych
 *            n - liczba elementów tablicy
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void odwrocTablice(int tab[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int pomocnicza = tab[i];
        tab[i] = tab[n - 1 - i];
        tab[n - 1 - i] = pomocnicza;
    }
}

//@ ARR-19 | histogram: how many times each value min..max occurs (e.g. dice faces 1..6), prints it | <iostream>
/********************************************************
 * nazwa funkcji: zliczKazdaWartosc
 * opis funkcji: zlicza wystąpienia każdej wartości z przedziału min..max i je wyświetla
 * parametry: tab - tablica liczb całkowitych z przedziału min..max
 *            n - liczba elementów tablicy
 *            min - najmniejsza możliwa wartość
 *            max - największa możliwa wartość (max - min < 100)
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void zliczKazdaWartosc(int tab[], int n, int min, int max)
{
    int licznik[100];                    // licznik[w - min] = how many times w occurs
    for (int i = 0; i <= max - min; i++)
    {
        licznik[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        licznik[tab[i] - min]++;
    }
    for (int w = min; w <= max; w++)
    {
        cout << w << ": " << licznik[w - min] << endl;
    }
}

//@ ARR-20 | is the array sorted ascending? | -
/********************************************************
 * nazwa funkcji: czyPosortowana
 * opis funkcji: sprawdza, czy elementy tablicy są uporządkowane niemalejąco
 * parametry: tab - tablica liczb całkowitych
 *            n - liczba elementów tablicy
 * zwracany typ i opis: bool - true, gdy tablica jest posortowana rosnąco
 * autor: <numer zdającego>
 ********************************************************/
bool czyPosortowana(int tab[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (tab[i - 1] > tab[i])
        {
            return false;
        }
    }
    return true;
}

//@ ARR-21 | remove the element at an index (shift left, size decreases) | -
/********************************************************
 * nazwa funkcji: usunElement
 * opis funkcji: usuwa element o podanym indeksie, przesuwając dalsze elementy w lewo
 * parametry: tab - tablica liczb całkowitych
 *            n - (wejście/wyjście) liczba elementów, zmniejszana o 1
 *            indeks - indeks usuwanego elementu
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void usunElement(int tab[], int &n, int indeks)
{
    if (indeks < 0 || indeks >= n)
    {
        return;
    }
    for (int i = indeks; i < n - 1; i++)
    {
        tab[i] = tab[i + 1];
    }
    n--;
}

//@ ARR-22 | dynamic array: create with new[] and fill randomly (size given at runtime) - remember delete[] | <cstdlib> <ctime>
/********************************************************
 * nazwa funkcji: utworzTabliceLosowa
 * opis funkcji: tworzy tablicę dynamiczną o rozmiarze n i wypełnia ją losowo
 *               (wywołujący musi zwolnić pamięć: delete[] tab;)
 * parametry: n - liczba elementów
 *            min - najmniejsza losowana wartość
 *            max - największa losowana wartość
 * zwracany typ i opis: int* - wskaźnik na utworzoną tablicę
 * autor: <numer zdającego>
 ********************************************************/
int *utworzTabliceLosowa(int n, int min, int max)
{
    int *tab = new int[n];
    for (int i = 0; i < n; i++)
    {
        tab[i] = rand() % (max - min + 1) + min;
    }
    return tab;
}

//@ ARR-23 | 2D array: fill randomly, display as a grid, row sums (fixed number of columns) | <iostream> <cstdlib>
const int KOLUMNY = 4;     // number of columns must be a constant for int tab[][KOLUMNY]

/********************************************************
 * nazwa funkcji: wypelnijIWyswietl2D
 * opis funkcji: wypełnia tablicę dwuwymiarową liczbami losowymi 0..9, wyświetla ją
 *               wierszami i podaje sumę każdego wiersza
 * parametry: tab - tablica dwuwymiarowa o KOLUMNY kolumnach
 *            wiersze - liczba wierszy
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void wypelnijIWyswietl2D(int tab[][KOLUMNY], int wiersze)
{
    for (int w = 0; w < wiersze; w++)
    {
        int sumaWiersza = 0;
        for (int k = 0; k < KOLUMNY; k++)
        {
            tab[w][k] = rand() % 10;
            sumaWiersza = sumaWiersza + tab[w][k];
            cout << tab[w][k] << "\t";
        }
        cout << "| suma: " << sumaWiersza << endl;
    }
}

// ====================== DEMO (don't copy) ======================
int main()
{
    srand(time(0));
    const int N = 10;
    int tab[N + 1] = {4, 8, 15, 16, 23, 42, 8, 3, 8, 1};   // + 1 slot for the sentinel

    wyswietlTablice(tab, 3);
    wyswietlWLinii(tab, N);
    cout << "suma " << suma(tab, N) << ", srednia " << srednia(tab, N)
         << ", min " << minimum(tab, N) << ", max " << maksimum(tab, N)
         << ", iloczyn " << iloczyn(tab, N) << endl;
    int mn, mx;
    znajdzEkstrema(tab, N, mn, mx);
    cout << "ekstrema " << mn << " " << mx << ", indeks min " << indeksMinimum(tab, N)
         << ", indeks max " << indeksMaksimum(tab, N) << endl;
    cout << "podzielne przez 4: ";
    int ile = wyswietlPodzielne(tab, N, 4);
    cout << "ile: " << ile << ", parzystych: " << zliczParzyste(tab, N) << endl;

    int indeksy[N];
    cout << "pierwsze 8 -> " << wyszukajPierwszy(tab, N, 8) << ", wszystkie 8 ->";
    int ileIndeksow = wyszukajWszystkie(tab, N, 8, indeksy);
    for (int i = 0; i < ileIndeksow; i++)
    {
        cout << " " << indeksy[i];
    }
    cout << ", wszystkie 99 ->";
    ileIndeksow = wyszukajWszystkie(tab, N, 99, indeksy);
    if (ileIndeksow == 0)
    {
        cout << " -1";
    }
    cout << endl << "8 wystepuje " << zliczWystapienia(tab, N, 8) << " razy, wartownik 23 -> "
         << wyszukajZWartownikiem(tab, N, 23) << ", wartownik 7 -> " << wyszukajZWartownikiem(tab, N, 7) << endl;

    int posort[] = {1, 3, 5, 7, 9, 11};
    cout << "binarnie 9 -> " << wyszukajBinarnie(posort, 6, 9) << ", posortowana? " << czyPosortowana(posort, 6) << endl;

    odwrocTablice(tab, N);
    wyswietlWLinii(tab, N);
    int n = N;
    usunElement(tab, n, 0);
    wyswietlWLinii(tab, n);

    int kostki[] = {1, 6, 6, 2, 6, 1};
    zliczKazdaWartosc(kostki, 6, 1, 6);

    int *dyn = utworzTabliceLosowa(5, 1, 100);
    wyswietlWLinii(dyn, 5);
    delete[] dyn;

    int t2[3][KOLUMNY];
    wypelnijIWyswietl2D(t2, 3);
    return 0;
}
