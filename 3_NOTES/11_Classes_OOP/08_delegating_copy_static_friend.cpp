// ======================================================================
// Ksiazka: copy constructor, static counter (int Ksiazka::licznik = 0),
// friend function; delegating constructor shown in a comment only.
// Original file: Classes/ksiazka.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class Ksiazka
{
private:
    string tytul;
    string autor;
    int rokWydania;
    static int licznik;       // ile książek utworzono (wspólne dla wszystkich)

public:
    Ksiazka()
    {
        tytul = "brak";
        autor = "brak";
        rokWydania = 0;
        licznik++;
    }

    // Konstruktor delegujący = jeden konstruktor woła drugi (tylko do rozpoznania):
    // Ksiazka() : Ksiazka("brak", "brak", 0)
    // {
    // }

    Ksiazka(string nowyTytul, string nowyAutor, int rok)
    {
        tytul = nowyTytul;
        autor = nowyAutor;
        rokWydania = rok;
        licznik++;
    }

    // konstruktor kopiujący - parametr musi być referencją
    Ksiazka(const Ksiazka &wzor)
    {
        tytul = wzor.tytul;
        autor = wzor.autor;
        rokWydania = wzor.rokWydania;
        licznik++;
    }

    void wypisz()
    {
        cout << tytul << ", " << autor << ", " << rokWydania << endl;
    }

    static int getLicznik()
    {
        return licznik;
    }

    // funkcja zaprzyjaźniona - NIE jest metodą, ale widzi pola private
    friend Ksiazka cofnijRok(Ksiazka ksiazka, int ileLat);
};

int Ksiazka::licznik = 0;     // definicja pola static poza klasą

/********************************************************
 * nazwa funkcji: cofnijRok
 * opis funkcji: zwraca kopię książki z rokiem wydania mniejszym o ileLat
 * parametry: ksiazka - książka (kopia), ileLat - o ile lat cofnąć
 * zwracany typ i opis: Ksiazka - zmieniona kopia
 ********************************************************/
Ksiazka cofnijRok(Ksiazka ksiazka, int ileLat)
{
    ksiazka.rokWydania = ksiazka.rokWydania - ileLat;   // dostęp do private dzięki friend
    return ksiazka;
}

int main()
{
    Ksiazka k1("Balladyna", "Slowacki", 1839);
    Ksiazka k2 = k1;                       // konstruktor kopiujący
    Ksiazka k3 = cofnijRok(k1, 100);       // funkcja friend

    k1.wypisz();
    k2.wypisz();
    k3.wypisz();
    cout << "Utworzono ksiazek: " << Ksiazka::getLicznik() << endl;

    return 0;
}
