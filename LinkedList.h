#pragma once
#include <initializer_list>
#include <string>
#include <stdexcept>

/**
 * @brief Класс, реализующий линейный односвязный список целых чисел
 */
class LinkedList 
{
private:
    /**
     * @brief Вложенная структура узла списка
     */
    struct Node 
    {
        int data;    
        Node* next;   

        /**
         * @brief Конструктор узла
         * @param val Значение узла
         * @param nextNode Указатель на следующий узел (по умолчанию nullptr)
         */
        Node(int val, Node* nextNode = nullptr) : data(val), next(nextNode) {}
    };

    Node* head; 
    size_t size; 

    /**
     * @brief Вспомогательный метод для копирования данных из другого списка
     * @param other Список для копирования
     */
    void copyFrom(const LinkedList& other);

    /**
     * @brief Вспомогательный метод для перемещения данных из другого списка
     * @param other Список для перемещения (будет обнулен)
     */
    void moveFrom(LinkedList&& other);

    /**
     * @brief Вспомогательный метод для очистки списка
     */
    void clear();

public:
    /**
     * @brief Конструктор по умолчанию
     */
    LinkedList() noexcept : head(nullptr), size(0) {}

    /**
     * @brief Конструктор с инициализацией через список
     * @param initList Список инициализации значений
     */
    LinkedList(std::initializer_list<int> initList);

    /**
     * @brief Конструктор копирования
     * @param other Список для копирования
     */
    LinkedList(const LinkedList& other);

    /**
     * @brief Конструктор перемещения
     * @param other Список для перемещения
     */
    LinkedList(LinkedList&& other) noexcept;

    /**
     * @brief Деструктор
     */
    ~LinkedList() { clear(); }

    /**
     * @brief Оператор копирующего присваивания
     * @param other Список для копирования
     * @return Ссылка на текущий список
     */
    LinkedList& operator=(const LinkedList& other);

    /**
     * @brief Оператор перемещающего присваивания
     * @param other Список для перемещения
     * @return Ссылка на текущий список
     */
    LinkedList& operator=(LinkedList&& other) noexcept;

    /**
     * @brief Оператор вставки в начало списка
     * @param value Значение для вставки
     * @return Ссылка на текущий список
     */
    LinkedList& operator<<(int value);

    /**
     * @brief Оператор вставки в конец списка
     * @param value Значение для вставки
     * @return Ссылка на текущий список
     */
    LinkedList& operator>>(int value);

    /**
     * @brief Вставка элемента на указанную позицию
     * @param value Значение для вставки
     * @param position Позиция для вставки (0 - начало списка)
     * @throw std::out_of_range Если позиция превышает размер списка
     */
    void insert(int value, size_t position);

    /**
     * @brief Удаление элемента с указанной позиции
     * @param position Позиция для удаления
     * @throw std::out_of_range Если позиция превышает размер списка
     */
    void remove(size_t position);

    /**
     * @brief Проверка наличия значения в списке
     * @param value Значение для поиска
     * @return true если значение найдено, false в противном случае
     */
    bool contains(int value) const noexcept;

    /**
     * @brief Модификация значения в списке
     * @param oldValue Значение для замены
     * @param newValue Новое значение
     * @throw std::runtime_error Если старое значение не найдено
     */
    void modify(int oldValue, int newValue);

    /**
     * @brief Проверка списка на пустоту
     * @return true если список пуст, false в противном случае
     */
    bool isEmpty() const noexcept { return size == 0; }

    /**
     * @brief Преобразование списка в строку
     * @return Строковое представление списка (например "1 -> 2 -> 3")
     */
    std::string toString() const;

    /**
     * @brief Оператор доступа к элементу по индексу
     * @param index Индекс элемента
     * @return Ссылка на значение элемента
     * @throw std::out_of_range Если индекс превышает размер списка
     */
    int& operator[](size_t index);

    /**
     * @brief Константный оператор доступа к элементу по индексу
     * @param index Индекс элемента
     * @return Константная ссылка на значение элемента
     * @throw std::out_of_range Если индекс превышает размер списка
     */
    const int& operator[](size_t index) const;

    /**
     * @brief Получение текущего размера списка
     * @return Количество элементов в списке
     */
    size_t getSize() const noexcept { return size; }

    /**
     * @brief Получение указателя на голову списка (для тестирования)
     * @return Константный указатель на первый узел
     */
    const Node* getHead() const noexcept { return head; }
};