// ======================================================================
// BUILDING BLOCKS: PESEL - format, control digit, validation, sex, birth date
// PESEL = 11 digits, indexes 0..10:  RR MM DD ZZZ P K
//   weights for digits 0..9: 1 3 7 9 1 3 7 9 1 3
//   control digit (index 10) = (10 - sum % 10) % 10
//   sex = digit at index 9: even -> woman (K), odd -> man (M)
//   month: +80 -> 1800s, +0 -> 1900s, +20 -> 2000s, +40 -> 2100s, +60 -> 2200s
// HOW TO USE: copy the comment box + code under a //@ line, up to the next //@ line.
// ======================================================================

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//@ PESEL-01 | is it exactly 11 digits? | <string> <cctype>
/********************************************************
 * nazwa funkcji: czyPoprawnyFormatPesel
 * opis funkcji: sprawdza, czy napis składa się dokładnie z 11 cyfr
 * parametry: pesel - sprawdzany numer PESEL
 * zwracany typ i opis: bool - true, gdy format jest poprawny
 * autor: <numer zdającego>
 ********************************************************/
bool czyPoprawnyFormatPesel(string pesel)
{
    if (pesel.length() != 11)
    {
        return false;
    }
    for (int i = 0; i < 11; i++)
    {
        if (!isdigit(pesel[i]))
        {
            return false;
        }
    }
    return true;
}

//@ PESEL-02 | compute the control digit from the first 10 digits | <string>
/********************************************************
 * nazwa funkcji: cyfraKontrolnaPesel
 * opis funkcji: oblicza cyfrę kontrolną numeru PESEL z wagami 1 3 7 9 1 3 7 9 1 3
 * parametry: pesel - numer PESEL (co najmniej 10 cyfr)
 * zwracany typ i opis: int - obliczona cyfra kontrolna (0..9)
 * autor: <numer zdającego>
 ********************************************************/
int cyfraKontrolnaPesel(string pesel)
{
    int wagi[10] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    int suma = 0;
    for (int i = 0; i < 10; i++)
    {
        suma += (pesel[i] - '0') * wagi[i];        // - '0' : char digit -> number
    }
    return (10 - suma % 10) % 10;
}

//@ PESEL-03 | full validation: format + checksum (self-contained) | <string> <cctype>
/********************************************************
 * nazwa funkcji: czyPoprawnyPesel
 * opis funkcji: sprawdza format numeru PESEL (11 cyfr) oraz zgodność cyfry kontrolnej
 * parametry: pesel - sprawdzany numer PESEL
 * zwracany typ i opis: bool - true, gdy PESEL jest poprawny
 * autor: <numer zdającego>
 ********************************************************/
bool czyPoprawnyPesel(string pesel)
{
    if (pesel.length() != 11)
    {
        return false;
    }
    for (int i = 0; i < 11; i++)
    {
        if (!isdigit(pesel[i]))
        {
            return false;
        }
    }

    int wagi[10] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    int suma = 0;
    for (int i = 0; i < 10; i++)
    {
        suma += (pesel[i] - '0') * wagi[i];
    }
    int kontrolna = (10 - suma % 10) % 10;
    if (kontrolna == pesel[10] - '0')
    {
        return true;
    }
    return false;
}

//@ PESEL-04 | sex from PESEL: 'K' (woman) or 'M' (man) | <string>
/********************************************************
 * nazwa funkcji: plecZPesel
 * opis funkcji: sprawdza dziesiątą cyfrę numeru PESEL (indeks 9) - parzysta oznacza
 *               kobietę, nieparzysta mężczyznę
 * parametry: pesel - numer PESEL
 * zwracany typ i opis: char - 'K' dla kobiety, 'M' dla mężczyzny
 * autor: <numer zdającego>
 ********************************************************/
char plecZPesel(string pesel)
{
    if ((pesel[9] - '0') % 2 == 0)
    {
        return 'K';
    }
    return 'M';
}

//@ PESEL-05 | birth date from PESEL (day, month, year through & parameters, all centuries) | <string>
/********************************************************
 * nazwa funkcji: dataUrodzeniaZPesel
 * opis funkcji: odczytuje datę urodzenia z numeru PESEL; stulecie wynika z dodatku
 *               do miesiąca (+80: 1800, +0: 1900, +20: 2000, +40: 2100, +60: 2200)
 * parametry: pesel - numer PESEL
 *            dzien - (wyjście) dzień urodzenia
 *            miesiac - (wyjście) miesiąc urodzenia
 *            rok - (wyjście) rok urodzenia
 * zwracany typ i opis: brak (wyniki przez parametry referencyjne)
 * autor: <numer zdającego>
 ********************************************************/
void dataUrodzeniaZPesel(string pesel, int &dzien, int &miesiac, int &rok)
{
    rok = (pesel[0] - '0') * 10 + (pesel[1] - '0');
    miesiac = (pesel[2] - '0') * 10 + (pesel[3] - '0');
    dzien = (pesel[4] - '0') * 10 + (pesel[5] - '0');

    if (miesiac > 80)
    {
        rok = rok + 1800;
        miesiac = miesiac - 80;
    }
    else if (miesiac > 60)
    {
        rok = rok + 2200;
        miesiac = miesiac - 60;
    }
    else if (miesiac > 40)
    {
        rok = rok + 2100;
        miesiac = miesiac - 40;
    }
    else if (miesiac > 20)
    {
        rok = rok + 2000;
        miesiac = miesiac - 20;
    }
    else
    {
        rok = rok + 1900;
    }
}

// ====================== DEMO (don't copy) ======================
int main()
{
    string numery[4] = {"55030101193", "02270803624", "55030101194", "1234"};
    for (int i = 0; i < 4; i++)
    {
        string p = numery[i];
        cout << p << ": ";
        if (!czyPoprawnyFormatPesel(p))
        {
            cout << "zly format" << endl;
        }
        else
        {
            int d;
            int m;
            int r;
            dataUrodzeniaZPesel(p, d, m, r);
            cout << "kontrolna " << cyfraKontrolnaPesel(p) << ", poprawny " << czyPoprawnyPesel(p)
                 << ", plec " << plecZPesel(p) << ", urodzony " << d << "." << m << "." << r << endl;
        }
    }
    return 0;
}
