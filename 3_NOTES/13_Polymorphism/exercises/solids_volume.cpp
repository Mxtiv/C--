// ======================================================================
// solids volume: Bryla -> Walec -> Stozek, Bryla -> Prostopadloscian; virtual objetosc()
// Original file: unsorted/various/polimorfizmsnejp.cpp
// FIXED: volume is double (was int); return 0 from main (was NULL)
// ======================================================================

#include <iostream>
using namespace std;

class Bryla
{
protected:
    int wysokosc;

public:
    Bryla(int nowaWysokosc)
    {
        wysokosc = nowaWysokosc;
    }

    virtual double objetosc()
    {
        cout << "wywolales metode z klasy bazowej" << endl;
        return 0;
    }
};

class Walec : public Bryla
{
protected:
    int promien;

public:
    Walec(int nowaWysokosc, int nowyPromien) : Bryla(nowaWysokosc)
    {
        promien = nowyPromien;
    }

    double objetosc()
    {
        return 3.14 * promien * promien * wysokosc;
    }
};

// stozek dziedziczy po walcu (ma ten sam promien i wysokosc)
class Stozek : public Walec
{
public:
    Stozek(int nowaWysokosc, int nowyPromien) : Walec(nowaWysokosc, nowyPromien)
    {
    }

    double objetosc()
    {
        return 3.14 * promien * promien * wysokosc / 3;
    }
};

class Prostopadloscian : public Bryla
{
private:
    int dlugosc;
    int szerokosc;

public:
    Prostopadloscian(int nowaWysokosc, int nowaDlugosc, int nowaSzerokosc) : Bryla(nowaWysokosc)
    {
        dlugosc = nowaDlugosc;
        szerokosc = nowaSzerokosc;
    }

    double objetosc()
    {
        return dlugosc * szerokosc * wysokosc;
    }
};

int main()
{
    Walec walec(4, 6);
    Stozek stozek(5, 4);
    Prostopadloscian prostopadloscian(5, 5, 4);

    Bryla *bryla;

    bryla = &walec;
    cout << "Objetosc walca: " << bryla->objetosc() << endl;

    bryla = &stozek;
    cout << "Objetosc stozka: " << bryla->objetosc() << endl;

    bryla = &prostopadloscian;
    cout << "Objetosc prostopadloscianu: " << bryla->objetosc() << endl;
    return 0;
}
