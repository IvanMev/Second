#include <iostream>
#include "Triangle.h"
#include "Point.h"

int main() 
{
    setlocale(LC_ALL, "Russian");
    Point A, B, C;

    std::cout << "Введите координаты точки A (x y): ";
    std::cin >> A;

    std::cout << "Введите координаты точки B (x y): ";
    std::cin >> B;

    std::cout << "Введите координаты точки C (x y): ";
    std::cin >> C;

    Triangle triangle(A, B, C);

    Point H = triangle.findHeightPointH();
    std::cout << "Точка H (основание высоты из A на BC): " << H << std::endl;

    double area = triangle.area();
    std::cout << "Площадь треугольника: " << area << std::endl;
    return 0;
}