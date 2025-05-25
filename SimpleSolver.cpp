#include "SimpleSolver.h"
#include <stdexcept>
#include <cmath>


SimpleSolver::SimpleSolver(double a, double b, double c) : QuadraticEquationSolver(a, b, c) {}


std::vector<ComplexNumber> SimpleSolver::solve() const
{
    double d = discriminant();
    if (d < 0)
    {
        throw std::runtime_error("Дискриминант отрицательный, вещественных корней нет");
    }

    double a = get_a();
    double b = get_b();
    double sqrt_d = sqrt(d);
    double x1 = (-b + sqrt_d) / (2 * a);
    double x2 = (-b - sqrt_d) / (2 * a);

    return { ComplexNumber(x1), ComplexNumber(x2) };
}