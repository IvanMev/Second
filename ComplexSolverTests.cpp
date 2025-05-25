#include "C:\Users\Ivan\source\repos\Задание 3\Solver.Tests\stdafx.h"
#include "C:\Users\Ivan\source\repos\Задание 3\Задание 3\ComplexSolver.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SolverTests
{
    TEST_CLASS(ComplexSolverTests)
    {
    public:
        TEST_METHOD(TestComplexRoots)
        {
            ComplexSolver solver(1.0, 0.0, 1.0);
            auto roots = solver.solve();

            Assert::AreEqual(0.0, roots[0].get_real());
            Assert::AreEqual(1.0, roots[0].get_imaginary());
            Assert::AreEqual(0.0, roots[1].get_real());
            Assert::AreEqual(-1.0, roots[1].get_imaginary());
        }

        TEST_METHOD(TestRealRoots)
        {
            ComplexSolver solver(1.0, -5.0, 6.0);
            auto roots = solver.solve();

            Assert::AreEqual(3.0, roots[0].get_real());
            Assert::AreEqual(0.0, roots[0].get_imaginary());
            Assert::AreEqual(2.0, roots[1].get_real());
        }
    };
}