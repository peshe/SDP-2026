#include <string>
#include <utility>
#include <vector>


class Trie
{
public:
    bool add(const std::string& word);
    bool remove(const std::string& word);

    void printWithPrefix(const std::string& prefix) const;

private:
    struct TrieNode
    {
        bool canTerminate;
        std::vector<std::pair<char, TrieNode*>> next;

        TrieNode()
        : canTerminate(false), next{}
        {}
        ~TrieNode();

        TrieNode* find(char c);
        TrieNode* add(char c);

    private:
        TrieNode(const TrieNode&) = delete;
        TrieNode& operator= (const TrieNode&) = delete;
    };

    TrieNode root;

private:
    TrieNode* find(const std::string& prefix);

    static void printWithPrefix(const std::string& prefix, const TrieNode*);
};
