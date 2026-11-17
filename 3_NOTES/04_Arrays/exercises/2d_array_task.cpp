// ======================================================================
// 2D array random fill + print
// Original file: Arrays/dwuwymiaroweTablice/zadanie.cpp
// FIXED - the bug was: array declared [3][4] but loops only go 2x3
// ======================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
int arr[3][4];
srand(time(NULL));
for (int i = 0; i < 3; i++)
    {
      for (short j = 0; j < 4; j++)
      {
        arr[i][j] = rand() % 11;
      }
    }
     for (short i = 0; i < 3; i++)
  {
    for (short j = 0; j < 4; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
return 0;
}