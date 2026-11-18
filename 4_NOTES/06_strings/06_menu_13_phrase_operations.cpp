// ======================================================================
// 13-option menu on one phrase: swap first/last word, replace characters, insert before
// a character, count a pattern (with its indexes), count letters/digits/others,
// toggle case, count upper/lower case - everything walks the string character by character
// Original file: unsorted/sprawdzian/stringpoprawa.cpp
// ======================================================================

#include <iostream>
#include <string>
#include <cctype>      // isalpha, isdigit, isupper, islower, toupper, tolower
using namespace std;

// Swaps the first word with the last one: "ala ma kota" -> "kota ma ala"
string zamienPierwszeZOstatnim(string tekst)
{
    int pierwszaSpacja = -1;
    int ostatniaSpacja = -1;
    for (int i = 0; i < tekst.length(); i++)
    {
        if (tekst[i] == ' ')
        {
            if (pierwszaSpacja == -1)
            {
                pierwszaSpacja = i;
            }
            ostatniaSpacja = i;
        }
    }
    if (pierwszaSpacja == -1)       // only one word - nothing to swap
    {
        return tekst;
    }
    string pierwsze = tekst.substr(0, pierwszaSpacja);
    string srodek = tekst.substr(pierwszaSpacja, ostatniaSpacja - pierwszaSpacja + 1);
    string ostatnie = tekst.substr(ostatniaSpacja + 1);
    return ostatnie + srodek + pierwsze;
}

// Replaces every character stary with nowy (e.g. ' ' -> '%', 'a' -> '@')
string zamienZnak(string tekst, char stary, char nowy)
{
    for (int i = 0; i < tekst.length(); i++)
    {
        if (tekst[i] == stary)
        {
            tekst[i] = nowy;
        }
    }
    return tekst;
}

// Adds '!' in front of every 'c' (builds a new string)
string wykrzyknikPrzedC(string tekst)
{
    string wynik = "";
    for (int i = 0; i < tekst.length(); i++)
    {
        if (tekst[i] == 'c')
        {
            wynik = wynik + '!';
        }
        wynik = wynik + tekst[i];
    }
    return wynik;
}

// Prints at which indexes wzorzec starts and how many times it occurs
void policzWystapienia(string tekst, string wzorzec)
{
    int ile = 0;
    int dlugoscWzorca = wzorzec.length();
    cout << "Indexes of occurrences: ";
    for (int i = 0; i + dlugoscWzorca <= tekst.length(); i++)
    {
        if (tekst.substr(i, dlugoscWzorca) == wzorzec)
        {
            cout << i << " ";
            ile++;
        }
    }
    cout << endl << "Number of occurrences of '" << wzorzec << "': " << ile << endl;
}

void policzRodzajeZnakow(string tekst)
{
    int litery = 0;
    int cyfry = 0;
    int inne = 0;
    for (int i = 0; i < tekst.length(); i++)
    {
        if (isalpha(tekst[i]))
        {
            litery++;
        }
        else if (isdigit(tekst[i]))
        {
            cyfry++;
        }
        else
        {
            inne++;
        }
    }
    cout << "Letters: " << litery << ", digits: " << cyfry << ", other: " << inne << endl;
}

// Big letters become small and small become big
string zamienWielkoscLiter(string tekst)
{
    for (int i = 0; i < tekst.length(); i++)
    {
        if (isupper(tekst[i]))
        {
            tekst[i] = tolower(tekst[i]);
        }
        else if (islower(tekst[i]))
        {
            tekst[i] = toupper(tekst[i]);
        }
    }
    return tekst;
}

void policzWielkieIMale(string tekst)
{
    int wielkie = 0;
    int male = 0;
    for (int i = 0; i < tekst.length(); i++)
    {
        if (isupper(tekst[i]))
        {
            wielkie++;
        }
        else if (islower(tekst[i]))
        {
            male++;
        }
    }
    cout << "Uppercase letters: " << wielkie << ", lowercase letters: " << male << endl;
}

int main()
{
    string oryginal;
    cout << "Enter a phrase: ";
    getline(cin, oryginal);
    string tekst = oryginal;

    int wybor;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Swap first word with last\n";
        cout << "2. Replace every space with '%'\n";
        cout << "3. Replace 'a' with '@'\n";
        cout << "4. Add '!' in front of every 'c'\n";
        cout << "5. Put the phrase into quotation marks\n";
        cout << "6. Add a '.' at the end\n";
        cout << "7. Count occurrences of a pattern\n";
        cout << "8. Count letters, digits and other characters\n";
        cout << "9. Toggle case of letters\n";
        cout << "10. Count uppercase and lowercase letters\n";
        cout << "11. Display current phrase\n";
        cout << "12. Reset to original phrase\n";
        cout << "13. Exit\n";
        cout << "Choose an option: ";
        cin >> wybor;
        cin.ignore();

        string wzorzec;
        switch (wybor)
        {
        case 1:
            tekst = zamienPierwszeZOstatnim(tekst);
            cout << tekst << endl;
            break;
        case 2:
            tekst = zamienZnak(tekst, ' ', '%');
            cout << tekst << endl;
            break;
        case 3:
            tekst = zamienZnak(tekst, 'a', '@');
            cout << tekst << endl;
            break;
        case 4:
            tekst = wykrzyknikPrzedC(tekst);
            cout << tekst << endl;
            break;
        case 5:
            tekst = "\"" + tekst + "\"";
            cout << tekst << endl;
            break;
        case 6:
            tekst = tekst + ".";
            cout << tekst << endl;
            break;
        case 7:
            cout << "Enter a pattern: ";
            getline(cin, wzorzec);
            policzWystapienia(tekst, wzorzec);
            break;
        case 8:
            policzRodzajeZnakow(tekst);
            break;
        case 9:
            tekst = zamienWielkoscLiter(tekst);
            cout << tekst << endl;
            break;
        case 10:
            policzWielkieIMale(tekst);
            break;
        case 11:
            cout << "Current phrase: " << tekst << endl;
            break;
        case 12:
            tekst = oryginal;
            cout << "Phrase has been reset to the original: " << tekst << endl;
            break;
        case 13:
            break;
        default:
            cout << "Invalid option. Please choose again.\n";
            break;
        }
    } while (wybor != 13);

    return 0;
}
// Pobierz napis dwuczłonowy.
// Zamień pierwszy człon z drugim.
// Policz małe litery.
// Sprawdź czy w podanym napisie występuje kombinacja "ab".
// Wyniki zaprezentuj w konsoli.
