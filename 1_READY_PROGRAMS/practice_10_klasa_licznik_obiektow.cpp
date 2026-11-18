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
    /********************************************************
     * nazwa funkcji: Ksiazka (konstruktor bezparametrowy)
     * opis funkcji: ustawia wartości domyślne i nadaje kolejny numer
     * parametry: brak
     * zwracany typ i opis: brak
     * autor: <numer zdającego>
     ********************************************************/
    Ksiazka()
    {
        licznik++;
        numer = licznik;
        tytul = "brak";
        autor = "brak";
        rokWydania = 2000;
    }

    /********************************************************
     * nazwa funkcji: Ksiazka (konstruktor z parametrami)
     * opis funkcji: ustawia podane dane książki i nadaje kolejny numer
     * parametry: nowyTytul - tytuł książki
     *            nowyAutor - autor książki
     *            rok - rok wydania (sprawdzany przez setRokWydania)
     * zwracany typ i opis: brak
     * autor: <numer zdającego>
     ********************************************************/
    Ksiazka(string nowyTytul, string nowyAutor, int rok)
    {
        licznik++;
        numer = licznik;
        tytul = nowyTytul;
        autor = nowyAutor;
        rokWydania = 2000;
        setRokWydania(rok);
    }

    /********************************************************
     * nazwa funkcji: Ksiazka (konstruktor kopiujący)
     * opis funkcji: kopiuje dane innej książki; kopia to nowy obiekt, więc
     *               dostaje nowy numer
     * parametry: wzor - kopiowana książka
     * zwracany typ i opis: brak
     * autor: <numer zdającego>
     ********************************************************/
    Ksiazka(Ksiazka &wzor)
    {
        licznik++;
        numer = licznik;
        tytul = wzor.tytul;
        autor = wzor.autor;
        rokWydania = wzor.rokWydania;
    }

    string getTytul()
    {
        return tytul;
    }

    string getAutor()
    {
        return autor;
    }

    int getRokWydania()
    {
        return rokWydania;
    }

    void setTytul(string nowyTytul)
    {
        tytul = nowyTytul;
    }

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
    void wyswietl()
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

    Ksiazka *wszystkie[4] = {&k1, &k2, &k3, &k4};
    cout << "Lista ksiazek:" << endl;
    for (int i = 0; i < 4; i++)
    {
        wszystkie[i]->wyswietl();
    }

    cout << "Liczba utworzonych ksiazek: " << Ksiazka::getLicznik() << endl;
    return 0;
}
