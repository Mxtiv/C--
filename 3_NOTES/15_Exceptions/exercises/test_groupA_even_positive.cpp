// ======================================================================
// test group A: read a positive EVEN number; each kind of wrong input is reported
// with a different exception mechanism
// Original file: TryCatch/test1.cpp
// FIXED - the bugs were: `num % 2 == 0` threw OddNumber for EVEN numbers (reversed);
// num was int, so the "not an integer" check could never fire (now read as double);
// checks reordered so every case is reachable.
// ======================================================================

// Gupa A Pobierz liczbę parzystą dodatnią od użytkownika: jeżeli jest parzysta dodatnia to jest dobrze i się wypisuje komunikat "JD".
// Jeżeli liczba jest ujemna błąd z odpowiednim komunikatem jest wyrzucany przez typ zmiennej. Jeżeli liczba jest nieparzysta błąd jest wyrzucany przy pomocy klasy exception.
// Jeżeli liczba jest niecałkowita błąd wyrzucany jest przy pomocy klasy  runtime_error, jeżeli jest równa 0 blad obsługuje klasa pochodna od runtime_error.
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

class OddNumber : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Liczba musi byc parzysta";
    }
};

class numIsZero : public runtime_error
{
public:
    numIsZero() : runtime_error("Liczba nie moze wynosic zero") {}
};

int main()
{
    double num;
    cout << endl << "Podaj liczbe parzysta dodatnia: ";
    cin >> num;
    try
    {
        if (num < 0)
            throw 1;                                         // by variable type (int)
        if (num == 0)
            throw numIsZero();                               // class derived from runtime_error
        if (num != (int)num)
            throw runtime_error("Liczba musi byc calkowita."); // runtime_error
        if ((int)num % 2 != 0)
            throw OddNumber();                               // class derived from exception
        cout << "JD" << endl;
    }
    catch (int)
    {
        cout << "Liczby ujemne nie sa dozwolone!" << endl;
    }
    catch (const OddNumber &e)
    {
        cout << e.what() << endl;
    }
    catch (const runtime_error &e)     // catches numIsZero too (it IS a runtime_error)
    {
        cout << e.what() << endl;
    }
    return 0;
}
