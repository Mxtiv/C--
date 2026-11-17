// ======================================================================
// BUILDING BLOCKS: strings (napisy, std::string) - case, counting, words, splitting,
// palindrome, reverse, replace, Caesar cipher, validation, initials, letter frequency
// HOW TO USE: copy the comment box + code under a //@ line, up to the next //@ line.
// ======================================================================

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>
using namespace std;

//@ STR-01 | text to UPPER case | <string> <cctype>
/********************************************************
 * nazwa funkcji: naWielkie
 * opis funkcji: zamienia wszystkie litery napisu na wielkie
 * parametry: tekst - napis do zamiany
 * zwracany typ i opis: string - napis wielkimi literami
 * autor: <numer zdającego>
 ********************************************************/
string naWielkie(string tekst)
{
    for (char &c : tekst)            // & -> modifies the characters of the copy
        c = toupper(c);
    return tekst;
}

//@ STR-02 | text to lower case | <string> <cctype>
/********************************************************
 * nazwa funkcji: naMale
 * opis funkcji: zamienia wszystkie litery napisu na małe
 * parametry: tekst - napis do zamiany
 * zwracany typ i opis: string - napis małymi literami
 * autor: <numer zdającego>
 ********************************************************/
string naMale(string tekst)
{
    for (char &c : tekst)
        c = tolower(c);
    return tekst;
}

//@ STR-03 | count vowels (a e i o u y, any case) | <string> <cctype>
/********************************************************
 * nazwa funkcji: zliczSamogloski
 * opis funkcji: zlicza samogłoski (a, e, i, o, u, y) w napisie, bez względu na wielkość liter
 * parametry: tekst - analizowany napis
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

//@ STR-04 | count consonants (letters that are not vowels) | <string> <cctype>
/********************************************************
 * nazwa funkcji: zliczSpolgloski
 * opis funkcji: zlicza spółgłoski w napisie (litery niebędące samogłoskami)
 * parametry: tekst - analizowany napis
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

//@ STR-05 | count digits in a text | <string> <cctype>
/********************************************************
 * nazwa funkcji: zliczCyfry
 * opis funkcji: zlicza cyfry występujące w napisie
 * parametry: tekst - analizowany napis
 * zwracany typ i opis: int - liczba cyfr
 * autor: <numer zdającego>
 ********************************************************/
int zliczCyfry(const string &tekst)
{
    int ile = 0;
    for (char c : tekst)
        if (isdigit(c))
            ile++;
    return ile;
}

//@ STR-06 | count occurrences of one character | <string>
/********************************************************
 * nazwa funkcji: zliczZnak
 * opis funkcji: zlicza wystąpienia podanego znaku w napisie
 * parametry: tekst - analizowany napis
 *            znak - zliczany znak
 * zwracany typ i opis: int - liczba wystąpień znaku
 * autor: <numer zdającego>
 ********************************************************/
int zliczZnak(const string &tekst, char znak)
{
    int ile = 0;
    for (char c : tekst)
        if (c == znak)
            ile++;
    return ile;
}

//@ STR-07 | count words (separated by spaces) | <string> <sstream>
/********************************************************
 * nazwa funkcji: zliczSlowa
 * opis funkcji: zlicza słowa w napisie (słowa oddzielone białymi znakami)
 * parametry: tekst - analizowany napis
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

//@ STR-08 | split a text into words -> vector<string> | <string> <vector> <sstream>
/********************************************************
 * nazwa funkcji: podzielNaSlowa
 * opis funkcji: dzieli napis na słowa oddzielone białymi znakami
 * parametry: tekst - napis do podziału
 * zwracany typ i opis: vector<string> - kolejne słowa
 * autor: <numer zdającego>
 ********************************************************/
vector<string> podzielNaSlowa(const string &tekst)
{
    vector<string> slowa;
    istringstream strumien(tekst);
    string slowo;
    while (strumien >> slowo)
        slowa.push_back(slowo);
    return slowa;
}

//@ STR-09 | split by a separator, e.g. "Jan;17;4.5" by ';' -> vector<string> | <string> <vector> <sstream>
/********************************************************
 * nazwa funkcji: podzielWgSeparatora
 * opis funkcji: dzieli napis na części oddzielone podanym znakiem
 * parametry: tekst - napis do podziału
 *            separator - znak oddzielający części
 * zwracany typ i opis: vector<string> - kolejne części napisu
 * autor: <numer zdającego>
 ********************************************************/
vector<string> podzielWgSeparatora(const string &tekst, char separator)
{
    vector<string> czesci;
    stringstream strumien(tekst);
    string czesc;
    while (getline(strumien, czesc, separator))
        czesci.push_back(czesc);
    return czesci;
}

//@ STR-10 | reverse a text | <string>
/********************************************************
 * nazwa funkcji: odwrocNapis
 * opis funkcji: zwraca napis zapisany od końca
 * parametry: tekst - napis do odwrócenia
 * zwracany typ i opis: string - odwrócony napis
 * autor: <numer zdającego>
 ********************************************************/
