// ======================================================================
// READY PROGRAM 01: class holding an array - display "i: value", search returning
// the indexes or -1, values divisible by k (display + count), product, min/max,
// average. THE most common INF.04 C++ task (your groups A and B).
// Original file: inf04/8)Duckman.cpp + inf04/11)grb.cpp + inf04/1)ArraysClasses.cpp
// Blocks used: CLS-03, ARR-01, ARR-14, ARR-11, ARR-10, ARR-07, ARR-04, IO-01
// To adapt: change the divisor (3 / 7), the random range, the size, the wording.
// ======================================================================
//
// Założenia aplikacji (treść zadania):
// - Tablica oraz operacje na niej są zaimplementowane z wykorzystaniem klasy
// - Pola klasy: tablica liczb całkowitych (tradycyjna tablica) oraz liczba elementów
//   tablicy; oba pola dostępne tylko w tej klasie i niedostępne dla klas potomnych
// - Konstruktor: przyjmuje rozmiar tablicy, ustawia pole liczby elementów i wypełnia
//   tablicę pseudolosowymi liczbami całkowitymi z zakresu od 1 do 6
// - Metody:
//   * wyświetlająca wszystkie elementy w postaci „<indeks_tablicy>: <wartość>”
//   * wyszukująca wszystkie wystąpienia wartości przekazanej jako argument; zwraca
//     indeksy szukanego elementu lub -1, gdy elementu nie znaleziono
//   * wyświetlająca wszystkie wartości podzielne przez 3 i zwracająca ich liczbę
//   * licząca iloczyn wartości w tablicy i zwracająca tę wartość
//   * znajdująca wartości ekstremalne i zwracająca je
// - Program główny: tworzy obiekt z rozmiarem tablicy większym od 10 i sprawdza
//   działanie wszystkich metod; komunikacja z użytkownikiem musi być zrozumiała

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
using namespace std;

/********************************************************
 * nazwa klasy: Tablica
 * opis klasy: przechowuje tablicę liczb całkowitych wypełnioną losowo (1..6)
 *             i udostępnia operacje na niej
 * pola: tab - wskaźnik na dynamiczną tablicę liczb całkowitych
 *       rozmiar - faktyczna liczba elementów tablicy
 * autor: <numer zdającego>
 ********************************************************/
class Tablica
{
private:
    int *tab;
    int rozmiar;

public:
    /********************************************************
     * nazwa funkcji: Tablica (konstruktor)
     * opis funkcji: ustawia liczbę elementów i wypełnia tablicę liczbami
     *               pseudolosowymi z zakresu 1..6
     * parametry: n - rozmiar tablicy
     * zwracany typ i opis: brak
     * autor: <numer zdającego>
     ********************************************************/
    Tablica(int n) : tab(new int[n]), rozmiar(n)
    {
        for (int i = 0; i < rozmiar; i++)
            tab[i] = rand() % 6 + 1;
    }

    ~Tablica()
    {
        delete[] tab;
    }

    Tablica(const Tablica &) = delete;
    Tablica &operator=(const Tablica &) = delete;

    /********************************************************
     * nazwa funkcji: wyswietl
     * opis funkcji: wyświetla wszystkie elementy tablicy w postaci "<indeks>: <wartość>"
     * parametry: brak
     * zwracany typ i opis: brak
     * autor: <numer zdającego>
     ********************************************************/
    void wyswietl() const
    {
        for (int i = 0; i < rozmiar; i++)
            cout << i << ": " << tab[i] << endl;
    }

    /********************************************************
     * nazwa funkcji: wyszukaj
     * opis funkcji: wyszukuje wszystkie wystąpienia podanej wartości w tablicy
     * parametry: szukana - szukana wartość
     * zwracany typ i opis: vector<int> - indeksy znalezionych elementów lub {-1},
     *                      gdy elementu nie znaleziono
     * autor: <numer zdającego>
     ********************************************************/
    vector<int> wyszukaj(int szukana) const
    {
        vector<int> indeksy;
        for (int i = 0; i < rozmiar; i++)
            if (tab[i] == szukana)
                indeksy.push_back(i);
        if (indeksy.empty())
            indeksy.push_back(-1);
        return indeksy;
    }

