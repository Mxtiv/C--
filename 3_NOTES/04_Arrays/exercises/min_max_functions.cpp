// ======================================================================
// random fill + min/max element functions
// Original file: Arrays/Sort/sortowanie.cpp
// FIXED - the bug was: srand() inside the loop - call srand(time(0)) ONCE at the start of main
// ======================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
using namespace std;
void wypelnijLosowo(int tablica[], int rozmiarTablicy)
{
  for (int i = 0; i < rozmiarTablicy; i++) // wypełnianie tablicy losowymi cyframi.
  {
    tablica[i] = rand() % 10;    // wstawiamy do i-tego elementu losową cyfrę
  }
}
void wypiszTablice(int tablica[], int rozmiarTablicy)
{
  for (int i = 0; i < rozmiarTablicy; i++) // wypisujemy zawartość wszystkich elementów tablicy z przecinkami.
  {
    cout << tablica[i] << ", ";
  }
}
int elementMinimalny(int tablica[], int rozmiarTablicy)
{
  int min = tablica[0];
  for (int i = 0; i < rozmiarTablicy; i++) // wyszukujemy ekstremalne wartości z tablicy.
  {

    if (tablica[i] < min)
    {
      min = tablica[i];
    }
  }
  return min;
}
int elementMaxymalny(int tablica[], int rozmiarTablicy)
{
  {
  int max = tablica[0];
  for (int i = 0; i < rozmiarTablicy; i++) // wyszukujemy ekstremalne wartości z tablicy.
  {
    if (tablica[i] > max)
    {
      max = tablica[i];
    }
  }
  return max;
}
}
int main()
{
  srand(time(NULL)); // ONCE, at the start of main
  int liczby[10];
  wypelnijLosowo(liczby, 10);
  wypiszTablice(liczby, 10);
  cout << endl;
  cout<<elementMaxymalny(liczby,10)<<endl;
  cout<<elementMinimalny(liczby,10);
  return 0;
}