// ======================================================================
// isalpha isdigit isalnum isupper islower isspace ispunct tolower toupper
// Original file: Libraries/cctype.cpp
// ======================================================================

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    char litera = 'A';
    char cyfra = '5';
    char znak = '!';
    char spacja = ' ';

    // The is... functions return a number: non-zero = true, 0 = false.
    // Use them in if: if (isdigit(c)) { ... }
    cout << "Character functions demo:\n";
    cout << "isalpha('A'): " << (isalpha(litera) != 0) << " (is letter)\n";
    cout << "isdigit('5'): " << (isdigit(cyfra) != 0) << " (is digit)\n";
    cout << "isalnum('A'): " << (isalnum(litera) != 0) << " (is letter or digit)\n";
    cout << "isupper('A'): " << (isupper(litera) != 0) << " (is uppercase)\n";
    cout << "islower('A'): " << (islower(litera) != 0) << " (is lowercase)\n";
    cout << "isspace(' '): " << (isspace(spacja) != 0) << " (is space, tab, enter)\n";
    cout << "ispunct('!'): " << (ispunct(znak) != 0) << " (is punctuation)\n";

    // tolower / toupper return an int - store it in a char (or cast with (char))
    char mala = tolower(litera);
    char duza = toupper('a');
    cout << "tolower('A'): " << mala << "\n";
    cout << "toupper('a'): " << duza << "\n";

    // Typical use: count digits in a text
    string tekst = "Ala ma 2 koty i 13 rybek";
    int ileCyfr = 0;
    for (int i = 0; i < tekst.length(); i++)
    {
        if (isdigit(tekst[i]))
        {
            ileCyfr++;
        }
    }
    cout << "digits in \"" << tekst << "\": " << ileCyfr << "\n";

    return 0;
}
