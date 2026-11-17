// ======================================================================
// getline(cin, s) + find(" ")
// Original file: unsorted/stringi/StringGetLine.cpp
// FIXED - the bug was: prints find() - length() which underflows (size_t) to a huge number
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string napis1;
    cout << "podaj imie i nazwisko: ";
    getline(cin, napis1);
    size_t spacja = napis1.find(" ");
    if (spacja == string::npos) { cout << "brak spacji" << endl; return 0; }
    cout << "spacja na pozycji: " << spacja << endl;
    cout << "imie: " << napis1.substr(0, spacja) << ", nazwisko: " << napis1.substr(spacja + 1) << endl;
    return 0;
}
