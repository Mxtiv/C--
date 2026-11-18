// ======================================================================
// INF.04-02-26.01-SG - quiz: klasa ABSTRAKCYJNA Pytanie (pola protected, konstruktor 2-arg.,
// czysto wirtualna sprawdzOdpowiedz(char)) + PytanieZamkniete (pola private, konstruktor
// 6-arg. wołający konstruktor bazowy, implementacja sprawdzania). Część III: próba
// utworzenia obiektu Pytanie (błąd kompilacji -> zrzut test1.png, potem w komentarz),
// dane i odpowiedź z klawiatury -> "Odpowiedz prawidlowa/nieprawidlowa" (test2.png).
// Spec + key checklist + Git steps: README.md in this folder.
// ======================================================================
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Pytanie
{
protected:                      // dostępne w klasie i w klasach potomnych
    string tresc;
    string nazwaPliku;
    bool poprawna;

public:
    Pytanie(string nowaTresc, string nowaNazwaPliku)
    {
        tresc = nowaTresc;
        nazwaPliku = nowaNazwaPliku;
        poprawna = false;
    }

    virtual bool sprawdzOdpowiedz(char odpowiedz) = 0;   // abstrakcyjna, bez implementacji
};

class PytanieZamkniete : public Pytanie
{
private:                        // niedostępne w klasach potomnych
    string odpowiedzA;
    string odpowiedzB;
    string odpowiedzC;
    char poprawnaOdpowiedz;

public:
    // ": Pytanie(...)" = wywołanie konstruktora klasy bazowej (tak to się zapisuje w C++)
    PytanieZamkniete(string nowaTresc, string nowaNazwaPliku, string a, string b, string c,
                     char poprawnaLitera) : Pytanie(nowaTresc, nowaNazwaPliku)
    {
        odpowiedzA = a;
        odpowiedzB = b;
        odpowiedzC = c;
        poprawnaOdpowiedz = poprawnaLitera;
    }

    /************************************************
    nazwa:      sprawdzOdpowiedz
    opis:       porównuje odpowiedź użytkownika z poprawną i zapisuje wynik w polu poprawna
    parametry:  odpowiedz - odpowiedź użytkownika: 'A', 'B' lub 'C'
    zwracany typ i opis: bool - true, gdy odpowiedź jest poprawna
    autor:      00000000000
    ************************************************/
    bool sprawdzOdpowiedz(char odpowiedz)
    {
        if (toupper(odpowiedz) == poprawnaOdpowiedz)
        {
            poprawna = true;
        }
        else
        {
            poprawna = false;
        }
        return poprawna;
    }
};

string wczytajLinie(string komunikat)
{
    string linia;
    cout << komunikat;
    getline(cin, linia);
    return linia;
}

int main()
{
    // part III, test 1: an abstract class cannot be instantiated. Uncomment, build, take the
    // screenshot test1.png of the error, then put it back into this comment:
    // Pytanie pytanie("Ktore to schronisko?", "zad1.jpg");

    string tresc = wczytajLinie("Podaj tresc pytania: ");
    string plik = wczytajLinie("Podaj nazwe pliku ze zdjeciem: ");
    string a = wczytajLinie("Podaj odpowiedz A: ");
    string b = wczytajLinie("Podaj odpowiedz B: ");
    string c = wczytajLinie("Podaj odpowiedz C: ");
    string poprawna = wczytajLinie("Ktora odpowiedz jest poprawna (A/B/C)? ");

    PytanieZamkniete pytanie(tresc, plik, a, b, c, (char)toupper(poprawna[0]));

    string odpowiedz = wczytajLinie("Twoja odpowiedz (A/B/C): ");
    if (pytanie.sprawdzOdpowiedz(odpowiedz[0]))
    {
        cout << "Odpowiedz prawidlowa" << endl;
    }
    else
    {
        cout << "Odpowiedz nieprawidlowa" << endl;
    }
    return 0;
}
