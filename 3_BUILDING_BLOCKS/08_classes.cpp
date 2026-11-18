// ======================================================================
// BUILDING BLOCKS: classes (klasy) - ready skeletons to rename and fill in
//   CLS-01 basic class: private fields, constructors, getters/setters with validation
//   CLS-02 static object counter + automatic id (e.g. Notatka, Osoba, Ksiazka)
//   CLS-03 class holding a dynamic array (the typical exam "Tablica" class)
//   CLS-04 class holding a STATIC array of fixed size
//   CLS-05 inheritance: base constructor call, protected fields, virtual method
//   CLS-06 abstract base class + polymorphism (array of base-class pointers)
//   CLS-07 operators: + == << for your own class
//   CLS-08 struct + array of structs + search by field
// HOW TO USE: copy everything under a //@ line, up to the next //@ line, then rename.
// Constructors assign the fields in their body; parameter names differ from field names.
// ======================================================================

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//@ CLS-01 | basic class: private fields, default + parameter constructor, getters, setters with validation, display | <iostream> <string>
/********************************************************
 * nazwa klasy: Osoba
 * opis klasy: przechowuje dane osoby (imię i wiek) z kontrolą poprawności wieku
 * pola: imie - imię osoby
 *       wiek - wiek osoby w latach (0..130)
 * autor: <numer zdającego>
 ********************************************************/
class Osoba
{
private:
    string imie;
    int wiek;

public:
    Osoba()                                  // default constructor
    {
        imie = "brak";
        wiek = 0;
    }

    Osoba(string noweImie, int nowyWiek)     // parameter constructor
    {
        imie = noweImie;
        wiek = 0;
        setWiek(nowyWiek);                   // reuse the validation
    }

    string getImie()
    {
        return imie;
    }

    int getWiek()
    {
        return wiek;
    }

    void setImie(string noweImie)
    {
        imie = noweImie;
    }

    /********************************************************
     * nazwa funkcji: setWiek
     * opis funkcji: ustawia wiek, jeśli mieści się w zakresie 0..130
     * parametry: nowyWiek - nowa wartość wieku
     * zwracany typ i opis: bool - true, gdy wartość była poprawna i została ustawiona
     * autor: <numer zdającego>
     ********************************************************/
    bool setWiek(int nowyWiek)
    {
        if (nowyWiek < 0 || nowyWiek > 130)
        {
            return false;
        }
        wiek = nowyWiek;
        return true;
    }

    /********************************************************
     * nazwa funkcji: wyswietl
     * opis funkcji: wyświetla dane osoby
     * parametry: brak
     * zwracany typ i opis: brak
     * autor: <numer zdającego>
     ********************************************************/
    void wyswietl()
    {
        cout << "Imie: " << imie << ", wiek: " << wiek << endl;
    }
};

//@ CLS-02 | static counter of created objects + automatic id (id = 1, 2, 3 ...) | <iostream> <string>
/********************************************************
 * nazwa klasy: Notatka
 * opis klasy: notatka z automatycznie nadawanym numerem; klasa zlicza utworzone obiekty
 * pola: licznik - (statyczne) liczba utworzonych notatek, wspólna dla wszystkich obiektów
 *       id - numer notatki nadawany w konstruktorze
 *       tytul - tytuł notatki
 *       tresc - treść notatki
 * autor: <numer zdającego>
 ********************************************************/
class Notatka
{
private:
    static int licznik;          // ONE shared value for the whole class
    int id;
    string tytul;
    string tresc;

public:
    Notatka(string nowyTytul, string nowaTresc)
    {
        tytul = nowyTytul;
        tresc = nowaTresc;
        licznik++;
        id = licznik;            // 1, 2, 3, ...
    }

    static int getLicznik()      // call: Notatka::getLicznik()
    {
        return licznik;
    }

    int getId()
    {
        return id;
    }

    /********************************************************
     * nazwa funkcji: wyswietl
     * opis funkcji: wyświetla numer, tytuł i treść notatki
     * parametry: brak
     * zwracany typ i opis: brak
     * autor: <numer zdającego>
     ********************************************************/
    void wyswietl()
    {
        cout << "[" << id << "] " << tytul << ": " << tresc << endl;
    }
};

