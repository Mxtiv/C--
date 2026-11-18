// ======================================================================
// A const field CANNOT be assigned in the constructor body - it MUST be set
// in the initializer list. This is the one place where the list is required
// (not needed at the exam - there you simply don't make fields const).
// Also: constructor and method defined OUTSIDE the class (Klasa::metoda).
// Original file: unsorted/various/listaInicjalizacyjna.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class Pracownik
{
private:
    const int id;      // stała - ustawiona raz, potem nie da się zmienić
    string imie;

public:
    Pracownik(int noweId, string noweImie);   // tylko prototyp
    void wyswietlDane();
};

// definicja konstruktora poza klasą
Pracownik::Pracownik(int noweId, string noweImie) : id(noweId)   // const -> lista inicjalizacyjna
{
    // id = noweId;    // BŁĄD - do const nie można przypisać
    imie = noweImie;   // zwykłe pole - normalnie w ciele
}

void Pracownik::wyswietlDane()
{
    cout << "Id: " << id << ", imie: " << imie << endl;
}

int main()
{
    Pracownik p1(1, "Jan");
    p1.wyswietlDane();

    Pracownik p2(2, "Anna");
    p2.wyswietlDane();

    return 0;
}
