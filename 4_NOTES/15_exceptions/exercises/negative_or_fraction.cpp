// ======================================================================
// two ways: runtime_error and logic_error with a message
// Original file: TryCatch/task3.cpp
// FIXED - the bug was: condition reversed: `a - (int)a == 0` is true for WHOLE numbers - should be != 0
// (simplified: the original derived its own class from logic_error - plain logic_error is enough)
// ======================================================================

// Obsluz na dwa sposoby blad podania przez uzytkownika liczby ujemnej i niecalkowitej.
// Jezeli liczba jest nieujemna i calkowita, to ja wypisujemy. Jezeli jest ujemna albo niecalkowita,
// to wypisujemy komunikat o bledzie.

#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    try
    {
        double a;
        cout << "Podaj liczbe: ";
        cin >> a;

        if (a < 0)
        {
            throw runtime_error("Liczba jest ujemna");
        }
        if (a - (int)a != 0)
        {
            throw logic_error("Liczba jest niecalkowita");
        }
        cout << "Podana liczba: " << a << endl;
    }
    catch (runtime_error &e)
    {
        cout << "runtime_error: " << e.what() << endl;
    }
    catch (logic_error &e)
    {
        cout << "logic_error: " << e.what() << endl;
    }

    return 0;
}