int Notatka::licznik = 0;        // static field definition - OUTSIDE the class, exactly once

//@ CLS-03 | class with a DYNAMIC array: size in constructor, random fill 1..6, destructor; add methods from 03_arrays.cpp | <iostream> <cstdlib> <ctime>
/********************************************************
 * nazwa klasy: Tablica
 * opis klasy: przechowuje tablicę liczb całkowitych wypełnioną losowo i wykonuje na niej operacje
 * pola: tab - wskaźnik na dynamiczną tablicę liczb (dostępny tylko w tej klasie)
 *       rozmiar - faktyczna liczba elementów tablicy
 * autor: <numer zdającego>
 ********************************************************/
class Tablica
{
private:                         // "dostępne tylko w tej klasie, niedostępne dla klas potomnych"
    int *tab;
    int rozmiar;

public:
    /********************************************************
     * nazwa funkcji: Tablica (konstruktor)
     * opis funkcji: tworzy tablicę o podanym rozmiarze i wypełnia ją liczbami
     *               pseudolosowymi z zakresu 1..6
     * parametry: n - rozmiar tablicy
     * zwracany typ i opis: brak
     * autor: <numer zdającego>
     ********************************************************/
    Tablica(int n)
    {
        rozmiar = n;
        tab = new int[rozmiar];
        for (int i = 0; i < rozmiar; i++)
        {
            tab[i] = rand() % 6 + 1;
        }
    }

    ~Tablica()                   // destructor frees the memory from new[]
    {
        delete[] tab;
    }

    /********************************************************
     * nazwa funkcji: wyswietl
     * opis funkcji: wyświetla elementy tablicy w postaci "<indeks>: <wartość>"
     * parametry: brak
     * zwracany typ i opis: brak
     * autor: <numer zdającego>
     ********************************************************/
    void wyswietl()
    {
        for (int i = 0; i < rozmiar; i++)
        {
            cout << i << ": " << tab[i] << endl;
        }
    }

    /********************************************************
     * nazwa funkcji: suma
     * opis funkcji: oblicza sumę elementów tablicy
     * parametry: brak
     * zwracany typ i opis: int - suma elementów
     * autor: <numer zdającego>
     ********************************************************/
    int suma()
    {
        int s = 0;
        for (int i = 0; i < rozmiar; i++)
        {
            s += tab[i];
        }
        return s;
    }

    int getRozmiar()
    {
        return rozmiar;
    }
    // + paste more methods from 03_arrays.cpp: drop the (tab, n) parameters, use tab and rozmiar
};

//@ CLS-04 | class with a STATIC array of fixed size (const ROZMIAR) - fill, display, find max | <iostream> <cstdlib> <ctime>
/********************************************************
 * nazwa klasy: TablicaStala
 * opis klasy: przechowuje tablicę o stałym rozmiarze ROZMIAR wypełnianą losowo
 * pola: tab - tablica ROZMIAR liczb całkowitych
 * autor: <numer zdającego>
 ********************************************************/
const int ROZMIAR = 10;          // global constant (skip this line if your file already has ROZMIAR)

class TablicaStala
{
private:
    int tab[ROZMIAR];

public:
    /********************************************************
     * nazwa funkcji: wypelnij
     * opis funkcji: wypełnia tablicę liczbami pseudolosowymi z przedziału min..max
     * parametry: min - najmniejsza losowana wartość
     *            max - największa losowana wartość
     * zwracany typ i opis: brak
     * autor: <numer zdającego>
     ********************************************************/
    void wypelnij(int min, int max)
    {
        for (int i = 0; i < ROZMIAR; i++)
        {
            tab[i] = rand() % (max - min + 1) + min;
        }
    }

    void wyswietl()
    {
        for (int i = 0; i < ROZMIAR; i++)
        {
            cout << tab[i] << " ";
        }
        cout << endl;
    }

