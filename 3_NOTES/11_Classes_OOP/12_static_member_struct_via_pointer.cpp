// ======================================================================
// static member of a struct type; access through a pointer with ->
// Original file: unsorted/various/obslugaPrzezPointer.cpp
// ======================================================================

#include <iostream>
using namespace std;

struct DataZatrudnienia
{
    int dzien;
    int miesiac;
    int rok;
};

class Pracownik
{
public:
    string imie;
    string nazwisko;
    static DataZatrudnienia data_zatrudnienia;

    void wyswietlDane()
    {
        cout << "Imię: " << imie << endl;
        cout << "Nazwisko: " << nazwisko << endl;
        cout << "Data zatrudnienia: " << data_zatrudnienia.dzien << "."
             << data_zatrudnienia.miesiac << "." << data_zatrudnienia.rok << endl;
    }
};

DataZatrudnienia Pracownik::data_zatrudnienia;

int main()
{

    Pracownik pracownik;
    Pracownik *w_pracownik = &pracownik;
    w_pracownik->imie = "Jan";
    w_pracownik->nazwisko = "Kowalski";
    w_pracownik->data_zatrudnienia.dzien = 9;
    w_pracownik->data_zatrudnienia.miesiac = 11;
    w_pracownik->data_zatrudnienia.rok = 2001;

    w_pracownik->wyswietlDane();

    return 0;
}
