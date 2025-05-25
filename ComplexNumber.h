#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <stdexcept>

/**
 * @class ComplexNumber
 * @brief Класс для работы с комплексными числами
 */
class ComplexNumber 
{
private:
    double real;        
    double imaginary;   

public:
    /**
     * @brief Конструктор комплексного числа
     * @param real Вещественная часть (по умолчанию 0.0)
     * @param imaginary Мнимая часть (по умолчанию 0.0)
     */
    ComplexNumber(double real = 0.0, double imaginary = 0.0);

    /**
     * @brief Получить вещественную часть
     * @return Вещественная часть числа
     */
    double get_real() const;

    /**
     * @brief Получить мнимую часть
     * @return Мнимая часть числа
     */
    double get_imaginary() const;

    /**
     * @brief Оператор сложения комплексных чисел
     * @param other Другое комплексное число
     * @return Результат сложения
     */
    ComplexNumber operator+(const ComplexNumber& other) const;

    /**
     * @brief Оператор вычитания комплексных чисел
     * @param other Другое комплексное число
     * @return Результат вычитания
     */
    ComplexNumber operator-(const ComplexNumber& other) const;

    /**
     * @brief Оператор умножения комплексных чисел
     * @param other Другое комплексное число
     * @return Результат умножения
     */
    ComplexNumber operator*(const ComplexNumber& other) const;

    /**
     * @brief Оператор деления комплексных чисел
     * @param other Другое комплексное число
     * @return Результат деления
     * @throw std::invalid_argument При делении на ноль
     */
    ComplexNumber operator/(const ComplexNumber& other) const;

    /**
     * @brief Оператор сравнения на равенство
     * @param other Другое комплексное число
     * @return true, если числа равны, иначе false
     */
    bool operator==(const ComplexNumber& other) const;

    /**
     * @brief Оператор сравнения на неравенство
     * @param other Другое комплексное число
     * @return true, если числа не равны, иначе false
     */
    bool operator!=(const ComplexNumber& other) const;

    /**
     * @brief Вычисление комплексно-сопряженного числа
     * @return Комплексно-сопряженное число
     */
    ComplexNumber conjugate() const;

    /**
     * @brief Вычисление модуля комплексного числа
     * @return Модуль числа
     */
    double modulus() const;

    /**
     * @brief Вычисление аргумента комплексного числа
     * @return Аргумент числа в радианах
     */
    double argument() const;

    /**
     * @brief Преобразование в алгебраическую форму строки
     * @return Строковое представление в алгебраической форме
     */
    std::string to_algebraic() const;

    /**
     * @brief Преобразование в тригонометрическую форму строки
     * @return Строковое представление в тригонометрической форме
     */
    std::string to_trigonometric() const;

    /**
     * @brief Преобразование в экспоненциальную форму строки
     * @return Строковое представление в экспоненциальной форме
     */
    std::string to_exponential() const;

    /**
     * @brief Оператор вывода в поток
     * @param os Выходной поток
     * @param num Комплексное число для вывода
     * @return Поток вывода
     */
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& num);

    /**
     * @brief Оператор ввода из потока
     * @param is Входной поток
     * @param num Комплексное число для ввода
     * @return Поток ввода
     */
    friend std::istream& operator>>(std::istream& is, ComplexNumber& num);
};