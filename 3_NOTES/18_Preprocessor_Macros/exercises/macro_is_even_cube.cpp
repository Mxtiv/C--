// ======================================================================
// IS_EVEN(n), CUBE(h)
// Original file: unsorted/various/macros.cpp
// FIXED - the bug was: global h = n is 0, so CUBE(h) is always 0; local n shadows the global
// ======================================================================

#include <iostream>
using namespace std;

#define IS_EVEN(n) ((n) % 2 == 0)
#define CUBE(h) ((h) * (h) * (h))
int main() {
    int n;
    cout << "Podaj liczbę: ";
    cin >> n;
    int h = n;   // h must be set AFTER n is read
    cout << (IS_EVEN(n) ? "TRUE" : "FALSE") << endl;
    cout << "Liczba podniesiona do potęgi 3: " << CUBE(h) << endl; 
    cout << "Wartość n: " << h << endl;
    cout << "Test na parzystość podniesionej do 3: " << (IS_EVEN(CUBE(h)) ? "TRUE" : "FALSE") << endl;

    return 0;
}
   