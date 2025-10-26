#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

template<typename T>
class NArray {
private:
    T* data;
    int capacity;
    int size;
    unsigned maxSize;

    void resize(int new_capacity) {
        T* new_data = new T[new_capacity];
        for (int i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    NArray(unsigned n =10, int initial_capacity = 2)
        : capacity(initial_capacity), size(0), maxSize(n) {
        data = new T[capacity];
    }

    ~NArray() {
        delete[] data;
    }

    void shift() {
        for (int index = 0; index < size - 1; ++index) {
            std::swap(data[index], data[index + 1]);
        }
    }

    bool maxSizeReached() const {
        return size == maxSize;
    }

    void push_back(const T& value) {
        if (maxSizeReached()) {
            shift();
            data[size - 1] = value;
        }
        else {
            if (size == capacity) {
                resize(capacity * 2);
            }
            data[size++] = value;
        }
    }

    void changeAt(size_t index, const T& value) {
        if (index < 0 || index > capacity) {
            throw std::invalid_argument("Out of range.");
        }

        data[index] = value;
    }

    T getAt(size_t index) const {
        return this->data[index];
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }
};

template<typename T>
class HistoryArray {
private:
    T* data;
    int capacity;
    int size;
    NArray<std::string> history;

    void resize(int new_capacity) {
        T* new_data = new T[new_capacity];
        for (int i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    HistoryArray(int initial_capacity = 2)
        : capacity(initial_capacity), size(0) {
        data = new T[capacity];
        history.push_back("CREATED");
    }

    ~HistoryArray() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        data[size++] = value;
        std::stringstream ss;
        ss << "Added ";
        ss << value;
        ss << " at end";
        history.push_back(ss.str());
    }

    void changeAt(size_t index, const T& value) {
        if (index < 0 || index > capacity) {
            throw std::invalid_argument("Out of range.");
        }
        std::stringstream ss;
        ss << "Element at index: ";
        ss << index;
        ss << " changed from: ";
        ss << data[index];
        ss << " to: ";
        ss << value;
        history.push_back(ss.str());
        data[index] = value;
    }

    T getAt(size_t index) const {
        return this->data[index];
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    void printHistory() const {
        std::cout << "History: " << std::endl;
        for (int i = this->history.getSize() - 1; i >= 0; i--) {
            std::cout << this->history.getAt(i) << std::endl;
        }
    }
};


template<typename T>
class SumNArray {
private:
    T* data;
    int capacity;
    int size;
    T sum;
    unsigned maxSize;

    void resize(int new_capacity) {
        T* new_data = new T[new_capacity];
        for (int i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    SumNArray(unsigned n ,int initial_capacity = 2)
        : capacity(initial_capacity), size(0), sum(0), maxSize(n) {
        data = new T[capacity];
    }

    ~SumNArray() {
        delete[] data;
    }

    void shift() {
        std::cout << "Shift";
        for (int index = 0; index < size -1; ++index) {
            std::swap(data[index], data[index + 1]);
            std::cout << data[index] << std::endl;
        }
    }

    bool maxSizeReached() const{
        return size == maxSize;
    }

    void push_back(const T& value) {
        std::cout << "Push back value : " << value << "\n";
        if (maxSizeReached()) {
            shift();
            data[size -1] = value;
        }
        else {
            if (size == capacity) {
                resize(capacity * 2);
            }
            data[size++] = value;
            sum += value;
        }
    }

    void changeAt(size_t index, const T& value) {
        if (index < 0 || index > capacity) {
            throw std::invalid_argument("Out of range.");
        }

        sum -= data[index];
        sum += value;
        data[index] = value;
    }

    T getAt(size_t index) const {
        return this->data[index];
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    T sumF() const {
        return sum;
    }
};

void print(SumNArray<int>& nArrayInts) {
    std::cout << "Array values:" << std::endl;
    for (int i = 0; i < nArrayInts.getSize(); i++) {
        std::cout << "arr[" << i << "] = " << nArrayInts.getAt(i) << std::endl;;
    }
}

int main()
{
    //SumNArray<int> arr(2,3);
    //arr.push_back(5);
    //arr.push_back(15);
    //arr.push_back(25);
    //arr.push_back(35);
    //arr.push_back(45);

    //print(arr);

    //std::cout << "Sum: " << arr.sumF() << std::endl; // 45

    //arr.changeAt(1, 10);
    //std::cout << "Sum after change: " << arr.sumF() << std::endl; // 40

    HistoryArray<int> arr;
    arr.push_back(2);
    arr.push_back(33);
    arr.push_back(5);
    arr.push_back(5);
    arr.push_back(5);
    arr.push_back(5);
    arr.push_back(5);
    arr.push_back(5);
    arr.push_back(5);
    arr.push_back(5);
    arr.changeAt(1, 4);
    arr.printHistory();

    return 0;
}



