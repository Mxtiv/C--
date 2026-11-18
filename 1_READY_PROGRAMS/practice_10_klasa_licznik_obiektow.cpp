// ======================================================================
// READY PROGRAM 10: class with a STATIC object counter and automatic id, private fields,
// getters/setters with validation, copy constructor, array of objects
// Based on: Classes/ksiazka.cpp + unsorted/calfmatthew/rectangle1.cpp
// Blocks used: CLS-01, CLS-02
// ======================================================================
//
// Treść zadania (wariant): Klasa Ksiazka z polami: tytuł, autor, rok wydania, numer
// (nadawany automatycznie) oraz statycznym licznikiem utworzonych obiektów.
// Konstruktor bezparametrowy ustawia wartości domyślne, konstruktor z parametrami -
// podane wartości. Rok wydania musi być z przedziału 1450..2025 (setter z kontrolą).
// Metoda wyświetlająca dane książki; metoda statyczna zwracająca liczbę obiektów.
// Program tworzy kilka książek (także kopię), wyświetla je i liczbę obiektów.

#include <iostream>
#include <string>
using namespace std;

/********************************************************
 * nazwa klasy: Ksiazka
 * opis klasy: przechowuje dane książki; zlicza utworzone obiekty i nadaje im numery
 * pola: licznik - (statyczne) liczba utworzonych obiektów
 *       numer - kolejny numer książki nadawany w konstruktorze
 *       tytul, autor - dane książki
 *       rokWydania - rok wydania (1450..2025)
 * autor: <numer zdającego>
 ********************************************************/
class Ksiazka
{
private:
    static int licznik;
    int numer;
    string tytul;
    string autor;
    int rokWydania;

public:
    Ksiazka() : Ksiazka("brak", "brak", 2000) {}                    // delegating constructor

    Ksiazka(string tytul, string autor, int rok) : tytul(tytul), autor(autor), rokWydania(2000)
    {
        licznik++;
        numer = licznik;
        setRokWydania(rok);
    }

    Ksiazka(const Ksiazka &wzor) : tytul(wzor.tytul), autor(wzor.autor), rokWydania(wzor.rokWydania)
    {
        licznik++;                     // a copy is a new object -> new number
        numer = licznik;
    }

    string getTytul() const { return tytul; }
    string getAutor() const { return autor; }
    int getRokWydania() const { return rokWydania; }
    void setTytul(const string &t) { tytul = t; }

    /********************************************************
     * nazwa funkcji: setRokWydania
     * opis funkcji: ustawia rok wydania, jeżeli należy do przedziału 1450..2025
     * parametry: rok - nowy rok wydania
     * zwracany typ i opis: bool - true, gdy rok był poprawny i został ustawiony
     * autor: <numer zdającego>
     ********************************************************/
    bool setRokWydania(int rok)
    {
        if (rok < 1450 || rok > 2025)
        {
            cout << "Niepoprawny rok wydania: " << rok << endl;
            return false;
        }
        rokWydania = rok;
        return true;
    }

    /********************************************************
     * nazwa funkcji: wyswietl
     * opis funkcji: wyświetla numer i dane książki
     * parametry: brak
     * zwracany typ i opis: brak
     * autor: <numer zdającego>
     ********************************************************/
    void wyswietl() const
    {
        cout << numer << ". \"" << tytul << "\", " << autor << ", " << rokWydania << endl;
    }

    /********************************************************
     * nazwa funkcji: getLicznik
     * opis funkcji: zwraca liczbę utworzonych obiektów klasy (metoda statyczna)
     * parametry: brak
     * zwracany typ i opis: int - liczba utworzonych książek
     * autor: <numer zdającego>
     ********************************************************/
    static int getLicznik()
    {
        return licznik;
    }
};

int Ksiazka::licznik = 0;              // static field definition

int main()
{
    Ksiazka k1("Pan Tadeusz", "Adam Mickiewicz", 1834);
    Ksiazka k2("Lalka", "Boleslaw Prus", 1890);
    Ksiazka k3;                        // default values
    Ksiazka k4 = k2;                   // copy constructor
    k4.setTytul("Lalka (wydanie 2)");
    k3.setRokWydania(3000);            // rejected by the setter

    Ksiazka *wszystkie[] = {&k1, &k2, &k3, &k4};
    cout << "Lista ksiazek:" << endl;
    for (Ksiazka *k : wszystkie)
        k->wyswietl();

    cout << "Liczba utworzonych ksiazek: " << Ksiazka::getLicznik() << endl;
    return 0;
}
