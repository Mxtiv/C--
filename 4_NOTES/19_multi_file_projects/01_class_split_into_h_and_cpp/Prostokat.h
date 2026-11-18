// ======================================================================
// ADDED (gap-fill): the CORRECT way to split a class into .h + .cpp
// HEADER (.h): only DECLARATIONS. Protected by an include guard.
// Never #include a .cpp file.
// Build:  g++ main.cpp Prostokat.cpp -o program.exe
// ======================================================================

#ifndef PROSTOKAT_H        // include guard: jesli jeszcze nie zdefiniowane...
#define PROSTOKAT_H        // ...zdefiniuj - drugi #include tego pliku zostanie pominiety

#include <string>
using namespace std;       // w duzych projektach unika sie tego w .h - na egzaminie mozna

/********************************************************
 * nazwa klasy: Prostokat
 * opis klasy: prostokat o bokach a i b, liczy pole i obwod
 * pola: a, b - dlugosci bokow
 *       liczbaProstokatow - wspolny licznik utworzonych obiektow
 * autor: <numer zdającego>
 ********************************************************/
class Prostokat
{
private:
    double a;
    double b;
    static int liczbaProstokatow;   // tu tylko DEKLARACJA, definicja w Prostokat.cpp

public:
    Prostokat();                    // same naglowki metod (prototypy)
    Prostokat(double bokA, double bokB);
    double pole();
    double obwod();
    bool czyKwadrat();
    void wypisz();
    static int ile();
};

// prototyp zwyklej funkcji (definicja w Prostokat.cpp)
bool czyWiekszy(Prostokat p1, Prostokat p2);

#endif // PROSTOKAT_H
