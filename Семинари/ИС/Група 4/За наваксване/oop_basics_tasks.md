# OOP Basics Practice Tasks (50 Tasks)
## Classes, Inheritance, and Polymorphism

Master object-oriented programming fundamentals through repetition and progressive complexity.

---

## Trivial Tasks (1-10)

### 1. Simple Class Definition
**Difficulty:** Trivial
**Task:** Create a class `Rectangle` with width and height members, constructor, and method to calculate area.

### 2. Class with Getters/Setters
**Difficulty:** Trivial
**Task:** Create a `Person` class with private name and age, provide public getters and setters.

### 3. Default Constructor
**Difficulty:** Trivial
**Task:** Create a `Counter` class with a default constructor that initializes count to 0.

### 4. Parameterized Constructor
**Difficulty:** Trivial
**Task:** Create a `Book` class with title and author, use parameterized constructor.

### 5. Multiple Constructors
**Difficulty:** Trivial
**Task:** Create a `Point` class with default constructor (0,0) and parameterized constructor (x,y).

### 6. Destructor Basics
**Difficulty:** Trivial
**Task:** Create a class that prints a message in its constructor and destructor.

### 7. Static Member Variable
**Difficulty:** Trivial
**Task:** Create a class with a static counter that tracks how many objects have been created.

### 8. Static Member Function
**Difficulty:** Trivial
**Task:** Create a class with a static method to return the count of instances.

### 9. Const Member Function
**Difficulty:** Trivial
**Task:** Create a class with const member functions for getters that don't modify state.

### 10. Friend Function
**Difficulty:** Trivial
**Task:** Create a class with private members and a friend function that can access them.

---

## Simple Tasks (11-40)

### 11. Circle Class
**Difficulty:** Simple
**Task:** Create a `Circle` class with radius, methods for area, circumference, and diameter.

### 12. BankAccount Class
**Difficulty:** Simple
**Task:** Create `BankAccount` with balance, deposit(), withdraw(), and getBalance() methods.

### 13. Student Class
**Difficulty:** Simple
**Task:** Create `Student` with name, ID, grades array, methods to add grade and calculate average.

### 14. Date Class
**Difficulty:** Simple
**Task:** Create `Date` class with day, month, year, validate dates, and display method.

### 15. Time Class
**Difficulty:** Simple
**Task:** Create `Time` class with hours, minutes, seconds, validation, and methods to add time.

### 16. Complex Number Class
**Difficulty:** Simple
**Task:** Create `Complex` class with real and imaginary parts, add(), subtract(), multiply() methods.

### 17. Fraction Class
**Difficulty:** Simple
**Task:** Create `Fraction` with numerator/denominator, simplify(), add(), subtract() methods.

### 18. Vector2D Class
**Difficulty:** Simple
**Task:** Create 2D vector class with x, y, methods for magnitude, dot product, addition.

### 19. Basic Inheritance
**Difficulty:** Simple
**Task:** Create `Animal` base class and `Dog` derived class, override speak() method.

### 20. Three-Level Inheritance
**Difficulty:** Simple
**Task:** Create `Vehicle -> Car -> SportsCar` inheritance chain, add specific attributes at each level.

### 21. Protected Members
**Difficulty:** Simple
**Task:** Demonstrate protected members - accessible in derived class but not outside.

### 22. Constructor Inheritance
**Difficulty:** Simple
**Task:** Show how derived class constructor calls base class constructor.

### 23. Destructor Order
**Difficulty:** Simple
**Task:** Create inheritance hierarchy and demonstrate destructor call order (derived then base).

### 24. Method Overriding
**Difficulty:** Simple
**Task:** Override a base class method in derived class, call both versions.

### 25. Virtual Function Basics
**Difficulty:** Simple
**Task:** Create base class with virtual function, override in derived, demonstrate polymorphism.

### 26. Pure Virtual Function
**Difficulty:** Simple
**Task:** Create abstract base class with pure virtual function, implement in derived classes.

### 27. Interface Implementation
**Difficulty:** Simple
**Task:** Create an interface (abstract class) `Drawable` with draw(), implement in multiple classes.

### 28. Multiple Inheritance
**Difficulty:** Simple
**Task:** Create a class that inherits from two base classes, demonstrate member access.

