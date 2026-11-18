// ======================================================================
// throw int/double/float/const char* + catch(...)
// Original file: TryCatch/task1.cpp
// ======================================================================

// Szukamy zawodnika na pozycje centra. Dobry zawodnik ma miedzy 210 a 220 cm.
// Pytamy czlowieka o wzrost. Lapiemy trzy komunikaty bledu: "za niski", "za wysoki", "alien".

#include <iostream>
using namespace std;

int main()
{
    try
    {
        int wzrost;
        cout << "Podaj wzrost: ";
        cin >> wzrost;

        if (wzrost < 210)
        {
            throw wzrost;             // int
        }
        if (wzrost >= 210 && wzrost <= 220)
        {
            throw 1.0;                // double
        }
        if (wzrost > 220 && wzrost <= 250)
        {
            throw 1.0f;               // float
        }
        if (wzrost > 250)
        {
            throw "alien";            // const char* - nie ma dla niego catch, wiec lapie catch(...)
        }
    }
    catch (int)
    {
        cout << "Za niski" << endl;
    }
    catch (double)
    {
        cout << "OK" << endl;
    }
    catch (float)
    {
        cout << "Za wysoki" << endl;
    }
    catch (...)
    {
        cout << "Alien" << endl;
    }

    return 0;
}
