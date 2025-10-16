#pragma once
#include <cstddef>
#include <iostream>
#include <stdexcept>

namespace simple {
    template <class T>
class vector {
    public:
        vector() : _size(0), _capacity(0), _data(nullptr) {}

        ~vector() {
            delete[] _data;
        }

        vector(const vector<T>& other) {
            std::cout << "Copy ctor\n";
            _data = new T[other._capacity];
            for (size_t i = 0; i < other._size; i++)
            {
                _data[i] = other._data[i];
            }

            _size = other._size;
            _capacity = other._capacity;
        }

        const vector<T>& operator=(const vector<T>& other) {
            std::cout << "Copy op=\n";
            if (this != &other) {
                vector<T> temp(other);
                std::swap(_data, temp._data);
                std::swap(_size, temp._size);
                std::swap(_capacity, temp._capacity);
            }
            return *this;
        }

        vector(vector<T>&& other) noexcept {
            std::cout << "Move ctor\n";
            _data = other._data;
            _size = other._size;
            _capacity = other._capacity;

            other._data = nullptr;
            other._size = 0;
            other._capacity = 0;
        }

        vector<T>& operator=(vector<T>&& other) noexcept {
            std::cout << "Move op=\n";
            if (this != &other) {
                delete[] _data;
                _data = other._data;
                _size = other._size;
                _capacity = other._capacity;

                other._data = nullptr;
                other._size = 0;
                other._capacity = 0;
            }
            return *this;
        }

        void push_back(const T& elem) {
            if (_size >= _capacity)
                reserve(_capacity == 0 ? INITIAL_CAP : _capacity * GROWTH_RAT);

            _data[_size++] = elem;
        }

        //void erase(size_t pos)
        //void insert(size_t pos)

    private:
        void reserve(size_t new_capacity) {
            if(new_capacity <= _capacity)
                throw std::logic_error("New cap must be more than old!");
                // return
            
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < _size; i++)
            {
              new_data[i] = std::move(_data[i]);  
            }

            delete[] _data;
            _data = new_data;
            _capacity = new_capacity;
        }

    private:
        constexpr static int INITIAL_CAP = 10;
        constexpr static double GROWTH_RAT = 1.66;
    
    private:
        T* _data;
        size_t _size;
        size_t _capacity;
};
}