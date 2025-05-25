#include "QuadraticEquationSolver.h"

QuadraticEquationSolver::QuadraticEquationSolver(double a, double b, double c) : a(a), b(b), c(c) 
{
    if (a == 0) 
    {
        throw std::invalid_argument("Coefficient 'a' cannot be zero");
    }
}

double QuadraticEquationSolver::discriminant() const 
{
    return b * b - 4 * a * c;
}