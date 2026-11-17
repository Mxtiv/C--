// ======================================================================
// BUILDING BLOCKS: classes (klasy) - ready skeletons to rename and fill in
//   CLS-01 basic class: private fields, constructors, getters/setters with validation
//   CLS-02 static object counter + automatic id (e.g. Notatka, Osoba, Ksiazka)
//   CLS-03 class holding a dynamic array (the typical exam "Tablica" class)
//   CLS-04 class holding a STATIC array of fixed size
//   CLS-05 inheritance: base constructor call, protected fields, virtual + override
//   CLS-06 abstract base class + polymorphism (array of base-class pointers)
//   CLS-07 operators: + == << for your own class
//   CLS-08 struct + array of structs + search by field
// HOW TO USE: copy everything under a //@ line, up to the next //@ line, then rename.
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
    Osoba() : imie("brak"), wiek(0) {}                       // default constructor
    Osoba(string imie, int wiek) : imie(imie), wiek(0)       // parameter constructor
    {
        setWiek(wiek);                                       // reuse the validation
    }

    string getImie() const { return imie; }
    int getWiek() const { return wiek; }

    void setImie(const string &noweImie) { imie = noweImie; }

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
            return false;
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
    void wyswietl() const
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
    Notatka(string tytul, string tresc) : tytul(tytul), tresc(tresc)
    {
        licznik++;
        id = licznik;            // 1, 2, 3, ...
    }

    static int getLicznik() { return licznik; }   // call: Notatka::getLicznik()
    int getId() const { return id; }

    /********************************************************
     * nazwa funkcji: wyswietl
     * opis funkcji: wyświetla numer, tytuł i treść notatki
     * parametry: brak
     * zwracany typ i opis: brak
     * autor: <numer zdającego>
     ********************************************************/
    void wyswietl() const
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
    Tablica(int n) : tab(new int[n]), rozmiar(n)
    {
        for (int i = 0; i < rozmiar; i++)
            tab[i] = rand() % 6 + 1;
    }

    ~Tablica()                   // destructor frees the memory from new[]
    {
        delete[] tab;
    }

    Tablica(const Tablica &) = delete;             // no copying (would double-delete)
    Tablica &operator=(const Tablica &) = delete;

    /********************************************************
     * nazwa funkcji: wyswietl
     * opis funkcji: wyświetla elementy tablicy w postaci "<indeks>: <wartość>"
     * parametry: brak
     * zwracany typ i opis: brak
     * autor: <numer zdającego>
     ********************************************************/
    void wyswietl() const
    {
        for (int i = 0; i < rozmiar; i++)
            cout << i << ": " << tab[i] << endl;
    }

    /********************************************************
     * nazwa funkcji: suma
     * opis funkcji: oblicza sumę elementów tablicy
     * parametry: brak
     * zwracany typ i opis: int - suma elementów
     * autor: <numer zdającego>
     ********************************************************/
    int suma() const
    {
        int s = 0;
        for (int i = 0; i < rozmiar; i++)
            s += tab[i];
        return s;
    }

    int getRozmiar() const { return rozmiar; }
    // + paste more methods from 03_arrays.cpp: drop the (tab, n) parameters, use tab and rozmiar
};

//@ CLS-04 | class with a STATIC array of fixed size (const ROZMIAR) - fill, display, find max | <iostream> <cstdlib> <ctime>
/********************************************************
 * nazwa klasy: TablicaStala
 * opis klasy: przechowuje tablicę o stałym rozmiarze ROZMIAR wypełnianą losowo
 * pola: ROZMIAR - (stała) liczba elementów tablicy
 *       tab - tablica liczb całkowitych
 * autor: <numer zdającego>
 ********************************************************/
class TablicaStala
{
private:
    static const int ROZMIAR = 10;
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
            tab[i] = rand() % (max - min + 1) + min;
    }

    void wyswietl() const
    {
        for (int i = 0; i < ROZMIAR; i++)
            cout << tab[i] << " ";
        cout << endl;
    }

    /********************************************************
     * nazwa funkcji: maksimum
     * opis funkcji: wyszukuje największą wartość w tablicy
     * parametry: brak
     * zwracany typ i opis: int - największa wartość
     * autor: <numer zdającego>
     ********************************************************/
    int maksimum() const
    {
        int max = tab[0];
        for (int i = 1; i < ROZMIAR; i++)
            if (tab[i] > max)
                max = tab[i];
        return max;
    }
};

