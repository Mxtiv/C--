// ======================================================================
// same shapes created with new/delete
// Original file: Classes/Polimorfizm/X) Zadanie figury sterta, virtual/main.cpp
// FIXED - the bug was: integer division in triangle area
// ======================================================================

#include <iostream>
using namespace std;
class Figury
{
public:
    virtual ~Figury() {}   // objects are deleted through Figury* -> virtual destructor
    virtual double polePowierzchni()
    {
        cout << endl
             << "wywołałeś funkcję z klasy bazowej";
        return 0;
    };
};
class Trojkat : public Figury
{
public:
    int podstawa;
    int wysokosc;
    Trojkat() {};
    Trojkat(int podstawa1, int wysokosc1)
    {
        podstawa = podstawa1;
        wysokosc = wysokosc1;
    }
    double polePowierzchni()
    {
        return podstawa * wysokosc / 2.0;
    }
};
class Rownoleglobok : public Figury
{
public:
    int podstawa;
    int wysokosc;
    Rownoleglobok() {};
    Rownoleglobok(int podstawa1, int wysokosc1) {podstawa=podstawa1; wysokosc=wysokosc1;};
    double polePowierzchni()
    {
        return podstawa * wysokosc;
    }
};
class Kolo : public Figury
{
public:
    int promien;
    Kolo() {};
    Kolo(int promien1)
    {
        promien = promien1;
    }
    double polePowierzchni()
    {
        return 3.14 * (promien * promien);
    }
};
int main()
{
    Figury *figura;
    figura=new Trojkat(2,1);
    cout<<endl<<figura->polePowierzchni()<<endl;
    delete figura;
    figura=new Rownoleglobok(1,1);
    cout<<figura->polePowierzchni()<<endl;
    delete figura;
    figura=new Kolo(1);
    cout<<figura->polePowierzchni();
    delete figura;
    return 0;
}