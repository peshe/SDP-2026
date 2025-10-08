# Преговор на C++ Шаблони и Рекурсия

## ⚠️ **Получаване на петте точки в рамките на семинара**

| Посетени седмици* | Точки |
| -------------- | ------ |
| 3              | 1.0    |
| 6              | 2.0    |
| 9              | 3.0    |
| 11             | 4.0    |
| 13+            | 5.0    |

**\*Посещаването включва и някакъв вид участие в упражненията.**

## Шаблони в C++

Шаблоните ви позволяват да пишете обобщен код, който работи с различни типове данни.

### Шаблони за Функции

```cpp
template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

int maxInt = maximum(5, 10);
double maxDouble = maximum(3.14, 2.71);
```

### Шаблони за Класове

```cpp
template <typename T>
class Stack {
private:
    T* arr;
    int top;
    int capacity;
public:
    Stack(int size) : capacity(size), top(-1) {
        arr = new T[capacity];
    }
    
    void push(T item) {
        if (top < capacity - 1) {
            arr[++top] = item;
        }
    }
    
    T pop() {
        if (top >= 0) {
            return arr[top--];
        }
        throw std::runtime_error("Empty stack");
    }
};
```

### Не типови параметри и параметри по подразбиране

```cpp
template <typename T = int, int size = 0>
class FixedArray {
private:
    T arr[size];
public:
    T& operator[](int index) {
        return arr[index];
    }
};
```

### Проблем със разделна компилация на Шаблони

**Важно:** Шаблонните класове и функции **не могат** да бъдат разделени в отделни `.cpp` файлове като обикновените класове, защото компилаторът трябва да види цялата дефиниция на шаблона в момента на инстанциране.

#### Защо възниква този проблем?

```cpp
// stack.h
template <typename T>
class Stack {
private:
    T* arr;
    int top;
public:
    Stack(int size);
};

// stack.cpp - ще има грешка при линкване
template <typename T>
Stack<T>::Stack(int size) : top(-1) {
    arr = new T[size];
}
```

#### Решения за "псевдо" разделна компилация

**1. Inline файлове (.inl или .hpp)**

```cpp
// stack.h
template <typename T>
class Stack {
private:
    T* arr;
    int top;
public:
    Stack(int size);
    void push(T item);
    T pop();
};

#include "stack.inl"  // Включва имплементацията

// stack.inl
template <typename T>
Stack<T>::Stack(int size) : top(-1) {
    arr = new T[size];
}

template <typename T>
void Stack<T>::push(T item) {
    if (top < capacity - 1) {
        arr[++top] = item;
    }
}
```

**2. Всичко в header файла (.hpp)**

```cpp
// stack.hpp
template <typename T>
class Stack {
private:
    T* arr;
    int top;
    int capacity;
    
public:
    Stack(int size) : capacity(size), top(-1) {
        arr = new T[capacity];
    }
    
    void push(T item) {
        if (top < capacity - 1) {
            arr[++top] = item;
        }
    }
    
    T pop() {
        if (top >= 0) {
            return arr[top--];
        }
        throw std::runtime_error("Empty stack");
    }
};
```

**3. Експлицитно инстанциране (ограничено приложение)**

```cpp
// stack.cpp
#include "stack.h"

// Експлицитно инстанциране за конкретни типове
template class Stack<int>;
template class Stack<double>;
template class Stack<std::string>;

// Сега може да се ползва само за тези типове
```

**Препоръка:** Използвайте вариант 1 (inline файлове) или вариант 2 (всичко в header) за максимална гъвкавост.

