// ======================================================================
// count numbers in a file, then read them into new int[]
// Original file: Libraries/Fstreamy/fstream1.cpp
// FIXED - the bug was: while(!eof()) loop miscounts
//
// fstream modes (fstream plik; plik.open("a.txt", TRYB);):
//   ios::in  - odczyt          ios::out - zapis (kasuje stara zawartosc)
//   ios::app - dopisywanie na koncu
// Prosciej: ifstream = odczyt, ofstream = zapis, ofstream(..., ios::app) = dopisywanie.
// ======================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // 1. pierwsze przejscie przez plik - tylko liczymy, ile jest liczb
    fstream plik;
    plik.open("numbers_input.txt", ios::in);
    if (!plik)
    {
        cout << "Nie mozna otworzyc pliku numbers_input.txt" << endl;
        return 1;
    }
    int liczba;
    int ile = 0;
    while (plik >> liczba)
    {
        ile++;
    }
    plik.close();

    // 2. tablica dynamiczna dokladnie na tyle liczb
    int *liczby = new int[ile];

    // 3. drugie przejscie - wczytanie do tablicy
    plik.open("numbers_input.txt", ios::in);
    for (int i = 0; i < ile; i++)
    {
        plik >> liczby[i];
    }
    plik.close();

    cout << "Wczytano " << ile << " liczb: ";
    for (int i = 0; i < ile; i++)
    {
        cout << liczby[i] << " ";
    }
    cout << endl;

    delete[] liczby;        // new[] -> delete[]
    return 0;
}
