// ======================================================================
// INF.04-01-25.01-SG - klasa z tablicą: pola PRIVATE (tablica + faktyczna liczba elementów),
// konstruktor(rozmiar) losuje 1..1000; metody public: wyświetl "<i>: <wartość>",
// szukaj (indeks lub -1), nieparzyste (wyświetla + zwraca ile), średnia.
// Program główny: rozmiar > 20, test wszystkich metod. Spec + key: README.md
// ======================================================================
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Tablica
{
private:                        // tylko ta klasa, niedostępne dla klas potomnych
    int *tablica;               // tradycyjna tablica (dynamiczna - rozmiar z konstruktora)
    int liczbaElementow;

public:
    Tablica(int rozmiar)
    {
        liczbaElementow = rozmiar;
        tablica = new int[liczbaElementow];
        for (int i = 0; i < liczbaElementow; i++)
        {
            tablica[i] = rand() % 1000 + 1;
        }
    }

    ~Tablica()
    {
        delete[] tablica;
    }

    void wyswietl()
    {
        for (int i = 0; i < liczbaElementow; i++)
        {
            cout << i << ": " << tablica[i] << endl;
        }
    }

    /**********************************************
    nazwa metody:  szukaj
    opis metody:   wyszukuje pierwsze wystąpienie podanej wartości w tablicy
    parametry:     wartosc - liczba, której szukamy
    zwracany typ i opis: int - indeks pierwszego wystąpienia lub -1, gdy nie znaleziono
    autor:         00000000000
    ***********************************************/
    int szukaj(int wartosc)
    {
        for (int i = 0; i < liczbaElementow; i++)
        {
            if (tablica[i] == wartosc)
            {
                return i;
            }
        }
        return -1;
    }

    int wyswietlNieparzyste()
    {
        int ile = 0;
        for (int i = 0; i < liczbaElementow; i++)
        {
            if (tablica[i] % 2 != 0)
            {
                cout << tablica[i] << " ";
                ile++;
            }
        }
        cout << endl;
        return ile;
    }

    double srednia()
    {
        double suma = 0;
        for (int i = 0; i < liczbaElementow; i++)
        {
            suma = suma + tablica[i];
        }
        return suma / liczbaElementow;
    }
};

int main()
{
    srand((unsigned)time(0));
    Tablica tablica(25);

    cout << "Elementy tablicy:" << endl;
    tablica.wyswietl();

    int szukana;
    cout << "Podaj liczbe do wyszukania: ";
    cin >> szukana;
    int indeks = tablica.szukaj(szukana);
    if (indeks != -1)
    {
        cout << "Liczba " << szukana << " znajduje sie pod indeksem " << indeks << endl;
    }

    cout << "Liczby nieparzyste: ";
    int ileNieparzystych = tablica.wyswietlNieparzyste();
    cout << "Liczba wartosci nieparzystych: " << ileNieparzystych << endl;

    cout << "Srednia wartosci: " << tablica.srednia() << endl;
    return 0;
}
