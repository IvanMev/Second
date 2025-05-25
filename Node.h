#pragma once

class Node 
{
public:
    int data;
    Node* next;

    Node();
    explicit Node(int value);
    Node(int value, Node* nextNode);
};