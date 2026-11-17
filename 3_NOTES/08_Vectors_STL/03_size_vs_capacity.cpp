// ======================================================================
// size() vs capacity() after resize(0) and clear()
// Original file: unsorted/Vectors/1) Pojemnosc wektora przed i po resize/main.cpp
// FIXED - the bug was: clears `wektor` but prints `wiektor` (typo)
// ======================================================================

#include <iostream>
#include <vector>

using namespace std;

int main() {

  vector<int> wektor = {10, 20, 30, 40, 50};

  cout << "Rozmiar oryginalny: " << wektor.size() << endl;
  cout << "Pojemność oryginalna: " << wektor.capacity() << endl;

  wektor.resize(0);

  cout << "Rozmiar po resize(0): " << wektor.size() << endl;
  cout << "Pojemność po resize(0): " << wektor.capacity() << endl;

  vector<int> wiektor = {10, 20, 30, 40, 50};
  wiektor.clear();

  cout << "Rozmiar po clear(): " << wiektor.size() << endl;
  cout << "Pojemność po clear(): " << wiektor.capacity() << endl;

  return 0;
}