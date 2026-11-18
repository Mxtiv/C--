// ======================================================================
// length, substr, find/rfind + npos, replace, insert, erase, toupper/tolower in a loop,
// compare, stoi/stod, reverse by hand, split by ',' by hand (array + count)
// Original file: String/overviewString.cpp
// ======================================================================

#include <iostream>
#include <string>      // string, stoi, stod
#include <cctype>      // toupper, tolower
using namespace std;

int main()
{
    // ---------------- Basic String Creation ----------------
    string tekst1 = "Hello";
    string tekst2 = "World";
    string pusty = "";

    // ---------------- String Length ----------------
    cout << "Length of tekst1: " << tekst1.length() << endl;   // .length() or .size()
    if (pusty.length() == 0)
    {
        cout << "pusty is empty" << endl;
    }

    // ---------------- Substring: substr(start, how many) ----------------
    string fragment = tekst2.substr(1, 3);       // start at index 1, 3 characters
    cout << "Substring from tekst2: " << fragment << endl;              // "orl"

    string koncowka = tekst1.substr(tekst1.length() - 3);   // from index to the end
    cout << "Last 3 characters of tekst1: " << koncowka << endl;       // "llo"

    // ---------------- Find First and Last Occurrence ----------------
    string zdanie = "I love programming";
    cout << "First occurrence of 'o': " << zdanie.find('o') << endl;    // 3
    cout << "Last occurrence of 'o': " << zdanie.rfind('o') << endl;    // 9

    // find gives string::npos when there is NO such text
    if (zdanie.find("love") != string::npos)
    {
        cout << "'love' found in zdanie." << endl;
    }
    else
    {
        cout << "'love' not found in zdanie." << endl;
    }

    // ---------------- Replace, Insert, Erase ----------------
    zdanie.replace(2, 4, "like");       // from index 2, 4 characters -> "like"
    cout << "After replace: " << zdanie << endl;    // "I like programming"

    zdanie.insert(7, "really ");        // insert at index 7
    cout << "After insert: " << zdanie << endl;     // "I like really programming"

    zdanie.erase(7, 7);                 // remove 7 characters from index 7
    cout << "After erase: " << zdanie << endl;      // "I like programming"

    // ---------------- Upper / lower case: character by character ----------------
    for (int i = 0; i < zdanie.length(); i++)
    {
        zdanie[i] = toupper(zdanie[i]);
    }
    cout << "Uppercase: " << zdanie << endl;        // "I LIKE PROGRAMMING"

    for (int i = 0; i < zdanie.length(); i++)
    {
        zdanie[i] = tolower(zdanie[i]);
    }
    cout << "Lowercase: " << zdanie << endl;        // "i like programming"

    // ---------------- String Comparison ----------------
    string a = "apple";
    string b = "banana";
    if (a == b)
    {
        cout << "equal" << endl;
    }
    if (a < b)          // alphabetical order
    {
        cout << a << " comes before " << b << endl;
    }

    // ---------------- String to Number ----------------
    int liczba = stoi("100");
    double pi = stod("3.14159");
    cout << "stoi: " << liczba + 1 << ", stod: " << pi << endl;

    // ---------------- Reverse: build a new string from the end ----------------
    string doOdwrocenia = "C++ is fun!";
    string odwrocony = "";
    for (int i = doOdwrocenia.length() - 1; i >= 0; i--)
    {
        odwrocony = odwrocony + doOdwrocenia[i];
    }
    cout << "Reversed string: " << odwrocony << endl;   // "!nuf si ++C"

    // ---------------- Split by ',' : walk the string, collect parts into an array ----------------
    string dane = "apple,banana,cherry";
    string czesci[10];
    int ile = 0;
    string aktualna = "";
    for (int i = 0; i < dane.length(); i++)
    {
        if (dane[i] == ',')
        {
            czesci[ile] = aktualna;     // a comma ends one part
            ile++;
            aktualna = "";
        }
        else
        {
            aktualna = aktualna + dane[i];
        }
    }
    czesci[ile] = aktualna;             // the last part (no comma after it)
    ile++;

    cout << "Split by commas (" << ile << " parts): ";
    for (int i = 0; i < ile; i++)
    {
        cout << czesci[i] << " ";
    }
    cout << endl;

    return 0;
}
