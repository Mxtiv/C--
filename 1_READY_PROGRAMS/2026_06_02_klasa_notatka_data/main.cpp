// ======================================================================
// INF.04-02-26.06-SG - klasa Notatka: publiczne pola tytuł, treść, priorytet (bool),
// data dodania (typ daty: time_t); konstruktor 3-arg. i 1-arg. (data = teraz),
// wypisz(): linia "____", "Notatka WAZNA! <tytul>" albo "Notatka <tytul>", treść, data, linia.
// Program główny: notatka ważna (dane w kodzie) + notatka z tytułem z klawiatury.
// Spec + key checklist: README.md in this folder.
// ======================================================================
#define _CRT_SECURE_NO_WARNINGS     // Visual Studio: bez tego localtime() daje błąd C4996
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Notatka
{
public:
    string tytul;
    string tresc;
    bool wazna;
    time_t dataDodania;          // typ przechowujący datę (i czas)

    Notatka(string nowyTytul, string nowaTresc, bool czyWazna)
    {
        tytul = nowyTytul;
        tresc = nowaTresc;
        wazna = czyWazna;
        dataDodania = time(0);               // aktualna data
    }

    Notatka(string nowyTytul)
    {
        tytul = nowyTytul;
        tresc = "";
        wazna = false;
        dataDodania = time(0);
    }

    /*
    nazwa:  wypisz
    opis:   wyświetla notatkę w osobnych liniach: linia, tytuł (z dopiskiem WAZNA!), treść,
            data dodania, linia
    parametry: brak
    zwracany typ: brak
    autor:  00000000000
    */
    void wypisz()
    {
        cout << "________________" << endl;
        if (wazna)
        {
            cout << "Notatka WAZNA! " << tytul << endl;
        }
        else
        {
            cout << "Notatka " << tytul << endl;
        }
        cout << tresc << endl;

        char data[11];                       // "dd.mm.rrrr" = 10 znaków + znak końca napisu
        strftime(data, 11, "%d.%m.%Y", localtime(&dataDodania));
        cout << data << endl;
        cout << "________________" << endl;
    }
};

int main()
{
    Notatka wazna("Egzamin INF.04", "Zabrac dowod osobisty i dlugopis", true);

    string tytul;
    cout << "Podaj tytul notatki: ";
    getline(cin, tytul);
    Notatka zwykla(tytul);

    wazna.wypisz();
    zwykla.wypisz();
    return 0;
}
