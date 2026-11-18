// ======================================================================
// new Struct[n] with n from the user, fill in a loop, print with a function, delete[]
// Original file: unsorted/sprawdzian/arrayStructures.cpp
// ======================================================================

#include <iostream>
using namespace std;

struct OcenaStypendium
{
    int ocena;
    double stypendium;
};

void wyswietl(OcenaStypendium dane)
{
    cout << "Grade: " << dane.ocena << ", Wage: " << dane.stypendium << " zl" << endl;
}

int main()
{
    int ileUczniow;
    do
    {
        cout << "Enter the number of students: ";
        cin >> ileUczniow;
    } while (ileUczniow < 1);

    // array of structs with a size known only now
    OcenaStypendium *uczniowie = new OcenaStypendium[ileUczniow];

    for (int i = 0; i < ileUczniow; i++)
    {
        cout << "Enter grade for student " << i + 1 << ": ";
        cin >> uczniowie[i].ocena;
        cout << "Enter wage for student " << i + 1 << ": ";
        cin >> uczniowie[i].stypendium;
    }

    cout << "Grade and Wage Details:" << endl;
    for (int i = 0; i < ileUczniow; i++)
    {
        cout << "Student " << i + 1 << ": ";
        wyswietl(uczniowie[i]);
    }

    delete[] uczniowie;
    return 0;
}
