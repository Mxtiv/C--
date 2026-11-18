// ======================================================================
// test: fill, insert, push_back, erase, print divisible by 3
// Original file: unsorted/Vectors/vectorSprawdzian.cpp
// FIXED - the bug was: wypelnij(vector<int> wekt) takes the vector BY VALUE so the vector stays empty - use vector<int>&
// ======================================================================

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void wypisz(vector<int> wektor)
{
    for (int i = 0; i < wektor.size(); i++)
    {
        cout << wektor[i] << " ";
    }
    cout << endl;
}

// & - adds elements to the caller's vector
void wypelnij(vector<int> &wektor, int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        wektor.push_back(rand() % 60 + 21);     // 21..80
    }
}

void wypiszPodzielnePrzez3(vector<int> wektor)
{
    for (int i = 0; i < wektor.size(); i++)
    {
        if (wektor[i] % 3 == 0)
        {
            cout << wektor[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    srand(time(0));
    vector<int> wektor;

    int rozmiar;
    do
    {
        cout << "Podaj rozmiar wektora (2-50): ";
        cin >> rozmiar;
    } while (rozmiar < 2 || rozmiar > 50);

    wypelnij(wektor, rozmiar);
    cout << "Zawartość wektora: ";
    wypisz(wektor);

    int liczba1;
    int liczba2;
    int liczba3;
    cout << "Podaj 3 liczby do wektora: ";
    cin >> liczba1 >> liczba2 >> liczba3;

    // insert at position 1 three times -> they end up in order liczba1, liczba2, liczba3
    wektor.insert(wektor.begin() + 1, liczba3);
    wektor.insert(wektor.begin() + 1, liczba2);
    wektor.insert(wektor.begin() + 1, liczba1);
    wektor.push_back(liczba1);
    wektor.push_back(liczba2);
    wektor.push_back(liczba3);
    wektor.erase(wektor.begin() + 3);           // remove the element at position 3

    cout << "Po zmianach: ";
    wypisz(wektor);
    cout << "Liczby podzielne przez 3: ";
    wypiszPodzielnePrzez3(wektor);

    return 0;
}
