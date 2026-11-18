// ======================================================================
// test group A: read a positive EVEN number; each kind of wrong input is reported
// with a different exception mechanism
// Original file: TryCatch/test1.cpp
// FIXED - the bugs were: `num % 2 == 0` threw OddNumber for EVEN numbers (reversed);
// num was int, so the "not an integer" check could never fire (now read as double);
// checks reordered so every case is reachable.
// ======================================================================

// Grupa A. Pobierz liczbe parzysta dodatnia od uzytkownika: jezeli jest parzysta dodatnia, to wypisz "JD".
// Jezeli liczba jest ujemna - blad wyrzucany przez typ zmiennej.
// Jezeli liczba jest nieparzysta - blad wyrzucany przy pomocy klasy exception.
// Jezeli liczba jest niecalkowita - blad wyrzucany przy pomocy klasy runtime_error.
// Jezeli jest rowna 0 - blad obsluguje klasa pochodna od runtime_error.

#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

// klasa pochodna od runtime_error: konstruktor przekazuje komunikat do klasy bazowej.
// Wywolanie konstruktora klasy bazowej MUSI byc po dwukropku - inaczej sie nie da.
class LiczbaZero : public runtime_error
{
public:
    LiczbaZero() : runtime_error("Liczba nie moze wynosic zero")
    {
    }
};

int main()
{
    double liczba;
    cout << "Podaj liczbe parzysta dodatnia: ";
    cin >> liczba;

    try
    {
        if (liczba < 0)
        {
            throw 1;                                            // typ zmiennej (int)
        }
        if (liczba == 0)
        {
            throw LiczbaZero();                                 // klasa pochodna od runtime_error
        }
        if (liczba != (int)liczba)
        {
            throw runtime_error("Liczba musi byc calkowita");   // runtime_error
        }
        if ((int)liczba % 2 != 0)
        {
            throw exception();                                  // sama klasa exception
        }
        cout << "JD" << endl;
    }
    catch (int)
    {
        cout << "Liczby ujemne nie sa dozwolone!" << endl;
    }
    catch (runtime_error &e)       // lapie tez LiczbaZero (ona JEST runtime_error)
    {
        cout << e.what() << endl;
    }
    catch (exception &e)           // zwykly exception - na koncu, bo lapie wszystkie wyjatki biblioteki
    {
        cout << "Liczba musi byc parzysta" << endl;
    }
    return 0;
}
