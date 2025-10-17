# OOP Basics Practice - Solutions

Complete solutions with sample usage for all 50 OOP tasks.

---

## Trivial Tasks (1-10)

### 1. Simple Class Definition
```cpp
#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() {
        return width * height;
    }
};

int main() {
    Rectangle rect(5.0, 3.0);
    cout << "Area: " << rect.area() << endl;
    return 0;
}
```
**Sample Output:**
```
Area: 15
```

### 2. Class with Getters/Setters
```cpp
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    void setName(const string& n) { name = n; }
    void setAge(int a) { age = a; }
    string getName() const { return name; }
    int getAge() const { return age; }
};

int main() {
    Person person;
    person.setName("Alice");
    person.setAge(25);
    cout << person.getName() << ", " << person.getAge() << endl;
    return 0;
}
```
**Sample Output:**
```
Alice, 25
```

### 3. Default Constructor
```cpp
#include <iostream>
using namespace std;

class Counter {
private:
    int count;

public:
    Counter() : count(0) {}

    void increment() { count++; }
    int getCount() const { return count; }
};

int main() {
    Counter counter;
    cout << "Initial: " << counter.getCount() << endl;
    counter.increment();
    cout << "After increment: " << counter.getCount() << endl;
    return 0;
}
```
**Sample Output:**
```
Initial: 0
After increment: 1
```

### 4. Parameterized Constructor
```cpp
#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;

public:
    Book(const string& t, const string& a) : title(t), author(a) {}

    void display() {
        cout << "Title: " << title << ", Author: " << author << endl;
    }
};

int main() {
    Book book("1984", "George Orwell");
    book.display();
    return 0;
}
```
**Sample Output:**
```
Title: 1984, Author: George Orwell
```

### 5. Multiple Constructors
```cpp
#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point() : x(0), y(0) {}
    Point(int xVal, int yVal) : x(xVal), y(yVal) {}

    void display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p1;
    Point p2(5, 10);
    p1.display();
    p2.display();
    return 0;
}
```
**Sample Output:**
```
(0, 0)
(5, 10)
```

### 6. Destructor Basics
```cpp
#include <iostream>
using namespace std;

class Demo {
public:
    Demo() {
        cout << "Constructor called" << endl;
    }

    ~Demo() {
        cout << "Destructor called" << endl;
    }
};

int main() {
    Demo obj;
    cout << "In main" << endl;
    return 0;
}
```
**Sample Output:**
```
Constructor called
In main
Destructor called
```

### 7. Static Member Variable
```cpp
#include <iostream>
using namespace std;

class Counter {
private:
    static int count;

public:
    Counter() {
        count++;
    }

    static int getCount() {
        return count;
    }
};

int Counter::count = 0;

int main() {
    Counter c1, c2, c3;
    cout << "Objects created: " << Counter::getCount() << endl;
    return 0;
}
```
**Sample Output:**
```
Objects created: 3
```

### 8. Static Member Function
```cpp
#include <iostream>
using namespace std;

class Math {
public:
    static int add(int a, int b) {
        return a + b;
    }

    static int multiply(int a, int b) {
        return a * b;
    }
};

int main() {
    cout << "5 + 3 = " << Math::add(5, 3) << endl;
    cout << "5 * 3 = " << Math::multiply(5, 3) << endl;
    return 0;
}
```
**Sample Output:**
```
5 + 3 = 8
5 * 3 = 15
```

### 9. Const Member Function
```cpp
#include <iostream>
using namespace std;

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getRadius() const {
        return radius;
    }

    double area() const {
        return 3.14159 * radius * radius;
    }
};

int main() {
    const Circle circle(5.0);
    cout << "Radius: " << circle.getRadius() << endl;
    cout << "Area: " << circle.area() << endl;
    return 0;
}
```
**Sample Output:**
```
Radius: 5
Area: 78.5397
```

### 10. Friend Function
```cpp
#include <iostream>
using namespace std;

class Box {
private:
    double width;

public:
    Box(double w) : width(w) {}

    friend void printWidth(const Box& box);
};

void printWidth(const Box& box) {
    cout << "Width: " << box.width << endl;
}

int main() {
    Box box(10.5);
    printWidth(box);
    return 0;
}
```
**Sample Output:**
```
Width: 10.5
```

---

## Simple Tasks (11-40)

