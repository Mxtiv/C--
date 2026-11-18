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
    string napis;
    cout << "podaj imie i nazwisko: ";
    getline(cin, napis);

    if (napis.find(" ") == string::npos)
    {
        cout << "brak spacji" << endl;
        return 0;
    }
    int spacja = napis.find(" ");
    cout << "spacja na pozycji: " << spacja << endl;
    cout << "imie: " << napis.substr(0, spacja) << ", nazwisko: " << napis.substr(spacja + 1) << endl;
    return 0;
}
