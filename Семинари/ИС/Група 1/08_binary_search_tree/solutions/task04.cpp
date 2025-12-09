#include <iostream>
#include <vector>
#include "../../07_tree/solutions/Node.h"


template <typename T>
void printLeftParentRight(const Node<T>* btree) {
    if (btree == nullptr) return;

    printLeftParentRight(btree->left);
    std::cout << ' ' << btree->value << ' ';
    printLeftParentRight(btree->right);
}

template <typename T>
Node<T>* sortedVectorToBstInternal(
    const std::vector<T>& input, long long int startIdx, long long int endIdx
) {
    if (startIdx > endIdx) return nullptr;

    long long int midIdx = startIdx + (endIdx - startIdx) / 2;

    Node<T>* root = new Node<T>(input[midIdx]);
    root->left = sortedVectorToBstInternal(input, startIdx, midIdx - 1);
    root->right = sortedVectorToBstInternal(input, midIdx + 1, endIdx);

    return root;
}

template <typename T>
Node<T>* sortedVectorToBst(const std::vector<T>& input) {
    if (input.empty()) return nullptr;

    return sortedVectorToBstInternal(input, 0, input.size() - 1);
}

int main() {
    std::vector<int> v {1, 2, 3, 4, 5, 6, 7};
    Node<int>* bst = sortedVectorToBst(v);
    printLeftParentRight(bst);
    std::cout << std::endl;

    delete bst;
    return 0;
}