    /********************************************************
     * nazwa funkcji: maksimum
     * opis funkcji: wyszukuje największą wartość w tablicy
     * parametry: brak
     * zwracany typ i opis: int - największa wartość
     * autor: <numer zdającego>
     ********************************************************/
    int maksimum()
    {
        int max = tab[0];
        for (int i = 1; i < ROZMIAR; i++)
        {
            if (tab[i] > max)
            {
                max = tab[i];
            }
        }
        return max;
    }
};

//@ CLS-05 | inheritance: base class with protected fields, derived class calls the BASE constructor, virtual method | <iostream> <string>
/********************************************************
 * nazwa klasy: Pojazd
 * opis klasy: klasa bazowa opisująca pojazd
 * pola: marka - marka pojazdu (dostępna w klasach pochodnych)
 *       rok - rok produkcji (dostępny w klasach pochodnych)
 * autor: <numer zdającego>
 ********************************************************/
class Pojazd
{
protected:                       // visible in derived classes, NOT in main
    string marka;
    int rok;

public:
    Pojazd(string nowaMarka, int nowyRok)
    {
        marka = nowaMarka;
        rok = nowyRok;
    }

    virtual void wyswietl()      // virtual -> through Pojazd* the derived version is called
    {
        cout << "Pojazd: " << marka << ", rok " << rok << endl;
    }
};

/********************************************************
 * nazwa klasy: Samochod
 * opis klasy: samochód - klasa pochodna klasy Pojazd, dodaje liczbę drzwi
 * pola: drzwi - liczba drzwi
 * autor: <numer zdającego>
 ********************************************************/
class Samochod : public Pojazd
{
private:
    int drzwi;

public:
    Samochod(string nowaMarka, int nowyRok, int noweDrzwi) : Pojazd(nowaMarka, nowyRok)   // base constructor FIRST
    {
        drzwi = noweDrzwi;
    }

    void wyswietl()
    {
        cout << "Samochod: " << marka << ", rok " << rok << ", drzwi: " << drzwi << endl;
    }
};
// usage:  Samochod s("Fiat", 2003, 5);
//         Pojazd *p = &s;
//         p->wyswietl();        // Samochod version thanks to virtual

//@ CLS-06 | abstract base class (pure virtual = 0) + 2 derived classes + polymorphism through an array of Figura* | <iostream> <string>
/********************************************************
 * nazwa klasy: Figura
 * opis klasy: abstrakcyjna klasa bazowa figur - nie można tworzyć jej obiektów
 * pola: brak
 * autor: <numer zdającego>
 ********************************************************/
class Figura
{
public:
    virtual double pole() = 0;           // pure virtual -> every derived class MUST define it
    virtual string nazwa() = 0;
};

/********************************************************
 * nazwa klasy: Kolo
 * opis klasy: koło - klasa pochodna klasy Figura
 * pola: r - promień koła
 * autor: <numer zdającego>
 ********************************************************/
class Kolo : public Figura
{
private:
    double r;

public:
    Kolo(double promien)
    {
        r = promien;
    }

    double pole()
    {
        return 3.14159 * r * r;
    }

    string nazwa()
    {
        return "Kolo";
    }
};

/********************************************************
 * nazwa klasy: Prostokat
 * opis klasy: prostokąt - klasa pochodna klasy Figura
 * pola: a, b - długości boków
 * autor: <numer zdającego>
 ********************************************************/
class Prostokat : public Figura
{
private:
    double a;
    double b;

public:
    Prostokat(double bokA, double bokB)
    {
        a = bokA;
        b = bokB;
    }

    double pole()
    {
        return a * b;
    }

    string nazwa()
    {
        return "Prostokat";
    }
};
// usage:  Kolo k(1);
//         Prostokat p(2, 3);
//         Figura *figury[2] = {&k, &p};
//         for (int i = 0; i < 2; i++)
//         {
//             cout << figury[i]->nazwa() << ": " << figury[i]->pole() << endl;
//         }

//@ CLS-07 | operators for your class: + (member), == (member), << (friend, for cout) | <iostream>
/********************************************************
 * nazwa klasy: Punkt
 * opis klasy: punkt na płaszczyźnie z przeciążonymi operatorami +, == oraz <<
 * pola: x, y - współrzędne punktu
 * autor: <numer zdającego>
 ********************************************************/
