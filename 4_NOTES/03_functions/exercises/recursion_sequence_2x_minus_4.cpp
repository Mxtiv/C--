// ======================================================================
// recursive sequence attempt: a1 = 1, an = 2 * (a(n-1) - 1) - 4
// Original file: unsorted/sprawdzian/rekurencja.cpp
// FIXED - the bug was: ciag(n) called ciag(n) with the SAME n -> infinite recursion / stack overflow. Should be ciag(n - 1)
// ======================================================================

#include <iostream>
using namespace std;

int ciag(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return 2 * (ciag(n - 1) - 1) - 4;
}

int main()
{
    int liczba;
    do
    {
        cout << "Podaj numer w ciągu do obliczenia (1-20): ";
        cin >> liczba;
    } while (liczba < 1 || liczba > 20);
    cout << ciag(liczba) << endl;
    return 0;
}
