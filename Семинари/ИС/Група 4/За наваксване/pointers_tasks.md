# Pointers Practice Tasks (50 Tasks)

Master pointer manipulation through repetition and progressive complexity.

---

## Trivial Tasks (1-10)

### 1. Declare and Initialize
**Difficulty:** Trivial
**Task:** Declare an integer variable, create a pointer to it, and print both the value and address.

### 2. Pointer Dereferencing
**Difficulty:** Trivial
**Task:** Create a pointer to an integer, modify the integer's value through the pointer, and print the result.

### 3. Null Pointer Check
**Difficulty:** Trivial
**Task:** Declare a null pointer, check if it's null before dereferencing, and print appropriate messages.

### 4. Pointer to Float
**Difficulty:** Trivial
**Task:** Create a pointer to a float variable, assign a value through the pointer, and display it.

### 5. Address Arithmetic Basics
**Difficulty:** Trivial
**Task:** Declare two integer variables, print their addresses, and calculate the difference between addresses.

### 6. Pointer Assignment
**Difficulty:** Trivial
**Task:** Create two pointers, make them point to the same variable, modify through one pointer, verify through the other.

### 7. Const Pointer
**Difficulty:** Trivial
**Task:** Create a const pointer to an integer and demonstrate that you can change the value but not the pointer itself.

### 8. Pointer to Const
**Difficulty:** Trivial
**Task:** Create a pointer to a const integer and demonstrate that you cannot change the value through the pointer.

### 9. Size of Pointer
**Difficulty:** Trivial
**Task:** Print the size of different pointer types (int*, char*, double*) and observe they're all the same.

### 10. Swap Using Pointers
**Difficulty:** Trivial
**Task:** Write a function that swaps two integers using pointers.

---

## Simple Tasks (11-40)

### 11. Array Access via Pointer
**Difficulty:** Simple
**Task:** Create an array, use a pointer to iterate through it and print all elements.

### 12. Pointer Arithmetic Increment
**Difficulty:** Simple
**Task:** Create an integer array, use pointer arithmetic (++) to traverse and print elements.

### 13. Pointer Arithmetic Decrement
**Difficulty:** Simple
**Task:** Create an array, start a pointer at the end, use (--) to traverse backwards.

### 14. Pointer Addition
**Difficulty:** Simple
**Task:** Create an array, use pointer + offset syntax to access and print every other element.

### 15. Pointer Subtraction
**Difficulty:** Simple
**Task:** Given two pointers in an array, calculate the number of elements between them using subtraction.

### 16. Array Sum via Pointer
**Difficulty:** Simple
**Task:** Write a function that takes an array pointer and size, returns the sum using pointer arithmetic.

### 17. Find Maximum via Pointer
**Difficulty:** Simple
**Task:** Write a function using pointers to find the maximum element in an array.

### 18. Find Minimum via Pointer
**Difficulty:** Simple
**Task:** Write a function using pointers to find the minimum element in an array.

### 19. Reverse Array with Pointers
**Difficulty:** Simple
**Task:** Use two pointers (start and end) to reverse an array in-place.

### 20. Copy Array with Pointers
**Difficulty:** Simple
**Task:** Write a function that copies one array to another using only pointer arithmetic.

### 21. Compare Arrays with Pointers
**Difficulty:** Simple
**Task:** Write a function that compares two arrays element-by-element using pointers.

### 22. Pointer to Pointer Basics
**Difficulty:** Simple
**Task:** Create a pointer to pointer, use it to modify an integer value, demonstrate double dereferencing.

### 23. Modify Pointer via Function
**Difficulty:** Simple
**Task:** Write a function that takes a pointer-to-pointer and modifies where the original pointer points.

### 24. Array of Pointers
**Difficulty:** Simple
**Task:** Create an array of 5 integer pointers, make them point to different variables, print all values.

### 25. Pointer Array Initialization
**Difficulty:** Simple
**Task:** Create an array of pointers to strings (char*), initialize with string literals, print all.

### 26. Dynamic Single Integer
**Difficulty:** Simple
**Task:** Allocate a single integer dynamically, assign value via pointer, print, and deallocate.

### 27. Find Element via Pointer
**Difficulty:** Simple
**Task:** Write a function that returns a pointer to the first occurrence of a value in an array (or nullptr).

