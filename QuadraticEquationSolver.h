#pragma once
#include <vector>
#include "ComplexNumber.h"

/**
 * @class QuadraticEquationSolver
 * @brief Абстрактный базовый класс для решения квадратных уравнений
 */
class QuadraticEquationSolver 
{
private:
    double a;
    double b;
    double c;

public:
    /**
     * @brief Конструктор квадратного уравнения
     * @param a Коэффициент при x²
     * @param b Коэффициент при x
     * @param c Свободный член
     */
    QuadraticEquationSolver(double a, double b, double c);

    /**
     * @brief Чисто виртуальный метод для решения уравнения
     * @return Вектор комплексных корней уравнения
     */
    virtual std::vector<ComplexNumber> solve() const = 0;

    /**
     * @brief Получить коэффициент a
     * @return Значение коэффициента a
     */
    double get_a() const { return a; }

    /**
     * @brief Получить коэффициент b
     * @return Значение коэффициента b
     */
    double get_b() const { return b; }

    /**
     * @brief Получить коэффициент c
     * @return Значение коэффициента c
     */
    double get_c() const { return c; }

    /**
     * @brief Вычислить дискриминант уравнения
     * @return Значение дискриминанта (b² - 4ac)
     */
    double discriminant() const;
};