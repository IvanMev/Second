#pragma once
#include "Point.h"
#include <stdexcept>

class Triangle 
{
private:
    /**
    * @brief точка A
    */
    Point A;
    /**
    * @brief точка B
    */
    Point B;
    /**
    * @brief точка C
    */
    Point C;
    /**
    * @brief длина BC
    */
    double a;
    /**
    * @brief длина AC
    */
    double b;
    /**
    * @brief длина AB
    */
    double c;
public:
    /**
    * @brief конструктор с параметрами
    */
    Triangle(const Point& A, const Point& B, const Point& C);
    /**
    * @brief находит, проверяет и выводит высоту
    * @return находит, проверяет и выводит высоту
    */
    Point findHeightPointH() const;
    /**
    * @brief находит площадь треугольника
    * @return находит площадь треугольника
    */
    double area() const;
    /**
    * @brief перенаправление объекта в поток вывода
    * @param os - поток вывода
    * @param t - треугольник
    * @return результирующий поток вывода
    */
    friend std::ostream& operator<<(std::ostream& os, const Triangle& t);
};