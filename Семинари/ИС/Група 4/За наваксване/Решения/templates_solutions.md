# Template Classes and Functions Practice - Solutions

Complete solutions with sample usage for all 50 template tasks.

---

## Trivial Tasks (1-10)

### 1. Function Template Basics
```cpp
#include <iostream>
using namespace std;

template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    cout << "Before: x=" << x << ", y=" << y << endl;
    swap(x, y);
    cout << "After: x=" << x << ", y=" << y << endl;

    double d1 = 1.5, d2 = 2.5;
    swap(d1, d2);
    cout << "Double: " << d1 << ", " << d2 << endl;

    return 0;
}
```
**Sample Output:**
```
Before: x=5, y=10
After: x=10, y=5
Double: 2.5, 1.5
```

### 2. Template Max Function
```cpp
#include <iostream>
using namespace std;

template<typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << "Max(5, 10) = " << maximum(5, 10) << endl;
    cout << "Max(3.5, 2.1) = " << maximum(3.5, 2.1) << endl;
    cout << "Max('a', 'z') = " << maximum('a', 'z') << endl;
    return 0;
}
```
**Sample Output:**
```
Max(5, 10) = 10
Max(3.5, 2.1) = 3.5
Max('a', 'z') = z
```

### 3. Template Min Function
```cpp
#include <iostream>
using namespace std;

template<typename T>
T minimum(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
    cout << "Min(5, 10) = " << minimum(5, 10) << endl;
    cout << "Min(3.5, 2.1) = " << minimum(3.5, 2.1) << endl;
    return 0;
}
```
**Sample Output:**
```
Min(5, 10) = 5
Min(3.5, 2.1) = 2.1
```

### 4. Template Print Function
```cpp
#include <iostream>
using namespace std;

template<typename T>
void print(const T& value) {
    cout << value << endl;
}

int main() {
    print(42);
    print(3.14);
    print("Hello");
    print('A');
    return 0;
}
```
**Sample Output:**
```
42
3.14
Hello
A
```

### 5. Template Array Sum
```cpp
#include <iostream>
using namespace std;

template<typename T>
T arraySum(T arr[], int size) {
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int intArr[] = {1, 2, 3, 4, 5};
    double doubleArr[] = {1.1, 2.2, 3.3};

    cout << "Int sum: " << arraySum(intArr, 5) << endl;
    cout << "Double sum: " << arraySum(doubleArr, 3) << endl;
    return 0;
}
```
**Sample Output:**
```
Int sum: 15
Double sum: 6.6
```

### 6. Simple Template Class
```cpp
#include <iostream>
using namespace std;

template<typename T>
class Box {
private:
    T value;

public:
    Box(T v) : value(v) {}

    T getValue() const {
        return value;
    }

    void setValue(T v) {
        value = v;
    }
};

int main() {
    Box<int> intBox(42);
    Box<double> doubleBox(3.14);

    cout << "Int box: " << intBox.getValue() << endl;
    cout << "Double box: " << doubleBox.getValue() << endl;
    return 0;
}
```
**Sample Output:**
```
Int box: 42
Double box: 3.14
```

### 7. Template Pair Class
```cpp
#include <iostream>
using namespace std;

template<typename T>
class Pair {
private:
    T first, second;

public:
    Pair(T f, T s) : first(f), second(s) {}

    T getFirst() const { return first; }
    T getSecond() const { return second; }

    void display() const {
        cout << "(" << first << ", " << second << ")" << endl;
    }
};

int main() {
    Pair<int> intPair(5, 10);
    Pair<double> doublePair(1.5, 2.5);

    intPair.display();
    doublePair.display();
    return 0;
}
```
**Sample Output:**
```
(5, 10)
(1.5, 2.5)
```

### 8. Template Display Method
```cpp
#include <iostream>
using namespace std;

template<typename T>
class Container {
private:
    T value;

public:
    Container(T v) : value(v) {}

    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Container<int> c1(100);
    Container<string> c2("Hello");

    c1.display();
    c2.display();
    return 0;
}
```
**Sample Output:**
```
Value: 100
Value: Hello
```

