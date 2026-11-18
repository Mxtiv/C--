// ======================================================================
// Osoba: private pesel + setter + getter (by value and by reference).
// PESEL is stored as a string - 11 digits do not fit in int.
// Original file: unsorted/hermetyzacja/hermbyKaczmar.cpp
// FIXED: return NULL from main -> return 0; pesel int -> string
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class Osoba
{
private:
    string imie;
    string nazwisko;
    string pesel;

public:
    Osoba(string noweImie, string noweNazwisko)
    {
        imie = noweImie;
        nazwisko = noweNazwisko;
        pesel = "";
    }

    void setPesel(string nowyPesel)
    {
        if (nowyPesel.length() == 11)
        {
            pesel = nowyPesel;
        }
        else
        {
            cout << "PESEL musi miec 11 cyfr" << endl;
        }
    }

    string getPesel()                   // getter przez wartość (zwykły)
    {
        return pesel;
    }

    void getPesel(string &wynik)        // getter przez referencję (przeciążony)
    {
        wynik = pesel;
    }

    void wypisz()
    {
        cout << imie << " " << nazwisko << ", PESEL: " << pesel << endl;
    }
};

int main()
{
    string imie;
    string nazwisko;
    string pesel;
    cout << "Podaj imie i nazwisko: ";
    cin >> imie >> nazwisko;
    cout << "Podaj PESEL: ";
    cin >> pesel;

    Osoba osoba(imie, nazwisko);
    osoba.setPesel(pesel);
    osoba.wypisz();

    string kopia;
    osoba.getPesel(kopia);
    cout << "Getter przez referencje: " << kopia << endl;
    cout << "Getter przez wartosc: " << osoba.getPesel() << endl;

    return 0;
}
