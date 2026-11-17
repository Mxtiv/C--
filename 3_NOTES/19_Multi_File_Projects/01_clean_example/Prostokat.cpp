// ======================================================================
// ADDED (gap-fill): SOURCE (.cpp): the DEFINITIONS for everything declared in Prostokat.h
// ======================================================================

#include "Prostokat.h"     // own header first, in "quotes"
#include <string>
#include <sstream>

int Prostokat::count = 0;  // static member definition (exactly once, in a .cpp)

Prostokat::Prostokat(double a, double b) : a(a), b(b)   // default args are NOT repeated here
{
    count++;
}

double Prostokat::pole() const
{
    return a * b;
}

double Prostokat::obwod() const
{
    return 2 * (a + b);
}

std::string Prostokat::opis() const
{
    std::ostringstream out;                 // builds a string like cout does (to_string would give 3.000000)
    out << "Prostokat " << a << " x " << b;
    return out.str();
}

int Prostokat::ile()
{
    return count;
}

bool czyKwadrat(const Prostokat &p, double a, double b)
{
    (void)p;
    return a == b;
}
