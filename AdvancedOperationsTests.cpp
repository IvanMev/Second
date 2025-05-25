#include "C:\Users\Ivan\source\repos\Задание 3\Solver.Tests\stdafx.h"
#include "C:\Users\Ivan\source\repos\Задание 3\Задание 3\ComplexNumber.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ComplexNumberTests
{
    TEST_CLASS(AdvancedOperationsTests)
    {
    public:
        TEST_METHOD(TestModulus)
        {
            ComplexNumber num(3.0, 4.0);
            double mod = num.modulus();
            Assert::AreEqual(5.0, mod);
        }

        TEST_METHOD(TestConjugate)
        {
            ComplexNumber num(3.0, 4.0);
            ComplexNumber conj = num.conjugate();
            Assert::AreEqual(3.0, conj.get_real());
            Assert::AreEqual(-4.0, conj.get_imaginary());
        }
    };
}