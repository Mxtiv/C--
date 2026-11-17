// ======================================================================
// sum numbers from wyjscie.txt
// Original file: Libraries/Fstreamy/fstream.cpp
// FIXED - the bug was: `suma` is uninitialized; while(!eof()) adds the last number twice - use while (plik >> x)
// ======================================================================

#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    int suma = 0;
    int zPliku;
    // ofstream zapis("wyjscie.txt");
    // zapis << 5 << " kupa " << -50;
    ifstream odczyt("wyjscie.txt");
    while (odczyt >> zPliku)   // stops exactly at the end of data
    {
        suma=suma+zPliku;
    }
    cout << suma;
    odczyt.close();
    // zapis.close();

    return 0;
}