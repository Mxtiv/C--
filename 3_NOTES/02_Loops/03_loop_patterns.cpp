// ======================================================================
// ADDED (gap-fill): loop PATTERNS you write again and again
// counting, sum/avg, digits of a number, reverse number, first match, flags,
// do-while menu, "repeat until valid" input, nested loop shapes
// Not from your original repo - written to fill a missing topic.
// ======================================================================

#include <iostream>
using namespace std;

int main()
{
    // ---------------- sum + count + average of 1..10 that are even ----------------
    int sum = 0, count = 0;
    for (int i = 1; i <= 10; i++)
    {
        if (i % 2 == 0)
        {
            sum += i;
            count++;
        }
    }
    cout << "even sum " << sum << ", count " << count << ", avg " << (double)sum / count << endl;

    // ---------------- digits of a number (while + % 10 + / 10) ----------------
    int n = 90417;
    int digitSum = 0, digits = 0, reversed = 0;
    int temp = n;
    while (temp > 0)
    {
        int last = temp % 10;          // take last digit
        digitSum += last;
        reversed = reversed * 10 + last;
        digits++;
        temp /= 10;                    // remove last digit
    }
    cout << n << ": digit sum " << digitSum << ", digits " << digits << ", reversed " << reversed << endl;

    // ---------------- find FIRST match and stop (break) ----------------
    int firstDiv7 = -1;
    for (int i = 50; i <= 100; i++)
    {
        if (i % 7 == 0)
        {
            firstDiv7 = i;
            break;
        }
    }
    cout << "first multiple of 7 in 50..100: " << firstDiv7 << endl;

    // ---------------- flag pattern: is n prime? ----------------
    int p = 97;
    bool isPrime = (p >= 2);
    for (int d = 2; d * d <= p; d++)
    {
        if (p % d == 0) { isPrime = false; break; }
    }
    cout << p << (isPrime ? " is prime" : " is not prime") << endl;

    // ---------------- nested loops: multiplication table + triangle ----------------
    for (int r = 1; r <= 3; r++)
    {
        for (int c = 1; c <= 5; c++)
            cout << r * c << "\t";
        cout << endl;
    }
    for (int r = 1; r <= 4; r++)
    {
        for (int c = 0; c < r; c++) cout << '*';
        cout << endl;
    }

    // ---------------- do-while MENU (runs at least once) ----------------
    // Interactive version (uncomment to use):
    //
    // int choice;
    // do {
    //     cout << "1. Add  2. Show  0. Exit\nChoice: ";
    //     cin >> choice;
    //     switch (choice) {
    //         case 1: /* ... */ break;
    //         case 2: /* ... */ break;
    //         case 0: cout << "Bye\n"; break;
    //         default: cout << "Wrong option\n";
    //     }
    // } while (choice != 0);

    // ---------------- "repeat until valid" input ----------------
    // int size;
    // do {
    //     cout << "Size (3-10): ";
    //     cin >> size;
    // } while (size < 3 || size > 10);

    // ---------------- "play again?" loop ----------------
    // char again;
    // do {
    //     /* one round */
    //     cout << "Again? (t/n): ";
    //     cin >> again;
    // } while (again == 't' || again == 'T');

    return 0;
}
