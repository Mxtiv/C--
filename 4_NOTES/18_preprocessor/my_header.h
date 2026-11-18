// ======================================================================
// include guard #ifndef / #define / #endif (this is the header 01_ includes)
// Original file: Preprocessing/compilationConditions.cpp
// FIXED: renamed from compilationConditions.cpp to my_header.h and added #include <iostream>
// ======================================================================

#ifndef MY_HEADER_H      // jesli MY_HEADER_H jeszcze NIE jest zdefiniowane...
#define MY_HEADER_H      // ...zdefiniuj je - drugi #include tego pliku nic juz nie wstawi

#include <iostream>     // naglowek dolacza to, czego SAM uzywa (cout)
using namespace std;

void przywitaj()
{
    cout << "Czesc z pliku my_header.h!" << endl;
}

#endif                  // koniec MY_HEADER_H
