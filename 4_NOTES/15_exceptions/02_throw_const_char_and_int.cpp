// ======================================================================
// throw "text" -> catch(const char*), throw 18 -> catch(int)
// Original file: TryCatch/practice1.cpp
// ======================================================================

#include <iostream>
using namespace std;

int main()
{
    int wiek;

    cout << "Podaj swoj wiek: ";
    cin >> wiek;

    try
    {
        if (wiek < 0)
        {
            throw "Wiek nie moze byc ujemny!";      // tekst w " " ma typ const char*
        }
        if (wiek < 18)
        {
            throw 18;                               // int
        }
        cout << "Witaj w systemie dla doroslych!" << endl;   // pomijane, gdy cos rzucono wyzej
    }
    catch (const char* blad)
    {
        cout << "Blad: " << blad << endl;
    }
    catch (int limit)
    {
        cout << "Musisz miec przynajmniej " << limit << " lat." << endl;
    }

    return 0;
}
