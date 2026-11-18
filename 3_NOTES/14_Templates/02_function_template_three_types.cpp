// ======================================================================
// template<T1,T2,T3> function with explicit types
// Original file: unsorted/various/templates.cpp
// ======================================================================

#include <iostream>
using namespace std;

template <typename T1, typename T2, typename T3>
T1 obwod(T1 bok1, T2 bok2, T3 bok3)
{
    return bok1 + bok2 + bok3;
}

int main()
{
    float bok1 = 1.5;
    float bok2 = 3;
    float bok3 = 4.2;

    cout << "Obwod wynosi " << obwod<float, float, float>(bok1, bok2, bok3) << endl;
    cout << "Obwod wynosi " << obwod<float, int, float>(bok1, bok2, bok3) << endl;   // bok2 zamieniony na int (3)
    return 0;
}
