// ======================================================================
// recursive sequence an = a(n-1)^2 - 100
// Original file: unsorted/calculations/silniarekurencyjna.cpp
// FIXED: returns long long and prints n = 2..5 (a6 would overflow even long long)
// ======================================================================

#include <iostream>
using namespace std;

long long sequence(int n) { 
    if (n == 1) {
        return 2;
    } else {
        return sequence(n - 1) * sequence(n - 1) - 100;
    }
}

int main() {
    for (int n = 2; n <= 5; n++) {
        cout << "!(" << n << ") = " << sequence(n) << endl;
    }
    return 0;
}