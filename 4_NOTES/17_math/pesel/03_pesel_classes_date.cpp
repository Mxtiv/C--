// ======================================================================
// class Data + class Pesel, a method that returns an object
// Original file: unsorted/calculations/peselBirthSex.cpp
// FIXED - the bugs were: checksum used ASCII codes (no - '0') and weight 2 instead of 3 -> it was
// always false; input check accepted letters (now: exactly 11 digits); string PESEL{0} -> string PESEL
// ======================================================================

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/********************************************************
 * nazwa klasy: Data
 * opis klasy: przechowuje date (dzien, miesiac, rok)
 * pola: dzien, miesiac, rok - skladniki daty
 * autor: <numer zdającego>
 ********************************************************/
class Data
{
private:
    int dzien;
    int miesiac;
    int rok;

public:
    Data(int d, int m, int r)
    {
        dzien = d;
        miesiac = m;
        rok = r;
    }

    void wypisz()
    {
        cout << dzien << "." << miesiac << "." << rok << endl;
    }
};

/********************************************************
 * nazwa klasy: Pesel
 * opis klasy: numer PESEL i odczytane z niego informacje
 * pola: numer - 11 cyfr numeru PESEL
 * autor: <numer zdającego>
 ********************************************************/
class Pesel
{
private:
    string numer;

    int cyfra(int indeks)              // pomocnicza: cyfra na pozycji indeks jako liczba
    {
        return numer[indeks] - '0';
    }

public:
    Pesel(string nowyNumer)
    {
        numer = nowyNumer;
    }

    char plec()
    {
        if (cyfra(9) % 2 == 0)
        {
            return 'K';
        }
        else
        {
            return 'M';
        }
    }

    bool sumaKontrolna()
    {
        int wagi[10] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
        int s = 0;
        for (int i = 0; i < 10; i++)
        {
            s = s + cyfra(i) * wagi[i];
        }
        int r = (10 - s % 10) % 10;
        if (r == cyfra(10))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Data dataUrodzenia()               // metoda zwraca OBIEKT innej klasy
    {
        int rok = cyfra(0) * 10 + cyfra(1);
        int miesiac = cyfra(2) * 10 + cyfra(3);
        int dzien = cyfra(4) * 10 + cyfra(5);

        if (miesiac > 20)
        {
            rok = rok + 2000;
            miesiac = miesiac - 20;
        }
        else
        {
            rok = rok + 1900;
        }
        return Data(dzien, miesiac, rok);
    }
};

/********************************************************
 * nazwa funkcji: czySameCyfry
 * opis funkcji: sprawdza, czy napis ma 11 znakow i same cyfry
 * parametry: tekst - napis do sprawdzenia
 * zwracany typ i opis: bool - true gdy 11 cyfr
 * autor: <numer zdającego>
 ********************************************************/
bool czySameCyfry(string tekst)
{
    if (tekst.length() != 11)
    {
        return false;
    }
    for (int i = 0; i < 11; i++)
    {
        if (!isdigit(tekst[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string tekst;
    do
    {
        cout << "Podaj PESEL (11 cyfr): ";
        cin >> tekst;
    } while (!czySameCyfry(tekst));

    Pesel osoba(tekst);
    cout << "Plec: " << osoba.plec() << endl;
    cout << "Data urodzenia: ";
    Data data = osoba.dataUrodzenia();
    data.wypisz();
    if (osoba.sumaKontrolna())
    {
        cout << "Suma kontrolna: poprawna" << endl;
    }
    else
    {
        cout << "Suma kontrolna: bledna" << endl;
    }

    return 0;
}
