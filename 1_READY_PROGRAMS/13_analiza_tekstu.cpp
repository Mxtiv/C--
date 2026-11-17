// ======================================================================
// READY PROGRAM 13: text analysis - length, words, vowels, consonants, digits,
// upper/lower case, palindrome, reversed, UPPER CASE, letter frequency, swap words
// Based on: unsorted/sprawdzian/stringpoprawa.cpp + unsorted/stringi/stringZadania.cpp
// Blocks used: IO-03, STR-03, STR-04, STR-05, STR-07, STR-10, STR-11, STR-01, STR-20, STR-22
// ======================================================================
//
// Treść zadania (wariant): Program pobiera tekst (cały wiersz, ze spacjami) i wyświetla:
// długość, liczbę słów, samogłosek, spółgłosek, cyfr, wielkich i małych liter,
// informację, czy tekst jest palindromem, tekst odwrócony i zapisany wielkimi literami
// oraz częstość występowania liter.

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

/********************************************************
 * nazwa funkcji: zliczSamogloski
 * opis funkcji: zlicza samogłoski (a, e, i, o, u, y) bez względu na wielkość liter
 * parametry: tekst - analizowany tekst
 * zwracany typ i opis: int - liczba samogłosek
 * autor: <numer zdającego>
 ********************************************************/
int zliczSamogloski(const string &tekst)
{
    const string samogloski = "aeiouy";
    int ile = 0;
    for (char c : tekst)
        if (samogloski.find(tolower(c)) != string::npos)
            ile++;
    return ile;
}

/********************************************************
 * nazwa funkcji: zliczSpolgloski
 * opis funkcji: zlicza spółgłoski (litery niebędące samogłoskami)
 * parametry: tekst - analizowany tekst
 * zwracany typ i opis: int - liczba spółgłosek
 * autor: <numer zdającego>
 ********************************************************/
int zliczSpolgloski(const string &tekst)
{
    const string samogloski = "aeiouy";
    int ile = 0;
    for (char c : tekst)
        if (isalpha(c) && samogloski.find(tolower(c)) == string::npos)
            ile++;
    return ile;
}

/********************************************************
 * nazwa funkcji: zliczSlowa
 * opis funkcji: zlicza słowa oddzielone białymi znakami
 * parametry: tekst - analizowany tekst
 * zwracany typ i opis: int - liczba słów
 * autor: <numer zdającego>
 ********************************************************/
int zliczSlowa(const string &tekst)
{
    istringstream strumien(tekst);
    string slowo;
    int ile = 0;
    while (strumien >> slowo)
        ile++;
    return ile;
}

/********************************************************
 * nazwa funkcji: czyPalindrom
 * opis funkcji: sprawdza, czy tekst czytany od tyłu jest taki sam (pomija spacje i wielkość liter)
 * parametry: tekst - sprawdzany tekst
 * zwracany typ i opis: bool - true, gdy tekst jest palindromem
 * autor: <numer zdającego>
 ********************************************************/
bool czyPalindrom(const string &tekst)
{
    string czysty;
    for (char c : tekst)
        if (c != ' ')
            czysty += tolower(c);
    int i = 0, j = (int)czysty.length() - 1;
    while (i < j)
        if (czysty[i++] != czysty[j--])
            return false;
    return true;
}

/********************************************************
 * nazwa funkcji: odwrocNapis
 * opis funkcji: zwraca tekst zapisany od końca
 * parametry: tekst - tekst wejściowy
 * zwracany typ i opis: string - odwrócony tekst
 * autor: <numer zdającego>
 ********************************************************/
string odwrocNapis(const string &tekst)
{
    return string(tekst.rbegin(), tekst.rend());
}

/********************************************************
 * nazwa funkcji: naWielkie
 * opis funkcji: zamienia wszystkie litery na wielkie
 * parametry: tekst - tekst wejściowy
 * zwracany typ i opis: string - tekst wielkimi literami
 * autor: <numer zdającego>
 ********************************************************/
string naWielkie(string tekst)
{
    for (char &c : tekst)
        c = toupper(c);
    return tekst;
}

/********************************************************
 * nazwa funkcji: czestoscLiter
 * opis funkcji: wyświetla, ile razy występuje każda litera a..z (pomija nieobecne)
 * parametry: tekst - analizowany tekst
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void czestoscLiter(const string &tekst)
{
    int licznik[26] = {0};
    for (char c : tekst)
        if (isalpha(c))
            licznik[tolower(c) - 'a']++;
    for (int i = 0; i < 26; i++)
        if (licznik[i] > 0)
            cout << (char)('a' + i) << ":" << licznik[i] << " ";
    cout << endl;
}

int main()
{
    string tekst;
    cout << "Podaj tekst: ";
    getline(cin, tekst);

    int cyfry = 0, wielkie = 0, male = 0;
    for (char c : tekst)
    {
        if (isdigit(c)) cyfry++;
        else if (isupper(c)) wielkie++;
        else if (islower(c)) male++;
    }

    cout << "Dlugosc tekstu:      " << tekst.length() << endl;
    cout << "Liczba slow:         " << zliczSlowa(tekst) << endl;
    cout << "Samogloski:          " << zliczSamogloski(tekst) << endl;
    cout << "Spolgloski:          " << zliczSpolgloski(tekst) << endl;
    cout << "Cyfry:               " << cyfry << endl;
    cout << "Wielkie / male:      " << wielkie << " / " << male << endl;
    cout << "Palindrom:           " << (czyPalindrom(tekst) ? "tak" : "nie") << endl;
    cout << "Tekst odwrocony:     " << odwrocNapis(tekst) << endl;
    cout << "Wielkimi literami:   " << naWielkie(tekst) << endl;
    cout << "Czestosc liter:      ";
    czestoscLiter(tekst);
    return 0;
}
