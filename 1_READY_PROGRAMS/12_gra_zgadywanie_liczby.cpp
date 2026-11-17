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
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

/********************************************************
 * nazwa funkcji: wczytajLiczbe
 * opis funkcji: wczytuje liczbę całkowitą z zakresu min..max, ponawiając pytanie przy błędzie
 * parametry: komunikat - tekst wyświetlany użytkownikowi
 *            min - najmniejsza dopuszczalna wartość
 *            max - największa dopuszczalna wartość
 * zwracany typ i opis: int - poprawna liczba
 * autor: <numer zdającego>
 ********************************************************/
int wczytajLiczbe(const string &komunikat, int min, int max)
{
    int liczba;
    while (true)
    {
        cout << komunikat;
        if (cin >> liczba && liczba >= min && liczba <= max)
            return liczba;
        if (cin.eof()) exit(0);
        cout << "Podaj liczbe od " << min << " do " << max << "." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

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
        strzal = wczytajLiczbe("Twoj strzal (1-100): ", 1, 100);
        proby++;
        if (strzal < sekret)
            cout << "Za malo!" << endl;
        else if (strzal > sekret)
            cout << "Za duzo!" << endl;
    } while (strzal != sekret);
    return proby;
}

/********************************************************
 * nazwa funkcji: zapytajTakNie
 * opis funkcji: zadaje pytanie i czeka na odpowiedź t lub n
 * parametry: pytanie - tekst pytania
 * zwracany typ i opis: bool - true dla 't', false dla 'n'
 * autor: <numer zdającego>
 ********************************************************/
bool zapytajTakNie(const string &pytanie)
{
    char odp;
    while (true)
    {
        cout << pytanie;
        if (!(cin >> odp)) return false;
        if (odp == 't' || odp == 'T') return true;
        if (odp == 'n' || odp == 'N') return false;
    }
}

int main()
{
    srand(time(0));
    cout << "Zgadnij liczbe od 1 do 100!" << endl;
    do
    {
        int proby = rozegrajRunde();
        cout << "Brawo! Zgadles w " << proby << " probach." << endl;
    } while (zapytajTakNie("Grasz jeszcze raz? (t/n): "));
    return 0;
}
