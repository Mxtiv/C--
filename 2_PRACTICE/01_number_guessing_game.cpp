// ======================================================================
// READY PROGRAM 12: number guessing game - random 1..100, hints "za malo / za duzo",
// attempt counter, play again
// (new - a classic exam-style console game)
// Blocks used: RND-01, IO-01, IO-04
// ======================================================================
//
// Treść zadania: Program losuje liczbę z zakresu 1..100. Użytkownik zgaduje ją,
// a program po każdej próbie podpowiada "za mało" / "za dużo". Po trafieniu
// wyświetla liczbę prób i pyta, czy zagrać ponownie.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/********************************************************
 * nazwa funkcji: rozegrajRunde
 * opis funkcji: losuje liczbę 1..100 i prowadzi zgadywanie z podpowiedziami
 * parametry: brak
 * zwracany typ i opis: int - liczba prób potrzebnych do odgadnięcia
 * autor: <numer zdającego>
 ********************************************************/
int rozegrajRunde()
{
    int sekret = rand() % 100 + 1;
    int proby = 0;
    int strzal;
    do
    {
        do
        {
            cout << "Twoj strzal (1-100): ";
            cin >> strzal;
        } while (strzal < 1 || strzal > 100);

        proby++;
        if (strzal < sekret)
        {
            cout << "Za malo!" << endl;
        }
        else if (strzal > sekret)
        {
            cout << "Za duzo!" << endl;
        }
    } while (strzal != sekret);
    return proby;
}

int main()
{
    srand(time(0));
    cout << "Zgadnij liczbe od 1 do 100!" << endl;
    char odpowiedz;
    do
    {
        int proby = rozegrajRunde();
        cout << "Brawo! Zgadles w " << proby << " probach." << endl;

        do
        {
            cout << "Grasz jeszcze raz? (t/n): ";
            cin >> odpowiedz;
        } while (odpowiedz != 't' && odpowiedz != 'n');
    } while (odpowiedz == 't');
    return 0;
}
