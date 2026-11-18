// ======================================================================
// INF.04-02-23.01-SG (and 23.01-01-SD, 23.01-02-AG) - klasa Notatka:
// statyczny licznik + id (private), tytuł i treść (protected), konstruktor (tytuł, treść),
// metoda wyświetlająca tytuł+treść, metoda diagnostyczna z polami oddzielonymi ";".
// Spec + key checklist: README.md in this folder.
// ======================================================================
#include <iostream>
#include <string>
using namespace std;

/************************************************
   klasa: Notatka
   opis: reprezentuje jedną notatkę użytkownika z unikalnym identyfikatorem
   pola: licznikNotatek - (statyczne) liczba utworzonych notatek
         id - unikalny identyfikator notatki
         tytul - tytuł notatki
         tresc - treść notatki
   autor: 00000000000
************************************************/
class Notatka
{
private:                        // niedostępne dla klas potomnych
    static int licznikNotatek;
    int id;

protected:                      // dostępne dla klas potomnych
    string tytul;
    string tresc;

public:
    Notatka(string tytul, string tresc)
    {
        licznikNotatek++;               // najpierw licznik...
        id = licznikNotatek;            // ...potem id = licznik (1, 2, 3...)
        this->tytul = tytul;
        this->tresc = tresc;
    }

    void wyswietl()
    {
        cout << "Tytul: " << tytul << endl;
        cout << "Tresc: " << tresc << endl;
    }

    void diagnostyka()
    {
        cout << licznikNotatek << ";" << id << ";" << tytul << ";" << tresc << endl;
    }
};

int Notatka::licznikNotatek = 0;

int main()
{
    Notatka zakupy("Zakupy", "Chleb, mleko, maslo");
    Notatka egzamin("Egzamin INF.04", "Powtorzyc klasy i sortowanie");

    cout << "--- Notatka 1 ---" << endl;
    zakupy.wyswietl();
    cout << "Diagnostyka: ";
    zakupy.diagnostyka();

    cout << "--- Notatka 2 ---" << endl;
    egzamin.wyswietl();
    cout << "Diagnostyka: ";
    egzamin.diagnostyka();
    return 0;
}
