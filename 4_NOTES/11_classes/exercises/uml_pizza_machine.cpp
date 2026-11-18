// ======================================================================
// UML pizza machine (automat do pizzy): constructor with prices,
// setters, getters, calculation methods.
// Original file: unsorted/diagramy/pizza.cpp
// FIXED - the bugs were: constructor assigned to its PARAMETERS (shadowing) instead of fields;
// `ileSera *= cenaSera` changed the field; large pizza price was set to 2.0.
// Lesson: give parameters different names than fields (nowaCena vs cena) - then no this-> is needed.
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class AutomatDoPizzy
{
private:
    int ileSera;
    int ileSzynki;
    int ileBrokulow;
    bool czyDuza;
    double cenaSera;
    double cenaSzynki;
    double cenaBrokulow;
    double cenaCiastaMalego;

public:
    AutomatDoPizzy(double nowaCenaSera, double nowaCenaSzynki, double nowaCenaBrokulow, double nowaCenaCiasta)
    {
        cenaSera = nowaCenaSera;
        cenaSzynki = nowaCenaSzynki;
        cenaBrokulow = nowaCenaBrokulow;
        cenaCiastaMalego = nowaCenaCiasta;
        ileSera = 0;
        ileSzynki = 0;
        ileBrokulow = 0;
        czyDuza = false;
    }

    void setIleSera(int ile)
    {
        ileSera = ile;
    }

    void setIleSzynki(int ile)
    {
        ileSzynki = ile;
    }

    void setIleBrokulow(int ile)
    {
        ileBrokulow = ile;
    }

    void setCzyDuza(bool duza)
    {
        czyDuza = duza;
    }

    double cenaPizzy()
    {
        double cena = cenaCiastaMalego;
        if (czyDuza)
        {
            cena = 2 * cenaCiastaMalego;   // duże ciasto kosztuje dwa razy tyle
        }
        cena = cena + ileSera * cenaSera + ileSzynki * cenaSzynki + ileBrokulow * cenaBrokulow;
        return cena;
    }

    int ileKalorii()
    {
        int kalorie = 200 + ileSera * 100 + ileSzynki * 70 + ileBrokulow * 10;
        if (czyDuza)
        {
            kalorie = kalorie * 2;
        }
        return kalorie;
    }

    bool czyVege()
    {
        return ileSzynki == 0;
    }
};

int main()
{
    int ser;
    int szynka;
    int brokuly;
    string rozmiar;

    cout << "Ile porcji sera: ";
    cin >> ser;
    cout << "Ile porcji szynki: ";
    cin >> szynka;
    cout << "Ile porcji brokulow: ";
    cin >> brokuly;
    cout << "Rozmiar (D - duza, inny - mala): ";
    cin >> rozmiar;

    AutomatDoPizzy pizza(3, 2, 1, 5);
    pizza.setIleSera(ser);
    pizza.setIleSzynki(szynka);
    pizza.setIleBrokulow(brokuly);
    pizza.setCzyDuza(rozmiar == "D" || rozmiar == "d");

    cout << "Cena pizzy: " << pizza.cenaPizzy() << " zl" << endl;
    cout << "Kalorie: " << pizza.ileKalorii() << endl;
    if (pizza.czyVege())
    {
        cout << "Pizza wegetarianska: tak" << endl;
    }
    else
    {
        cout << "Pizza wegetarianska: nie" << endl;
    }

    return 0;
}
