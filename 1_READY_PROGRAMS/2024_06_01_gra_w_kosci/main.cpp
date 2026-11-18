// ======================================================================
// INF.04-01-24.06-SG (and INF.04-01-25.01-SD) - gra w kości:
// liczba kostek 3..10 (pytanie powtarzane), rzut = losowanie do tablicy, "Kostka i: x",
// punkty = suma oczek tych wartości, które wypadły co najmniej 2 razy, "Jeszcze raz? (t/n)".
// Funkcje bez zmiennych globalnych (dane przez parametry). Spec + key: README.md
// ======================================================================
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAKS_KOSTEK = 10;

int wczytajLiczbeKostek()
{
    int liczba;
    do
    {
        cout << "Ile kostek chcesz rzucic? (3 - 10): ";
        cin >> liczba;
        if (!cin)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            liczba = 0;
        }
    } while (liczba < 3 || liczba > 10);
    return liczba;
}

/************************************************
nazwa:      rzucKostkami
opis:       losuje liczbę oczek (1..6) dla każdej kostki i zapisuje wyniki do tablicy
parametry:  kostki - tablica na wyniki rzutów
            liczbaKostek - ile kostek rzucić
zwracany typ i opis: brak
autor:      00000000000
************************************************/
void rzucKostkami(int kostki[], int liczbaKostek)
{
    for (int i = 0; i < liczbaKostek; i++)
    {
        kostki[i] = rand() % 6 + 1;
    }
}

/************************************************
nazwa:      policzPunkty
opis:       sumuje oczka wartości, które zostały wylosowane co najmniej dwa razy
parametry:  kostki - tablica z wynikami rzutów
            liczbaKostek - liczba elementów tablicy
zwracany typ i opis: int - liczba zdobytych punktów
autor:      00000000000
************************************************/
int policzPunkty(const int kostki[], int liczbaKostek)
{
    int punkty = 0;
    for (int oczka = 1; oczka <= 6; oczka++)
    {
        int ile = 0;
        for (int i = 0; i < liczbaKostek; i++)
        {
            if (kostki[i] == oczka)
            {
                ile++;
            }
        }
        if (ile >= 2)
        {
            punkty = punkty + ile * oczka;
        }
    }
    return punkty;
}

int main()
{
    srand((unsigned)time(0));
    int kostki[MAKS_KOSTEK];
    int liczbaKostek = wczytajLiczbeKostek();
    char odpowiedz;
    do
    {
        rzucKostkami(kostki, liczbaKostek);
        for (int i = 0; i < liczbaKostek; i++)
        {
            cout << "Kostka " << i + 1 << ": " << kostki[i] << endl;
        }
        cout << "Liczba uzyskanych punktow: " << policzPunkty(kostki, liczbaKostek) << endl;

        cout << "Jeszcze raz? (t/n): ";
        cin >> odpowiedz;
    } while (odpowiedz == 't');
    return 0;
}
