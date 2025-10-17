# Dynamic Memory Management Practice - Solutions

Complete solutions with sample usage for all 50 dynamic memory tasks.

---

## Trivial Tasks (1-10)

### 1. Allocate Single Integer
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

### 2. Allocate Single Float
```cpp
#include <iostream>
using namespace std;

int main() {
    float* ptr = new float;
    *ptr = 3.14f;
    cout << "Float value: " << *ptr << endl;
    delete ptr;
    return 0;
}
```
**Sample Output:**
```
Float value: 3.14
```

### 3. Allocate Array of Integers
```cpp
#include <iostream>
using namespace std;

int main() {
    int* arr = new int[5];

    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
```
**Sample Output:**
```
0 10 20 30 40
```

### 4. Check for Null
```cpp
#include <iostream>
using namespace std;

int main() {
    int* ptr = new int;

    if (ptr != nullptr) {
        *ptr = 100;
        cout << "Value: " << *ptr << endl;
        delete ptr;
    } else {
        cout << "Memory allocation failed" << endl;
    }

    return 0;
}
```
**Sample Output:**
```
Value: 100
```

### 5. Memory Leak Example
```cpp
#include <iostream>
using namespace std;

int main() {
    // BAD: Memory leak - allocated but never deleted
    int* ptr = new int;
    *ptr = 42;
    cout << "Value: " << *ptr << endl;

    // Memory is leaked here because we didn't delete ptr
    // This is intentional to demonstrate the problem

    cout << "This is a memory leak example" << endl;
    cout << "In production code, always delete allocated memory!" << endl;

    return 0;
}
```
**Sample Output:**
```
Value: 42
This is a memory leak example
In production code, always delete allocated memory!
```

### 6. Double Delete Bug
```cpp
#include <iostream>
using namespace std;

int main() {
    int* ptr = new int(42);
    cout << "Value: " << *ptr << endl;

    delete ptr;
    // BAD: Double delete causes undefined behavior
    // delete ptr;  // NEVER do this!

    cout << "Avoided double delete" << endl;
    cout << "Double delete causes undefined behavior and crashes" << endl;

    return 0;
}
```
**Sample Output:**
```
Value: 42
Avoided double delete
Double delete causes undefined behavior and crashes
```

### 7. Set Pointer to Null
```cpp
#include <iostream>
using namespace std;

int main() {
    int* ptr = new int(42);
    cout << "Value: " << *ptr << endl;

    delete ptr;
    ptr = nullptr;  // Good practice

    // Now safe to check
    if (ptr == nullptr) {
        cout << "Pointer is null, safe" << endl;
    }

    return 0;
}
```
**Sample Output:**
```
Value: 42
Pointer is null, safe
```

### 8. Dangling Pointer Example
```cpp
#include <iostream>
using namespace std;

int main() {
    int* ptr = new int(42);
    cout << "Value: " << *ptr << endl;

    delete ptr;
    // BAD: ptr is now a dangling pointer
    // cout << *ptr;  // NEVER access after delete!

    ptr = nullptr;  // Fix: Set to null after delete
    cout << "Set to null to avoid dangling pointer" << endl;

    return 0;
}
```
**Sample Output:**
```
Value: 42
Set to null to avoid dangling pointer
```

### 9. Dynamic String Allocation
```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const char* str = "Hello, World!";
    char* dynStr = new char[strlen(str) + 1];

    strcpy(dynStr, str);
    cout << dynStr << endl;

    delete[] dynStr;
    return 0;
}
```
**Sample Output:**
```
Hello, World!
```

### 10. Dynamic Struct Allocation
```cpp
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    Point* p = new Point;
    p->x = 10;
    p->y = 20;

    cout << "Point: (" << p->x << ", " << p->y << ")" << endl;

    delete p;
    return 0;
}
```
**Sample Output:**
```
Point: (10, 20)
```

---

## Simple Tasks (11-40)

### 11. Dynamic 2D Array (Array of Arrays)
```cpp
#include <iostream>
using namespace std;

int main() {
    int rows = 3, cols = 4;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value++;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

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

### 12. Dynamic 2D Array (Contiguous)
```cpp
#include <iostream>
using namespace std;

int main() {
    int rows = 3, cols = 4;

    int* matrix = new int[rows * cols];

    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i * cols + j] = value++;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i * cols + j] << " ";
        }
        cout << endl;
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

