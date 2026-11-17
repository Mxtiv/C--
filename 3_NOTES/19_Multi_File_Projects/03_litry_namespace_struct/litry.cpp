// ======================================================================
// definitions: greedy conversion of litres into tanks / baths / gallons / litres
// Original file: Maths/litrysprawdzian/litry.cpp
// FIXED: this file now contains only the definition and #includes litry.h
// (the namespace + struct moved to the header)
// ======================================================================

#include "litry.h"

void litrywpojemnikach(int litr, litry &liter)   // litry& -> the caller's struct is filled in
{
    liter.tanks = litr / inlitery::tanks;
    litr = litr % inlitery::tanks;

    liter.bath = litr / inlitery::bath;
    litr = litr % inlitery::bath;

    liter.galons = litr / inlitery::galons;
    litr = litr % inlitery::galons;

    liter.litr = litr;
}
