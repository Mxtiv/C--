// ======================================================================
// BUILDING BLOCKS: number algorithms (algorytmy liczbowe) - primes, sieve, NWD/NWW,
// factorial, Fibonacci, digits, perfect / Armstrong numbers, power, leap year,
// number systems, prime factors, rounding
// HOW TO USE: copy the comment box + code under a //@ line, up to the next //@ line.
// "needs NUM-xx" in the //@ line = that block calls another block - copy both.
// ======================================================================

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

//@ NUM-01 | is n a prime number? (checks divisors up to sqrt(n)) | -
/********************************************************
 * nazwa funkcji: czyPierwsza
 * opis funkcji: sprawdza, czy liczba jest pierwsza (dzielniki sprawdzane do pierwiastka z n)
 * parametry: n - sprawdzana liczba
 * zwracany typ i opis: bool - true, gdy n jest liczbą pierwszą
 * autor: <numer zdającego>
 ********************************************************/
bool czyPierwsza(int n)
{
    if (n < 2) return false;
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0)
            return false;
    return true;
}

//@ NUM-02 | sieve of Eratosthenes: all primes <= n (returns them in a vector) | <vector>
/********************************************************
 * nazwa funkcji: sitoEratostenesa
 * opis funkcji: wyznacza wszystkie liczby pierwsze nie większe od n metodą sita Eratostenesa -
 *               wykreśla wielokrotności kolejnych liczb pierwszych
 * parametry: n - górna granica przedziału
 * zwracany typ i opis: vector<int> - liczby pierwsze z przedziału 2..n
 * autor: <numer zdającego>
 ********************************************************/
vector<int> sitoEratostenesa(int n)
{
    vector<bool> pierwsza(n + 1, true);
    vector<int> wynik;
    for (int i = 2; i <= n; i++)
    {
        if (!pierwsza[i]) continue;
        wynik.push_back(i);
        for (long long j = (long long)i * i; j <= n; j += i)
            pierwsza[j] = false;               // cross out the multiples
    }
    return wynik;
}

//@ NUM-03 | print primes in a range a..b (needs NUM-01) | <iostream>
/********************************************************
 * nazwa funkcji: wypiszPierwszeWPrzedziale
 * opis funkcji: wypisuje liczby pierwsze z przedziału a..b i zwraca ich liczbę
 * parametry: a - początek przedziału
 *            b - koniec przedziału
 * zwracany typ i opis: int - liczba znalezionych liczb pierwszych
 * autor: <numer zdającego>
 ********************************************************/
int wypiszPierwszeWPrzedziale(int a, int b)
{
    int ile = 0;
    for (int i = a; i <= b; i++)
        if (czyPierwsza(i))
        {
            cout << i << " ";
            ile++;
        }
    cout << endl;
    return ile;
}

//@ NUM-04 | NWD (GCD) - Euclid, modulo version (fast) | -
/********************************************************
 * nazwa funkcji: nwd
 * opis funkcji: wyznacza największy wspólny dzielnik dwóch liczb algorytmem Euklidesa
 *               (wersja z resztą z dzielenia)
 * parametry: a - pierwsza liczba
 *            b - druga liczba
 * zwracany typ i opis: int - największy wspólny dzielnik a i b
 * autor: <numer zdającego>
 ********************************************************/
int nwd(int a, int b)
{
    while (b != 0)
    {
        int reszta = a % b;
        a = b;
        b = reszta;
    }
    return a;
}

//@ NUM-05 | NWD (GCD) - Euclid, SUBTRACTION version (exam classic) | -
/********************************************************
 * nazwa funkcji: nwdOdejmowanie
 * opis funkcji: wyznacza największy wspólny dzielnik dwóch liczb dodatnich algorytmem
 *               Euklidesa w wersji z odejmowaniem (większą liczbę zmniejsza się o mniejszą)
 * parametry: a - pierwsza liczba
 *            b - druga liczba
 * zwracany typ i opis: int - największy wspólny dzielnik a i b
 * autor: <numer zdającego>
 ********************************************************/
