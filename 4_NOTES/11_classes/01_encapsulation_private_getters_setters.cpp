// ======================================================================
// Hermetyzacja (encapsulation): private fields, public setter and getters.
// Commented lines in main show what is NOT allowed.
// Original file: unsorted/hermetyzacja/hermetization.cpp
// ======================================================================

#include <iostream>
using namespace std;

/********************************************************
 * nazwa klasy: Liczby
 * opis klasy: przechowuje dwie liczby schowane jako private
 * pola: liczba1, liczba2 - przechowywane liczby
 ********************************************************/
class Liczby
{
private:                 // dostęp tylko z metod tej klasy
    int liczba1;
    int liczba2;

public:
    Liczby()
    {
        liczba1 = 0;
        liczba2 = 0;
    }

    // setter - jedyna droga, żeby zmienić prywatne pola
    void setLiczby(int wartosc1, int wartosc2)
    {
        liczba1 = wartosc1;
        liczba2 = wartosc2;
    }

    // gettery - zwracają kopię wartości pola
    int getLiczba1()
    {
        return liczba1;
    }

    int getLiczba2()
    {
        return liczba2;
    }

    // getter oddający DWIE wartości naraz - przez parametry z &
    void getLiczby(int &wartosc1, int &wartosc2)
    {
        wartosc1 = liczba1;
        wartosc2 = liczba2;
    }
};

int main()
{
    int jeden;
    int dwa;
    cout << "Podaj dwie liczby: ";
    cin >> jeden >> dwa;

    Liczby obiekt;                 // tworzymy obiekt klasy Liczby
    // cout << obiekt.liczba1;     // BŁĄD - liczba1 jest private
    // obiekt.liczba1 = jeden;     // BŁĄD - liczba1 jest private
    obiekt.setLiczby(jeden, dwa);  // OK - publiczny setter

    cout << "liczba1 = " << obiekt.getLiczba1() << endl;
    cout << "liczba2 = " << obiekt.getLiczba2() << endl;

    int a;
    int b;
    obiekt.getLiczby(a, b);        // obie wartości przez referencje
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}