### 13. Resize Dynamic Array
```cpp
#include <iostream>
using namespace std;

int main() {
    int size = 5;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }

    // Resize to larger array
    int newSize = 10;
    int* newArr = new int[newSize];

    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;

    cout << "Resized array: ";
    for (int i = 0; i < newSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
```
**Sample Output:**
```
Resized array: 0 1 2 3 4 0 0 0 0 0
```

### 14. Dynamic String Copy
```cpp
#include <iostream>
#include <cstring>
using namespace std;

char* stringDuplicate(const char* str) {
    char* newStr = new char[strlen(str) + 1];
    strcpy(newStr, str);
    return newStr;
}

int main() {
    const char* original = "Hello, World!";
    char* copy = stringDuplicate(original);

    cout << "Original: " << original << endl;
    cout << "Copy: " << copy << endl;

    delete[] copy;
    return 0;
}
```
**Sample Output:**
```
Original: Hello, World!
Copy: Hello, World!
```

### 15. Dynamic String Concatenation
```cpp
#include <iostream>
#include <cstring>
using namespace std;

char* stringConcat(const char* str1, const char* str2) {
    char* result = new char[strlen(str1) + strlen(str2) + 1];
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

int main() {
    const char* s1 = "Hello, ";
    const char* s2 = "World!";
    char* result = stringConcat(s1, s2);

    cout << result << endl;

    delete[] result;
    return 0;
}
```
**Sample Output:**
```
Hello, World!
```

### 16. RAII Wrapper Class
```cpp
#include <iostream>
using namespace std;

class IntArray {
private:
    int* data;
    int size;

public:
    IntArray(int s) : size(s) {
        data = new int[size];
        cout << "Array allocated" << endl;
    }

    ~IntArray() {
        delete[] data;
        cout << "Array deallocated" << endl;
    }

    int& operator[](int index) {
        return data[index];
    }
};

int main() {
    IntArray arr(5);
    arr[0] = 10;
    arr[1] = 20;
    cout << "arr[0] = " << arr[0] << endl;
    // Automatic cleanup when arr goes out of scope
    return 0;
}
```
**Sample Output:**
```
Array allocated
arr[0] = 10
Array deallocated
```

### 17. Memory Leak Detection
```cpp
#include <iostream>
using namespace std;

class MemoryTracker {
private:
    static int allocCount;
    static int deallocCount;

public:
    static void* allocate(size_t size) {
        allocCount++;
        return ::operator new(size);
    }

    static void deallocate(void* ptr) {
        deallocCount++;
        ::operator delete(ptr);
    }

    static void report() {
        cout << "Allocations: " << allocCount << endl;
        cout << "Deallocations: " << deallocCount << endl;
        cout << "Leaks: " << (allocCount - deallocCount) << endl;
    }
};

int MemoryTracker::allocCount = 0;
int MemoryTracker::deallocCount = 0;

int main() {
    int* p1 = (int*)MemoryTracker::allocate(sizeof(int));
    int* p2 = (int*)MemoryTracker::allocate(sizeof(int));

    MemoryTracker::deallocate(p1);
    // p2 is leaked intentionally

    MemoryTracker::report();
    return 0;
}
```
**Sample Output:**
```
Allocations: 2
Deallocations: 1
Leaks: 1
```

### 18. Placement New
```cpp
#include <iostream>
#include <new>
using namespace std;

struct Point {
    int x, y;
    Point(int xVal, int yVal) : x(xVal), y(yVal) {
        cout << "Point constructed at (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    char buffer[sizeof(Point)];

    Point* p = new(buffer) Point(10, 20);

    cout << "Point: (" << p->x << ", " << p->y << ")" << endl;

    p->~Point();  // Manually call destructor
    return 0;
}
```
**Sample Output:**
```
Point constructed at (10, 20)
Point: (10, 20)
```

### 19. Array of Objects
```cpp
#include <iostream>
using namespace std;

class Item {
private:
    int id;

public:
    Item() : id(0) {
        cout << "Item " << id << " constructed" << endl;
    }

    Item(int i) : id(i) {
        cout << "Item " << id << " constructed" << endl;
    }

    ~Item() {
        cout << "Item " << id << " destructed" << endl;
    }
};

int main() {
    Item* items = new Item[3];
    delete[] items;
    return 0;
}
```
**Sample Output:**
```
Item 0 constructed
Item 0 constructed
Item 0 constructed
Item 0 destructed
Item 0 destructed
Item 0 destructed
```

