// ======================================================================
// private validation method used by a public setter, getters, leading zeros in a date (05.03.1999)
// Original file: unsorted/diagramy/peselClass.cpp
// FIXED - the bug was: int s is uninitialized; `pesel[9] - 48 % 2` has wrong precedence
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

/********************************************************
 * nazwa klasy: Osoba
 * opis klasy: osoba z numerem PESEL; PESEL ustawia sie tylko przez setter,
 *             ktory najpierw sprawdza sume kontrolna
 * pola: pesel - numer PESEL, plec - 'K' lub 'M'
 * autor: <numer zdającego>
 ********************************************************/
class Osoba
{
private:
    string pesel;
    char plec;

    // metoda PRYWATNA - z zewnatrz jej nie wywolasz, uzywa jej publiczny setter
    bool czyPoprawny(string podanyPesel)
    {
        if (podanyPesel.length() != 11)
        {
            return false;
        }
        int wagi[10] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
        int s = 0;
        for (int i = 0; i < 10; i++)
        {
            s = s + (podanyPesel[i] - '0') * wagi[i];
        }
        int r = (10 - s % 10) % 10;
        if (r == podanyPesel[10] - '0')
        {
            return true;
        }
        return false;
    }

public:
    Osoba()
    {
        pesel = "";
        plec = '?';
    }

    // setter zwraca true/false - czy udalo sie ustawic
    bool setPesel(string podanyPesel)
    {
        if (!czyPoprawny(podanyPesel))
        {
            return false;
        }
        pesel = podanyPesel;
        if ((pesel[9] - '0') % 2 == 0)
        {
            plec = 'K';
        }
        else
        {
            plec = 'M';
        }
        return true;
    }

    string getPesel()
    {
        return pesel;
    }

    char getPlec()
    {
        return plec;
    }

    void wypiszDateUrodzenia()
    {
        int rok = (pesel[0] - '0') * 10 + (pesel[1] - '0');
        int miesiac = (pesel[2] - '0') * 10 + (pesel[3] - '0');
        int dzien = (pesel[4] - '0') * 10 + (pesel[5] - '0');

        if (miesiac > 20)
        {
            rok = rok + 2000;
            miesiac = miesiac - 20;
        }
        else
        {
            rok = rok + 1900;
        }

        // zero z przodu: 5 -> "05"
        cout << "Data urodzenia: ";
        if (dzien < 10)
        {
            cout << "0";
        }
        cout << dzien << ".";
        if (miesiac < 10)
        {
            cout << "0";
        }
        cout << miesiac << "." << rok << endl;
    }
};

int main()
{
    Osoba osoba;
    string pesel;
    bool ustawiony;
    do
    {
        cout << "Podaj PESEL: ";
        cin >> pesel;
        ustawiony = osoba.setPesel(pesel);
        if (!ustawiony)
        {
            cout << "Niepoprawny PESEL, sprobuj jeszcze raz" << endl;
        }
    } while (!ustawiony);

    cout << "PESEL: " << osoba.getPesel() << endl;
    cout << "Plec: " << osoba.getPlec() << endl;
    osoba.wypiszDateUrodzenia();

    return 0;
}
