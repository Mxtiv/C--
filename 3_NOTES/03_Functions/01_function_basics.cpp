// ======================================================================
// ADDED (gap-fill): function basics - prototype vs definition, return values,
// void, parameters, default arguments, passing arrays, returning several values,
// static local, const parameters
// Not from your original repo - written to fill a missing topic.
// Next file: 02_pass_by_value_reference_pointer.cpp (yours) shows the 4 ways to pass data.
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

// ---------------- PROTOTYPES (declarations) ----------------
// Tell the compiler the function exists so main() can call it before its full definition.
int add(int a, int b);
double average(const int arr[], int size);
void printLine(char ch = '-', int length = 20);     // default arguments go in the PROTOTYPE
void minMax(const int arr[], int size, int &minOut, int &maxOut);

// ---------------- definitions placed before main need no prototype ----------------
bool isEven(int n)
{
    return n % 2 == 0;       // return ends the function immediately
}

string greet(const string &name)       // const& = no copy, cannot modify
{
    return "Hi, " + name + "!";
}

int main()
{
    cout << add(2, 3) << endl;
    cout << boolalpha << isEven(10) << noboolalpha << endl;
    cout << greet("Ala") << endl;

    printLine();              // uses both defaults: '-' and 20
    printLine('*');           // length default 20
    printLine('=', 5);

    int data[] = {4, 8, 15, 16, 23, 42};
    int size = sizeof(data) / sizeof(data[0]);   // number of elements (works only on real arrays, not pointers)
    cout << "avg " << average(data, size) << endl;

    int lo, hi;
    minMax(data, size, lo, hi);                  // "returns" two values through references
    cout << "min " << lo << ", max " << hi << endl;

    return 0;
}

// ---------------- DEFINITIONS (after main, matching the prototypes) ----------------
int add(int a, int b)
{
    return a + b;
}

// Arrays are always passed as a pointer to the first element -> the function CAN change them.
// Use const to promise you won't. The size must be passed separately.
double average(const int arr[], int size)
{
    if (size == 0) return 0;
    int sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    return static_cast<double>(sum) / size;
}

void printLine(char ch, int length)      // no default values repeated here
{
    for (int i = 0; i < length; i++) cout << ch;
    cout << endl;
}

void minMax(const int arr[], int size, int &minOut, int &maxOut)
{
    minOut = maxOut = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < minOut) minOut = arr[i];
        if (arr[i] > maxOut) maxOut = arr[i];
    }
}
