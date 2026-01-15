// upr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
class MinHeap
{
public:
    MinHeap(int size)
    {
        heapVect.resize(size);
    }
    bool isEmpty()
    {
        return size == 0;
    }
    int peek()
    {
        return heapVect[0];
    }
    void insert(int el)
    {
        heapVect.push_back(el);

        siftUp(size - 1);
        size++;
    }
    void pop()
    {
        std::swap(heapVect[0], heapVect[size - 1]);

        size--;

        siftDown(0);
    }
private:
    void siftDown(int index)
    {
        if (index >= size)
        {
            return;
        }

        int root = heapVect[index];

        int lIndex = 2 * index + 1;
        int rIndex = 2 * index + 2;
        int lchild = heapVect[lIndex];
        int rchild = heapVect[rIndex];

        int min = lchild < rchild ? lIndex : rIndex;

        if (root < heapVect[min])
        {
            std::swap(heapVect[index], heapVect[min]);
            siftDown(min);
        }
    }
    void siftUp(int idx)
    {
        int currentElement = heapVect[idx];
        int parentIdx = (idx - 1) / 2;
        int parentElement = heapVect[parentIdx];
        if (idx == 0)
        {
            return;
        }
        if (currentElement < parentElement)
        {
            std::swap(heapVect[idx], heapVect[parentIdx]);
            siftUp(parentIdx);
        }

    }
    std::vector<int> heapVect;
    int size;
};
int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


