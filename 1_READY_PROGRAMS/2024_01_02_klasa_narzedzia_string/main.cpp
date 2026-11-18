// ======================================================================
// INF.04-02-24.01-SG (and 24.01-02-AG, 24.01-01-SD, 24.06-01-SD) - klasa narzędziowa dla napisów:
// metody STATYCZNE i publiczne: liczba samogłosek "aąeęiouóyAĄEĘIOUÓY" oraz usuwanie
// powtórzeń znaków stojących obok siebie ("Abba;;;to" -> "Aba;to").
// Spec + key checklist: README.md in this folder.
// ======================================================================
#include <iostream>
#include <string>
#include <clocale>
using namespace std;

/************************************************
   klasa: NarzedziaNapisow
   opis: biblioteka narzędziowa (tylko metody statyczne) do przetwarzania napisów
   metody: liczSamogloski - zwraca liczbę samogłosek w napisie (int)
           usunPowtorzenia - zwraca napis bez powtórzeń sąsiednich znaków (string)
   autor: 00000000000
************************************************/
class NarzedziaNapisow
{
public:
    static int liczSamogloski(string tekst)
    {
        if (tekst.empty())                     // pusty napis -> 0 (string w C++ nie może być null)
        {
            return 0;
        }
        string samogloski = "aąeęiouóyAĄEĘIOUÓY";
        int licznik = 0;
        for (int i = 0; i < tekst.length(); i++)
        {
            for (int j = 0; j < samogloski.length(); j++)
            {
                if (tekst[i] == samogloski[j])
                {
                    licznik++;
                    break;
                }
            }
        }
        return licznik;
    }

    static string usunPowtorzenia(string tekst)
    {
        if (tekst.empty())                     // pusty napis -> pusty napis
        {
            return "";
        }
        string wynik = "";
        for (int i = 0; i < tekst.length(); i++)
        {
            // ostatni znak zawsze zostaje, inny zostaje tylko gdy następny jest inny
            if (i == tekst.length() - 1 || tekst[i] != tekst[i + 1])
            {
                wynik += tekst[i];
            }
        }
        return wynik;
    }
};

int main()
{
    setlocale(LC_ALL, "");                     // polskie znaki w konsoli

    string tekst;
    cout << "Podaj tekst: ";
    getline(cin, tekst);

    cout << "Liczba samoglosek: " << NarzedziaNapisow::liczSamogloski(tekst) << endl;
    cout << "Tekst bez powtorzen: " << NarzedziaNapisow::usunPowtorzenia(tekst) << endl;
    return 0;
}
