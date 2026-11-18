// ======================================================================
// ALL-IN-ONE summary: function template + specialization, class template
// + one-method specialization + class specialization, explicit vs implicit
// instantiation (konkretyzacja jawna / niejawna)
// Original file: unsorted/typename template/ultimate.cpp (shortened)
// ======================================================================

#include <iostream>
#include <cmath>
using namespace std;

// ---------------- szablon funkcji ----------------
template <typename T1, typename T2>
T1 funkcja(T1 zmienna1, T2 zmienna2)
{
    cout << "Ogolny szablon - iloczyn: ";
    return zmienna1 * zmienna2;
}

// specjalizacja dla int, float - potega
template <>
int funkcja<int, float>(int zmienna1, float zmienna2)
{
    cout << "Specjalizacja int float - potega: ";
    return (int)pow(zmienna1, zmienna2);
}

// konkretyzacja JAWNA funkcji: kompilator ma od razu zbudowac wersje double,double
template double funkcja<double, double>(double zmienna1, double zmienna2);

// ---------------- szablon klasy ----------------
template <typename T1, typename T2>
class SzablonKlasy
{
public:
    T1 pole1;
    T2 pole2;

    void wyswietl()
    {
        cout << "Konkretyzacja" << endl;
    }
};

// specjalizacja jednej metody
template <>
void SzablonKlasy<double, float>::wyswietl()
{
    cout << "Specjalizacja metody double float" << endl;
}

// specjalizacja calej klasy
template <>
class SzablonKlasy<int, float>
{
public:
    void wyswietl()
    {
        cout << "Specjalizacja klasy int float" << endl;
    }
};

// konkretyzacja JAWNA klasy
template class SzablonKlasy<char, char>;

int main()
{
    cout << funkcja<int, float>(2, 3.0f) << endl;   // specjalizacja (wywolanie jawne)   -> 8
    cout << funkcja(2, 3.0f) << endl;               // specjalizacja (wywolanie niejawne) -> 8
    cout << funkcja(2.0, 4.0) << endl;              // konkretyzacja -> 8

    SzablonKlasy<int, float> obiekt1;
    obiekt1.wyswietl();                             // specjalizacja klasy
    SzablonKlasy<double, float> obiekt2;
    obiekt2.wyswietl();                             // specjalizacja metody
    SzablonKlasy<int, int> obiekt3;
    obiekt3.wyswietl();                             // konkretyzacja niejawna (przy tworzeniu obiektu)
    SzablonKlasy<char, char> obiekt4;
    obiekt4.wyswietl();                             // konkretyzacja jawna (linia template class ...)

    return 0;
}
