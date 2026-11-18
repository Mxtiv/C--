// ======================================================================
// Punkt: static counter of created points, copy constructor,
// friend function odleglosc() reading private x, y.
// (the reflect / move methods are in ../09_point_class_static_method.cpp)
// Original file: unsorted/calfmatthew/coordinates.cpp
// ======================================================================

#include <iostream>
#include <cmath>
using namespace std;

class Punkt
{
private:
    double x;
    double y;
    static int liczbaPunktow;

public:
    Punkt()
    {
        x = 0;
        y = 0;
        liczbaPunktow++;
    }

    Punkt(double noweX, double noweY)
    {
        x = noweX;
        y = noweY;
        liczbaPunktow++;
    }

    // kopiujący też musi zwiększyć licznik - inaczej kopie nie byłyby liczone
    Punkt(const Punkt &wzor)
    {
        x = wzor.x;
        y = wzor.y;
        liczbaPunktow++;
    }

    void wypisz()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    static int getLiczbaPunktow()
    {
        return liczbaPunktow;
    }

    friend double odleglosc(Punkt p1, Punkt p2);
};

int Punkt::liczbaPunktow = 0;

// zwykła funkcja, ale jako friend widzi x i y
double odleglosc(Punkt p1, Punkt p2)
{
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    Punkt p1(0, 0);
    Punkt p2(3, 4);
    Punkt p3 = p2;            // konstruktor kopiujący

    p1.wypisz();
    p3.wypisz();
    cout << "Odleglosc p1-p2: " << odleglosc(p1, p2) << endl;   // 5
    // uwaga: przekazanie przez wartość też robi kopie (i zwiększa licznik)
    cout << "Utworzono punktow: " << Punkt::getLiczbaPunktow() << endl;

    return 0;
}
