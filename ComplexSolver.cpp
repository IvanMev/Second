#include "ComplexSolver.h"
#include <cmath>

ComplexSolver::ComplexSolver(double a, double b, double c): QuadraticEquationSolver(a, b, c) {}

std::vector<ComplexNumber> ComplexSolver::solve() const 
{
    double d = discriminant();
    double a = get_a();
    double b = get_b();

    if (d >= 0) 
    {
        double sqrt_d = sqrt(d);
        double x1 = (-b + sqrt_d) / (2 * a);
        double x2 = (-b - sqrt_d) / (2 * a);
        return { ComplexNumber(x1), ComplexNumber(x2) };
    }
    else 
    {
        double sqrt_abs_d = sqrt(-d);
        ComplexNumber x1(-b / (2 * a), sqrt_abs_d / (2 * a));
        ComplexNumber x2(-b / (2 * a), -sqrt_abs_d / (2 * a));
        return { x1, x2 };
    }
}