// ======================================================================
// test: decode an egg code (kod jaja), e.g. 1PL12345678 or 1-PL-12345678
//   digit 0..3 = type of farming, 2 letters = country, rest = producer number
// Shows: private helper methods called from a public setter, static counter.
// Original file: Classes/spr/sprawdzianjajo/mainJajo.cpp
// FIXED - the original did not compile (`=` instead of `==`, (string) casts on chars,
// private setters called from main, static counter not defined outside the class).
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class Jajo
{
private:
    string kod;               // kod bez myślników, np. 1PL12345678
    int typChowu;             // 0..3, -1 = zły
    string kraj;
    string producent;
    static int iloscJaj;

    // metody prywatne - wołane tylko z wnętrza klasy (z setKod)
    void ustawTypChowu()
    {
        if (kod[0] >= '0' && kod[0] <= '3')
        {
            typChowu = kod[0] - '0';      // znak cyfry -> liczba
        }
        else
        {
            typChowu = -1;
        }
    }

    void ustawKraj()
    {
        if (kod[1] == 'P' && kod[2] == 'L')
        {
            kraj = "Polska";
        }
        else if (kod[1] == 'D' && kod[2] == 'E')
        {
            kraj = "Niemcy";
        }
        else
        {
            kraj = "nieznany kraj";
        }
    }

public:
    Jajo()
    {
        kod = "";
        typChowu = -1;
        kraj = "";
        producent = "";
    }

    void setKod(string kodJaja)
    {
        // usuwamy myślniki: 1-PL-12345678 -> 1PL12345678
        kod = "";
        for (int i = 0; i < kodJaja.length(); i++)
        {
            if (kodJaja[i] != '-')
            {
                kod = kod + kodJaja[i];
            }
        }
        if (kod.length() < 4)
        {
            cout << "Za krotki kod!" << endl;
            return;
        }
        iloscJaj++;
        ustawTypChowu();
        ustawKraj();
        producent = kod.substr(3);
    }

    string getTypChowuSlownie()
    {
        switch (typChowu)
        {
        case 0:
            return "ekologiczny";
        case 1:
            return "wolny wybieg";
        case 2:
            return "sciolkowy";
        case 3:
            return "klatkowy";
        default:
            return "zly numer";
        }
    }

    void wypisz()
    {
        cout << "Typ chowu: " << getTypChowuSlownie() << endl;
        cout << "Kraj: " << kraj << endl;
        cout << "Numer producenta: " << producent << endl;
    }

    static int getIloscJaj()
    {
        return iloscJaj;
    }
};

int Jajo::iloscJaj = 0;

int main()
{
    string kodJaja;
    cout << "Podaj kod jaja (np. 1PL12345678): ";
    cin >> kodJaja;

    Jajo jajo;
    jajo.setKod(kodJaja);
    jajo.wypisz();
    cout << "Sprawdzonych jaj: " << Jajo::getIloscJaj() << endl;

    return 0;
}
