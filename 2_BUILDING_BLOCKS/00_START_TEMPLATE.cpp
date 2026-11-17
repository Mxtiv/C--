// ======================================================================
// START TEMPLATE - copy this WHOLE file when you begin a new task.
// It has the #includes you normally need, srand, and empty INF.04 comment
// boxes. Then paste blocks (ARR-.., SORT-.., NUM-.., STR-.., CLS-..) above main.
//
// Order inside the file:  includes -> constants -> classes/structs -> functions -> main
// ======================================================================

#include <iostream>   // cout, cin
#include <string>     // string, getline, stoi, to_string
#include <cstdlib>    // rand, srand
#include <ctime>      // time
#include <vector>     // vector (e.g. a function that returns many indexes)
#include <algorithm>  // sort, swap, min, max, reverse
#include <cmath>      // sqrt, pow, round
using namespace std;

const int ROZMIAR = 10;   // constants go here

/********************************************************
 * nazwa klasy: <NazwaKlasy>
 * opis klasy: <do czego służy klasa>
 * pola: <pole1> - <opis>
 *       <pole2> - <opis>
 * autor: <numer zdającego>
 ********************************************************/
class NazwaKlasy
{
private:
    int pole;

public:
    NazwaKlasy(int wartosc) : pole(wartosc) {}

    /********************************************************
     * nazwa funkcji: <nazwaMetody>
     * opis funkcji: <co robi metoda>
     * parametry: <parametr> - <opis>   (lub: brak)
     * zwracany typ i opis: <typ> - <opis>   (lub: brak)
     * autor: <numer zdającego>
     ********************************************************/
    int getPole() const
    {
        return pole;
    }
};

/********************************************************
 * nazwa funkcji: <nazwaFunkcji>
 * opis funkcji: <co robi funkcja>
 * parametry: <parametr1> - <opis>
 *            <parametr2> - <opis>
 * zwracany typ i opis: <typ> - <opis>
 * autor: <numer zdającego>
 ********************************************************/
void nazwaFunkcji()
{
}

int main()
{
    srand(time(0));           // ONCE, at the very start (only if you use rand)

    NazwaKlasy obiekt(5);
    cout << "Wartosc pola: " << obiekt.getPole() << endl;
    nazwaFunkcji();

    return 0;
}

// CHECKLIST before you hand in:
//  [ ] compiles with no errors              [ ] comment box above every required function
//  [ ] clear messages ("Podaj liczbe: ")    [ ] meaningful names (Polish or English)
//  [ ] loops use the size field/variable, never a hard-coded number
//  [ ] "returns" really returns (return / & parameters), "displays" really prints
//  [ ] new[] has a matching delete[] (destructor)   [ ] srand(time(0)) once
