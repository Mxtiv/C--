// ======================================================================
// ADDED (gap-fill): the CORRECT way to split a class into .h + .cpp
// HEADER (.h): only DECLARATIONS. Protected by an include guard.
// Never #include a .cpp file.
// Build:  g++ main.cpp Prostokat.cpp -o program.exe
// ======================================================================

#ifndef PROSTOKAT_H        // include guard: if not defined yet...
#define PROSTOKAT_H        // ...define it, so a second #include is skipped
                           // (modern alternative: #pragma once)
#include <string>

class Prostokat
{
private:
    double a;
    double b;
    static int count;      // declared here, DEFINED in Prostokat.cpp

public:
    Prostokat(double a = 1, double b = 1);
    double pole() const;
    double obwod() const;
    std::string opis() const;   // no "using namespace std" in headers -> write std::
    static int ile();
};

// free function declaration (prototype)
bool czyKwadrat(const Prostokat &p, double a, double b);

#endif // PROSTOKAT_H
