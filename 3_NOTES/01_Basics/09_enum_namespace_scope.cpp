// ======================================================================
// ADDED (gap-fill): enum, enum class, namespace, using, typedef/using alias, static local
// Not from your original repo - written to fill a missing topic.
// (Big real example with enums: 12_Inheritance/07_multiple_inheritance_computer.cpp)
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

// ---------------- plain enum: names become int constants 0,1,2... ----------------
enum Color { RED, GREEN, BLUE };                 // RED=0, GREEN=1, BLUE=2
enum Grade { ONE = 1, TWO, THREE, FOUR, FIVE, SIX };   // TWO=2 ... SIX=6

// ---------------- enum class: scoped + type safe (modern, preferred) ----------------
enum class Status { Active, Blocked, Deleted };

string statusToText(Status s)
{
    switch (s)
    {
    case Status::Active:  return "active";
    case Status::Blocked: return "blocked";
    case Status::Deleted: return "deleted";
    }
    return "?";
}

// ---------------- namespace: groups names, avoids conflicts ----------------
namespace geometry
{
    const double PI = 3.14159;
    double circleArea(double r) { return PI * r * r; }
}
namespace physics
{
    const double G = 9.81;
}

// ---------------- type alias ----------------
typedef unsigned long long ull;   // old style
using Text = string;              // new style

// ---------------- static local variable keeps its value between calls ----------------
int callCounter()
{
    static int calls = 0;   // initialized only once
    return ++calls;
}

int main()
{
    Color c = GREEN;
    cout << "GREEN = " << c << endl;                  // prints 1
    if (c == GREEN) cout << "it is green" << endl;

    Grade g = FIVE;
    cout << "grade " << g << endl;                    // 5

    Status s = Status::Blocked;
    cout << "status: " << statusToText(s) << ", as int: " << static_cast<int>(s) << endl;
    // int x = s;   // ERROR for enum class - needs static_cast (that's the "type safety")

    cout << "area: " << geometry::circleArea(2) << ", g = " << physics::G << endl;
    using geometry::PI;                               // bring one name in
    cout << "PI: " << PI << endl;

    ull big = 18000000000000000000ULL;
    Text t = "alias works";
    cout << big << " " << t << endl;

    callCounter(); callCounter();
    cout << "callCounter called " << callCounter() << " times" << endl;   // 3

    return 0;
}
