// ======================================================================
// ALL-IN-ONE class: private fields, default + parameter constructor,
// destructor, getters, setters with validation, static counter + static getter.
// (copy constructor -> 05/06, friend -> 08/10/11, operators -> 14)
// Original file: unsorted/calfmatthew/rectangle1.cpp
// ======================================================================

#include <iostream>
using namespace std;

/********************************************************
 * nazwa klasy: Prostokat
 * opis klasy: prostokąt o podanych bokach, liczy pole
 * pola: szerokosc, wysokosc - boki prostokąta
 *       licznik - (static) ile obiektów istnieje
 ********************************************************/
class Prostokat
{
private:
    double szerokosc;
    double wysokosc;
    static int licznik;   // JEDNA wspólna kopia dla wszystkich obiektów

public:
    // konstruktor domyślny (bez parametrów)
    Prostokat()
    {
        szerokosc = 1;
        wysokosc = 1;
        licznik++;
    }

    // konstruktor z parametrami
    Prostokat(double nowaSzerokosc, double nowaWysokosc)
    {
        szerokosc = nowaSzerokosc;
        wysokosc = nowaWysokosc;
        licznik++;
    }

    // destruktor - bez parametrów, uruchamia się sam przy niszczeniu obiektu
    ~Prostokat()
    {
        licznik--;
    }

    double getSzerokosc()
    {
        return szerokosc;
    }

    double getWysokosc()
    {
        return wysokosc;
    }

    // setter z walidacją - złej wartości nie zapisujemy
    void setSzerokosc(double nowaSzerokosc)
    {
        if (nowaSzerokosc > 0)
        {
            szerokosc = nowaSzerokosc;
        }
    }

    void setWysokosc(double nowaWysokosc)
    {
        if (nowaWysokosc > 0)
        {
            wysokosc = nowaWysokosc;
        }
    }

    /********************************************************
     * nazwa funkcji: pole
     * opis funkcji: liczy pole prostokąta
     * parametry: brak
     * zwracany typ i opis: double - pole prostokąta
     ********************************************************/
    double pole()
    {
        return szerokosc * wysokosc;
    }

    void wypisz()
    {
        cout << "Prostokat " << szerokosc << " x " << wysokosc << endl;
    }

    // metoda statyczna - wołamy przez nazwę klasy: Prostokat::getLicznik()
    static int getLicznik()
    {
        return licznik;
    }
};

// pole statyczne trzeba zdefiniować POZA klasą
int Prostokat::licznik = 0;

int main()
{
    Prostokat p1;              // konstruktor domyślny
    p1.wypisz();

    Prostokat p2(3, 4);        // konstruktor z parametrami
    p2.wypisz();
    p2.setSzerokosc(-5);       // odrzucone przez walidację
    cout << "Pole p2: " << p2.pole() << endl;

    cout << "Liczba prostokatow: " << Prostokat::getLicznik() << endl;   // 2

    {
        Prostokat p3(2, 2);
        cout << "W bloku: " << Prostokat::getLicznik() << endl;          // 3
    }                          // tu destruktor p3
    cout << "Po bloku: " << Prostokat::getLicznik() << endl;             // 2

    return 0;
}
