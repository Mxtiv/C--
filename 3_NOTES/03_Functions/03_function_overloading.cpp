// ======================================================================
// overloading: wypisz(int), wypisz(double), wypisz(string), wypisz(int,int)
// Original file: Functions/overloadFunctions.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

// Overloading = the SAME name, a DIFFERENT parameter list (number or types).
// The return type alone is not enough to tell them apart.

void wypisz(int liczba)
{
    cout << "Printing integer: " << liczba << endl;
}

void wypisz(double liczba)
{
    cout << "Printing double: " << liczba << endl;
}

void wypisz(string tekst)
{
    cout << "Printing string: " << tekst << endl;
}

void wypisz(int a, int b)
{
    cout << "Printing two integers: " << a << " and " << b << endl;
}

int main()
{
    wypisz(42);                  // calls wypisz(int)
    wypisz(3.14);                // calls wypisz(double)
    wypisz(string("Hello!"));    // calls wypisz(string)
    wypisz(10, 20);              // calls wypisz(int, int)

    return 0;
}
