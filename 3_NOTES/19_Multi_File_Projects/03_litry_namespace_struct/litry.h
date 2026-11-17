// ======================================================================
// header: namespace with constants, struct, function prototype
// Original file: Maths/litrysprawdzian/litry.h
// FIXED - the bugs were: the header did #include "litry.cpp" (a header must never include a .cpp)
// and the prototype litrywpojemnikach(int, int) did not match the definition (int, litry&).
// Now: declarations here, definitions in litry.cpp.  Build: g++ main.cpp litry.cpp -o litry.exe
// ======================================================================

#ifndef LITRY_H
#define LITRY_H

namespace inlitery
{
    const int litr = 1;      // const at namespace scope is fine in a header
    const int galons = 5;
    const int bath = 200;
    const int tanks = 1000;
}

struct litry
{
    int litr{};
    int galons{};
    int bath{};
    int tanks{};
};

void litrywpojemnikach(int litr, litry &liter);

#endif