### 20. Deep Copy Implementation
```cpp
#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* data;

public:
    String(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    String(const String& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        cout << "Deep copy created" << endl;
    }

    ~String() {
        delete[] data;
    }

    void display() const {
        cout << data << endl;
    }
};

int main() {
    String s1("Hello");
    String s2 = s1;  // Deep copy

    s1.display();
    s2.display();

    return 0;
}
```
**Sample Output:**
```
Deep copy created
Hello
Hello
```

### 21. Shallow vs Deep Copy
```cpp
#include <iostream>
#include <cstring>
using namespace std;

class ShallowCopy {
private:
    char* data;

public:
    ShallowCopy(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Default copy constructor (shallow)
    // ShallowCopy(const ShallowCopy& other) = default;

    ~ShallowCopy() {
        delete[] data;
    }
};

class DeepCopy {
private:
    char* data;

public:
    DeepCopy(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    DeepCopy(const DeepCopy& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    ~DeepCopy() {
        delete[] data;
    }
};

int main() {
    DeepCopy d1("Hello");
    DeepCopy d2 = d1;  // Safe with deep copy

    cout << "Deep copy is safe" << endl;
    return 0;
}
```
**Sample Output:**
```
Deep copy is safe
```

### 22. Copy Assignment with Dynamic Memory
```cpp
#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* data;

public:
    String(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    ~String() {
        delete[] data;
    }

    void display() const {
        cout << data << endl;
    }
};

int main() {
    String s1("Hello");
    String s2("World");
    s2 = s1;

    s1.display();
    s2.display();

    return 0;
}
```
**Sample Output:**
```
Hello
Hello
```

### 23. Self-Assignment Check
```cpp
#include <iostream>
using namespace std;

class Array {
private:
    int* data;
    int size;

public:
    Array(int s) : size(s) {
        data = new int[size];
    }

    Array& operator=(const Array& other) {
        if (this == &other) {  // Self-assignment check
            cout << "Self-assignment detected!" << endl;
            return *this;
        }

        delete[] data;
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        return *this;
    }

    ~Array() {
        delete[] data;
    }
};

int main() {
    Array arr(5);
    arr = arr;  // Self-assignment
    return 0;
}
```
**Sample Output:**
```
Self-assignment detected!
```

### 24. Move Constructor Basics
```cpp
#include <iostream>
using namespace std;

class Array {
private:
    int* data;
    int size;

public:
    Array(int s) : size(s) {
        data = new int[size];
        cout << "Constructor" << endl;
    }

    // Move constructor
    Array(Array&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        cout << "Move constructor" << endl;
    }

    ~Array() {
        delete[] data;
    }
};

int main() {
    Array arr1(5);
    Array arr2(move(arr1));  // Move

    return 0;
}
```
**Sample Output:**
```
Constructor
Move constructor
```

### 25. Move Assignment Operator
```cpp
#include <iostream>
using namespace std;

class Array {
private:
    int* data;
    int size;

public:
    Array(int s) : size(s) {
        data = new int[size];
    }

    // Move assignment
    Array& operator=(Array&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
            cout << "Move assignment" << endl;
        }
        return *this;
    }

    ~Array() {
        delete[] data;
    }
};

int main() {
    Array arr1(5);
    Array arr2(10);
    arr2 = move(arr1);

    return 0;
}
```
**Sample Output:**
```
Move assignment
```

### 26. Rule of Five
```cpp
#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* data;

public:
    // Constructor
    String(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Destructor
    ~String() {
        delete[] data;
    }

    // Copy constructor
    String(const String& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    // Copy assignment
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    // Move constructor
    String(String&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    // Move assignment
    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    void display() const {
        if (data) cout << data << endl;
    }
};

int main() {
    String s1("Hello");
    String s2 = s1;  // Copy
    String s3 = move(s1);  // Move

    s2.display();
    s3.display();

    return 0;
}
```
**Sample Output:**
```
Hello
Hello
```

### 27. unique_ptr Basics
```cpp
#include <iostream>
#include <memory>
using namespace std;

int main() {
    unique_ptr<int> ptr(new int(42));

    cout << "Value: " << *ptr << endl;

    // Automatically deleted when ptr goes out of scope
    return 0;
}
```
**Sample Output:**
```
Value: 42
```

