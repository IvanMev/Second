#pragma once
#include "Point.h"
#include <stdexcept>

class Triangle 
{
private:
    Point A;
    Point B;
    Point C;

public:
    Triangle(const Point& A, const Point& B, const Point& C);
    Point findHeightPointH() const;
    double area() const;
    friend std::ostream& operator<<(std::ostream& os, const Triangle& t);
};