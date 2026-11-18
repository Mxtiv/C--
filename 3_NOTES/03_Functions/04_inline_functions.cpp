// ======================================================================
// inline functions
// Original file: Functions/inlineFunctions.cpp
// ======================================================================

#include <iostream>
using namespace std;

// inline = a hint for the compiler: "paste the body where the function is called"
// instead of a real call. Only for very short functions. It works the same as without it.
inline int dodaj(int a, int b)
{
    return a + b;
}

inline int kwadrat(int x)
{
    return x * x;
}

int main()
{
    int a = 5;
    int b = 10;

    cout << "Addition: " << dodaj(a, b) << endl;
    cout << "Square: " << kwadrat(a) << endl;

    return 0;
}
