// ======================================================================
// Constructors: default, with parameters, copy.
// The same constructor written two ways:
//   1) assignment in the body       <- write it like this at the exam
//   2) initializer list : pole(x)   <- you only need to RECOGNISE it
// Original file: Classes/konstruktory/listaInicjalizacyjna.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class Drzewo
{
private:
    bool czyIglaste;
    int obwodPnia;
    string nazwa;

public:
    // konstruktor domyślny
    Drzewo()
    {
        czyIglaste = false;
        obwodPnia = 0;
        nazwa = "brak";
    }

    // 1) konstruktor z parametrami - przypisanie w ciele (exam style)
    Drzewo(bool iglaste, int obwod, string nowaNazwa)
    {
        czyIglaste = iglaste;
        obwodPnia = obwod;
        nazwa = nowaNazwa;
    }

    // 2) TO SAMO z listą inicjalizacyjną (pola ustawione przed wejściem do { }):
    // Drzewo(bool iglaste, int obwod, string nowaNazwa) : czyIglaste(iglaste), obwodPnia(obwod), nazwa(nowaNazwa)
    // {
    // }

    void wypisz()
    {
        cout << "Nazwa: " << nazwa << ", iglaste: " << czyIglaste << ", obwod pnia: " << obwodPnia << endl;
    }
};

int main()
{
    Drzewo d1;                         // konstruktor domyślny
    d1.wypisz();

    Drzewo d2(true, 55, "sosna");      // konstruktor z parametrami
    d2.wypisz();

    Drzewo d3(d2);                     // kopiujący - kompilator tworzy go sam (kopiuje pola)
    d3.wypisz();

    return 0;
}