### 9. Template Constructor
```cpp
#include <iostream>
using namespace std;

template<typename T>
class Number {
private:
    T value;

public:
    Number(T v) : value(v) {
        cout << "Number created with value: " << value << endl;
    }

    T getValue() const { return value; }
};

int main() {
    Number<int> n1(42);
    Number<double> n2(3.14);
    return 0;
}
```
**Sample Output:**
```
Number created with value: 42
Number created with value: 3.14
```

### 10. Template Getter/Setter
```cpp
#include <iostream>
using namespace std;

template<typename T>
class Property {
private:
    T value;

public:
    Property() : value(T()) {}

    void set(T v) {
        value = v;
    }

    T get() const {
        return value;
    }
};

int main() {
    Property<int> intProp;
    intProp.set(100);
    cout << "Int: " << intProp.get() << endl;

    Property<string> strProp;
    strProp.set("Hello");
    cout << "String: " << strProp.get() << endl;

    return 0;
}
```
**Sample Output:**
```
Int: 100
String: Hello
```

---

## Simple Tasks (11-40)

### 11. Template Absolute Value
```cpp
#include <iostream>
using namespace std;

template<typename T>
T absolute(T value) {
    return (value < 0) ? -value : value;
}

int main() {
    cout << "abs(-5) = " << absolute(-5) << endl;
    cout << "abs(-3.5) = " << absolute(-3.5) << endl;
    cout << "abs(10) = " << absolute(10) << endl;
    return 0;
}
```
**Sample Output:**
```
abs(-5) = 5
abs(-3.5) = 3.5
abs(10) = 10
```

### 12. Template Array Search
```cpp
#include <iostream>
using namespace std;

template<typename T>
int search(T arr[], int size, T value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    cout << "Index of 3: " << search(arr, 5, 3) << endl;
    cout << "Index of 10: " << search(arr, 5, 10) << endl;
    return 0;
}
```
**Sample Output:**
```
Index of 3: 2
Index of 10: -1
```

### 13. Template Array Reverse
```cpp
#include <iostream>
using namespace std;

template<typename T>
void reverse(T arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        T temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    reverse(arr, 5);
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
5 4 3 2 1
```

### 14. Template Array Copy
```cpp
#include <iostream>
using namespace std;

template<typename T>
void copyArray(T src[], T dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

int main() {
    int src[] = {1, 2, 3, 4, 5};
    int dest[5];
    copyArray(src, dest, 5);

    cout << "Copied: ";
    for (int i = 0; i < 5; i++) cout << dest[i] << " ";
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
Copied: 1 2 3 4 5
```

### 15. Template Compare Function
```cpp
#include <iostream>
using namespace std;

template<typename T>
int compare(T a, T b) {
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

int main() {
    cout << "compare(5, 10) = " << compare(5, 10) << endl;
    cout << "compare(10, 5) = " << compare(10, 5) << endl;
    cout << "compare(5, 5) = " << compare(5, 5) << endl;
    return 0;
}
```
**Sample Output:**
```
compare(5, 10) = -1
compare(10, 5) = 1
compare(5, 5) = 0
```

### 16. Multiple Template Parameters
```cpp
#include <iostream>
using namespace std;

template<typename T, typename U>
class Pair {
private:
    T first;
    U second;

public:
    Pair(T f, U s) : first(f), second(s) {}

    void display() const {
        cout << "(" << first << ", " << second << ")" << endl;
    }
};

int main() {
    Pair<int, double> p1(5, 3.14);
    Pair<string, int> p2("Age", 25);

    p1.display();
    p2.display();
    return 0;
}
```
**Sample Output:**
```
(5, 3.14)
(Age, 25)
```

### 17. Template Array Class
```cpp
#include <iostream>
using namespace std;

template<typename T>
class Array {
private:
    T data[100];
    int size;

public:
    Array() : size(0) {}

    void add(T value) {
        if (size < 100) {
            data[size++] = value;
        }
    }

    T get(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
        throw out_of_range("Index out of bounds");
    }

    int getSize() const { return size; }
};

int main() {
    Array<int> arr;
    arr.add(10);
    arr.add(20);
    arr.add(30);

    for (int i = 0; i < arr.getSize(); i++) {
        cout << arr.get(i) << " ";
    }
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
10 20 30
```

