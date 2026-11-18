// ======================================================================
// recursion: print 1..n (recursive call BEFORE printing)
// Original file: unsorted/sprawdzian/rekurencjaFINALE.cpp
// ======================================================================

#include <iostream>
using namespace std;

void wypiszLiczby(int n)
{
    if (n > 0)
    {
        wypiszLiczby(n - 1);     // first print 1..n-1
        cout << n << " ";        // then n  -> output: 1 2 3 ... n
    }
}

int main()
{
    int n = 10;
    wypiszLiczby(n);
    cout << endl;
    return 0;
}