### 11. Circle Class
```cpp
#include <iostream>
using namespace std;

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const {
        return 3.14159 * radius * radius;
    }

    double circumference() const {
        return 2 * 3.14159 * radius;
    }

    double diameter() const {
        return 2 * radius;
    }
};

int main() {
    Circle circle(5.0);
    cout << "Area: " << circle.area() << endl;
    cout << "Circumference: " << circle.circumference() << endl;
    cout << "Diameter: " << circle.diameter() << endl;
    return 0;
}
```
**Sample Output:**
```
Area: 78.5397
Circumference: 31.4159
Diameter: 10
```

### 12. BankAccount Class
```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount() : balance(0) {}

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (amount > balance) return false;
        balance -= amount;
        return true;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account;
    account.deposit(1000);
    cout << "Balance: " << account.getBalance() << endl;
    account.withdraw(250);
    cout << "After withdrawal: " << account.getBalance() << endl;
    return 0;
}
```
**Sample Output:**
```
Balance: 1000
After withdrawal: 750
```

### 13. Student Class
```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    int id;
    vector<double> grades;

public:
    Student(const string& n, int i) : name(n), id(i) {}

    void addGrade(double grade) {
        grades.push_back(grade);
    }

    double average() const {
        if (grades.empty()) return 0.0;
        double sum = 0;
        for (double g : grades) sum += g;
        return sum / grades.size();
    }

    void display() const {
        cout << "Student: " << name << ", ID: " << id
             << ", Average: " << average() << endl;
    }
};

int main() {
    Student student("Alice", 101);
    student.addGrade(85);
    student.addGrade(90);
    student.addGrade(88);
    student.display();
    return 0;
}
```
**Sample Output:**
```
Student: Alice, ID: 101, Average: 87.6667
```

### 14. Date Class
```cpp
#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;

    bool isValid() const {
        if (month < 1 || month > 12) return false;
        if (day < 1 || day > 31) return false;
        return true;
    }

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    void display() const {
        if (isValid()) {
            cout << day << "/" << month << "/" << year << endl;
        } else {
            cout << "Invalid date" << endl;
        }
    }
};

int main() {
    Date date1(15, 8, 2024);
    Date date2(32, 13, 2024);
    date1.display();
    date2.display();
    return 0;
}
```
**Sample Output:**
```
15/8/2024
Invalid date
```

### 15. Time Class
```cpp
#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

    void normalize() {
        minutes += seconds / 60;
        seconds %= 60;
        hours += minutes / 60;
        minutes %= 60;
        hours %= 24;
    }

public:
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    void addTime(const Time& other) {
        hours += other.hours;
        minutes += other.minutes;
        seconds += other.seconds;
        normalize();
    }

    void display() const {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
};

int main() {
    Time t1(10, 30, 45);
    Time t2(2, 45, 30);
    t1.display();
    t1.addTime(t2);
    t1.display();
    return 0;
}
```
**Sample Output:**
```
10:30:45
13:16:15
```

### 16. Complex Number Class
```cpp
#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex add(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex subtract(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex multiply(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);
    Complex c3 = c1.add(c2);
    c3.display();
    return 0;
}
```
**Sample Output:**
```
4 + 6i
```

### 17. Fraction Class
```cpp
#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator, denominator;

    int gcd(int a, int b) const {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    void simplify() {
        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
    }

public:
    Fraction(int n, int d) : numerator(n), denominator(d) {
        simplify();
    }

    Fraction add(const Fraction& other) const {
        return Fraction(
            numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator
        );
    }

    void display() const {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    Fraction f3 = f1.add(f2);
    f3.display();
    return 0;
}
```
**Sample Output:**
```
5/6
```

### 18. Vector2D Class
```cpp
#include <iostream>
#include <cmath>
using namespace std;

class Vector2D {
private:
    double x, y;

public:
    Vector2D(double xVal = 0, double yVal = 0) : x(xVal), y(yVal) {}

    double magnitude() const {
        return sqrt(x * x + y * y);
    }

    double dot(const Vector2D& other) const {
        return x * other.x + y * other.y;
    }

    Vector2D add(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);
    cout << "Magnitude: " << v1.magnitude() << endl;
    cout << "Dot product: " << v1.dot(v2) << endl;
    Vector2D v3 = v1.add(v2);
    v3.display();
    return 0;
}
```
**Sample Output:**
```
Magnitude: 5
Dot product: 11
(4, 6)
```

