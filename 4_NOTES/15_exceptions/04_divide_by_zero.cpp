// ======================================================================
// divide by zero: throw runtime_error from a function, catch it in main
// Original file: TryCatch/task2.cpp
// (simplified: the original used an own class derived from exception -
//  that version is in 01_custom_exception_what.cpp)
// ======================================================================

// Obsluz blad dzielenia przez zero.

#include <iostream>
#include <stdexcept>      // runtime_error
using namespace std;

/********************************************************
 * nazwa funkcji: podziel
 * opis funkcji: dzieli a przez b, przy b = 0 rzuca wyjatek runtime_error
 * parametry: a - dzielna
 *            b - dzielnik
 * zwracany typ i opis: double - iloraz
 ********************************************************/
double podziel(double a, double b)
{
    if (b == 0)
    {
        throw runtime_error("Nie dziel przez zero!");
    }
    return a / b;
}

int main()
{
    double a, b;
    cout << "Podaj a: ";
    cin >> a;
    cout << "Podaj b: ";
    cin >> b;

    try
    {
        double wynik = podziel(a, b);     // gdy podziel rzuci wyjatek, skaczemy od razu do catch
        cout << "Wynik: " << wynik << endl;
    }
    catch (runtime_error &e)          // e.what() zwraca tekst podany przy throw
    {
        cout << "Blad: " << e.what() << endl;
    }
    return 0;
}
