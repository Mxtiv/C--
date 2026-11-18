// ======================================================================
// #include <...> vs #include "myheader.h"
// Original file: Preprocessing/inclusion.cpp
//
//   #include <iostream>    - naglowek biblioteki (szukany w katalogach kompilatora)
//   #include "myheader.h"  - WLASNY naglowek (szukany najpierw obok pliku .cpp)
// ======================================================================

#include <iostream>
#include "myheader.h"
#include "myheader.h"   // drugi raz - dzieki include guard nie ma bledu "redefinition"
using namespace std;

int main()
{
    cout << "Program glowny" << endl;
    przywitaj();        // funkcja z myheader.h
    return 0;
}
