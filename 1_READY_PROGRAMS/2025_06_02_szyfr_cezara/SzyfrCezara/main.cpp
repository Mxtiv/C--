// ======================================================================
// INF.04-02-25.06-SG part I - szyfr Cezara w konsoli. Funkcja szyfruj() jest w szyfr.cpp,
// testy jednostkowe (część III) w ../SzyfrCezaraTesty. Spec + key: ../README.md
// g++ (without Visual Studio):  g++ -std=c++17 main.cpp szyfr.cpp -o szyfr.exe
// ======================================================================
#include <iostream>
#include <string>
#include "szyfr.h"
using namespace std;

int main()
{
    string tekst;
    cout << "Podaj tekst do zaszyfrowania (male litery i spacje): ";
    getline(cin, tekst);

    int klucz;
    cout << "Podaj klucz (liczba calkowita): ";
    cin >> klucz;

    cout << "Tekst zaszyfrowany: " << szyfruj(tekst, klucz) << endl;
    return 0;
}
