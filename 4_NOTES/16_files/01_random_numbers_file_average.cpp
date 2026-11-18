// ======================================================================
// ofstream write, if (!plik) check, while (plik >> x) read into an array, average
// Original file: Libraries/ReadingFiles/maksik.cpp
// FIXED: removed the extra srand() calls inside the loop (srand once is enough)
// ======================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROZMIAR = 100;

/********************************************************
 * nazwa funkcji: zapiszLosoweDoPliku
 * opis funkcji: zapisuje n losowych liczb z zakresu min..max do pliku
 * parametry: n - ile liczb, min - najmniejsza, max - najwieksza
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void zapiszLosoweDoPliku(int n, int min, int max)
{
    ofstream plik("wyjscie.txt");       // ofstream = zapis, tworzy / nadpisuje plik
    if (!plik)                          // ZAWSZE sprawdz, czy plik sie otworzyl
    {
        cout << "Nie mozna otworzyc pliku do zapisu" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        int liczba = rand() % (max - min + 1) + min;
        plik << liczba << " ";
    }
    plik.close();
}

/********************************************************
 * nazwa funkcji: wczytajZPliku
 * opis funkcji: wczytuje liczby z pliku do tablicy
 * parametry: tab - tablica na liczby
 * zwracany typ i opis: int - ile liczb wczytano
 * autor: <numer zdającego>
 ********************************************************/
int wczytajZPliku(int tab[])
{
    ifstream plik("wyjscie.txt");       // ifstream = odczyt
    if (!plik)
    {
        cout << "Nie mozna otworzyc pliku do odczytu" << endl;
        return 0;
    }

    int ile = 0;
    int liczba;
    while (ile < ROZMIAR && plik >> liczba)   // poprawna petla - konczy sie dokladnie na koncu danych
    {
        tab[ile] = liczba;
        ile++;
    }
    plik.close();
    return ile;
}

/********************************************************
 * nazwa funkcji: srednia
 * opis funkcji: liczy srednia arytmetyczna elementow tablicy
 * parametry: tab - tablica liczb, n - liczba elementow
 * zwracany typ i opis: double - srednia (0 dla pustej tablicy)
 * autor: <numer zdającego>
 ********************************************************/
double srednia(int tab[], int n)
{
    if (n == 0)
    {
        return 0;
    }

    int suma = 0;
    for (int i = 0; i < n; i++)
    {
        suma = suma + tab[i];
    }
    return (double)suma / n;
}

int main()
{
    srand(time(0));

    int ileLiczb, min, max;
    do
    {
        cout << "Ile liczb wylosowac (1-100): ";
        cin >> ileLiczb;
    } while (ileLiczb < 1 || ileLiczb > ROZMIAR);
    cout << "Podaj minimum: ";
    cin >> min;
    do
    {
        cout << "Podaj maksimum (>= minimum): ";
        cin >> max;
    } while (max < min);

    zapiszLosoweDoPliku(ileLiczb, min, max);

    int liczby[ROZMIAR];
    int ile = wczytajZPliku(liczby);

    cout << "Liczby z pliku: ";
    for (int i = 0; i < ile; i++)
    {
        cout << liczby[i] << " ";
    }
    cout << endl;
    cout << "Srednia: " << srednia(liczby, ile) << endl;

    return 0;
}
