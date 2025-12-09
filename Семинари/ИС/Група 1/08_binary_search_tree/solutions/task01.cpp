#include <cassert>
#include <iostream>
#include "../../07_tree/solutions/Node.h"


template <typename T>
T getMin(const Node<T>* root) {
    assert(root != nullptr && "Tree is empty!");
    T result = root->value;

    if (root->left) {
        T minLeft = getMin(root->left);
        if (minLeft < result) result = minLeft;
    }

    if (root->right) {
        T minRight = getMin(root->right);
        if (minRight < result) result = minRight;
    }

    return result;
}

template <typename T>
T getMax(const Node<T>* root) {
    assert(root != nullptr && "Tree is empty!");
    T result = root->value;

    if (root->left) {
        T maxLeft = getMax(root->left);
        if (maxLeft > result) result = maxLeft;
    }

    if (root->right) {
        T maxRight = getMax(root->right);
        if (maxRight > result) result = maxRight;
    }

    return result;
}

template <typename T>
bool isBST(const Node<T>* root) {
    if (!root) return true;

    if (!isBST(root->left) || !isBST(root->right)) return false;

    if (root->left && getMax(root->left) >= root->value) return false;
    if (root->right && getMin(root->right) <= root->value) return false;

    return true;
}

int main() {
    Node<int>* btree = new Node<int>(4,
                               new Node<int>(2,
                                              new Node<int>(1),
                                              new Node<int>(3)),
                               new Node<int>(6,
                                              new Node<int>(5),
                                              new Node<int>(7)));
    std::cout << std::boolalpha << isBST(btree) << std::endl;

    delete btree;
    return 0;
}