int nwdOdejmowanie(int a, int b)
{
    if (a == 0) return b;          // without this the loop below never ends
    if (b == 0) return a;
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

//@ NUM-06 | NWD (GCD) - recursive version | -
/********************************************************
 * nazwa funkcji: nwdRekurencyjnie
 * opis funkcji: wyznacza największy wspólny dzielnik rekurencyjnie: nwd(a, b) = nwd(b, a % b)
 * parametry: a - pierwsza liczba
 *            b - druga liczba
 * zwracany typ i opis: int - największy wspólny dzielnik a i b
 * autor: <numer zdającego>
 ********************************************************/
int nwdRekurencyjnie(int a, int b)
{
    if (b == 0) return a;
    return nwdRekurencyjnie(b, a % b);
}

//@ NUM-07 | NWW (LCM) = a / NWD(a, b) * b (needs NUM-04) | -
/********************************************************
 * nazwa funkcji: nww
 * opis funkcji: wyznacza najmniejszą wspólną wielokrotność dwóch liczb
 * parametry: a - pierwsza liczba
 *            b - druga liczba
 * zwracany typ i opis: long long - najmniejsza wspólna wielokrotność a i b
 * autor: <numer zdającego>
 ********************************************************/
long long nww(int a, int b)
{
    return (long long)a / nwd(a, b) * b;      // divide first -> no overflow
}

//@ NUM-08 | factorial n! with a loop (long long fits up to 20!) | -
/********************************************************
 * nazwa funkcji: silnia
 * opis funkcji: oblicza silnię liczby n iteracyjnie
 * parametry: n - liczba nieujemna (maks. 20)
 * zwracany typ i opis: long long - wartość n!
 * autor: <numer zdającego>
 ********************************************************/
long long silnia(int n)
{
    long long wynik = 1;
    for (int i = 2; i <= n; i++)
        wynik *= i;
    return wynik;
}

//@ NUM-09 | factorial n! recursive | -
/********************************************************
 * nazwa funkcji: silniaRekurencyjnie
 * opis funkcji: oblicza silnię liczby n rekurencyjnie: n! = n * (n-1)!, 0! = 1
 * parametry: n - liczba nieujemna (maks. 20)
 * zwracany typ i opis: long long - wartość n!
 * autor: <numer zdającego>
 ********************************************************/
long long silniaRekurencyjnie(int n)
{
    if (n <= 1) return 1;
    return n * silniaRekurencyjnie(n - 1);
}

//@ NUM-10 | n-th Fibonacci number with a loop (F0 = 0, F1 = 1) | -
/********************************************************
 * nazwa funkcji: fibonacci
 * opis funkcji: oblicza n-ty wyraz ciągu Fibonacciego iteracyjnie (F0 = 0, F1 = 1)
 * parametry: n - numer wyrazu (n >= 0)
 * zwracany typ i opis: long long - n-ty wyraz ciągu
 * autor: <numer zdającego>
 ********************************************************/
long long fibonacci(int n)
{
    long long a = 0, b = 1;
    for (int i = 0; i < n; i++)
    {
        long long nastepny = a + b;
        a = b;
        b = nastepny;
    }
    return a;
}

//@ NUM-11 | n-th Fibonacci number recursive (slow for n > 35) | -
/********************************************************
 * nazwa funkcji: fibonacciRekurencyjnie
 * opis funkcji: oblicza n-ty wyraz ciągu Fibonacciego rekurencyjnie: F(n) = F(n-1) + F(n-2)
 * parametry: n - numer wyrazu (n >= 0)
 * zwracany typ i opis: long long - n-ty wyraz ciągu
 * autor: <numer zdającego>
 ********************************************************/
long long fibonacciRekurencyjnie(int n)
{
    if (n < 2) return n;
    return fibonacciRekurencyjnie(n - 1) + fibonacciRekurencyjnie(n - 2);
}

//@ NUM-12 | print the first n Fibonacci numbers | <iostream>
/********************************************************
 * nazwa funkcji: wypiszCiagFibonacciego
 * opis funkcji: wypisuje n pierwszych wyrazów ciągu Fibonacciego
 * parametry: n - liczba wyrazów do wypisania
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void wypiszCiagFibonacciego(int n)
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

//@ NUM-13 | sum of the digits of a number | -
/********************************************************
 * nazwa funkcji: sumaCyfr
 * opis funkcji: oblicza sumę cyfr liczby całkowitej
 * parametry: n - liczba całkowita
 * zwracany typ i opis: int - suma cyfr
 * autor: <numer zdającego>
 ********************************************************/
int sumaCyfr(int n)
{
    if (n < 0) n = -n;
    int s = 0;
    while (n > 0)
    {
        s += n % 10;       // last digit
        n /= 10;           // remove the last digit
    }
    return s;
}

//@ NUM-14 | how many digits a number has | -
/********************************************************
 * nazwa funkcji: liczbaCyfr
 * opis funkcji: zlicza cyfry liczby całkowitej
 * parametry: n - liczba całkowita
 * zwracany typ i opis: int - liczba cyfr (dla 0 zwraca 1)
 * autor: <numer zdającego>
 ********************************************************/
int liczbaCyfr(int n)
{
    if (n == 0) return 1;
    if (n < 0) n = -n;
    int ile = 0;
    while (n > 0)
    {
        ile++;
        n /= 10;
    }
    return ile;
}

//@ NUM-15 | reverse the digits: 1230 -> 321 | -
/********************************************************
 * nazwa funkcji: odwrocLiczbe
 * opis funkcji: zapisuje cyfry liczby w odwrotnej kolejności
 * parametry: n - liczba nieujemna
 * zwracany typ i opis: int - liczba o odwróconej kolejności cyfr
 * autor: <numer zdającego>
 ********************************************************/
int odwrocLiczbe(int n)
{
    int wynik = 0;
    while (n > 0)
    {
        wynik = wynik * 10 + n % 10;
        n /= 10;
    }
    return wynik;
}

//@ NUM-16 | is the number a palindrome (12321)? | -
/********************************************************
 * nazwa funkcji: czyPalindromLiczbowy
 * opis funkcji: sprawdza, czy liczba czytana od tyłu jest taka sama (np. 12321)
 * parametry: n - liczba nieujemna
 * zwracany typ i opis: bool - true, gdy liczba jest palindromem
 * autor: <numer zdającego>
 ********************************************************/
bool czyPalindromLiczbowy(int n)
{
    int kopia = n, odwrocona = 0;
    while (kopia > 0)
    {
        odwrocona = odwrocona * 10 + kopia % 10;
        kopia /= 10;
    }
    return odwrocona == n;
}

//@ NUM-17 | sum of proper divisors (without the number itself) | -
/********************************************************
 * nazwa funkcji: sumaDzielnikow
 * opis funkcji: oblicza sumę dzielników właściwych liczby (mniejszych od niej)
 * parametry: n - liczba naturalna
 * zwracany typ i opis: int - suma dzielników właściwych
 * autor: <numer zdającego>
 ********************************************************/
int sumaDzielnikow(int n)
{
    int s = 0;
    for (int d = 1; d <= n / 2; d++)
        if (n % d == 0)
            s += d;
    return s;
}

//@ NUM-18 | is it a perfect number (6 = 1+2+3, 28, 496)? | -
/********************************************************
 * nazwa funkcji: czyDoskonala
 * opis funkcji: sprawdza, czy liczba jest doskonała (równa sumie swoich dzielników właściwych)
 * parametry: n - liczba naturalna
 * zwracany typ i opis: bool - true, gdy liczba jest doskonała
 * autor: <numer zdającego>
 ********************************************************/
bool czyDoskonala(int n)
{
    if (n < 2) return false;
    int s = 0;
    for (int d = 1; d <= n / 2; d++)
        if (n % d == 0)
            s += d;
    return s == n;
}

//@ NUM-19 | print all divisors of n | <iostream>
/********************************************************
 * nazwa funkcji: wypiszDzielniki
 * opis funkcji: wypisuje wszystkie dzielniki liczby i zwraca ich liczbę
 * parametry: n - liczba naturalna
 * zwracany typ i opis: int - liczba dzielników
 * autor: <numer zdającego>
 ********************************************************/
int wypiszDzielniki(int n)
{
    int ile = 0;
    for (int d = 1; d <= n; d++)
        if (n % d == 0)
        {
            cout << d << " ";
            ile++;
        }
    cout << endl;
    return ile;
}

//@ NUM-20 | prime factorization: 360 = 2 * 2 * 2 * 3 * 3 * 5 | <iostream>
/********************************************************
 * nazwa funkcji: rozkladNaCzynniki
 * opis funkcji: wypisuje rozkład liczby na czynniki pierwsze
 * parametry: n - liczba naturalna większa od 1
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void rozkladNaCzynniki(int n)
{
    cout << n << " =";
    bool pierwszy = true;
    for (int d = 2; d * d <= n; d++)
        while (n % d == 0)
        {
            cout << (pierwszy ? " " : " * ") << d;
            pierwszy = false;
            n /= d;
        }
    if (n > 1) cout << (pierwszy ? " " : " * ") << n;
    cout << endl;
}

//@ NUM-21 | power a^b, fast (squaring), integers | -
/********************************************************
 * nazwa funkcji: potega
 * opis funkcji: oblicza podstawa^wykladnik metodą szybkiego potęgowania
 * parametry: podstawa - podstawa potęgi
 *            wykladnik - wykładnik nieujemny
 * zwracany typ i opis: long long - wartość potęgi
 * autor: <numer zdającego>
 ********************************************************/
long long potega(long long podstawa, int wykladnik)
{
    long long wynik = 1;
    while (wykladnik > 0)
    {
        if (wykladnik % 2 == 1) wynik *= podstawa;
        podstawa *= podstawa;
        wykladnik /= 2;
    }
    return wynik;
}

//@ NUM-22 | Armstrong / narcissistic number (153 = 1^3 + 5^3 + 3^3) | -
/********************************************************
 * nazwa funkcji: czyArmstronga
 * opis funkcji: sprawdza, czy liczba jest równa sumie swoich cyfr podniesionych do potęgi
 *               równej liczbie cyfr (liczba Armstronga)
 * parametry: n - liczba naturalna
 * zwracany typ i opis: bool - true, gdy n jest liczbą Armstronga
 * autor: <numer zdającego>
 ********************************************************/
bool czyArmstronga(int n)
{
    int cyfry = 0;
    for (int t = n; t > 0; t /= 10) cyfry++;
    long long s = 0;
    for (int t = n; t > 0; t /= 10)
    {
        long long p = 1;
        for (int k = 0; k < cyfry; k++) p *= t % 10;
        s += p;
    }
    return s == n;
}

//@ NUM-23 | leap year? | -
/********************************************************
 * nazwa funkcji: czyPrzestepny
 * opis funkcji: sprawdza, czy rok jest przestępny
 * parametry: rok - sprawdzany rok
 * zwracany typ i opis: bool - true dla roku przestępnego
 * autor: <numer zdającego>
 ********************************************************/
bool czyPrzestepny(int rok)
{
    return (rok % 4 == 0 && rok % 100 != 0) || rok % 400 == 0;
}

//@ NUM-24 | decimal -> any base 2..16 (binary, octal, hex) as text | <string> <algorithm>
/********************************************************
 * nazwa funkcji: naSystem
 * opis funkcji: zamienia liczbę dziesiętną na zapis w systemie o podanej podstawie (2..16)
 *               metodą kolejnych dzieleń - reszty czytane od końca
 * parametry: liczba - liczba nieujemna w systemie dziesiętnym
 *            podstawa - podstawa systemu docelowego (2..16)
 * zwracany typ i opis: string - zapis liczby w nowym systemie
 * autor: <numer zdającego>
 ********************************************************/
string naSystem(int liczba, int podstawa)
{
    if (liczba == 0) return "0";
    const string cyfry = "0123456789ABCDEF";
    string wynik;
    while (liczba > 0)
    {
        wynik += cyfry[liczba % podstawa];
        liczba /= podstawa;
    }
    reverse(wynik.begin(), wynik.end());
    return wynik;
}

//@ NUM-25 | any base 2..16 -> decimal (Horner's scheme) | <string> <cctype>
/********************************************************
 * nazwa funkcji: zSystemu
 * opis funkcji: zamienia zapis liczby w systemie o podanej podstawie na liczbę dziesiętną
 *               (schemat Hornera)
 * parametry: zapis - cyfry liczby, np. "1011" lub "FF"
 *            podstawa - podstawa systemu (2..16)
 * zwracany typ i opis: int - wartość dziesiętna
 * autor: <numer zdającego>
 ********************************************************/
int zSystemu(const string &zapis, int podstawa)
{
    int wynik = 0;
    for (char c : zapis)
    {
        int cyfra = isdigit(c) ? c - '0' : toupper(c) - 'A' + 10;
        wynik = wynik * podstawa + cyfra;
    }
    return wynik;
}

//@ NUM-26 | round to k decimal places (e.g. 3.14159 -> 3.14) | <cmath>
/********************************************************
 * nazwa funkcji: zaokraglij
 * opis funkcji: zaokrągla liczbę do podanej liczby miejsc po przecinku
 * parametry: x - liczba do zaokrąglenia
 *            miejsca - liczba miejsc po przecinku
 * zwracany typ i opis: double - zaokrąglona liczba
 * autor: <numer zdającego>
 ********************************************************/
double zaokraglij(double x, int miejsca)
{
    double mnoznik = pow(10, miejsca);
    return round(x * mnoznik) / mnoznik;
}

// ====================== DEMO (don't copy) ======================
int main()
{
    cout << boolalpha;
    cout << "97 pierwsza? " << czyPierwsza(97) << ", 91 pierwsza? " << czyPierwsza(91) << endl;
    cout << "sito do 50: ";
    for (int p : sitoEratostenesa(50)) cout << p << " ";
    cout << endl << "pierwsze 90..110: ";
    wypiszPierwszeWPrzedziale(90, 110);
    cout << "NWD(84,36) = " << nwd(84, 36) << " = " << nwdOdejmowanie(84, 36) << " = " << nwdRekurencyjnie(84, 36)
         << ", NWW = " << nww(84, 36) << endl;
    cout << "10! = " << silnia(10) << " = " << silniaRekurencyjnie(10)
         << ", F(20) = " << fibonacci(20) << " = " << fibonacciRekurencyjnie(20) << endl;
    wypiszCiagFibonacciego(10);
    cout << "sumaCyfr(9876) = " << sumaCyfr(9876) << ", liczbaCyfr = " << liczbaCyfr(9876)
         << ", odwroc(1230) = " << odwrocLiczbe(1230) << ", 12321 palindrom? " << czyPalindromLiczbowy(12321) << endl;
    cout << "dzielniki 28: ";
    wypiszDzielniki(28);
    cout << "suma dzielnikow 28 = " << sumaDzielnikow(28) << ", 28 doskonala? " << czyDoskonala(28)
         << ", 153 Armstrong? " << czyArmstronga(153) << endl;
    rozkladNaCzynniki(360);
    cout << "2^30 = " << potega(2, 30) << ", 2024 przestepny? " << czyPrzestepny(2024)
         << ", 1900? " << czyPrzestepny(1900) << endl;
    cout << "156 -> " << naSystem(156, 2) << " / " << naSystem(156, 16)
         << ", 10011100 -> " << zSystemu("10011100", 2) << ", FF -> " << zSystemu("ff", 16) << endl;
    cout << "zaokraglij(3.14159, 2) = " << zaokraglij(3.14159, 2) << endl;
    return 0;
}
