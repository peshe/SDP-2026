// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <vector>

class MyCoolListIterator
{
public:
    virtual bool valid() = 0;
    virtual int get() = 0;
    virtual void next() = 0;
};

class SimpleMCLIterator : public MyCoolListIterator {
public:
    SimpleMCLIterator(std::list<int> data) {
        collectionData = data;
        collectionDataIterator = collectionData.begin();
    }
    bool valid() {
        return collectionDataIterator != collectionData.end();
    }
    int get() {
        return *collectionDataIterator;
    }
    void next() {
        collectionDataIterator++;
    }

private:
    std::list<int> collectionData;
    std::list<int>::iterator collectionDataIterator;
};

class MyCoolList 
{

public:
    void add(int value) {
        data.push_back(value);

        bool positionFound = false;
        std::list<int>::iterator it = sortedData.begin();
        while (it != sortedData.end() || positionFound == false)
        {
            if (*it > value)
            {
                positionFound = true;
            }
            it++;
        }
        sortedData.insert(it, value);
    }

    void remove(int index) {
        std::list<int>::iterator it = data.begin();
        advance(it, index);
        int value = *it;
        data.erase(it);

        bool positionFound = false;
        std::list<int>::iterator it = sortedData.begin();
        while (it != sortedData.end() || positionFound == false)
        {
            if (*it == value)
            {
                positionFound = true;
            }
            it++;
        }
        sortedData.erase(it);

        this->deletedData.push_back(value);
    }

    MyCoolListIterator* getSimpleIterator() {
        MyCoolListIterator* mclIterator = new SimpleMCLIterator(this->data);
        return mclIterator;
    }

    MyCoolListIterator* getSortedIterator() {
        MyCoolListIterator* mclIterator = new SimpleMCLIterator(this->sortedData);
        return mclIterator;
    }

    MyCoolListIterator* getGhostIterator() {
        std::list<int> dataAndDeletedList = this->data;
        dataAndDeletedList.merge(this->deletedData);
        MyCoolListIterator* mclIterator = new SimpleMCLIterator(dataAndDeletedList);
        return mclIterator;
    }

private:
    std::list<int> data;
    std::list<int> sortedData;
    std::list<int> deletedData;
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
