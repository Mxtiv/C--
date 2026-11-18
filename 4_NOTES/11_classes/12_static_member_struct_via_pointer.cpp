// ======================================================================
// static field whose type is a struct; using an object through a pointer
// with -> (wskaznik->metoda() is the same as (*wskaznik).metoda()).
// Original file: unsorted/various/obslugaPrzezPointer.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

struct Data
{
    int dzien;
    int miesiac;
    int rok;
};

class Pracownik
{
private:
    string imie;
    static Data dataZatrudnienia;    // jedna data wspólna dla wszystkich pracowników

public:
    void setImie(string noweImie)
    {
        imie = noweImie;
    }

    static void setData(int dzien, int miesiac, int rok)
    {
        dataZatrudnienia.dzien = dzien;
        dataZatrudnienia.miesiac = miesiac;
        dataZatrudnienia.rok = rok;
    }

    void wypisz()
    {
        cout << imie << ", zatrudniony: " << dataZatrudnienia.dzien << "."
             << dataZatrudnienia.miesiac << "." << dataZatrudnienia.rok << endl;
    }
};

Data Pracownik::dataZatrudnienia;     // definicja pola static poza klasą

int main()
{
    Pracownik::setData(9, 11, 2001);      // static - przez nazwę klasy

    Pracownik pracownik;
    Pracownik *wskaznik = &pracownik;     // wskaźnik na obiekt
    wskaznik->setImie("Jan Kowalski");    // -> zamiast .
    wskaznik->wypisz();

    Pracownik drugi;
    drugi.setImie("Anna Nowak");
    drugi.wypisz();                       // ta sama data - pole static

    return 0;
}
