// ======================================================================
// getline + istringstream >> word: split a line into words (array + count)
// Original file: unsorted/stringi/stringOG.cpp
// (Exam code: walk the string character by character instead - see 01_string_overview.cpp.)
// ======================================================================

#include <iostream>
#include <string>
#include <sstream>     // istringstream - the topic of this file
using namespace std;

const int MAKS_SLOW = 50;

// Writes the words into slowa[] and RETURNS how many there are
int rozdzielNaSlowa(string napis, string slowa[])
{
    istringstream strumien(napis);   // reads from a string like cin reads from the keyboard
    string slowo;
    int ile = 0;
    while (strumien >> slowo && ile < MAKS_SLOW)   // >> stops at spaces, just like cin >>
    {
        slowa[ile] = slowo;
        ile++;
    }
    return ile;
}

int main()
{
    string napis;
    cout << "Wprowadź napis: ";
    getline(cin, napis);

    string slowa[MAKS_SLOW];
    int ile = rozdzielNaSlowa(napis, slowa);

    cout << "Oto rozdzielone słowa (" << ile << "):" << endl;
    for (int i = 0; i < ile; i++)
    {
        cout << slowa[i] << endl;
    }
    return 0;
}
