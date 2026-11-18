// ======================================================================
// Teacher's model solution of the UML "Motor" task.
// UML: - = private, + = public. The diagram made kolor and czyLyse public,
// so they stay public here - at the exam do exactly what the diagram says.
// Original file: unsorted/diagramy/motorByMrKaczmarzyk.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class Motor
{
private:
    bool czyDwusuw;
    bool czyCross;
    int pojemnosc;
    double ilePaliwa;
    double pojemnoscBaku;

public:
    string kolor;
    bool czyLyse;

    Motor()
    {
        czyDwusuw = false;
        czyCross = false;
        pojemnosc = 0;
        ilePaliwa = 0;
        pojemnoscBaku = 20;
        kolor = "";
        czyLyse = false;
    }

    Motor(string nowyKolor, bool lyse)
    {
        czyDwusuw = false;
        czyCross = false;
        pojemnosc = 0;
        ilePaliwa = 0;
        pojemnoscBaku = 20;
        kolor = nowyKolor;
        czyLyse = lyse;
    }

    // tankujemy tyle, ile się zmieści
    void tankuj(double litry)
    {
        double wolneMiejsce = pojemnoscBaku - ilePaliwa;
        if (litry <= wolneMiejsce)
        {
            ilePaliwa = ilePaliwa + litry;
            cout << "Wlales " << litry << " l" << endl;
        }
        else
        {
            ilePaliwa = pojemnoscBaku;
            cout << "Wlales " << wolneMiejsce << " l, bo bak jest pelny" << endl;
        }
    }

    void setCzyDwusuw(bool dwusuw)
    {
        czyDwusuw = dwusuw;
    }

    void setCzyCross(bool cross)
    {
        czyCross = cross;
    }

    void setPojemnosc(int nowaPojemnosc)
    {
        pojemnosc = nowaPojemnosc;
    }

    bool getCzyDwusuw()
    {
        return czyDwusuw;
    }

    bool getCzyCross()
    {
        return czyCross;
    }

    int getPojemnosc()
    {
        return pojemnosc;
    }

    void czyTymPojade()
    {
        if (kolor == "czerwony" && czyDwusuw == true && czyLyse == false)
        {
            cout << "Moge jechac!" << endl;
        }
        else
        {
            cout << "Nie moge jechac" << endl;
        }
    }

    void czyNadajeSie(int oczekiwanaPojemnosc)
    {
        if (pojemnosc < oczekiwanaPojemnosc)
        {
            cout << "Nie nadaje sie!" << endl;
        }
        else
        {
            cout << "Nadaje sie!" << endl;
        }
    }
};

int main()
{
    Motor motor1("czerwony", false);
    motor1.setCzyDwusuw(true);
    motor1.setCzyCross(true);
    motor1.setPojemnosc(600);
    motor1.tankuj(15.5);
    motor1.tankuj(10);
    motor1.czyTymPojade();
    motor1.czyNadajeSie(500);

    return 0;
}
