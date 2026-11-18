// ======================================================================
// basics, dereference, pointer arithmetic, pointer to array, pointer to pointer,
// nullptr, pointer as a function parameter, new/delete
// Original file: Pointers/overviewPointers.cpp
// ======================================================================

#include <iostream>
using namespace std;

// A function that gets an ADDRESS can change the caller's variable
void podwoj(int *wskaznik)
{
    *wskaznik = *wskaznik * 2;
}

int main()
{
    // 1. Basic pointer usage
    int a = 10;
    int *wsk = &a;      // pointer to int, holds the ADDRESS of a (& = "address of")
    cout << "1. Basic pointer usage:" << endl;
    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Pointer wsk holds address: " << wsk << endl;
    cout << "Dereferencing wsk (*wsk): " << *wsk << endl << endl;   // * = "value at that address"

    // 2. Changing a variable through a pointer
    cout << "2. Changing a through the pointer:" << endl;
    *wsk = 20;
    cout << "Value of a after *wsk = 20: " << a << endl << endl;

    // 3. Pointer arithmetic and arrays
    cout << "3. Pointer arithmetic:" << endl;
    int tab[5] = {1, 2, 3, 4, 5};
    int *wskTab = tab;           // the array name is the address of its first element
    cout << "wskTab points to: " << *wskTab << endl;                 // 1
    wskTab++;                    // move to the next element
    cout << "after wskTab++: " << *wskTab << endl;                   // 2
    wskTab = wskTab + 2;         // move forward by 2 elements
    cout << "after wskTab + 2: " << *wskTab << endl;                 // 4

    // *(tab + i) is the same as tab[i]
    for (int i = 0; i < 5; i++)
    {
        cout << "Element " << i << " = " << *(tab + i) << endl;
    }
    cout << endl;

    // 4. Pointer to pointer
    cout << "4. Pointer to pointer:" << endl;
    int x = 30;
    int *wskX = &x;
    int **wskWsk = &wskX;        // holds the address of the pointer wskX
    cout << "*wskWsk gives the address of x: " << *wskWsk << endl;
    cout << "**wskWsk gives the value of x: " << **wskWsk << endl << endl;

    // 5. Null pointer - points nowhere; check before using *
    cout << "5. Null pointer:" << endl;
    int *pusty = nullptr;        // (old code writes NULL - the same idea)
    if (pusty == nullptr)
    {
        cout << "pusty is a null pointer, it doesn't point to any variable." << endl << endl;
    }

    // 6. Pointer as a function parameter
    cout << "6. Pointer as a parameter:" << endl;
    int liczba = 7;
    podwoj(&liczba);             // pass the ADDRESS
    cout << "after podwoj(&liczba): " << liczba << endl << endl;      // 14

    // 7. Dynamic memory (more in 03_new_delete.cpp)
    cout << "7. new / delete:" << endl;
    int *dynamiczna = new int;   // a new int on the heap
    *dynamiczna = 100;
    cout << "Value on the heap: " << *dynamiczna << endl;
    delete dynamiczna;           // every new needs a delete
    dynamiczna = nullptr;
    cout << "Memory freed." << endl;

    return 0;
}
