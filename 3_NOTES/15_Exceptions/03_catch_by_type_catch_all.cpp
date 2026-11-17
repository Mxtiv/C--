// ======================================================================
// catch(double)/(int)/(float)/(...) - catch picks by the TYPE thrown
// Original file: unsorted/trycatch/example1.cpp
// FIXED: `long int domyslny` was thrown uninitialized (now = 0)
// ======================================================================

// Użytkownik ma podać liczbę dwucyfrową. 
// Jeżeli jest podana inna to napisz: podales jednocyfrowa, trzycefrowa, czterocyfrowa, 
// wiecej niż czterocyfrowa. Ostatni blad ogarnij domyślnym catch.
#include <iostream>
using namespace std;
int main()
{
    try//catche łapią po typie wyrzucanej zmiennej
    {
        int liczba, reszta1;
        double reszta2;
        float cztero;
        long int domyslny = 0;
        cout << "podaj liczbe dwucyfrowa: \n";
        cin >> liczba;
        if (liczba < 10)
            throw liczba;
        if (liczba > 99 && liczba < 1000)
            throw 1.0;
        if (liczba > 999 && liczba < 10000)
            throw 1.0f;
        if (liczba > 9999)
            throw domyslny;
        reszta1 = liczba % 10;
        reszta2 = (liczba - reszta1) / 10;
        cout << "podana liczba rozlozona: \n";
        cout << reszta2 << endl;
        cout << reszta1 << endl;
    }
    catch (double)
    {
        cout << "Podales liczbe trzycyfrowa";
    }
    catch (int)
    {
        cout << "Podales liczbe jednocyfrowa\n";
    }
    catch (float)
    {
        cout << "Podales liczbe czterocyfrowa";
    }
    catch (...)
    {
        cout << "wiecej niz czterocyfrowa";
    }
    return 0;
}