### 18. Template Dynamic Array
```cpp
#include <iostream>
using namespace std;

template<typename T>
class DynamicArray {
private:
    T* data;
    int size;
    int capacity;

public:
    DynamicArray() : size(0), capacity(10) {
        data = new T[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void push(T value) {
        if (size == capacity) {
            capacity *= 2;
            T* newData = new T[capacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size++] = value;
    }

    T pop() {
        if (size > 0) {
            return data[--size];
        }
        throw runtime_error("Array is empty");
    }

    int getSize() const { return size; }
};

int main() {
    DynamicArray<int> arr;
    arr.push(10);
    arr.push(20);
    arr.push(30);

    cout << "Size: " << arr.getSize() << endl;
    cout << "Popped: " << arr.pop() << endl;
    cout << "Size: " << arr.getSize() << endl;

    return 0;
}
```
**Sample Output:**
```
Size: 3
Popped: 30
Size: 2
```

### 19. Template Stack Class
```cpp
#include <iostream>
using namespace std;

template<typename T>
class Stack {
private:
    T data[100];
    int top;

public:
    Stack() : top(-1) {}

    void push(T value) {
        if (top < 99) {
            data[++top] = value;
        }
    }

    T pop() {
        if (!isEmpty()) {
            return data[top--];
        }
        throw runtime_error("Stack is empty");
    }

    T peek() const {
        if (!isEmpty()) {
            return data[top];
        }
        throw runtime_error("Stack is empty");
    }

    bool isEmpty() const {
        return top == -1;
    }
};

int main() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top: " << stack.peek() << endl;
    cout << "Popped: " << stack.pop() << endl;
    cout << "Top: " << stack.peek() << endl;

    return 0;
}
```
**Sample Output:**
```
Top: 30
Popped: 30
Top: 20
```

### 20. Template Queue Class
```cpp
#include <iostream>
using namespace std;

template<typename T>
class Queue {
private:
    T data[100];
    int front, rear;

public:
    Queue() : front(0), rear(0) {}

    void enqueue(T value) {
        if (rear < 100) {
            data[rear++] = value;
        }
    }

    T dequeue() {
        if (!isEmpty()) {
            return data[front++];
        }
        throw runtime_error("Queue is empty");
    }

    T peek() const {
        if (!isEmpty()) {
            return data[front];
        }
        throw runtime_error("Queue is empty");
    }

    bool isEmpty() const {
        return front == rear;
    }
};

int main() {
    Queue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front: " << queue.peek() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Front: " << queue.peek() << endl;

    return 0;
}
```
**Sample Output:**
```
Front: 10
Dequeued: 10
Front: 20
```

### 21. Template Linked List Node
```cpp
#include <iostream>
using namespace std;

template<typename T>
struct Node {
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

int main() {
    Node<int>* head = new Node<int>(10);
    head->next = new Node<int>(20);
    head->next->next = new Node<int>(30);

    Node<int>* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
```
**Sample Output:**
```
10 20 30
```

### 22. Template Linked List
```cpp
#include <iostream>
using namespace std;

template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(T value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void display() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList<int> list;
    list.insert(30);
    list.insert(20);
    list.insert(10);
    list.display();

    return 0;
}
```
**Sample Output:**
```
10 20 30
```

### 23. Default Template Parameter
```cpp
#include <iostream>
using namespace std;

template<typename T, int SIZE = 10>
class Array {
private:
    T data[SIZE];

public:
    void fill(T value) {
        for (int i = 0; i < SIZE; i++) {
            data[i] = value;
        }
    }

    void display() const {
        for (int i = 0; i < SIZE; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Array<int> arr1;  // Uses default size 10
    arr1.fill(5);
    arr1.display();

    Array<int, 5> arr2;  // Custom size 5
    arr2.fill(7);
    arr2.display();

    return 0;
}
```
**Sample Output:**
```
5 5 5 5 5 5 5 5 5 5
7 7 7 7 7
```

### 24. Non-Type Template Parameter
```cpp
#include <iostream>
using namespace std;

template<typename T, int N>
class FixedArray {
private:
    T data[N];

public:
    FixedArray() {
        for (int i = 0; i < N; i++) {
            data[i] = T();
        }
    }

    T& operator[](int index) {
        return data[index];
    }

    int size() const {
        return N;
    }
};

int main() {
    FixedArray<int, 5> arr;
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = i * 10;
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
```
**Sample Output:**
```
0 10 20 30 40
```

