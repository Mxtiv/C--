// ======================================================================
// struct + prototypes
// Original file: unsorted/normalizacja/operacje.h
// ======================================================================

#ifndef OPERATIONS_H
#define OPERATIONS_H

struct Normalizator
{
    int cysterny;
    int wanny;
    int galony;
    int litry;
};

void policzLitry(int wszystkieLitry, Normalizator &wynik);    // & - funkcja wypelnia strukture wywolujacego
void wypiszInformacje(Normalizator wynik);

#endif
