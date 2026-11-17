// ======================================================================
// UML pizza machine: init list, this-> setters, calculation methods
// Original file: unsorted/diagramy/pizza.cpp
// FIXED - the bugs were: constructor assigned to its PARAMETERS (shadowing) instead of fields; `ileSera *= cenaSera` changed the field; large pizza price was set to 2.0
// ======================================================================

#include <iostream>
using namespace std;

class automat_do_pizzy
{
private:
    int ileSera;
    int ileSzynki;
    int ileBrokuly;
    bool czyDuza;

    float cenaSera;
    float cenaSzynki;
    float cenaBrokuly;
    float cenaCiastaMalego;

public:
    // Constructor
    automat_do_pizzy(float cenaSera, float cenaSzynki, float cenaBrokuly, float cenaCiastaMalego)
        : cenaSera(cenaSera), cenaSzynki(cenaSzynki), cenaBrokuly(cenaBrokuly), cenaCiastaMalego(cenaCiastaMalego)
    {
        ileSera = 0;
        ileSzynki = 0;
        ileBrokuly = 0;
        czyDuza = false;
        // (prices are already set by the initializer list above)
    }

    // Setters
    void setIleSera(int ileSera) { this->ileSera = ileSera; }
    void setIleSzynki(int ileSzynki) { this->ileSzynki = ileSzynki; }
    void setIleBrokuly(int ileBrokuly) { this->ileBrokuly = ileBrokuly; }
    void setCzyDuza(bool czyDuza) { this->czyDuza = czyDuza; }

    // Getters
    int getIleSera() { return ileSera; }
    int getIleSzynki() { return ileSzynki; }
    int getIleBrokuly() { return ileBrokuly; }
    bool getCzyDuza() { return czyDuza; }

    // Methods
    float cenaPizzy()
    {
        float cena = cenaCiastaMalego;
        if (czyDuza)
        {
            cena = 2 * cenaCiastaMalego;   // large dough costs twice the small one
        }
        cena += 3;
        cena += ileSera * cenaSera;
        cena += ileSzynki * cenaSzynki;
        cena += ileBrokuly * cenaBrokuly;
        return cena;
    }

    int ileKalorii()
    {
        int kalorie = 200; // Wartość bazowa dla małej pizzy
        kalorie += ileSera / 402;
        kalorie += ileSzynki / 145;
        kalorie += ileBrokuly / 37;
        if (czyDuza)
            kalorie *= 2;
        return kalorie;
    }

    bool czyVege()
    {
        return ileSzynki == 0;
    }
};

int main()
{
    int choiceSer, choiceSzynka, choiceBrokuly;
    string choiceRozmiar;

    cout << "Podaj ilość sera: ";
    cin >> choiceSer;

    cout << "Podaj ilość szynki: ";
    cin >> choiceSzynka;

    cout << "Podaj ilość brokuły: ";
    cin >> choiceBrokuly;

    cout << "Podaj rozmiar pizzy (D - duża, inny - mała): ";
    cin >> choiceRozmiar;

    automat_do_pizzy pizza(3, 2, 1, 5.0);
    pizza.setIleSera(choiceSer);
    pizza.setIleSzynki(choiceSzynka);
    pizza.setIleBrokuly(choiceBrokuly);
    pizza.setCzyDuza(choiceRozmiar == "D" || choiceRozmiar == "d");

    std::cout << "Cena pizzy: " << pizza.cenaPizzy() << std::endl;
    std::cout << "Ilość kalorii: " << pizza.ileKalorii() << std::endl;
    std::cout << "Czy pizza jest wegetariańska? " << (pizza.czyVege() ? "Tak" : "Nie") << std::endl;

    return 0;
}