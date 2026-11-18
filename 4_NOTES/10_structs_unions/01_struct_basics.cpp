// ======================================================================
// struct with a method, init with {}, dot / -> access, array of structs,
// struct as a function parameter, returning a struct
// Original file: Structs/basicsStructures.cpp
// FIXED: wyswietlOsobe/utworzOsobe were defined inside main - moved above main
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

// A struct groups several values that belong together
struct Osoba
{
    string imie;
    int wiek;
    double wzrost;

    // A function inside the struct (method) - sees the fields directly
    void wyswietl()
    {
        cout << "Name: " << imie << ", Age: " << wiek << ", Height: " << wzrost << " m" << endl;
    }
};

// A normal function that gets a struct (by value - a copy, only read)
void wyswietlOsobe(Osoba osoba)
{
    cout << osoba.imie << " (" << osoba.wiek << ")" << endl;
}

// A function can return a whole struct
Osoba utworzOsobe(string imie, int wiek, double wzrost)
{
    Osoba nowa;
    nowa.imie = imie;
    nowa.wiek = wiek;
    nowa.wzrost = wzrost;
    return nowa;
}

int main()
{
    // ---------------- creating: field by field ----------------
    Osoba osoba1;
    osoba1.imie = "Alice";
    osoba1.wiek = 30;
    osoba1.wzrost = 1.75;
    osoba1.wyswietl();

    // ---------------- creating: all fields at once, in order ----------------
    Osoba osoba2 = {"Bob", 25, 1.80};
    osoba2.wyswietl();

    // ---------------- reading fields with a dot ----------------
    cout << "Person 1's name is: " << osoba1.imie << endl;

    // ---------------- through a pointer: -> instead of . ----------------
    Osoba *wskOsoba = &osoba1;
    cout << "Pointer accessing Person 1's age: " << wskOsoba->wiek << endl;

    // ---------------- array of structs ----------------
    const int ILE = 3;
    Osoba ludzie[ILE] = {
        {"Charlie", 22, 1.85},
        {"David", 28, 1.78},
        {"Eva", 26, 1.65}
    };
    cout << "Array of people:" << endl;
    for (int i = 0; i < ILE; i++)
    {
        ludzie[i].wyswietl();
    }

    // ---------------- struct to / from a function ----------------
    wyswietlOsobe(osoba2);
    Osoba osoba3 = utworzOsobe("Fay", 31, 1.70);
    wyswietlOsobe(osoba3);

    return 0;
}
