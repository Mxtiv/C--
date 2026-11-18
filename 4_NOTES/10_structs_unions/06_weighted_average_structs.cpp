// ======================================================================
// weighted average; dynamic array of structs (grade + weight) passed to functions
// Original file: unsorted/various/sredniaWazona.cpp
// ======================================================================

#include <iostream>
using namespace std;

struct Ocena
{
    int ocena;
    int waga;
};

void wczytajOceny(Ocena oceny[], int ilosc)
{
    cout << "Podaj teraz oceny oraz ich wagi (ocena waga):" << endl;
    for (int i = 0; i < ilosc; i++)
    {
        cin >> oceny[i].ocena >> oceny[i].waga;
    }
}

// srednia wazona = suma (ocena * waga) / suma wag
double sredniaWazona(Ocena oceny[], int ilosc)
{
    double sumaOcen = 0;
    double sumaWag = 0;
    for (int i = 0; i < ilosc; i++)
    {
        sumaOcen = sumaOcen + oceny[i].ocena * oceny[i].waga;
        sumaWag = sumaWag + oceny[i].waga;
    }
    if (sumaWag == 0)
    {
        return 0;
    }
    return sumaOcen / sumaWag;
}

int main()
{
    int ilosc;
    do
    {
        cout << "Podaj ilosc ocen ktore uczen bedzie posiadac: ";
        cin >> ilosc;
    } while (ilosc < 1);

    Ocena *oceny = new Ocena[ilosc];    // dynamic array of structs
    wczytajOceny(oceny, ilosc);
    cout << "Srednia ocen wynosi: " << sredniaWazona(oceny, ilosc) << endl;

    delete[] oceny;
    return 0;
}
