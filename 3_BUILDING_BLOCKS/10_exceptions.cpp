// ======================================================================
// BUILDING BLOCKS: exceptions (wyjątki) - throw / try / catch
//   EXC-03 a function that throws runtime_error (division by zero) + try/catch with e.what()
//   EXC-05 throw an int or a string, catch them by type, catch (...) for anything else
// HOW TO USE: copy the comment box + code under a //@ line, up to the next //@ line.
// ======================================================================

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

//@ EXC-03 | function that THROWS runtime_error on bad input (division by zero) + try/catch | <iostream> <stdexcept>
/********************************************************
 * nazwa funkcji: podziel
 * opis funkcji: dzieli dwie liczby; przy dzieleniu przez zero zgłasza wyjątek runtime_error
 * parametry: a - dzielna
 *            b - dzielnik
 * zwracany typ i opis: double - iloraz a / b
 * autor: <numer zdającego>
 ********************************************************/
double podziel(double a, double b)
{
    if (b == 0)
    {
        throw runtime_error("Dzielenie przez zero!");     // the function stops here
    }
    return a / b;
}
// usage:  try
//         {
//             cout << podziel(10, 0) << endl;
//         }
//         catch (runtime_error &e)
//         {
//             cout << "Blad: " << e.what() << endl;     // what() gives the message
//         }

//@ EXC-05 | throw an int or a string, catch each type in its own catch, catch (...) last | <iostream> <string>
/********************************************************
 * nazwa funkcji: sprawdzWiek
 * opis funkcji: sprawdza wiek i zgłasza wyjątek: int - gdy wiek jest ujemny,
 *               string - gdy wiek jest większy niż 130
 * parametry: wiek - sprawdzany wiek
 * zwracany typ i opis: int - poprawny wiek
 * autor: <numer zdającego>
 ********************************************************/
int sprawdzWiek(int wiek)
{
    if (wiek < 0)
    {
        throw wiek;                                  // throws an int
    }
    if (wiek > 130)
    {
        throw string("Wiek powyzej 130 lat");        // string(...) - a bare "..." would NOT be caught by catch (string)
    }
    return wiek;
}
// usage:  try
//         {
//             int poprawny = sprawdzWiek(wiek);       // if it throws, the next line is skipped
//             cout << "OK " << poprawny << endl;
//         }
//         catch (int blad)
//         {
//             cout << "Wiek ujemny: " << blad << endl;
//         }
//         catch (string komunikat)
//         {
//             cout << komunikat << endl;
//         }
//         catch (...)                                   // any other type - always LAST
//         {
//             cout << "Nieznany blad" << endl;
//         }

// ====================== DEMO (don't copy) ======================
int main()
{
    try
    {
        cout << podziel(10, 4) << endl;
        cout << podziel(1, 0) << endl;               // not printed - exception
    }
    catch (runtime_error &e)
    {
        cout << "zlapano: " << e.what() << endl;
    }

    int proby[3] = {17, -3, 150};
    for (int i = 0; i < 3; i++)
    {
        try
        {
            int poprawny = sprawdzWiek(proby[i]);
            cout << "OK " << poprawny << endl;
        }
        catch (int blad)
        {
            cout << "wiek ujemny: " << blad << endl;
        }
        catch (string komunikat)
        {
            cout << komunikat << endl;
        }
        catch (...)
        {
            cout << "nieznany blad" << endl;
        }
    }
    return 0;
}