[Задълбочаване в шаблони](https://learn.microsoft.com/en-us/cpp/cpp/templates-cpp?view=msvc-170)

## Рекурсия в C++

Рекурсия се получава когато една функция извиква сама себе си или индиректно чрез друга функция, за да реши по-малки инстанции от същия проблем. Всяко рекурсивно решение на проблем има и итеративно такова (с цикли). Предимството на рекурсията е, че в някои случаи тя може да направи кода по-четим и по-лесен за разбиране.

### Основна структура

```cpp
returnType recursiveFunction(parameters) {
    // Базов случай - спира рекурсията
    if (baseCondition) {
        return baseValue;
    }
    
    // Рекурсивна стъпка
    return someOperation(recursiveFunction(modifiedParameters));
}
```

[Още материали от курса по УП за рекурсия](https://github.com/dimoyordanov/UpInformaticsSeminarPracticum2024-25/blob/main/Seminar/Week11/README.md)

## Нотации за Сложност

### Нотация Big-O (O)

$f(n) \in O(g(n)) \text{ if } \exists c > 0, n_0 > 0 \text{ such that } |f(n)| \leq c \cdot g(n) \text{ for all } n \geq n_0$

Горна граница - най-лош сценарий. $f(n) = O(g(n))$ означава, че $f(n)$ не расте по-бързо от $g(n)$.

### Нотация Little-o (o)

$f(n) \in o(g(n)) \text{ if } \lim_{n \to \infty} \frac{f(n)}{g(n)} = 0$

Строга горна граница. $f(n) = o(g(n))$ означава, че $f(n)$ расте строго по-бавно от $g(n)$.

### Нотация Омега (Ω)

$f(n) \in \Omega(g(n)) \text{ if } \exists c > 0, n_0 > 0 \text{ such that } f(n) \geq c \cdot g(n) \text{ for all } n \geq n_0$

Долна граница - най-добър сценарий. $f(n) = \Omega(g(n))$ означава, че $f(n)$ расте поне толкова бързо колкото $g(n)$.

### Нотация Тета (Θ)

$f(n) \in \Theta(g(n)) \text{ if } \exists c_1, c_2 > 0, n_0 > 0 \text{ such that } c_1 \cdot g(n) \leq f(n) \leq c_2 \cdot g(n) \text{ for all } n \geq n_0$

Тясна граница - среден случай. $f(n) = \Theta(g(n))$ означава, че $f(n)$ и $g(n)$ растат с еднаква скорост.

## Често срещани Big-O сложности

От най-добра до най-лоша производителност:

1. **O(1)** - Константно време
2. **O(log n)** - Логаритмично време
3. **O(n)** - Линейно време
4. **O(n log n)** - Линеаритмично време
5. **O(n²)** - Квадратично време
6. **O(2ⁿ)** - Експоненциално време
7. **O(n!)** - Факториално време

![Big-O Notation](https://cdn-media-1.freecodecamp.org/images/1*KfZYFUT2OKfjekJlCeYvuQ.jpeg)

## Времева сложност

Времевата сложност измерва как времето за изпълнение расте с размера на входа.

### Примери с анализ

```cpp
// O(1) - Константно време
int getFirst(vector<int>& arr) {
    return arr[0];  // Винаги една операция
}

// O(n) - Линейно време
int sum(vector<int>& arr) {
    int total = 0;
    for (int x : arr) {  // n итерации
        total += x;
    }
    return total;
}

// O(n²) - Квадратично време
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {      // n итерации
        for (int j = 0; j < n-1; j++) { // n итерации всяка
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// O(log n) - Логаритмично време
bool binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return true;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;  // Размерът на проблема се половява всяка итерация
    }
    return false;
}

// O(2ⁿ) - Експоненциално време (неефективен Фибоначи)
int fibonacciRecursive(int n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);  // Две рекурсивни извиквания
}
```

## Пространствена сложност

Пространствената сложност измерва как използването на памет расте с размера на входа.

### Източници на pамет

- Входни данни
- Спомагателни структури от данни
- Стек от рекурсивни извиквания
- Локални променливи

### Примери за пространствена сложност

```cpp
// O(1) - Константно пространство
int iterativeSum(vector<int>& arr) {
    int sum = 0;  // Само една променлива независимо от размера на входа
    for (int x : arr) {
        sum += x;
    }
    return sum;
}

// O(n) - Линейно пространство
vector<int> copyArray(vector<int>& arr) {
    vector<int> copy(arr.size());  // Нов масив с размер n
    for (int i = 0; i < arr.size(); i++) {
        copy[i] = arr[i];
    }
    return copy;
}

// O(n) - Линейно пространство поради стека за извиквания
void printNumbers(int n) {
    if (n <= 0) return;
    printNumbers(n - 1);  // n рекурсивни извиквания
    std::cout << n << " ";
}

// O(n²) - Квадратично пространство
vector<vector<int>> createMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));  // n×n матрица
    return matrix;
}
```

## Рекурсивни алгоритми с пространствен анализ

### Обхождане на Дърво - O(h) пространство, където h е височината

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    
    inorderTraversal(root->left);   // Рекурсивно извикване
    std::cout << root->val << " ";
    inorderTraversal(root->right);  // Рекурсивно извикване
    
    // Пространство: O(h) където h е височината на дървото поради стека за извиквания
}
```

### Ханойските Кули - O(n) пространство

```cpp
void hanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        std::cout << "Move disk 1 from " << source << " to " << destination << '\n';
        return;
    }
    
    hanoi(n-1, source, auxiliary, destination);
    std::cout << "Move disk " << n << " from " << source << " to " << destination << '\n';
    hanoi(n-1, auxiliary, destination, source);
    
    // Време: O(2ⁿ), Пространство: O(n) поради дълбочината на рекурсията
}
```

## Задачи

**Анализирайте времевата и пространствената сложност на тези функции:**

```cpp
// 1
void mystery1(int n) {
    for (int i = 1; i <= n; i *= 2) {
        std::cout << i << " ";
    }
}

// 2
int mystery2(vector<vector<int>>& matrix) {
    int sum = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

// 3
void mystery3(int n) {
    if (n <= 0) return;
    for (int i = 0; i < n; i++) {
        std::cout << "*";
    }
    mystery3(n - 1);
}

// 4
vector<int> mystery4(vector<int>& arr) {
    if (arr.size() <= 1) return arr;
    
    vector<int> left, right;
    int mid = arr.size() / 2;
    
    for (int i = 0; i < mid; i++) left.push_back(arr[i]);
    for (int i = mid; i < arr.size(); i++) right.push_back(arr[i]);
    
    left = mystery4(left);
    right = mystery4(right);
    
    return merge(left, right);  // O(n)
}

// 5
void mystery5(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
    if (index == nums.size()) {
        result.push_back(current);  
        return;
    }
    
    mystery5(nums, index + 1, current);
    
    current.push_back(nums[index]);
    mystery5(nums, index + 1, current);
    current.pop_back();
}

// 6
void mystery6(string& str, int start) {
    if (start == str.length()) {
        std::cout << str << '\n';
        return;
    }
    
    for (int i = start; i < str.length(); i++) {
        swap(str[start], str[i]);
        mystery6(str, start + 1);
        swap(str[start], str[i]); 
    }
}
```
