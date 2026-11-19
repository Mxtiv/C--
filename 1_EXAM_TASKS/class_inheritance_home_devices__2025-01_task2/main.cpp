// ======================================================================
// INF.04-02-25.01-SG (and INF.04-01-25.06-SD) - klasa bazowa Urzadzenie + potomne
// Pralka (program 1..12, inaczej 0) i Odkurzacz (on()/off() tylko przy zmianie stanu).
// Program główny: pralka - numer z klawiatury (poprawny i niepoprawny), odkurzacz: on() x3,
// komunikat "Odkurzacz wyladowal sie", off(). Spec + key checklist: README.md
// ======================================================================
#include <iostream>
#include <string>
using namespace std;

class Urzadzenie
{
public:
    /************************************************
    nazwa:      wyswietlKomunikat
    opis:       wyświetla na ekranie podany komunikat
    parametry:  komunikat - treść do wyświetlenia   
    zwracany typ i opis: brak
    autor:      00000000000
    ************************************************/
    void wyswietlKomunikat(string komunikat)
    {
        cout << komunikat << endl;
    }
};

class Pralka : public Urzadzenie
{
private:                          // instancje i klasy potomne nie mają dostępu
    int numerProgramu;

public:
    Pralka()
    {
        numerProgramu = 0;
    }

    int ustawProgram(int numer)
    {
        if (numer >= 1 && numer <= 12)
        {
            numerProgramu = numer;
        }
        else
        {
            numerProgramu = 0;
        }
        return numerProgramu;
    }
};

class Odkurzacz : public Urzadzenie
{
private:
    bool wlaczony;

public:
    Odkurzacz()
    {
        wlaczony = false;
    }

    void on()
    {
        if (!wlaczony)
        {
            wlaczony = true;
            wyswietlKomunikat("Odkurzacz wlaczono");
        }
    }

    void off()
    {
        if (wlaczony)
        {
            wlaczony = false;
            wyswietlKomunikat("Odkurzacz wylaczono");
        }
    }
};

int main()
{
    Pralka pralka;
    Odkurzacz odkurzacz;

    int numer;
    cout << "Podaj numer prania 1..12: ";
    cin >> numer;
    if (pralka.ustawProgram(numer) == 0)
    {
        cout << "Podano niepoprawny numer programu" << endl;
    }
    else
    {
        cout << "Program zostal ustawiony" << endl;
    }

    odkurzacz.on();
    odkurzacz.on();
    odkurzacz.on();                                   // komunikat tylko raz
    odkurzacz.wyswietlKomunikat("Odkurzacz wyladowal sie");
    odkurzacz.off();
    return 0;
}