### 28. Count Occurrences via Pointer
**Difficulty:** Simple
**Task:** Write a function using pointers to count how many times a value appears in an array.

### 29. Pointer to Structure
**Difficulty:** Simple
**Task:** Create a simple struct (e.g., Point with x, y), create a pointer to it, access members using ->.

### 30. Array of Structures via Pointer
**Difficulty:** Simple
**Task:** Create an array of structs, use a pointer to iterate and print all struct members.

### 31. Function Returning Pointer
**Difficulty:** Simple
**Task:** Write a function that returns a pointer to the largest element in an array.

### 32. Multiple Indirection
**Difficulty:** Simple
**Task:** Create a chain: variable -> pointer -> pointer-to-pointer -> pointer-to-pointer-to-pointer, modify the original value.

### 33. Void Pointer Basics
**Difficulty:** Simple
**Task:** Create a void pointer, assign it to different types (int, float, char), cast and print appropriately.

### 34. Generic Swap with Void Pointers
**Difficulty:** Simple
**Task:** Write a swap function using void pointers that can swap any two values given their size.

### 35. Pointer to Function Basics
**Difficulty:** Simple
**Task:** Create a simple function, create a pointer to it, call the function through the pointer.

### 36. Function Pointer Array
**Difficulty:** Simple
**Task:** Create an array of function pointers (e.g., basic math operations), call them via array indexing.

### 37. Callback Function via Pointer
**Difficulty:** Simple
**Task:** Write a function that takes a function pointer as callback and applies it to array elements.

### 38. Const Correctness Practice
**Difficulty:** Simple
**Task:** Write a function that takes `const int* arr` and demonstrates you cannot modify array elements.

### 39. Pointer Comparison
**Difficulty:** Simple
**Task:** Create two pointers into an array, use comparison operators (<, >, ==) to determine their relative positions.

### 40. Reference vs Pointer
**Difficulty:** Simple
**Task:** Write two functions (one with pointer parameter, one with reference), demonstrate their usage differences.

---

## Complex Tasks (41-50)

### 41. 2D Array via Pointer-to-Pointer
**Difficulty:** Complex
**Task:** Dynamically allocate a 2D array using pointer-to-pointer, fill it, print it, and properly deallocate.

### 42. Matrix Operations with Pointers
**Difficulty:** Complex
**Task:** Write functions to add and multiply two matrices using only pointer arithmetic (no [] notation).

### 43. Linked List Node Insertion
**Difficulty:** Complex
**Task:** Create a simple linked list node structure, write a function to insert at head using pointer-to-pointer.

### 44. Linked List Traversal
**Difficulty:** Complex
**Task:** Write functions to traverse, print, and count nodes in a linked list using pointers.

### 45. Smart Pointer-like Wrapper
**Difficulty:** Complex
**Task:** Create a simple class that wraps a pointer and auto-deletes in destructor (basic RAII pattern).

### 46. Pointer-Based Quick Sort
**Difficulty:** Complex
**Task:** Implement quicksort using pointers for partitioning and recursion (no array indexing).

### 47. Dynamic Ragged Array
**Difficulty:** Complex
**Task:** Create a ragged 2D array where each row has different length, all dynamically allocated.

### 48. Function Pointer Dispatcher
**Difficulty:** Complex
**Task:** Create a command dispatcher using a map/array of function pointers to handle different operations.

### 49. Pointer-Based Binary Search
**Difficulty:** Complex
**Task:** Implement binary search using only pointers (start, end, mid) instead of indices.

### 50. Custom Memory Pool
**Difficulty:** Complex
**Task:** Create a simple memory pool: allocate a large chunk, implement your own allocate/deallocate using pointer arithmetic.

---

## Learning Objectives

By completing these tasks, you will develop instinctive understanding of:
- Pointer declaration, initialization, and dereferencing
- Pointer arithmetic and array traversal
- Multi-level pointers and pointer-to-pointer
- Function pointers and callbacks
- Const correctness with pointers
- Void pointers and type casting
- Dynamic memory allocation patterns
- Pointer-based algorithms and data structures

**Practice Tip:** Do these tasks in order, and repeat sections where you feel less confident. The goal is automatic, instinctive pointer manipulation.
