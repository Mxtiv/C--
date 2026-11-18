// ======================================================================
// Samochod -> Ciezarowka / Autobus: default + param ctors calling the base ctor
// Original file: Classes/Klasy z dziedziczeniem/X) Zadanie klasy z wartosciami samochodu/main.cpp
// FIXED - the bug was: main builds an Autobus but never calls wyswietl(); seat arguments are passed in swapped order
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class Samochod
{
private:
    string marka;

protected:
    string model;
    int rokProdukcji;

public:
    Samochod()
    {
        marka = "fiat";
        model = "punto";
        rokProdukcji = 2003;
    }

    Samochod(string nowaMarka, string nowyModel, int nowyRok)
    {
        marka = nowaMarka;
        model = nowyModel;
        rokProdukcji = nowyRok;
    }

    string getMarka()
    {
        return marka;
    }
};

class Ciezarowka : public Samochod
{
private:
    string przeznaczenie;

public:
    Ciezarowka()                // bez ": Samochod(...)" -> wywola sie Samochod()
    {
        przeznaczenie = "chlodnia";
    }

    Ciezarowka(string nowaMarka, string nowyModel, int nowyRok, string nowePrzeznaczenie) : Samochod(nowaMarka, nowyModel, nowyRok)
    {
        przeznaczenie = nowePrzeznaczenie;
    }

    void wyswietl()
    {
        cout << getMarka() << " " << model << " " << rokProdukcji << ", " << przeznaczenie << endl;
    }
};

class Autobus : public Samochod
{
private:
    int miejscaSiedzace;
    int miejscaStojace;

public:
    Autobus()
    {
        miejscaSiedzace = 24;
        miejscaStojace = 48;
    }

    Autobus(string nowaMarka, string nowyModel, int nowyRok, int siedzace, int stojace) : Samochod(nowaMarka, nowyModel, nowyRok)
    {
        miejscaSiedzace = siedzace;
        miejscaStojace = stojace;
    }

    void wyswietl()
    {
        cout << getMarka() << " " << model << " " << rokProdukcji << endl;
        cout << "miejsca siedzace: " << miejscaSiedzace << ", stojace: " << miejscaStojace << endl;
    }
};

int main()
{
    int rok;
    int siedzace;
    int stojace;
    string marka;
    string model;

    cout << "Podaj marke: ";
    cin >> marka;
    cout << "Podaj model: ";
    cin >> model;
    cout << "Podaj rok produkcji: ";
    cin >> rok;
    cout << "Podaj liczbe miejsc siedzacych: ";
    cin >> siedzace;
    cout << "Podaj liczbe miejsc stojacych: ";
    cin >> stojace;

    Autobus autobus(marka, model, rok, siedzace, stojace);
    autobus.wyswietl();

    Ciezarowka ciezarowka;      // konstruktor domyslny -> Samochod() + "chlodnia"
    ciezarowka.wyswietl();
    return 0;
}
