// ======================================================================
// BUILDING BLOCKS: vector - fill a vector (push_back), display it, min/max/sum/average
// HOW TO USE: copy the comment box + code under a //@ line, up to the next //@ line.
// A vector is an array that grows by itself:  v.push_back(x) adds, v.size() = how many,
// v[i] = element i. Pass it BY REFERENCE (vector<int> &v) when the function changes it.
// ======================================================================

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

//@ VEC-01 | fill a vector with n random ints min..max with push_back (vector passed by reference!) | <vector> <cstdlib> <ctime>
/********************************************************
 * nazwa funkcji: wypelnijWektor
 * opis funkcji: wypełnia wektor n liczbami pseudolosowymi z przedziału min..max
 * parametry: v - wektor do wypełnienia (przekazany przez referencję)
 *            n - liczba elementów
 *            min - najmniejsza losowana wartość
 *            max - największa losowana wartość
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void wypelnijWektor(vector<int> &v, int n, int min, int max)
{
    v.clear();                                   // start from an empty vector
    for (int i = 0; i < n; i++)
    {
        v.push_back(rand() % (max - min + 1) + min);
    }
}

//@ VEC-02 | display a vector in one line (index loop up to v.size()) | <iostream> <vector>
/********************************************************
 * nazwa funkcji: wyswietlWektor
 * opis funkcji: wyświetla elementy wektora w jednym wierszu
 * parametry: v - wektor liczb
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void wyswietlWektor(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

//@ VEC-03 | min, max, sum, average of a vector with one own loop (prints them) | <iostream> <vector>
/********************************************************
 * nazwa funkcji: statystykiWektora
 * opis funkcji: wyświetla najmniejszą i największą wartość, sumę i średnią elementów wektora
 * parametry: v - niepusty wektor liczb
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void statystykiWektora(vector<int> v)
{
    int min = v[0];
    int max = v[0];
    int suma = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < min)
        {
            min = v[i];
        }
        if (v[i] > max)
        {
            max = v[i];
        }
        suma += v[i];
    }
    double srednia = (double)suma / v.size();
    cout << "min: " << min << ", max: " << max << ", suma: " << suma << ", srednia: " << srednia << endl;
}

// ====================== DEMO (don't copy) ======================
int main()
{
    srand(time(0));
    vector<int> v;
    wypelnijWektor(v, 10, 1, 10);
    wyswietlWektor(v);
    statystykiWektora(v);
    v.push_back(100);                            // one more element at the end
    cout << "po push_back: " << v.size() << " elementow" << endl;
    wyswietlWektor(v);
    return 0;
}
