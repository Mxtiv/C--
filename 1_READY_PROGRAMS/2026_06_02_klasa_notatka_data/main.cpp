// ======================================================================
// INF.04-02-26.06-SG - klasa Notatka: publiczne pola tytuł, treść, priorytet (bool),
// data dodania (typ daty: time_t); konstruktor 3-arg. i 1-arg. (data = teraz),
// wypisz(): linia "____", "Notatka WAZNA! <tytul>" albo "Notatka <tytul>", treść, data, linia.
// Program główny: notatka ważna (dane w kodzie) + notatka z tytułem z klawiatury.
// Spec + key checklist: README.md in this folder.
// ======================================================================
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

    Notatka(string tytul, string tresc, bool wazna)
    {
        this->tytul = tytul;
        this->tresc = tresc;
        this->wazna = wazna;
        dataDodania = time(nullptr);         // aktualna data
    }

    Notatka(string tytul)
    {
        this->tytul = tytul;
        tresc = "";
        wazna = false;
        dataDodania = time(nullptr);
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

        char data[11];
        strftime(data, sizeof(data), "%d.%m.%Y", localtime(&dataDodania));
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
