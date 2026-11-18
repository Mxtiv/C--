// ======================================================================
// READY PROGRAM 13: text analysis - length, words, vowels, consonants, digits,
// upper/lower case, palindrome, reversed, UPPER CASE, letter frequency
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
#include <cctype>
using namespace std;

/********************************************************
 * nazwa funkcji: czySamogloska
 * opis funkcji: sprawdza, czy znak jest samogłoską (a, e, i, o, u, y), bez względu
 *               na wielkość liter
 * parametry: znak - sprawdzany znak
 * zwracany typ i opis: bool - true, gdy znak jest samogłoską
 * autor: <numer zdającego>
 ********************************************************/
bool czySamogloska(char znak)
{
    znak = tolower(znak);
    if (znak == 'a' || znak == 'e' || znak == 'i' || znak == 'o' || znak == 'u' || znak == 'y')
    {
        return true;
    }
    return false;
}

/********************************************************
 * nazwa funkcji: zliczSamogloski
 * opis funkcji: zlicza samogłoski (a, e, i, o, u, y) bez względu na wielkość liter
 * parametry: tekst - analizowany tekst
 * zwracany typ i opis: int - liczba samogłosek
 * autor: <numer zdającego>
 ********************************************************/
int zliczSamogloski(string tekst)
{
    int ile = 0;
    int dlugosc = tekst.length();
    for (int i = 0; i < dlugosc; i++)
    {
        if (czySamogloska(tekst[i]))
        {
            ile++;
        }
    }
    return ile;
}

/********************************************************
 * nazwa funkcji: zliczSpolgloski
 * opis funkcji: zlicza spółgłoski (litery niebędące samogłoskami)
 * parametry: tekst - analizowany tekst
 * zwracany typ i opis: int - liczba spółgłosek
 * autor: <numer zdającego>
 ********************************************************/
int zliczSpolgloski(string tekst)
{
    int ile = 0;
    int dlugosc = tekst.length();
    for (int i = 0; i < dlugosc; i++)
    {
        if (isalpha(tekst[i]) && !czySamogloska(tekst[i]))
        {
            ile++;
        }
    }
    return ile;
}

/********************************************************
 * nazwa funkcji: zliczSlowa
 * opis funkcji: zlicza słowa oddzielone spacjami - nowe słowo zaczyna się tam,
 *               gdzie po spacji (albo na początku tekstu) stoi znak inny niż spacja
 * parametry: tekst - analizowany tekst
 * zwracany typ i opis: int - liczba słów
 * autor: <numer zdającego>
 ********************************************************/
int zliczSlowa(string tekst)
{
    int ile = 0;
    int dlugosc = tekst.length();
    for (int i = 0; i < dlugosc; i++)
    {
        if (tekst[i] != ' ' && (i == 0 || tekst[i - 1] == ' '))
        {
            ile++;
        }
    }
    return ile;
}

/********************************************************
 * nazwa funkcji: czyPalindrom
 * opis funkcji: sprawdza, czy tekst czytany od tyłu jest taki sam (pomija spacje i wielkość liter)
 * parametry: tekst - sprawdzany tekst
 * zwracany typ i opis: bool - true, gdy tekst jest palindromem
 * autor: <numer zdającego>
 ********************************************************/
bool czyPalindrom(string tekst)
{
    string czysty = "";
    int dlugosc = tekst.length();
    for (int i = 0; i < dlugosc; i++)
    {
        if (tekst[i] != ' ')
        {
            czysty = czysty + (char)tolower(tekst[i]);
        }
    }

    int dlugoscCzystego = czysty.length();
    for (int i = 0; i < dlugoscCzystego / 2; i++)
    {
        if (czysty[i] != czysty[dlugoscCzystego - 1 - i])
        {
            return false;
        }
    }
    return true;
}

/********************************************************
 * nazwa funkcji: odwrocNapis
 * opis funkcji: zwraca tekst zapisany od końca
 * parametry: tekst - tekst wejściowy
 * zwracany typ i opis: string - odwrócony tekst
 * autor: <numer zdającego>
 ********************************************************/
string odwrocNapis(string tekst)
{
    string wynik = "";
    int dlugosc = tekst.length();
    for (int i = dlugosc - 1; i >= 0; i--)
    {
        wynik = wynik + tekst[i];
    }
    return wynik;
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
    int dlugosc = tekst.length();
    for (int i = 0; i < dlugosc; i++)
    {
        tekst[i] = toupper(tekst[i]);
    }
    return tekst;
}

/********************************************************
 * nazwa funkcji: czestoscLiter
 * opis funkcji: wyświetla, ile razy występuje każda litera a..z (pomija nieobecne)
 * parametry: tekst - analizowany tekst
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void czestoscLiter(string tekst)
{
    int licznik[26];
    for (int i = 0; i < 26; i++)
    {
        licznik[i] = 0;
    }

    int dlugosc = tekst.length();
    for (int i = 0; i < dlugosc; i++)
    {
        char znak = tolower(tekst[i]);
        if (znak >= 'a' && znak <= 'z')
        {
            licznik[znak - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (licznik[i] > 0)
        {
            cout << (char)('a' + i) << ":" << licznik[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    string tekst;
    cout << "Podaj tekst: ";
    getline(cin, tekst);

    int cyfry = 0;
    int wielkie = 0;
    int male = 0;
    int dlugosc = tekst.length();
    for (int i = 0; i < dlugosc; i++)
    {
        if (isdigit(tekst[i]))
        {
            cyfry++;
        }
        else if (isupper(tekst[i]))
        {
            wielkie++;
        }
        else if (islower(tekst[i]))
        {
            male++;
        }
    }

    cout << "Dlugosc tekstu:      " << dlugosc << endl;
    cout << "Liczba slow:         " << zliczSlowa(tekst) << endl;
    cout << "Samogloski:          " << zliczSamogloski(tekst) << endl;
    cout << "Spolgloski:          " << zliczSpolgloski(tekst) << endl;
    cout << "Cyfry:               " << cyfry << endl;
    cout << "Wielkie / male:      " << wielkie << " / " << male << endl;
    if (czyPalindrom(tekst))
    {
        cout << "Palindrom:           tak" << endl;
    }
    else
    {
        cout << "Palindrom:           nie" << endl;
    }
    cout << "Tekst odwrocony:     " << odwrocNapis(tekst) << endl;
    cout << "Wielkimi literami:   " << naWielkie(tekst) << endl;
    cout << "Czestosc liter:      ";
    czestoscLiter(tekst);
    return 0;
}
