#pragma once
#include <inttypes.h>
#include <stdexcept>

class Operator {
    public:
    Operator(uint8_t p) : priority(p) {}
    virtual int calculate(int left, int right) const = 0;
    // Come off as redundant, because we have to compare pointers later
    bool operator<(const Operator& other) { return this->priority < other.priority; } 
    bool operator>(const Operator& other) { return this->priority > other.priority; } 
    uint8_t getPrecedence() const { return priority; }
    virtual char c_str() const = 0;
    private:
    uint8_t priority = 0;
};

class AdditionOperator : public Operator {
    public:
    AdditionOperator() : Operator(0) {}
    int calculate(int left, int right) const { return left + right; }  
    char c_str() const override { return '+'; }
};
class SubtractionOperator : public Operator {
    public:
    SubtractionOperator() : Operator(0) {}
    int calculate(int left, int right) const { return left - right; }
    char c_str() const override { return '-'; }
};
class MultiplicationOperator : public Operator {
    public:
    MultiplicationOperator() : Operator(1) {}
    int calculate(int left, int right) const { return left * right; }
    char c_str() const override { return '*'; }
};
class DivisionOperator : public Operator {
    public:
    DivisionOperator() : Operator(1) {}
    int calculate(int left, int right) const { 
        if (right == 0)
            throw std::invalid_argument("Right val cannot be 0");
        return left / right; 
    }
    char c_str() const override { return '/'; }
};

Operator* operatorFactory(char sym) {
    switch (sym)
    {
    case '+': return new AdditionOperator(); 
    case '-': return new SubtractionOperator();
    case '*': return new MultiplicationOperator();
    case '/': return new DivisionOperator();
    default: return nullptr;
    }
}