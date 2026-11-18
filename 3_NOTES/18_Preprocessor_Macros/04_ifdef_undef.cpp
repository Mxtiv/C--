// ======================================================================
// #define, #undef, #ifdef
// Original file: Preprocessing/undefining.cpp
// ======================================================================

#include <iostream>
using namespace std;

#define DEBUG       // zdefiniuj DEBUG
#undef DEBUG        // ...i usun definicje - od tego miejsca DEBUG nie istnieje

int main()
{
#ifdef DEBUG
    cout << "Tryb DEBUG wlaczony" << endl;
#else
    cout << "Tryb DEBUG wylaczony" << endl;     // ta linia, bo DEBUG zostal usuniety
#endif
    return 0;
}
