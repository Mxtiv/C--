// ======================================================================
// derived class redeclares `cyfra`, hiding the base field
// Original file: unsorted/various/dziedziczenietask.cpp
// FIXED - the bug was: cyfra is never initialized
// ======================================================================

#include <iostream>
using namespace std;

class Liczba1
{
public:
    int cyfra;

    Liczba1()
    {
        cyfra = 0;
    }

    void zwieksz()
    {
        cyfra++;
        cout << "Wywolanie zwieksz() z klasy Liczba1" << endl;
    }
};

class Liczba2 : public Liczba1
{
public:
    int cyfra;              // NOWE pole o tej samej nazwie -> ukrywa pole z bazy

    Liczba2()
    {
        cyfra = 0;
    }

    void zwieksz()
    {
        cyfra = cyfra + 2;  // zmienia Liczba2::cyfra, a nie Liczba1::cyfra
        cout << "Wywolanie zwieksz() z klasy Liczba2" << endl;
    }
};

int main()
{
    Liczba1 liczba1;
    liczba1.zwieksz();

    Liczba2 liczba2;
    liczba2.zwieksz();

    cout << "liczba1.cyfra = " << liczba1.cyfra << endl;
    cout << "liczba2.cyfra = " << liczba2.cyfra << endl;
    cout << "ukryta czesc z bazy liczba2.Liczba1::cyfra = " << liczba2.Liczba1::cyfra << endl;
    return 0;
}
