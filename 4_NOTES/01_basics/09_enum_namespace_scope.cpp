// ======================================================================
// ADDED (gap-fill): enum, enum class, namespace, static local variable
// Not from your original repo - written to fill a missing topic.
// (Big real example with enums: 12_inheritance/07_multiple_inheritance_computer.cpp)
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

// ---------------- plain enum: names become int constants 0,1,2... ----------------
enum Kolor { CZERWONY, ZIELONY, NIEBIESKI };              // 0, 1, 2
enum Ocena { JEDEN = 1, DWA, TRZY, CZTERY, PIEC, SZESC };  // DWA=2 ... SZESC=6

// ---------------- enum class: names must be written as Status::... ----------------
enum class Status { Aktywny, Zablokowany, Usuniety };

string statusNaTekst(Status s)
{
    switch (s)
    {
    case Status::Aktywny:
        return "active";
    case Status::Zablokowany:
        return "blocked";
    case Status::Usuniety:
        return "deleted";
    }
    return "?";
}

// ---------------- namespace: groups names, avoids conflicts ----------------
namespace geometria
{
    const double PI = 3.14159;

    double poleKola(double r)
    {
        return PI * r * r;
    }
}

// ---------------- static local variable keeps its value between calls ----------------
int licznikWywolan()
{
    static int wywolania = 0;   // set to 0 only once
    wywolania++;
    return wywolania;
}

int main()
{
    Kolor k = ZIELONY;
    cout << "ZIELONY = " << k << endl;                // prints 1
    if (k == ZIELONY)
    {
        cout << "it is green" << endl;
    }

    Ocena o = PIEC;
    cout << "grade " << o << endl;                    // 5

    Status s = Status::Zablokowany;
    cout << "status: " << statusNaTekst(s) << ", as int: " << (int)s << endl;
    // int x = s;   // ERROR for enum class - it needs a cast: (int)s

    cout << "area: " << geometria::poleKola(2) << ", PI: " << geometria::PI << endl;

    licznikWywolan();
    licznikWywolan();
    cout << "licznikWywolan called " << licznikWywolan() << " times" << endl;   // 3

    return 0;
}
