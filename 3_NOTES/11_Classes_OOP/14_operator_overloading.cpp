// ======================================================================
// ADDED (gap-fill): operator overloading (przeciążanie operatorów) on Ulamek:
//   +  and ==  as methods        a + b  means  a.operator+(b)
//   <<         as a friend       (the left side is cout, not our object)
// Same idea as 11_fraction_friend_functions.cpp, but with operators
// instead of named functions dodaj / pomnoz.
// The ostream & in operator<< is required by C++ - it's the topic here.
// ======================================================================

#include <iostream>
using namespace std;

class Ulamek
{
private:
    int licznik;
    int mianownik;

public:
    Ulamek(int nowyLicznik, int nowyMianownik)
    {
        licznik = nowyLicznik;
        mianownik = nowyMianownik;
    }

    // a + b
    Ulamek operator+(Ulamek drugi)
    {
        Ulamek wynik(licznik * drugi.mianownik + drugi.licznik * mianownik, mianownik * drugi.mianownik);
        return wynik;
    }

    // a == b   (1/2 == 2/4 -> porównujemy na krzyż)
    bool operator==(Ulamek drugi)
    {
        return licznik * drugi.mianownik == drugi.licznik * mianownik;
    }

    // cout << a
    friend ostream &operator<<(ostream &wyjscie, Ulamek u)
    {
        wyjscie << u.licznik << "/" << u.mianownik;
        return wyjscie;      // zwracamy strumień, żeby działało cout << a << b
    }
};

int main()
{
    Ulamek a(1, 2);
    Ulamek b(1, 4);

    cout << a << " + " << b << " = " << a + b << endl;     // 6/8

    if (a == Ulamek(2, 4))
    {
        cout << "1/2 == 2/4" << endl;
    }

    return 0;
}
