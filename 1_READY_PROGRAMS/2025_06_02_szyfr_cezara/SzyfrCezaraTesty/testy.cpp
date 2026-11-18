// INF.04-02-25.06-SG part III - testy jednostkowe (Visual Studio: Native Unit Test Project,
// biblioteka Microsoft CppUnitTestFramework). Jeden przypadek z tabeli 4 = jedna metoda testująca.
// Uruchomienie: Test -> Run All Tests (okno Test Explorer = zrzut test1.png).
#include "CppUnitTest.h"
#include "../SzyfrCezara/szyfr.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SzyfrCezaraTesty
{
    TEST_CLASS(SzyfrCezaraTesty)
    {
    public:
        TEST_METHOD(Szyfruj_KluczDodatniMniejszyOdAlfabetu_PrzesuwaLitery)
        {
            Assert::AreEqual(string("def"), szyfruj("abc", 3));
        }

        TEST_METHOD(Szyfruj_LiteryPozaAlfabetem_ZawijaNaPoczatek)
        {
            Assert::AreEqual(string("abc"), szyfruj("xyz", 3));
        }

        TEST_METHOD(Szyfruj_KluczUjemny_Odszyfrowuje)
        {
            Assert::AreEqual(string("abc"), szyfruj("def", -3));
        }

        TEST_METHOD(Szyfruj_KluczWiekszyNizDlugoscAlfabetu_DzialaJakModulo26)
        {
            Assert::AreEqual(string("def"), szyfruj("abc", 29));
        }

        TEST_METHOD(Szyfruj_SpacjaWTekscie_ZostajeBezZmian)
        {
            Assert::AreEqual(string("cd ef"), szyfruj("ab cd", 2));
        }
    };
}
