// ======================================================================
// global function vs lambda used as a "local function"
// Original file: Functions/globalLocal.cpp
// ======================================================================

#include <iostream>
using namespace std;

// Global function - the normal way, use this in exam code
int kwadrat(int x)
{
    return x * x;
}

int main()
{
    // C++ does not allow a function inside a function. A lambda is a nameless
    // function written inside main and stored in a variable (it needs auto).
    auto kwadratLambda = [](int x)
    {
        return x * x;
    };

    cout << "global function: " << kwadrat(4) << endl;
    cout << "lambda:          " << kwadratLambda(4) << endl;

    return 0;
}