### 19. Basic Inheritance
```cpp
#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;

public:
    Animal(const string& n) : name(n) {}

    virtual void speak() const {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal {
public:
    Dog(const string& n) : Animal(n) {}

    void speak() const override {
        cout << name << " says: Woof!" << endl;
    }
};

int main() {
    Animal animal("Generic");
    Dog dog("Buddy");
    animal.speak();
    dog.speak();
    return 0;
}
```
**Sample Output:**
```
Animal makes a sound
Buddy says: Woof!
```

### 20. Three-Level Inheritance
```cpp
#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string brand;

public:
    Vehicle(const string& b) : brand(b) {}

    void display() const {
        cout << "Brand: " << brand << endl;
    }
};

class Car : public Vehicle {
protected:
    int doors;

public:
    Car(const string& b, int d) : Vehicle(b), doors(d) {}

    void display() const {
        Vehicle::display();
        cout << "Doors: " << doors << endl;
    }
};

class SportsCar : public Car {
private:
    int topSpeed;

public:
    SportsCar(const string& b, int d, int s) : Car(b, d), topSpeed(s) {}

    void display() const {
        Car::display();
        cout << "Top Speed: " << topSpeed << " km/h" << endl;
    }
};

int main() {
    SportsCar ferrari("Ferrari", 2, 350);
    ferrari.display();
    return 0;
}
```
**Sample Output:**
```
Brand: Ferrari
Doors: 2
Top Speed: 350 km/h
```

### 21. Protected Members
```cpp
#include <iostream>
using namespace std;

class Base {
protected:
    int protectedValue;

public:
    Base() : protectedValue(42) {}
};

class Derived : public Base {
public:
    void showValue() {
        cout << "Protected value: " << protectedValue << endl;
    }
};

int main() {
    Derived obj;
    obj.showValue();
    // obj.protectedValue = 10;  // ERROR: cannot access from outside
    return 0;
}
```
**Sample Output:**
```
Protected value: 42
```

### 22. Constructor Inheritance
```cpp
#include <iostream>
#include <string>
using namespace std;

class Base {
protected:
    string name;

public:
    Base(const string& n) : name(n) {
        cout << "Base constructor: " << name << endl;
    }
};

class Derived : public Base {
private:
    int id;

public:
    Derived(const string& n, int i) : Base(n), id(i) {
        cout << "Derived constructor: " << id << endl;
    }
};

int main() {
    Derived obj("Test", 123);
    return 0;
}
```
**Sample Output:**
```
Base constructor: Test
Derived constructor: 123
```

### 23. Destructor Order
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base constructor" << endl;
    }

    ~Base() {
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived constructor" << endl;
    }

    ~Derived() {
        cout << "Derived destructor" << endl;
    }
};

int main() {
    Derived obj;
    return 0;
}
```
**Sample Output:**
```
Base constructor
Derived constructor
Derived destructor
Base destructor
```

### 24. Method Overriding
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    void show() {
        cout << "Base show" << endl;
    }
};

class Derived : public Base {
public:
    void show() {
        cout << "Derived show" << endl;
        Base::show();  // Call base version
    }
};

int main() {
    Derived obj;
    obj.show();
    return 0;
}
```
**Sample Output:**
```
Derived show
Base show
```

### 25. Virtual Function Basics
```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() const {
        cout << "Drawing Shape" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() const override {
        cout << "Drawing Circle" << endl;
    }
};

int main() {
    Shape* shape = new Circle();
    shape->draw();  // Calls Circle::draw()
    delete shape;
    return 0;
}
```
**Sample Output:**
```
Drawing Circle
```

### 26. Pure Virtual Function
```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;  // Pure virtual
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }
};

int main() {
    Shape* shape = new Rectangle(5, 3);
    cout << "Area: " << shape->area() << endl;
    delete shape;
    return 0;
}
```
**Sample Output:**
```
Area: 15
```

### 27. Interface Implementation
```cpp
#include <iostream>
using namespace std;

class Drawable {
public:
    virtual void draw() const = 0;
    virtual ~Drawable() {}
};

class Circle : public Drawable {
public:
    void draw() const override {
        cout << "Drawing Circle" << endl;
    }
};

class Square : public Drawable {
public:
    void draw() const override {
        cout << "Drawing Square" << endl;
    }
};

int main() {
    Drawable* shapes[2];
    shapes[0] = new Circle();
    shapes[1] = new Square();

    for (int i = 0; i < 2; i++) {
        shapes[i]->draw();
        delete shapes[i];
    }
    return 0;
}
```
**Sample Output:**
```
Drawing Circle
Drawing Square
```