### 29. Diamond Problem Awareness
**Difficulty:** Simple
**Task:** Create diamond inheritance pattern, show the problem, solve with virtual inheritance.

### 30. Operator Overloading (+)
**Difficulty:** Simple
**Task:** Overload + operator for a class (e.g., Complex numbers or Vectors).

### 31. Operator Overloading (==, !=)
**Difficulty:** Simple
**Task:** Overload comparison operators for a class.

### 32. Operator Overloading (<<)
**Difficulty:** Simple
**Task:** Overload << operator for output stream to print your class objects.

### 33. Operator Overloading (>>)
**Difficulty:** Simple
**Task:** Overload >> operator for input stream to read class objects.

### 34. Operator Overloading ([])
**Difficulty:** Simple
**Task:** Create an array-like class and overload [] operator for element access.

### 35. Copy Constructor
**Difficulty:** Simple
**Task:** Implement a proper copy constructor for a class with dynamic memory.

### 36. Copy Assignment Operator
**Difficulty:** Simple
**Task:** Implement copy assignment operator (operator=) with self-assignment check.

### 37. Rule of Three
**Difficulty:** Simple
**Task:** Implement destructor, copy constructor, and copy assignment for a class managing resources.

### 38. Composition
**Difficulty:** Simple
**Task:** Create `Engine` class and `Car` class that contains an Engine (has-a relationship).

### 39. Aggregation
**Difficulty:** Simple
**Task:** Create classes demonstrating aggregation (weaker relationship than composition).

### 40. Polymorphic Array
**Difficulty:** Simple
**Task:** Create array of base class pointers pointing to different derived class objects, call virtual functions.

---

## Complex Tasks (41-50)

### 41. Shape Hierarchy
**Difficulty:** Complex
**Task:** Create `Shape` base class with pure virtual area() and perimeter(), implement Circle, Rectangle, Triangle.

### 42. Employee Management System
**Difficulty:** Complex
**Task:** Create Employee base class, Manager/Engineer derived classes, calculateSalary() with different formulas.

### 43. Library Management System
**Difficulty:** Complex
**Task:** Create Book, Member, Library classes with methods to borrow/return books, track availability.

### 44. Bank Account Hierarchy
**Difficulty:** Complex
**Task:** Create Account base, SavingsAccount/CheckingAccount derived with different interest calculations.

### 45. Animal Hierarchy with Interfaces
**Difficulty:** Complex
**Task:** Create Animal base, Mammal/Bird derived, interfaces Swimmable/Flyable, implement Duck (can swim and fly).

### 46. Smart Pointer-like Class
**Difficulty:** Complex
**Task:** Create a reference-counting smart pointer class with proper copy semantics.

### 47. Iterator Pattern
**Difficulty:** Complex
**Task:** Create a custom container class with an iterator class to traverse elements.

### 48. Observer Pattern
**Difficulty:** Complex
**Task:** Implement observer pattern - Subject notifies multiple Observers of state changes.

### 49. Factory Pattern
**Difficulty:** Complex
**Task:** Create a factory class that produces different derived class objects based on input.

### 50. Game Entity System
**Difficulty:** Complex
**Task:** Create GameObject base class, Player/Enemy/Item derived classes, Game class to manage them all, demonstrate polymorphism.

---

## Learning Objectives

By completing these tasks, you will develop instinctive understanding of:
- Class design and encapsulation
- Constructors and destructors
- Member access control (public, private, protected)
- Static members and methods
- Const correctness
- Inheritance hierarchies (single, multiple, multilevel)
- Method overriding and virtual functions
- Polymorphism and dynamic binding
- Abstract classes and interfaces
- Operator overloading
- Copy semantics (Rule of Three)
- Object relationships (composition, aggregation, association)
- Virtual destructors and memory management
- Design patterns basics
- Object lifetime and RAII principles

**Practice Tip:** Start with simple single-class designs, then progress to inheritance. Understand the difference between is-a (inheritance) and has-a (composition). Draw UML diagrams for complex hierarchies. Repeat until OOP design becomes intuitive.

**Important:** Always use virtual destructors in base classes when using polymorphism. This prevents memory leaks when deleting derived objects through base pointers.
