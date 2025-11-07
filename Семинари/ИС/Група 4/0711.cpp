// stackFromQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template<typename T>
class Stack {
public:
    void push(const T& value) {
        if (queue1.empty()) {
            queue1.push(value);
            while (!queue2.empty()) {
                queue1.push(queue2.front());
                queue2.pop();
            }
        }
        else {
            queue2.push(value);
            while (!queue1.empty())
            {
                queue2.push(queue1.front());
                queue1.pop();
            }
        }
    }

    void pop() {
        if (!queue1.empty()) {
            queue1.pop();
        }
        else {
            queue2.pop();
        }
    }

    T peek() {
        if (!queue1.empty()) {
            return queue1.front();
        }
        else {
            return queue2.front();
        }
    }

    bool isEmpty() const {
        return queue1.empty() && queue2.empty();
    }

    void print() {
        while (!this->isEmpty()) {
            std::cout << this->peek() << std::endl;
            this->pop();
        }
    }

private:
    std::queue<T> queue1;
    std::queue<T> queue2;
};

template <typename T>
class Queue {
public:
    void push(const T& value) {
        stack1.push(value);
    }

    void pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
           
        }
        stack2.pop();
    }

    T peek() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }

        }
        return stack2.top();
    }

    bool isEmpty() const {
        return stack1.empty() && stack2.empty();
    }

    void print() {
        while (!this->isEmpty()) {
            std::cout << this->peek() << std::endl;
            this->pop();
        }
    }

private:
    std::stack<T> stack1;
    std::stack<T> stack2;

};

struct Pos
{
    int x;
    int y;
    int count=0;
    
};
Pos generatePosition1(Pos pos) {
    Pos newPos{
        pos.x + 1,pos.y - 2,pos.count + 1
    };
    return newPos;
}
Pos generatePosition2(Pos pos) {
    Pos newPos{
        pos.x + 2,pos.y - 1,pos.count + 1
    };
    return newPos;
}

bool isValidPosition(Pos pos) {
    return pos.x >= 1 && pos.x <= 8 && pos.y >= 1 && pos.y <= 8;
}

std::vector<Pos> visited;

bool isNotVisited(Pos pos) {
    visited.
}

void addPossiblePos(Pos pos, std::queue<Pos>& posQueue)
{
    Pos pos1 = generatePosition1(pos), pos2 = generatePosition2(pos);
    if (isValidPosition(pos1) && isNotVisited(pos1)) posQueue.push(pos1);
}
int minimumSteps(Pos curr, Pos dest)
{
    std::queue<Pos> posQueue;
    
   
   
    posQueue.push(curr);


    while (!posQueue.empty())
    {
        Pos temp = posQueue.front();
        posQueue.pop();
        addPossiblePos(temp, posQueue);

        if (temp.x == dest.x && temp.y == dest.y)
        {
            return temp.count;
        }


        
    }
    return -1;
}
int main()
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.print();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.pop();
    stack.print();
    std::cout << std::endl;
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.print();
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.print();
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
