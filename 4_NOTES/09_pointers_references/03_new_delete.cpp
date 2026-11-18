// ======================================================================
// new int, new double, new int[n], delete / delete[], set to nullptr after delete
// Original file: Pointers/dynamicAllocation.cpp
// ======================================================================

#include <iostream>
using namespace std;

int main()
{
    // 1. new - reserves memory on the heap and gives back its ADDRESS
    int *wskInt = new int;
    double *wskDouble = new double;

    // 2. Write values into that memory through the pointers
    *wskInt = 42;
    *wskDouble = 3.14159;

    cout << "Value of dynamic integer: " << *wskInt << endl;
    cout << "Address of dynamic integer: " << wskInt << endl;
    cout << "Value of dynamic double: " << *wskDouble << endl;

    // 3. new[] - an array whose size could come from the user
    int rozmiar = 5;
    int *tablica = new int[rozmiar];
    for (int i = 0; i < rozmiar; i++)
    {
        tablica[i] = i * 10;     // used exactly like a normal array
    }

    cout << "Array values and addresses:" << endl;
    for (int i = 0; i < rozmiar; i++)
    {
        cout << "Value: " << tablica[i] << ", Address: " << &tablica[i] << endl;
    }

    // 4. Free the memory: delete for one value, delete[] for an array
    delete wskInt;
    delete wskDouble;
    delete[] tablica;

    // 5. After delete the pointer still holds the old address ("dangling pointer").
    //    Set it to nullptr so nobody uses freed memory by mistake.
    wskInt = nullptr;
    wskDouble = nullptr;
    tablica = nullptr;

    cout << "Memory has been freed." << endl;
    return 0;
}
