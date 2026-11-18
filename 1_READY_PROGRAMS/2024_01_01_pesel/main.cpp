// ======================================================================
// INF.04-01-24.01-SG - sprawdzanie numeru PESEL: płeć (osobna funkcja -> 'K' / 'M')
// i suma kontrolna (osobna funkcja -> bool) dokładnie według kroków 1-5 z arkusza.
// Zmienna PESEL zainicjowana numerem zdającego albo 55030101193, potem wczytanie z klawiatury.
// Spec + key checklist: README.md in this folder.
// ======================================================================
#include <iostream>
#include <string>
using namespace std;

/**********************************************
nazwa funkcji:  sprawdzPlec
opis funkcji:   ustala płeć na podstawie 10. cyfry numeru PESEL (parzysta - kobieta)
parametry:      pesel - numer PESEL (11 cyfr) w postaci napisu
zwracany typ i opis: char - 'K' dla kobiety, 'M' dla mężczyzny
autor:          00000000000
***********************************************/
char sprawdzPlec(string pesel)
{
    int cyfraPlci = pesel[9] - '0';
    if (cyfraPlci % 2 == 0)
    {
        return 'K';
    }
    else
    {
        return 'M';
    }
}

/**********************************************
nazwa funkcji:  sprawdzSumeKontrolna
opis funkcji:   liczy sumę kontrolną z wagami 1 3 7 9 1 3 7 9 1 3 i porównuje ją z 11. cyfrą
parametry:      pesel - numer PESEL (11 cyfr) w postaci napisu
zwracany typ i opis: bool - true, gdy suma kontrolna jest zgodna, false w przeciwnym razie
autor:          00000000000
***********************************************/
bool sprawdzSumeKontrolna(string pesel)
{
    int wagi[10] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    int S = 0;
    for (int i = 0; i < 10; i++)            // 1. + 2. iloczyny cyfr i wag, suma S
    {
        S = S + (pesel[i] - '0') * wagi[i];
    }
    int M = S % 10;                          // 3.
    int R;
    if (M == 0)                              // 4.
    {
        R = 0;
    }
    else
    {
        R = 10 - M;
    }
    return R == pesel[10] - '0';             // 5.
}

int main()
{
    string pesel = "55030101193";            // numer zdającego lub numer z arkusza

    cout << "Podaj numer PESEL: ";
    cin >> pesel;

    if (sprawdzPlec(pesel) == 'K')
    {
        cout << "Plec: Kobieta" << endl;
    }
    else
    {
        cout << "Plec: Mezczyzna" << endl;
    }

    if (sprawdzSumeKontrolna(pesel))
    {
        cout << "Suma kontrolna jest zgodna" << endl;
    }
    else
    {
        cout << "Suma kontrolna jest niezgodna" << endl;
    }
    return 0;
}
