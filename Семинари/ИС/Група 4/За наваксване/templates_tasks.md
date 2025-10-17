# Template Classes and Functions Practice Tasks (50 Tasks)

Master generic programming and templates through repetition and progressive complexity.

---

## Trivial Tasks (1-10)

### 1. Function Template Basics
**Difficulty:** Trivial
**Task:** Create a template function `swap` that swaps two values of any type.

### 2. Template Max Function
**Difficulty:** Trivial
**Task:** Create a template function that returns the maximum of two values.

### 3. Template Min Function
**Difficulty:** Trivial
**Task:** Create a template function that returns the minimum of two values.

### 4. Template Print Function
**Difficulty:** Trivial
**Task:** Create a template function that prints a value of any type.

### 5. Template Array Sum
**Difficulty:** Trivial
**Task:** Create a template function that sums all elements in an array of any numeric type.

### 6. Simple Template Class
**Difficulty:** Trivial
**Task:** Create a template class `Box<T>` that holds a single value of type T.

### 7. Template Pair Class
**Difficulty:** Trivial
**Task:** Create a template class `Pair<T>` that holds two values of the same type.

### 8. Template Display Method
**Difficulty:** Trivial
**Task:** Add a display() method to a template class that prints the stored value.

### 9. Template Constructor
**Difficulty:** Trivial
**Task:** Create a template class with parameterized constructor to initialize the value.

### 10. Template Getter/Setter
**Difficulty:** Trivial
**Task:** Create template class with getter and setter methods for the stored value.

---

## Simple Tasks (11-40)

### 11. Template Absolute Value
**Difficulty:** Simple
**Task:** Create a template function for absolute value that works with int, float, double.

### 12. Template Array Search
**Difficulty:** Simple
**Task:** Create a template function that searches for a value in an array, returns index or -1.

### 13. Template Array Reverse
**Difficulty:** Simple
**Task:** Create a template function that reverses an array of any type.

### 14. Template Array Copy
**Difficulty:** Simple
**Task:** Create a template function that copies one array to another for any type.

### 15. Template Compare Function
**Difficulty:** Simple
**Task:** Create a template function that compares two values, returns -1, 0, or 1.

### 16. Multiple Template Parameters
**Difficulty:** Simple
**Task:** Create `Pair<T, U>` class that holds two values of potentially different types.

### 17. Template Array Class
**Difficulty:** Simple
**Task:** Create a template `Array<T>` class that wraps a fixed-size array with bounds checking.

### 18. Template Dynamic Array
**Difficulty:** Simple
**Task:** Create a template `DynamicArray<T>` with dynamic allocation, push/pop operations.

### 19. Template Stack Class
**Difficulty:** Simple
**Task:** Create a template `Stack<T>` with push, pop, top, isEmpty operations.

### 20. Template Queue Class
**Difficulty:** Simple
**Task:** Create a template `Queue<T>` with enqueue, dequeue, front operations.

### 21. Template Linked List Node
**Difficulty:** Simple
**Task:** Create a template `Node<T>` for linked list with data and next pointer.

### 22. Template Linked List
**Difficulty:** Simple
**Task:** Create a template `LinkedList<T>` with insert, delete, display operations.

### 23. Default Template Parameter
**Difficulty:** Simple
**Task:** Create a template class with a default type parameter (e.g., `Array<T, int SIZE = 10>`).

### 24. Non-Type Template Parameter
**Difficulty:** Simple
**Task:** Create a template class that takes a size as a non-type parameter (e.g., `Array<T, int N>`).

### 25. Template Specialization
**Difficulty:** Simple
**Task:** Create a template function and specialize it for `char*` to handle strings differently.

### 26. Class Template Specialization
**Difficulty:** Simple
**Task:** Create a template class and provide full specialization for `bool` type.

### 27. Partial Template Specialization
**Difficulty:** Simple
**Task:** Create template `Pair<T, U>` and partially specialize for `Pair<T, T>` (same types).

### 28. Template Member Function
**Difficulty:** Simple
**Task:** Create a class with a template member function that can work with different types.

