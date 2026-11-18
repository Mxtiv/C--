// ======================================================================
// (int)char = ASCII code, shift a letter and wrap around the alphabet
// Original file: unsorted/sprawdzian/stringAscii.cpp
// FIXED: the new code was computed before the letter was validated (a re-entered letter was ignored)
// ======================================================================

#include <iostream>
using namespace std;

int main()
{
    char litera;
    do
    {
        cout << "Enter a letter: ";
        cin >> litera;
    } while (!((litera >= 'A' && litera <= 'Z') || (litera >= 'a' && litera <= 'z')));

    int kod = (int)litera;      // 'A' = 65 ... 'Z' = 90, 'a' = 97 ... 'z' = 122
    cout << "ASCII code of '" << litera << "' is: " << kod << endl;

    int cyfra;
    do
    {
        cout << "Enter a digit (0-9): ";
        cin >> cyfra;
    } while (cyfra < 0 || cyfra > 9);

    int nowyKod = kod + cyfra;
    // past 'Z' or past 'z' -> go back to the start of the alphabet
    if ((litera <= 'Z' && nowyKod > 'Z') || (litera >= 'a' && nowyKod > 'z'))
    {
        nowyKod = nowyKod - 26;
    }

    char nowaLitera = (char)nowyKod;
    cout << "After adding " << cyfra << ", the new letter is: " << nowaLitera << endl;

    return 0;
}
