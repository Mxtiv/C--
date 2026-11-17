// ======================================================================
// recursive sequence a1=2, an=a(n-1)-100
// Original file: unsorted/calculations/silnia.cpp
// ======================================================================

#include <iostream>
using namespace std;

int sequence(int n) {
    if (n == 1) {
        return 2;
    } else {
        return sequence(n - 1) - 100;
    }
}

int main() {
    int n = 2;
    cout << sequence(n) << endl;
    return 0;
}