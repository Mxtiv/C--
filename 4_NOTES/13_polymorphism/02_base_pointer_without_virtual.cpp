// ======================================================================
// base-class pointer to derived objects WITHOUT virtual -> base method is called (why you need virtual)
// Original file: unsorted/various/dziedziczenieDynamic.cpp
// FIXED: the closing } of main was missing
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class Pracownik
{
public:
    string imie;
    string nazwisko;

    void zwrocDane();           // BEZ virtual
};

class Nauczyciel : public Pracownik
{
public:
    string przedmiot;

    void zwrocDane();
};

// metody zdefiniowane POZA klasa (Klasa::metoda)
void Pracownik::zwrocDane()
{
    cout << "zwrocDane() z klasy Pracownik: " << imie << " " << nazwisko << endl;
}

void Nauczyciel::zwrocDane()
{
    cout << "zwrocDane() z klasy Nauczyciel: " << imie << " " << nazwisko << ", " << przedmiot << endl;
}

int main()
{
    // wskaznik do klasy BAZOWEJ moze pokazywac na obiekt klasy POCHODNEJ
    Pracownik *wskaznik;

    Pracownik pracownik;
    wskaznik = &pracownik;
    wskaznik->imie = "Jan";
    wskaznik->nazwisko = "Kowalski";
    wskaznik->zwrocDane();      // Pracownik::zwrocDane

    Nauczyciel nauczyciel;
    wskaznik = &nauczyciel;
    wskaznik->imie = "Adam";
    wskaznik->nazwisko = "Nowak";
    // wskaznik->przedmiot = "informatyka";  // BLAD - przez wskaznik bazowy widac tylko to, co jest w Pracownik
    nauczyciel.przedmiot = "informatyka";

    wskaznik->zwrocDane();      // UWAGA: Pracownik::zwrocDane, bo NIE MA virtual!
    nauczyciel.zwrocDane();     // Nauczyciel::zwrocDane (wolane bezposrednio na obiekcie)

    // bez virtual o wyborze metody decyduje TYP WSKAZNIKA (Pracownik*),
    // z virtual decyduje TYP OBIEKTU, na ktory wskaznik pokazuje - patrz 03_
    return 0;
}
