#include <iostream>
#include "functionsInsertion.h"
#include <cstdlib>

using namespace std;

namespace InsertionFunctions {

    template<typename T>
    Node<T>* createNode(T value) {
        Node<T>* ptrTemp = (Node<T>*)malloc(sizeof(Node<T>));
        ptrTemp->payload = value;
        ptrTemp->ptrNext = nullptr;
        ptrTemp->ptrPrev = nullptr;
            
        return ptrTemp;
    }

    template<typename T>
    void displayList(Node<T>* ptrNode) {
        if (ptrNode == nullptr) {
            cout << "Empty list" << endl;
            return;
        }
        
        if (ptrNode->ptrPrev != nullptr) {
            cout << "The element is in the middle or at the end of the list." << endl;
            return;
        }
        
        Node<T>* ptrTemp = ptrNode;
        cout << "Payload: ";
        
        while (ptrTemp != nullptr) {
            cout <<  ptrTemp->payload << " ";
            ptrTemp = ptrTemp->ptrNext;
        }
        
        cout << endl;
    }


    template<typename T>
    void insertEnd(Node<T>** ptrHead, T value) {
        Node<T>* ptrNewNode = createNode(value);

        if (*ptrHead == nullptr) {
            *ptrHead = ptrNewNode; 
            return;
        }
        
        Node<T>* ptrTemp = *ptrHead;
        while (ptrTemp->ptrNext != nullptr)
            ptrTemp = ptrTemp->ptrNext;
        
        ptrNewNode->ptrPrev = ptrTemp;
        ptrTemp->ptrNext = ptrNewNode;
    }

    template<typename T>
    void deleteList(Node<T>** ptrHead) {
        Node<T>* ptrCurrent = *ptrHead;
        Node<T>* ptrNext = nullptr;

        while (ptrCurrent != nullptr) {
            ptrNext = ptrCurrent->ptrNext;
            free(ptrCurrent);
            ptrCurrent = ptrNext;
        }

        *ptrHead = nullptr;
    }

    template<typename T>
    void swapValue(Node<T>** ptrNode1, Node<T>** ptrNode2) {
        T tempPayload = (*ptrNode1)->payload;
        (*ptrNode1)->payload = (*ptrNode2)->payload;
        (*ptrNode2)->payload = tempPayload;
    }

    template<typename T>
    void listInsertionSort(Node<T>** ptrHead) {
        if (*ptrHead == nullptr || (*ptrHead)->ptrNext == nullptr)
            return;

        Node<T>* ptrSorted = nullptr;
        Node<T>* ptrCurrent = *ptrHead;  

        while (ptrCurrent != nullptr) {
            Node<T>* ptrNext = ptrCurrent->ptrNext; 
            if (ptrSorted == nullptr || ptrSorted->payload >= ptrCurrent->payload) {
                ptrCurrent->ptrNext = ptrSorted;
                ptrCurrent->ptrPrev = nullptr;
                if (ptrSorted != nullptr)
                    ptrSorted->ptrPrev = ptrCurrent;

                ptrSorted = ptrCurrent;
            } 
            else {
                Node<T>* ptrTemp = ptrSorted;
                while (ptrTemp->ptrNext != nullptr && ptrTemp->ptrNext->payload < ptrCurrent->payload)
                    ptrTemp = ptrTemp->ptrNext;

                ptrCurrent->ptrNext = ptrTemp->ptrNext;
                ptrCurrent->ptrPrev = ptrTemp;
                if (ptrTemp->ptrNext != nullptr)
                    ptrTemp->ptrNext->ptrPrev = ptrCurrent;

                ptrTemp->ptrNext = ptrCurrent;
            }
            ptrCurrent = ptrNext;
        }

        *ptrHead = ptrSorted;
    }

}