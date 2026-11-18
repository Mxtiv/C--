// ======================================================================
// ADDED (gap-fill): references (alias), reference vs pointer side by side,
// swap 3 ways, dangling pointer, a tiny smart pointer (unique_ptr) example
// Not from your original repo - written to fill a missing topic.
// ======================================================================

#include <iostream>
#include <memory>   // unique_ptr, make_unique - only for the last example
using namespace std;

void zamienPrzezWartosc(int a, int b)      // changes COPIES -> no effect outside
{
    int pomocnicza = a;
    a = b;
    b = pomocnicza;
}

void zamienPrzezReferencje(int &a, int &b) // changes the originals
{
    int pomocnicza = a;
    a = b;
    b = pomocnicza;
}

void zamienPrzezWskazniki(int *a, int *b)  // changes the originals
{
    int pomocnicza = *a;
    *a = *b;
    *b = pomocnicza;
}

int main()
{
    // ---------------- reference = another name for the same variable ----------------
    int x = 10;
    int &ref = x;          // must be set at once, cannot be "re-pointed" later
    ref = 20;              // changes x
    cout << "x = " << x << endl;

    // ---------------- pointer vs reference ----------------
    int *wsk = &x;         // a pointer stores an ADDRESS, can be nullptr, can change target
    *wsk = 30;             // use * to reach the value
    cout << "x = " << x << endl;

    // ---------------- swap 3 ways ----------------
    int a = 1;
    int b = 2;
    zamienPrzezWartosc(a, b);
    cout << "by value:     " << a << " " << b << endl;   // 1 2
    zamienPrzezReferencje(a, b);
    cout << "by reference: " << a << " " << b << endl;   // 2 1
    zamienPrzezWskazniki(&a, &b);
    cout << "by pointer:   " << a << " " << b << endl;   // 1 2

    // ---------------- dangling pointer (what NOT to do) ----------------
    int *p = new int(5);
    delete p;
    p = nullptr;           // after delete set to nullptr, otherwise p points to freed memory
    if (p == nullptr)
    {
        cout << "p is safely null" << endl;
    }

    // ---------------- smart pointer: delete happens AUTOMATICALLY ----------------
    // unique_ptr owns the memory and frees it itself at the closing } - no delete needed.
    {
        unique_ptr<int> inteligentny = make_unique<int>(42);
        cout << "unique_ptr value: " << *inteligentny << endl;
    }   // memory freed here
    // (there is also shared_ptr - several owners; the memory is freed by the last one)

    return 0;
}
