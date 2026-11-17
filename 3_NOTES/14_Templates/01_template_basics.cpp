// ======================================================================
// ADDED (gap-fill): the simplest templates - one-type function template,
// class template Box<T>, explicit vs implicit (deduced) types, non-type parameter
// Not from your original repo - written to fill a missing topic.
// Then continue with your files 02..07 (specialization = specjalizacja,
// instantiation = konkretyzacja).
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

// ---------------- function template ----------------
// T is a placeholder type. The compiler generates maxOf<int>, maxOf<double>... when used.
template <typename T>
T maxOf(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T>
void printArray(const T arr[], int n)
{
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

// ---------------- class template ----------------
template <typename T>
class Box
{
private:
    T value;
public:
    Box(T v) : value(v) {}
    T get() const { return value; }
    void set(T v) { value = v; }
    void show() const;                    // defined outside below
};

template <typename T>                     // outside definition needs the template line again
void Box<T>::show() const
{
    cout << "Box holds: " << value << endl;
}

// ---------------- non-type template parameter (a number known at compile time) ----------------
template <typename T, int SIZE>
class FixedArray
{
public:
    T data[SIZE];
    int size() const { return SIZE; }
};

int main()
{
    cout << maxOf(3, 7) << endl;               // implicit (niejawne): T deduced as int
    cout << maxOf(2.5, 1.5) << endl;           // T = double
    cout << maxOf<double>(3, 7.5) << endl;     // explicit (jawne): needed when types differ
    cout << maxOf<string>("ala", "ola") << endl;

    int ints[] = {1, 2, 3};
    string words[] = {"one", "two"};
    printArray(ints, 3);
    printArray(words, 2);

    Box<int> bi(42);
    Box<string> bs("text");
    bi.set(bi.get() + 1);
    bi.show();
    bs.show();

    FixedArray<double, 4> fa;
    cout << "FixedArray size: " << fa.size() << endl;

    return 0;
}
