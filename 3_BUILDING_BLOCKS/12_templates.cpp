// ======================================================================
// BUILDING BLOCKS: templates (szablony) - function template, class template,
// full specialization (specjalizacja) vs instantiation (konkretyzacja)
// HOW TO USE: copy the comment box + code under a //@ line, up to the next //@ line.
//   konkretyzacja (instantiation) = the compiler makes a version of the template for the
//                                   types you use, e.g. wiekszy<int>, from the general code
//   specjalizacja (specialization) = YOU write a separate version for chosen types: template <>
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

//@ TPL-01 | function template: larger of two values of ANY type | -
/********************************************************
 * nazwa funkcji: wiekszy
 * opis funkcji: szablon funkcji zwracający większą z dwóch wartości dowolnego typu
 * parametry: a - pierwsza wartość
 *            b - druga wartość
 * zwracany typ i opis: T - większa z wartości
 * autor: <numer zdającego>
 ********************************************************/
template <typename T>
T wiekszy(T a, T b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

//@ TPL-02 | function template: display an array of ANY type | <iostream>
/********************************************************
 * nazwa funkcji: wyswietlDowolna
 * opis funkcji: szablon funkcji wyświetlający elementy tablicy dowolnego typu
 * parametry: tab - tablica
 *            n - liczba elementów
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
template <typename T>
void wyswietlDowolna(T tab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
}

//@ TPL-03 | class template with TWO type parameters: constructor, getters, display | <iostream>
/********************************************************
 * nazwa klasy: Para
 * opis klasy: szablon klasy przechowującej dwie wartości dowolnych typów
 * pola: pierwsza - wartość typu T1
 *       druga - wartość typu T2
 * autor: <numer zdającego>
 ********************************************************/
template <typename T1, typename T2>
class Para
{
private:
    T1 pierwsza;
    T2 druga;

public:
    Para(T1 a, T2 b)
    {
        pierwsza = a;
        druga = b;
    }

    T1 getPierwsza()
    {
        return pierwsza;
    }

    T2 getDruga()
    {
        return druga;
    }

    void wyswietl()
    {
        cout << "(" << pierwsza << ", " << druga << ")" << endl;
    }
};
// usage:  Para<string, int> p("Ala", 17);      // the types go in < >
//         p.wyswietl();

//@ TPL-04 | function template + a full SPECIALIZATION for <int, float>; other types = instantiation | <iostream>
/********************************************************
 * nazwa funkcji: oblicz
 * opis funkcji: szablon funkcji dwóch argumentów: dla typów <int, float> (specjalizacja)
 *               zwraca średnią, dla pozostałych typów (konkretyzacja) zwraca sumę
 * parametry: a - pierwszy argument
 *            b - drugi argument
 * zwracany typ i opis: double - wynik obliczenia
 * autor: <numer zdającego>
 ********************************************************/
template <typename T1, typename T2>
double oblicz(T1 a, T2 b)                         // general version -> konkretyzacja for any types
{
    cout << "konkretyzacja (suma): ";
    return a + b;
}

template <>
double oblicz<int, float>(int a, float b)         // specjalizacja: own code only for int, float
{
    cout << "specjalizacja int,float (srednia): ";
    return (a + b) / 2.0;
}
// calls:  oblicz<int, float>(3, 4.5f)   -> specjalizacja
//         oblicz(2.0, 3.0)             -> konkretyzacja for double, double (types deduced)

// ====================== DEMO (don't copy) ======================
int main()
{
    cout << wiekszy(3, 7) << " " << wiekszy(2.5, 1.5) << " " << wiekszy<string>("ala", "ola") << endl;
    double d[2] = {1.5, 2.5};
    wyswietlDowolna(d, 2);
    string s[3] = {"ala", "ma", "kota"};
    wyswietlDowolna(s, 3);
    Para<string, int> p("Ala", 17);
    p.wyswietl();
    cout << p.getPierwsza() << " ma " << p.getDruga() << " lat" << endl;
    cout << oblicz<int, float>(3, 4.5f) << endl;
    cout << oblicz(2.0, 3.0) << endl;
    cout << oblicz(1, 2) << endl;
    return 0;
}
