// ======================================================================
// derived class redeclares `cyfra`, hiding the base field
// Original file: unsorted/various/dziedziczenietask.cpp
// FIXED - the bug was: cyfra is never initialized
// ======================================================================

#include <iostream>
using namespace std;

class Number1
{
public:
    int cyfra = 0;
    void increment();
};
class Number2 : public Number1
{
public:
    int cyfra = 0;
    void increment();
};
void Number1::increment()
{
    cyfra++;
    cout << "Wywołanie metody increment() zdefiniowanej w klasie N1"
         << endl;
}
void Number2::increment()
{
    cyfra++;
    cyfra++;
    cout << "Wywołanie metody increment() zdefiniowanej w klasie N2"
         << endl;
}
int main()
{
    Number1 liczba1;
    liczba1.increment();
    Number2 liczba2;
    liczba2.increment();
    cout << "N1.cyfra = " << liczba1.cyfra << ", N2.cyfra = " << liczba2.cyfra
         << ", hidden base part N2.Number1::cyfra = " << liczba2.Number1::cyfra << endl;
    return 0;
}