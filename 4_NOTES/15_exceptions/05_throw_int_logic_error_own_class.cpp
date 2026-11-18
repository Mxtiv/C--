// ======================================================================
// throw int / logic_error("...") / own simple class (exercise text below)
// Original file: TryCatch/practice2.cpp
// ======================================================================

#include <iostream>
#include <string>
#include <stdexcept>      // logic_error
using namespace std;

// najprostsza wlasna klasa wyjatku - zwykla klasa z polem na komunikat
class ZaDuzaLiczba
{
public:
    string komunikat;

    ZaDuzaLiczba(string nowyKomunikat)
    {
        komunikat = nowyKomunikat;
    }
};

int main()
{
    int liczba;

    cout << "Podaj liczbe: ";
    cin >> liczba;

    try
    {
        if (liczba < 0)
        {
            throw -3;
        }
        if (liczba % 5 != 0)
        {
            throw logic_error("Liczba musi byc podzielna przez 5");
        }
        if (liczba > 100)
        {
            throw ZaDuzaLiczba("Za duza liczba na konkurs");
        }
        cout << "Zgloszenie przyjete: " << liczba << endl;
    }
    catch (int)
    {
        cout << "Liczby ujemne nie sa dozwolone" << endl;
    }
    catch (logic_error &e)
    {
        cout << e.what() << endl;
    }
    catch (ZaDuzaLiczba blad)         // zwykla klasa - mozna lapac przez wartosc
    {
        cout << blad.komunikat << endl;
    }

    return 0;
}

// Cwiczenie: sprawdz liczbe zgloszona do konkursu
// - liczba < 0               -> throw int,         "Liczby ujemne nie sa dozwolone"
// - nie dzieli sie przez 5   -> throw logic_error, "Liczba musi byc podzielna przez 5"
// - liczba > 100             -> throw wlasnej klasy, "Za duza liczba na konkurs"
// - poprawna                 -> "Zgloszenie przyjete: [liczba]"
// Przyklady:  -3 -> ujemna,  7 -> nie przez 5,  123 -> za duza,  50 -> przyjete
