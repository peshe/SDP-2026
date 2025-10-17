# Dynamic Memory Management Practice Tasks (50 Tasks)

Master dynamic memory allocation, deallocation, and smart pointers through repetition and progressive complexity.

---

## Trivial Tasks (1-10)

### 1. Allocate Single Integer
**Difficulty:** Trivial
**Task:** Allocate a single integer on the heap using `new`, assign value, print it, and delete.

### 2. Allocate Single Float
**Difficulty:** Trivial
**Task:** Allocate a float dynamically, use it, and properly deallocate.

### 3. Allocate Array of Integers
**Difficulty:** Trivial
**Task:** Allocate an integer array dynamically, fill it, print it, and delete using `delete[]`.

### 4. Check for Null
**Difficulty:** Trivial
**Task:** After allocation, check if the pointer is null before using it.

### 5. Memory Leak Example
**Difficulty:** Trivial
**Task:** Intentionally create a memory leak (allocate without deleting) and explain why it's bad.

### 6. Double Delete Bug
**Difficulty:** Trivial
**Task:** Show what happens with double delete, explain the undefined behavior.

### 7. Set Pointer to Null
**Difficulty:** Trivial
**Task:** After deleting a pointer, set it to nullptr to avoid dangling pointer issues.

### 8. Dangling Pointer Example
**Difficulty:** Trivial
**Task:** Demonstrate a dangling pointer (using a pointer after deletion) and explain the danger.

### 9. Dynamic String Allocation
**Difficulty:** Trivial
**Task:** Allocate a char array dynamically, copy a string into it, print, delete.

### 10. Dynamic Struct Allocation
**Difficulty:** Trivial
**Task:** Define a struct, allocate it dynamically, access members using ->, delete.

---

## Simple Tasks (11-40)

### 11. Dynamic 2D Array (Array of Arrays)
**Difficulty:** Simple
**Task:** Allocate a 2D array dynamically using array-of-pointers approach, fill, print, properly deallocate.

### 12. Dynamic 2D Array (Contiguous)
**Difficulty:** Simple
**Task:** Allocate a 2D array as a single contiguous block, access using pointer arithmetic.

### 13. Resize Dynamic Array
**Difficulty:** Simple
**Task:** Allocate array, copy to larger array when needed (manual vector-like growth).

### 14. Dynamic String Copy
**Difficulty:** Simple
**Task:** Implement a function that dynamically allocates and copies a string (like strdup).

### 15. Dynamic String Concatenation
**Difficulty:** Simple
**Task:** Concatenate two strings into a new dynamically allocated string.

### 16. RAII Wrapper Class
**Difficulty:** Simple
**Task:** Create a class that allocates in constructor and deallocates in destructor (RAII principle).

### 17. Memory Leak Detection
**Difficulty:** Simple
**Task:** Create a simple memory tracking system that counts new/delete calls to detect leaks.

### 18. Placement New
**Difficulty:** Simple
**Task:** Demonstrate placement new - constructing object in pre-allocated memory.

### 19. Array of Objects
**Difficulty:** Simple
**Task:** Dynamically allocate an array of class objects, ensure constructors/destructors are called.

### 20. Deep Copy Implementation
**Difficulty:** Simple
**Task:** Create a class with dynamic member, implement deep copy in copy constructor.

### 21. Shallow vs Deep Copy
**Difficulty:** Simple
**Task:** Demonstrate the difference between shallow and deep copy with dynamic members.

### 22. Copy Assignment with Dynamic Memory
**Difficulty:** Simple
**Task:** Implement copy assignment operator that properly handles dynamic memory.

### 23. Self-Assignment Check
**Difficulty:** Simple
**Task:** Show why self-assignment check is important in assignment operator.

### 24. Move Constructor Basics
**Difficulty:** Simple
**Task:** Implement move constructor that transfers ownership of dynamic memory (C++11).

### 25. Move Assignment Operator
**Difficulty:** Simple
**Task:** Implement move assignment operator to transfer ownership efficiently.

### 26. Rule of Five
**Difficulty:** Simple
**Task:** Implement all five: destructor, copy constructor, copy assignment, move constructor, move assignment.

### 27. unique_ptr Basics
**Difficulty:** Simple
**Task:** Use std::unique_ptr to manage a single dynamically allocated object.

### 28. unique_ptr Array
**Difficulty:** Simple
**Task:** Use std::unique_ptr to manage a dynamically allocated array.

### 29. unique_ptr Transfer Ownership
**Difficulty:** Simple
**Task:** Demonstrate transferring ownership using std::move with unique_ptr.

