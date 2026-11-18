// ======================================================================
// recursive factorial with base case
// Original file: Functions/recurrent.cpp
// ======================================================================

#include <iostream>
using namespace std;

// Recursive function = a function that calls itself
long long silnia(int n)
{
    // Base case: stops the recursion (without it -> infinite calls -> crash)
    if (n == 0)
    {
        return 1;
    }
    // Recursive case: n * factorial of (n-1)
    return n * silnia(n - 1);
}

int main()
{
    int liczba = 5;

    cout << "Factorial of " << liczba << " is: " << silnia(liczba) << endl;

    return 0;
}
