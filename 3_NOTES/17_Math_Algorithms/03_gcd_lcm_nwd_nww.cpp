// ======================================================================
// GCD (Euclid, modulo version) and LCM
// Original file: Maths/nwd.cpp
// ======================================================================

#include <iostream>
using namespace std;

/********************************************************
 * nazwa funkcji: nwd
 * opis funkcji: najwiekszy wspolny dzielnik - algorytm Euklidesa (wersja z modulo)
 * parametry: a, b - liczby calkowite dodatnie
 * zwracany typ i opis: int - NWD(a, b)
 * autor: <numer zdającego>
 ********************************************************/
int nwd(int a, int b)
{
    while (b != 0)
    {
        int pomocnicza = b;
        b = a % b;
        a = pomocnicza;
    }
    return a;
}

/********************************************************
 * nazwa funkcji: nww
 * opis funkcji: najmniejsza wspolna wielokrotnosc
 * parametry: a, b - liczby calkowite dodatnie
 * zwracany typ i opis: int - NWW(a, b)
 * autor: <numer zdającego>
 ********************************************************/
int nww(int a, int b)
{
    return a / nwd(a, b) * b;      // najpierw dzielenie - mniejsza szansa na przepelnienie
}

int main()
{
    int a, b;
    do
    {
        cout << "Podaj dwie liczby dodatnie: ";
        cin >> a >> b;
    } while (a <= 0 || b <= 0);

    cout << "NWD(" << a << ", " << b << ") = " << nwd(a, b) << endl;
    cout << "NWW(" << a << ", " << b << ") = " << nww(a, b) << endl;

    return 0;
}
