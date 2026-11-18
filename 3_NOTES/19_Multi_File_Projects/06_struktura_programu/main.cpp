// ======================================================================
// main using functions from operacje.h
// Original file: unsorted/strukturaProgramu/main.cpp
// Build:  g++ main.cpp operacje.cpp -o program.exe
// ======================================================================

#include <iostream>
#include "operacje.h"
using namespace std;

int main()
{
    double bok = 3;
    cout << "Pole kwadratu: " << poleKwadratu(bok) << endl;
    cout << "Obwod kwadratu: " << obwodKwadratu(bok) << endl;
    cout << "Pole prostokata 2 x 5: " << poleProstokata(2, 5) << endl;
    cout << "Obwod prostokata 2 x 5: " << obwodProstokata(2, 5) << endl;
    return 0;
}
