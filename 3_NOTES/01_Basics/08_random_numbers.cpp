// ======================================================================
// ADDED (gap-fill): random numbers - rand / srand (exam style)
// Not from your original repo - written to fill a missing topic.
// ======================================================================

#include <iostream>
#include <cstdlib>   // rand, srand
#include <ctime>     // time
using namespace std;

int main()
{
    // Call srand ONCE at the start of main. Without it you get the same numbers every run.
    // DON'T call srand inside a loop (some older files do: srand(time(NULL)*(i+1)) -
    // it works only by accident and gives poor randomness).
    srand(time(0));

    // Formula: rand() % (how_many_values) + start
    int kostka = rand() % 6 + 1;        // 1..6
    int od0do99 = rand() % 100;         // 0..99
    int od10do20 = rand() % 11 + 10;    // 10..20   (20 - 10 + 1 = 11 values)

    int min = -5;
    int max = 5;
    int zZakresu = rand() % (max - min + 1) + min;   // general: min..max inclusive

    double od0do1 = (double)rand() / RAND_MAX;       // 0.0 .. 1.0

    cout << kostka << " " << od0do99 << " " << od10do20 << " " << zZakresu << " " << od0do1 << endl;

    // fill an array with random numbers 1..6
    const int N = 10;
    int tab[N];
    for (int i = 0; i < N; i++)
    {
        tab[i] = rand() % 6 + 1;
    }
    for (int i = 0; i < N; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;

    return 0;
}
