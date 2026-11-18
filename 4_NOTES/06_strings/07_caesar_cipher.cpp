// ======================================================================
// Caesar cipher +3 encrypt / decrypt (lowercase, wraps around)
// Original file: unsorted/sprawdzian/stringEncrypt.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

// 'a'..'w' -> +3,   'x', 'y', 'z' -> wrap to 'a', 'b', 'c'.  Other characters stay.
string szyfrowanie(string tekst)
{
    for (int i = 0; i < tekst.length(); i++)
    {
        if (tekst[i] >= 'a' && tekst[i] <= 'w')
        {
            tekst[i] = tekst[i] + 3;
        }
        else if (tekst[i] >= 'x' && tekst[i] <= 'z')
        {
            tekst[i] = tekst[i] + 3 - 26;
        }
    }
    return tekst;
}

// The other way: 'd'..'z' -> -3,  'a', 'b', 'c' -> wrap to 'x', 'y', 'z'
string deszyfrowanie(string tekst)
{
    for (int i = 0; i < tekst.length(); i++)
    {
        if (tekst[i] >= 'd' && tekst[i] <= 'z')
        {
            tekst[i] = tekst[i] - 3;
        }
        else if (tekst[i] >= 'a' && tekst[i] <= 'c')
        {
            tekst[i] = tekst[i] - 3 + 26;
        }
    }
    return tekst;
}

int main()
{
    string tekst;
    cout << "podaj napis: ";
    getline(cin, tekst);

    string zaszyfrowany = szyfrowanie(tekst);
    cout << zaszyfrowany << endl;
    cout << deszyfrowanie(zaszyfrowany) << endl;
    return 0;
}
