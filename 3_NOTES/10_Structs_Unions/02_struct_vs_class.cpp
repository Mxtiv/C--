// ======================================================================
// struct (public by default) vs class (private by default), constructor in a struct,
// method in a struct, struct with an array of other structs inside
// Original file: Structs/overviewStructures.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

// 1. struct: everything is PUBLIC unless you write otherwise
struct Osoba
{
    string imie;
    int wiek;

    Osoba(string noweImie, int nowyWiek)    // a struct can have a constructor too
    {
        imie = noweImie;
        wiek = nowyWiek;
    }

    void wyswietl()
    {
        cout << "Person: " << imie << ", Age: " << wiek << endl;
    }
};

// 2. class: everything is PRIVATE unless you write public:
class Pracownik
{
private:
    string imie;
    int pensja;

public:
    Pracownik(string noweImie, int nowaPensja)
    {
        imie = noweImie;
        pensja = nowaPensja;
    }

    void wyswietl()
    {
        cout << "Employee Name: " << imie << ", Salary: " << pensja << endl;
    }
};

// 3. struct with a method that calculates something
struct Prostokat
{
    int szerokosc;
    int wysokosc;

    int pole()
    {
        return szerokosc * wysokosc;
    }
};

// 4. struct inside a struct (an array of them)
struct Uczen
{
    string imie;
    int ocena;
};

struct Kurs
{
    string nazwa;
    Uczen uczniowie[3];

    void wyswietl()
    {
        cout << "Course: " << nazwa << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "Student " << i + 1 << ": " << uczniowie[i].imie << ", Grade: " << uczniowie[i].ocena << endl;
        }
    }
};

int main()
{
    Osoba osoba("John", 25);
    osoba.wiek = 26;            // OK - struct fields are public
    osoba.wyswietl();

    Pracownik pracownik("Alice", 5000);
    // pracownik.pensja = 1;    // ERROR - class fields are private
    pracownik.wyswietl();

    Prostokat prostokat = {5, 10};
    cout << "Rectangle area: " << prostokat.pole() << endl;

    Kurs kurs;
    kurs.nazwa = "Math 101";
    kurs.uczniowie[0] = {"Alice", 5};
    kurs.uczniowie[1] = {"Bob", 4};
    kurs.uczniowie[2] = {"Charlie", 3};
    kurs.wyswietl();

    return 0;
}
