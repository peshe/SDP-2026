#include "Node.h"

#include <cassert>
#include <iostream>
#include <new>


template <typename T>
Node<T>* cloneReversed(const Node<T>* originalFirst, Node<T>*& /*in & out*/ clonedLast) {
    if (originalFirst == nullptr) {
        clonedLast = nullptr;
        return nullptr;
    }

    if (originalFirst->next == nullptr) {
        clonedLast = new Node<T>(originalFirst->value);
        return clonedLast;
    }

    Node<T>* result = cloneReversed(originalFirst->next, clonedLast);

    try {
        clonedLast->next = new Node<T>(originalFirst->value);
        clonedLast = clonedLast->next;
        return result;
    }
    catch (std::bad_alloc& e) {
        delete result;
        throw;
    }
}

template <typename T>
Node<T>* cloneReversed(const Node<T>* first) {
    Node<T>* clonedLast = nullptr;
    return cloneReversed(first, clonedLast);
}

int main () {
    Node<int>* l  = new Node<int>(1);
    l->add(2);
    l->add(3);
    l->add(4);
    l->add(5);

    Node<int>* clone = cloneReversed(l);
    l->print();
    clone->print();

    delete l;
    delete clone;
    return 0;
}