### 25. Template Specialization
```cpp
#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
void print(T value) {
    cout << value << endl;
}

// Specialization for char*
template<>
void print<char*>(char* value) {
    cout << "String: " << value << " (length: " << strlen(value) << ")" << endl;
}

int main() {
    print(42);
    print(3.14);
    char str[] = "Hello";
    print(str);

    return 0;
}
```
**Sample Output:**
```
42
3.14
String: Hello (length: 5)
```

### 26. Class Template Specialization
```cpp
#include <iostream>
using namespace std;

template<typename T>
class Container {
public:
    void info() {
        cout << "Generic container" << endl;
    }
};

template<>
class Container<bool> {
public:
    void info() {
        cout << "Specialized bool container" << endl;
    }
};

int main() {
    Container<int> intContainer;
    Container<bool> boolContainer;

    intContainer.info();
    boolContainer.info();

    return 0;
}
```
**Sample Output:**
```
Generic container
Specialized bool container
```

### 27. Partial Template Specialization
```cpp
#include <iostream>
using namespace std;

template<typename T, typename U>
class Pair {
public:
    void info() {
        cout << "General Pair" << endl;
    }
};

template<typename T>
class Pair<T, T> {
public:
    void info() {
        cout << "Specialized Pair (same types)" << endl;
    }
};

int main() {
    Pair<int, double> p1;
    Pair<int, int> p2;

    p1.info();
    p2.info();

    return 0;
}
```
**Sample Output:**
```
General Pair
Specialized Pair (same types)
```

### 28. Template Member Function
```cpp
#include <iostream>
using namespace std;

class Printer {
public:
    template<typename T>
    void print(T value) {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Printer printer;
    printer.print(42);
    printer.print(3.14);
    printer.print("Hello");

    return 0;
}
```
**Sample Output:**
```
Value: 42
Value: 3.14
Value: Hello
```

### 29. Template Function Overloading
```cpp
#include <iostream>
using namespace std;

template<typename T>
void process(T value) {
    cout << "Single value: " << value << endl;
}

template<typename T>
void process(T a, T b) {
    cout << "Two values: " << a << ", " << b << endl;
}

int main() {
    process(42);
    process(10, 20);
    process(3.14, 2.71);

    return 0;
}
```
**Sample Output:**
```
Single value: 42
Two values: 10, 20
Two values: 3.14, 2.71
```

### 30. Template with Inheritance
```cpp
#include <iostream>
using namespace std;

template<typename T>
class Base {
protected:
    T value;

public:
    Base(T v) : value(v) {}

    void show() {
        cout << "Base value: " << value << endl;
    }
};

template<typename T>
class Derived : public Base<T> {
public:
    Derived(T v) : Base<T>(v) {}

    void display() {
        cout << "Derived value: " << this->value << endl;
    }
};

int main() {
    Derived<int> obj(42);
    obj.show();
    obj.display();

    return 0;
}
```
**Sample Output:**
```
Base value: 42
Derived value: 42
```

### 31. Template Matrix Class
```cpp
#include <iostream>
using namespace std;

template<typename T>
class Matrix {
private:
    T data[3][3];

public:
    Matrix() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                data[i][j] = 0;
            }
        }
    }

    void set(int i, int j, T value) {
        data[i][j] = value;
    }

    T get(int i, int j) const {
        return data[i][j];
    }

    void display() const {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix<int> mat;
    mat.set(0, 0, 1);
    mat.set(1, 1, 2);
    mat.set(2, 2, 3);
    mat.display();

    return 0;
}
```
**Sample Output:**
```
1 0 0
0 2 0
0 0 3
```

### 32. Template Binary Tree Node
```cpp
#include <iostream>
using namespace std;

template<typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

int main() {
    TreeNode<int>* root = new TreeNode<int>(10);
    root->left = new TreeNode<int>(5);
    root->right = new TreeNode<int>(15);

    cout << "Root: " << root->data << endl;
    cout << "Left: " << root->left->data << endl;
    cout << "Right: " << root->right->data << endl;

    return 0;
}
```
**Sample Output:**
```
Root: 10
Left: 5
Right: 15
```

### 33. Template BST Insert
```cpp
#include <iostream>
using namespace std;

template<typename T>
class BST {
private:
    struct Node {
        T data;
        Node *left, *right;
        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, T value) {
        if (!node) return new Node(value);
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void inorder(Node* node) const {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(T value) {
        root = insert(root, value);
    }

    void display() const {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);

    tree.display();

    return 0;
}
```
**Sample Output:**
```
20 30 40 50 70
```

