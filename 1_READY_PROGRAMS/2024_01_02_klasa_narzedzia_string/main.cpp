// ======================================================================
// INF.04-02-24.01-SG (and 24.01-02-AG, 24.06-01-SD) - klasa narzędziowa dla napisów:
// metody STATYCZNE i publiczne: liczba samogłosek "aąeęiouóyAĄEĘIOUÓY" oraz usuwanie
// powtórzeń znaków stojących obok siebie ("Abba;;;to" -> "Aba;to").
// Polish letters (ą, ę, ó) need WIDE strings on Windows: wstring + wcin/wcout in UTF-16 mode.
// This file is saved as UTF-8 WITH BOM (Visual Studio then reads L"ą" correctly).
// Spec + key checklist: README.md in this folder.
// ======================================================================
#include <iostream>
#include <string>
#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif
#include <clocale>
using namespace std;

/************************************************
   klasa: NarzedziaNapisow
   opis: biblioteka narzędziowa (tylko metody statyczne) do przetwarzania napisów
   metody: liczSamogloski - zwraca liczbę samogłosek w napisie (int)
           usunPowtorzenia - zwraca napis bez powtórzeń sąsiednich znaków (wstring)
   autor: 00000000000
************************************************/
class NarzedziaNapisow
{
public:
    static int liczSamogloski(const wchar_t *tekst)
    {
        if (tekst == nullptr || tekst[0] == L'\0')     // null lub pusty napis -> 0
        {
            return 0;
        }
        wstring samogloski = L"aąeęiouóyAĄEĘIOUÓY";
        int licznik = 0;
        for (int i = 0; tekst[i] != L'\0'; i++)
        {
            if (samogloski.find(tekst[i]) != wstring::npos)
            {
                licznik++;
            }
        }
        return licznik;
    }

    static wstring usunPowtorzenia(const wchar_t *tekst)
    {
        if (tekst == nullptr || tekst[0] == L'\0')     // null lub pusty napis -> pusty napis
        {
            return L"";
        }
        wstring wynik = L"";
        for (int i = 0; tekst[i] != L'\0'; i++)
        {
            if (tekst[i + 1] != tekst[i])              // następny znak inny -> zostaw ten znak
            {
                wynik += tekst[i];
            }
        }
        return wynik;
    }
};

int main()
{
#ifdef _WIN32
    if (_isatty(_fileno(stdin)) && _isatty(_fileno(stdout)))
    {
        _setmode(_fileno(stdout), _O_U16TEXT);   // console window: Polish letters in and out
        _setmode(_fileno(stdin), _O_U16TEXT);
    }
    else
    {
        setlocale(LC_ALL, ".UTF-8");            // redirected (pipe / file): UTF-8 text
    }
#else
    setlocale(LC_ALL, "");
#endif
    wstring tekst;
    wcout << L"Podaj tekst: ";
    getline(wcin, tekst);

    wcout << L"Liczba samoglosek: " << NarzedziaNapisow::liczSamogloski(tekst.c_str()) << endl;
    wcout << L"Tekst bez powtorzen: " << NarzedziaNapisow::usunPowtorzenia(tekst.c_str()) << endl;
    wcout << L"Test null: " << NarzedziaNapisow::liczSamogloski(nullptr) << L" samoglosek, \""
          << NarzedziaNapisow::usunPowtorzenia(nullptr) << L"\"" << endl;
    return 0;
}
