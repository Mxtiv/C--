// ======================================================================
// INF.04-01-21.06-SG (and INF.04-01-22.01-SG - the same task)
// Sortowanie przez wybieranie MALEJĄCO, tablica 10 liczb jest polem klasy,
// wczytywana z klawiatury; metoda szukająca maksimum jest PRYWATNA.
// Spec + key checklist: README.md in this folder.
// ======================================================================
#include <iostream>
using namespace std;

const int ROZMIAR = 10;

class Sortowanie
{
private:
    int tablica[ROZMIAR];

    /********************************************************
    * nazwa funkcji:  szukajMaksimum
    * parametry wejściowe: poczatek - indeks, od którego szukamy (do końca tablicy)
    * wartość zwracana: indeks największego elementu z zakresu poczatek..ROZMIAR-1
    * autor:          00000000000
    * ****************************************************/
    int szukajMaksimum(int poczatek)
    {
        int indeksMaksimum = poczatek;
        for (int i = poczatek + 1; i < ROZMIAR; i++)
        {
            if (tablica[i] > tablica[indeksMaksimum])
            {
                indeksMaksimum = i;
            }
        }
        return indeksMaksimum;
    }

public:
    void wczytaj()
    {
        cout << "Podaj " << ROZMIAR << " liczb calkowitych:" << endl;
        for (int i = 0; i < ROZMIAR; i++)
        {
            cout << "Liczba " << i + 1 << ": ";
            cin >> tablica[i];
        }
    }

    /********************************************************
    * nazwa funkcji:  sortuj
    * parametry wejściowe: brak
    * wartość zwracana: brak - sortuje pole tablica malejąco (przez wybieranie)
    * autor:          00000000000
    * ****************************************************/
    void sortuj()
    {
        for (int i = 0; i < ROZMIAR - 1; i++)
        {
            int indeksMaksimum = szukajMaksimum(i);   // 1. największy z i..koniec
            int pomocnicza = tablica[i];             // 2. zamiana z elementem na pozycji i
            tablica[i] = tablica[indeksMaksimum];
            tablica[indeksMaksimum] = pomocnicza;
        }
    }

    void wyswietl()
    {
        for (int i = 0; i < ROZMIAR; i++)
        {
            cout << tablica[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Sortowanie sortowanie;
    sortowanie.wczytaj();
    sortowanie.sortuj();
    cout << "Tablica posortowana malejaco: ";
    sortowanie.wyswietl();
    return 0;
}