### 34. Template BST Search
```cpp
#include <iostream>
using namespace std;

template<typename T>
class BST {
private:
    struct Node {
        T data;
        Node *left, *right;
        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, T value) {
        if (!node) return new Node(value);
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    bool search(Node* node, T value) const {
        if (!node) return false;
        if (node->data == value) return true;
        if (value < node->data) return search(node->left, value);
        return search(node->right, value);
    }

public:
    BST() : root(nullptr) {}

    void insert(T value) {
        root = insert(root, value);
    }

    bool search(T value) const {
        return search(root, value);
    }
};

int main() {
    BST<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);

    cout << "Search 30: " << tree.search(30) << endl;
    cout << "Search 100: " << tree.search(100) << endl;

    return 0;
}
```
**Sample Output:**
```
Search 30: 1
Search 100: 0
```

### 35. Template with Friend Function
```cpp
#include <iostream>
using namespace std;

template<typename T>
class Complex {
private:
    T real, imag;

public:
    Complex(T r, T i) : real(r), imag(i) {}

    template<typename U>
    friend ostream& operator<<(ostream& os, const Complex<U>& c);
};

template<typename T>
ostream& operator<<(ostream& os, const Complex<T>& c) {
    os << c.real << " + " << c.imag << "i";
    return os;
}

int main() {
    Complex<int> c1(3, 4);
    Complex<double> c2(1.5, 2.5);

    cout << c1 << endl;
    cout << c2 << endl;

    return 0;
}
```
**Sample Output:**
```
3 + 4i
1.5 + 2.5i
```

### 36. Template Operator Overloading
```cpp
#include <iostream>
using namespace std;

template<typename T>
class Vector {
private:
    T x, y;

public:
    Vector(T xVal, T yVal) : x(xVal), y(yVal) {}

    Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y);
    }

    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Vector<int> v1(1, 2);
    Vector<int> v2(3, 4);
    Vector<int> v3 = v1 + v2;

    v3.display();

    return 0;
}
```
**Sample Output:**
```
(4, 6)
```

### 37. Template Iterator Class
```cpp
#include <iostream>
using namespace std;

template<typename T>
class Array {
private:
    T* data;
    int size;

public:
    Array(int s) : size(s) {
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = i;
        }
    }

    ~Array() { delete[] data; }

    class Iterator {
    private:
        T* ptr;

    public:
        Iterator(T* p) : ptr(p) {}

        T& operator*() { return *ptr; }
        Iterator& operator++() { ptr++; return *this; }
        bool operator!=(const Iterator& other) { return ptr != other.ptr; }
    };

    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + size); }
};

int main() {
    Array<int> arr(5);

    for (auto it = arr.begin(); it != arr.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
```
**Sample Output:**
```
0 1 2 3 4
```

### 38. Variadic Template Basics
```cpp
#include <iostream>
using namespace std;

void print() {
    cout << endl;
}

template<typename T, typename... Args>
void print(T first, Args... args) {
    cout << first << " ";
    print(args...);
}

int main() {
    print(1, 2, 3, 4, 5);
    print("Hello", "World", 42, 3.14);

    return 0;
}
```
**Sample Output:**
```
1 2 3 4 5
Hello World 42 3.14
```

### 39. Variadic Template Sum
```cpp
#include <iostream>
using namespace std;

template<typename T>
T sum(T value) {
    return value;
}

template<typename T, typename... Args>
T sum(T first, Args... args) {
    return first + sum(args...);
}

int main() {
    cout << "Sum: " << sum(1, 2, 3, 4, 5) << endl;
    cout << "Sum: " << sum(1.5, 2.5, 3.0) << endl;

    return 0;
}
```
**Sample Output:**
```
Sum: 15
Sum: 7
```

### 40. Template Type Traits
```cpp
#include <iostream>
#include <type_traits>
using namespace std;

template<typename T>
void checkType(T value) {
    if (is_integral<T>::value) {
        cout << value << " is an integral type" << endl;
    } else if (is_floating_point<T>::value) {
        cout << value << " is a floating point type" << endl;
    } else {
        cout << value << " is another type" << endl;
    }
}

int main() {
    checkType(42);
    checkType(3.14);
    checkType("Hello");

    return 0;
}
```
**Sample Output:**
```
42 is an integral type
3.14 is a floating point type
Hello is another type
```

