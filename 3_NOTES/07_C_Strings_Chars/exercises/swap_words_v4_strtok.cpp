// ======================================================================
// cleanest swap version: strtok cuts off the first word and returns a pointer to it
// Original file: unsorted/Cstrings/nikodemst/1) Cstring wszystko/cstringSwap4.cpp
// ======================================================================

#include <iostream>
#include <cstring>
using namespace std;

const int DLUGOSC = 70;

int main()
{
    char wejscie1[DLUGOSC];
    char wejscie2[DLUGOSC];

    cout << "Podaj frazę dwuwyrazową: ";
    cin.getline(wejscie1, DLUGOSC);
    cout << "Podaj frazę dwuwyrazową, ponownie: ";
    cin.getline(wejscie2, DLUGOSC);

    cout << "wejscie:" << endl;
    cout << " " << wejscie1 << endl;
    cout << " " << wejscie2 << endl;

    // strtok puts '\0' in place of the first space -> wejscie1 now holds only the first word
    char *slowo1 = strtok(wejscie1, " ");
    char *slowo2 = strtok(wejscie2, " ");
    if (slowo1 == NULL || slowo2 == NULL)
    {
        cout << "Puste napisy." << endl;
        return 0;
    }

    int dlugosc1 = strlen(slowo1);
    int dlugosc2 = strlen(slowo2);

    char wyjscie1[2 * DLUGOSC] = "";
    char wyjscie2[2 * DLUGOSC] = "";

    // the second word starts right after the old space: index dlugosc + 1
    strcat(wyjscie1, slowo2);
    strcat(wyjscie1, " ");
    strcat(wyjscie1, &wejscie1[dlugosc1 + 1]);

    strcat(wyjscie2, slowo1);
    strcat(wyjscie2, " ");
    strcat(wyjscie2, &wejscie2[dlugosc2 + 1]);

    cout << "wyjscie:" << endl;
    cout << " " << wyjscie1 << endl;
    cout << " " << wyjscie2 << endl;

    return 0;
}
