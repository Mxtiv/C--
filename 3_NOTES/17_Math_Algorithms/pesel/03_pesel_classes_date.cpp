// ======================================================================
// class date + class pesel, .at(), method returns an object
// Original file: unsorted/calculations/peselBirthSex.cpp
// FIXED - the bugs were: checksum used ASCII codes (no - '0') and weight 2 instead of 3 -> it was
// always false; input check accepted letters (now: exactly 11 digits); string PESEL{0} -> string PESEL
// ======================================================================

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class date
{
public:
    unsigned short day{}, month{}, year{};
    date(short DAY, short MONTH, short YEAR)
    {
        day = DAY;
        month = MONTH;
        year = YEAR;
    }
    void print()
    {
        cout << " day: " << day << '\n';
        cout << " month: " << month << '\n';
        cout << " year: " << year << '\n';
    }
};
class pesel
{
private:
    string PESEL;

public:
    char sex()
    {
        if (PESEL.at(9) % 2 == 0)
            return 'K';
        else
            return 'M';
    }
    bool sumaKontrolna()
    {
        const int weights[10] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
        unsigned int sum{0}, sumModulo, R;
        for (int i = 0; i < 10; i++)
            sum += (PESEL.at(i) - '0') * weights[i];      // - '0' turns the char digit into a number
        sumModulo = sum % 10;
        if (sumModulo == 0)
            R = 0;
        else
            R = 10 - sumModulo;
        if (R == (unsigned)(PESEL.at(10) - '0'))
            return true;
        else
            return false;
    }
    date birthDay()
    {
        unsigned short day{}, month{}, year{};
        day = 10 * (static_cast<unsigned short>(PESEL.at(4)) - 48) + (static_cast<unsigned short>(PESEL.at(5)) - 48);
        if (static_cast<unsigned short>(PESEL.at(2)) - 48 > 1)
        {
            month = ((10 * (static_cast<unsigned short>(PESEL.at(2)) - 48)) + (static_cast<unsigned short>(PESEL.at(3)) - 48)) - 20;
            year = 2000 + (10 * (static_cast<unsigned short>(PESEL.at(0)) - 48) + (static_cast<unsigned short>(PESEL.at(1)) - 48));
        }
        else
        {
            month = 10 * (static_cast<unsigned short>(PESEL.at(2)) - 48) + (static_cast<unsigned short>(PESEL.at(3)) - 48);
            year = 1900 + (10 * (static_cast<unsigned short>(PESEL.at(0)) - 48) + (static_cast<unsigned short>(PESEL.at(1)) - 48));
        }
        return date(day, month, year);
    }
    pesel(string peselInsert)
    {
        PESEL = peselInsert;
    }
};
void displayPeselInformation(pesel person)
{
    cout << "Pesel information: \n"
         << "Gender: " << person.sex() << '\n'
         << "Birthday: \n";
    person.birthDay().print();
    cout << "Control Sum: " << (person.sumaKontrolna() ? "true" : "false");
}
int main()
{
    bool next = true;
    string n;
    while (next)
    {
        string p = "";
        bool flag = true;                  // true = "all characters are digits"
        cout << "Enter pesel to display person data:\n";
        cin >> p;
        for (char l : p)
        {
            if (!isdigit(l)) flag = false;
        }
        if (p.length() == 11 && flag == true)
        {
            pesel person1(p);
            displayPeselInformation(person1);
        }
        else
            cout << "Please enter valid pesel.";
        cout << "\nenter \"c\" to continue \n";
        cin >> n;
        if (n != "c")
            next = false;
    }

    return 0;
}