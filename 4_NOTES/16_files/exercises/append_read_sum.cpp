// ======================================================================
// append user numbers (ios::app), read them back, sum
// Original file: unsorted/sprawdzian/fstreamShroom.cpp
// FIXED - the bugs were: there was NO main() (program could not link); while(!eof())
// loops processed the last number twice -> now while (plik >> x)
// ======================================================================

#include <iostream>
#include <fstream>
using namespace std;

/********************************************************
 * nazwa funkcji: dopiszLiczby
 * opis funkcji: pyta o liczby i dopisuje je na koncu pliku plik.txt
 * parametry: brak
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void dopiszLiczby()
{
    ofstream plik("plik.txt", ios::app);       // app = dopisz, nie kasuj starej zawartosci
    int ile;
    do
    {
        cout << "Ile liczb dopisac (1-20): ";
        cin >> ile;
    } while (ile < 1 || ile > 20);

    for (int i = 0; i < ile; i++)
    {
        int liczba;
        cout << "Podaj liczbe: ";
        cin >> liczba;
        plik << liczba << " ";
    }
    plik.close();
}

/********************************************************
 * nazwa funkcji: wypiszISumuj
 * opis funkcji: wypisuje liczby z pliku plik.txt i liczy ich sume
 * parametry: brak
 * zwracany typ i opis: int - suma liczb z pliku
 * autor: <numer zdającego>
 ********************************************************/
int wypiszISumuj()
{
    ifstream plik("plik.txt");
    int liczba;
    int suma = 0;
    cout << "Liczby w pliku: ";
    while (plik >> liczba)
    {
        cout << liczba << " ";
        suma = suma + liczba;
    }
    cout << endl;
    plik.close();
    return suma;
}

int main()
{
    dopiszLiczby();
    int suma = wypiszISumuj();
    cout << "Suma: " << suma << endl;
    return 0;
}
