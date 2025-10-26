#pragma once
#include <deque>
#include <cstddef>

namespace fmi {

    template <class T>
    class StackInterface {
    public:
        virtual ~StackInterface() = default;
        virtual bool empty() const = 0;
        virtual size_t size() const = 0;

        virtual T pop() = 0;
        virtual void push(const T& elem) = 0;

        virtual T& top() = 0;
        virtual const T& top() const = 0;
    };

    template <class T, class Container = std::deque<T>>
    class stack : public StackInterface<T> {
        public:
        bool empty() const override {
            return _data.empty();
        }

        size_t size() const override {
            return _data.size();
        }

        T pop() override {
            T elem = _data.back();
            _data.pop_back();
            return elem;
        }

        void push(const T& elem) override {
            _data.push_back(elem);
        }

        T& top() override {
            return _data.back();
        }

        const T& top() const override {
            return _data.back();
        }

        private:
        Container _data;
    };
}