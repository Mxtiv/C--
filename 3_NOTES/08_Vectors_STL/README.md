# 08_Vectors_STL - vector and the STL - basic algorithms, map, set

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [2_BUILDING_BLOCKS/11_vector_stl.cpp](../../2_BUILDING_BLOCKS/11_vector_stl.cpp)

```cpp
#include <vector>
vector<int> v;   vector<int> v(n);   vector<int> v = {1, 2, 3};
v.push_back(x)  v.size()  v[i]  v.empty()  v.clear()  v.resize(n)
v.insert(v.begin() + i, x)   v.erase(v.begin() + i)
for (int i = 0; i < (int)v.size(); i++)      // the loop to use
{
    cout << v[i] << " ";
}
void f(vector<int> v)           // by value = a COPY (fine for reading)
void f(vector<int> &v)          // by reference - needed to ADD / CHANGE elements
// Only to recognise (exam: write your own loop):
sort(v.begin(), v.end())  reverse(...)  count(...)  *min_element(...)  accumulate(..., 0)
map<string, int> m;  m["kot"]++;      set<int> s;  s.insert(5);      pair<string, int> p("Ala", 17);
```

## Files

| File | What it shows | |
|---|---|---|
| [01_overview_vectors.cpp](01_overview_vectors.cpp) | vector in functions: fill with push_back (&amp;), print, min, max, sum, average, bubble sort | ⭐ |
| [02_vector_commands_push_insert_erase.cpp](02_vector_commands_push_insert_erase.cpp) | push_back, insert(begin()+i), size, capacity, resize, erase one / range, clear, empty (Polish comments) | ⭐ 🔧 fixed |
| [03_size_vs_capacity.cpp](03_size_vs_capacity.cpp) | size() vs capacity() after resize(0) and clear() | 🔧 fixed |
| [04_fill_random_foreach.cpp](04_fill_random_foreach.cpp) | fill with random numbers; index loop vs range-for ("foreach") |  |
| [05_vector_loops_minmax_bubble.cpp](05_vector_loops_minmax_bubble.cpp) | vector&lt;int&gt;(n) used like an array in main: loops, min/max/sum/avg, bubble sort |  |
| [06_stl_algorithms.cpp](06_stl_algorithms.cpp) | basic idea of &lt;algorithm&gt; / &lt;numeric&gt;: sort, reverse, find, count, min/max_element, accumulate | 🆕 added |
| [07_map_set_pair.cpp](07_map_set_pair.cpp) | basic idea of pair, map (counting words), set (unique sorted values) | 🆕 added |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [test_vector_insert_div3.cpp](exercises/test_vector_insert_div3.cpp) | test: fill, insert, push_back, erase, print divisible by 3 | 🔧 fixed |
| [vector_menu_sum_avg.cpp](exercises/vector_menu_sum_avg.cpp) | char menu: print / add / sum / average of a vector |  |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
