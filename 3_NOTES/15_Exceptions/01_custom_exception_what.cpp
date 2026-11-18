// ======================================================================
// own exception class derived from std::exception - redefine what()
// Original file: unsorted/trycatch/exceptions/definition.cpp
// ======================================================================

/* Tak wyglada (w skrocie) klasa exception z biblioteki <exception>:
class exception
{
public:
    virtual const char* what() const noexcept;   // zwraca opis bledu
};
   Obsluga bledow przy pomocy klasy exception polega na napisaniu klasy
   pochodnej i zdefiniowaniu w niej na nowo metody what(). */

#include <iostream>
#include <exception>
using namespace std;

class MojWyjatek : public exception
{
public:
    // naglowek musi byc DOKLADNIE taki jak w klasie exception:
    // const = metoda nie zmienia obiektu, noexcept = sama nie rzuca wyjatkow
    // (to jedyne miejsce, gdzie const/noexcept sa potrzebne)
    const char* what() const noexcept
    {
        return "Moj wlasny wyjatek";
    }
};

int main()
{
    try
    {
        throw MojWyjatek();
    }
    catch (exception &e)          // wyjatki-klasy lapiemy przez referencje &
    {
        cout << "Zlapano wyjatek: " << e.what() << endl;
    }
    return 0;
}
