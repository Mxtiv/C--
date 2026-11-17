// ======================================================================
// ADDED (gap-fill): operator overloading (przeciazanie operatorow) on a Fraction class -
// + - * as members, == and < , unary -, +=, ++ (pre/post), << and >> as friends
// Not from your original repo - written to fill a missing topic.
// (Your 11_fraction_friend_functions.cpp does the same with named functions dodaj/pomnoz.)
// ======================================================================

#include <iostream>
#include <numeric>   // std::gcd (C++17)
using namespace std;

class Fraction
{
private:
    int num;   // licznik
    int den;   // mianownik

    void reduce()
    {
        int g = gcd(num, den);
        if (g != 0) { num /= g; den /= g; }
        if (den < 0) { num = -num; den = -den; }   // keep the sign in the numerator
    }

public:
    Fraction(int n = 0, int d = 1) : num(n), den(d == 0 ? 1 : d) { reduce(); }

    // a + b  -> called as a.operator+(b)
    Fraction operator+(const Fraction &o) const { return Fraction(num * o.den + o.num * den, den * o.den); }
    Fraction operator-(const Fraction &o) const { return Fraction(num * o.den - o.num * den, den * o.den); }
    Fraction operator*(const Fraction &o) const { return Fraction(num * o.num, den * o.den); }
    Fraction operator-() const { return Fraction(-num, den); }                 // unary minus

    Fraction &operator+=(const Fraction &o)      // returns *this by reference so a += b += c works
    {
        *this = *this + o;
        return *this;
    }

    bool operator==(const Fraction &o) const { return num == o.num && den == o.den; }
    bool operator<(const Fraction &o) const { return num * o.den < o.num * den; }

    Fraction &operator++()       { num += den; return *this; }                // ++f  (pre)
    Fraction operator++(int)     { Fraction old = *this; num += den; return old; }   // f++ (post, dummy int)

    // << and >> must be FRIENDS (left side is the stream, not our object)
    friend ostream &operator<<(ostream &out, const Fraction &f)
    {
        out << f.num << "/" << f.den;
        return out;
    }
    friend istream &operator>>(istream &in, Fraction &f)
    {
        char slash;
        in >> f.num >> slash >> f.den;   // input like 3/4
        if (f.den == 0) f.den = 1;
        f.reduce();
        return in;
    }
};

int main()
{
    Fraction a(1, 2), b(3, 4);
    cout << a << " + " << b << " = " << a + b << endl;   // 5/4
    cout << a << " - " << b << " = " << a - b << endl;   // -1/4
    cout << a << " * " << b << " = " << a * b << endl;   // 3/8
    cout << "-a = " << -a << endl;
    cout << boolalpha << "a < b ? " << (a < b) << ", a == 2/4 ? " << (a == Fraction(2, 4)) << endl;

    Fraction c = a;
    c += b;
    cout << "c += b -> " << c << endl;
    cout << "c++ prints " << c++ << ", now c = " << c << endl;
    cout << "++c prints " << ++c << endl;

    // Fraction in; cin >> in;  // type e.g. 6/8 -> stored as 3/4
    return 0;
}
