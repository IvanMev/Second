#include "ComplexNumber.h"
#include <cmath>
#include <sstream>
#include <iomanip>

ComplexNumber::ComplexNumber(double real, double imaginary): real(real), imaginary(imaginary) {}

double ComplexNumber::get_real() const { return real; }
double ComplexNumber::get_imaginary() const { return imaginary; }

ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const 
{
    return ComplexNumber(real + other.real, imaginary + other.imaginary);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const 
{
    return ComplexNumber(real - other.real, imaginary - other.imaginary);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const 
{
    return ComplexNumber
    (
        real * other.real - imaginary * other.imaginary,
        real * other.imaginary + imaginary * other.real
    );
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& other) const 
{
    double denominator = other.real * other.real + other.imaginary * other.imaginary;
    if (denominator == 0) 
    {
        throw std::runtime_error("Division by zero");
    }
    return ComplexNumber
    (
        (real * other.real + imaginary * other.imaginary) / denominator,
        (imaginary * other.real - real * other.imaginary) / denominator
    );
}

bool ComplexNumber::operator==(const ComplexNumber& other) const 
{
    return real == other.real && imaginary == other.imaginary;
}

bool ComplexNumber::operator!=(const ComplexNumber& other) const 
{
    return !(*this == other);
}

ComplexNumber ComplexNumber::conjugate() const 
{
    return ComplexNumber(real, -imaginary);
}

double ComplexNumber::modulus() const 
{
    return sqrt(real * real + imaginary * imaginary);
}

double ComplexNumber::argument() const 
{
    return atan2(imaginary, real);
}

std::string ComplexNumber::to_algebraic() const 
{
    std::ostringstream oss;
    oss << real;
    if (imaginary >= 0) 
    {
        oss << " + " << imaginary << "i";
    }
    else 
    {
        oss << " - " << -imaginary << "i";
    }
    return oss.str();
}

std::string ComplexNumber::to_trigonometric() const 
{
    double r = modulus();
    double phi = argument();
    std::ostringstream oss;
    oss << r << "(cos(" << phi << ") + i*sin(" << phi << "))";
    return oss.str();
}

std::string ComplexNumber::to_exponential() const 
{
    double r = modulus();
    double phi = argument();
    std::ostringstream oss;
    oss << r << "e^(i*" << phi << ")";
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const ComplexNumber& num) 
{
    os << num.to_algebraic();
    return os;
}

std::istream& operator>>(std::istream& is, ComplexNumber& num) 
{
    is >> num.real >> num.imaginary;
    return is;
}