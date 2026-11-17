// ======================================================================
// BUILDING BLOCKS: files (pliki) - write, append, read numbers, read lines,
// read "name;age;grade" records, check if a file exists
// HOW TO USE: copy the comment box + code under a //@ line, up to the next //@ line.
// File names without a folder are looked up next to where you RUN the .exe.
// ======================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

//@ FILE-01 | write an array to a text file (overwrites), numbers separated by spaces | <fstream> <string>
/********************************************************
 * nazwa funkcji: zapiszDoPliku
 * opis funkcji: zapisuje elementy tablicy do pliku tekstowego (nadpisuje plik)
 * parametry: nazwaPliku - nazwa pliku
 *            tab - tablica liczb
 *            n - liczba elementów tablicy
 * zwracany typ i opis: bool - true, gdy zapis się udał
 * autor: <numer zdającego>
 ********************************************************/
bool zapiszDoPliku(const string &nazwaPliku, const int tab[], int n)
{
    ofstream plik(nazwaPliku);
    if (!plik) return false;
    for (int i = 0; i < n; i++)
        plik << tab[i] << " ";
    plik << endl;
    return true;                 // file closes automatically at the end of the function
}

//@ FILE-02 | append one line at the END of a file (ios::app) | <fstream> <string>
/********************************************************
 * nazwa funkcji: dopiszDoPliku
 * opis funkcji: dopisuje wiersz tekstu na końcu pliku (plik jest tworzony, jeśli nie istnieje)
 * parametry: nazwaPliku - nazwa pliku
 *            tekst - dopisywany wiersz
 * zwracany typ i opis: bool - true, gdy zapis się udał
 * autor: <numer zdającego>
 ********************************************************/
bool dopiszDoPliku(const string &nazwaPliku, const string &tekst)
{
    ofstream plik(nazwaPliku, ios::app);
    if (!plik) return false;
    plik << tekst << endl;
    return true;
}

//@ FILE-03 | read ALL numbers from a file into a vector (correct loop: while (plik >> x)) | <fstream> <string> <vector> <iostream>
/********************************************************
 * nazwa funkcji: wczytajLiczbyZPliku
 * opis funkcji: wczytuje wszystkie liczby całkowite z pliku tekstowego
 * parametry: nazwaPliku - nazwa pliku
 * zwracany typ i opis: vector<int> - wczytane liczby (pusty, gdy pliku nie ma)
 * autor: <numer zdającego>
 ********************************************************/
vector<int> wczytajLiczbyZPliku(const string &nazwaPliku)
{
    vector<int> liczby;
    ifstream plik(nazwaPliku);
    if (!plik)
    {
        cerr << "Nie mozna otworzyc pliku " << nazwaPliku << endl;
        return liczby;
    }
    int x;
    while (plik >> x)            // NOT while (!plik.eof()) - that reads the last number twice
        liczby.push_back(x);
    return liczby;
}

//@ FILE-04 | read a file line by line into a vector<string> | <fstream> <string> <vector>
/********************************************************
 * nazwa funkcji: wczytajLinieZPliku
 * opis funkcji: wczytuje kolejne wiersze pliku tekstowego
 * parametry: nazwaPliku - nazwa pliku
 * zwracany typ i opis: vector<string> - wczytane wiersze (pusty, gdy pliku nie ma)
 * autor: <numer zdającego>
 ********************************************************/
vector<string> wczytajLinieZPliku(const string &nazwaPliku)
{
    vector<string> linie;
    ifstream plik(nazwaPliku);
    string linia;
    while (getline(plik, linia))
        linie.push_back(linia);
    return linie;
}

//@ FILE-05 | read records "name;age;grade" (one per line) into a vector of structs | <fstream> <sstream> <string> <vector>
/********************************************************
 * nazwa struktury: Rekord
 * opis struktury: jeden wiersz danych z pliku: imię, wiek, ocena
 * pola: imie, wiek, ocena
 * autor: <numer zdającego>
 ********************************************************/
struct Rekord
{
    string imie;
    int wiek;
    double ocena;
};

/********************************************************
 * nazwa funkcji: wczytajRekordy
 * opis funkcji: wczytuje z pliku wiersze w formacie imie;wiek;ocena
 * parametry: nazwaPliku - nazwa pliku
 * zwracany typ i opis: vector<Rekord> - wczytane rekordy
 * autor: <numer zdającego>
 ********************************************************/
vector<Rekord> wczytajRekordy(const string &nazwaPliku)
{
    vector<Rekord> rekordy;
    ifstream plik(nazwaPliku);
    string linia;
    while (getline(plik, linia))
    {
        stringstream ss(linia);
        string imie, wiek, ocena;
        if (getline(ss, imie, ';') && getline(ss, wiek, ';') && getline(ss, ocena, ';'))
            rekordy.push_back({imie, stoi(wiek), stod(ocena)});
    }
    return rekordy;
}

//@ FILE-06 | does a file exist (can it be opened)? | <fstream> <string>
/********************************************************
 * nazwa funkcji: czyPlikIstnieje
 * opis funkcji: sprawdza, czy plik o podanej nazwie można otworzyć do odczytu
 * parametry: nazwaPliku - nazwa pliku
 * zwracany typ i opis: bool - true, gdy plik istnieje
 * autor: <numer zdającego>
 ********************************************************/
bool czyPlikIstnieje(const string &nazwaPliku)
{
    ifstream plik(nazwaPliku);
    return plik.good();
}

// ====================== DEMO (don't copy) ======================
int main()
{
    int dane[] = {5, 10, 15, 20};
    zapiszDoPliku("demo_liczby.txt", dane, 4);
    vector<int> liczby = wczytajLiczbyZPliku("demo_liczby.txt");
    cout << "wczytano " << liczby.size() << " liczb:";
    for (int x : liczby) cout << " " << x;
    cout << endl;

    ofstream("demo_uczniowie.txt") << "Jan;17;4.5\nAnna;18;5.0\n";
    dopiszDoPliku("demo_uczniowie.txt", "Ola;16;3.5");
    for (const string &l : wczytajLinieZPliku("demo_uczniowie.txt")) cout << "linia: " << l << endl;
    for (const Rekord &r : wczytajRekordy("demo_uczniowie.txt")) cout << r.imie << " " << r.wiek << " " << r.ocena << endl;
    cout << boolalpha << "istnieje? " << czyPlikIstnieje("demo_liczby.txt") << ", brak.txt? " << czyPlikIstnieje("brak.txt") << endl;
    return 0;
}