### 30. shared_ptr Basics
**Difficulty:** Simple
**Task:** Use std::shared_ptr to manage a shared object, observe reference counting.

### 31. shared_ptr Multiple Owners
**Difficulty:** Simple
**Task:** Create multiple shared_ptr instances pointing to same object, verify count.

### 32. weak_ptr Basics
**Difficulty:** Simple
**Task:** Use std::weak_ptr to observe a shared object without increasing reference count.

### 33. Circular Reference Problem
**Difficulty:** Simple
**Task:** Demonstrate circular reference memory leak with shared_ptr, solve with weak_ptr.

### 34. make_unique Usage
**Difficulty:** Simple
**Task:** Use std::make_unique to create unique_ptr (safer than raw new).

### 35. make_shared Usage
**Difficulty:** Simple
**Task:** Use std::make_shared to create shared_ptr (more efficient).

### 36. Custom Deleter for unique_ptr
**Difficulty:** Simple
**Task:** Provide a custom deleter function to unique_ptr for special cleanup.

### 37. Custom Deleter for shared_ptr
**Difficulty:** Simple
**Task:** Provide a custom deleter to shared_ptr (e.g., for file handles, arrays).

### 38. Smart Pointer with Inheritance
**Difficulty:** Simple
**Task:** Store derived class objects in smart pointers of base class type (polymorphism).

### 39. Return Smart Pointer from Function
**Difficulty:** Simple
**Task:** Write a function that returns unique_ptr or shared_ptr.

### 40. Smart Pointer Array Alternative
**Difficulty:** Simple
**Task:** Compare unique_ptr<T[]> vs std::vector<T> for dynamic arrays.

---

## Complex Tasks (41-50)

### 41. Custom Allocator
**Difficulty:** Complex
**Task:** Create a simple memory pool allocator for fixed-size objects.

### 42. Reference Counting Smart Pointer
**Difficulty:** Complex
**Task:** Implement your own reference-counting smart pointer from scratch (like shared_ptr).

### 43. Intrusive Reference Counting
**Difficulty:** Complex
**Task:** Implement intrusive reference counting where count is inside the managed object.

### 44. Copy-on-Write String
**Difficulty:** Complex
**Task:** Implement a string class with copy-on-write optimization using reference counting.

### 45. Memory Arena
**Difficulty:** Complex
**Task:** Create a memory arena that allocates from a large buffer, deallocates all at once.

### 46. Object Pool
**Difficulty:** Complex
**Task:** Implement an object pool that reuses allocated objects instead of constantly allocating/deallocating.

### 47. Garbage Collector (Mark and Sweep)
**Difficulty:** Complex
**Task:** Implement a simple mark-and-sweep garbage collector for a custom object system.

### 48. Dynamic Array with Smart Pointers
**Difficulty:** Complex
**Task:** Implement a vector-like class using unique_ptr internally for automatic memory management.

### 49. Graph with Shared Ownership
**Difficulty:** Complex
**Task:** Create a graph structure where nodes are shared, use shared_ptr and weak_ptr appropriately.

### 50. Resource Manager
**Difficulty:** Complex
**Task:** Create a resource manager that manages multiple resource types (textures, sounds) using smart pointers and RAII.

---

## Learning Objectives

By completing these tasks, you will develop instinctive understanding of:
- Dynamic memory allocation (new/delete, new[]/delete[])
- Memory leaks and how to prevent them
- Dangling pointers and null pointer safety
- RAII (Resource Acquisition Is Initialization)
- Rule of Three (C++98/03)
- Rule of Five (C++11+) with move semantics
- Deep copy vs shallow copy
- Move semantics and rvalue references
- Smart pointers (unique_ptr, shared_ptr, weak_ptr)
- Reference counting and ownership semantics
- Custom deleters
- make_unique and make_shared
- Circular reference problems
- Memory management best practices
- When to use which smart pointer
- Performance implications of different approaches
- Custom allocators and memory pools
- Exception safety with dynamic memory

**Practice Tip:** Modern C++ (C++11 and later) prefers smart pointers over raw new/delete. However, understanding raw pointers is essential. Start with manual memory management to understand the problems, then appreciate how smart pointers solve them.

**Best Practices:**
- Prefer stack allocation when possible
- Use std::vector instead of raw arrays
- Use smart pointers instead of raw new/delete
- Never mix smart pointers with raw pointer ownership
- Prefer unique_ptr by default, use shared_ptr only when needed
- Always use make_unique/make_shared instead of raw new
- Follow the Rule of Zero when possible (no manual resource management)

**Warning:** Memory bugs are among the hardest to debug. Practice defensive programming, use tools like valgrind or AddressSanitizer to detect memory issues.
