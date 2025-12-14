#include <iostream>

#include "../../07_tree/solutions/Node.h"


template<class T>
void rightRotation(Node<T>*& root) {
    Node<T>* originalLeft = root->left;
    root->left = originalLeft->right;
    originalLeft->right = root;
    root = originalLeft;
}

template<class T>
void leftRotation(Node<T>*& root) {
    Node<T>* originalRight = root->right;
    root->right = originalRight->left;
    originalRight->left = root;
    root = originalRight;
}

// Helper functions to better visualize the tree before and after rotating
// https://dreampuf.github.io/GraphvizOnline/
template<typename T>
void printDot(const Node<T>* root) {
    std::cout << "digraph G {" << std::endl;
    printDotHelper(root);
    std::cout << "}" << std::endl;
}

template<typename T>
void printDotHelper(const Node<T>* current) {
    if (current == nullptr) {
        return;
    }

    std::cout << (long) current << "[label=\"" << current->value << "\"]" << std::endl;

    if (current->left != nullptr) {
        std::cout << (long) current << " -> " << (long) current->left << std::endl;
    }

    if (current->right != nullptr) {
        std::cout << (long) current << " -> " << (long) current->right << std::endl;
    }

    printDotHelper(current->left);
    printDotHelper(current->right);
}

int main() {
    Node<int>* bst = new Node<int>(50,
                            new Node<int>(17,
                               new Node<int>(9),
                               new Node<int>(23)),
                            new Node<int>(76));
    printDot(bst);

    rightRotation(bst);
    std::cout << "After right rotation:\n";
    printDot(bst);

    leftRotation(bst);
    std::cout << "After left rotation:\n";
    printDot(bst);

    delete bst;
    return 0;
}
