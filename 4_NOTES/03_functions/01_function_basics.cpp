// ======================================================================
// ADDED (gap-fill): function basics - prototype vs definition, return values,
// void, parameters, default arguments, passing arrays, returning several values
// Not from your original repo - written to fill a missing topic.
// Next file: 02_pass_by_value_reference_pointer.cpp (yours) shows the ways to pass data.
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

// ---------------- PROTOTYPES (declarations) ----------------
// Tell the compiler the function exists so main() can call it before its full definition.
int dodaj(int a, int b);
double srednia(int tab[], int n);
void rysujLinie(char znak = '-', int dlugosc = 20);     // default arguments go in the PROTOTYPE
void minMax(int tab[], int n, int &min, int &max);

// ---------------- definitions placed before main need no prototype ----------------
bool czyParzysta(int liczba)
{
    return liczba % 2 == 0;      // return ends the function immediately
}

string przywitaj(string imie)    // parameter by value - the function gets a copy
{
    return "Hi, " + imie + "!";
}

int main()
{
    cout << dodaj(2, 3) << endl;
    cout << czyParzysta(10) << endl;     // 1 = true
    cout << przywitaj("Ala") << endl;

    rysujLinie();             // uses both defaults: '-' and 20
    rysujLinie('*');          // dlugosc default 20
    rysujLinie('=', 5);

    const int N = 6;
    int dane[N] = {4, 8, 15, 16, 23, 42};
    cout << "avg " << srednia(dane, N) << endl;

    int najmniejsza;
    int najwieksza;
    minMax(dane, N, najmniejsza, najwieksza);    // "returns" two values through references
    cout << "min " << najmniejsza << ", max " << najwieksza << endl;

    return 0;
}

// ---------------- DEFINITIONS (after main, matching the prototypes) ----------------
int dodaj(int a, int b)
{
    return a + b;
}

// An array is NOT copied - the function works on the original (it CAN change it).
// The number of elements must be passed separately.
double srednia(int tab[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    int suma = 0;
    for (int i = 0; i < n; i++)
    {
        suma = suma + tab[i];
    }
    return (double)suma / n;
}

void rysujLinie(char znak, int dlugosc)      // no default values repeated here
{
    for (int i = 0; i < dlugosc; i++)
    {
        cout << znak;
    }
    cout << endl;
}

void minMax(int tab[], int n, int &min, int &max)
{
    min = tab[0];
    max = tab[0];
    for (int i = 1; i < n; i++)
    {
        if (tab[i] < min)
        {
            min = tab[i];
        }
        if (tab[i] > max)
        {
            max = tab[i];
        }
    }
}
