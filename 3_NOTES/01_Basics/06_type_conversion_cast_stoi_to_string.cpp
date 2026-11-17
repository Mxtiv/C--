// ======================================================================
// ADDED (gap-fill): type conversions - implicit, static_cast, C-style cast,
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
    int sum = 7, count = 2;
    double avg1 = sum / count;                          // 3   (int division happened first!)
    double avg2 = static_cast<double>(sum) / count;     // 3.5 (C++ style, preferred)
    double avg3 = (double)sum / count;                  // 3.5 (C style)
    cout << avg1 << " " << avg2 << " " << avg3 << endl;

    int rounded = static_cast<int>(3.7 + 0.5);          // manual rounding -> 4
    cout << "rounded: " << rounded << endl;

    // ---------------- string -> number ----------------
    string s1 = "123", s2 = "3.75", s3 = "42abc";
    int n1 = stoi(s1);          // string to int
    double n2 = stod(s2);       // string to double
    float n3 = stof(s2);        // string to float
    long long n4 = stoll("9000000000");
    int n5 = stoi(s3);          // reads "42" and stops at the first non-digit
    cout << n1 + 1 << " " << n2 * 2 << " " << n3 << " " << n4 << " " << n5 << endl;
    // stoi("abc") throws std::invalid_argument -> see 15_Exceptions/06_standard_library_exceptions.cpp

    // ---------------- number -> string ----------------
    string t = to_string(25) + " years, " + to_string(1.5);   // to_string(1.5) -> "1.500000"
    cout << t << endl;

    // ---------------- char <-> int ----------------
    char c = 'A';
    int code = c;               // 65 (ASCII code)
    char back = 66;             // 'B'
    char digitChar = '7';
    int digit = digitChar - '0';        // 7  <- THE way to turn a digit char into a number
    char fromDigit = 3 + '0';           // '3'
    cout << code << " " << back << " " << digit << " " << fromDigit << endl;

    // sum of digits of a string of digits (used in PESEL checks)
    string number = "55030101193";
    int digitsSum = 0;
    for (char ch : number) digitsSum += ch - '0';
    cout << "sum of digits: " << digitsSum << endl;

    // ---------------- bool ----------------
    bool b = 5;                 // any non-zero -> true
    int fromBool = true;        // 1
    cout << b << " " << fromBool << endl;

    return 0;
}