string odwrocNapis(const string &tekst)
{
    string wynik;
    for (int i = tekst.length() - 1; i >= 0; i--)
        wynik += tekst[i];
    return wynik;
}

//@ STR-11 | palindrome check, ignoring spaces and letter case ("Kobyla ma maly bok") | <string> <cctype>
/********************************************************
 * nazwa funkcji: czyPalindrom
 * opis funkcji: sprawdza, czy napis czytany od tyłu jest taki sam
 *               (pomija spacje i wielkość liter)
 * parametry: tekst - sprawdzany napis
 * zwracany typ i opis: bool - true, gdy napis jest palindromem
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
    {
        if (czysty[i] != czysty[j]) return false;
        i++;
        j--;
    }
    return true;
}

//@ STR-12 | remove all spaces | <string>
/********************************************************
 * nazwa funkcji: usunSpacje
 * opis funkcji: usuwa wszystkie spacje z napisu
 * parametry: tekst - napis wejściowy
 * zwracany typ i opis: string - napis bez spacji
 * autor: <numer zdającego>
 ********************************************************/
string usunSpacje(const string &tekst)
{
    string wynik;
    for (char c : tekst)
        if (c != ' ')
            wynik += c;
    return wynik;
}

//@ STR-13 | replace ALL occurrences of a fragment with another | <string>
/********************************************************
 * nazwa funkcji: zamienWszystkie
 * opis funkcji: zamienia wszystkie wystąpienia fragmentu na inny fragment
 * parametry: tekst - napis wejściowy
 *            co - szukany fragment
 *            naCo - fragment wstawiany w miejsce znalezionego
 * zwracany typ i opis: string - napis po zamianie
 * autor: <numer zdającego>
 ********************************************************/
string zamienWszystkie(string tekst, const string &co, const string &naCo)
{
    if (co.empty()) return tekst;
    size_t pozycja = tekst.find(co);
    while (pozycja != string::npos)
    {
        tekst.replace(pozycja, co.length(), naCo);
        pozycja = tekst.find(co, pozycja + naCo.length());
    }
    return tekst;
}

//@ STR-14 | Caesar cipher with any key (keeps case, other chars unchanged); decrypt = key 26 - k | <string>
/********************************************************
 * nazwa funkcji: szyfrujCezarem
 * opis funkcji: szyfruje napis szyfrem Cezara - każda litera jest przesuwana w alfabecie
 *               o klucz pozycji (z zawinięciem z 'z' na 'a'); inne znaki bez zmian
 * parametry: tekst - napis do zaszyfrowania
 *            klucz - przesunięcie (może być ujemne)
 * zwracany typ i opis: string - zaszyfrowany napis
 * autor: <numer zdającego>
 ********************************************************/
string szyfrujCezarem(string tekst, int klucz)
{
    klucz = ((klucz % 26) + 26) % 26;          // any key -> 0..25
    for (char &c : tekst)
    {
        if (c >= 'a' && c <= 'z')
            c = 'a' + (c - 'a' + klucz) % 26;
        else if (c >= 'A' && c <= 'Z')
            c = 'A' + (c - 'A' + klucz) % 26;
    }
    return tekst;
}

//@ STR-15 | Caesar decrypt (needs STR-14) | <string>
/********************************************************
 * nazwa funkcji: deszyfrujCezarem
 * opis funkcji: odszyfrowuje napis zaszyfrowany szyfrem Cezara z podanym kluczem
 * parametry: tekst - zaszyfrowany napis
 *            klucz - klucz użyty do szyfrowania
 * zwracany typ i opis: string - odszyfrowany napis
 * autor: <numer zdającego>
 ********************************************************/
string deszyfrujCezarem(const string &tekst, int klucz)
{
    return szyfrujCezarem(tekst, -klucz);
}

//@ STR-16 | is the text a whole number ("123", "-45")? - check BEFORE stoi | <string> <cctype>
/********************************************************
 * nazwa funkcji: czyLiczbaCalkowita
 * opis funkcji: sprawdza, czy napis zawiera wyłącznie liczbę całkowitą (opcjonalnie z minusem)
 * parametry: tekst - sprawdzany napis
 * zwracany typ i opis: bool - true, gdy napis jest liczbą całkowitą
 * autor: <numer zdającego>
 ********************************************************/
bool czyLiczbaCalkowita(const string &tekst)
{
    if (tekst.empty()) return false;
    size_t start = (tekst[0] == '-') ? 1 : 0;
    if (start == tekst.length()) return false;
    for (size_t i = start; i < tekst.length(); i++)
        if (!isdigit(tekst[i]))
            return false;
    return true;
}

//@ STR-17 | capitalize every word: "jan kowalski" -> "Jan Kowalski" | <string> <cctype>
/********************************************************
 * nazwa funkcji: kazdeSlowoWielka
 * opis funkcji: zamienia pierwszą literę każdego słowa na wielką, a pozostałe na małe
 * parametry: tekst - napis wejściowy
 * zwracany typ i opis: string - napis z wielkimi pierwszymi literami słów
 * autor: <numer zdającego>
 ********************************************************/
