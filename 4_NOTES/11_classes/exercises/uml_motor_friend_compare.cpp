// ======================================================================
// UML "Motor" + friend function porownaj(Motor, Motor) that reads the
// private fields of both motors and RETURNS the winner (a Motor object).
// (the plain UML solution is in uml_motor_teacher_solution.cpp)
// Original files: unsorted/diagramy/aureliamotor.cpp
//                 + unsorted/diagramy/motorFINALcompare.cpp (returning the winner) - merged
// FIXED - the bug was: setCzyDwusuw/setCzyCross assigned backwards (parameter = field)
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class Motor
{
private:
    string nazwa;
    bool czyDwusuw;
    bool czyCross;
    bool czyLyse;
    int pojemnosc;

public:
    Motor(string nowaNazwa, bool dwusuw, bool cross, bool lyse, int nowaPojemnosc)
    {
        nazwa = nowaNazwa;
        czyDwusuw = dwusuw;
        czyCross = cross;
        czyLyse = lyse;
        pojemnosc = nowaPojemnosc;
    }

    string getNazwa()
    {
        return nazwa;
    }

    friend Motor porownaj(Motor motor1, Motor motor2);
};

/********************************************************
 * nazwa funkcji: porownaj
 * opis funkcji: przyznaje punkty za pojemność, cross, dwusuw i nie łyse opony
 * parametry: motor1, motor2 - porównywane motory
 * zwracany typ i opis: Motor - motor z większą liczbą punktów (przy remisie motor1)
 ********************************************************/
Motor porownaj(Motor motor1, Motor motor2)
{
    int punkty1 = 0;
    int punkty2 = 0;

    if (motor1.pojemnosc > motor2.pojemnosc)       // pola private - wolno, bo friend
    {
        punkty1++;
    }
    else if (motor2.pojemnosc > motor1.pojemnosc)
    {
        punkty2++;
    }

    if (motor1.czyCross)
    {
        punkty1++;
    }
    if (motor2.czyCross)
    {
        punkty2++;
    }

    if (motor1.czyDwusuw)
    {
        punkty1++;
    }
    if (motor2.czyDwusuw)
    {
        punkty2++;
    }

    if (motor1.czyLyse == false)
    {
        punkty1++;
    }
    if (motor2.czyLyse == false)
    {
        punkty2++;
    }

    cout << motor1.nazwa << ": " << punkty1 << " pkt, " << motor2.nazwa << ": " << punkty2 << " pkt" << endl;

    if (punkty2 > punkty1)
    {
        return motor2;
    }
    return motor1;
}

int main()
{
    Motor motor1("Yamaha", true, true, false, 600);
    Motor motor2("Honda", false, false, true, 250);

    Motor zwyciezca = porownaj(motor1, motor2);
    cout << "Wygrywa: " << zwyciezca.getNazwa() << endl;

    return 0;
}
