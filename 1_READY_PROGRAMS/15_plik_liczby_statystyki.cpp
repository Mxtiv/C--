// ======================================================================
// READY PROGRAM 15: files - write n random numbers to a file, read them back,
// display, min / max / sum / average, append the result to the file
// Based on: Libraries/ReadingFiles/maksik.cpp + unsorted/sprawdzian/fstreamKmak.cpp
// Blocks used: FILE-01, FILE-03, FILE-02, VEC-03, IO-01
// ======================================================================
//
// Treść zadania (wariant): Program pobiera liczbę n, zapisuje do pliku liczby.txt
// n liczb pseudolosowych z zakresu 1..100, następnie wczytuje liczby z pliku,
// wyświetla je, oblicza sumę, średnią, wartość najmniejszą i największą
// i dopisuje podsumowanie na końcu pliku.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

/********************************************************
 * nazwa funkcji: zapiszLosoweDoPliku
 * opis funkcji: zapisuje do pliku n liczb pseudolosowych z przedziału min..max
 * parametry: nazwaPliku - nazwa pliku
 *            n - liczba liczb
 *            min, max - zakres losowania
 * zwracany typ i opis: bool - true, gdy zapis się udał
 * autor: <numer zdającego>
 ********************************************************/
bool zapiszLosoweDoPliku(const string &nazwaPliku, int n, int min, int max)
{
    ofstream plik(nazwaPliku);
    if (!plik) return false;
    for (int i = 0; i < n; i++)
        plik << rand() % (max - min + 1) + min << " ";
    plik << endl;
    return true;
}

/********************************************************
 * nazwa funkcji: wczytajLiczbyZPliku
 * opis funkcji: wczytuje wszystkie liczby całkowite z pliku
 * parametry: nazwaPliku - nazwa pliku
 * zwracany typ i opis: vector<int> - wczytane liczby
 * autor: <numer zdającego>
 ********************************************************/
vector<int> wczytajLiczbyZPliku(const string &nazwaPliku)
{
    vector<int> liczby;
    ifstream plik(nazwaPliku);
    int x;
    while (plik >> x)
        liczby.push_back(x);
    return liczby;
}

/********************************************************
 * nazwa funkcji: dopiszDoPliku
 * opis funkcji: dopisuje wiersz tekstu na końcu pliku
 * parametry: nazwaPliku - nazwa pliku
 *            tekst - dopisywany tekst
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void dopiszDoPliku(const string &nazwaPliku, const string &tekst)
{
    ofstream plik(nazwaPliku, ios::app);
    plik << tekst << endl;
}

/********************************************************
 * nazwa funkcji: wczytajLiczbe
 * opis funkcji: wczytuje liczbę całkowitą z zakresu min..max, ponawiając pytanie przy błędzie
 * parametry: komunikat - tekst wyświetlany użytkownikowi
 *            min - najmniejsza dopuszczalna wartość
 *            max - największa dopuszczalna wartość
 * zwracany typ i opis: int - poprawna liczba
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
        cout << "Podaj liczbe od " << min << " do " << max << "." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main()
{
    srand(time(0));
    const string PLIK = "liczby.txt";

    int n = wczytajLiczbe("Ile liczb zapisac do pliku? (1-100): ", 1, 100);
    if (!zapiszLosoweDoPliku(PLIK, n, 1, 100))
    {
        cout << "Nie udalo sie zapisac pliku!" << endl;
        return 1;
    }

    vector<int> liczby = wczytajLiczbyZPliku(PLIK);
    cout << "Liczby z pliku: ";
    int suma = 0, min = liczby[0], max = liczby[0];
    for (int x : liczby)
    {
        cout << x << " ";
        suma += x;
        if (x < min) min = x;
        if (x > max) max = x;
    }
    double srednia = (double)suma / liczby.size();

    cout << endl << "Suma: " << suma << ", srednia: " << srednia
         << ", min: " << min << ", max: " << max << endl;

    dopiszDoPliku(PLIK, "Suma: " + to_string(suma) + ", min: " + to_string(min) + ", max: " + to_string(max));
    cout << "Podsumowanie dopisano do pliku " << PLIK << endl;
    return 0;
}