    /********************************************************
     * nazwa funkcji: wyswietlPodzielne
     * opis funkcji: wyświetla wszystkie wartości podzielne przez dzielnik i zlicza je
     * parametry: dzielnik - liczba, przez którą sprawdzana jest podzielność
     * zwracany typ i opis: int - liczba wartości podzielnych przez dzielnik
     * autor: <numer zdającego>
     ********************************************************/
    int wyswietlPodzielne(int dzielnik) const
    {
        int ile = 0;
        for (int i = 0; i < rozmiar; i++)
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

    /********************************************************
     * nazwa funkcji: iloczyn
     * opis funkcji: oblicza iloczyn wszystkich wartości w tablicy
     * parametry: brak
     * zwracany typ i opis: long long - iloczyn elementów tablicy
     * autor: <numer zdającego>
     ********************************************************/
    long long iloczyn() const
    {
        long long wynik = 1;
        for (int i = 0; i < rozmiar; i++)
            wynik *= tab[i];
        return wynik;
    }

    /********************************************************
     * nazwa funkcji: znajdzEkstrema
     * opis funkcji: wyszukuje wartość najmniejszą i największą w tablicy
     * parametry: min - (wyjście) wartość najmniejsza
     *            max - (wyjście) wartość największa
     * zwracany typ i opis: brak (wartości zwracane przez parametry referencyjne)
     * autor: <numer zdającego>
     ********************************************************/
    void znajdzEkstrema(int &min, int &max) const
    {
        min = max = tab[0];
        for (int i = 1; i < rozmiar; i++)
        {
            if (tab[i] < min) min = tab[i];
            if (tab[i] > max) max = tab[i];
        }
    }

    /********************************************************
     * nazwa funkcji: srednia
     * opis funkcji: oblicza średnią arytmetyczną wartości w tablicy
     * parametry: brak
     * zwracany typ i opis: double - średnia elementów
     * autor: <numer zdającego>
     ********************************************************/
    double srednia() const
    {
        int suma = 0;
        for (int i = 0; i < rozmiar; i++)
            suma += tab[i];
        return (double)suma / rozmiar;
    }
};

/********************************************************
 * nazwa funkcji: wczytajLiczbe
 * opis funkcji: wczytuje liczbę całkowitą z zakresu min..max, ponawiając pytanie przy błędzie
 * parametry: komunikat - tekst wyświetlany użytkownikowi
 *            min - najmniejsza dopuszczalna wartość
 *            max - największa dopuszczalna wartość
 * zwracany typ i opis: int - poprawna liczba podana przez użytkownika
 * autor: <numer zdającego>
 ********************************************************/
int wczytajLiczbe(const string &komunikat, int min, int max)
{
    int liczba;
    while (true)
    {
        cout << komunikat;
        if (cin >> liczba && liczba >= min && liczba <= max)
            return liczba;
        cout << "Niepoprawna wartosc. Podaj liczbe od " << min << " do " << max << "." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main()
{
    srand(time(0));

    Tablica tablica(15);                      // size bigger than 10

    cout << "Elementy tablicy:" << endl;
    tablica.wyswietl();

    int szukana = wczytajLiczbe("\nPodaj wartosc do wyszukania (1-6): ", 1, 6);
    vector<int> indeksy = tablica.wyszukaj(szukana);
    if (indeksy[0] == -1)
        cout << "Nie znaleziono wartosci " << szukana << " (wynik: -1)" << endl;
    else
    {
        cout << "Wartosc " << szukana << " znajduje sie pod indeksami: ";
        for (int i : indeksy) cout << i << " ";
        cout << endl;
    }

    cout << "\nWartosci podzielne przez 3: ";
    int ile = tablica.wyswietlPodzielne(3);
    cout << "Liczba wartosci podzielnych przez 3: " << ile << endl;

    cout << "\nIloczyn wartosci: " << tablica.iloczyn() << endl;

    int min, max;
    tablica.znajdzEkstrema(min, max);
    cout << "Wartosc najmniejsza: " << min << ", wartosc najwieksza: " << max << endl;
    cout << "Srednia: " << tablica.srednia() << endl;

    return 0;
}
