// ======================================================================
// test: water dispenser (dystrybutor wody) - constructor, setters,
// int &kubek output parameter, static counter + static getter,
// interactive do-while "pour more?".
// Original files: unsorted/sprawdzian/instrybutor.cpp (interactive)
//                 + unsorted/sprawdzian/MATEUSZCIELEN.cpp (same class, fixed 250 ml) - merged
// FIXED - the bug was: `if (czy = 2)` and `while (czy = 1)` ASSIGNED instead of comparing (now ==)
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class Dystrybutor
{
private:
    int iloscWody;
    int lacznieNalano;
    int pojemnosc;
    string kolor;
    bool czyCieplaWoda;
    static int liczbaDystrybutorow;

public:
    Dystrybutor()
    {
        iloscWody = 0;
        lacznieNalano = 0;
        pojemnosc = 0;
        kolor = "brak";
        czyCieplaWoda = false;
        liczbaDystrybutorow++;
    }

    void setPojemnosc(int nowaPojemnosc)
    {
        pojemnosc = nowaPojemnosc;
    }

    void setKolor(string nowyKolor)
    {
        kolor = nowyKolor;
    }

    void setCzyCieplaWoda(bool ciepla)
    {
        czyCieplaWoda = ciepla;
    }

    void uzupelnijWode()
    {
        iloscWody = pojemnosc;
        cout << "Dystrybutor uzupelniony do " << pojemnosc << " ml." << endl;
    }

    // kubek przez & - metoda zmienia zmienną z main
    void nalejDoKubka(int ile, int &kubek)
    {
        if (ile <= iloscWody)
        {
            kubek = kubek + ile;
            iloscWody = iloscWody - ile;
            lacznieNalano = lacznieNalano + ile;
            cout << "Nalano " << ile << " ml. W kubku jest " << kubek << " ml." << endl;
        }
        else
        {
            cout << "Za malo wody w dystrybutorze!" << endl;
        }
    }

    void wypisz()
    {
        cout << "Kolor: " << kolor << endl;
        if (czyCieplaWoda)
        {
            cout << "Ciepla woda: tak" << endl;
        }
        else
        {
            cout << "Ciepla woda: nie" << endl;
        }
        cout << "Woda w zbiorniku: " << iloscWody << " / " << pojemnosc << " ml" << endl;
        cout << "Lacznie nalano: " << lacznieNalano << " ml" << endl;
    }

    static int getLiczbaDystrybutorow()
    {
        return liczbaDystrybutorow;
    }
};

int Dystrybutor::liczbaDystrybutorow = 0;

int main()
{
    Dystrybutor d1;
    d1.setPojemnosc(2000);
    d1.setKolor("niebieski");
    d1.setCzyCieplaWoda(true);
    d1.uzupelnijWode();

    int kubek = 0;
    int ile;
    int czyDalej;
    do
    {
        cout << "Ile nalac (ml)? ";
        cin >> ile;
        d1.nalejDoKubka(ile, kubek);
        cout << "Nalewac dalej? (1 - tak, 2 - nie): ";
        cin >> czyDalej;
    } while (czyDalej == 1);

    d1.wypisz();
    cout << "Liczba dystrybutorow: " << Dystrybutor::getLiczbaDystrybutorow() << endl;

    return 0;
}