//@ CLS-05 | inheritance: base class with protected fields, derived class calls the BASE constructor, virtual + override | <iostream> <string>
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
    Pojazd(string marka, int rok) : marka(marka), rok(rok) {}
    virtual ~Pojazd() {}         // always virtual destructor in a base class

    virtual void wyswietl() const
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
    Samochod(string marka, int rok, int drzwi) : Pojazd(marka, rok), drzwi(drzwi) {}   // base ctor FIRST

    void wyswietl() const override
    {
        cout << "Samochod: " << marka << ", rok " << rok << ", drzwi: " << drzwi << endl;
    }
};

//@ CLS-06 | abstract base class (pure virtual = 0) + 2 derived classes + polymorphism through Figura* | <iostream> <string>
/********************************************************
 * nazwa klasy: Figura
 * opis klasy: abstrakcyjna klasa bazowa figur - nie można tworzyć jej obiektów
 * pola: brak
 * autor: <numer zdającego>
 ********************************************************/
class Figura
{
public:
    virtual double pole() const = 0;          // pure virtual -> every derived class MUST define it
    virtual string nazwa() const = 0;
    virtual ~Figura() {}
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
    Kolo(double r) : r(r) {}
    double pole() const override { return 3.14159265358979 * r * r; }   // (M_PI is not standard C++)
    string nazwa() const override { return "Kolo"; }
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
    double a, b;

public:
    Prostokat(double a, double b) : a(a), b(b) {}
    double pole() const override { return a * b; }
    string nazwa() const override { return "Prostokat"; }
};
// usage:  Figura *figury[] = { new Kolo(1), new Prostokat(2, 3) };
//         for (Figura *f : figury) { cout << f->nazwa() << " " << f->pole() << endl; delete f; }

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
    double x, y;

public:
    Punkt(double x = 0, double y = 0) : x(x), y(y) {}

    Punkt operator+(const Punkt &inny) const          // p1 + p2
    {
        return Punkt(x + inny.x, y + inny.y);
    }

    bool operator==(const Punkt &inny) const          // p1 == p2
    {
        return x == inny.x && y == inny.y;
    }

    friend ostream &operator<<(ostream &out, const Punkt &p)   // cout << p
    {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }
};

//@ CLS-08 | struct + array of structs: fill, display all, find the best by a field | <iostream> <string>
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
void wyswietlUczniow(const Uczen uczniowie[], int n)
{
    for (int i = 0; i < n; i++)
        cout << i + 1 << ". " << uczniowie[i].imie << " - " << uczniowie[i].srednia << endl;
}

/********************************************************
 * nazwa funkcji: najlepszyUczen
 * opis funkcji: wyszukuje ucznia z najwyższą średnią
 * parametry: uczniowie - tablica uczniów
 *            n - liczba uczniów (co najmniej 1)
 * zwracany typ i opis: int - indeks ucznia z najwyższą średnią
 * autor: <numer zdającego>
 ********************************************************/
int najlepszyUczen(const Uczen uczniowie[], int n)
{
    int najlepszy = 0;
    for (int i = 1; i < n; i++)
        if (uczniowie[i].srednia > uczniowie[najlepszy].srednia)
            najlepszy = i;
    return najlepszy;
}

// ====================== DEMO (don't copy) ======================
int main()
{
    srand(time(0));

    Osoba o("Ala", 17);
    o.setWiek(200);                         // rejected
    o.wyswietl();

    Notatka n1("Zakupy", "mleko"), n2("Szkola", "INF04");
    n2.wyswietl();
    cout << "notatek: " << Notatka::getLicznik() << endl;

    Tablica t(5);
    t.wyswietl();
    cout << "suma: " << t.suma() << ", rozmiar: " << t.getRozmiar() << endl;

    TablicaStala ts;
    ts.wypelnij(1, 100);
    ts.wyswietl();
    cout << "max: " << ts.maksimum() << endl;

    Pojazd *p = new Samochod("Fiat", 2003, 5);
    p->wyswietl();                          // Samochod version thanks to virtual
    delete p;

    Figura *figury[] = {new Kolo(1), new Prostokat(2, 3)};
    for (Figura *f : figury)
    {
        cout << f->nazwa() << ": " << f->pole() << endl;
        delete f;
    }

    Punkt a(1, 2), b(3, 4);
    cout << a << " + " << b << " = " << a + b << ", rowne? " << (a == b) << endl;

    Uczen klasa[] = {{"Ola", 4.5}, {"Jan", 5.2}, {"Ewa", 3.9}};
    wyswietlUczniow(klasa, 3);
    cout << "najlepszy: " << klasa[najlepszyUczen(klasa, 3)].imie << endl;
    return 0;
}
