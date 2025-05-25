#include "C:\Users\Ivan\source\repos\Задание 3\Solver.Tests\stdafx.h""
#include "C:\Users\Ivan\source\repos\Задание 3\Задание 3\ComplexNumber.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ComplexNumberTests
{
    TEST_CLASS(BasicOperationsTests)
    {
    public:
        TEST_METHOD(TestAddition)
        {
            ComplexNumber a(1.5, 2.5);
            ComplexNumber b(3.5, 4.5);
            ComplexNumber c = a + b;

            Assert::AreEqual(5.0, c.get_real());
            Assert::AreEqual(7.0, c.get_imaginary());
        }

        TEST_METHOD(TestSubtraction)
        {
            ComplexNumber a(5.0, 5.0);
            ComplexNumber b(2.0, 3.0);
            ComplexNumber c = a - b;

            Assert::AreEqual(3.0, c.get_real());
            Assert::AreEqual(2.0, c.get_imaginary());
        }
    };
}