string kazdeSlowoWielka(string tekst)
{
    bool poczatekSlowa = true;
    for (char &c : tekst)
    {
        if (c == ' ')
            poczatekSlowa = true;
        else
        {
            c = poczatekSlowa ? toupper(c) : tolower(c);
            poczatekSlowa = false;
        }
    }
    return tekst;
}

//@ STR-18 | initials: "Jan Maria Rokita" -> "JMR" | <string> <sstream> <cctype>
/********************************************************
 * nazwa funkcji: inicjaly
 * opis funkcji: tworzy inicjały z pierwszych liter kolejnych słów
 * parametry: tekst - imiona i nazwisko
 * zwracany typ i opis: string - inicjały wielkimi literami
 * autor: <numer zdającego>
 ********************************************************/
string inicjaly(const string &tekst)
{
    istringstream strumien(tekst);
    string slowo, wynik;
    while (strumien >> slowo)
        wynik += toupper(slowo[0]);
    return wynik;
}

//@ STR-19 | swap the two words of a 2-word text: "Jan Kowalski" -> "Kowalski Jan" | <string>
/********************************************************
 * nazwa funkcji: zamienSlowa
 * opis funkcji: zamienia miejscami pierwszy i drugi człon napisu dwuczłonowego
 * parametry: tekst - napis złożony z dwóch słów oddzielonych spacją
 * zwracany typ i opis: string - napis z zamienionymi członami (bez zmian, gdy brak spacji)
 * autor: <numer zdającego>
 ********************************************************/
string zamienSlowa(const string &tekst)
{
    size_t spacja = tekst.find(' ');
    if (spacja == string::npos) return tekst;
    return tekst.substr(spacja + 1) + " " + tekst.substr(0, spacja);
}

//@ STR-20 | frequency of each letter a..z (prints only the letters that occur) | <iostream> <string> <cctype>
/********************************************************
 * nazwa funkcji: czestoscLiter
 * opis funkcji: zlicza i wyświetla, ile razy każda litera a..z występuje w napisie
 * parametry: tekst - analizowany napis
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
            cout << (char)('a' + i) << ": " << licznik[i] << endl;
}

//@ STR-21 | anagram check (same letters, other order: "listen" / "silent") | <string> <algorithm>
/********************************************************
 * nazwa funkcji: czyAnagram
 * opis funkcji: sprawdza, czy dwa napisy składają się z tych samych znaków
 * parametry: a - pierwszy napis
 *            b - drugi napis
 * zwracany typ i opis: bool - true, gdy napisy są anagramami
 * autor: <numer zdającego>
 ********************************************************/
bool czyAnagram(string a, string b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

//@ STR-22 | count upper and lower case letters (results through & parameters) | <string> <cctype>
/********************************************************
 * nazwa funkcji: zliczWielkieIMale
 * opis funkcji: zlicza wielkie i małe litery w napisie
 * parametry: tekst - analizowany napis
 *            wielkie - (wyjście) liczba wielkich liter
 *            male - (wyjście) liczba małych liter
 * zwracany typ i opis: brak (wyniki przez parametry referencyjne)
 * autor: <numer zdającego>
 ********************************************************/
void zliczWielkieIMale(const string &tekst, int &wielkie, int &male)
{
    wielkie = male = 0;
    for (char c : tekst)
    {
        if (isupper(c)) wielkie++;
        else if (islower(c)) male++;
    }
}

// ====================== DEMO (don't copy) ======================
int main()
{
    string t = "Kobyla ma maly bok 2024";
    cout << naWielkie(t) << " | " << naMale(t) << endl;
    cout << "samogloski " << zliczSamogloski(t) << ", spolgloski " << zliczSpolgloski(t)
         << ", cyfry " << zliczCyfry(t) << ", 'a' " << zliczZnak(t, 'a') << ", slowa " << zliczSlowa(t) << endl;
    for (const string &s : podzielNaSlowa(t)) cout << "[" << s << "]";
    cout << endl;
    for (const string &s : podzielWgSeparatora("Jan;17;4.5", ';')) cout << "[" << s << "]";
    cout << endl << odwrocNapis("C++ rocks") << " | palindrom? " << boolalpha << czyPalindrom("Kobyla ma maly bok")
         << " | " << usunSpacje(t) << endl;
    cout << zamienWszystkie("ala ma kota, ala ma psa", "ala", "ola") << endl;
    string szyfr = szyfrujCezarem("Ala ma Kota xyz", 3);
    cout << szyfr << " -> " << deszyfrujCezarem(szyfr, 3) << endl;
    cout << "czyLiczba(\"-45\") " << czyLiczbaCalkowita("-45") << ", (\"4a\") " << czyLiczbaCalkowita("4a") << endl;
    cout << kazdeSlowoWielka("jAN kowALSKI") << " | " << inicjaly("jan maria rokita") << " | " << zamienSlowa("Jan Kowalski") << endl;
    czestoscLiter("Abba");
    int w, m;
    zliczWielkieIMale("Ala Ma KOTA", w, m);
    cout << "anagram? " << czyAnagram("listen", "silent") << ", wielkie " << w << ", male " << m << endl;
    return 0;
}
