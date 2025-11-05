/******************************************************************
*  Sample code to the course "Data Structures And Algorithms", FMI
*
* An educational class, representing singly linked list
*
* (cc) Petar Armyanov, FMI, 2025
*******************************************************************/
#pragma once

#ifndef _LINKED_LIST_HEADER_INCLUDED__
#define _LINKED_LIST_HEADER_INCLUDED__

#include <iostream>
#include <stdexcept>
#include <initializer_list>

template <typename DataType>
class LList
{
    struct Node
    {
        explicit Node(const DataType& val = DataType{}, Node* next = nullptr);
        DataType data;
        Node* next;
    };

public:
    // Life-cycle management
    LList() noexcept;
    LList(std::initializer_list<DataType> values);
    LList(const LList& other);
    LList(LList&& other) noexcept;
    LList& operator=(const LList& rhs);
    LList& operator=(LList&& other) noexcept;
    ~LList() noexcept;

    // Access to elements in the list
    //  only read-only access for simplicity
    const DataType& front() const;
    const DataType& back() const;
    const DataType& at(size_t pos) const; //! Aware the linear complexity!

    class iterator;

    iterator begin();
    iterator end() const;

    // State information
    bool empty() const;
    size_t size() const;

    // Inserting elements
    void push_front(const DataType& val);
    void push_back(const DataType& val);
    void push_atPos(size_t pos, const DataType& val);
    void push_after(const iterator& it, const DataType& val);

    // Erasing elements
    // Note: This methods do not return the removed value!
    void pop_front();
    void pop_end(); //! Aware the linear complexity!
    void pop_after(const iterator& it);
	DataType pop_atPos(size_t pos); //! Aware the linear complexity!


    // Additional useful operations
    void append(LList other);

    // Algorithms
    void reverse();
    void toSet();
    void sort();
    bool isSorted() const;

    // Higher order methods
    template<typename Func> void map(const Func& func);
    template<typename Func> void filter(const Func& predicate);

private:
    Node *head, *tail;
    size_t sz;

    void copy(const LList& other);
    void freeHeap(Node*& head);

    Node* merge(Node* left, Node* right);
    void split(Node* list, Node*& left, Node*& right);
    void split_no_stable(Node* list, Node*& left, Node*& right);
    Node* mergeSort(Node* list);
    Node* mergeSort(Node* list, size_t sz);

    void fixTail();
};

// Internal iterator calss
template<typename DataType>
class LList<DataType>::iterator
{
    friend class LList<DataType>;

    // Holds a pointer to cuurrent element and owner list
    LList<DataType>::Node* ptr;
    const LList<DataType>& owner;  // used to verify list side effect operations

    iterator(LList<DataType>::Node* ptr, const LList<DataType>& creator)
        : ptr(ptr), owner(creator) {}

public:
    bool valid() const { return ptr; }
    operator bool() const { return ptr; }

    DataType& operator*() { return ptr->data; }
    DataType* operator->() { return &ptr->data; }
    const DataType& operator*() const { return ptr->data; }
    const DataType* operator->() const { return &ptr->data; }

    iterator& operator++()
    {
        ptr = ptr->next;
        return *this;
    }
    iterator operator++(int)
    {
        iterator res = *this;
        ++*this;
        return res;
    }

    bool operator == (const iterator& rhs) const
    {
        return ptr == rhs.ptr;
    }
    bool operator != (const iterator& rhs) const
    {
        return !(*this == rhs);
    }
};

template<typename DataType>
inline LList<DataType>::Node::Node(const DataType& val, Node* next)
    :data(val), next(next)
{}

template<typename DataType>
inline void LList<DataType>::copy(const LList<DataType>& other)
{
    Node dummy;
    Node* iter = &dummy;
    Node* curr = other.head;

    // Initializing as empty, in case of exception
    tail = head = nullptr;
    sz = 0;

    while (curr) {
        try {
            iter->next = new Node(curr->data);
        }
        catch (...) {   //weak exception safety
            freeHeap(dummy.next);
            throw;
        }
        iter = iter->next;
        curr = curr->next;
    }
    head = dummy.next;
    tail = head ? iter : nullptr;
    sz = other.sz;
}

template<typename DataType>
inline void LList<DataType>::freeHeap(Node*& head)
{
    for (Node* iter = head; iter; ) {
        Node* const detach = iter;
        iter = iter->next;
        delete detach;
    }

    head = nullptr;
}

template<typename DataType>
inline LList<DataType>::LList() noexcept
    :head(nullptr), tail(nullptr), sz(0) {}

template<typename DataType>
inline LList<DataType>::LList(std::initializer_list<DataType> values)
    : LList()
{
    for (const DataType& val : values) {
        push_back(val);
    }
}

