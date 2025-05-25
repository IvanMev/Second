#include "LinkedList.h"
#include <sstream>
#include <utility>

void LinkedList::copyFrom(const LinkedList& other) 
{
    Node** current = &head;
    for (Node* otherCurrent = other.head; otherCurrent; otherCurrent = otherCurrent->next) 
    {
        *current = new Node(otherCurrent->data);
        current = &(*current)->next;
    }
    size = other.size;
}

void LinkedList::moveFrom(LinkedList&& other) 
{
    head = other.head;
    size = other.size;
    other.head = nullptr;
    other.size = 0;
}

void LinkedList::clear() 
{
    while (head) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}

LinkedList::LinkedList(std::initializer_list<int> initList) : LinkedList() 
{
    for (auto it = rbegin(initList); it != rend(initList); ++it) 
    { 
        *this << *it;
    }
}

LinkedList::LinkedList(const LinkedList& other) : LinkedList() 
{
    copyFrom(other);
}

LinkedList::LinkedList(LinkedList&& other) noexcept : LinkedList() 
{
    moveFrom(std::move(other));
}

LinkedList& LinkedList::operator=(const LinkedList& other) 
{
    if (this != &other) 
    {
        clear();
        copyFrom(other);
    }
    return *this;
}

LinkedList& LinkedList::operator=(LinkedList&& other) noexcept 
{
    if (this != &other) 
    {
        clear();
        moveFrom(std::move(other));
    }
    return *this;
}

LinkedList& LinkedList::operator<<(int value) 
{
    head = new Node(value, head);
    ++size;
    return *this;
}

LinkedList& LinkedList::operator>>(int value) 
{
    Node** current = &head;
    while (*current) 
    {
        current = &(*current)->next;
    }
    *current = new Node(value);
    ++size;
    return *this;
}

void LinkedList::insert(int value, size_t position) 
{
    if (position > size) 
    {
        throw std::out_of_range("Position out of range");
    }

    Node** current = &head;
    for (size_t i = 0; i < position; ++i) 
    {
        current = &(*current)->next;
    }
    *current = new Node(value, *current);
    ++size;
}

void LinkedList::remove(size_t position) 
{
    if (position >= size)
    {
        throw std::out_of_range("Position out of range");
    }

    Node** current = &head;
    for (size_t i = 0; i < position; ++i) 
    {
        current = &(*current)->next;
    }
    Node* temp = *current;
    *current = temp->next;
    delete temp;
    --size;
}

bool LinkedList::contains(int value) const noexcept 
{
    for (Node* current = head; current; current = current->next) 
    {
        if (current->data == value) 
        {
            return true;
        }
    }
    return false;
}

void LinkedList::modify(int oldValue, int newValue) 
{
    for (Node* current = head; current; current = current->next) 
    {
        if (current->data == oldValue) 
        {
            current->data = newValue;
            return;
        }
    }
    throw std::runtime_error("Value not found in the list");
}

std::string LinkedList::toString() const 
{
    std::ostringstream oss;
    Node* current = head;
    while (current) 
    {
        oss << current->data;
        if (current->next) 
        {
            oss << " -> ";
        }
        current = current->next;
    }
    return oss.str();
}

int& LinkedList::operator[](size_t index) 
{
    if (index >= size) 
    {
        throw std::out_of_range("Index out of range");
    }
    Node* current = head;
    for (size_t i = 0; i < index; ++i) 
    {
        current = current->next;
    }
    return current->data;
}

const int& LinkedList::operator[](size_t index) const 
{
    if (index >= size) 
    {
        throw std::out_of_range("Index out of range");
    }
    Node* current = head;
    for (size_t i = 0; i < index; ++i) 
    {
        current = current->next;
    }
    return current->data;
}