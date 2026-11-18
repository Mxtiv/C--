// ======================================================================
// BUILDING BLOCKS: strings (napisy, std::string) - case, counting, words, splitting,
// palindrome, reverse, replace, Caesar cipher, validation, initials, letter frequency
// HOW TO USE: copy the comment box + code under a //@ line, up to the next //@ line.
// Every block walks the string character by character: tekst[i], i = 0 .. tekst.length() - 1
// ======================================================================

#include <iostream>
#include <string>
#include <cctype>
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
    for (int i = 0; i < tekst.length(); i++)
    {
        tekst[i] = toupper(tekst[i]);
    }
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
    for (int i = 0; i < tekst.length(); i++)
    {
        tekst[i] = tolower(tekst[i]);
    }
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
int zliczSamogloski(string tekst)
{
    int ile = 0;
    for (int i = 0; i < tekst.length(); i++)
    {
        char znak = tolower(tekst[i]);
        if (znak == 'a' || znak == 'e' || znak == 'i' || znak == 'o' || znak == 'u' || znak == 'y')
        {
            ile++;
        }
    }
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
int zliczSpolgloski(string tekst)
{
    int ile = 0;
    for (int i = 0; i < tekst.length(); i++)
    {
        char znak = tolower(tekst[i]);
        if (znak >= 'a' && znak <= 'z')
        {
            if (znak != 'a' && znak != 'e' && znak != 'i' && znak != 'o' && znak != 'u' && znak != 'y')
            {
                ile++;
            }
        }
    }
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
int zliczCyfry(string tekst)
{
    int ile = 0;
    for (int i = 0; i < tekst.length(); i++)
    {
        if (isdigit(tekst[i]))
        {
            ile++;
        }
    }
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
int zliczZnak(string tekst, char znak)
{
    int ile = 0;
    for (int i = 0; i < tekst.length(); i++)
    {
        if (tekst[i] == znak)
        {
            ile++;
        }
    }
    return ile;
}

//@ STR-07 | count words separated by spaces (counts where a word starts) | <string>
/********************************************************
 * nazwa funkcji: zliczSlowa
 * opis funkcji: zlicza słowa w napisie (słowa oddzielone spacjami); słowo zaczyna się
 *               tam, gdzie znak nie jest spacją, a poprzedni znak jest spacją lub go nie ma
 * parametry: tekst - analizowany napis
 * zwracany typ i opis: int - liczba słów
 * autor: <numer zdającego>
 ********************************************************/
int zliczSlowa(string tekst)
{
    int ile = 0;
    for (int i = 0; i < tekst.length(); i++)
    {
        if (tekst[i] != ' ' && (i == 0 || tekst[i - 1] == ' '))
        {
            ile++;
        }
    }
    return ile;
}

//@ STR-08 | split a text into words -> string slowa[] array, returns how many | <string>
/********************************************************
 * nazwa funkcji: podzielNaSlowa
 * opis funkcji: dzieli napis na słowa oddzielone spacjami i zapisuje je do tablicy
 * parametry: tekst - napis do podziału
 *            slowa - tablica na słowa (musi być dość duża, np. string slowa[100])
 * zwracany typ i opis: int - liczba słów zapisanych w tablicy
 * autor: <numer zdającego>
 ********************************************************/
int podzielNaSlowa(string tekst, string slowa[])
{
    int ile = 0;
    string slowo = "";
    for (int i = 0; i < tekst.length(); i++)
    {
        if (tekst[i] == ' ')
        {
            if (slowo != "")
            {
                slowa[ile] = slowo;
                ile++;
                slowo = "";
            }
        }
        else
        {
            slowo += tekst[i];
        }
    }
    if (slowo != "")                 // the last word has no space after it
    {
        slowa[ile] = slowo;
        ile++;
    }
    return ile;
}

//@ STR-09 | split by a separator, e.g. "Jan;17;4.5" by ';' -> string czesci[] array, returns how many | <string>
/********************************************************
 * nazwa funkcji: podzielWgSeparatora
 * opis funkcji: dzieli napis na części oddzielone podanym znakiem i zapisuje je do tablicy
 * parametry: tekst - napis do podziału
 *            separator - znak oddzielający części
 *            czesci - tablica na części (musi być dość duża, np. string czesci[20])
 * zwracany typ i opis: int - liczba części zapisanych w tablicy
 * autor: <numer zdającego>
 ********************************************************/
int podzielWgSeparatora(string tekst, char separator, string czesci[])
{
    int ile = 0;
    string czesc = "";
    for (int i = 0; i < tekst.length(); i++)
    {
        if (tekst[i] == separator)
        {
            czesci[ile] = czesc;
            ile++;
            czesc = "";
        }
        else
        {
            czesc += tekst[i];
        }
    }
    czesci[ile] = czesc;             // the last part
    ile++;
    return ile;
}

//@ STR-10 | reverse a text | <string>
/********************************************************
 * nazwa funkcji: odwrocNapis
 * opis funkcji: zwraca napis zapisany od końca
 * parametry: tekst - napis do odwrócenia
 * zwracany typ i opis: string - odwrócony napis
 * autor: <numer zdającego>
 ********************************************************/
string odwrocNapis(string tekst)
{
    string wynik = "";
    for (int i = tekst.length() - 1; i >= 0; i--)
    {
        wynik += tekst[i];
    }
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
bool czyPalindrom(string tekst)
{
    string czysty = "";
    for (int i = 0; i < tekst.length(); i++)
    {
        if (tekst[i] != ' ')
        {
            czysty += tolower(tekst[i]);
        }
    }
    int dlugosc = czysty.length();
    for (int i = 0; i < dlugosc / 2; i++)
    {
        if (czysty[i] != czysty[dlugosc - 1 - i])
        {
            return false;
        }
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
string usunSpacje(string tekst)
{
    string wynik = "";
    for (int i = 0; i < tekst.length(); i++)
    {
        if (tekst[i] != ' ')
        {
            wynik += tekst[i];
        }
    }
    return wynik;
}

//@ STR-13 | replace ALL occurrences of a fragment with another (walks the text, compares with substr) | <string>
/********************************************************
 * nazwa funkcji: zamienWszystkie
 * opis funkcji: zamienia wszystkie wystąpienia fragmentu na inny fragment
 * parametry: tekst - napis wejściowy
 *            co - szukany fragment (niepusty)
 *            naCo - fragment wstawiany w miejsce znalezionego
 * zwracany typ i opis: string - napis po zamianie
 * autor: <numer zdającego>
 ********************************************************/
string zamienWszystkie(string tekst, string co, string naCo)
{
    string wynik = "";
    int i = 0;
    while (i < tekst.length())
    {
        if (tekst.substr(i, co.length()) == co)
        {
            wynik += naCo;
            i = i + co.length();     // jump over the found fragment
        }
        else
        {
            wynik += tekst[i];
            i++;
        }
    }
    return wynik;
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
    klucz = klucz % 26;              // any key -> -25..25
    if (klucz < 0)
    {
        klucz = klucz + 26;          // -> 0..25
    }
    for (int i = 0; i < tekst.length(); i++)
    {
        if (tekst[i] >= 'a' && tekst[i] <= 'z')
        {
            tekst[i] = 'a' + (tekst[i] - 'a' + klucz) % 26;
        }
        else if (tekst[i] >= 'A' && tekst[i] <= 'Z')
        {
            tekst[i] = 'A' + (tekst[i] - 'A' + klucz) % 26;
        }
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
string deszyfrujCezarem(string tekst, int klucz)
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
bool czyLiczbaCalkowita(string tekst)
{
    int start = 0;
    if (tekst.length() > 0 && tekst[0] == '-')
    {
        start = 1;                   // skip the minus
    }
    if (start == tekst.length())
    {
        return false;                // "" or just "-"
    }
    for (int i = start; i < tekst.length(); i++)
    {
        if (!isdigit(tekst[i]))
        {
            return false;
        }
    }
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
    for (int i = 0; i < tekst.length(); i++)
    {
        if (i == 0 || tekst[i - 1] == ' ')
        {
            tekst[i] = toupper(tekst[i]);
        }
        else
        {
            tekst[i] = tolower(tekst[i]);
        }
    }
    return tekst;
}

//@ STR-18 | initials: "Jan Maria Rokita" -> "JMR" | <string> <cctype>
/********************************************************
 * nazwa funkcji: inicjaly
 * opis funkcji: tworzy inicjały z pierwszych liter kolejnych słów
 * parametry: tekst - imiona i nazwisko
 * zwracany typ i opis: string - inicjały wielkimi literami
 * autor: <numer zdającego>
 ********************************************************/
string inicjaly(string tekst)
{
    string wynik = "";
    for (int i = 0; i < tekst.length(); i++)
    {
        if (tekst[i] != ' ' && (i == 0 || tekst[i - 1] == ' '))     // first letter of a word
        {
            wynik += toupper(tekst[i]);
        }
    }
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
string zamienSlowa(string tekst)
{
    int spacja = -1;
    for (int i = 0; i < tekst.length(); i++)
    {
        if (tekst[i] == ' ')
        {
            spacja = i;
            break;
        }
    }
    if (spacja == -1)
    {
        return tekst;
    }
    string pierwsze = tekst.substr(0, spacja);
    string drugie = tekst.substr(spacja + 1);
    return drugie + " " + pierwsze;
}

//@ STR-20 | frequency of each letter a..z (prints only the letters that occur) | <iostream> <string> <cctype>
/********************************************************
 * nazwa funkcji: czestoscLiter
 * opis funkcji: zlicza i wyświetla, ile razy każda litera a..z występuje w napisie
 * parametry: tekst - analizowany napis
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void czestoscLiter(string tekst)
{
    int licznik[26] = {0};           // licznik[0] -> 'a', licznik[1] -> 'b', ...
    for (int i = 0; i < tekst.length(); i++)
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
            cout << (char)('a' + i) << ": " << licznik[i] << endl;
        }
    }
}

//@ STR-21 | anagram check (same letters, other order: "listen" / "silent") - letter-count arrays | <string> <cctype>
/********************************************************
 * nazwa funkcji: czyAnagram
 * opis funkcji: sprawdza, czy dwa napisy składają się z tych samych liter w tej samej
 *               liczbie (pomija wielkość liter i znaki niebędące literami a..z)
 * parametry: a - pierwszy napis
 *            b - drugi napis
 * zwracany typ i opis: bool - true, gdy napisy są anagramami
 * autor: <numer zdającego>
 ********************************************************/
bool czyAnagram(string a, string b)
{
    int licznikA[26] = {0};
    int licznikB[26] = {0};
    for (int i = 0; i < a.length(); i++)
    {
        char znak = tolower(a[i]);
        if (znak >= 'a' && znak <= 'z')
        {
            licznikA[znak - 'a']++;
        }
    }
    for (int i = 0; i < b.length(); i++)
    {
        char znak = tolower(b[i]);
        if (znak >= 'a' && znak <= 'z')
        {
            licznikB[znak - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (licznikA[i] != licznikB[i])
        {
            return false;
        }
    }
    return true;
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
void zliczWielkieIMale(string tekst, int &wielkie, int &male)
{
    wielkie = 0;
    male = 0;
    for (int i = 0; i < tekst.length(); i++)
    {
        if (isupper(tekst[i]))
        {
            wielkie++;
        }
        else if (islower(tekst[i]))
        {
            male++;
        }
    }
}

// ====================== DEMO (don't copy) ======================
int main()
{
    string t = "Kobyla ma maly bok 2024";
    cout << naWielkie(t) << " | " << naMale(t) << endl;
    cout << "samogloski " << zliczSamogloski(t) << ", spolgloski " << zliczSpolgloski(t)
         << ", cyfry " << zliczCyfry(t) << ", 'a' " << zliczZnak(t, 'a') << ", slowa " << zliczSlowa(t) << endl;

    string slowa[100];
    int ileSlow = podzielNaSlowa("  ala  ma kota ", slowa);
    for (int i = 0; i < ileSlow; i++)
    {
        cout << "[" << slowa[i] << "]";
    }
    cout << endl;

    string czesci[20];
    int ileCzesci = podzielWgSeparatora("Jan;17;4.5", ';', czesci);
    for (int i = 0; i < ileCzesci; i++)
    {
        cout << "[" << czesci[i] << "]";
    }
    cout << endl;

    cout << odwrocNapis("C++ rocks") << " | palindrom? " << czyPalindrom("Kobyla ma maly bok")
         << " | " << usunSpacje(t) << endl;
    cout << zamienWszystkie("ala ma kota, ala ma psa", "ala", "ola") << endl;
    string szyfr = szyfrujCezarem("Ala ma Kota xyz", 3);
    cout << szyfr << " -> " << deszyfrujCezarem(szyfr, 3) << endl;
    cout << "czyLiczba(\"-45\") " << czyLiczbaCalkowita("-45") << ", (\"4a\") " << czyLiczbaCalkowita("4a")
         << ", (\"-\") " << czyLiczbaCalkowita("-") << endl;
    cout << kazdeSlowoWielka("jAN kowALSKI") << " | " << inicjaly("jan maria rokita") << " | " << zamienSlowa("Jan Kowalski") << endl;
    czestoscLiter("Abba");
    int w;
    int m;
    zliczWielkieIMale("Ala Ma KOTA", w, m);
    cout << "anagram? " << czyAnagram("listen", "silent") << " " << czyAnagram("kot", "koc")
         << ", wielkie " << w << ", male " << m << endl;
    return 0;
}
