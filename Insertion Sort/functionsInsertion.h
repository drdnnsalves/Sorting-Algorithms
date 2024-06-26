#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

namespace InsertionFunctions {

    template<typename T>
    struct Node {
        T payload; 
        Node* ptrNext;
        Node* ptrPrev;
    };

    template<typename T>
    Node<T>* createNode(T value);

    template<typename T>
    void displayList(Node<T>*);

    template<typename T>
    void insertEnd(Node<T>**, T value);

    template<typename T>
    void deleteList(Node<T>**);

    template<typename T>
    void swapValue(Node<T>**, Node<T>**);

    template<typename T>
    void listInsertionSort(Node<T>**);

}

#include "functionsInsertion.cpp"

#endif