template<typename DataType>
inline LList<DataType>::LList(const LList& other)
    :LList()
{
    copy(other);
}

template<typename DataType>
inline LList<DataType>::LList(LList&& other) noexcept
    :LList()
{
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    std::swap(sz, other.sz);
}

template<typename DataType>
inline LList<DataType>& LList<DataType>::operator=(const LList<DataType>& rhs)
{
    if (this != &rhs) {
        *this = LList<DataType>(rhs);
    }
    return *this;
}

template<typename DataType>
inline LList<DataType>& LList<DataType>::operator=(LList<DataType>&& rhs) noexcept
{
    if (this != &rhs) {
        std::swap(head, rhs.head);
        std::swap(tail, rhs.tail);
        std::swap(sz, rhs.sz);
    }
    return *this;
}

template<typename DataType>
inline LList<DataType>::~LList() noexcept
{
    freeHeap(head);
}

template<typename DataType>
inline const DataType& LList<DataType>::at(size_t pos) const
{
    if (empty() || pos >= size()) {
        throw std::invalid_argument("Index out of bounds\n");
    }

    if (pos == size() - 1) {
        return tail->data;
    }

    const Node* iter = head;
    for (size_t i = 0; i < pos; ++i, iter = iter->next)
        ;
    return iter->data;
}

template<typename DataType>
inline const DataType& LList<DataType>::front() const
{
    return at(0);
}

template<typename DataType>
inline const DataType& LList<DataType>::back() const
{
    return at(sz - 1);
}

template<typename DataType>
inline size_t LList<DataType>::size() const
{
    return sz;
}

template<typename DataType>
inline typename LList<DataType>::iterator LList<DataType>::begin()
{
    return iterator(head, *this);
}

template<typename DataType>
inline typename LList<DataType>::iterator LList<DataType>::end() const
{
    return iterator(nullptr, *this);
}

template<typename DataType>
inline void LList<DataType>::push_atPos(size_t pos, const DataType& val)
{
    if (pos > size()) {
        throw std::invalid_argument("Index out of bounds\n");
    }

    if (pos == 0) {
        head = new Node(val, head);
        if (empty()) tail = head;
    }
    else if (pos == size()) {
        tail->next = new Node(val);
        tail = tail->next;
    }
    else {
        Node* iter = head;
        for (size_t i = 0; i < pos - 1; ++i, iter = iter->next)
            ;

        iter->next = new Node(val, iter->next);
    }

    ++sz;
}

template<typename DataType>
inline void LList<DataType>::push_after(const iterator& it, const DataType& val)
{
    if (&it.owner != this) {
        throw std::invalid_argument("Iterator from different list!\n");
    }
    if (!it.ptr) {
        throw std::invalid_argument("Bad iterator!\n");
    }
    it.ptr->next = new Node(val, it.ptr->next);
    if (it.ptr == tail) {
        tail = it.ptr->next;
    }
    ++sz;
}

template<typename DataType>
inline void LList<DataType>::push_front(const DataType& val)
{
    push_atPos(0, val);
}

template<typename DataType>
inline void LList<DataType>::push_back(const DataType& val)
{
    push_atPos(sz, val);
}

template<typename DataType>
inline void LList<DataType>::pop_after(const iterator& it)
{
    if (&it.owner != this) {
        throw std::invalid_argument("Iterator from different list!\n");
    }
    if (!it.ptr) {
        throw std::invalid_argument("Bad iterator!\n");
    }
    if (!it.ptr->next) return;// last element -> nothing to remove

    Node* toDelete = it.ptr->next;
    it.ptr->next = toDelete->next;
    if (tail == toDelete)
        tail = it.ptr;
    --sz;
    delete toDelete;
}

template<typename DataType>
inline DataType LList<DataType>::pop_atPos(size_t pos)
{
    if (empty() || pos >= sz) {
        throw std::invalid_argument("Index out of bounds\n");
    }

    Node* detach = head;

    if (pos == 0) {
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
    else {
        Node* iter = head;
        for (size_t i = 0; i < pos - 1; ++i, iter = iter->next)
            ;

        detach = iter->next;
        iter->next = detach->next;

        if (detach == tail) {
            tail = iter;
        }
    }
    --sz;
    DataType store = std::move(detach->data);
    delete detach;
    return store;
}

template<typename DataType>
inline void LList<DataType>::pop_front()
{
    pop_atPos(0);
}

template<typename DataType>
inline void LList<DataType>::pop_end()
{
    pop_atPos(sz - 1);
}

template<typename DataType>
inline bool LList<DataType>::empty() const
{
    return sz == 0;
}

template<typename DataType>
inline void LList<DataType>::append(LList other)
{
    if (tail) {
        tail->next = other.head;
    }
    else {
        head = other.head;
    }
    tail = other.head;
    sz += other.sz;
    other.head = other.tail = nullptr;
}

template<typename DataType>
inline void LList<DataType>::reverse()
{
    if (size() < 2) {
        return;
    }

    Node* curr = head;
    Node* perv = nullptr;
    Node* next = nullptr;
    tail = head;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = perv;
        perv = curr;
        curr = next;
    }

    head = perv;
}

