// ======================================================================
// feature flags with #ifdef (Polish explanation)
// Original file: unsorted/preprocessing/preProcessingDirectives.cpp
// ======================================================================

/*
Dyrektywy kompilacji warunkowej steruja tym, KTORY kod zostanie skompilowany.
Uzywa sie ich np. do wlaczania / wylaczania fragmentow programu albo do roznego
kodu dla roznych systemow operacyjnych.
*/

#include <iostream>
using namespace std;

#define FUNKCJA_A       // <-- zmien na FUNKCJA_B, a skompiluje sie druga funkcja

#ifdef FUNKCJA_A
void funkcjaA()
{
    cout << "Funkcja A jest w uzyciu." << endl;
}
#endif

#ifdef FUNKCJA_B
void funkcjaB()
{
    cout << "Funkcja B jest w uzyciu." << endl;
}
#endif

int main()
{
#ifdef FUNKCJA_A
    funkcjaA();
#endif

#ifdef FUNKCJA_B
    funkcjaB();
#endif

    return 0;
}
