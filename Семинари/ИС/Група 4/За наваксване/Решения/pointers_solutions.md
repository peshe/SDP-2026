# Pointers Practice - Solutions

Complete solutions with sample usage for all 50 pointer tasks.

---

## Trivial Tasks (1-10)

### 1. Declare and Initialize
```cpp
#include <iostream>
using namespace std;

int main() {
    int num = 42;
    int* ptr = &num;

    cout << "Value: " << num << endl;
    cout << "Address: " << ptr << endl;
    cout << "Value via pointer: " << *ptr << endl;
    return 0;
}
```
**Sample Output:**
```
Value: 42
Address: 0x7ffeeb3d8a4c
Value via pointer: 42
```

### 2. Pointer Dereferencing
```cpp
#include <iostream>
using namespace std;

int main() {
    int num = 10;
    int* ptr = &num;

    cout << "Before: " << num << endl;
    *ptr = 20;  // Modify through pointer
    cout << "After: " << num << endl;
    return 0;
}
```
**Sample Output:**
```
Before: 10
After: 20
```

### 3. Null Pointer Check
```cpp
#include <iostream>
using namespace std;

int main() {
    int* ptr = nullptr;

    if (ptr == nullptr) {
        cout << "Pointer is null, cannot dereference" << endl;
    } else {
        cout << "Value: " << *ptr << endl;
    }
    return 0;
}
```
**Sample Output:**
```
Pointer is null, cannot dereference
```

### 4. Pointer to Float
```cpp
#include <iostream>
using namespace std;

int main() {
    float num = 0.0f;
    float* ptr = &num;

    *ptr = 3.14f;
    cout << "Float value: " << num << endl;
    return 0;
}
```
**Sample Output:**
```
Float value: 3.14
```

### 5. Address Arithmetic Basics
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20;
    int* ptr1 = &a;
    int* ptr2 = &b;

    cout << "Address of a: " << ptr1 << endl;
    cout << "Address of b: " << ptr2 << endl;
    cout << "Difference: " << (ptr2 - ptr1) << " elements" << endl;
    return 0;
}
```
**Sample Output:**
```
Address of a: 0x7ffeeb3d8a48
Address of b: 0x7ffeeb3d8a44
Difference: -1 elements
```

### 6. Pointer Assignment
```cpp
#include <iostream>
using namespace std;

int main() {
    int num = 100;
    int* ptr1 = &num;
    int* ptr2 = ptr1;  // Both point to same location

    *ptr1 = 200;
    cout << "Modified via ptr1, read via ptr2: " << *ptr2 << endl;
    return 0;
}
```
**Sample Output:**
```
Modified via ptr1, read via ptr2: 200
```

### 7. Const Pointer
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20;
    int* const ptr = &a;  // Const pointer

    *ptr = 15;  // OK: can change value
    cout << "Value: " << *ptr << endl;
    // ptr = &b;  // ERROR: cannot change pointer
    return 0;
}
```
**Sample Output:**
```
Value: 15
```

### 8. Pointer to Const
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20;
    const int* ptr = &a;  // Pointer to const

    cout << "Value: " << *ptr << endl;
    // *ptr = 15;  // ERROR: cannot change value through pointer
    ptr = &b;  // OK: can change pointer
    cout << "New value: " << *ptr << endl;
    return 0;
}
```
**Sample Output:**
```
Value: 10
New value: 20
```

### 9. Size of Pointer
```cpp
#include <iostream>
using namespace std;

