// ======================================================================
// for, while, do-while, break, continue, nested loops, infinite loop + break,
// changing every element of an array in a loop
// Original file: Loops/EveryLoopDetailed.cpp
// ======================================================================

#include <iostream>
using namespace std;

int main()
{
    // 1. For loop - use it when you know how many steps there are
    cout << "For loop:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Iteration " << i + 1 << endl;
    }

    // 2. While loop - checks the condition BEFORE each step
    cout << "\nWhile loop:\n";
    int i = 0;
    while (i < 5)
    {
        cout << "Iteration " << i + 1 << endl;
        i++;                    // without this the loop would never end
    }

    // 3. While loop that never runs - the condition is false from the start
    cout << "\nWhile loop (condition never met):\n";
    int licznik = 0;
    while (licznik > 5)
    {
        cout << "This will not be printed.\n";
        licznik++;
    }

    // 4. Do-while loop - checks the condition AFTER each step, so it runs at least once
    cout << "\nDo-while loop:\n";
    int j = 0;
    do
    {
        cout << "Iteration " << j + 1 << endl;
        j++;
    } while (j < 5);

    // 5. Nested for loop - the inner loop runs fully for every step of the outer loop
    cout << "\nNested for loop:\n";
    for (int w = 0; w < 3; w++)
    {
        for (int k = 0; k < 3; k++)
        {
            cout << "w: " << w << ", k: " << k << endl;
        }
    }

    // 6. break - leaves the loop at once
    cout << "\nFor loop with break:\n";
    for (int k = 0; k < 5; k++)
    {
        if (k == 3)
        {
            cout << "Breaking loop at iteration " << k + 1 << endl;
            break;
        }
        cout << "Iteration " << k + 1 << endl;
    }

    // 7. Infinite loop + break - stops only when break runs
    cout << "\nInfinite while loop with break:\n";
    int l = 0;
    while (true)
    {
        if (l == 3)
        {
            cout << "Breaking infinite loop at iteration " << l + 1 << endl;
            break;
        }
        cout << "Iteration " << l + 1 << endl;
        l++;
    }

    // 8. continue - skips the rest of THIS step and goes to the next one
    cout << "\nFor loop with continue:\n";
    for (int k = 0; k < 5; k++)
    {
        if (k == 2)
        {
            continue;           // iteration 3 is not printed
        }
        cout << "Iteration " << k + 1 << endl;
    }
    // In a while / do-while loop remember to increase the counter BEFORE continue,
    // otherwise the loop gets stuck on the same value forever.

    // 9. Going through an array and changing every element
    cout << "\nArray in a for loop:\n";
    const int N = 5;
    int tab[N] = {10, 20, 30, 40, 50};
    for (int k = 0; k < N; k++)
    {
        tab[k] = tab[k] + 5;    // increase each element by 5
    }
    for (int k = 0; k < N; k++)
    {
        cout << "Updated value: " << tab[k] << endl;
    }
    // In other code you may see "range-for":  for (int x : tab)  - it walks the whole
    // array without an index. The index loop above does the same and works everywhere.

    return 0;
}
