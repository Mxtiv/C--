// ======================================================================
// INF.04-03-23.06-SG (and INF.04-01-23.06-SD) - klasa Film (wypożyczalnia):
// pola tytuł (max 20 znaków) i liczba wypożyczeń - PROTECTED (klasa + potomne),
// inicjalizacja pustym/0, setter tytułu, gettery, bezargumentowa inkrementuj() void.
// Spec + key checklist: README.md in this folder.
// ======================================================================
#include <iostream>
#include <string>
using namespace std;

/******************************************************
nazwa klasy: Film
pola:    tytul - tytuł filmu (maksymalnie 20 znaków)
         liczbaWypozyczen - ile razy film został wypożyczony
metody:  ustawTytul, brak – zapisuje tytuł (obcina do 20 znaków)
         pobierzTytul, string – zwraca tytuł
         pobierzLiczbeWypozyczen, int – zwraca liczbę wypożyczeń
         inkrementuj, brak – zwiększa liczbę wypożyczeń o 1
informacje: reprezentuje film w wirtualnej wypożyczalni
autor:   00000000000
*****************************************************/
class Film
{
protected:                     // dostęp ma klasa i klasy potomne
    string tytul;
    int liczbaWypozyczen;

public:
    Film()
    {
        tytul = "";
        liczbaWypozyczen = 0;
    }

    void ustawTytul(string nowyTytul)
    {
        tytul = nowyTytul.substr(0, 20);
    }

    string pobierzTytul()
    {
        return tytul;
    }

    int pobierzLiczbeWypozyczen()
    {
        return liczbaWypozyczen;
    }

    void inkrementuj()
    {
        liczbaWypozyczen++;
    }
};

int main()
{
    Film film;
    cout << "Po inicjalizacji: tytul = \"" << film.pobierzTytul() << "\", wypozyczen = "
         << film.pobierzLiczbeWypozyczen() << endl;

    film.ustawTytul("Zielona mila");                                  // test set
    cout << "Tytul po ustawieniu: " << film.pobierzTytul() << endl;   // test get

    cout << "Wypozyczen przed inkrementacja: " << film.pobierzLiczbeWypozyczen() << endl;
    film.inkrementuj();
    cout << "Wypozyczen po inkrementacji: " << film.pobierzLiczbeWypozyczen() << endl;
    return 0;
}
