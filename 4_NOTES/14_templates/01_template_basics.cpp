// ======================================================================
// ADDED (gap-fill): the simplest templates - function template,
// class template Pudelko<T>, explicit vs implicit (deduced) types
// Not from your original repo - written to fill a missing topic.
// Then continue with files 02..07 (specialization = specjalizacja,
// instantiation = konkretyzacja).
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

// ---------------- szablon funkcji (function template) ----------------
// T to "typ zastepczy". Kompilator sam tworzy wieksza<int>, wieksza<double>...
// dopiero gdy funkcja zostanie uzyta (to jest konkretyzacja).
template <typename T>
T wieksza(T a, T b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

template <typename T>
void wypiszTablice(T tab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
}

// ---------------- szablon klasy (class template) ----------------
template <typename T>
class Pudelko
{
private:
    T wartosc;

public:
    Pudelko(T nowaWartosc)
    {
        wartosc = nowaWartosc;
    }

    T getWartosc()
    {
        return wartosc;
    }

    void pokaz();                         // definicja ponizej, poza klasa
};

template <typename T>                     // poza klasa trzeba znowu napisac linie template
void Pudelko<T>::pokaz()
{
    cout << "Pudelko zawiera: " << wartosc << endl;
}

int main()
{
    cout << wieksza(3, 7) << endl;               // niejawnie (implicit): T = int, kompilator sam zgaduje
    cout << wieksza(2.5, 1.5) << endl;           // T = double
    cout << wieksza<double>(3, 7.5) << endl;     // jawnie (explicit): potrzebne, gdy typy sa rozne
    cout << wieksza<string>("ala", "ola") << endl;

    int liczby[3] = {1, 2, 3};
    string slowa[2] = {"jeden", "dwa"};
    wypiszTablice(liczby, 3);
    wypiszTablice(slowa, 2);

    Pudelko<int> pudelkoInt(42);                 // przy klasie typ piszemy w < >
    Pudelko<string> pudelkoTekst("tekst");
    cout << pudelkoInt.getWartosc() + 1 << endl;
    pudelkoInt.pokaz();
    pudelkoTekst.pokaz();

    return 0;
}
