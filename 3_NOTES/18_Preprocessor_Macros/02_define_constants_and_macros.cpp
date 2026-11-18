// ======================================================================
// #define PI, #define KWADRAT(x) ((x) * (x))
// Original file: Preprocessing/macroFunctions.cpp
//
// #define to zwykla podmiana TEKSTU przed kompilacja (bez typu, bez srednika).
// Na egzaminie stala lepiej zapisac jako: const double PI = 3.14159;
// ======================================================================

#include <iostream>
using namespace std;

#define PI 3.14159                  // stala
#define KWADRAT(x) ((x) * (x))      // makro z parametrem - ZAWSZE nawiasy wokol x i calosci
#define ZLY_KWADRAT(x) x * x        // bez nawiasow - zle!

int main()
{
    cout << "PI: " << PI << endl;
    cout << "KWADRAT(5) = " << KWADRAT(5) << endl;                  // ((5) * (5)) = 25
    cout << "KWADRAT(2 + 3) = " << KWADRAT(2 + 3) << endl;          // ((2 + 3) * (2 + 3)) = 25
    cout << "ZLY_KWADRAT(2 + 3) = " << ZLY_KWADRAT(2 + 3) << endl;  // 2 + 3 * 2 + 3 = 11 !
    return 0;
}