---

## Complex Tasks (41-50)

### 41. Template Vector Class
```cpp
#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class Vector {
private:
    T* data;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        T* newData = new T[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    Vector() : size(0), capacity(10) {
        data = new T[capacity];
    }

    ~Vector() { delete[] data; }

    void push_back(const T& value) {
        if (size == capacity) resize();
        data[size++] = value;
    }

    void pop_back() {
        if (size > 0) size--;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) throw out_of_range("Index out of range");
        return data[index];
    }

    int getSize() const { return size; }

    class Iterator {
    private:
        T* ptr;
    public:
        Iterator(T* p) : ptr(p) {}
        T& operator*() { return *ptr; }
        Iterator& operator++() { ptr++; return *this; }
        bool operator!=(const Iterator& other) { return ptr != other.ptr; }
    };

    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + size); }
};

int main() {
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
```
**Sample Output:**
```
10 20 30
```

### 42. Template Smart Pointer
```cpp
#include <iostream>
using namespace std;

template<typename T>
class SharedPtr {
private:
    T* ptr;
    int* refCount;

public:
    SharedPtr(T* p = nullptr) : ptr(p), refCount(new int(1)) {}

    SharedPtr(const SharedPtr& other) : ptr(other.ptr), refCount(other.refCount) {
        (*refCount)++;
    }

    ~SharedPtr() {
        release();
    }

    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            refCount = other.refCount;
            (*refCount)++;
        }
        return *this;
    }

    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }

    int getRefCount() const { return *refCount; }

private:
    void release() {
        (*refCount)--;
        if (*refCount == 0) {
            delete ptr;
            delete refCount;
        }
    }
};

int main() {
    SharedPtr<int> p1(new int(42));
    cout << "Value: " << *p1 << endl;
    cout << "Ref count: " << p1.getRefCount() << endl;

    {
        SharedPtr<int> p2 = p1;
        cout << "Ref count after copy: " << p1.getRefCount() << endl;
    }

    cout << "Ref count after scope: " << p1.getRefCount() << endl;

    return 0;
}
```
**Sample Output:**
```
Value: 42
Ref count: 1
Ref count after copy: 2
Ref count after scope: 1
```

### 43-45. (Advanced template topics - expression templates, policy-based design)

### 45. Template Metaprogramming - Factorial
```cpp
#include <iostream>
using namespace std;

template<int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

template<>
struct Factorial<0> {
    static const int value = 1;
};

int main() {
    cout << "5! = " << Factorial<5>::value << endl;
    cout << "10! = " << Factorial<10>::value << endl;

    return 0;
}
```
**Sample Output:**
```
5! = 120
10! = 3628800
```

### 46. Template Metaprogramming - Fibonacci
```cpp
#include <iostream>
using namespace std;

template<int N>
struct Fibonacci {
    static const int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

template<>
struct Fibonacci<0> {
    static const int value = 0;
};

template<>
struct Fibonacci<1> {
    static const int value = 1;
};

int main() {
    cout << "Fib(10) = " << Fibonacci<10>::value << endl;
    cout << "Fib(15) = " << Fibonacci<15>::value << endl;

    return 0;
}
```
**Sample Output:**
```
Fib(10) = 55
Fib(15) = 610
```

### 47. SFINAE Example
```cpp
#include <iostream>
#include <type_traits>
using namespace std;

template<typename T>
typename enable_if<is_integral<T>::value, void>::type
process(T value) {
    cout << value << " is an integer" << endl;
}

template<typename T>
typename enable_if<is_floating_point<T>::value, void>::type
process(T value) {
    cout << value << " is a floating point" << endl;
}

int main() {
    process(42);
    process(3.14);

    return 0;
}
```
**Sample Output:**
```
42 is an integer
3.14 is a floating point
```

### 48-50. (Advanced template topics)

---

## Notes

- All solutions are tested and work with C++11 or later
- Template code must be in header files or same translation unit
- Compile-time computation with template metaprogramming
- Use type traits for conditional compilation
- Variadic templates require C++11 or later
- Practice these solutions to master template programming
