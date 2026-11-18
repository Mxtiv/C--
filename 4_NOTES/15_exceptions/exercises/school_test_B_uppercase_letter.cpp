// ======================================================================
// test group B: cctype + exception / runtime_error / derived class
// Original file: TryCatch/test2.cpp
// ======================================================================

// Grupa B. Pobierz duza litere od uzytkownika: jezeli jest duza, to wypisz "JD".
// Jezeli litera jest mala - blad wyrzucany przez typ zmiennej.
// Jezeli jest cyfra - blad wyrzucany przy pomocy klasy exception.
// Jezeli jest znakiem interpunkcyjnym ( , . ; ) - blad wyrzucany przy pomocy klasy runtime_error.
// Jezeli nie jest litera ani cyfra ani znakiem interpunkcyjnym - blad wyrzucany przy pomocy klasy pochodnej od runtime_error.

#include <iostream>
#include <exception>
#include <stdexcept>
#include <cctype>
using namespace std;

// klasa pochodna od runtime_error: komunikat przekazujemy konstruktorowi klasy bazowej po dwukropku
class InnyZnak : public runtime_error
{
public:
    InnyZnak() : runtime_error("Nieprawidlowy znak!")
    {
    }
};

int main()
{
    char znak;
    cout << "Podaj duza litere: ";
    cin >> znak;

    try
    {
        if (isdigit(znak))
        {
            throw exception();                                     // sama klasa exception
        }
        if (znak == ',' || znak == '.' || znak == ';')
        {
            throw runtime_error("Nie podawaj znaku interpunkcyjnego!");
        }
        if (!isalpha(znak))
        {
            throw InnyZnak();                                      // klasa pochodna od runtime_error
        }
        if (islower(znak))
        {
            throw 1;                                               // typ zmiennej (int)
        }
        cout << "JD" << endl;
    }
    catch (int)
    {
        cout << "Podales mala litere!" << endl;
    }
    catch (runtime_error &e)          // lapie runtime_error i InnyZnak
    {
        cout << e.what() << endl;
    }
    catch (exception &e)              // na koncu - zostal tylko przypadek cyfry
    {
        cout << "Nie mozna podac cyfry!" << endl;
    }

    return 0;
}
