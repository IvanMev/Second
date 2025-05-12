#pragma once
#include <iostream>

/**
* @brief класс Точка
*/
class Point
{
private:
    /**
    * @brief координата x
    */
    double x;
    /**
    * @brief координата y
    */
    double y;

public:
    /**
    * @brief конструктор с параметрами
    */
    Point(double x = 0, double y = 0);

    /**
    * @brief получение координаты x
    */
    double getX() const;

    /**
    * @brief получение координаты y
    */
    double getY() const;

    /**
    * @brief оператор сравнения точек на равенство
    */
    bool operator==(const Point& other) const;

    /**
    * @brief оператор сравнения точек на неравенство
    */
    bool operator!=(const Point& other) const;

    /**
    * @brief перенаправление объекта в поток вывода
    * @param os - поток вывода
    * @param p - точка
    * @return результирующий поток вывода
    */
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    /**
    * @brief перенаправление объекта в поток вывода
    * @param is - поток вывода
    * @param p - точка
    * @return результирующий поток вывода
    */
    friend std::istream& operator>>(std::istream& is, Point& p);
};