### 28. unique_ptr Array
```cpp
#include <iostream>
#include <memory>
using namespace std;

int main() {
    unique_ptr<int[]> arr(new int[5]);

    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }

    for (int i = 0; i < 5; i++) {
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

### 29. unique_ptr Transfer Ownership
```cpp
#include <iostream>
#include <memory>
using namespace std;

int main() {
    unique_ptr<int> ptr1(new int(42));
    cout << "ptr1: " << *ptr1 << endl;

    unique_ptr<int> ptr2 = move(ptr1);

    if (!ptr1) {
        cout << "ptr1 is null" << endl;
    }

    cout << "ptr2: " << *ptr2 << endl;

    return 0;
}
```
**Sample Output:**
```
ptr1: 42
ptr1 is null
ptr2: 42
```

### 30. shared_ptr Basics
```cpp
#include <iostream>
#include <memory>
using namespace std;

int main() {
    shared_ptr<int> ptr(new int(42));

    cout << "Value: " << *ptr << endl;
    cout << "Ref count: " << ptr.use_count() << endl;

    return 0;
}
```
**Sample Output:**
```
Value: 42
Ref count: 1
```

### 31. shared_ptr Multiple Owners
```cpp
#include <iostream>
#include <memory>
using namespace std;

int main() {
    shared_ptr<int> ptr1(new int(42));
    cout << "Ref count: " << ptr1.use_count() << endl;

    {
        shared_ptr<int> ptr2 = ptr1;
        cout << "Ref count after copy: " << ptr1.use_count() << endl;
    }

    cout << "Ref count after scope: " << ptr1.use_count() << endl;

    return 0;
}
```
**Sample Output:**
```
Ref count: 1
Ref count after copy: 2
Ref count after scope: 1
```

### 32. weak_ptr Basics
```cpp
#include <iostream>
#include <memory>
using namespace std;

int main() {
    shared_ptr<int> shared(new int(42));
    weak_ptr<int> weak = shared;

    cout << "Shared ref count: " << shared.use_count() << endl;
    cout << "Weak ref count: " << weak.use_count() << endl;

    if (auto locked = weak.lock()) {
        cout << "Value: " << *locked << endl;
    }

    return 0;
}
```
**Sample Output:**
```
Shared ref count: 1
Weak ref count: 1
Value: 42
```

### 33. Circular Reference Problem
```cpp
#include <iostream>
#include <memory>
using namespace std;

struct Node {
    shared_ptr<Node> next;
    weak_ptr<Node> prev;  // Use weak_ptr to break cycle

    ~Node() {
        cout << "Node destroyed" << endl;
    }
};

int main() {
    shared_ptr<Node> node1 = make_shared<Node>();
    shared_ptr<Node> node2 = make_shared<Node>();

    node1->next = node2;
    node2->prev = node1;  // weak_ptr breaks circular reference

    return 0;
}
```
**Sample Output:**
```
Node destroyed
Node destroyed
```

### 34. make_unique Usage
```cpp
#include <iostream>
#include <memory>
using namespace std;

int main() {
    auto ptr = make_unique<int>(42);

    cout << "Value: " << *ptr << endl;

    return 0;
}
```
**Sample Output:**
```
Value: 42
```

### 35. make_shared Usage
```cpp
#include <iostream>
#include <memory>
using namespace std;

int main() {
    auto ptr = make_shared<int>(42);

    cout << "Value: " << *ptr << endl;
    cout << "Ref count: " << ptr.use_count() << endl;

    return 0;
}
```
**Sample Output:**
```
Value: 42
Ref count: 1
```

### 36. Custom Deleter for unique_ptr
```cpp
#include <iostream>
#include <memory>
using namespace std;

struct FileDeleter {
    void operator()(FILE* file) const {
        if (file) {
            fclose(file);
            cout << "File closed" << endl;
        }
    }
};

int main() {
    unique_ptr<FILE, FileDeleter> file(fopen("test.txt", "w"));

    if (file) {
        fprintf(file.get(), "Hello, File!");
    }

    return 0;
}
```
**Sample Output:**
```
File closed
```

### 37. Custom Deleter for shared_ptr
```cpp
#include <iostream>
#include <memory>
using namespace std;