template<typename DataType>
inline void LList<DataType>::toSet()
{
    Node* slow, * fast, * detach;
    slow = head;
    while (slow && slow->next) {
        fast = slow;
        while (fast->next) {
            if (slow->data == fast->next->data) {
                detach = fast->next;
                fast->next = detach->next;
                --sz;
                delete detach;
            }
            else {
                fast = fast->next;
            }
        }
        slow = slow->next;
    }
    tail = slow;
}

template<typename DataType>
inline bool LList<DataType>::isSorted() const
{
    if (sz < 3) return true;

    Node* iter = head;
    while (iter->next && iter->data == iter->next->data) {
        iter = iter->next;
    }
    if (!iter->next) return true;

    bool asc = iter->data < iter->next->data;
    while (iter->next) {
        if (!(iter->data == iter->next->data) &&
            ((iter->data < iter->next->data) != asc)) {
            return false;
        }
        iter = iter->next;
    }
    return true;
}

template<typename DataType>
inline void LList<DataType>::sort()
{
    head = mergeSort(head);
    fixTail();
}

template<typename DataType>
inline void LList<DataType>::split_no_stable(Node* list, Node*& left, Node*& right)
{
    Node dummyLeft;
    Node dummyRight;
    Node* iter = list;
    Node* end_left = &dummyLeft;
    Node* end_right = &dummyRight;

    bool swithToLeft = true;
    while (iter) {
        if (swithToLeft) {
            end_left->next = iter;
            end_left = end_left->next;
            swithToLeft = false;
        }
        else {
            end_right->next = iter;
            end_right = end_right->next;
            swithToLeft = true;
        }
        iter = iter->next;
    }

    end_left->next = nullptr;
    end_right->next = nullptr;

    left = dummyLeft.next;
    right = dummyRight.next;
}

template<typename DataType>
inline void LList<DataType>::split(Node* list, Node*& left, Node*& right)
{
    if (!list) return;
    left = list;

    Node* fast = list->next, *slow = list;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    right = slow->next;
    slow->next = nullptr;
}

template<typename DataType>
inline typename LList<DataType>::Node* LList<DataType>::merge(Node* left, Node* right)
{
    Node merged;
    Node* curr = &merged;
    while (left && right) {
        if (left->data < right->data) {
            curr->next = left;
            left = left->next;
        }
        else {
            curr->next = right;
            right = right->next;
        }
        curr = curr->next;
    }
    curr->next = left ? left : right;
    return merged.next;
}

template<typename DataType>
inline typename LList<DataType>::Node* LList<DataType>::mergeSort(Node* list, size_t size)
{
    if (!list || !list->next) {
        return list;
    }
    Node* left = nullptr, * right = nullptr;
    split(list, left, right, size);
    return merge(mergeSort(left, size / 2 + size % 2), mergeSort(right, size / 2));
}

template<typename DataType>
inline typename LList<DataType>::Node* LList<DataType>::mergeSort(Node* list)
{
    if (!list || !list->next) {
        return list;
    }

    Node* left = nullptr, * right = nullptr;
    split(list, left, right);
    return merge(mergeSort(left), mergeSort(right));
}

template<typename DataType>
inline void LList<DataType>::fixTail()
{
    if (!head) {
        tail = head;
        return;
    }
    Node* iterator;
    for (iterator = head; iterator->next; iterator = iterator->next)
        ;
    tail = iterator;
}

template<typename DataType>
template<typename Func>
inline void LList<DataType>::map(const Func& func)
{
    for (Node* iterator = head; iterator; iterator = iterator->next)
        func(iterator->data);
}

template<typename DataType>
template<typename Func>
inline void LList<DataType>::filter(const Func& predicate)
{
    Node dummy;
    Node* current = &dummy;
    Node* toDelete = nullptr;

    for (Node* iterator = head; iterator; iterator = iterator->next) {
        delete toDelete;
        current->next = iterator;
        if (predicate(iterator->data)) {
            current = current->next;
            toDelete = nullptr;
        }
        else {
            toDelete = iterator;
            --sz;
        }
    }
    if (sz) {
        head = dummy.next;
        tail = current;
    }
    else {
        head = tail = nullptr;
    }
}

#endif //#ifndef _LINKED_LIST_HEADER_INCLUDED__
