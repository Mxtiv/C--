// ======================================================================
// union basics: all members share ONE place in memory, sizeof, overwriting
// Original file: Structs/Unions/overviewUnions.cpp
// ======================================================================

#include <iostream>
using namespace std;

// A union looks like a struct, but its members are stored in the SAME memory.
// Its size = the size of the biggest member. Only the member written last is valid.
union Dane
{
    int liczba;          // 4 bytes
    double ulamek;       // 8 bytes
    char znak;           // 1 byte
};

int main()
{
    Dane dane;

    dane.liczba = 10;
    cout << "int: " << dane.liczba << endl;

    dane.ulamek = 220.5;             // overwrites liczba - now only ulamek is valid
    cout << "double: " << dane.ulamek << endl;

    dane.znak = 'A';                 // overwrites ulamek - now only znak is valid
    cout << "char: " << dane.znak << endl;

    cout << "sizeof(Dane) = " << sizeof(Dane) << " bytes (the biggest member: double)" << endl;

    // For comparison: a struct keeps every field separately, so it needs more memory
    struct DaneStruktura
    {
        int liczba;
        double ulamek;
        char znak;
    };
    cout << "sizeof(DaneStruktura) = " << sizeof(DaneStruktura) << " bytes" << endl;

    return 0;
}
