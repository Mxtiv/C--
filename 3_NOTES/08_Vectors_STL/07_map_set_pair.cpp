// ======================================================================
// ADDED (gap-fill): other STL containers - pair, map (dictionary), set (unique sorted),
// stack, queue - plus the typical "count occurrences with a map" pattern
// Not from your original repo - written to fill a missing topic.
// ======================================================================

#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <utility>   // pair
using namespace std;

int main()
{
    // ---------------- pair: two values together ----------------
    pair<string, int> p = {"Ala", 17};
    cout << p.first << " " << p.second << endl;
    auto p2 = make_pair(3.5, 'x');
    cout << p2.first << " " << p2.second << endl;

    // ---------------- map<key, value>: sorted by key, keys are unique ----------------
    map<string, int> ages;
    ages["Ola"] = 18;                 // insert or overwrite
    ages["Bartek"] = 17;
    ages.insert({"Celina", 19});
    ages["Ola"] = 20;                 // overwrite

    for (const auto &entry : ages)    // iterates in key order: Bartek, Celina, Ola
        cout << entry.first << " -> " << entry.second << endl;

    if (ages.count("Bartek")) cout << "Bartek is in the map" << endl;
    auto it = ages.find("Zenon");
    if (it == ages.end()) cout << "Zenon not found" << endl;
    ages.erase("Celina");
    cout << "size now " << ages.size() << endl;

    // ---------------- typical pattern: count how many times each word occurs ----------------
    string words[] = {"kot", "pies", "kot", "mysz", "kot", "pies"};
    map<string, int> freq;
    for (const string &w : words) freq[w]++;          // missing key starts at 0
    for (const auto &[word, n] : freq)                // C++17 structured binding
        cout << word << ": " << n << endl;

    // ---------------- set: unique values, always sorted ----------------
    set<int> s = {5, 1, 5, 3, 1, 9};
    s.insert(4);
    for (int x : s) cout << x << " ";                 // 1 3 4 5 9
    cout << "| contains 3? " << s.count(3) << endl;

    // ---------------- stack: LIFO (last in, first out) ----------------
    stack<int> st;
    st.push(1); st.push(2); st.push(3);
    while (!st.empty()) { cout << st.top() << " "; st.pop(); }   // 3 2 1
    cout << endl;

    // ---------------- queue: FIFO (first in, first out) ----------------
    queue<string> q;
    q.push("first"); q.push("second"); q.push("third");
    while (!q.empty()) { cout << q.front() << " "; q.pop(); }    // first second third
    cout << endl;

    return 0;
}
