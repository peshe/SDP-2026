#include <iostream>
#include <vector>
#include "../../07_tree/solutions/Node.h"


template <typename T>
void bstToVectorHelper(const Node<T>* root, std::vector<T>& result) {
    if (!root) return;

    bstToVectorHelper(root->left, result);
    result.push_back(root->value);
    bstToVectorHelper(root->right, result);
}

template <typename T>
std::vector<T> bstToVector(const Node<T>* root) {
    std::vector<T> result;
    bstToVectorHelper(root, result);
    return result;
}

int main() {
    Node<int>* btree = new Node<int>(4,
                               new Node<int>(2,
                                              new Node<int>(1),
                                              new Node<int>(3)),
                               new Node<int>(6,
                                              new Node<int>(5),
                                              new Node<int>(7)));
    auto v = bstToVector(btree);
    for (auto elem : v) std::cout << elem << ' ';
    std::cout << std::endl;

    delete btree;
    return 0;
}
