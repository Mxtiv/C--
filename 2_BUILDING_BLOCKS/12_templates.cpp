// ======================================================================
// BUILDING BLOCKS: templates (szablony) - function template, class template,
// full specialization (specjalizacja) vs instantiation (konkretyzacja)
// HOW TO USE: copy the comment box + code under a //@ line, up to the next //@ line.
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
    return (a > b) ? a : b;
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
void wyswietlDowolna(const T tab[], int n)
{
    for (int i = 0; i < n; i++)
        cout << tab[i] << " ";
    cout << endl;
}

//@ TPL-03 | class template with TWO type parameters + a method defined outside the class | <iostream>
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
public:
    T1 pierwsza;
    T2 druga;

    Para(T1 a, T2 b) : pierwsza(a), druga(b) {}
    void wyswietl() const;
};

template <typename T1, typename T2>              // outside definition repeats the template line
void Para<T1, T2>::wyswietl() const
{
    cout << "(" << pierwsza << ", " << druga << ")" << endl;
}

//@ TPL-04 | function template + 2 full SPECIALIZATIONS (int,float and double,double); other types = instantiation | <iostream>
/********************************************************
 * nazwa funkcji: oblicz
 * opis funkcji: szablon funkcji dwóch argumentów: dla <int, float> zwraca średnią,
 *               dla <double, double> iloczyn, dla pozostałych typów (konkretyzacja) sumę
 * parametry: a - pierwszy argument
 *            b - drugi argument
 * zwracany typ i opis: double - wynik obliczenia
 * autor: <numer zdającego>
 ********************************************************/
template <typename T1, typename T2>
double oblicz(T1 a, T2 b)                         // general version -> konkretyzacja
{
    cout << "konkretyzacja (suma): ";
    return a + b;
}

template <>
double oblicz<int, float>(int a, float b)         // specjalizacja int, float
{
    cout << "specjalizacja int,float (srednia): ";
    return (a + b) / 2.0;
}

template <>
double oblicz<double, double>(double a, double b) // specjalizacja double, double
{
    cout << "specjalizacja double,double (iloczyn): ";
    return a * b;
}
// calls:  oblicz<int, float>(3, 4.5f)  - explicit (jawne)
//         oblicz(2.0, 3.0)            - implicit (niejawne), types deduced -> double,double

//@ TPL-05 | class template + full class SPECIALIZATION for one type pair | <iostream>
/********************************************************
 * nazwa klasy: Szablon
 * opis klasy: szablon klasy z metodą info(); dla typów <int, float> istnieje osobna
 *             specjalizacja, pozostałe typy używają wersji ogólnej (konkretyzacja)
 * pola: a, b - przechowywane wartości
 * autor: <numer zdającego>
 ********************************************************/
template <typename T1, typename T2>
class Szablon
{
public:
    T1 a;
    T2 b;
    void info() const { cout << "konkretyzacja" << endl; }
};

template <>
class Szablon<int, float>                         // the WHOLE class rewritten for int, float
{
public:
    int a;
    float b;
    void info() const { cout << "specjalizacja int, float" << endl; }
};
// specializing only ONE method instead:  template <> void Szablon<double, float>::info() const { ... }

// ====================== DEMO (don't copy) ======================
int main()
{
    cout << wiekszy(3, 7) << " " << wiekszy(2.5, 1.5) << " " << wiekszy<string>("ala", "ola") << endl;
    double d[] = {1.5, 2.5};
    wyswietlDowolna(d, 2);
    Para<string, int> p("Ala", 17);
    p.wyswietl();
    cout << oblicz<int, float>(3, 4.5f) << endl;
    cout << oblicz(2.0, 3.0) << endl;
    cout << oblicz(1, 2) << endl;
    Szablon<int, float> s1;
    Szablon<char, int> s2;
    s1.info();
    s2.info();
    return 0;
}
