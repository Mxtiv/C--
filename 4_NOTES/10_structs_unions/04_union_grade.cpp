// ======================================================================
// union Ocena {int; double} - writing one member overwrites the other
// Original file: unsorted/Cstrings/nikodemst/TEMP) Cunie/main.cpp
// FIXED: `Ocena ocena = {ocena.ocena_c = 4}` used the variable inside its own initializer (undefined) -> {4}
// ======================================================================

#include <iostream>
using namespace std;

union Ocena                     // definicja unii o nazwie Ocena
{
    int ocenaCalkowita;         // ocena całkowita, np. 3
    double ocenaRzeczywista;    // ocena z połówkami, np. 3.5
};

int main()
{
    Ocena ocena = {4};                              // {4} trafia do PIERWSZEGO pola: ocenaCalkowita
    cout << sizeof(ocena) << endl;                  // rozmiar unii = rozmiar największego pola (8)
    cout << sizeof(ocena.ocenaCalkowita) << endl;   // 4
    cout << ocena.ocenaCalkowita << endl;           // 4

    ocena.ocenaRzeczywista = 3.5;                   // zapis do drugiego pola nadpisuje pierwsze
    cout << sizeof(ocena.ocenaRzeczywista) << endl; // 8
    cout << ocena.ocenaRzeczywista << endl;         // 3.5

    // Pole ocenaCalkowita nie ma już sensownej wartości (te same bajty zajęła ocena 3.5) -
    // nie odczytuj go. W strukturze obie wartości by zostały, ale struktura zajmuje więcej pamięci.
    return 0;
}
