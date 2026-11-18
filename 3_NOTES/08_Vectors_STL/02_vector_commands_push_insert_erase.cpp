// ======================================================================
// push_back, insert(begin()+i), size, capacity, resize, erase one / range, clear, empty (Polish comments)
// Original file: unsorted/Vectors/vectorExampleCommands.cpp
// FIXED - the bug was: last lines read wektor[3] and *wektor.begin() on an EMPTY vector (undefined behaviour)
// ======================================================================

#include <iostream>
#include <vector>       // dołączenie do programu wektorów
using namespace std;

void wypisz(vector<int> wektor)
{
    for (int i = 0; i < wektor.size(); i++)
    {
        cout << "wektor[" << i << "] = " << wektor[i] << endl;
    }
}

int main()
{
    // Wektor ma nazwę "wektor", typ elementów to int,
    // rozmiar wynosi 5, ponieważ ma w sobie 5 elementów (10,20,30,40,50)
    vector<int> wektor = {10, 20, 30, 40, 50};
    wypisz(wektor);

    wektor.push_back(60);                           // dopisanie nowego elementu na końcu wektora
    cout << "Ostatni element (dopisany): " << wektor[wektor.size() - 1] << endl;

    wektor.insert(wektor.begin(), 0);               // wstawienie 0 przed pierwszym elementem
    cout << "Pierwszy element (dopisany): " << wektor[0] << endl;
    wypisz(wektor);

    cout << "size: " << wektor.size() << endl;          // ile elementów ma wektor
    cout << "capacity: " << wektor.capacity() << endl;  // na ile elementów jest zarezerwowana pamięć

    wektor.resize(5);                               // zmiana rozmiaru - elementy z końca są wyrzucane
    wektor.insert(wektor.begin() + 1, 1);           // wstawienie na pozycję 1 (drugi element)
    wektor.erase(wektor.begin() + 1);               // usunięcie elementu z pozycji 1
    wektor.erase(wektor.begin() + 1, wektor.end()); // usunięcie przedziału: od pozycji 1 do końca
    cout << "Po erase zostało: " << wektor.size() << " element(ów)" << endl;

    wektor.clear();                                 // usunięcie wszystkich elementów (size = 0)

    if (wektor.empty())                             // sprawdzenie, czy wektor jest pusty
    {
        cout << "Wektor jest pusty." << endl;
    }
    else
    {
        cout << "Wektor nie jest pusty." << endl;
    }

    // Zanim odczytasz wektor[3], sprawdź czy taki element istnieje
    if (wektor.size() > 3)
    {
        cout << "Element na pozycji 3: " << wektor[3] << endl;
    }
    else
    {
        cout << "Wektor ma mniej niz 4 elementy - wektor[3] nie istnieje" << endl;
    }

    return 0;
}
