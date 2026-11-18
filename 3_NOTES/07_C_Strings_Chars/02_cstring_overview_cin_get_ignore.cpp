// ======================================================================
// char[] init, cin >>, cin.ignore(n,'\n'), cin.get(buf,n) with spaces,
// strcpy strlen strcmp strcat strstr (Polish comments)
// Original file: unsorted/Cstrings/nikodemst/1) Cstring wszystko/main.cpp
// ======================================================================

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char wersja1[30] = "C++98";          // C-napis = tablica znaków zakończona '\0' (miejsce na '\0' też się liczy!)
    cout << wersja1 << endl;             // wypisze się napis, a nie adres napisu

    cout << "Podaj inną wersję, np. C++17: ";
    cin >> wersja1;                      // cin >> czyta jedno słowo (do spacji)
    cout << wersja1 << endl << endl;

    char wersja2[30];
    cout << "Podaj wersję C#, np. 8.0: ";
    cin >> wersja2;
    cout << wersja2 << endl;

    char wersja3[30];
    cout << "\nPodaj alternatywną nazwę Visual C++ 2015 (Visual C++ 14.0): ";
    cin.ignore(50, '\n');                // cin.ignore(ile znaków pominąć, na jakim znaku skończyć) - usuwa Enter po cin >>
    cin.get(wersja3, 30);                // cin.get pobiera napis RAZEM ze spacjami (max 29 znaków + '\0')
    cout << wersja3 << endl << endl;

    strcpy(wersja1, wersja2);            // kopiuje wersja2 do wersja1: strcpy(do czego, co)
    cout << "po strcpy: " << wersja1 << " " << wersja2 << endl;

    cout << "strlen(wersja1) = " << strlen(wersja1) << endl;     // liczba znaków (bez '\0')

    // strcmp: 0 gdy napisy są identyczne, < 0 gdy pierwszy jest wcześniej w alfabecie, > 0 gdy później
    if (strcmp(wersja1, wersja2) == 0)
    {
        cout << "wersja1 i wersja2 są takie same" << endl;
    }

    strcat(wersja1, "+");                // dopisuje napis na koniec wersja1 (musi się zmieścić!)
    cout << "po strcat: " << wersja1 << endl;

    // strstr zwraca wskaźnik na pierwsze wystąpienie albo NULL, gdy nie ma
    if (strstr(wersja3, "C++") != NULL)
    {
        cout << "\"C++\" jest w napisie wersja3, pozycja: " << strstr(wersja3, "C++") - wersja3 << endl;
    }
    else
    {
        cout << "\"C++\" nie występuje w napisie wersja3" << endl;
    }

    return 0;
}
