// ======================================================================
// substr, find (+ npos), replace, erase, insert - editing a string step by step
// Original file: String/stringUltimate.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string tekst = "Hello World";

    // Substring
    string fragment = tekst.substr(6, 5);       // "World"
    cout << "Substring: " << fragment << endl;

    // Find - gives the index of the first match, or string::npos if there is none
    int pozycja = tekst.find("World");
    if (tekst.find("World") != string::npos)
    {
        cout << "'World' found at position: " << pozycja << endl;
    }
    else
    {
        cout << "'World' not found." << endl;
    }

    // Replace 5 characters from pozycja
    tekst.replace(pozycja, 5, "Universe");
    cout << "After replacement: " << tekst << endl;     // "Hello Universe"

    // Erase 9 characters from index 5
    tekst.erase(5, 9);
    cout << "After erasing: " << tekst << endl;         // "Hello"

    // Insert at index 5
    tekst.insert(5, " People");
    cout << "After insertion: " << tekst << endl;       // "Hello People"

    // Compare
    if (tekst == "Hello People")
    {
        cout << "tekst is equal to \"Hello People\"" << endl;
    }

    return 0;
}