### 28. Multiple Inheritance
```cpp
#include <iostream>
using namespace std;

class Printable {
public:
    void print() const {
        cout << "Printing..." << endl;
    }
};

class Scannable {
public:
    void scan() const {
        cout << "Scanning..." << endl;
    }
};

class Printer : public Printable, public Scannable {
public:
    void operate() {
        print();
        scan();
    }
};

int main() {
    Printer printer;
    printer.operate();
    return 0;
}
```
**Sample Output:**
```
Printing...
Scanning...
```

### 29. Diamond Problem Awareness
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    int value;
    Base() : value(42) {}
};

class Derived1 : virtual public Base {};
class Derived2 : virtual public Base {};

class Final : public Derived1, public Derived2 {};

int main() {
    Final obj;
    cout << "Value: " << obj.value << endl;  // No ambiguity with virtual
    return 0;
}
```
**Sample Output:**
```
Value: 42
```

### 30. Operator Overloading (+)
```cpp
#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);
    Complex c3 = c1 + c2;
    c3.display();
    return 0;
}
```
**Sample Output:**
```
4 + 6i
```

### 31. Operator Overloading (==, !=)
```cpp
#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int xVal, int yVal) : x(xVal), y(yVal) {}

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }
};

int main() {
    Point p1(1, 2);
    Point p2(1, 2);
    Point p3(3, 4);

    cout << "p1 == p2: " << (p1 == p2) << endl;
    cout << "p1 != p3: " << (p1 != p3) << endl;
    return 0;
}
```
**Sample Output:**
```
p1 == p2: 1
p1 != p3: 1
```

### 32. Operator Overloading (<<)
```cpp
#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int xVal, int yVal) : x(xVal), y(yVal) {}

    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

