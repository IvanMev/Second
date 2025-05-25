#include <iostream>
#include "SimpleSolver.h"
#include "ComplexSolver.h"

/**
 * @brief Точка входа в программу
 * @return Код возврата
 *
 * Программа запрашивает коэффициенты квадратного уравнения и тип решателя,
 * затем выводит найденные корни уравнения.
 */
int main() 
{
    setlocale(LC_ALL, "Russian");

    double a, b, c;
    std::cout << "Введите коэффициенты квадратного уравнения (a b c): ";
    std::cin >> a >> b >> c;

    int choice;
    std::cout << "Выберите решатель (1 - простой, 2 - комплексный): ";
    std::cin >> choice;

    if (choice == 1) 
    {
        SimpleSolver solver(a, b, c);
        auto roots = solver.solve();
        std::cout << "Корни уравнения: " << roots[0] << ", " << roots[1] << std::endl;
    }
    else if (choice == 2) 
    {
        ComplexSolver solver(a, b, c);
        auto roots = solver.solve();
        std::cout << "Корни уравнения:\n";
        std::cout << "1: " << roots[0] << " (" << roots[0].to_exponential() << ")\n";
        std::cout << "2: " << roots[1] << " (" << roots[1].to_exponential() << ")\n";
    }
    else 
    {
        std::cout << "Неверный выбор решателя!" << std::endl;
    }

    return 0;
}