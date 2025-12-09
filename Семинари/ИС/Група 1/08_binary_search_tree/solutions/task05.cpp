#include <cassert>
#include <set>
#include <vector>


int countUniques(const std::vector<int>& data) {
    std::set<int> dataset;

    for (int element : data) {
        dataset.insert(element);
    }

    return dataset.size();
}

bool twoSum(const std::vector<int>& data, int target) {
    std::set<int> dataset;

    for (int element : data) {
        if (dataset.count(target - element) > 0) {
            return true;
        }
        dataset.insert(element);
    }

    return false;
}

int main() {
    std::vector<int> t1 = {1, 1, 1, 1, 1};
    assert(countUniques(t1) == 1);
    assert(!twoSum(t1, 1));
    assert(twoSum(t1, 2));
    assert(!twoSum(t1, 3));

    std::vector<int> t2 = {1, 2, 3, 4, 5};
    assert(countUniques(t2) == 5);
    assert(twoSum(t2, 5));
    assert(!twoSum(t2, 10));

    std::vector<int> t3 = {1, 2, 1, 2, 1};
    assert(countUniques(t3) == 2);
    assert(!twoSum(t3, 1));
    assert(twoSum(t3, 2));
    assert(twoSum(t3, 3));
    assert(twoSum(t3, 4));
    assert(!twoSum(t3, 5));

    return 0;
}
