// ======================================================================
// size() vs capacity() after resize(0) and clear()
// Original file: unsorted/Vectors/1) Pojemnosc wektora przed i po resize/main.cpp
// FIXED - the bug was: clears `wektor` but prints `wiektor` (typo)
// ======================================================================

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // size     = ile elementów jest w wektorze
    // capacity = na ile elementów wektor ma już zarezerwowaną pamięć (>= size)
    vector<int> wektor = {10, 20, 30, 40, 50};

    cout << "Rozmiar oryginalny: " << wektor.size() << endl;
    cout << "Pojemność oryginalna: " << wektor.capacity() << endl;

    wektor.resize(0);

    cout << "Rozmiar po resize(0): " << wektor.size() << endl;
    cout << "Pojemność po resize(0): " << wektor.capacity() << endl;   // pamięć zostaje!

    vector<int> drugi = {10, 20, 30, 40, 50};
    drugi.clear();

    cout << "Rozmiar po clear(): " << drugi.size() << endl;
    cout << "Pojemność po clear(): " << drugi.capacity() << endl;       // też zostaje

    return 0;
}
