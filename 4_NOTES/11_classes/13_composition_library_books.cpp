// ======================================================================
// Composition (kompozycja): class Biblioteka HAS books - an array of
// Ksiazka* created with new and freed with delete in the destructor.
// (despite the original file name, this is not a singleton)
// Original file: Singleton/librarySingleton.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

const int MAX_KSIAZEK = 10;

class Ksiazka
{
private:
    string tytul;
    string autor;
    bool wypozyczona;

public:
    Ksiazka(string nowyTytul, string nowyAutor)
    {
        tytul = nowyTytul;
        autor = nowyAutor;
        wypozyczona = false;
    }

    void wypozycz()
    {
        if (wypozyczona == false)
        {
            wypozyczona = true;
            cout << "Wypozyczono: " << tytul << endl;
        }
        else
        {
            cout << "Juz wypozyczona: " << tytul << endl;
        }
    }

    void wypisz()
    {
        cout << tytul << " - " << autor;
        if (wypozyczona)
        {
            cout << " [wypozyczona]" << endl;
        }
        else
        {
            cout << " [dostepna]" << endl;
        }
    }
};

class Biblioteka
{
private:
    Ksiazka *ksiazki[MAX_KSIAZEK];   // tablica wskaźników na książki
    int ile;                         // ile książek naprawdę jest

public:
    Biblioteka()
    {
        ile = 0;
    }

    // destruktor sprząta to, co utworzyło new
    ~Biblioteka()
    {
        for (int i = 0; i < ile; i++)
        {
            delete ksiazki[i];
        }
    }

    void dodaj(string tytul, string autor)
    {
        if (ile < MAX_KSIAZEK)
        {
            ksiazki[ile] = new Ksiazka(tytul, autor);
            ile++;
        }
        else
        {
            cout << "Biblioteka pelna!" << endl;
        }
    }

    void wypozycz(int numer)
    {
        if (numer >= 0 && numer < ile)
        {
            ksiazki[numer]->wypozycz();
        }
    }

    void wypisz()
    {
        for (int i = 0; i < ile; i++)
        {
            cout << i << ". ";
            ksiazki[i]->wypisz();
        }
    }
};

int main()
{
    Biblioteka biblioteka;
    biblioteka.dodaj("Rok 1984", "George Orwell");
    biblioteka.dodaj("Lalka", "Boleslaw Prus");
    biblioteka.dodaj("Pan Tadeusz", "Adam Mickiewicz");

    biblioteka.wypozycz(1);
    biblioteka.wypozycz(1);
    biblioteka.wypisz();

    return 0;
}   // tu destruktor Biblioteki usuwa książki
