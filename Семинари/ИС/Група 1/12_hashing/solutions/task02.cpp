class Solution {
private:
    typedef unsigned long long StringHash;

    static StringHash hashString(const string& str) {
        unsigned characterCounts[26] = {0};
        for (auto ch : str) {
            ++characterCounts[ch - 'a'];
        }

        StringHash result = 5381;
        for (size_t i = 0; i < 26; ++i) {
            result = result * 33 + characterCounts[i];
        }
        return result;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<StringHash, vector<string>> groups;

        for (const auto& str : strs) {
            StringHash hash = hashString(str);

            groups[hash].push_back(str);
        }

        vector<vector<string>> result;
        for (const auto& group : groups) {
            const auto& groupMembers = group.second;

            result.push_back(groupMembers);
        }
        return result;
    }
};