### 29. Template Function Overloading
**Difficulty:** Simple
**Task:** Overload a template function with different parameter counts (1 param vs 2 params).

### 30. Template with Inheritance
**Difficulty:** Simple
**Task:** Create a template base class and a template derived class.

### 31. Template Matrix Class
**Difficulty:** Simple
**Task:** Create a template `Matrix<T>` class for 2D arrays with basic operations.

### 32. Template Binary Tree Node
**Difficulty:** Simple
**Task:** Create a template `TreeNode<T>` with left, right pointers and data.

### 33. Template BST Insert
**Difficulty:** Simple
**Task:** Create a template Binary Search Tree with insert operation.

### 34. Template BST Search
**Difficulty:** Simple
**Task:** Add search operation to template BST.

### 35. Template with Friend Function
**Difficulty:** Simple
**Task:** Create a template class with a friend template function for operator overloading.

### 36. Template Operator Overloading
**Difficulty:** Simple
**Task:** Overload arithmetic operators for a template class (e.g., Vector<T>).

### 37. Template Iterator Class
**Difficulty:** Simple
**Task:** Create a template iterator for your custom container class.

### 38. Variadic Template Basics
**Difficulty:** Simple
**Task:** Create a variadic template function that prints all its arguments.

### 39. Variadic Template Sum
**Difficulty:** Simple
**Task:** Create a variadic template function that sums all its arguments.

### 40. Template Type Traits
**Difficulty:** Simple
**Task:** Use type traits (is_integral, is_floating_point) to enable functions conditionally.

---

## Complex Tasks (41-50)

### 41. Template Vector Class
**Difficulty:** Complex
**Task:** Create a full `Vector<T>` class similar to std::vector with dynamic resizing, iterators, and all standard operations.

### 42. Template Smart Pointer
**Difficulty:** Complex
**Task:** Create a template smart pointer class with reference counting (like shared_ptr).

### 43. Template Expression Templates
**Difficulty:** Complex
**Task:** Implement basic expression templates for efficient Vector arithmetic without temporaries.

### 44. Template Policy-Based Design
**Difficulty:** Complex
**Task:** Create a template class that takes policy classes as template parameters (e.g., allocation policy, comparison policy).

### 45. Template Metaprogramming - Factorial
**Difficulty:** Complex
**Task:** Calculate factorial at compile-time using template metaprogramming.

### 46. Template Metaprogramming - Fibonacci
**Difficulty:** Complex
**Task:** Calculate Fibonacci numbers at compile-time using template metaprogramming.

### 47. SFINAE Example
**Difficulty:** Complex
**Task:** Use SFINAE (Substitution Failure Is Not An Error) to enable different template functions based on type properties.

### 48. Template Tuple Class
**Difficulty:** Complex
**Task:** Create a variadic template Tuple class that can hold any number of different types.

### 49. Template Function Object
**Difficulty:** Complex
**Task:** Create template functor classes for different operations, use with template algorithms.

### 50. Generic Algorithm Library
**Difficulty:** Complex
**Task:** Create a small library of generic algorithms (sort, find, transform, accumulate) that work with any container and type.

---

## Learning Objectives

By completing these tasks, you will develop instinctive understanding of:
- Function template syntax and instantiation
- Class template design and usage
- Template parameter types (type, non-type, template)
- Template specialization (full and partial)
- Default template parameters
- Template instantiation and code generation
- Template compilation model
- Template type deduction
- Template with inheritance
- Friend templates
- Variadic templates (C++11+)
- Template metaprogramming basics
- SFINAE and enable_if
- Type traits and compile-time type checking
- Template design patterns
- Generic programming principles
- STL-style generic containers and algorithms

**Practice Tip:** Templates are compile-time constructs. Start with simple function templates, then move to class templates. Understand template instantiation - each unique type creates a new copy of the code. Practice reading compiler error messages from templates (they can be lengthy).

**Warning:** Template code must be in header files (or same file) because the compiler needs to see the definition to instantiate it. This is different from regular classes.

**Modern C++:** These tasks cover C++98/03 through C++17 features. Pay special attention to variadic templates (C++11+) and type traits - they're essential for modern C++ programming.
