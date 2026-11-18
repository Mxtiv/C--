// ======================================================================
// READY PROGRAM 15: files - write n random numbers to a file, read them back,
// display, min / max / sum / average, append the result to the file
// Based on: Libraries/ReadingFiles/maksik.cpp + unsorted/sprawdzian/fstreamKmak.cpp
// Blocks used: FILE-01, FILE-03, FILE-02, ARR-05, ARR-06, ARR-03, ARR-04, IO-01
// ======================================================================
//
// Treść zadania (wariant): Program pobiera liczbę n, zapisuje do pliku liczby.txt
// n liczb pseudolosowych z zakresu 1..100, następnie wczytuje liczby z pliku
// do tablicy, wyświetla je, oblicza sumę, średnią, wartość najmniejszą i największą
// i dopisuje podsumowanie na końcu pliku.

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_LICZB = 100;

/********************************************************
 * nazwa funkcji: zapiszLosoweDoPliku
 * opis funkcji: zapisuje do pliku n liczb pseudolosowych z przedziału min..max
 * parametry: nazwaPliku - nazwa pliku
 *            n - liczba liczb
 *            min, max - zakres losowania
 * zwracany typ i opis: bool - true, gdy zapis się udał
 * autor: <numer zdającego>
 ********************************************************/
bool zapiszLosoweDoPliku(string nazwaPliku, int n, int min, int max)
{
    ofstream plik(nazwaPliku);
    if (!plik.is_open())
    {
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        plik << rand() % (max - min + 1) + min << " ";
    }
    plik << endl;
    plik.close();
    return true;
}

/********************************************************
 * nazwa funkcji: wczytajLiczbyZPliku
 * opis funkcji: wczytuje liczby całkowite z pliku do tablicy (najwyżej MAX_LICZB)
 * parametry: nazwaPliku - nazwa pliku
 *            liczby - tablica, do której trafiają wczytane liczby
 * zwracany typ i opis: int - ile liczb wczytano
 * autor: <numer zdającego>
 ********************************************************/
int wczytajLiczbyZPliku(string nazwaPliku, int liczby[])
{
    ifstream plik(nazwaPliku);
    int ile = 0;
    int liczba;
    while (ile < MAX_LICZB && plik >> liczba)
    {
        liczby[ile] = liczba;
        ile++;
    }
    plik.close();
    return ile;
}

/********************************************************
 * nazwa funkcji: dopiszDoPliku
 * opis funkcji: dopisuje wiersz tekstu na końcu pliku
 * parametry: nazwaPliku - nazwa pliku
 *            tekst - dopisywany tekst
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void dopiszDoPliku(string nazwaPliku, string tekst)
{
    ofstream plik(nazwaPliku, ios::app);
    plik << tekst << endl;
    plik.close();
}

int main()
{
    srand(time(0));
    string nazwaPliku = "liczby.txt";

    int n;
    do
    {
        cout << "Ile liczb zapisac do pliku? (1-100): ";
        cin >> n;
    } while (n < 1 || n > MAX_LICZB);

    if (!zapiszLosoweDoPliku(nazwaPliku, n, 1, 100))
    {
        cout << "Nie udalo sie zapisac pliku!" << endl;
        return 1;
    }

    int liczby[MAX_LICZB];
    int ile = wczytajLiczbyZPliku(nazwaPliku, liczby);
    if (ile == 0)
    {
        cout << "Plik jest pusty!" << endl;
        return 1;
    }

    cout << "Liczby z pliku: ";
    int suma = 0;
    int min = liczby[0];
    int max = liczby[0];
    for (int i = 0; i < ile; i++)
    {
        cout << liczby[i] << " ";
        suma = suma + liczby[i];
        if (liczby[i] < min)
        {
            min = liczby[i];
        }
        if (liczby[i] > max)
        {
            max = liczby[i];
        }
    }
    double srednia = (double)suma / ile;

    cout << endl << "Suma: " << suma << ", srednia: " << srednia;
    cout << ", min: " << min << ", max: " << max << endl;

    dopiszDoPliku(nazwaPliku, "Suma: " + to_string(suma) + ", min: " + to_string(min) + ", max: " + to_string(max));
    cout << "Podsumowanie dopisano do pliku " << nazwaPliku << endl;
    return 0;
}
