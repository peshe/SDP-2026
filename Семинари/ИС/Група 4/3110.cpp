// stack_upr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdexcept>
#include <string>
#include <sstream>
template<typename T>
class linkedStack {
public:
    void push(T& value) {
        node* data = new node{ value, tos };
        tos = data;
    }
    T pop() {
        if (tos != nullptr) {
            node* temp = tos;
            tos = temp->next;
            T data = temp->data;
            delete temp;
            return data;
        }
        throw std::out_of_range("error");
    }
    bool isEmpty() {
        return tos == nullptr;
    }
    T top() {
        if (tos != nullptr) {
            return tos->data;
        }
        throw std::out_of_range("error");
    }
private:
    struct node {
        T data;
        node* next;
    } *tos;

};

template <typename T>
class CompositeStack
{
private:
    linkedStack<T> stack1;
    linkedStack<T> stack2;

public:
    void push1(T& value)
    {
        stack1.push(value);
    }

    void push2(T& value)
    {
        stack2.push(value);
    }

    T pop1()
    {
        return stack1.pop();
    }

    T& pop2()
    {
        return stack2.pop();
    }

    T& peek1()
    {
        return stack1.top();
    }

    T peek2()
    {
        return stack2.top();
    }
    bool isEmpty1() {
        return stack1.isEmpty();
    }
    bool isEmpty2() {
        return stack2.isEmpty();
    }
};

class UndoRedoStringBuilder {
private:
    std::string _s;
    CompositeStack<std::string> stacks;
public:

    void append(std::string& s) {
        stacks.push1(_s);
        _s += s;
        while (!stacks.isEmpty2()) {
            stacks.pop2();
        }
    }
    std::string getResult() {
        return this->_s;
    }
    void undo() {
        if (!stacks.isEmpty1()) {
            stacks.push2(_s);
            _s = stacks.pop1();

        }
        throw std::out_of_range("cant undo");
    }
    void redo() {
        if (!stacks.isEmpty2()) {
            stacks.push1(_s);
            _s = stacks.pop2();
        }
            
        throw std::out_of_range("cant redo");
    }
};

int main()
{
    std::cout << "Hello World!\n";

    CompositeStack<int> s;
    int a = 1;
    int b = 2;

    s.push1(a);
    s.push2(b);

    std::cout << s.peek1() << " " << s.peek2() << std::endl;

    s.push1(b);
    s.push2(a);

    std::cout << s.peek1() << " " << s.peek2() << std::endl;

    std::cout << s.pop1() << " " << s.pop2() << std::endl;
    std::cout << s.peek1() << " " << s.peek2() << std::endl;
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


