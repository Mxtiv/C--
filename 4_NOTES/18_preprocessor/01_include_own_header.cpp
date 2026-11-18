// ======================================================================
// #include <...> vs #include "my_header.h"
// Original file: Preprocessing/inclusion.cpp
//
//   #include <iostream>    - naglowek biblioteki (szukany w katalogach kompilatora)
//   #include "my_header.h"  - WLASNY naglowek (szukany najpierw obok pliku .cpp)
// ======================================================================

#include <iostream>
#include "my_header.h"
#include "my_header.h"   // drugi raz - dzieki include guard nie ma bledu "redefinition"
using namespace std;

int main()
{
    cout << "Program glowny" << endl;
    przywitaj();        // funkcja z my_header.h
    return 0;
}
