// ======================================================================
// header: namespace with constants, struct, function prototype
// Original file: Maths/litrysprawdzian/litry.h
// FIXED - the bugs were: the header did #include "litry.cpp" (a header must never include a .cpp)
// and the prototype litrywpojemnikach(int, int) did not match the definition (int, litry&).
// Now: declarations here, definitions in litry.cpp.  Build: g++ main.cpp litry.cpp -o litry.exe
// ======================================================================

#ifndef LITRY_H
#define LITRY_H

// namespace = "nazwisko" dla nazw; uzycie: pojemnosci::WANNA
namespace pojemnosci
{
    const int GALON = 5;
    const int WANNA = 200;
    const int CYSTERNA = 1000;
}

struct Litry
{
    int cysterny;
    int wanny;
    int galony;
    int litry;
};

void zamienLitry(int ileLitrow, Litry &wynik);

#endif
