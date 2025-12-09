#include <algorithm>
#include <cmath>
#include <iostream>
#include "../../07_tree/solutions/Node.h"


template <typename T>
int height(const Node<T>* root) {
    if (!root) return 0;

    return 1 + std::max(height(root->left), height(root->right));
}

template <typename T>
bool isBalanced(const Node<T>* root) {
    if (!root) return true;

    return isBalanced(root->left) &&
            isBalanced(root->right) &&
            (std::abs(height(root->left) - height(root->right)) < 2);
}

int main() {
    Node<int>* btree = new Node<int>(4,
                               new Node<int>(2,
                                              new Node<int>(1),
                                              new Node<int>(3)));
    std::cout << std::boolalpha << isBalanced(btree) << std::endl;

    delete btree;
    return 0;
}
