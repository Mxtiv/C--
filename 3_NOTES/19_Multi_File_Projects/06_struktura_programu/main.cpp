// ======================================================================
// main using functions from operacje.h
// Original file: unsorted/strukturaProgramu/main.cpp
// ======================================================================

#include <iostream>
#include <string>
#include "operacje.h"
using namespace std;
int main(){
    double bok = 1;
    cout << "Bok kwadratu wynosi: " << poleKw(bok) << endl;
    cout << "Obwód kwadratu wynosi: " << obwodKw(bok) << endl;

    return 0;
    
}