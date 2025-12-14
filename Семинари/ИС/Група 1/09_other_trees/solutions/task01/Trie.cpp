#include "Trie.h"

#include <cassert>
#include <iostream>
#include <string>
#include <utility>


using std::cout;
using std::string;


Trie::TrieNode::~TrieNode() {
    for (auto& i : next) {
        delete i.second;
    }
}

Trie::TrieNode* Trie::TrieNode::find(char c) {
    for (auto& i : next) {
        if (i.first == c) {
            return i.second;
        }
    }
    return nullptr;
}

Trie::TrieNode* Trie::TrieNode::add(char c) {
    TrieNode* result = new TrieNode();
    next.push_back(std::make_pair(c, result));
    return result;
}


bool Trie::add(const string& word) {
    TrieNode* current = &root;

    for (char c : word) {
        TrieNode* next = current->find(c);

        if (next == nullptr) {
            next = current->add(c);
        }

        assert(next != nullptr);
        current = next;
    }

    bool added = !current->canTerminate;
    current->canTerminate = true;
    return added;
}

bool Trie::remove(const string& word) {
    TrieNode* node = find(word);
    if (node == nullptr) {
        return false;
    }

    bool removed = node->canTerminate;
    node->canTerminate = false;
    return removed;
}

void Trie::printWithPrefix(const string& prefix) const {
    const TrieNode* node = const_cast<Trie*>(this)->find(prefix);
    printWithPrefix(prefix, node);
    cout << std::endl;
}

Trie::TrieNode* Trie::find(const string& prefix) {
    TrieNode* current = &root;

    for (char c : prefix) {
        TrieNode* next = current->find(c);

        if (next == nullptr) {
            return nullptr;
        }

        current = next;
    }

    return current;
}

/*static*/ void Trie::printWithPrefix(const string& prefix, const Trie::TrieNode* node) {
    if (node == nullptr) {
        return;
    }

    if (node->canTerminate) {
        cout << prefix << '\n';
    }

    for (auto& i : node->next) {
        printWithPrefix(prefix + i.first, i.second);
    }
}
