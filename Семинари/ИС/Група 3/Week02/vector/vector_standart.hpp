#pragma once
#include <stdexcept>
#include <utility>

namespace standart_simple
{
    template <class T>
    class vector {
    public:
        vector() {
            _start = _end = _end_container = nullptr;
        }

        ~vector() {
            for (T* p = _start; p != _end; ++p)
            {
                p->~T();
            }
            ::operator delete(_start);
        }

        size_t size() const {
            return _end - _start;
        }

        size_t capacity() const {
            return _end_container - _start;
        }
    private:
        void reserve(size_t new_cap) {
            if(new_cap <= capacity())
                return;
            
            T* new_start = static_cast<T*>(::operator new(sizeof(T) * new_cap));
            
            size_t old_size = size();
            for (size_t i = 0; i < old_size; ++i)
            {
                new (new_start + i) T(std::move(_start[i]));
                _start[i].~T();
            }

            ::operator delete(_start);
            _start = new_start;
            _end = _start + old_size;
            _end_container = _start + new_cap;
        }

        T* _start;
        T* _end; //back
        T* _end_container;   
    };
};