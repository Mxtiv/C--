// ======================================================================
// the same sphere calculation written 3 ways: by value, by reference (output params), by pointer
// Original file: unsorted/various/pi.cpp
// ======================================================================

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979;

// 1) BY VALUE - the function gets a COPY of promien; it can return only ONE value
double objetoscPrzezWartosc(double promien)
{
    double objetosc = (4.0 / 3.0) * PI * pow(promien, 3);
    return objetosc;
}

// 2) BY REFERENCE (&) - objetosc and pole ARE the caller's variables,
//    so the function can "return" two results through them
void kulaPrzezReferencje(double promien, double &objetosc, double &pole)
{
    objetosc = (4.0 / 3.0) * PI * pow(promien, 3);
    pole = 4 * PI * pow(promien, 2);
}

// 3) BY POINTER (*) - the function gets ADDRESSES; call it with &x, use *x inside
void kulaPrzezWskazniki(double promien, double *objetosc, double *pole)
{
    *objetosc = (4.0 / 3.0) * PI * pow(promien, 3);
    *pole = 4 * PI * pow(promien, 2);
}

// (In books you may also see "const double &promien" - a reference that cannot be changed.
//  For int / double / string just pass by value, like in 1).)

int main()
{
    double promien;
    do
    {
        cout << "Enter the radius of the sphere: ";
        cin >> promien;
    } while (promien <= 0);

    cout << "By value     - volume: " << objetoscPrzezWartosc(promien) << endl;

    double objetosc2;
    double pole2;
    kulaPrzezReferencje(promien, objetosc2, pole2);
    cout << "By reference - volume: " << objetosc2 << ", surface: " << pole2 << endl;

    double objetosc3;
    double pole3;
    kulaPrzezWskazniki(promien, &objetosc3, &pole3);
    cout << "By pointer   - volume: " << objetosc3 << ", surface: " << pole3 << endl;

    return 0;
}