int main() {
    int* intPtr;
    char* charPtr;
    double* doublePtr;

    cout << "Size of int*: " << sizeof(intPtr) << endl;
    cout << "Size of char*: " << sizeof(charPtr) << endl;
    cout << "Size of double*: " << sizeof(doublePtr) << endl;
    return 0;
}
```
**Sample Output:**
```
Size of int*: 8
Size of char*: 8
Size of double*: 8
```

### 10. Swap Using Pointers
```cpp
#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    cout << "Before: x=" << x << ", y=" << y << endl;
    swap(&x, &y);
    cout << "After: x=" << x << ", y=" << y << endl;
    return 0;
}
```
**Sample Output:**
```
Before: x=5, y=10
After: x=10, y=5
```

---

## Simple Tasks (11-40)

### 11. Array Access via Pointer
```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int* ptr = arr;

    for (int i = 0; i < 5; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
10 20 30 40 50
```

### 12. Pointer Arithmetic Increment
```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int* ptr = arr;

    for (int i = 0; i < 5; i++, ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
1 2 3 4 5
```

### 13. Pointer Arithmetic Decrement
```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int* ptr = arr + 4;  // Point to last element

    for (int i = 0; i < 5; i++, ptr--) {
        cout << *ptr << " ";
    }
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
5 4 3 2 1
```

### 14. Pointer Addition
```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int* ptr = arr;

    for (int i = 0; i < 6; i += 2) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
10 30 50
```

### 15. Pointer Subtraction
```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* start = arr + 2;
    int* end = arr + 7;

    cout << "Elements between: " << (end - start) << endl;
    return 0;
}
```
**Sample Output:**
```
Elements between: 5
```

### 16. Array Sum via Pointer
```cpp
#include <iostream>
using namespace std;

int arraySum(int* arr, int size) {
    int sum = 0;
    int* end = arr + size;
    for (int* ptr = arr; ptr < end; ptr++) {
        sum += *ptr;
    }
    return sum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    cout << "Sum: " << arraySum(arr, 5) << endl;
    return 0;
}
```
**Sample Output:**
```
Sum: 15
```

### 17. Find Maximum via Pointer
```cpp
#include <iostream>
using namespace std;

int findMax(int* arr, int size) {
    int max = *arr;
    for (int* ptr = arr + 1; ptr < arr + size; ptr++) {
        if (*ptr > max) max = *ptr;
    }
    return max;
}

int main() {
    int arr[] = {3, 7, 2, 9, 1};
    cout << "Max: " << findMax(arr, 5) << endl;
    return 0;
}
```
**Sample Output:**
```
Max: 9
```

### 18. Find Minimum via Pointer
```cpp
#include <iostream>
using namespace std;

int findMin(int* arr, int size) {
    int min = *arr;
    for (int* ptr = arr + 1; ptr < arr + size; ptr++) {
        if (*ptr < min) min = *ptr;
    }
    return min;
}

int main() {
    int arr[] = {3, 7, 2, 9, 1};
    cout << "Min: " << findMin(arr, 5) << endl;
    return 0;
}
```
**Sample Output:**
```
Min: 1
```

### 19. Reverse Array with Pointers
```cpp
#include <iostream>
using namespace std;

void reverseArray(int* arr, int size) {
    int* start = arr;
    int* end = arr + size - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    reverseArray(arr, 5);

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
5 4 3 2 1
```

### 20. Copy Array with Pointers
```cpp
#include <iostream>
using namespace std;

void copyArray(int* src, int* dest, int size) {
    int* srcEnd = src + size;
    while (src < srcEnd) {
        *dest++ = *src++;
    }
}

int main() {
    int src[] = {1, 2, 3, 4, 5};
    int dest[5];

    copyArray(src, dest, 5);

    for (int i = 0; i < 5; i++) {
        cout << dest[i] << " ";
    }
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
1 2 3 4 5
```

### 21. Compare Arrays with Pointers
```cpp
#include <iostream>
using namespace std;

bool compareArrays(int* arr1, int* arr2, int size) {
    int* end = arr1 + size;
    while (arr1 < end) {
        if (*arr1++ != *arr2++) return false;
    }
    return true;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 5};
    int arr3[] = {1, 2, 3, 4, 6};

    cout << "arr1 == arr2: " << compareArrays(arr1, arr2, 5) << endl;
    cout << "arr1 == arr3: " << compareArrays(arr1, arr3, 5) << endl;
    return 0;
}
```
**Sample Output:**
```
arr1 == arr2: 1
arr1 == arr3: 0
```

### 22. Pointer to Pointer Basics
```cpp
#include <iostream>
using namespace std;

int main() {
    int num = 42;
    int* ptr = &num;
    int** pptr = &ptr;

    cout << "Value via double dereference: " << **pptr << endl;
    **pptr = 100;
    cout << "Modified value: " << num << endl;
    return 0;
}
```
**Sample Output:**
```
Value via double dereference: 42
Modified value: 100
```

### 23. Modify Pointer via Function
```cpp
#include <iostream>
using namespace std;

void modifyPointer(int** pptr, int* newTarget) {
    *pptr = newTarget;
}

int main() {
    int a = 10, b = 20;
    int* ptr = &a;

    cout << "Before: " << *ptr << endl;
    modifyPointer(&ptr, &b);
    cout << "After: " << *ptr << endl;
    return 0;
}
```
**Sample Output:**
```
Before: 10
After: 20
```

### 24. Array of Pointers
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20, c = 30, d = 40, e = 50;
    int* ptrs[5] = {&a, &b, &c, &d, &e};

    for (int i = 0; i < 5; i++) {
        cout << *ptrs[i] << " ";
    }
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
10 20 30 40 50
```

### 25. Pointer Array Initialization
```cpp
#include <iostream>
using namespace std;

int main() {
    const char* strings[] = {"Hello", "World", "C++", "Pointers", "Array"};

    for (int i = 0; i < 5; i++) {
        cout << strings[i] << endl;
    }
    return 0;
}
```
**Sample Output:**
```
Hello
World
C++
Pointers
Array
```

### 26. Dynamic Single Integer
```cpp
#include <iostream>
using namespace std;

int main() {
    int* ptr = new int;
    *ptr = 42;

    cout << "Value: " << *ptr << endl;
    delete ptr;
    ptr = nullptr;

    return 0;
}
```
**Sample Output:**
```
Value: 42
```

### 27. Find Element via Pointer
```cpp
#include <iostream>
using namespace std;

int* findElement(int* arr, int size, int value) {
    int* end = arr + size;
    for (int* ptr = arr; ptr < end; ptr++) {
        if (*ptr == value) return ptr;
    }
    return nullptr;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int* result = findElement(arr, 5, 30);

    if (result != nullptr) {
        cout << "Found: " << *result << endl;
    } else {
        cout << "Not found" << endl;
    }
    return 0;
}
```
**Sample Output:**
```
Found: 30
```

### 28. Count Occurrences via Pointer
```cpp
#include <iostream>
using namespace std;

int countOccurrences(int* arr, int size, int value) {
    int count = 0;
    int* end = arr + size;
    for (int* ptr = arr; ptr < end; ptr++) {
        if (*ptr == value) count++;
    }
    return count;
}

int main() {
    int arr[] = {1, 2, 3, 2, 4, 2, 5};
    cout << "Count of 2: " << countOccurrences(arr, 7, 2) << endl;
    return 0;
}
```
**Sample Output:**
```
Count of 2: 3
```

### 29. Pointer to Structure
```cpp
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    Point p = {10, 20};
    Point* ptr = &p;

    cout << "x: " << ptr->x << ", y: " << ptr->y << endl;
    ptr->x = 30;
    cout << "Modified x: " << ptr->x << endl;
    return 0;
}
```
**Sample Output:**
```
x: 10, y: 20
Modified x: 30
```

### 30. Array of Structures via Pointer
```cpp
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    Point points[] = {{1, 2}, {3, 4}, {5, 6}};
    Point* ptr = points;

    for (int i = 0; i < 3; i++, ptr++) {
        cout << "(" << ptr->x << ", " << ptr->y << ")" << endl;
    }
    return 0;
}
```
**Sample Output:**
```
(1, 2)
(3, 4)
(5, 6)
```

### 31. Function Returning Pointer
```cpp
#include <iostream>
using namespace std;

int* findLargest(int* arr, int size) {
    int* largest = arr;
    for (int* ptr = arr + 1; ptr < arr + size; ptr++) {
        if (*ptr > *largest) largest = ptr;
    }
    return largest;
}

int main() {
    int arr[] = {3, 7, 2, 9, 1};
    int* result = findLargest(arr, 5);
    cout << "Largest: " << *result << endl;
    return 0;
}
```
**Sample Output:**
```
Largest: 9
```

### 32. Multiple Indirection
```cpp
#include <iostream>
using namespace std;

int main() {
    int num = 42;
    int* p1 = &num;
    int** p2 = &p1;
    int*** p3 = &p2;

    cout << "Original: " << num << endl;
    ***p3 = 100;
    cout << "Modified: " << num << endl;
    return 0;
}
```
**Sample Output:**
```
Original: 42
Modified: 100
```

### 33. Void Pointer Basics
```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 42;
    float f = 3.14f;
    char c = 'A';

    void* ptr;

    ptr = &i;
    cout << "Int: " << *(int*)ptr << endl;

    ptr = &f;
    cout << "Float: " << *(float*)ptr << endl;

    ptr = &c;
    cout << "Char: " << *(char*)ptr << endl;

    return 0;
}
```
**Sample Output:**
```
Int: 42
Float: 3.14
Char: A
```

### 34. Generic Swap with Void Pointers
```cpp
#include <iostream>
#include <cstring>
using namespace std;

void genericSwap(void* a, void* b, size_t size) {
    char* temp = new char[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    delete[] temp;
}

int main() {
    int x = 10, y = 20;
    cout << "Before: x=" << x << ", y=" << y << endl;
    genericSwap(&x, &y, sizeof(int));
    cout << "After: x=" << x << ", y=" << y << endl;

    double d1 = 1.5, d2 = 2.5;
    cout << "Before: d1=" << d1 << ", d2=" << d2 << endl;
    genericSwap(&d1, &d2, sizeof(double));
    cout << "After: d1=" << d1 << ", d2=" << d2 << endl;

    return 0;
}
```
**Sample Output:**
```
Before: x=10, y=20
After: x=20, y=10
Before: d1=1.5, d2=2.5
After: d1=2.5, d2=1.5
```

### 35. Pointer to Function Basics
```cpp
#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int main() {
    int (*funcPtr)(int, int) = add;

    cout << "5 + 3 = " << funcPtr(5, 3) << endl;
    return 0;
}
```
**Sample Output:**
```
5 + 3 = 8
```

### 36. Function Pointer Array
```cpp
#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

int main() {
    int (*operations[4])(int, int) = {add, subtract, multiply, divide};
    const char* names[] = {"Add", "Subtract", "Multiply", "Divide"};

    for (int i = 0; i < 4; i++) {
        cout << names[i] << "(10, 2) = " << operations[i](10, 2) << endl;
    }
    return 0;
}
```
**Sample Output:**
```
Add(10, 2) = 12
Subtract(10, 2) = 8
Multiply(10, 2) = 20
Divide(10, 2) = 5
```

### 37. Callback Function via Pointer
```cpp
#include <iostream>
using namespace std;

void applyFunction(int* arr, int size, int (*func)(int)) {
    for (int i = 0; i < size; i++) {
        arr[i] = func(arr[i]);
    }
}

int square(int x) { return x * x; }

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    applyFunction(arr, 5, square);

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
1 4 9 16 25
```

### 38. Const Correctness Practice
```cpp
#include <iostream>
using namespace std;

void printArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
        // arr[i] = 0;  // ERROR: cannot modify through const pointer
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    printArray(arr, 5);
    return 0;
}
```
**Sample Output:**
```
1 2 3 4 5
```

### 39. Pointer Comparison
```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int* ptr1 = &arr[1];
    int* ptr2 = &arr[3];

    cout << "ptr1 < ptr2: " << (ptr1 < ptr2) << endl;
    cout << "ptr1 == ptr2: " << (ptr1 == ptr2) << endl;

    ptr1 = ptr2;
    cout << "After assignment, ptr1 == ptr2: " << (ptr1 == ptr2) << endl;

    return 0;
}
```
**Sample Output:**
```
ptr1 < ptr2: 1
ptr1 == ptr2: 0
After assignment, ptr1 == ptr2: 1
```

### 40. Reference vs Pointer
```cpp
#include <iostream>
using namespace std;

void incrementByPointer(int* ptr) {
    if (ptr != nullptr) {
        (*ptr)++;
    }
}

void incrementByReference(int& ref) {
    ref++;
}

int main() {
    int x = 10;

    incrementByPointer(&x);
    cout << "After pointer increment: " << x << endl;

    incrementByReference(x);
    cout << "After reference increment: " << x << endl;

    // Pointer can be null
    int* ptr = nullptr;
    incrementByPointer(ptr);  // Safe

    // Reference cannot be null (must always refer to valid object)
    // incrementByReference(*ptr);  // Would crash

    return 0;
}
```
**Sample Output:**
```
After pointer increment: 11
After reference increment: 12
```

---

## Complex Tasks (41-50)

### 41. 2D Array via Pointer-to-Pointer
```cpp
#include <iostream>
using namespace std;

int main() {
    int rows = 3, cols = 4;

    // Allocate array of row pointers
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    // Fill matrix
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value++;
        }
    }

    // Print matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
```
**Sample Output:**
```
1 2 3 4
5 6 7 8
9 10 11 12
```

### 42. Matrix Operations with Pointers
```cpp
#include <iostream>
using namespace std;

void addMatrices(int* mat1, int* mat2, int* result, int rows, int cols) {
    int* end = mat1 + (rows * cols);
    while (mat1 < end) {
        *result++ = *mat1++ + *mat2++;
    }
}

void printMatrix(int* mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << *(mat + i * cols + j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int mat1[] = {1, 2, 3, 4, 5, 6};
    int mat2[] = {6, 5, 4, 3, 2, 1};
    int result[6];

    addMatrices(mat1, mat2, result, 2, 3);

    cout << "Result:" << endl;
    printMatrix(result, 2, 3);

    return 0;
}
```
**Sample Output:**
```
Result:
7 7 7
7 7 7
```

### 43. Linked List Node Insertion
```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtHead(Node** head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insertAtHead(&head, 3);
    insertAtHead(&head, 2);
    insertAtHead(&head, 1);

    printList(head);

    // Clean up
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
```
**Sample Output:**
```
1 2 3
```

### 44. Linked List Traversal
```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtHead(Node** head, int value) {
    Node* newNode = new Node{value, *head};
    *head = newNode;
}

int countNodes(Node* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}

void printList(Node* head) {
    Node* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    for (int i = 5; i >= 1; i--) {
        insertAtHead(&head, i);
    }

    cout << "List: ";
    printList(head);
    cout << "Count: " << countNodes(head) << endl;

    return 0;
}
```
**Sample Output:**
```
List: 1 2 3 4 5
Count: 5
```

### 45. Smart Pointer-like Wrapper
```cpp
#include <iostream>
using namespace std;

template<typename T>
class SimpleSmartPtr {
private:
    T* ptr;
public:
    SimpleSmartPtr(T* p = nullptr) : ptr(p) {}

    ~SimpleSmartPtr() {
        delete ptr;
        cout << "Memory deallocated" << endl;
    }

    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }

    // Prevent copying
    SimpleSmartPtr(const SimpleSmartPtr&) = delete;
    SimpleSmartPtr& operator=(const SimpleSmartPtr&) = delete;
};

int main() {
    {
        SimpleSmartPtr<int> ptr(new int(42));
        cout << "Value: " << *ptr << endl;
    }  // Automatic deallocation

    cout << "Out of scope" << endl;
    return 0;
}
```
**Sample Output:**
```
Value: 42
Memory deallocated
Out of scope
```

### 46. Pointer-Based Quick Sort
```cpp
#include <iostream>
using namespace std;

int* partition(int* low, int* high) {
    int pivot = *high;
    int* i = low - 1;

    for (int* j = low; j < high; j++) {
        if (*j <= pivot) {
            i++;
            swap(*i, *j);
        }
    }
    swap(*(i + 1), *high);
    return i + 1;
}

void quickSort(int* low, int* high) {
    if (low < high) {
        int* pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = 6;

    quickSort(arr, arr + size - 1);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
```
**Sample Output:**
```
1 5 7 8 9 10
```

### 47. Dynamic Ragged Array
```cpp
#include <iostream>
using namespace std;

int main() {
    int rows = 4;
    int colSizes[] = {2, 3, 4, 2};

    // Allocate ragged array
    int** ragged = new int*[rows];
    for (int i = 0; i < rows; i++) {
        ragged[i] = new int[colSizes[i]];
    }

    // Fill with values
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colSizes[i]; j++) {
            ragged[i][j] = value++;
        }
    }

    // Print
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colSizes[i]; j++) {
            cout << ragged[i][j] << " ";
        }
        cout << endl;
    }

    // Cleanup
    for (int i = 0; i < rows; i++) {
        delete[] ragged[i];
    }
    delete[] ragged;

    return 0;
}
```
**Sample Output:**
```
1 2
3 4 5
6 7 8 9
10 11
```

### 48. Function Pointer Dispatcher
```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

void cmdAdd() { cout << "Executing ADD command" << endl; }
void cmdDelete() { cout << "Executing DELETE command" << endl; }
void cmdList() { cout << "Executing LIST command" << endl; }
void cmdHelp() { cout << "Executing HELP command" << endl; }

int main() {
    map<string, void(*)()> dispatcher;
    dispatcher["add"] = cmdAdd;
    dispatcher["delete"] = cmdDelete;
    dispatcher["list"] = cmdList;
    dispatcher["help"] = cmdHelp;

    string commands[] = {"add", "list", "help", "delete"};

    for (const string& cmd : commands) {
        if (dispatcher.find(cmd) != dispatcher.end()) {
            dispatcher[cmd]();
        }
    }

    return 0;
}
```
**Sample Output:**
```
Executing ADD command
Executing LIST command
Executing HELP command
Executing DELETE command
```

### 49. Pointer-Based Binary Search
```cpp
#include <iostream>
using namespace std;

int* binarySearch(int* start, int* end, int target) {
    while (start <= end) {
        int* mid = start + (end - start) / 2;

        if (*mid == target) {
            return mid;
        } else if (*mid < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return nullptr;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = 8;

    int* result = binarySearch(arr, arr + size - 1, 7);

    if (result != nullptr) {
        cout << "Found: " << *result << " at index " << (result - arr) << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}
```
**Sample Output:**
```
Found: 7 at index 3
```

### 50. Custom Memory Pool
```cpp
#include <iostream>
#include <cstddef>
using namespace std;

class MemoryPool {
private:
    char* pool;
    size_t poolSize;
    char* nextFree;

public:
    MemoryPool(size_t size) : poolSize(size) {
        pool = new char[size];
        nextFree = pool;
        cout << "Memory pool created: " << size << " bytes" << endl;
    }

    ~MemoryPool() {
        delete[] pool;
        cout << "Memory pool destroyed" << endl;
    }

    void* allocate(size_t size) {
        if (nextFree + size > pool + poolSize) {
            cout << "Pool exhausted!" << endl;
            return nullptr;
        }
        void* ptr = nextFree;
        nextFree += size;
        return ptr;
    }

    void reset() {
        nextFree = pool;
        cout << "Pool reset" << endl;
    }

    size_t available() const {
        return poolSize - (nextFree - pool);
    }
};

int main() {
    MemoryPool pool(1024);

    int* a = (int*)pool.allocate(sizeof(int));
    *a = 42;
    cout << "Allocated int: " << *a << endl;

    double* b = (double*)pool.allocate(sizeof(double));
    *b = 3.14;
    cout << "Allocated double: " << *b << endl;

    cout << "Available: " << pool.available() << " bytes" << endl;

    pool.reset();
    cout << "Available after reset: " << pool.available() << " bytes" << endl;

    return 0;
}
```
**Sample Output:**
```
Memory pool created: 1024 bytes
Allocated int: 42
Allocated double: 3.14
Available: 1012 bytes
Pool reset
Available after reset: 1024 bytes
Memory pool destroyed
```

---

## Notes

- All solutions are tested and work with standard C++11 or later
- Remember to compile with `-std=c++11` or higher
- Use valgrind or sanitizers to check for memory leaks
- Practice these solutions multiple times to build muscle memory
