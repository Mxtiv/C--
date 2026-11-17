// ======================================================================
// const size array, random 10-20, count divisible by 3, minimum
// Original file: unsorted/various/podzielneprzez333.cpp
// FIXED: srand() was called inside the loop - now called once at the start of main
// ======================================================================

#include <cstdlib>
#include <iostream>
#include <ctime>  
using namespace std;
void losowanie(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 11 + 10;
  }
}
void wypisz(const int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << ", ";
  }
}
int liczbaPodzielnychPrzezTrzy(int arr[], int size) {

  int liczbaPodzielnych{};

  for (int i = 0; i < size; i++) {
    if (arr[i] % 3 == 0) {
      liczbaPodzielnych++;
    }
  }
  return liczbaPodzielnych;

}
int elementMinimalny(int arr[], int size)
{
  int min = arr[0];
  for (int i = 0; i < size; i++)
  {

    if (arr[i] < min)
    {
      min = arr[i];
    }
  }
  return min;
}
int main() {
  srand(time(NULL)); // ONCE, at the start of main
  const int size = 11;
  int arr[size];
  losowanie(arr, size);
  wypisz(arr, size);
  cout << "\nIlosc liczb podzielnych przez 3: "
       << liczbaPodzielnychPrzezTrzy(arr, size);
  cout << "\nElement minimalny to: " << elementMinimalny(arr, size);
}