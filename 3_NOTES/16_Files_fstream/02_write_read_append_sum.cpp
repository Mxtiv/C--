// ======================================================================
// write numbers, read them and sum, APPEND the sum with ios::app,
// then read the whole file line by line with getline
// Original file: unsorted/sprawdzian/fstreamKmak.cpp
// FIXED - the bugs were: fstream without a mode (fails if the file does not exist) -> ofstream; srand() inside the loop
// ======================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));

    // 1. zapis - ofstream tworzy plik (albo czysci stary)
    ofstream zapis("wyjscie.txt");
    if (!zapis)
    {
        cout << "Nie mozna otworzyc pliku" << endl;
        return 1;
    }
    for (int i = 0; i < 10; i++)
    {
        zapis << rand() % 100 + 1 << " ";
    }
    zapis << endl;
    zapis.close();

    // 2. odczyt liczb - while (plik >> x), NIE while (!plik.eof())
    ifstream odczyt("wyjscie.txt");
    int liczba;
    int suma = 0;
    while (odczyt >> liczba)
    {
        suma = suma + liczba;
    }
    odczyt.close();
    cout << "Suma: " << suma << endl;

    // 3. dopisanie na koncu - ios::app nie kasuje tego, co juz jest w pliku
    ofstream dopisz("wyjscie.txt", ios::app);
    dopisz << "Suma: " << suma << endl;
    dopisz.close();

    // 4. odczyt calych linii
    ifstream linie("wyjscie.txt");
    string linia;
    cout << "Zawartosc pliku:" << endl;
    while (getline(linie, linia))
    {
        cout << linia << endl;
    }
    linie.close();

    return 0;
}
