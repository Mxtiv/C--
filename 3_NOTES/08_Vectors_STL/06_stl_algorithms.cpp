// ======================================================================
// ADDED (gap-fill): the basic idea of <algorithm> / <numeric> on a vector -
// sort, reverse, find, count, min_element / max_element, accumulate
// Not from your original repo - written to fill a missing topic.
// Exam code: write these yourself with a loop (see 01_overview_vectors.cpp) -
// this file is only so you RECOGNISE them in other people's code.
// ======================================================================

#include <iostream>
#include <vector>
#include <algorithm>   // sort, reverse, find, count, min_element, max_element
#include <numeric>     // accumulate
using namespace std;

void wypisz(vector<int> wektor)
{
    for (int i = 0; i < wektor.size(); i++)
    {
        cout << wektor[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> wektor = {5, 3, 8, 3, 9, 1, 8, 3};
    wypisz(wektor);

    // The algorithms take a RANGE: wektor.begin() = first element,
    // wektor.end() = one place PAST the last element.

    sort(wektor.begin(), wektor.end());             // ascending
    cout << "sorted:   ";
    wypisz(wektor);

    reverse(wektor.begin(), wektor.end());          // reverse order
    cout << "reversed: ";
    wypisz(wektor);

    cout << "count of 3: " << count(wektor.begin(), wektor.end(), 3) << endl;

    // find gives the place of the value, or wektor.end() if it is not there
    if (find(wektor.begin(), wektor.end(), 9) != wektor.end())
    {
        cout << "9 found" << endl;
    }

    // min_element / max_element give a place; * reads the value from that place
    cout << "min: " << *min_element(wektor.begin(), wektor.end()) << endl;
    cout << "max: " << *max_element(wektor.begin(), wektor.end()) << endl;

    // accumulate adds everything up, starting from 0
    cout << "sum: " << accumulate(wektor.begin(), wektor.end(), 0) << endl;

    // The same works on a plain array: tab and tab + n are its begin and end
    int tab[3] = {4, 2, 6};
    sort(tab, tab + 3);
    cout << "array sorted: " << tab[0] << " " << tab[1] << " " << tab[2] << endl;

    return 0;
}
