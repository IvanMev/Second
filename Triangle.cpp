#include "Triangle.h"
#include <cmath>

Triangle::Triangle(const Point& A, const Point& B, const Point& C) :
    A(A), B(B), C(C),
    a(sqrt(pow(B.x - C.x, 2) + pow(B.y - C.y, 2))),
    b(sqrt(pow(A.x - C.x, 2) + pow(A.y - C.y, 2))),
    c(sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2)))
{
    if (A == B || B == C || C == A)
    {
        throw std::invalid_argument("Точки совпадают, невозможно построить треугольник");
    }

    if (a + b <= c || a + c <= b || b + c <= a)
    {
        throw std::invalid_argument("Точки не образуют треугольник (нарушено неравенство треугольника)");
    }
}

Point Triangle::findHeightPointH() const
{
    double BC_x = C.x - B.x;
    double BC_y = C.y - B.y;

    double BA_x = A.x - B.x;
    double BA_y = A.y - B.y;

    double dotProduct = BA_x * BC_x + BA_y * BC_y;
    double BCLengthSquared = BC_x * BC_x + BC_y * BC_y;

    double t = dotProduct / BCLengthSquared;

    return Point(B.x + t * BC_x, B.y + t * BC_y);
}

double Triangle::area() const
{
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

std::ostream& operator<<(std::ostream& os, const Triangle& t)
{
    os << "Triangle(A=" << t.A << ", B=" << t.B << ", C=" << t.C << ")";
    return os;
}