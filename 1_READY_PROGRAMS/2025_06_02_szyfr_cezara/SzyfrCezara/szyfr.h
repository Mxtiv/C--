// Deklaracja funkcji szyfrującej - dzięki osobnemu plikowi .h projekt testów może z niej korzystać.
#pragma once
#include <string>

std::string szyfruj(std::string tekst, int klucz);
