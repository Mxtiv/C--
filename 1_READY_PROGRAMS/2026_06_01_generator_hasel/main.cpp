// ======================================================================
// INF.04-01-26.06-SG - generator bezpiecznych haseł (12 znaków): 3 małe, 3 wielkie,
// 2 polskie litery (znaki.txt), 2 cyfry, 2 znaki specjalne !@#$%^&*()_+ - każdy znak
// w LOSOWYM miejscu hasła (tu: znaki losowane po kolei, potem wymieszane). Bez gotowych generatorów haseł.
// Spec + key checklist: README.md in this folder.
// ======================================================================
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <clocale>
using namespace std;

/*
nazwa funkcji:        generujHaslo
opis funkcji:         tworzy 12-znakowe hasło z 3 małych liter, 3 wielkich liter, 2 polskich
                      liter, 2 cyfr i 2 znaków specjalnych umieszczonych w losowych miejscach
parametry:            brak
zwracany typ i opis:  string - wygenerowane hasło
autor:                00000000000
*/
string generujHaslo()
{
    string male = "abcdefghijklmnopqrstuvwxyz";
    string wielkie = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string polskie[16] = { "ą", "ę", "ł", "ń", "ó", "ś", "ż", "ź",
                           "Ą", "Ę", "Ł", "Ń", "Ó", "Ś", "Ż", "Ź" };   // zbiór z pliku znaki.txt
    string cyfry = "0123456789";
    string specjalne = "!@#$%^&*()_+";

    string znaki[12];                          // 12 znaków hasła
    int n = 0;
    for (int i = 0; i < 3; i++)
    {
        znaki[n] = male[rand() % male.length()];
        n++;
    }
    for (int i = 0; i < 3; i++)
    {
        znaki[n] = wielkie[rand() % wielkie.length()];
        n++;
    }
    for (int i = 0; i < 2; i++)
    {
        znaki[n] = polskie[rand() % 16];
        n++;
    }
    for (int i = 0; i < 2; i++)
    {
        znaki[n] = cyfry[rand() % cyfry.length()];
        n++;
    }
    for (int i = 0; i < 2; i++)
    {
        znaki[n] = specjalne[rand() % specjalne.length()];
        n++;
    }

    // losowe miejsca: każdy znak zamieniamy z losowo wybranym innym
    for (int i = 0; i < 12; i++)
    {
        int j = rand() % 12;
        string pomocnicza = znaki[i];
        znaki[i] = znaki[j];
        znaki[j] = pomocnicza;
    }

    string haslo = "";
    for (int i = 0; i < 12; i++)
    {
        haslo += znaki[i];
    }
    return haslo;
}

int main()
{
    setlocale(LC_ALL, "");                     // polskie znaki w konsoli
    srand(time(0));

    cout << "Wygenerowane bezpieczne hasla:" << endl;
    for (int i = 1; i <= 5; i++)
    {
        string haslo = generujHaslo();
        cout << "Haslo " << i << ": " << haslo << endl;
    }
    return 0;
}
