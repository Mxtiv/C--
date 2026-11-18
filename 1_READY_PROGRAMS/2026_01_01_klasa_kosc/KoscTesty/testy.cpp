// INF.04-01-26.01-SG part III - testy jednostkowe metody rzuc() (Visual Studio: Native Unit Test
// Project, Microsoft CppUnitTestFramework). Każdy przypadek testowy = osobna metoda.
#include "CppUnitTest.h"
#include "../Kosc/kosc.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KoscTesty
{
    TEST_CLASS(KoscTesty)
    {
    public:
        TEST_METHOD(Rzuc_KoscDostepna_WartoscWZakresieOd1Do6)
        {
            Kosc kosc;
            for (int i = 0; i < 1000; i++)          // many throws - every one must be 1..6
            {
                kosc.rzuc();
                Assert::IsTrue(kosc.liczbaOczek >= 1 && kosc.liczbaOczek <= 6);
            }
        }

        TEST_METHOD(Rzuc_KoscNiedostepna_WartoscBezZmian)
        {
            Kosc kosc(4);
            kosc.zablokuj();
            for (int i = 0; i < 100; i++)
            {
                kosc.rzuc();
                Assert::AreEqual(4, kosc.liczbaOczek);
            }
        }
    };
}
