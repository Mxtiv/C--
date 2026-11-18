// ======================================================================
// READY PROGRAM 14: number menu - prime?, perfect?, factorial, Fibonacci, NWD,
// decimal -> binary, digit sum. Shows how to wire blocks into a menu program.
// (new - combines the number blocks)
// Blocks used: IO-01, IO-05, NUM-01, NUM-18, NUM-08, NUM-12, NUM-04, NUM-24, NUM-13
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

/********************************************************
 * nazwa funkcji: wczytajLiczbe
 * opis funkcji: wczytuje liczbę całkowitą z zakresu min..max - pyta tak długo,
 *               aż użytkownik poda liczbę z tego zakresu
 * parametry: komunikat - tekst wyświetlany użytkownikowi
 *            min - najmniejsza dopuszczalna wartość
 *            max - największa dopuszczalna wartość
 * zwracany typ i opis: int - poprawna liczba
 * autor: <numer zdającego>
 ********************************************************/
int wczytajLiczbe(string komunikat, int min, int max)
{
    int liczba;
    do
    {
        cout << komunikat;
        cin >> liczba;
    } while (liczba < min || liczba > max);
    return liczba;
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
    if (n < 2)
    {
        return false;
    }
    for (int d = 2; d * d <= n; d++)
    {
        if (n % d == 0)
        {
            return false;
        }
    }
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
    if (n < 2)
    {
        return false;
    }
    int suma = 0;
    for (int d = 1; d <= n / 2; d++)
    {
        if (n % d == 0)
        {
            suma = suma + d;
        }
    }
    if (suma == n)
    {
        return true;
    }
    return false;
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
    for (int i = 2; i <= n; i++)
    {
        wynik = wynik * i;
    }
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
    long long a = 0;
    long long b = 1;
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
        int reszta = a % b;
        a = b;
        b = reszta;
    }
    return a;
}

/********************************************************
 * nazwa funkcji: naBinarny
 * opis funkcji: zamienia liczbę dziesiętną na zapis dwójkowy - kolejne reszty
 *               z dzielenia przez 2 dopisywane są na początku napisu
 * parametry: n - liczba nieujemna
 * zwracany typ i opis: string - zapis dwójkowy
 * autor: <numer zdającego>
 ********************************************************/
string naBinarny(int n)
{
    if (n == 0)
    {
        return "0";
    }
    string wynik = "";
    while (n > 0)
    {
        wynik = to_string(n % 2) + wynik;
        n = n / 2;
    }
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
    int suma = 0;
    while (n > 0)
    {
        suma = suma + n % 10;
        n = n / 10;
    }
    return suma;
}

int main()
{
    int wybor;
    do
    {
        cout << "\n===== LICZBY =====" << endl;
        cout << "1. Czy liczba jest pierwsza" << endl;
        cout << "2. Czy liczba jest doskonala" << endl;
        cout << "3. Silnia" << endl;
        cout << "4. Ciag Fibonacciego" << endl;
        cout << "5. NWD dwoch liczb" << endl;
        cout << "6. Zamiana na system dwojkowy" << endl;
        cout << "7. Suma cyfr" << endl;
        cout << "0. Koniec" << endl;
        wybor = wczytajLiczbe("Wybierz: ", 0, 7);

        switch (wybor)
        {
        case 1:
        {
            int n = wczytajLiczbe("Podaj liczbe: ", 0, 1000000000);
            if (czyPierwsza(n))
            {
                cout << n << " jest liczba pierwsza" << endl;
            }
            else
            {
                cout << n << " nie jest liczba pierwsza" << endl;
            }
            break;
        }
        case 2:
        {
            int n = wczytajLiczbe("Podaj liczbe: ", 1, 100000);
            if (czyDoskonala(n))
            {
                cout << n << " jest liczba doskonala" << endl;
            }
            else
            {
                cout << n << " nie jest liczba doskonala" << endl;
            }
            break;
        }
        case 3:
        {
            int n = wczytajLiczbe("Podaj n (0-20): ", 0, 20);
            cout << n << "! = " << silnia(n) << endl;
            break;
        }
        case 4:
        {
            int n = wczytajLiczbe("Ile wyrazow (1-90): ", 1, 90);
            wypiszFibonacciego(n);
            break;
        }
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
        {
            cout << "Koniec programu." << endl;
            break;
        }
        }
    } while (wybor != 0);
    return 0;
}
