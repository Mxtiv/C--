// ======================================================================
// recursive sequence a1 = 2, an = a(n-1)^2 - 100
// Original file: unsorted/calculations/silniarekurencyjna.cpp
// FIXED: returns long long and prints n = 2..5 (a6 would overflow even long long)
// ======================================================================

#include <iostream>
using namespace std;

long long ciag(int n)
{
    if (n == 1)
    {
        return 2;
    }
    long long poprzedni = ciag(n - 1);     // compute it ONCE, then square it
    return poprzedni * poprzedni - 100;
}

int main()
{
    for (int n = 2; n <= 5; n++)
    {
        cout << "a" << n << " = " << ciag(n) << endl;
    }
    return 0;
}
