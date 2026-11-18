// ======================================================================
// MULTIPLE inheritance: Laptop / Komputer : Pamiec, Procesor, Ekran; calling several base ctors
// Original file: unsorted/diagramy/HERITAGEDesktop.cpp (shortened: struct/union/enum parts removed)
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class Pamiec
{
protected:
    string marka;
    int pojemnoscGB;

public:
    Pamiec(string nowaMarka, int nowaPojemnosc)
    {
        marka = nowaMarka;
        pojemnoscGB = nowaPojemnosc;
    }
};

class Procesor
{
protected:
    string model;
    int liczbaRdzeni;

public:
    Procesor(string nowyModel, int nowaLiczbaRdzeni)
    {
        model = nowyModel;
        liczbaRdzeni = nowaLiczbaRdzeni;
    }
};

class Ekran
{
protected:
    int przekatna;

public:
    Ekran(int nowaPrzekatna)
    {
        przekatna = nowaPrzekatna;
    }
};

// dziedziczenie WIELOKROTNE: kilka klas bazowych po przecinku
// konstruktory baz wywolywane sa w kolejnosci z tej linii: Pamiec, Procesor, Ekran
class Laptop : public Pamiec, public Procesor, public Ekran
{
private:
    double waga;

public:
    Laptop(string markaDysku, int pojemnosc, string modelProcesora, int rdzenie, int cale, double nowaWaga)
        : Pamiec(markaDysku, pojemnosc), Procesor(modelProcesora, rdzenie), Ekran(cale)
    {
        waga = nowaWaga;
    }

    void wyswietl()
    {
        cout << "LAPTOP" << endl;
        cout << "Dysk: " << marka << ", " << pojemnoscGB << " GB" << endl;   // z Pamiec
        cout << "Procesor: " << model << ", rdzenie: " << liczbaRdzeni << endl; // z Procesor
        cout << "Ekran: " << przekatna << " cali" << endl;                     // z Ekran
        cout << "Waga: " << waga << " kg" << endl;
    }
};

// komputer stacjonarny - bez ekranu, dziedziczy tylko po dwoch klasach
class Komputer : public Pamiec, public Procesor
{
private:
    bool podswietlenieRGB;

public:
    Komputer(string markaDysku, int pojemnosc, string modelProcesora, int rdzenie, bool rgb)
        : Pamiec(markaDysku, pojemnosc), Procesor(modelProcesora, rdzenie)
    {
        podswietlenieRGB = rgb;
    }

    void wyswietl()
    {
        cout << "KOMPUTER" << endl;
        cout << "Dysk: " << marka << ", " << pojemnoscGB << " GB" << endl;
        cout << "Procesor: " << model << ", rdzenie: " << liczbaRdzeni << endl;
        if (podswietlenieRGB)
        {
            cout << "RGB: tak" << endl;
        }
        else
        {
            cout << "RGB: nie" << endl;
        }
    }
};

int main()
{
    Laptop laptop("WD", 512, "i5", 6, 15, 1.8);
    laptop.wyswietl();
    cout << endl;

    Komputer komputer("Samsung", 1000, "Ryzen 7", 8, true);
    komputer.wyswietl();
    return 0;
}
