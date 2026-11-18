#include "kosc.h"
#include <cstdlib>

int Kosc::liczbaInstancji = 0;

Kosc::Kosc(int wartosc)
{
    for (int i = 0; i <= 6; i++)
    {
        nazwyPlikow[i] = "kosc" + to_string(i) + ".png";     // kosc0.png ... kosc6.png
    }
    if (wartosc < 1 || wartosc > 6)
    {
        wartosc = 0;
    }
    liczbaOczek = wartosc;
    idPliku = wartosc;
    dostepna = true;
    liczbaInstancji++;
}

Kosc::Kosc()
{
    for (int i = 0; i <= 6; i++)
    {
        nazwyPlikow[i] = "kosc" + to_string(i) + ".png";
    }
    int wylosowana = rand() % 6 + 1;
    liczbaOczek = wylosowana;
    idPliku = wylosowana;
    dostepna = true;
    liczbaInstancji++;
}

/************************************************
nazwa:      rzuc
opis:       losuje nową wartość 1..6, ale tylko wtedy, gdy kość jest dostępna
parametry:  brak
zwracany typ i opis: brak
autor:      00000000000
************************************************/
void Kosc::rzuc()
{
    if (dostepna)
    {
        int wylosowana = rand() % 6 + 1;
        liczbaOczek = wylosowana;
        idPliku = wylosowana;
    }
}

void Kosc::zablokuj()
{
    dostepna = false;
}

string Kosc::wartoscSlownie()
{
    string slowa[7] = {"zero", "jeden", "dwa", "trzy", "cztery", "piec", "szesc"};
    return slowa[liczbaOczek];
}
