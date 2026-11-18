// ======================================================================
// three ways: throw int, throw runtime_error, throw own class derived from exception
// Original file: TryCatch/task4.cpp
// ======================================================================

// Pobieramy liczbe. Jezeli jest dwucyfrowa, to ja wypisz. Obsluz na trzy sposoby bledy:
// liczba jednocyfrowa
// liczba trzycyfrowa
// liczba cztero- i wiecej cyfrowa

#include <iostream>
#include <stdexcept>
using namespace std;

// wlasna klasa pochodna od exception - what() z naglowkiem jak w klasie bazowej
class ZaDlugaLiczba : public exception
{
public:
    const char* what() const noexcept
    {
        return "Podales liczbe cztero- lub wiecej cyfrowa";
    }
};

int main()
{
    try
    {
        int liczba;
        cout << "Podaj liczbe: ";
        cin >> liczba;

        if (liczba < 0)
        {
            liczba = -liczba;                 // liczymy cyfry bez minusa
        }
        if (liczba < 10)
        {
            throw liczba;                                         // sposob 1: int
        }
        if (liczba >= 100 && liczba < 1000)
        {
            throw runtime_error("Podales liczbe trzycyfrowa");    // sposob 2: runtime_error
        }
        if (liczba >= 1000)
        {
            throw ZaDlugaLiczba();                                // sposob 3: wlasna klasa
        }
        cout << "Twoja liczba to: " << liczba << endl;
    }
    catch (int)
    {
        cout << "Podales liczbe jednocyfrowa" << endl;
    }
    catch (exception &e)        // lapie runtime_error ORAZ ZaDlugaLiczba (obie pochodza od exception)
    {
        cout << e.what() << endl;
    }

    return 0;
}
