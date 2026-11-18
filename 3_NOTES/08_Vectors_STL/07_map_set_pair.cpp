// ======================================================================
// ADDED (gap-fill): the basic idea of other STL containers - pair, map (dictionary),
// set (unique sorted values) - plus the typical "count occurrences with a map" pattern
// Not from your original repo - written to fill a missing topic.
// Exam code: an array + count does the same job (see 04_Arrays); this is only to recognise them.
// ======================================================================

#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main()
{
    // ---------------- pair: two values kept together ----------------
    pair<string, int> osoba("Ala", 17);
    cout << osoba.first << " " << osoba.second << endl;

    // ---------------- map<key, value>: like an array indexed by a string ----------------
    map<string, int> wiek;
    wiek["Ola"] = 18;                 // add (or overwrite) the value for key "Ola"
    wiek["Bartek"] = 17;
    cout << "Ola has " << wiek["Ola"] << " years" << endl;

    // typical pattern: count how many times each word occurs
    const int ILE_SLOW = 6;
    string slowa[ILE_SLOW] = {"kot", "pies", "kot", "mysz", "kot", "pies"};
    map<string, int> licznik;
    for (int i = 0; i < ILE_SLOW; i++)
    {
        licznik[slowa[i]]++;          // a new key starts at 0
    }

    // going through a map: every element is a pair (key, value), sorted by key
    for (pair<string, int> para : licznik)
    {
        cout << para.first << ": " << para.second << endl;
    }

    // ---------------- set: every value only once, always sorted ----------------
    set<int> zbior;
    zbior.insert(5);
    zbior.insert(1);
    zbior.insert(5);                  // already there - ignored
    zbior.insert(3);
    for (int x : zbior)
    {
        cout << x << " ";             // 1 3 5
    }
    cout << "| contains 3? " << zbior.count(3) << endl;

    return 0;
}
