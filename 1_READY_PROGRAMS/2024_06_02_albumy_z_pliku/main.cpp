// ======================================================================
// INF.04-02-24.06-SG - wczytanie albumów z pliku Data.txt do kolekcji i wyświetlenie ich.
// Rekord = 5 linii (artist, "album", songsNumber, year, downloadNumber) + pusta linia.
// Klasa/struktura: 2 napisy + 3 liczby całkowite (pobrania >= 32 bit: max 1 506 404 300).
// Wczytanie i wyświetlenie w osobnych funkcjach; działa dla dowolnej liczby rekordów.
// Data.txt must be in the working folder (VS: next to the .vcxproj; g++: where you run it).
// Spec + key checklist: README.md in this folder.
// ======================================================================
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Album
{
    string artysta;
    string album;
    int liczbaUtworow;
    int rok;
    long long liczbaPobran;       // 64 bit - bezpiecznie (int też by wystarczył)
};

// usuwa \r (plik ma końce linii Windows) i znak BOM UTF-8 na początku pliku
string oczysc(string linia)
{
    if (linia.size() >= 3 && (unsigned char)linia[0] == 0xEF && (unsigned char)linia[1] == 0xBB && (unsigned char)linia[2] == 0xBF)
    {
        linia = linia.substr(3);
    }
    if (!linia.empty() && linia.back() == '\r')
    {
        linia.pop_back();
    }
    return linia;
}

/**********************************************
nazwa funkcji:  wczytajAlbumy
opis funkcji:   czyta z pliku kolejne rekordy (5 linii + pusta linia) i zapisuje je do wektora
parametry:      nazwaPliku - ścieżka do pliku z danymi
zwracany typ i opis: vector<Album> - wszystkie wczytane albumy (pusty, gdy brak pliku)
autor:          00000000000
***********************************************/
vector<Album> wczytajAlbumy(string nazwaPliku)
{
    vector<Album> albumy;
    ifstream plik(nazwaPliku);
    if (!plik.is_open())
    {
        cout << "Nie mozna otworzyc pliku " << nazwaPliku << endl;
        return albumy;
    }
    string linia;
    while (getline(plik, linia))
    {
        linia = oczysc(linia);
        if (linia == "")
        {
            continue;                         // pusta linia między rekordami
        }
        Album nowy;
        nowy.artysta = linia;
        getline(plik, linia);
        nowy.album = oczysc(linia);
        getline(plik, linia);
        nowy.liczbaUtworow = stoi(oczysc(linia));
        getline(plik, linia);
        nowy.rok = stoi(oczysc(linia));
        getline(plik, linia);
        nowy.liczbaPobran = stoll(oczysc(linia));
        albumy.push_back(nowy);
    }
    plik.close();
    return albumy;
}

void wyswietlAlbumy(const vector<Album> &albumy)
{
    for (int i = 0; i < (int)albumy.size(); i++)
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
    vector<Album> albumy = wczytajAlbumy("Data.txt");
    wyswietlAlbumy(albumy);
    cout << "Wczytano albumow: " << albumy.size() << endl;
    return 0;
}
