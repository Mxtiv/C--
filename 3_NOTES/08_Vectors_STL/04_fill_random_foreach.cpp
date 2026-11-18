// ======================================================================
// fill a vector with random numbers; print it with an index loop and with "foreach" (range-for)
// Original file: unsorted/Vectors/vectorForEachLoop.cpp
// ======================================================================

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));             // inicjalizujemy generator liczb pseudolosowych (raz!)

    vector<int> wektor;         // pusty wektor liczb całkowitych

    for (int i = 0; i < 10; i++)
    {
        wektor.push_back(rand() % 100 + 1);   // losowa liczba 1..100 dopisana na końcu
    }

    // 1) zwykła pętla z indeksem - tak pisz na egzaminie
    cout << "Zawartosc wektora (indeks):" << endl;
    for (int i = 0; i < wektor.size(); i++)
    {
        cout << wektor[i] << " ";
    }
    cout << endl;

    // 2) pętla "foreach" (range-for) - temat tego pliku: element przyjmuje po kolei
    //    każdą wartość z wektora; nie ma indeksu
    cout << "Zawartosc wektora (foreach):" << endl;
    for (int element : wektor)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
