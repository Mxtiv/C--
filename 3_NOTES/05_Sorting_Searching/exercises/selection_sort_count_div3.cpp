// ======================================================================
// selection sort + count divisible by 3
// Original file: unsorted/various/selectionsort.cpp
// FIXED - the bug was: DOES NOT COMPILE: podzielnePrzezTrzy(tablica) is missing the size argument
// ======================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void selectionSort(int tablica[]) {
    for (int i = 0; i < 9; i++) {
        int min = i;
        for (int j = i + 1; j < 10; j++) {
            if (tablica[j] < tablica[min]) {
                min = j;
            }
        }
        int temp = tablica[i];
        tablica[i] = tablica[min];
        tablica[min] = temp;
    }
}
int podzielnePrzezTrzy(int tabela[], int size) {
  int liczbaPodzielnych{};
  for (int i = 0; i < size; i++) {
    if (tabela[i] % 3 == 0)
      liczbaPodzielnych++;
  }
  return liczbaPodzielnych;
}

int main() {
    int tablica[10];

    srand(time(NULL));

    for (int i = 0; i < 10; ++i) {
        tablica[i] = rand() % 11 + 10;
    }

    // Wypisanie zawartości tablicy przed sortowaniem
    cout << "Zawartosc tablicy przed sortowaniem: ";
    for (int i = 0; i < 10; ++i) {
        cout << tablica[i] << " ";
    } 
    cout << endl;

    // Sortowanie tablicy
    selectionSort(tablica);

    // Wypisanie zawartości tablicy po sortowaniu
    cout << "Po sortowaniu: ";
    for (int i = 0; i < 10; ++i) cout << tablica[i] << " ";
    cout << endl << "Podzielnych przez 3: " << podzielnePrzezTrzy(tablica, 10) << endl;

    return 0;
}