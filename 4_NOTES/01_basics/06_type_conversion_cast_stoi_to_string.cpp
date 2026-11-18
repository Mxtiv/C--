// ======================================================================
// ADDED (gap-fill): type conversions - implicit, casts,
// string <-> number (stoi, stod, to_string), char <-> int
// Not from your original repo - written to fill a missing topic.
// (For the old C functions atoi/atof/strtol see 07_c_string_to_number_atoi_atof_strtol.cpp)
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // ---------------- implicit (automatic) ----------------
    int i = 3.99;           // double -> int: fraction is CUT (not rounded) -> 3
    double d = 5;           // int -> double: 5.0
    cout << i << " " << d << endl;

    // ---------------- explicit casts ----------------
    int suma = 7;
    int ile = 2;
    double srednia1 = suma / ile;                       // 3   (int division happened first!)
    double srednia2 = (double)suma / ile;               // 3.5 <- write it like this
    double srednia3 = static_cast<double>(suma) / ile;  // 3.5 - the same, "C++ style" you may see in books
    cout << srednia1 << " " << srednia2 << " " << srednia3 << endl;

    int zaokraglona = (int)(3.7 + 0.5);                 // manual rounding -> 4
    cout << "rounded: " << zaokraglona << endl;

    // ---------------- string -> number ----------------
    string s1 = "123";
    string s2 = "3.75";
    string s3 = "42abc";
    int n1 = stoi(s1);          // string to int
    double n2 = stod(s2);       // string to double
    int n3 = stoi(s3);          // reads "42" and stops at the first non-digit
    cout << n1 + 1 << " " << n2 * 2 << " " << n3 << endl;
    // stoi("abc") throws std::invalid_argument -> see 15_exceptions

    // ---------------- number -> string ----------------
    string t = to_string(25) + " years, " + to_string(1.5);   // to_string(1.5) -> "1.500000"
    cout << t << endl;

    // ---------------- char <-> int ----------------
    char c = 'A';
    int kod = c;                // 65 (ASCII code)
    char zKodu = 66;            // 'B'
    char znakCyfry = '7';
    int cyfra = znakCyfry - '0';        // 7  <- THE way to turn a digit char into a number
    char zCyfry = 3 + '0';              // '3'
    cout << kod << " " << zKodu << " " << cyfra << " " << zCyfry << endl;

    // sum of digits of a string of digits (used in PESEL checks)
    string numer = "55030101193";
    int sumaCyfr = 0;
    for (int j = 0; j < numer.length(); j++)
    {
        sumaCyfr = sumaCyfr + (numer[j] - '0');
    }
    cout << "sum of digits: " << sumaCyfr << endl;

    // ---------------- bool ----------------
    bool b = 5;                 // any non-zero -> true
    int zBool = true;           // 1
    cout << b << " " << zBool << endl;

    return 0;
}
