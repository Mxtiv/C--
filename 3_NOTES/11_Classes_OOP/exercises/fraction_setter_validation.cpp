// ======================================================================
// Setter with validation (mianownik != 0, repeated with do-while),
// overloaded getters (by reference / by value).
// Original file: unsorted/various/ulamekdemo.cpp
// ======================================================================

#include <iostream>
using namespace std;

class Ulamek
{
private:              // private jest domyślne w class, ale piszemy je dla czytelności
    int licznik;
    int mianownik;

public:
    Ulamek()
    {
        licznik = 0;
        mianownik = 1;
    }

    void setLicznik(int nowyLicznik)
    {
        licznik = nowyLicznik;
    }

    // setter z walidacją - zwraca true, gdy wartość była poprawna
    bool setMianownik(int nowyMianownik)
    {
        if (nowyMianownik == 0)
        {
            cout << "Mianownik nie moze byc 0!" << endl;
            return false;
        }
        mianownik = nowyMianownik;
        return true;
    }

    int getLicznik()
    {
        return licznik;
    }

    int getMianownik()                // getter przez wartość
    {
        return mianownik;
    }

    void getMianownik(int &wynik)     // getter przez parametr (przeciążony)
    {
        wynik = mianownik;
    }
};

int main()
{
    Ulamek ulamek;
    int licznik;
    int mianownik;

    cout << "Podaj licznik: ";
    cin >> licznik;
    ulamek.setLicznik(licznik);

    do
    {
        cout << "Podaj mianownik: ";
        cin >> mianownik;
    } while (ulamek.setMianownik(mianownik) == false);

    // ulamek.mianownik = 0;     // BŁĄD - pole prywatne

    int odczytany;
    ulamek.getMianownik(odczytany);
    cout << ulamek.getLicznik() << "/" << odczytany << endl;
    cout << "Mianownik (getter przez wartosc): " << ulamek.getMianownik() << endl;

    return 0;
}
