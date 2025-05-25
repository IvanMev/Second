#include "C:\Users\Ivan\source\repos\Задание 3\Solver.Tests\stdafx.h"
#include "C:\Users\Ivan\source\repos\Задание 3\Задание 3\SimpleSolver.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SolverTests
{
    TEST_CLASS(SimpleSolverTests)
    {
    public:
        TEST_METHOD(TestRealRoots)
        {
            SimpleSolver solver(1.0, -3.0, 2.0);
            auto roots = solver.solve();

            Assert::AreEqual(2, (int)roots.size());
            Assert::AreEqual(2.0, roots[0].get_real());
            Assert::AreEqual(1.0, roots[1].get_real());
        }

        TEST_METHOD(TestNoRealRootsThrows)
        {
            SimpleSolver solver(1.0, 0.0, 1.0);

            auto func = [&] { solver.solve(); };
            Assert::ExpectException<std::runtime_error>(func);
        }
    };
}