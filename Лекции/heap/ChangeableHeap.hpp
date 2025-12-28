/******************************************************************
*  Sample code to the course "Data Structures And Algorithms", FMI
*
* An educational class, representing binary heap,
*  that supports changing the value of a given element.
*
* (cc) Petar Armyanov, FMI, 2025
*******************************************************************/
#pragma once

#ifndef _CHANGEABLE_HEAP_HEADER_INCLUDED__
#define _CHANGEABLE_HEAP_HEADER_INCLUDED__

#include <vector>
#include <cassert>

namespace fmi::sdp
{

class Heap
{
public:

    class elemProxy
    {
        friend class Heap;

        size_t index;
        int data;
        Heap& owner;

        elemProxy(Heap& who, size_t idx, int data) : index(idx), data(data), owner(who) {}
        elemProxy& operator=(const elemProxy&) = delete;

    public:
        operator int() { return data; }
        elemProxy& operator=(int data)
        {
            if (data > this->data) {
                this->data = data;
                owner.sift_down(index);
            }
            else {
                this->data = data;
                owner.sift_up(index);
            }
            return *this;
        }
    };

public:
    size_t size() const { return data.size(); }
    bool empty() const { return size() == 0; }

    int min()
    {
        assert("Try to get head of an empty heap!" && !empty());
        return *data[0];
    }

    int extract()
    {
        int val = min();
        delete(data.front());

        if (size() > 1) {
            elemProxy* last = data.back();
            data.pop_back();
            last->index = 0;
            data[0] = last;
            sift_down(0);
        }
        else {
            data.pop_back();
        }
        return val;
    }

    elemProxy& insert(int val)
    {
        elemProxy* elem = new elemProxy(*this, size(), val);
        data.push_back(elem);
        sift_up(size() - 1);
        return *elem;
    }

    void changeValue(elemProxy& elem, int newValue)
    {
        assert(&elem.owner == this);
        elem = newValue;
    }

    Heap() = default;

    Heap(const Heap& other) : Heap()
    {
        for (elemProxy* p : other.data)
            insert(p->data);
    }

    Heap& operator=(const Heap& other)
    {
        if (this != &other) {
            for (elemProxy* p : data)
                delete p;
            data.clear();

            for (elemProxy* p : other.data)
                insert(p->data);
        }
        return *this;
    }

    ~Heap()
    {
        for (elemProxy* p : data)
            delete p;
    }

private:
    size_t parent(size_t index)
    {
        return (index - 1) / 2;
    }
    size_t child(size_t index)
    {
        return index * 2 + 1;
    }

    void sift_up(size_t index)
    {
        size_t p;
        while (index > 0 && data[p = parent(index)]->data > data[index]->data) {
            std::swap(data[p], data[index]);
            data[p]->index = p;
            data[index]->index = index;
            index = p;
        }
    }

    void sift_down(size_t index)
    {
        while (index < size() / 2) {
            size_t ch = child(index);
            if (ch < size() - 1 && data[ch]->data > data[ch + 1]->data) ++ch;
            if (ch < size() && data[index]->data > data[ch]->data) {
                std::swap(data[index], data[ch]);
                data[ch]->index = ch;
                data[index]->index = index;
                index = ch;
            }
            else {
                break;
            }
        }
    }

private:
    std::vector<elemProxy*> data;
};

}

#endif _CHANGEABLE_HEAP_HEADER_INCLUDED__
