/******************************************************************
*  Sample code to the course "Data Structures And Algorithms", FMI
*
* An educational class, representing binary heap
*
* (cc) Petar Armyanov, FMI, 2025
*******************************************************************/
#pragma once

#ifndef _BINARY_HEAP_HEADER_INCLUDED__
#define _BINARY_HEAP_HEADER_INCLUDED__

#include <vector>
#include <cassert>

namespace fmi::sdp
{

template <typename Type>
class BinaryHeap
{
public:
    size_t size() const { return data.size(); }
    bool empty() const { return data.empty(); }

    const Type& min() const
    {
        assert("Try to get head of an empty heap!" && !empty());
        return data[0];
    }

    Type extract()
    {
        assert("Try to get head of an empty heap!" && !empty());
        Type res = std::move(data[0]);
        if (size() > 1) {
            data[0] = std::move(data.back());
            sift_down(data.data(), size()-1, 0);
        }
        data.pop_back();
        return res;
    }

    void insert(const Type& what)
    {
        data.push_back(what);
        sift_up(data.data(), size() - 1);
    }

#ifndef NDEBUG
    void print() {
        for (int i = 0; i < size(); ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
#endif // NDEBUG


private:
    static constexpr size_t parent(size_t index)
    {
        return index > 0 ? (index - 1) / 2 : 0;
    }

    static constexpr size_t first_child(size_t index, size_t size)
    {
        return index * 2 + 1 < size ? index * 2 + 1 : size;
    }

    static void sift_up(Type* data, size_t index)
    {
        size_t p = parent(index);
        Type val = std::move(data[index]);
        while (index > 0 && data[p] > val) {
            data[index] = std::move(data[p]);
            index = p;
            p = parent(index);
        }
        data[index] = std::move(val);
    }

    static void sift_down(Type* data, size_t size, size_t index)
    {
        size_t ch = first_child(index, size);
        Type val = std::move(data[index]);
        while (ch < size) {
            if (ch < size - 1 && data[ch] > data[ch + 1]) ch++;
            if (data[ch] < val) {
                data[index] = std::move(data[ch]);
                index = ch;
                ch = first_child(index, size);
            }
            else {
                break;
            }
        }
        data[index] = std::move(val);
    }

    template <typename Type> friend void heapSort(Type* data, size_t size);

private:
    std::vector<Type> data;
};

template <typename Type>
inline void heapSort(Type* data, size_t size)
{
    for (int pos = (int)size / 2 + 1; pos >= 0; --pos) {
        BinaryHeap<Type>::sift_down(data, size, pos);
    }    

    for (int pos = (int)size - 1; pos > 0; --pos) {
        std::swap(data[0], data[pos]);
        BinaryHeap<Type>::sift_down(data, pos, 0);
    }

    for (int head = 0, tail = (int)size - 1; head < tail; ++head, --tail)
        std::swap(data[head], data[tail]);
}

}

#endif _BINARY_HEAP_HEADER_INCLUDED__
