// ======================================================================
// INF.04-02-24.06-SG - wczytanie albumów z pliku Data.txt do tablicy i wyświetlenie ich.
// Rekord = 5 linii (artist, "album", songsNumber, year, downloadNumber) + pusta linia.
// Struktura: 2 napisy + 3 liczby całkowite (int = 32 bity, max 1 506 404 300 się mieści).
// Wczytanie i wyświetlenie w osobnych funkcjach; pętla czyta tyle rekordów, ile jest w pliku.
// Data.txt must be in the working folder (VS: next to the .vcxproj; g++: where you run it).
// Spec + key checklist: README.md in this folder.
// ======================================================================
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAKS_ALBUMOW = 100;

struct Album
{
    string artysta;
    string album;
    int liczbaUtworow;
    int rok;
    int liczbaPobran;             // int ma 32 bity - wystarczy do 2 147 483 647
};

// usuwa znak '\r' z końca linii (plik ma końce linii Windows)
// i 3 znaki BOM UTF-8 z początku pliku
string oczyscLinie(string linia)
{
    int dlugosc = linia.length();
    if (dlugosc > 0 && linia[dlugosc - 1] == '\r')
    {
        linia = linia.substr(0, dlugosc - 1);
    }
    if (linia.length() >= 3 && linia[0] == (char)0xEF)
    {
        linia = linia.substr(3);
    }
    return linia;
}

/**********************************************
nazwa funkcji:  wczytajAlbumy
opis funkcji:   czyta z pliku kolejne rekordy (5 linii + pusta linia) i zapisuje je do tablicy
parametry:      nazwaPliku - ścieżka do pliku z danymi
                albumy - tablica, do której zapisywane są wczytane albumy
zwracany typ i opis: int - liczba wczytanych albumów (0, gdy brak pliku)
autor:          00000000000
***********************************************/
int wczytajAlbumy(string nazwaPliku, Album albumy[])
{
    ifstream plik(nazwaPliku);
    if (!plik.is_open())
    {
        cout << "Nie mozna otworzyc pliku " << nazwaPliku << endl;
        return 0;
    }
    int ile = 0;
    string linia;
    while (ile < MAKS_ALBUMOW && getline(plik, linia))
    {
        linia = oczyscLinie(linia);
        if (linia != "")                      // pusta linia między rekordami jest pomijana
        {
            albumy[ile].artysta = linia;
            getline(plik, linia);
            albumy[ile].album = oczyscLinie(linia);
            getline(plik, linia);
            albumy[ile].liczbaUtworow = stoi(linia);
            getline(plik, linia);
            albumy[ile].rok = stoi(linia);
            getline(plik, linia);
            albumy[ile].liczbaPobran = stoi(linia);
            ile++;
        }
    }
    plik.close();
    return ile;
}

void wyswietlAlbumy(Album albumy[], int ile)
{
    for (int i = 0; i < ile; i++)
    {
        cout << albumy[i].artysta << endl;
        cout << albumy[i].album << endl;
        cout << albumy[i].liczbaUtworow << endl;
        cout << albumy[i].rok << endl;
        cout << albumy[i].liczbaPobran << endl;
        cout << endl;
    }
}

int main()
{
    Album albumy[MAKS_ALBUMOW];
    int ile = wczytajAlbumy("Data.txt", albumy);
    wyswietlAlbumy(albumy, ile);
    cout << "Wczytano albumow: " << ile << endl;
    return 0;
}