int main() {
    Point p(3, 4);
    cout << "Point: " << p << endl;
    return 0;
}
```
**Sample Output:**
```
Point: (3, 4)
```

### 33. Operator Overloading (>>)
```cpp
#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point() : x(0), y(0) {}

    friend istream& operator>>(istream& is, Point& p) {
        is >> p.x >> p.y;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

int main() {
    Point p;
    cout << "Enter x and y: ";
    cin >> p;
    cout << "Point: " << p << endl;
    return 0;
}
```
**Sample Output:**
```
Enter x and y: 5 10
Point: (5, 10)
```

### 34. Operator Overloading ([])
```cpp
#include <iostream>
using namespace std;

class Array {
private:
    int data[10];

public:
    Array() {
        for (int i = 0; i < 10; i++) data[i] = i;
    }

    int& operator[](int index) {
        return data[index];
    }

    const int& operator[](int index) const {
        return data[index];
    }
};

int main() {
    Array arr;
    cout << "arr[5] = " << arr[5] << endl;
    arr[5] = 100;
    cout << "arr[5] = " << arr[5] << endl;
    return 0;
}
```
**Sample Output:**
```
arr[5] = 5
arr[5] = 100
```

### 35. Copy Constructor
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
        cout << "Copy constructor called" << endl;
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
    String s2 = s1;
    s1.display();
    s2.display();
    return 0;
}
```
**Sample Output:**
```
Copy constructor called
Hello
Hello
```

### 36. Copy Assignment Operator
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
        if (this != &other) {  // Self-assignment check
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
    s2.display();
    return 0;
}
```
**Sample Output:**
```
Hello
```

### 37. Rule of Three
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

    // Copy constructor
    String(const String& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    // Copy assignment operator
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    // Destructor
    ~String() {
        delete[] data;
    }

    void display() const {
        cout << data << endl;
    }
};

int main() {
    String s1("Hello");
    String s2 = s1;
    String s3("World");
    s3 = s1;
    s1.display();
    s2.display();
    s3.display();
    return 0;
}
```
**Sample Output:**
```
Hello
Hello
Hello
```

### 38. Composition
```cpp
#include <iostream>
using namespace std;

class Engine {
private:
    int horsepower;

public:
    Engine(int hp) : horsepower(hp) {}

    void start() {
        cout << "Engine started (" << horsepower << " HP)" << endl;
    }
};

class Car {
private:
    Engine engine;  // Composition

public:
    Car(int hp) : engine(hp) {}

    void start() {
        engine.start();
        cout << "Car is ready to go" << endl;
    }
};

int main() {
    Car car(200);
    car.start();
    return 0;
}
```
**Sample Output:**
```
Engine started (200 HP)
Car is ready to go
```

### 39. Aggregation
```cpp
#include <iostream>
#include <string>
using namespace std;

class Department {
private:
    string name;

public:
    Department(const string& n) : name(n) {}

    string getName() const {
        return name;
    }
};

class Employee {
private:
    string name;
    Department* dept;  // Aggregation (weak relationship)

public:
    Employee(const string& n, Department* d) : name(n), dept(d) {}

    void display() const {
        cout << name << " works in " << dept->getName() << endl;
    }
};

int main() {
    Department dept("IT");
    Employee emp("Alice", &dept);
    emp.display();
    return 0;
}
```
**Sample Output:**
```
Alice works in IT
```

### 40. Polymorphic Array
```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() const {
        cout << "Drawing Shape" << endl;
    }
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() const override {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        cout << "Drawing Rectangle" << endl;
    }
};

int main() {
    Shape* shapes[3];
    shapes[0] = new Circle();
    shapes[1] = new Rectangle();
    shapes[2] = new Circle();

    for (int i = 0; i < 3; i++) {
        shapes[i]->draw();
        delete shapes[i];
    }
    return 0;
}
```
**Sample Output:**
```
Drawing Circle
Drawing Rectangle
Drawing Circle
```

---

## Complex Tasks (41-50)

### 41. Shape Hierarchy
```cpp
#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

    double perimeter() const override {
        return 2 * 3.14159 * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2 * (width + height);
    }
};

class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {}

    double area() const override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double perimeter() const override {
        return a + b + c;
    }
};

int main() {
    Shape* shapes[3];
    shapes[0] = new Circle(5);
    shapes[1] = new Rectangle(4, 6);
    shapes[2] = new Triangle(3, 4, 5);

    for (int i = 0; i < 3; i++) {
        cout << "Area: " << shapes[i]->area()
             << ", Perimeter: " << shapes[i]->perimeter() << endl;
        delete shapes[i];
    }
    return 0;
}
```
**Sample Output:**
```
Area: 78.5397, Perimeter: 31.4159
Area: 24, Perimeter: 20
Area: 6, Perimeter: 12
```

### 42. Employee Management System
```cpp
#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;
    double baseSalary;

public:
    Employee(const string& n, int i, double bs) : name(n), id(i), baseSalary(bs) {}

    virtual double calculateSalary() const = 0;

    virtual void display() const {
        cout << "Name: " << name << ", ID: " << id;
    }

    virtual ~Employee() {}
};

class Manager : public Employee {
private:
    double bonus;

public:
    Manager(const string& n, int i, double bs, double b)
        : Employee(n, i, bs), bonus(b) {}

    double calculateSalary() const override {
        return baseSalary + bonus;
    }

    void display() const override {
        Employee::display();
        cout << ", Salary: " << calculateSalary() << " (Manager)" << endl;
    }
};

class Engineer : public Employee {
private:
    int projects;

public:
    Engineer(const string& n, int i, double bs, int p)
        : Employee(n, i, bs), projects(p) {}

    double calculateSalary() const override {
        return baseSalary + (projects * 500);
    }

    void display() const override {
        Employee::display();
        cout << ", Salary: " << calculateSalary() << " (Engineer)" << endl;
    }
};

int main() {
    Employee* employees[2];
    employees[0] = new Manager("Alice", 101, 5000, 2000);
    employees[1] = new Engineer("Bob", 102, 4000, 3);

    for (int i = 0; i < 2; i++) {
        employees[i]->display();
        delete employees[i];
    }
    return 0;
}
```
**Sample Output:**
```
Name: Alice, ID: 101, Salary: 7000 (Manager)
Name: Bob, ID: 102, Salary: 5500 (Engineer)
```

### 43. Library Management System
```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
private:
    string title;
    bool available;

public:
    Book(const string& t) : title(t), available(true) {}

    bool isAvailable() const { return available; }
    void borrow() { available = false; }
    void returnBook() { available = true; }
    string getTitle() const { return title; }
};

class Member {
private:
    string name;
    vector<Book*> borrowedBooks;

public:
    Member(const string& n) : name(n) {}

    void borrowBook(Book* book) {
        if (book->isAvailable()) {
            book->borrow();
            borrowedBooks.push_back(book);
            cout << name << " borrowed " << book->getTitle() << endl;
        } else {
            cout << "Book not available" << endl;
        }
    }

    void returnBook(Book* book) {
        book->returnBook();
        cout << name << " returned " << book->getTitle() << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const string& title) {
        books.push_back(Book(title));
    }

    Book* findBook(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                return &book;
            }
        }
        return nullptr;
    }
};

int main() {
    Library library;
    library.addBook("1984");
    library.addBook("Brave New World");

    Member member("Alice");
    Book* book = library.findBook("1984");
    if (book) {
        member.borrowBook(book);
        member.returnBook(book);
    }
    return 0;
}
```
**Sample Output:**
```
Alice borrowed 1984
Alice returned 1984
```

### 44. Bank Account Hierarchy
```cpp
#include <iostream>
using namespace std;

class Account {
protected:
    double balance;

public:
    Account(double initial) : balance(initial) {}

    virtual void addInterest() = 0;

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (amount > balance) return false;
        balance -= amount;
        return true;
    }

    double getBalance() const { return balance; }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(double initial, double rate)
        : Account(initial), interestRate(rate) {}

    void addInterest() override {
        balance += balance * interestRate;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(double initial) : Account(initial) {}

    void addInterest() override {
        // No interest for checking accounts
    }
};

int main() {
    SavingsAccount savings(1000, 0.05);
    CheckingAccount checking(500);

    savings.addInterest();
    cout << "Savings balance: " << savings.getBalance() << endl;
    cout << "Checking balance: " << checking.getBalance() << endl;

    return 0;
}
```
**Sample Output:**
```
Savings balance: 1050
Checking balance: 500
```

### 45. Animal Hierarchy with Interfaces
```cpp
#include <iostream>
using namespace std;

class Swimmable {
public:
    virtual void swim() const = 0;
    virtual ~Swimmable() {}
};

class Flyable {
public:
    virtual void fly() const = 0;
    virtual ~Flyable() {}
};

class Animal {
public:
    virtual void eat() const = 0;
    virtual ~Animal() {}
};

class Mammal : public Animal {
public:
    void eat() const override {
        cout << "Mammal eating" << endl;
    }
};

class Bird : public Animal {
public:
    void eat() const override {
        cout << "Bird eating" << endl;
    }
};

class Duck : public Bird, public Swimmable, public Flyable {
public:
    void swim() const override {
        cout << "Duck swimming" << endl;
    }

    void fly() const override {
        cout << "Duck flying" << endl;
    }
};

int main() {
    Duck duck;
    duck.eat();
    duck.swim();
    duck.fly();
    return 0;
}
```
**Sample Output:**
```
Bird eating
Duck swimming
Duck flying
```

### 46. Smart Pointer-like Class
```cpp
#include <iostream>
using namespace std;

template<typename T>
class SmartPtr {
private:
    T* ptr;
    int* refCount;

public:
    SmartPtr(T* p = nullptr) : ptr(p), refCount(new int(1)) {}

    SmartPtr(const SmartPtr& other) : ptr(other.ptr), refCount(other.refCount) {
        (*refCount)++;
    }

    SmartPtr& operator=(const SmartPtr& other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            refCount = other.refCount;
            (*refCount)++;
        }
        return *this;
    }

    ~SmartPtr() {
        release();
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
    SmartPtr<int> p1(new int(42));
    cout << "Value: " << *p1 << endl;
    cout << "Ref count: " << p1.getRefCount() << endl;

    {
        SmartPtr<int> p2 = p1;
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

### 47. Iterator Pattern
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
        for (int i = 0; i < size; i++) {
            data[i] = i * 10;
        }
    }

    ~IntArray() {
        delete[] data;
    }

    class Iterator {
    private:
        int* ptr;

    public:
        Iterator(int* p) : ptr(p) {}

        int& operator*() { return *ptr; }
        Iterator& operator++() { ptr++; return *this; }
        bool operator!=(const Iterator& other) { return ptr != other.ptr; }
    };

    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + size); }
};

int main() {
    IntArray arr(5);

    for (IntArray::Iterator it = arr.begin(); it != arr.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
```
**Sample Output:**
```
0 10 20 30 40
```

### 48. Observer Pattern
```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Observer {
public:
    virtual void update(const string& message) = 0;
    virtual ~Observer() {}
};

class Subject {
private:
    vector<Observer*> observers;
    string state;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void setState(const string& s) {
        state = s;
        notify();
    }

    void notify() {
        for (Observer* obs : observers) {
            obs->update(state);
        }
    }
};

class ConcreteObserver : public Observer {
private:
    string name;

public:
    ConcreteObserver(const string& n) : name(n) {}

    void update(const string& message) override {
        cout << name << " received: " << message << endl;
    }
};

int main() {
    Subject subject;

    ConcreteObserver obs1("Observer1");
    ConcreteObserver obs2("Observer2");

    subject.attach(&obs1);
    subject.attach(&obs2);

    subject.setState("State changed!");

    return 0;
}
```
**Sample Output:**
```
Observer1 received: State changed!
Observer2 received: State changed!
```

### 49. Factory Pattern
```cpp
#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    virtual void use() const = 0;
    virtual ~Product() {}
};

class ConcreteProductA : public Product {
public:
    void use() const override {
        cout << "Using Product A" << endl;
    }
};

class ConcreteProductB : public Product {
public:
    void use() const override {
        cout << "Using Product B" << endl;
    }
};

class Factory {
public:
    static Product* createProduct(const string& type) {
        if (type == "A") return new ConcreteProductA();
        if (type == "B") return new ConcreteProductB();
        return nullptr;
    }
};

int main() {
    Product* prodA = Factory::createProduct("A");
    Product* prodB = Factory::createProduct("B");

    prodA->use();
    prodB->use();

    delete prodA;
    delete prodB;

    return 0;
}
```
**Sample Output:**
```
Using Product A
Using Product B
```

### 50. Game Entity System
```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class GameObject {
protected:
    string name;
    int x, y;

public:
    GameObject(const string& n, int xPos, int yPos)
        : name(n), x(xPos), y(yPos) {}

    virtual void update() = 0;
    virtual void display() const {
        cout << name << " at (" << x << ", " << y << ")" << endl;
    }

    virtual ~GameObject() {}
};

class Player : public GameObject {
private:
    int health;

public:
    Player(const string& n, int xPos, int yPos)
        : GameObject(n, xPos, yPos), health(100) {}

    void update() override {
        x++;
        cout << "Player moving" << endl;
    }

    void display() const override {
        GameObject::display();
        cout << "Health: " << health << endl;
    }
};

class Enemy : public GameObject {
public:
    Enemy(const string& n, int xPos, int yPos)
        : GameObject(n, xPos, yPos) {}

    void update() override {
        x--;
        cout << "Enemy patrolling" << endl;
    }
};

class Item : public GameObject {
public:
    Item(const string& n, int xPos, int yPos)
        : GameObject(n, xPos, yPos) {}

    void update() override {
        cout << "Item waiting" << endl;
    }
};

class Game {
private:
    vector<GameObject*> entities;

public:
    void addEntity(GameObject* entity) {
        entities.push_back(entity);
    }

    void updateAll() {
        for (GameObject* entity : entities) {
            entity->update();
        }
    }

    void displayAll() const {
        for (GameObject* entity : entities) {
            entity->display();
        }
    }

    ~Game() {
        for (GameObject* entity : entities) {
            delete entity;
        }
    }
};

int main() {
    Game game;

    game.addEntity(new Player("Hero", 0, 0));
    game.addEntity(new Enemy("Goblin", 10, 5));
    game.addEntity(new Item("Potion", 5, 3));

    cout << "Initial state:" << endl;
    game.displayAll();

    cout << "\nUpdating..." << endl;
    game.updateAll();

    cout << "\nFinal state:" << endl;
    game.displayAll();

    return 0;
}
```
**Sample Output:**
```
Initial state:
Hero at (0, 0)
Health: 100
Goblin at (10, 5)
Potion at (5, 3)

Updating...
Player moving
Enemy patrolling
Item waiting

Final state:
Hero at (1, 0)
Health: 100
Goblin at (9, 5)
Potion at (5, 3)
```

---

## Notes

- All solutions are tested and work with standard C++11 or later
- Always use virtual destructors in base classes with virtual functions
- Follow RAII principles for resource management
- Prefer composition over inheritance when appropriate
- Use smart pointers in modern C++ instead of raw pointers
- Practice these solutions to master OOP concepts
