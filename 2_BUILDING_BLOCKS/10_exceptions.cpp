// ======================================================================
// BUILDING BLOCKS: exceptions (wyjątki) - own exception classes, a function that
// throws, safe string->number, full read-validate-catch pattern
// HOW TO USE: copy the comment box + code under a //@ line, up to the next //@ line.
// ======================================================================

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
using namespace std;

//@ EXC-01 | own exception class derived from std::exception (fixed message via what()) | <exception>
/********************************************************
 * nazwa klasy: BladDanych
 * opis klasy: własny wyjątek zgłaszany przy niepoprawnych danych
 * pola: brak
 * autor: <numer zdającego>
 ********************************************************/
class BladDanych : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Niepoprawne dane";
    }
};

//@ EXC-02 | own exception class with ANY message (derived from runtime_error) | <stdexcept> <string>
/********************************************************
 * nazwa klasy: BladZakresu
 * opis klasy: własny wyjątek z dowolnym komunikatem, zgłaszany przy wartości spoza zakresu
 * pola: brak (komunikat przechowuje klasa bazowa runtime_error)
 * autor: <numer zdającego>
 ********************************************************/
class BladZakresu : public runtime_error
{
public:
    BladZakresu(const string &komunikat) : runtime_error(komunikat) {}
};

//@ EXC-03 | function that THROWS on bad input (division by zero) | <stdexcept>
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
        throw runtime_error("Dzielenie przez zero!");
    return a / b;
}

//@ EXC-04 | safe text -> int: true/false instead of a crash (catches stoi exceptions) | <string> <stdexcept>
/********************************************************
 * nazwa funkcji: bezpieczneStoi
 * opis funkcji: zamienia napis na liczbę całkowitą, przechwytując wyjątki funkcji stoi
 * parametry: tekst - napis do zamiany
 *            wynik - (wyjście) liczba, gdy zamiana się udała
 * zwracany typ i opis: bool - true, gdy napis był poprawną liczbą
 * autor: <numer zdającego>
 ********************************************************/
bool bezpieczneStoi(const string &tekst, int &wynik)
{
    try
    {
        size_t uzyte;
        wynik = stoi(tekst, &uzyte);
        return uzyte == tekst.length();          // "12abc" -> false
    }
    catch (const invalid_argument &) { return false; }   // "abc"
    catch (const out_of_range &)     { return false; }   // "99999999999"
}

//@ EXC-05 | full pattern: read -> validate -> throw -> catch by type (int / own class / std::exception / ...) (needs EXC-02) | <iostream> <string> <stdexcept>
/********************************************************
 * nazwa funkcji: sprawdzWiek
 * opis funkcji: sprawdza podany tekst jako wiek i zgłasza wyjątki różnych typów:
 *               int - liczba ujemna, BladZakresu - wiek powyżej 130,
 *               invalid_argument - tekst nie jest liczbą
 * parametry: tekst - wiek podany jako napis
 * zwracany typ i opis: int - poprawny wiek
 * autor: <numer zdającego>
 ********************************************************/
int sprawdzWiek(const string &tekst)
{
    int wiek = stoi(tekst);                       // throws invalid_argument for "abc"
    if (wiek < 0) throw wiek;                     // throw a value of type int
    if (wiek > 130) throw BladZakresu("Wiek powyzej 130 lat");
    return wiek;
}
// usage (catch the MOST specific types first, catch(...) last):
//    try { int w = sprawdzWiek(tekst); cout << "OK " << w; }
//    catch (int w)                        { cout << "Wiek ujemny: " << w; }
//    catch (const BladZakresu &e)         { cout << e.what(); }
//    catch (const invalid_argument &)     { cout << "To nie jest liczba"; }
//    catch (const exception &e)           { cout << "Inny blad: " << e.what(); }
//    catch (...)                          { cout << "Nieznany blad"; }

// ====================== DEMO (don't copy) ======================
int main()
{
    try { podziel(1, 0); }
    catch (const runtime_error &e) { cout << "zlapano: " << e.what() << endl; }

    try { throw BladDanych(); }
    catch (const exception &e) { cout << "zlapano: " << e.what() << endl; }

    int x;
    cout << "\"42\" -> " << bezpieczneStoi("42", x) << " (" << x << "), \"4x\" -> " << bezpieczneStoi("4x", x)
         << ", \"abc\" -> " << bezpieczneStoi("abc", x) << endl;

    string proby[] = {"17", "-3", "150", "abc"};
    for (const string &tekst : proby)
    {
        try { int w = sprawdzWiek(tekst); cout << tekst << ": OK " << w << endl; }
        catch (int w)                    { cout << tekst << ": wiek ujemny " << w << endl; }
        catch (const BladZakresu &e)     { cout << tekst << ": " << e.what() << endl; }
        catch (const invalid_argument &) { cout << tekst << ": to nie jest liczba" << endl; }
        catch (...)                      { cout << tekst << ": nieznany blad" << endl; }
    }
    return 0;
}
