// ======================================================================
// READY PROGRAM 11: inheritance + polymorphism - abstract base class Figura,
// derived Kolo / Prostokat / Trojkat, array of base-class pointers, virtual methods,
// largest area
// Based on: Classes/Polimorfizm/X) Zadanie figury sterta, virtual/main.cpp (+ "stos")
// Blocks used: CLS-06, CLS-05
// ======================================================================
//
// Treść zadania (wariant): Abstrakcyjna klasa bazowa Figura z czysto wirtualnymi
// metodami pole(), obwod() i nazwa(). Klasy pochodne Kolo, Prostokat i Trojkat
// implementują te metody. Program tworzy po jednej figurze każdego rodzaju,
// przechowuje ich adresy w tablicy wskaźników do klasy bazowej, wyświetla pola
// i obwody figur oraz figurę o największym polu.

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979;

/********************************************************
 * nazwa klasy: Figura
 * opis klasy: abstrakcyjna klasa bazowa figur płaskich
 * pola: brak
 * autor: <numer zdającego>
 ********************************************************/
class Figura
{
public:
    virtual double pole() = 0;
    virtual double obwod() = 0;
    virtual string nazwa() = 0;

    /********************************************************
     * nazwa funkcji: wyswietl
     * opis funkcji: wyświetla nazwę, pole i obwód figury (korzysta z metod wirtualnych)
     * parametry: brak
     * zwracany typ i opis: brak
     * autor: <numer zdającego>
     ********************************************************/
    void wyswietl()
    {
        cout << nazwa() << ": pole = " << pole() << ", obwod = " << obwod() << endl;
    }
};

/********************************************************
 * nazwa klasy: Kolo
 * opis klasy: koło - klasa pochodna klasy Figura
 * pola: r - promień
 * autor: <numer zdającego>
 ********************************************************/
class Kolo : public Figura
{
private:
    double r;

public:
    Kolo(double promien)
    {
        r = promien;
    }

    double pole()
    {
        return PI * r * r;
    }

    double obwod()
    {
        return 2 * PI * r;
    }

    string nazwa()
    {
        return "Kolo";
    }
};

/********************************************************
 * nazwa klasy: Prostokat
 * opis klasy: prostokąt - klasa pochodna klasy Figura
 * pola: a, b - długości boków
 * autor: <numer zdającego>
 ********************************************************/
class Prostokat : public Figura
{
private:
    double a;
    double b;

public:
    Prostokat(double bokA, double bokB)
    {
        a = bokA;
        b = bokB;
    }

    double pole()
    {
        return a * b;
    }

    double obwod()
    {
        return 2 * (a + b);
    }

    string nazwa()
    {
        return "Prostokat";
    }
};

/********************************************************
 * nazwa klasy: Trojkat
 * opis klasy: trójkąt o bokach a, b, c - klasa pochodna klasy Figura; pole ze wzoru Herona
 * pola: a, b, c - długości boków
 * autor: <numer zdającego>
 ********************************************************/
class Trojkat : public Figura
{
private:
    double a;
    double b;
    double c;

public:
    Trojkat(double bokA, double bokB, double bokC)
    {
        a = bokA;
        b = bokB;
        c = bokC;
    }

    double pole()
    {
        double p = (a + b + c) / 2;                      // half of the perimeter
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    double obwod()
    {
        return a + b + c;
    }

    string nazwa()
    {
        return "Trojkat";
    }
};

int main()
{
    Kolo kolo(2);
    Prostokat prostokat(3, 4);
    Trojkat trojkat(3, 4, 5);

    Figura *figury[3] = {&kolo, &prostokat, &trojkat};

    int najwieksza = 0;
    for (int i = 0; i < 3; i++)
    {
        figury[i]->wyswietl();                           // the right version thanks to virtual
        if (figury[i]->pole() > figury[najwieksza]->pole())
        {
            najwieksza = i;
        }
    }
    cout << "Najwieksze pole ma: " << figury[najwieksza]->nazwa() << endl;
    return 0;
}
