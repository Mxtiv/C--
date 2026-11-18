// ======================================================================
// object created with new, passed by pointer to functions (-> instead of .)
// Original file: unsorted/various/sterta.cpp
// FIXED - the bug was: DOES NOT COMPILE: free function reads private `pesel` - add a getter
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class Pracownik
{
private:
    string imie;
    string nazwisko;
    string pesel;

public:
    void setDane(string noweImie, string noweNazwisko, string nowyPesel)
    {
        imie = noweImie;
        nazwisko = noweNazwisko;
        pesel = nowyPesel;
    }

    string getImie()
    {
        return imie;
    }

    string getNazwisko()
    {
        return nazwisko;
    }

    string getPesel()
    {
        return pesel;
    }
};

// The function gets the ADDRESS of the object - it fills the object from main
void pobierzDane(Pracownik *wskPracownik)
{
    string imie;
    string nazwisko;
    string pesel;
    cout << "Imię = ";
    cin >> imie;
    cout << "Nazwisko = ";
    cin >> nazwisko;
    cout << "Pesel = ";
    cin >> pesel;
    wskPracownik->setDane(imie, nazwisko, pesel);   // -> = method through a pointer
}

void wyswietlDane(Pracownik *wskPracownik)
{
    cout << wskPracownik->getImie() << " " << wskPracownik->getNazwisko()
         << " " << wskPracownik->getPesel() << endl;
}

int main()
{
    Pracownik *pracownik = new Pracownik();   // object on the heap
    pobierzDane(pracownik);
    wyswietlDane(pracownik);
    delete pracownik;                         // new -> delete
    return 0;
}
