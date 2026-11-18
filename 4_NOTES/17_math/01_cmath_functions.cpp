// ======================================================================
// abs sqrt pow log exp log10 sin cos tan ceil floor trunc round
// Original file: Maths/CMath.cpp
// ======================================================================

#include <iostream>
#include <cmath>      // funkcje matematyczne
using namespace std;

int main()
{
    double liczba = -9.5;

    cout << "abs(-9.5)    = " << abs(liczba) << "   (wartosc bezwzgledna)" << endl;
    cout << "sqrt(25)     = " << sqrt(25) << "   (pierwiastek kwadratowy)" << endl;
    cout << "pow(2, 3)    = " << pow(2, 3) << "   (potega: 2 do 3)" << endl;
    cout << "log(2.71828) = " << log(2.71828) << "   (logarytm naturalny ln)" << endl;
    cout << "exp(1)       = " << exp(1) << "   (e do potegi 1)" << endl;
    cout << "log10(100)   = " << log10(100) << "   (logarytm dziesietny)" << endl;

    // funkcje trygonometryczne licza w RADIANACH (180 stopni = 3.14159 rad)
    double pi = 3.14159;
    cout << "sin(pi/2)    = " << sin(pi / 2) << endl;
    cout << "cos(0)       = " << cos(0) << endl;
    cout << "tan(pi/4)    = " << tan(pi / 4) << endl;

    // zaokraglanie (wiecej w 02_rounding_ceil_floor_trunc_round.cpp)
    cout << "ceil(-9.5)   = " << ceil(liczba) << "   (w gore)" << endl;
    cout << "floor(-9.5)  = " << floor(liczba) << "   (w dol)" << endl;
    cout << "trunc(-9.5)  = " << trunc(liczba) << "   (obciecie czesci ulamkowej)" << endl;
    cout << "round(-9.5)  = " << round(liczba) << "   (do najblizszej calkowitej)" << endl;

    return 0;
}
