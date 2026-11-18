// ======================================================================
// include guard #ifndef / #define / #endif (this is the header 01_ includes)
// Original file: Preprocessing/compilationConditions.cpp
// FIXED: renamed from compilationConditions.cpp to myheader.h and added #include <iostream>
// ======================================================================

#ifndef MYHEADER_H      // jesli MYHEADER_H jeszcze NIE jest zdefiniowane...
#define MYHEADER_H      // ...zdefiniuj je - drugi #include tego pliku nic juz nie wstawi

#include <iostream>     // naglowek dolacza to, czego SAM uzywa (cout)
using namespace std;

void przywitaj()
{
    cout << "Czesc z pliku myheader.h!" << endl;
}

#endif                  // koniec MYHEADER_H
