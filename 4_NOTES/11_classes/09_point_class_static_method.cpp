// ======================================================================
// Punkt: constructors, reflect, move, point symmetry, distance to a line,
// static method (called as Punkt::odleglosc(p1, p2), no object needed).
// Original file: unsorted/calculations/diagramOdbicia.cpp
// ======================================================================

#include <iostream>
#include <cmath>
using namespace std;

class Punkt
{
private:
    double x;
    double y;

public:
    Punkt()
    {
        x = 0;
        y = 0;
    }

    Punkt(double noweX, double noweY)
    {
        x = noweX;
        y = noweY;
    }

    double getX()
    {
        return x;
    }

    double getY()
    {
        return y;
    }

    void odbijWzgledemX()
    {
        y = -y;
    }

    void odbijWzgledemY()
    {
        x = -x;
    }

    void przesun(double dx, double dy)
    {
        x = x + dx;
        y = y + dy;
    }

    // symetria względem punktu (px, py)
    void symetriaWzgledemPunktu(double px, double py)
    {
        x = 2 * px - x;
        y = 2 * py - y;
    }

    // odległość od prostej Ax + By + C = 0
    double odlegloscOdProstej(double a, double b, double c)
    {
        return fabs(a * x + b * y + c) / sqrt(a * a + b * b);
    }

    void wypisz()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    // metoda statyczna - nie ma "swojego" obiektu, dostaje oba punkty
    static double odleglosc(Punkt p1, Punkt p2)
    {
        double dx = p2.x - p1.x;
        double dy = p2.y - p1.y;
        return sqrt(dx * dx + dy * dy);
    }
};

int main()
{
    Punkt p1(3, 4);
    Punkt p2 = p1;            // kopia
    p1.wypisz();

    p1.przesun(1, -2);
    p1.wypisz();              // (4, 2)
    p1.odbijWzgledemX();
    p1.wypisz();              // (4, -2)
    p1.odbijWzgledemY();
    p1.wypisz();              // (-4, -2)
    p1.symetriaWzgledemPunktu(1, 1);
    p1.wypisz();              // (6, 4)

    cout << "Odleglosc od prostej 2x + 3y + 1 = 0: " << p1.odlegloscOdProstej(2, 3, 1) << endl;
    cout << "Odleglosc p1 - p2: " << Punkt::odleglosc(p1, p2) << endl;

    return 0;
}
