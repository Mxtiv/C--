// ======================================================================
// prototypes before main, a Pracownik& parameter (the function fills the caller's object)
// Original file: unsorted/various/referencje.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

// Definicja struktury Pracownik:
struct Pracownik
{
    string imie;
    string nazwisko;
};

// Prototypy funkcji zewnętrznych:
void pobierzDane(Pracownik &p);
void wyswietlDane(Pracownik p);

// PROGRAM GŁÓWNY
int main()
{
    Pracownik pracownik;            // utworzenie obiektu
    pobierzDane(pracownik);         // dane z klawiatury trafiają PROSTO do obiektu pracownik
    wyswietlDane(pracownik);        // prezentacja danych na ekranie
    return 0;
}

// Definicje funkcji zewnętrznych:

// & - p to INNA NAZWA obiektu z main, więc zmiany w p są zmianami w pracownik
void pobierzDane(Pracownik &p)
{
    cout << "Imię = ";
    cin >> p.imie;
    cout << "Nazwisko = ";
    cin >> p.nazwisko;
}

// bez & - funkcja dostaje kopię, tylko ją czyta
// (w książkach zobaczysz też "const Pracownik &p" - bez kopiowania i bez możliwości zmiany)
void wyswietlDane(Pracownik p)
{
    cout << "Imię: " << p.imie << endl;
    cout << "Nazwisko: " << p.nazwisko << endl;
}
