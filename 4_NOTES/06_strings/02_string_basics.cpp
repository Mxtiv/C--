// ======================================================================
// concatenation, [] access and change, append, length, ==, loop over chars, c_str()
// Original file: String/stringBasics.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Declaring and joining strings with +
    string tekst1 = "Hello";
    string tekst2 = "World";
    string tekst3 = tekst1 + " " + tekst2;
    cout << "Concatenated string: " << tekst3 << endl;

    // Accessing characters - index from 0 to length() - 1
    cout << "First character: " << tekst3[0] << endl;
    cout << "Last character: " << tekst3[tekst3.length() - 1] << endl;

    // Changing a character and adding text at the end
    tekst3[0] = 'h';
    tekst3 = tekst3 + "!!!";        // the same as tekst3.append("!!!") or tekst3 += "!!!"
    cout << "Modified string: " << tekst3 << endl;

    cout << "Length of string: " << tekst3.length() << endl;

    // Comparing
    if (tekst1 == "Hello")
    {
        cout << "tekst1 is equal to 'Hello'" << endl;
    }

    // Going through every character
    cout << "Characters: ";
    for (int i = 0; i < (int)tekst3.length(); i++)
    {
        cout << tekst3[i] << " ";
    }
    cout << endl;

    // c_str() gives an old C-style text (char array) - needed by atoi, strcpy, ...
    cout << "C-style string: " << tekst3.c_str() << endl;

    return 0;
}
