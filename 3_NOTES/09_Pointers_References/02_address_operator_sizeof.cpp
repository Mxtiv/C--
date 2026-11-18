// ======================================================================
// & address-of and sizeof for int / double / char / bool (Polish comments)
// Original file: Pointers/adressOperators.cpp
// ======================================================================

#include <iostream>
using namespace std;

int main()
{
    // Deklaracja i inicjalizacja zmiennej typu całkowitego int:
    int zmiennaInt = 10;

    cout << "Informacje dotyczące zmiennej zmiennaInt:" << endl;
    cout << "wartość: " << zmiennaInt << endl;                       // wartość przechowywana w zmiennej
    cout << "rozmiar: " << sizeof(zmiennaInt) << " bajty" << endl;   // ile bajtów zajmuje
    cout << "adres: " << &zmiennaInt << endl;                        // operator adresu & - adres w systemie szesnastkowym

    // Zmienna typu rzeczywistego double:
    double zmiennaDouble = 1.5;

    cout << "Informacje dotyczące zmiennej zmiennaDouble:" << endl;
    cout << "wartość: " << zmiennaDouble << endl;
    cout << "rozmiar: " << sizeof(zmiennaDouble) << " bajtów" << endl;
    cout << "adres: " << &zmiennaDouble << endl;

    // Rozmiary innych typów:
    cout << "sizeof(char) = " << sizeof(char) << ", sizeof(bool) = " << sizeof(bool)
         << ", sizeof(long long) = " << sizeof(long long) << endl;

    return 0;
}
