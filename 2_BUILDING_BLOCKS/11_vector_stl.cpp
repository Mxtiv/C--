// ======================================================================
// BUILDING BLOCKS: vector + STL - fill/display vectors, min/max/sum with algorithms,
// remove duplicates, remove by condition, sort structs by a field, count words (map)
// HOW TO USE: copy the comment box + code under a //@ line, up to the next //@ line.
// Pass vectors BY REFERENCE (vector<int> &v) when the function changes them.
// ======================================================================

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

//@ VEC-01 | fill a vector with n random ints min..max (vector passed by reference!) | <vector> <cstdlib> <ctime>
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
    v.clear();
    for (int i = 0; i < n; i++)
        v.push_back(rand() % (max - min + 1) + min);
}

//@ VEC-02 | display a vector in one line | <iostream> <vector>
/********************************************************
 * nazwa funkcji: wyswietlWektor
 * opis funkcji: wyświetla elementy wektora w jednym wierszu
 * parametry: v - wektor liczb
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void wyswietlWektor(const vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

//@ VEC-03 | min, max, sum, average of a vector with <algorithm>/<numeric> (prints them) | <iostream> <vector> <algorithm> <numeric>
/********************************************************
 * nazwa funkcji: statystykiWektora
 * opis funkcji: wyświetla najmniejszą i największą wartość, sumę i średnią elementów wektora
 * parametry: v - niepusty wektor liczb
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void statystykiWektora(const vector<int> &v)
{
    int min = *min_element(v.begin(), v.end());
    int max = *max_element(v.begin(), v.end());
    long long suma = accumulate(v.begin(), v.end(), 0LL);
    cout << "min: " << min << ", max: " << max << ", suma: " << suma
         << ", srednia: " << (double)suma / v.size() << endl;
}

//@ VEC-04 | remove duplicates (result is sorted) | <vector> <algorithm>
/********************************************************
 * nazwa funkcji: usunDuplikaty
 * opis funkcji: usuwa powtarzające się wartości z wektora (wynik jest posortowany)
 * parametry: v - wektor liczb (przekazany przez referencję)
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void usunDuplikaty(vector<int> &v)
{
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

//@ VEC-05 | remove all elements meeting a condition (here: even) - erase-remove idiom | <vector> <algorithm>
/********************************************************
 * nazwa funkcji: usunParzyste
 * opis funkcji: usuwa z wektora wszystkie liczby parzyste
 * parametry: v - wektor liczb (przekazany przez referencję)
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void usunParzyste(vector<int> &v)
{
    v.erase(remove_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; }), v.end());
}

//@ VEC-06 | sort a vector of structs by a field (descending) with a lambda | <vector> <algorithm> <string>
/********************************************************
 * nazwa struktury: Zawodnik
 * opis struktury: zawodnik z liczbą punktów
 * pola: nazwisko, punkty
 * autor: <numer zdającego>
 ********************************************************/
struct Zawodnik
{
    string nazwisko;
    int punkty;
};

/********************************************************
 * nazwa funkcji: sortujZawodnikow
 * opis funkcji: sortuje zawodników malejąco według liczby punktów
 * parametry: lista - wektor zawodników (przekazany przez referencję)
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void sortujZawodnikow(vector<Zawodnik> &lista)
{
    sort(lista.begin(), lista.end(), [](const Zawodnik &a, const Zawodnik &b) {
        return a.punkty > b.punkty;               // > descending, < ascending
    });
}

//@ VEC-07 | count how many times each word occurs (map<string,int>), prints in alphabetical order | <iostream> <map> <string> <sstream>
/********************************************************
 * nazwa funkcji: zliczKazdeSlowo
 * opis funkcji: zlicza wystąpienia każdego słowa w tekście i wyświetla wyniki alfabetycznie
 * parametry: tekst - analizowany tekst
 * zwracany typ i opis: map<string, int> - słowo -> liczba wystąpień
 * autor: <numer zdającego>
 ********************************************************/
map<string, int> zliczKazdeSlowo(const string &tekst)
{
    map<string, int> licznik;
    istringstream strumien(tekst);
    string slowo;
    while (strumien >> slowo)
        licznik[slowo]++;                         // a new key starts at 0
    for (const auto &para : licznik)
        cout << para.first << ": " << para.second << endl;
    return licznik;
}

// ====================== DEMO (don't copy) ======================
int main()
{
    srand(time(0));
    vector<int> v;
    wypelnijWektor(v, 10, 1, 10);
    wyswietlWektor(v);
    statystykiWektora(v);
    usunDuplikaty(v);
    wyswietlWektor(v);
    usunParzyste(v);
    wyswietlWektor(v);

    vector<Zawodnik> z = {{"Nowak", 12}, {"Kowal", 30}, {"Lis", 21}};
    sortujZawodnikow(z);
    for (const Zawodnik &x : z) cout << x.nazwisko << " " << x.punkty << " | ";
    cout << endl;

    zliczKazdeSlowo("kot pies kot mysz kot");
    return 0;
}
