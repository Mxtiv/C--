// ======================================================================
// ADDED (gap-fill): loop PATTERNS you write again and again
// counting, sum/avg, digits of a number, reverse number, first match, flags,
// nested loop shapes, do-while menu, "repeat until valid" input
// Not from your original repo - written to fill a missing topic.
// ======================================================================

#include <iostream>
using namespace std;

int main()
{
    // ---------------- sum + count + average of 1..10 that are even ----------------
    int suma = 0;
    int ile = 0;
    for (int i = 1; i <= 10; i++)
    {
        if (i % 2 == 0)
        {
            suma = suma + i;
            ile++;
        }
    }
    cout << "even sum " << suma << ", count " << ile << ", avg " << (double)suma / ile << endl;

    // ---------------- digits of a number (while + % 10 + / 10) ----------------
    int n = 90417;
    int sumaCyfr = 0;
    int ileCyfr = 0;
    int odwrocona = 0;
    int kopia = n;
    while (kopia > 0)
    {
        int ostatnia = kopia % 10;          // take last digit
        sumaCyfr = sumaCyfr + ostatnia;
        odwrocona = odwrocona * 10 + ostatnia;
        ileCyfr++;
        kopia = kopia / 10;                 // remove last digit
    }
    cout << n << ": digit sum " << sumaCyfr << ", digits " << ileCyfr << ", reversed " << odwrocona << endl;

    // ---------------- find FIRST match and stop (break) ----------------
    int pierwszaPrzez7 = -1;
    for (int i = 50; i <= 100; i++)
    {
        if (i % 7 == 0)
        {
            pierwszaPrzez7 = i;
            break;
        }
    }
    cout << "first multiple of 7 in 50..100: " << pierwszaPrzez7 << endl;

    // ---------------- flag pattern: is p prime? ----------------
    int p = 97;
    bool pierwsza = true;
    if (p < 2)
    {
        pierwsza = false;
    }
    for (int d = 2; d * d <= p; d++)
    {
        if (p % d == 0)
        {
            pierwsza = false;
            break;
        }
    }
    if (pierwsza)
    {
        cout << p << " is prime" << endl;
    }
    else
    {
        cout << p << " is not prime" << endl;
    }

    // ---------------- nested loops: multiplication table + triangle ----------------
    for (int w = 1; w <= 3; w++)
    {
        for (int k = 1; k <= 5; k++)
        {
            cout << w * k << "\t";
        }
        cout << endl;
    }
    for (int w = 1; w <= 4; w++)
    {
        for (int k = 0; k < w; k++)
        {
            cout << '*';
        }
        cout << endl;
    }

    // ---------------- do-while MENU (runs at least once) ----------------
    // Interactive version (uncomment to use):
    //
    // int wybor;
    // do
    // {
    //     cout << "1. Add  2. Show  0. Exit\nChoice: ";
    //     cin >> wybor;
    //     switch (wybor)
    //     {
    //     case 1:
    //         /* ... */
    //         break;
    //     case 2:
    //         /* ... */
    //         break;
    //     case 0:
    //         cout << "Bye\n";
    //         break;
    //     default:
    //         cout << "Wrong option\n";
    //         break;
    //     }
    // } while (wybor != 0);

    // ---------------- "repeat until valid" input ----------------
    // int rozmiar;
    // do
    // {
    //     cout << "Size (3-10): ";
    //     cin >> rozmiar;
    // } while (rozmiar < 3 || rozmiar > 10);

    // ---------------- "play again?" loop ----------------
    // char jeszczeRaz;
    // do
    // {
    //     /* one round */
    //     cout << "Again? (t/n): ";
    //     cin >> jeszczeRaz;
    // } while (jeszczeRaz == 't' || jeszczeRaz == 'T');

    return 0;
}
