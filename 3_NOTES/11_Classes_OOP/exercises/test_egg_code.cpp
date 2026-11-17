// ======================================================================
// test: decode an egg code (kod jaja), e.g. 1PL12345678 or 1-PL-12345678
//   digit 0..3 = type of farming, 2 letters = country, rest = producer number
// Original file: Classes/spr/sprawdzianjajo/mainJajo.cpp
// FIXED - the original did not compile. Corrected: `=` -> `==`, compare chars with
// kod[1] == 'P' (no (string) cast), private setters are now called from setKod(),
// getTypChowuSlownie() is called with (), static counter is defined outside the class.
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class Jajo
{
private:
    string kod;
    int typChowu;              // 0..3, -1 = wrong
    string krajPochodzenia;
    string reszta;
    static int iloscJaj;

    void setTypChowu()
    {
        if (kod[0] >= '0' && kod[0] <= '3')
            typChowu = kod[0] - '0';    // char digit -> int
        else
            typChowu = -1;
    }

    void setKrajPochodzenia()
    {
        // skip an optional separator after the first digit: "1PL..." or "1-PL-..."
        size_t p = (kod.size() > 1 && (kod[1] == '-' || kod[1] == ' ')) ? 2 : 1;
        if (kod.size() < p + 2)
        {
            krajPochodzenia = "Brak kodu kraju";
            return;
        }
        if (kod[p] == 'P' && kod[p + 1] == 'L')
            krajPochodzenia = "Polska";
        else if (kod[p] == 'D' && kod[p + 1] == 'E')
            krajPochodzenia = "Niemcy";
        else
            krajPochodzenia = "Jajo z nieznanego kraju";
    }

    void setReszta()
    {
        size_t p = (kod.size() > 1 && (kod[1] == '-' || kod[1] == ' ')) ? 2 : 1;
        p += 2;                                         // skip the country letters
        if (p < kod.size() && (kod[p] == '-' || kod[p] == ' ')) p++;
        reszta = (p < kod.size()) ? kod.substr(p) : "";
    }

public:
    Jajo() : typChowu(-1) {}

    void setKod(const string &kodJaja)
    {
        kod = kodJaja;
        iloscJaj++;
        setTypChowu();            // private methods are used INSIDE the class
        setKrajPochodzenia();
        setReszta();
    }

    string getTypChowuSlownie() const
    {
        switch (typChowu)
        {
        case 0: return "Ekologiczne jajo.";
        case 1: return "Jajo z wolnego wybiegu.";
        case 2: return "Jajo sciolkowe.";
        case 3: return "Jajo klatkowe.";
        default: return "Zly numerek.";
        }
    }

    void print() const
    {
        cout << "Typ chowu twojego jaja to: " << getTypChowuSlownie() << "\n";
        cout << "Kraj pochodzenia twojego jaja to: " << krajPochodzenia << ".\n";
        cout << "Numer producenta: " << reszta << ".\n";
    }

    static int getIloscJaj() { return iloscJaj; }
};

int Jajo::iloscJaj = 0;            // static member definition

int main()
{
    string kodJaja;
    Jajo jajo1;
    cout << "Podaj kod jaja (np. 1PL12345678): ";
    cin >> kodJaja;
    jajo1.setKod(kodJaja);
    jajo1.print();
    cout << "Sprawdzonych jaj: " << Jajo::getIloscJaj() << endl;
    return 0;
}
