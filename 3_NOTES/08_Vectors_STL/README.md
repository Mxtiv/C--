# 08_Vectors_STL - vector and the STL - algorithms, map, set, stack, queue

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [2_BUILDING_BLOCKS/11_vector_stl.cpp](../../2_BUILDING_BLOCKS/11_vector_stl.cpp)

```cpp
#include <vector>
vector<int> v;  vector<int> v(n);  vector<int> v = {1, 2, 3};  vector<int> v(n, 0);
v.push_back(x)  v.pop_back()  v.size()  v[i]  v.at(i)  v.front()  v.back()  v.empty()
v.insert(v.begin() + i, x)   v.erase(v.begin() + i)   v.clear()   v.resize(n)
void f(vector<int> &v)          // pass by REFERENCE to modify (by value = copy!)
#include <algorithm> / <numeric>
sort(v.begin(), v.end())  reverse(...)  find(...)  count(...)  count_if(..., lambda)
*min_element(...)  *max_element(...)  accumulate(v.begin(), v.end(), 0)
map<string,int> m; m["key"]++;   set<int> s;   stack<int>   queue<int>   pair<a,b>
```

## Files

| File | What it shows | |
|---|---|---|
| [01_overview_vectors.cpp](01_overview_vectors.cpp) | template print, fill with push_back/reserve, min_element, max_element, accumulate, average, bubble sort, std::sort | ⭐ |
| [02_vector_commands_push_insert_erase.cpp](02_vector_commands_push_insert_erase.cpp) | push_back, insert(begin()+i), size, capacity, resize, erase one / range, clear, empty (Polish comments) | ⭐ 🔧 fixed |
| [03_size_vs_capacity.cpp](03_size_vs_capacity.cpp) | size() vs capacity() after resize(0) and clear() | 🔧 fixed |
| [04_fill_random_foreach.cpp](04_fill_random_foreach.cpp) | fill with random numbers, range-for with const auto&amp;; commented extras: sort, unique+erase, empty |  |
| [05_vector_loops_minmax_bubble.cpp](05_vector_loops_minmax_bubble.cpp) | vector&lt;int&gt;(n), loops, manual min/max/sum/avg, bubble sort |  |
| [06_stl_algorithms.cpp](06_stl_algorithms.cpp) | &lt;algorithm&gt; + &lt;numeric&gt; cheat sheet on a vector - sort, reverse, find, count, count_if, min/max_element, accumulate, unique, remove_if (erase-remove), any_of/all_of, iterators, lambdas | ⭐ 🆕 added |
| [07_map_set_pair.cpp](07_map_set_pair.cpp) | other STL containers - pair, map (dictionary), set (unique sorted), stack, queue - plus the typical "count occurrences with a map" pattern | 🆕 added |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [test_vector_insert_div3.cpp](exercises/test_vector_insert_div3.cpp) | test: fill, insert, push_back, erase, print divisible by 3 | 🔧 fixed |
| [vector_menu_sum_avg.cpp](exercises/vector_menu_sum_avg.cpp) | char menu: print / add / sum / average of a vector |  |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
