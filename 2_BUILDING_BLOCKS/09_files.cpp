// ======================================================================
// BUILDING BLOCKS: files (pliki) - write, append, read numbers, read lines,
// read "name;age;grade" records, check if a file exists
// HOW TO USE: copy the comment box + code under a //@ line, up to the next //@ line.
// File names without a folder are looked up next to where you RUN the .exe.
// Reading functions fill a plain array and return how many elements they read.
// ======================================================================

#include <iostream>
#include <fstream>
#include <string>
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
bool zapiszDoPliku(string nazwaPliku, int tab[], int n)
{
    ofstream plik(nazwaPliku);
    if (!plik)
    {
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        plik << tab[i] << " ";
    }
    plik << endl;
    plik.close();
    return true;
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
bool dopiszDoPliku(string nazwaPliku, string tekst)
{
    ofstream plik(nazwaPliku, ios::app);
    if (!plik)
    {
        return false;
    }
    plik << tekst << endl;
    plik.close();
    return true;
}

//@ FILE-03 | read ALL numbers from a file into an int array, returns how many (loop: while (plik >> x)) | <iostream> <fstream> <string>
/********************************************************
 * nazwa funkcji: wczytajLiczbyZPliku
 * opis funkcji: wczytuje wszystkie liczby całkowite z pliku tekstowego do tablicy
 * parametry: nazwaPliku - nazwa pliku
 *            liczby - tablica na liczby (musi być dość duża, np. int liczby[100])
 * zwracany typ i opis: int - liczba wczytanych liczb (0, gdy pliku nie ma)
 * autor: <numer zdającego>
 ********************************************************/
int wczytajLiczbyZPliku(string nazwaPliku, int liczby[])
{
    ifstream plik(nazwaPliku);
    if (!plik)
    {
        cout << "Nie mozna otworzyc pliku " << nazwaPliku << endl;
        return 0;
    }
    int ile = 0;
    int x;
    while (plik >> x)            // NOT while (!plik.eof()) - that reads the last number twice
    {
        liczby[ile] = x;
        ile++;
    }
    plik.close();
    return ile;
}

//@ FILE-04 | read a file line by line into a string array, returns how many lines | <fstream> <string>
/********************************************************
 * nazwa funkcji: wczytajLinieZPliku
 * opis funkcji: wczytuje kolejne wiersze pliku tekstowego do tablicy
 * parametry: nazwaPliku - nazwa pliku
 *            linie - tablica na wiersze (musi być dość duża, np. string linie[100])
 * zwracany typ i opis: int - liczba wczytanych wierszy (0, gdy pliku nie ma)
 * autor: <numer zdającego>
 ********************************************************/
int wczytajLinieZPliku(string nazwaPliku, string linie[])
{
    ifstream plik(nazwaPliku);
    int ile = 0;
    string linia;
    while (getline(plik, linia))
    {
        linie[ile] = linia;
        ile++;
    }
    plik.close();
    return ile;
}

//@ FILE-05 | read records "name;age;grade" (one per line) into an array of structs - getline(plik, pole, ';') | <fstream> <string>
/********************************************************
 * nazwa struktury: Rekord
 * opis struktury: jeden wiersz danych z pliku: imię, wiek, ocena
 * pola: imie - imię
 *       wiek - wiek w latach
 *       ocena - ocena
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
 * opis funkcji: wczytuje z pliku wiersze w formacie imie;wiek;ocena do tablicy struktur
 * parametry: nazwaPliku - nazwa pliku
 *            rekordy - tablica na rekordy (musi być dość duża, np. Rekord rekordy[100])
 * zwracany typ i opis: int - liczba wczytanych rekordów
 * autor: <numer zdającego>
 ********************************************************/
int wczytajRekordy(string nazwaPliku, Rekord rekordy[])
{
    ifstream plik(nazwaPliku);
    int ile = 0;
    string imie;
    string wiek;
    string ocena;
    while (getline(plik, imie, ';'))     // reads up to the first ';'
    {
        getline(plik, wiek, ';');        // up to the second ';'
        getline(plik, ocena);            // the rest of the line
        rekordy[ile].imie = imie;
        rekordy[ile].wiek = stoi(wiek);
        rekordy[ile].ocena = stod(ocena);
        ile++;
    }
    plik.close();
    return ile;
}

//@ FILE-06 | does a file exist (can it be opened)? | <fstream> <string>
/********************************************************
 * nazwa funkcji: czyPlikIstnieje
 * opis funkcji: sprawdza, czy plik o podanej nazwie można otworzyć do odczytu
 * parametry: nazwaPliku - nazwa pliku
 * zwracany typ i opis: bool - true, gdy plik istnieje
 * autor: <numer zdającego>
 ********************************************************/
bool czyPlikIstnieje(string nazwaPliku)
{
    ifstream plik(nazwaPliku);
    if (plik.is_open())
    {
        plik.close();
        return true;
    }
    return false;
}

// ====================== DEMO (don't copy) ======================
int main()
{
    int dane[4] = {5, 10, 15, 20};
    zapiszDoPliku("demo_liczby.txt", dane, 4);
    int liczby[100];
    int ileLiczb = wczytajLiczbyZPliku("demo_liczby.txt", liczby);
    cout << "wczytano " << ileLiczb << " liczb:";
    for (int i = 0; i < ileLiczb; i++)
    {
        cout << " " << liczby[i];
    }
    cout << endl;

    ofstream plik("demo_uczniowie.txt");
    plik << "Jan;17;4.5" << endl;
    plik << "Anna;18;5.0" << endl;
    plik.close();
    dopiszDoPliku("demo_uczniowie.txt", "Ola;16;3.5");

    string linie[100];
    int ileLinii = wczytajLinieZPliku("demo_uczniowie.txt", linie);
    for (int i = 0; i < ileLinii; i++)
    {
        cout << "linia: " << linie[i] << endl;
    }

    Rekord rekordy[100];
    int ileRekordow = wczytajRekordy("demo_uczniowie.txt", rekordy);
    for (int i = 0; i < ileRekordow; i++)
    {
        cout << rekordy[i].imie << " " << rekordy[i].wiek << " " << rekordy[i].ocena << endl;
    }

    cout << "istnieje? " << czyPlikIstnieje("demo_liczby.txt") << ", brak.txt? " << czyPlikIstnieje("brak.txt") << endl;
    return 0;
}