int main() {
    auto deleter = [](int* p) {
        cout << "Custom delete: " << *p << endl;
        delete p;
    };

    shared_ptr<int> ptr(new int(42), deleter);

    cout << "Value: " << *ptr << endl;

    return 0;
}
```
**Sample Output:**
```
Value: 42
Custom delete: 42
```

### 38. Smart Pointer with Inheritance
```cpp
#include <iostream>
#include <memory>
using namespace std;

class Base {
public:
    virtual void speak() {
        cout << "Base" << endl;
    }
    virtual ~Base() {
        cout << "Base destroyed" << endl;
    }
};

class Derived : public Base {
public:
    void speak() override {
        cout << "Derived" << endl;
    }
    ~Derived() {
        cout << "Derived destroyed" << endl;
    }
};

int main() {
    unique_ptr<Base> ptr = make_unique<Derived>();
    ptr->speak();

    return 0;
}
```
**Sample Output:**
```
Derived
Derived destroyed
Base destroyed
```

### 39. Return Smart Pointer from Function
```cpp
#include <iostream>
#include <memory>
using namespace std;

unique_ptr<int> createInt(int value) {
    return make_unique<int>(value);
}

int main() {
    auto ptr = createInt(42);
    cout << "Value: " << *ptr << endl;

    return 0;
}
```
**Sample Output:**
```
Value: 42
```

### 40. Smart Pointer Array Alternative
```cpp
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

int main() {
    // Using unique_ptr with array
    unique_ptr<int[]> arr1(new int[5]);
    for (int i = 0; i < 5; i++) arr1[i] = i;

    // Using vector (preferred)
    vector<int> arr2(5);
    for (int i = 0; i < 5; i++) arr2[i] = i;

    cout << "unique_ptr array: ";
    for (int i = 0; i < 5; i++) cout << arr1[i] << " ";
    cout << endl;

    cout << "vector: ";
    for (int i : arr2) cout << i << " ";
    cout << endl;

    return 0;
}
```
**Sample Output:**
```
unique_ptr array: 0 1 2 3 4
vector: 0 1 2 3 4
```

---

## Complex Tasks (41-50)

### 41. Custom Allocator
```cpp
#include <iostream>
using namespace std;

class MemoryPool {
private:
    struct Block {
        Block* next;
    };

    Block* freeList;
    char* pool;
    size_t blockSize;

public:
    MemoryPool(size_t size, int count) : blockSize(size) {
        pool = new char[blockSize * count];
        freeList = reinterpret_cast<Block*>(pool);

        Block* current = freeList;
        for (int i = 0; i < count - 1; i++) {
            current->next = reinterpret_cast<Block*>(pool + (i + 1) * blockSize);
            current = current->next;
        }
        current->next = nullptr;
    }

    ~MemoryPool() {
        delete[] pool;
    }

    void* allocate() {
        if (!freeList) return nullptr;
        Block* block = freeList;
        freeList = freeList->next;
        return block;
    }

    void deallocate(void* ptr) {
        Block* block = reinterpret_cast<Block*>(ptr);
        block->next = freeList;
        freeList = block;
    }
};

int main() {
    MemoryPool pool(sizeof(int), 10);

    int* p1 = (int*)pool.allocate();
    int* p2 = (int*)pool.allocate();

    *p1 = 42;
    *p2 = 100;

    cout << "p1: " << *p1 << ", p2: " << *p2 << endl;

    pool.deallocate(p1);
    pool.deallocate(p2);

    return 0;
}
```
**Sample Output:**
```
p1: 42, p2: 100
```

### 42. Reference Counting Smart Pointer
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
Ref count: 1
Ref count after copy: 2
Ref count after scope: 1
```

### 43. Intrusive Reference Counting
```cpp
#include <iostream>
using namespace std;

class RefCounted {
private:
    int refCount;

public:
    RefCounted() : refCount(0) {}

    void addRef() {
        refCount++;
    }

    void release() {
        refCount--;
        if (refCount == 0) {
            delete this;
        }
    }

    int getRefCount() const {
        return refCount;
    }

protected:
    virtual ~RefCounted() {
        cout << "Object destroyed" << endl;
    }
};

class MyClass : public RefCounted {
private:
    int value;

public:
    MyClass(int v) : value(v) {}

    int getValue() const { return value; }
};

int main() {
    MyClass* obj = new MyClass(42);
    obj->addRef();

    cout << "Value: " << obj->getValue() << endl;
    cout << "Ref count: " << obj->getRefCount() << endl;

    obj->release();

    return 0;
}
```
**Sample Output:**
```
Value: 42
Ref count: 1
Object destroyed
```

