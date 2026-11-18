// Deklaracja funkcji szyfrującej - dzięki osobnemu plikowi .h projekt testów może z niej korzystać.
#pragma once
#include <string>
using namespace std;

string szyfruj(string tekst, int klucz);
