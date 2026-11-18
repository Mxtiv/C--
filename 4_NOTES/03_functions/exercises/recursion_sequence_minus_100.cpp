// ======================================================================
// recursive sequence a1=2, an=a(n-1)-100
// Original file: unsorted/calculations/silnia.cpp
// ======================================================================

#include <iostream>
using namespace std;

int ciag(int n)
{
    if (n == 1)
    {
        return 2;
    }
    return ciag(n - 1) - 100;
}

int main()
{
    for (int n = 1; n <= 5; n++)
    {
        cout << "a" << n << " = " << ciag(n) << endl;
    }
    return 0;
}
