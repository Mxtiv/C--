// ======================================================================
// 2D array random fill + print (everything in main)
// Original file: Arrays/dwuwymiaroweTablice/zadanie.cpp
// FIXED - the bug was: array declared [3][4] but loops only go 2x3
// ======================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    int tab[3][4];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tab[i][j] = rand() % 11;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
