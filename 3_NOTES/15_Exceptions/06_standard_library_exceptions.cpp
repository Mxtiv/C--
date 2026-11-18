// ======================================================================
// ADDED (gap-fill): exceptions thrown BY THE LIBRARY and how to catch them -
// stoi (invalid_argument), string.at() (out_of_range), own runtime_error,
// catch order: specific first, exception & next, (...) last
// Not from your original repo - written to fill a missing topic.
// ======================================================================

#include <iostream>
#include <string>
#include <stdexcept>   // runtime_error, invalid_argument, out_of_range
using namespace std;

int main()
{
    // ---------------- stoi: tekst, ktory nie jest liczba ----------------
    try
    {
        int liczba = stoi("abc");          // rzuca invalid_argument
        cout << liczba << endl;            // ta linia sie nie wykona
    }
    catch (invalid_argument &e)
    {
        cout << "To nie jest liczba" << endl;
    }

    // ---------------- .at() sprawdza zakres, [] NIE sprawdza ----------------
    string tekst = "Ala";
    try
    {
        cout << tekst.at(10) << endl;      // rzuca out_of_range
    }
    catch (out_of_range &e)
    {
        cout << "Indeks poza napisem" << endl;
    }

    // ---------------- kolejnosc catch: szczegolowe najpierw, ogolne na koncu ----------------
    try
    {
        throw runtime_error("cos poszlo nie tak");
    }
    catch (runtime_error &e)
    {
        cout << "runtime_error: " << e.what() << endl;
    }
    catch (exception &e)                   // klasa bazowa WSZYSTKICH wyjatkow biblioteki
    {
        cout << "inny wyjatek biblioteki: " << e.what() << endl;
    }
    catch (...)                            // cokolwiek innego (int, tekst...)
    {
        cout << "nieznany blad" << endl;
    }

    return 0;
}
