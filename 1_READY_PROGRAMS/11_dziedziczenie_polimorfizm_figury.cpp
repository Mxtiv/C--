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
// implementują te metody. Program tworzy figury dynamicznie, przechowuje je
// w tablicy wskaźników do klasy bazowej, wyświetla ich pola i obwody oraz figurę
// o największym polu. Na końcu zwalnia pamięć.

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
    virtual double pole() const = 0;
    virtual double obwod() const = 0;
    virtual string nazwa() const = 0;
    virtual ~Figura() {}

    /********************************************************
     * nazwa funkcji: wyswietl
     * opis funkcji: wyświetla nazwę, pole i obwód figury (korzysta z metod wirtualnych)
     * parametry: brak
     * zwracany typ i opis: brak
     * autor: <numer zdającego>
     ********************************************************/
    void wyswietl() const
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
    Kolo(double r) : r(r) {}
    double pole() const override { return PI * r * r; }
    double obwod() const override { return 2 * PI * r; }
    string nazwa() const override { return "Kolo"; }
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
    double a, b;

public:
    Prostokat(double a, double b) : a(a), b(b) {}
    double pole() const override { return a * b; }
    double obwod() const override { return 2 * (a + b); }
    string nazwa() const override { return "Prostokat"; }
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
    double a, b, c;

public:
    Trojkat(double a, double b, double c) : a(a), b(b), c(c) {}
    double pole() const override
    {
        double p = (a + b + c) / 2;                      // half of the perimeter
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    double obwod() const override { return a + b + c; }
    string nazwa() const override { return "Trojkat"; }
};

int main()
{
    const int N = 3;
    Figura *figury[N] = {new Kolo(2), new Prostokat(3, 4), new Trojkat(3, 4, 5)};

    int najwieksza = 0;
    for (int i = 0; i < N; i++)
    {
        figury[i]->wyswietl();                           // the right version thanks to virtual
        if (figury[i]->pole() > figury[najwieksza]->pole())
            najwieksza = i;
    }
    cout << "Najwieksze pole ma: " << figury[najwieksza]->nazwa() << endl;

    for (int i = 0; i < N; i++)
        delete figury[i];                                // virtual ~Figura() -> correct destructor
    return 0;
}
