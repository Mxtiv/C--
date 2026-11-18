// ======================================================================
// ADDED (gap-fill): operators - arithmetic, integer division, modulo,
// increment, compound assignment, comparison, logical, precedence
// Not from your original repo - written to fill a missing topic.
// ======================================================================

#include <iostream>
using namespace std;

int main()
{
    // ---------------- ARITHMETIC ----------------
    int a = 7;
    int b = 2;
    cout << "a + b = " << a + b << endl;      // 9
    cout << "a - b = " << a - b << endl;      // 5
    cout << "a * b = " << a * b << endl;      // 14
    cout << "a / b = " << a / b << endl;      // 3   <- INTEGER DIVISION cuts the fraction!
    cout << "a % b = " << a % b << endl;      // 1   <- remainder (modulo), only for integers

    // To get 3.5 at least ONE side must be a floating type:
    cout << "a / 2.0 = " << a / 2.0 << endl;                     // 3.5
    cout << "(double)a / b = " << (double)a / b << endl;         // 3.5
    // Typical bug:  double srednia = suma / ile;   (both int) -> wrong. Cast one of them.

    // modulo tricks
    int n = 1234;
    cout << "last digit: " << n % 10 << ", without last digit: " << n / 10 << endl;
    cout << "is even? " << (n % 2 == 0) << ", divisible by 3? " << (n % 3 == 0) << endl;

    // ---------------- INCREMENT / DECREMENT ----------------
    int i = 5;
    cout << i++ << endl;   // prints 5, THEN i becomes 6   (post-increment)
    cout << ++i << endl;   // i becomes 7, THEN prints 7    (pre-increment)
    i--;                   // 6

    // ---------------- COMPOUND ASSIGNMENT ----------------
    int x = 10;
    x += 5;   // x = x + 5  -> 15
    x -= 3;   // 12
    x *= 2;   // 24
    x /= 4;   // 6
    x %= 4;   // 2
    cout << "x = " << x << endl;

    // ---------------- COMPARISON (result is bool) ----------------
    cout << (a == b) << (a != b) << (a > b) << (a < b) << (a >= 7) << (a <= 6) << endl;   // 011010
    // CLASSIC BUG:  if (x = 5)  assigns 5 (always true). Comparison is ==

    // ---------------- LOGICAL ----------------
    bool p = true;
    bool q = false;
    cout << (p && q) << (p || q) << (!p) << endl;    // AND, OR, NOT -> 0 1 0
    int wiek = 20;
    if (wiek >= 18 && wiek <= 65)
    {
        cout << "working age" << endl;
    }
    // Short-circuit: in (ile != 0 && suma / ile > 5) the division never runs when ile == 0

    // ---------------- PRECEDENCE (when in doubt, use parentheses) ----------------
    // * / %  before  + -  before  < > <= >=  before  == !=  before  &&  before  ||
    cout << 2 + 3 * 4 << " vs " << (2 + 3) * 4 << endl;   // 14 vs 20

    // ---------------- char arithmetic ----------------
    char cyfra = '7';
    int wartosc = cyfra - '0';         // '7' - '0' = 7   (char digit -> number)
    char nastepna = 'a' + 1;           // 'b'
    cout << wartosc << " " << nastepna << " " << (int)'A' << endl;   // 7 b 65

    return 0;
}
