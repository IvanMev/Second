#include <iostream>
#include "C:\Users\Ivan\source\repos\LinkedListSolution\LinkedListSolution\LinkedList.h"

/**
 * @brief Основная функция демонстрации работы с LinkedList
 * @return Код завершения программы
 */
int main() 
{
   
    LinkedList list = { 1, 2, 3, 4, 5 };
    std::cout << "1. Initial list: " << list.toString() << std::endl;

    list << 0; 
    list >> 6;
    std::cout << "2. After adding elements: " << list.toString() << std::endl;

    list.insert(10, 3);
    std::cout << "3. After insert at position 3: " << list.toString() << std::endl;

    list.remove(4);
    std::cout << "4. After remove at position 4: " << list.toString() << std::endl;

    int searchValue = 3;
    std::cout << "5. List contains " << searchValue << ": " << (list.contains(searchValue) ? "Yes" : "No") << std::endl;

    list.modify(10, 100);
    std::cout << "6. After modify 10 to 100: " << list.toString() << std::endl;

    std::cout << "7. Element at index 2: " << list[2] << std::endl;

    std::cout << "8. Is list empty: " << (list.isEmpty() ? "Yes" : "No") << std::endl;

    LinkedList copy = list;
    std::cout << "9. Copy of list: " << copy.toString() << std::endl;

    LinkedList moved = std::move(list);
    std::cout << "10. Moved list: " << moved.toString() << std::endl;
    std::cout << "11. Original list after move: " << list.toString() << std::endl;

    return 0;
}