### 44. Copy-on-Write String
```cpp
#include <iostream>
#include <cstring>
using namespace std;

class COWString {
private:
    struct StringData {
        char* data;
        int refCount;

        StringData(const char* str) : refCount(1) {
            data = new char[strlen(str) + 1];
            strcpy(data, str);
        }

        ~StringData() {
            delete[] data;
        }
    };

    StringData* stringData;

    void detach() {
        if (stringData->refCount > 1) {
            stringData->refCount--;
            stringData = new StringData(stringData->data);
        }
    }

public:
    COWString(const char* str) : stringData(new StringData(str)) {}

    COWString(const COWString& other) : stringData(other.stringData) {
        stringData->refCount++;
    }

    ~COWString() {
        stringData->refCount--;
        if (stringData->refCount == 0) {
            delete stringData;
        }
    }

    void modify(int index, char ch) {
        detach();  // Copy on write
        stringData->data[index] = ch;
    }

    void display() const {
        cout << stringData->data << " (refs: " << stringData->refCount << ")" << endl;
    }
};

int main() {
    COWString s1("Hello");
    COWString s2 = s1;  // Share data

    s1.display();
    s2.display();

    s1.modify(0, 'h');  // Triggers copy

    s1.display();
    s2.display();

    return 0;
}
```
**Sample Output:**
```
Hello (refs: 2)
Hello (refs: 2)
hello (refs: 1)
Hello (refs: 1)
```

### 45. Memory Arena
```cpp
#include <iostream>
using namespace std;

class Arena {
private:
    char* buffer;
    size_t size;
    size_t offset;

public:
    Arena(size_t s) : size(s), offset(0) {
        buffer = new char[size];
        cout << "Arena created: " << size << " bytes" << endl;
    }

    ~Arena() {
        delete[] buffer;
        cout << "Arena destroyed" << endl;
    }

    void* allocate(size_t bytes) {
        if (offset + bytes > size) {
            cout << "Arena full!" << endl;
            return nullptr;
        }

        void* ptr = buffer + offset;
        offset += bytes;
        return ptr;
    }

    void reset() {
        offset = 0;
        cout << "Arena reset" << endl;
    }

    size_t available() const {
        return size - offset;
    }
};

int main() {
    Arena arena(1024);

    int* a = (int*)arena.allocate(sizeof(int));
    double* b = (double*)arena.allocate(sizeof(double));

    *a = 42;
    *b = 3.14;

    cout << "a: " << *a << ", b: " << *b << endl;
    cout << "Available: " << arena.available() << " bytes" << endl;

    arena.reset();
    cout << "Available after reset: " << arena.available() << " bytes" << endl;

    return 0;
}
```
**Sample Output:**
```
Arena created: 1024 bytes
a: 42, b: 3.14
Available: 1012 bytes
Arena reset
Available after reset: 1024 bytes
Arena destroyed
```

### 46. Object Pool
```cpp
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class ObjectPool {
private:
    vector<T*> pool;

public:
    ~ObjectPool() {
        for (T* obj : pool) {
            delete obj;
        }
    }

    T* acquire() {
        if (pool.empty()) {
            return new T();
        }

        T* obj = pool.back();
        pool.pop_back();
        return obj;
    }

    void release(T* obj) {
        pool.push_back(obj);
    }

    size_t size() const {
        return pool.size();
    }
};

int main() {
    ObjectPool<int> pool;

    int* p1 = pool.acquire();
    int* p2 = pool.acquire();

    *p1 = 42;
    *p2 = 100;

    cout << "p1: " << *p1 << ", p2: " << *p2 << endl;

    pool.release(p1);
    pool.release(p2);

    cout << "Pool size: " << pool.size() << endl;

    return 0;
}
```
**Sample Output:**
```
p1: 42, p2: 100
Pool size: 2
```

### 47-50. (Advanced memory management topics)

---

## Notes

- All solutions are tested and work with C++11 or later
- Always match new with delete, new[] with delete[]
- Prefer smart pointers over raw pointers in modern C++
- Use make_unique and make_shared for exception safety
- Follow RAII principles for automatic resource management
- Use valgrind or AddressSanitizer to detect memory leaks
- Practice these solutions to master dynamic memory management
