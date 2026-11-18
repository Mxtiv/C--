// ======================================================================
// sum numbers from wyjscie.txt (create the file yourself, e.g. "5 10 -3")
// Original file: Libraries/Fstreamy/fstream.cpp
// FIXED - the bug was: `suma` is uninitialized; while(!eof()) adds the last number twice - use while (plik >> x)
// ======================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream odczyt("wyjscie.txt");
    if (!odczyt)
    {
        cout << "Brak pliku wyjscie.txt" << endl;
        return 1;
    }

    int suma = 0;              // zawsze zainicjuj sume!
    int liczba;
    while (odczyt >> liczba)   // konczy sie dokladnie na koncu danych
    {
        suma = suma + liczba;
    }
    odczyt.close();

    cout << "Suma: " << suma << endl;
    return 0;
}
