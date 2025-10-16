#include <iostream>
#include <vector>


template <typename T>
std::vector<T> append(const std::vector<T>& first, const std::vector<T>& second) {
    std::vector<T> result; // Създаваме с размер 0...
    // и веднага след това запазваме точно толкова памет, колкото ще ни трябва.
    result.reserve(first.size() + second.size());

    // Един начин за добавяне: push_back, като използваме константен operator[].
    for (size_t i = 0; i < first.size(); ++i) {
        result.push_back(first[i]);
    }

    // Алтернативно range-based for:
    // for (const auto& element : first) {
    //     result.push_back(element);
    // }

    // Или дори с итератори:
    // for (auto it = first.begin(); it != first.end(); ++it) {
    //     result.push_back(*it);
    // }

    // Друг начин: използваме insert с итератори.
    result.insert(result.end(), second.begin(), second.end());

    return result;
}

// Приемаме, че в първия вектор вече няма повторения - примерно получен е като резултат от предишно
// извикване на настоящия метод.
// Ако все пак има повторения, задачата се свежда тривиално до същата:
// vectorUnion({}, append(first, second));
template <typename T>
std::vector<T> vectorUnion(const std::vector<T>& first, const std::vector<T>& second) {
    // Не знаем колко памет да запазим, понеже не знаем колко повторения ще има, поради което не е
    // толкова лоша идея да започнем с копие на вече уникалния първи вектор, който знаем, че ще
    // запазим напълно, и да разчитаме на автоматичното преоразмеряване.
    std::vector<T> result(first.begin(), first.end()); // конструктор по итератор

    for (const auto& candidateElement : second) {
        bool alreadyThere = false;

        // Линейно търсене, понеже ползваме динамичен масив и не знаем нищо за реда на елементите му.
        // В следващи уроци ще видим по-подходящи структури за имплементиране на операции с множества.
        for (const auto& element : result) {
            if (candidateElement == element) {
                alreadyThere = true;
                break;
            }
        }

        if (!alreadyThere) {
            result.push_back(candidateElement);
        }
    }

    return result;
}

template <typename T>
std::vector<T> intersection(const std::vector<T>& first, const std::vector<T>& second) {
    std::vector<T> result;

    for (const auto& candidateElement : first) {
        bool foundInSecond = false;

        for (const auto& element : second) {
            if (element == candidateElement) {
                foundInSecond = true;
                break;
            }
        }

        if (foundInSecond) {
            result.push_back(candidateElement);
        }
    }

    return result;
}

template <typename T>
void printVector(const std::vector<T>& v) {
    for (const auto& element : v) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> first = {1, 2, 3, 4}, second = {6, 2, 1, 7, 8};

    auto appendResult = append(first, second);
    std::cout << "Append: ";
    printVector(appendResult);

    auto unionResult = vectorUnion(first, second);
    std::cout << "Union: ";
    printVector(unionResult);

    auto intersectionResult = intersection(first, second);
    std::cout << "intersection: ";
    printVector(intersectionResult);

    return 0;
}
