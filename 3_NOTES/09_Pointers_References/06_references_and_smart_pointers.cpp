// ======================================================================
// ADDED (gap-fill): references (alias), reference vs pointer side by side,
// swap 3 ways, const reference, dangling pointer, smart pointers (unique_ptr, shared_ptr)
// Not from your original repo - written to fill a missing topic.
// ======================================================================

#include <iostream>
#include <memory>   // unique_ptr, shared_ptr, make_unique, make_shared
#include <string>
using namespace std;

void swapByValue(int a, int b)      { int t = a; a = b; b = t; }   // changes COPIES -> no effect
void swapByReference(int &a, int &b) { int t = a; a = b; b = t; }   // changes the originals
void swapByPointer(int *a, int *b)  { int t = *a; *a = *b; *b = t; } // changes the originals

struct Item
{
    string name;
    Item(string n) : name(n) { cout << "  [Item " << name << " created]" << endl; }
    ~Item() { cout << "  [Item " << name << " destroyed]" << endl; }
};

int main()
{
    // ---------------- reference = another name for the same variable ----------------
    int x = 10;
    int &ref = x;          // must be initialized, cannot be "re-pointed" later
    ref = 20;              // changes x
    cout << "x = " << x << ", &x == &ref: " << (&x == &ref) << endl;

    // ---------------- pointer vs reference ----------------
    int *ptr = &x;         // pointer stores an ADDRESS, can be nullptr, can change target
    *ptr = 30;             // dereference with *
    cout << "x = " << x << endl;

    // ---------------- swap ----------------
    int a = 1, b = 2;
    swapByValue(a, b);     cout << "by value:     " << a << " " << b << endl;   // 1 2
    swapByReference(a, b); cout << "by reference: " << a << " " << b << endl;   // 2 1
    swapByPointer(&a, &b); cout << "by pointer:   " << a << " " << b << endl;   // 1 2
    swap(a, b);            cout << "std::swap:    " << a << " " << b << endl;   // 2 1

    // ---------------- const reference: read-only, no copy (great for big objects) ----------------
    const string &longText = string(1000, 'x');
    cout << "length " << longText.size() << endl;

    // ---------------- range-for with reference modifies elements ----------------
    int arr[] = {1, 2, 3};
    for (int &v : arr) v *= 10;
    cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;

    // ---------------- dangling pointer (what NOT to do) ----------------
    int *p = new int(5);
    delete p;
    p = nullptr;           // after delete set to nullptr, otherwise p points to freed memory
    if (p == nullptr) cout << "p is safely null" << endl;

    // ---------------- smart pointers: delete happens AUTOMATICALLY ----------------
    cout << "unique_ptr:" << endl;
    {
        unique_ptr<Item> u = make_unique<Item>("A");   // one owner
        cout << "  using " << u->name << endl;
        // unique_ptr<Item> copy = u;                   // ERROR: cannot copy a unique_ptr
        unique_ptr<Item> moved = move(u);              // ownership moves
        cout << "  u is " << (u ? "not null" : "null now") << endl;
    }                                                   // Item A destroyed here
    cout << "shared_ptr:" << endl;
    {
        shared_ptr<Item> s1 = make_shared<Item>("B");
        {
            shared_ptr<Item> s2 = s1;                   // shared ownership
            cout << "  owners: " << s1.use_count() << endl;   // 2
        }
        cout << "  owners: " << s1.use_count() << endl;       // 1
    }                                                   // Item B destroyed when the last owner is gone

    return 0;
}
