// ======================================================================
// ADDED (gap-fill): <algorithm> + <numeric> cheat sheet on a vector -
// sort, reverse, find, count, count_if, min/max_element, accumulate, unique,
// remove_if (erase-remove), any_of/all_of, iterators, lambdas
// Not from your original repo - written to fill a missing topic.
// ======================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

void print(const string &label, const vector<int> &v)
{
    cout << label;
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main()
{
    vector<int> v = {5, 3, 8, 3, 9, 1, 8, 3};
    print("start:       ", v);

    // ---------------- iterators ----------------
    // v.begin() -> first element, v.end() -> one PAST the last. Most algorithms take (begin, end).
    cout << "first " << *v.begin() << ", last " << *(v.end() - 1) << ", back() " << v.back() << endl;

    // ---------------- min / max / sum / average ----------------
    auto minIt = min_element(v.begin(), v.end());
    auto maxIt = max_element(v.begin(), v.end());
    int sum = accumulate(v.begin(), v.end(), 0);       // 0 = start value (use 0.0 for double sum)
    cout << "min " << *minIt << " at " << (minIt - v.begin())
         << ", max " << *maxIt << ", sum " << sum
         << ", avg " << (double)sum / v.size() << endl;

    // ---------------- find / count ----------------
    auto it = find(v.begin(), v.end(), 9);
    cout << "9 found? " << (it != v.end()) << ", count of 3: " << count(v.begin(), v.end(), 3) << endl;
    int evens = count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });   // lambda condition
    cout << "even numbers: " << evens << endl;

    // ---------------- any_of / all_of / none_of ----------------
    cout << boolalpha
         << "any > 8? " << any_of(v.begin(), v.end(), [](int x) { return x > 8; })
         << ", all > 0? " << all_of(v.begin(), v.end(), [](int x) { return x > 0; }) << endl;

    // ---------------- sort / reverse ----------------
    vector<int> s = v;
    sort(s.begin(), s.end());                  print("sorted:      ", s);
    sort(s.begin(), s.end(), greater<int>());  print("descending:  ", s);
    reverse(s.begin(), s.end());               print("reversed:    ", s);

    // ---------------- remove duplicates (needs sorted data) ----------------
    s.erase(unique(s.begin(), s.end()), s.end());
    print("unique:      ", s);

    // ---------------- erase-remove idiom: delete all elements matching a condition ----------------
    vector<int> r = v;
    r.erase(remove_if(r.begin(), r.end(), [](int x) { return x == 3; }), r.end());
    print("without 3s:  ", r);

    // ---------------- transform: apply a function to every element ----------------
    vector<int> doubled(v.size());
    transform(v.begin(), v.end(), doubled.begin(), [](int x) { return x * 2; });
    print("doubled:     ", doubled);

    // ---------------- fill / iota ----------------
    vector<int> seq(5);
    iota(seq.begin(), seq.end(), 1);           // 1 2 3 4 5
    print("iota:        ", seq);
    fill(seq.begin(), seq.end(), 7);
    print("fill 7:      ", seq);

    // ---------------- the same algorithms work on plain arrays ----------------
    int arr[] = {4, 2, 6};
    sort(arr, arr + 3);
    cout << "array sorted: " << arr[0] << arr[1] << arr[2] << ", max " << *max_element(arr, arr + 3) << endl;

    return 0;
}
