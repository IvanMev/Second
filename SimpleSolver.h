#pragma once
#include "QuadraticEquationSolver.h"

/**
 * @class SimpleSolver
 * @brief Решатель квадратных уравнений, возвращающий только вещественные корни
 */
class SimpleSolver : public QuadraticEquationSolver 
{
public:
    /**
     * @brief Конструктор решателя
     * @param a Коэффициент при x²
     * @param b Коэффициент при x
     * @param c Свободный член
     */
    SimpleSolver(double a, double b, double c);

    /**
     * @brief Решение квадратного уравнения
     * @return Вектор комплексных корней (мнимая часть будет нулевой для вещественных корней)
     * @note Для отрицательного дискриминанта возвращает корни с нулевой мнимой частью
     */
    std::vector<ComplexNumber> solve() const override;
};