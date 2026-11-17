// ======================================================================
// ADDED (gap-fill): random numbers - rand/srand (exam style) and <random> (modern)
// Not from your original repo - written to fill a missing topic.
// ======================================================================

#include <iostream>
#include <cstdlib>   // rand, srand
#include <ctime>     // time
#include <random>    // mt19937, uniform_int_distribution (modern way)
using namespace std;

int main()
{
    // ---------------- 1) rand() + srand() ----------------
    // Call srand ONCE at the start of main. Without it you get the same numbers every run.
    // DON'T call srand inside a loop (many of the older files do: srand(time(NULL)*(i+1)) -
    // it works only by accident and gives poor randomness).
    srand(time(0));

    // Formula: rand() % (how_many_values) + start
    int dice   = rand() % 6 + 1;        // 1..6
    int zeroTo99 = rand() % 100;        // 0..99
    int from10to20 = rand() % 11 + 10;  // 10..20   (20 - 10 + 1 = 11 values)

    int minV = -5, maxV = 5;
    int range = rand() % (maxV - minV + 1) + minV;   // general: min..max inclusive

    double real01 = (double)rand() / RAND_MAX;        // 0.0 .. 1.0

    cout << dice << " " << zeroTo99 << " " << from10to20 << " " << range << " " << real01 << endl;

    // fill an array with random numbers 1..6
    const int N = 10;
    int tab[N];
    for (int i = 0; i < N; i++)
        tab[i] = rand() % 6 + 1;
    for (int i = 0; i < N; i++) cout << tab[i] << " ";
    cout << endl;

    // ---------------- 2) modern <random> (better quality) ----------------
    random_device rd;                               // seed source
    mt19937 gen(rd());                              // Mersenne Twister generator
    uniform_int_distribution<int> diceDist(1, 6);   // integers 1..6 inclusive
    uniform_real_distribution<double> realDist(0.0, 1.0);

    for (int i = 0; i < 5; i++) cout << diceDist(gen) << " ";
    cout << "| " << realDist(gen) << endl;

    return 0;
}
