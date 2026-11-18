// ======================================================================
// friend class (klasa zaprzyjaźniona): Kolo and Kula may read the PRIVATE
// field of Promien because Promien declares them as friends.
// Friendship is given, not taken - and it only works one way.
// Original file: Classes/friends/adam_I_przyjaciele.cpp
// ======================================================================

#include <iostream>
using namespace std;

const double PI = 3.14159;

class Promien
{
private:
    double r;

public:
    Promien(double nowyR)
    {
        r = nowyR;
    }

    friend class Kolo;     // Kolo może czytać r
    friend class Kula;     // Kula też
};

class Kolo
{
public:
    double pole(Promien promien)
    {
        return PI * promien.r * promien.r;     // r jest private, ale Kolo to przyjaciel
    }

    double obwod(Promien promien)
    {
        return 2 * PI * promien.r;
    }
};

class Kula
{
public:
    double objetosc(Promien promien)
    {
        return 4.0 / 3.0 * PI * promien.r * promien.r * promien.r;
    }
};

int main()
{
    Promien jeden(1);
    Kolo kolo;
    cout << "Pole kola: " << kolo.pole(jeden) << endl;
    cout << "Obwod kola: " << kolo.obwod(jeden) << endl;

    Promien dwa(2);
    Kula kula;
    cout << "Objetosc kuli: " << kula.objetosc(dwa) << endl;

    // cout << dwa.r;      // BŁĄD - main nie jest przyjacielem
    return 0;
}
