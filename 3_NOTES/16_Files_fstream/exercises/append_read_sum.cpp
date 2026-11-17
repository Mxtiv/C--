// ======================================================================
// append user numbers (ios::app), read them back, sum
// Original file: unsorted/sprawdzian/fstreamShroom.cpp
// FIXED - the bugs were: there was NO main() (program could not link); while(!eof())
// loops processed the last number twice -> now while (plik >> x)
// ======================================================================

#include <fstream>
#include <iostream>
using namespace std;

void Plikewpisywanie()
{
    fstream plik;
    plik.open("plik.txt", ios::app);           // append: keeps what is already in the file
    int powturzenie = 0, dodanielicbydopliku = 0;
    cout << "podej ile liczb w pliku" << endl;
    cin >> powturzenie;
    for (int i = 1; i <= powturzenie; i++)
    {
        cout << "podej liczbe" << endl;
        cin >> dodanielicbydopliku;
        plik << " " << dodanielicbydopliku;
    }
    plik.close();
}

void otwieranie()
{
    int zPliku;
    ifstream plik("plik.txt");
    cout << " liczby w piku " << endl;
    while (plik >> zPliku)
    {
        cout << zPliku << ", ";
    }
    cout << endl;
    plik.close();
}

void sumapliku()
{
    int zPliku, suma = 0;
    cout << "suma " << endl;
    ifstream sumaa("plik.txt");
    while (sumaa >> zPliku)
    {
        suma = zPliku + suma;
    }
    sumaa.close();
    cout << suma << endl;
}

int main()
{
    Plikewpisywanie();
    otwieranie();
    sumapliku();
    return 0;
}
