// ======================================================================
// catch(double)/(int)/(float)/(...) - catch picks by the TYPE thrown
// Original file: unsorted/trycatch/example1.cpp
// FIXED: `long int domyslny` was thrown uninitialized (now = 0)
// ======================================================================

// Uzytkownik ma podac liczbe dwucyfrowa.
// Jezeli jest podana inna, to napisz: podales jednocyfrowa, trzycyfrowa, czterocyfrowa,
// wiecej niz czterocyfrowa. Ostatni blad obsluz domyslnym catch(...).

#include <iostream>
using namespace std;

int main()
{
    try     // catch-e lapia po TYPIE wyrzuconej wartosci
    {
        int liczba;
        long domyslny = 0;

        cout << "Podaj liczbe dwucyfrowa: ";
        cin >> liczba;

        if (liczba < 10)
        {
            throw liczba;           // int
        }
        if (liczba > 99 && liczba < 1000)
        {
            throw 1.0;              // double
        }
        if (liczba > 999 && liczba < 10000)
        {
            throw 1.0f;             // float
        }
        if (liczba > 9999)
        {
            throw domyslny;         // long - nie ma catch(long), wiec lapie catch(...)
        }

        cout << "Cyfra dziesiatek: " << liczba / 10 << endl;
        cout << "Cyfra jednosci: " << liczba % 10 << endl;
    }
    catch (double)
    {
        cout << "Podales liczbe trzycyfrowa" << endl;
    }
    catch (int)
    {
        cout << "Podales liczbe jednocyfrowa" << endl;
    }
    catch (float)
    {
        cout << "Podales liczbe czterocyfrowa" << endl;
    }
    catch (...)                     // wszystko inne - zawsze na KONCU
    {
        cout << "Wiecej niz czterocyfrowa" << endl;
    }
    return 0;
}
