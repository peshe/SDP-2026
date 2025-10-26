#include "stack.hpp"
#include <string>
#include <cctype>
#include <stdexcept>
#include "operators.hpp"

std::string shuntingYard(const std::string& expr) {
    std::string output;
    fmi::stack<Operator*> ops;
    char curr;
    for (size_t i = 0; expr[i] != '\0' ; i++)
    {
        curr = expr[i];
        if (std::isdigit(curr)) {
            output.push_back(curr);
        }
        else {
            Operator* curr_op = operatorFactory(curr);
            if (!curr_op) continue;
            while (!ops.empty() && ops.top()->getPrecedence() >= curr_op->getPrecedence()) {
                auto top_op = ops.pop();
                output.push_back(top_op->c_str());
                delete top_op;
            }
            ops.push(curr_op);
        }
    }

    while (!ops.empty()) {
        auto top_op = ops.pop();
        output.push_back(top_op->c_str());
        delete top_op;
    }

    return output;
}

int evalRPN(const std::string& polish_expr) {
    fmi::stack<int> s;
    for (size_t i = 0; polish_expr[i]; i++)
    {
        if (std::isdigit(polish_expr[i])) {
            s.push(polish_expr[i] - '0');
        }
        else {
            if (s.size() < 2) 
                throw std::runtime_error("Wrong expression");
            int right = s.pop();
            int left = s.pop();
            Operator* op = operatorFactory(polish_expr[i]);
            if (!op) continue;
            int result = op->calculate(left, right);
            s.push(result);
            delete op;
        }
    }

    if (s.size() != 1) 
        throw std::runtime_error("Wrong expression!");

    return s.pop();
}

