// ======================================================================
// C-string -> number: atoi, atof, strtol
// Original file: Libraries/typeChange.cpp
// (For std::string use stoi / stod - see 06_type_conversion_cast_stoi_to_string.cpp)
// ======================================================================

#include <iostream>
#include <string>
#include <cstdlib>   // atoi, atof, strtol
using namespace std;

int main()
{
    char tekst1[] = "123.456";
    char tekst2[] = "789";
    char tekst3[] = "100000";

    double liczbaDouble = atof(tekst1);         // "123.456" -> 123.456
    int liczbaInt = atoi(tekst2);               // "789"     -> 789
    long liczbaLong = strtol(tekst3, NULL, 10); // 10 = base (decimal)

    cout << "atof:   " << liczbaDouble << endl;
    cout << "atoi:   " << liczbaInt << endl;
    cout << "strtol: " << liczbaLong << endl;

    // A std::string can be passed with .c_str():
    string s = "55";
    cout << "atoi(s.c_str()): " << atoi(s.c_str()) << endl;

    return 0;
}
