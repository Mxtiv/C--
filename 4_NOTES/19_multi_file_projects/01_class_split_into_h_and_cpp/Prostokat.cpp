// ======================================================================
// ADDED (gap-fill): SOURCE (.cpp): the DEFINITIONS for everything declared in Prostokat.h
// Every method is written as  typ Klasa::metoda(...)
// ======================================================================

#include <iostream>
#include "Prostokat.h"      // wlasny naglowek w "cudzyslowie"
using namespace std;

int Prostokat::liczbaProstokatow = 0;   // definicja pola static - DOKLADNIE raz, w pliku .cpp

Prostokat::Prostokat()
{
    a = 1;
    b = 1;
    liczbaProstokatow++;
}

Prostokat::Prostokat(double bokA, double bokB)
{
    a = bokA;
    b = bokB;
    liczbaProstokatow++;
}

double Prostokat::pole()
{
    return a * b;
}

double Prostokat::obwod()
{
    return 2 * (a + b);
}

bool Prostokat::czyKwadrat()
{
    if (a == b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Prostokat::wypisz()
{
    cout << "Prostokat " << a << " x " << b << endl;
}

int Prostokat::ile()                    // przy definicji NIE piszemy juz slowa static
{
    return liczbaProstokatow;
}

bool czyWiekszy(Prostokat p1, Prostokat p2)
{
    if (p1.pole() > p2.pole())
    {
        return true;
    }
    else
    {
        return false;
    }
}
