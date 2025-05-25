#pragma once
#include "QuadraticEquationSolver.h"

/**
 * @class ComplexSolver
 * @brief Реализация решателя квадратных уравнений с комплексными корнями
 *
 * Наследуется от QuadraticEquationSolver и реализует метод solve(),
 * возвращающий комплексные корни, включая случаи с отрицательным дискриминантом
 */
class ComplexSolver : public QuadraticEquationSolver 
{
public:
    /**
     * @brief Конструктор решателя
     * @param a Коэффициент при x²
     * @param b Коэффициент при x
     * @param c Свободный член
     */
    ComplexSolver(double a, double b, double c);

    /**
     * @brief Решает квадратное уравнение
     * @return Вектор из двух комплексных корней уравнения
     *
     * Для положительного дискриминанта возвращает два вещественных корня.
     * Для отрицательного - два комплексно-сопряженных корня.
     */
    std::vector<ComplexNumber> solve() const override;
};