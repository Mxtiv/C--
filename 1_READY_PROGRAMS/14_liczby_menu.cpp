// ======================================================================
// READY PROGRAM 14: number menu - prime?, perfect?, factorial, Fibonacci, NWD,
// decimal -> binary, digit sum. Shows how to wire blocks into a menu program.
// (new - combines the number blocks)
// Blocks used: IO-01, IO-05, NUM-01, NUM-18, NUM-08, NUM-12, NUM-04, NUM-24, NUM-13
// ======================================================================

#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <cstdlib>
using namespace std;

/********************************************************
 * nazwa funkcji: wczytajLiczbe
 * opis funkcji: wczytuje liczbę całkowitą z zakresu min..max, ponawiając pytanie przy błędzie
 * parametry: komunikat - tekst wyświetlany użytkownikowi
 *            min - najmniejsza dopuszczalna wartość
 *            max - największa dopuszczalna wartość
 * zwracany typ i opis: int - poprawna liczba
 * autor: <numer zdającego>
 ********************************************************/
int wczytajLiczbe(const string &komunikat, int min, int max)
{
    int liczba;
    while (true)
    {
        cout << komunikat;
        if (cin >> liczba && liczba >= min && liczba <= max)
            return liczba;
        if (cin.eof()) exit(0);
        cout << "Podaj liczbe od " << min << " do " << max << "." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

/********************************************************
 * nazwa funkcji: czyPierwsza
 * opis funkcji: sprawdza, czy liczba jest pierwsza
 * parametry: n - sprawdzana liczba
 * zwracany typ i opis: bool - true dla liczby pierwszej
 * autor: <numer zdającego>
 ********************************************************/
bool czyPierwsza(int n)
{
    if (n < 2) return false;
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0) return false;
    return true;
}

/********************************************************
 * nazwa funkcji: czyDoskonala
 * opis funkcji: sprawdza, czy liczba jest równa sumie swoich dzielników właściwych
 * parametry: n - sprawdzana liczba
 * zwracany typ i opis: bool - true dla liczby doskonałej
 * autor: <numer zdającego>
 ********************************************************/
bool czyDoskonala(int n)
{
    if (n < 2) return false;
    int suma = 0;
    for (int d = 1; d <= n / 2; d++)
        if (n % d == 0) suma += d;
    return suma == n;
}

/********************************************************
 * nazwa funkcji: silnia
 * opis funkcji: oblicza silnię liczby n
 * parametry: n - liczba 0..20
 * zwracany typ i opis: long long - n!
 * autor: <numer zdającego>
 ********************************************************/
long long silnia(int n)
{
    long long wynik = 1;
    for (int i = 2; i <= n; i++) wynik *= i;
    return wynik;
}

/********************************************************
 * nazwa funkcji: wypiszFibonacciego
 * opis funkcji: wypisuje n pierwszych wyrazów ciągu Fibonacciego
 * parametry: n - liczba wyrazów
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void wypiszFibonacciego(int n)
{
    long long a = 0, b = 1;
    for (int i = 0; i < n; i++)
    {
        cout << a << " ";
        long long nastepny = a + b;
        a = b;
        b = nastepny;
    }
    cout << endl;
}

/********************************************************
 * nazwa funkcji: nwd
 * opis funkcji: wyznacza największy wspólny dzielnik (algorytm Euklidesa)
 * parametry: a, b - liczby
 * zwracany typ i opis: int - NWD(a, b)
 * autor: <numer zdającego>
 ********************************************************/
int nwd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

/********************************************************
 * nazwa funkcji: naBinarny
 * opis funkcji: zamienia liczbę dziesiętną na zapis dwójkowy (reszty z dzielenia przez 2)
 * parametry: n - liczba nieujemna
 * zwracany typ i opis: string - zapis dwójkowy
 * autor: <numer zdającego>
 ********************************************************/
string naBinarny(int n)
{
    if (n == 0) return "0";
    string wynik;
    while (n > 0)
    {
        wynik += char('0' + n % 2);
        n /= 2;
    }
    reverse(wynik.begin(), wynik.end());
    return wynik;
}

/********************************************************
 * nazwa funkcji: sumaCyfr
 * opis funkcji: oblicza sumę cyfr liczby
 * parametry: n - liczba nieujemna
 * zwracany typ i opis: int - suma cyfr
 * autor: <numer zdającego>
 ********************************************************/
int sumaCyfr(int n)
{
    int s = 0;
    for (; n > 0; n /= 10) s += n % 10;
    return s;
}

int main()
{
    int wybor;
    do
    {
        cout << "\n===== LICZBY =====\n"
             << "1. Czy liczba jest pierwsza\n"
             << "2. Czy liczba jest doskonala\n"
             << "3. Silnia\n"
             << "4. Ciag Fibonacciego\n"
             << "5. NWD dwoch liczb\n"
             << "6. Zamiana na system dwojkowy\n"
             << "7. Suma cyfr\n"
             << "0. Koniec\n";
        wybor = wczytajLiczbe("Wybierz: ", 0, 7);

        switch (wybor)
        {
        case 1:
        {
            int n = wczytajLiczbe("Podaj liczbe: ", 0, 1000000000);
            cout << n << (czyPierwsza(n) ? " jest" : " nie jest") << " liczba pierwsza" << endl;
            break;
        }
        case 2:
        {
            int n = wczytajLiczbe("Podaj liczbe: ", 1, 100000);
            cout << n << (czyDoskonala(n) ? " jest" : " nie jest") << " liczba doskonala" << endl;
            break;
        }
        case 3:
        {
            int n = wczytajLiczbe("Podaj n (0-20): ", 0, 20);
            cout << n << "! = " << silnia(n) << endl;
            break;
        }
        case 4:
            wypiszFibonacciego(wczytajLiczbe("Ile wyrazow (1-90): ", 1, 90));
            break;
        case 5:
        {
            int a = wczytajLiczbe("Pierwsza liczba: ", 1, 1000000000);
            int b = wczytajLiczbe("Druga liczba: ", 1, 1000000000);
            cout << "NWD = " << nwd(a, b) << endl;
            break;
        }
        case 6:
        {
            int n = wczytajLiczbe("Podaj liczbe: ", 0, 1000000000);
            cout << n << " = " << naBinarny(n) << " (2)" << endl;
            break;
        }
        case 7:
        {
            int n = wczytajLiczbe("Podaj liczbe: ", 0, 1000000000);
            cout << "Suma cyfr: " << sumaCyfr(n) << endl;
            break;
        }
        case 0:
            cout << "Koniec programu." << endl;
            break;
        }
    } while (wybor != 0);
    return 0;
}
