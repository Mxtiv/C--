// ======================================================================
// INF.04-01-26.06-SG - generator bezpiecznych haseł (12 znaków): 3 małe, 3 wielkie,
// 2 polskie litery (znaki.txt), 2 cyfry, 2 znaki specjalne !@#$%^&*()_+ - każdy znak
// w LOSOWYM miejscu hasła (tu: losowa wolna pozycja). Bez gotowych generatorów haseł.
// Polish letters need WIDE strings: wstring + wcout in UTF-16 mode (file saved as UTF-8 WITH BOM).
// Spec + key checklist: README.md in this folder.
// ======================================================================
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <clocale>
#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif
using namespace std;

// wstawia ile losowych znaków z zestawu w losowe WOLNE miejsca hasła ('?' = wolne)
void wstawLosowo(wstring &haslo, const wstring &zestaw, int ile)
{
    for (int i = 0; i < ile; i++)
    {
        int pozycja;
        do
        {
            pozycja = rand() % haslo.size();
        } while (haslo[pozycja] != L'?');
        haslo[pozycja] = zestaw[rand() % zestaw.size()];
    }
}

/*
nazwa funkcji:        generujHaslo
opis funkcji:         tworzy 12-znakowe hasło z 3 małych liter, 3 wielkich liter, 2 polskich
                      liter, 2 cyfr i 2 znaków specjalnych umieszczonych w losowych miejscach
parametry:            brak
zwracany typ i opis:  wstring - wygenerowane hasło
autor:                00000000000
*/
wstring generujHaslo()
{
    wstring haslo(12, L'?');
    wstawLosowo(haslo, L"abcdefghijklmnopqrstuvwxyz", 3);
    wstawLosowo(haslo, L"ABCDEFGHIJKLMNOPQRSTUVWXYZ", 3);
    wstawLosowo(haslo, L"ąęłńóśżźĄĘŁŃÓŚŻŹ", 2);          // zbiór z pliku znaki.txt
    wstawLosowo(haslo, L"0123456789", 2);
    wstawLosowo(haslo, L"!@#$%^&*()_+", 2);
    return haslo;
}

int main()
{
#ifdef _WIN32
    if (_isatty(_fileno(stdout)))
    {
        _setmode(_fileno(stdout), _O_U16TEXT);   // console window: Polish letters
    }
    else
    {
        setlocale(LC_ALL, ".UTF-8");            // redirected output: UTF-8
    }
#else
    setlocale(LC_ALL, "");
#endif
    srand((unsigned)time(0));
    wcout << L"Wygenerowane bezpieczne hasla:" << endl;
    for (int i = 1; i <= 5; i++)
    {
        wstring haslo = generujHaslo();
        wcout << L"Haslo " << i << L": " << haslo << endl;
    }
    return 0;
}