class Punkt
{
private:
    double x;
    double y;

public:
    Punkt()
    {
        x = 0;
        y = 0;
    }

    Punkt(double nowyX, double nowyY)
    {
        x = nowyX;
        y = nowyY;
    }

    Punkt operator+(Punkt inny)                  // p1 + p2
    {
        Punkt wynik(x + inny.x, y + inny.y);
        return wynik;
    }

    bool operator==(Punkt inny)                  // p1 == p2
    {
        if (x == inny.x && y == inny.y)
        {
            return true;
        }
        return false;
    }

    friend ostream &operator<<(ostream &wyjscie, Punkt p)     // cout << p (friend -> may read private x, y)
    {
        wyjscie << "(" << p.x << ", " << p.y << ")";
        return wyjscie;
    }
};

//@ CLS-08 | struct + array of structs: display all, find the best by a field | <iostream> <string>
/********************************************************
 * nazwa struktury: Uczen
 * opis struktury: dane ucznia - imię i średnia ocen
 * pola: imie - imię ucznia
 *       srednia - średnia ocen
 * autor: <numer zdającego>
 ********************************************************/
struct Uczen
{
    string imie;
    double srednia;
};

/********************************************************
 * nazwa funkcji: wyswietlUczniow
 * opis funkcji: wyświetla dane wszystkich uczniów z tablicy
 * parametry: uczniowie - tablica uczniów
 *            n - liczba uczniów
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void wyswietlUczniow(Uczen uczniowie[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". " << uczniowie[i].imie << " - " << uczniowie[i].srednia << endl;
    }
}

/********************************************************
 * nazwa funkcji: najlepszyUczen
 * opis funkcji: wyszukuje ucznia z najwyższą średnią
 * parametry: uczniowie - tablica uczniów
 *            n - liczba uczniów (co najmniej 1)
 * zwracany typ i opis: int - indeks ucznia z najwyższą średnią
 * autor: <numer zdającego>
 ********************************************************/
int najlepszyUczen(Uczen uczniowie[], int n)
{
    int najlepszy = 0;
    for (int i = 1; i < n; i++)
    {
        if (uczniowie[i].srednia > uczniowie[najlepszy].srednia)
        {
            najlepszy = i;
        }
    }
    return najlepszy;
}

// ====================== DEMO (don't copy) ======================
int main()
{
    srand(time(0));

    Osoba o("Ala", 17);
    o.setWiek(200);                         // rejected
    o.wyswietl();

    Notatka n1("Zakupy", "mleko");
    Notatka n2("Szkola", "INF04");
    n2.wyswietl();
    cout << "notatek: " << Notatka::getLicznik() << ", id pierwszej: " << n1.getId() << endl;

    Tablica t(5);
    t.wyswietl();
    cout << "suma: " << t.suma() << ", rozmiar: " << t.getRozmiar() << endl;

    TablicaStala ts;
    ts.wypelnij(1, 100);
    ts.wyswietl();
    cout << "max: " << ts.maksimum() << endl;

    Samochod s("Fiat", 2003, 5);
    Pojazd *p = &s;
    p->wyswietl();                          // Samochod version thanks to virtual

    Kolo k(1);
    Prostokat pr(2, 3);
    Figura *figury[2] = {&k, &pr};
    for (int i = 0; i < 2; i++)
    {
        cout << figury[i]->nazwa() << ": " << figury[i]->pole() << endl;
    }

    Punkt a(1, 2);
    Punkt b(3, 4);
    cout << a << " + " << b << " = " << a + b << ", rowne? " << (a == b) << endl;

    Uczen klasa[3];
    klasa[0].imie = "Ola";
    klasa[0].srednia = 4.5;
    klasa[1].imie = "Jan";
    klasa[1].srednia = 5.2;
    klasa[2].imie = "Ewa";
    klasa[2].srednia = 3.9;
    wyswietlUczniow(klasa, 3);
    cout << "najlepszy: " << klasa[najlepszyUczen(klasa, 3)].imie << endl;
    return 0;
}
