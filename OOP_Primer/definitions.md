# Assignment 4 - Basic OOP Terminology

+ Name: Aniah Myles

+ Date: 06 Dec. 2024

+ Class: 2143-102 OOP

## Definitions:

### **Abstraction:**

The process of hiding implementation details and showing only the necessary features of an object. It simplifies complexity by providing a clear interface.

### **Abstract Classes:**

In object-oriented programming, a class designed only as a parent from which sub-classes MAY be derived, but which is not itself suitable for instantiation. Often used to "abstract out" incomplete sets of features which may then be shared by a group of sibling sub-classes which add different variations of the missing pieces. It can also be noticed if the class has at least one pure virtual function.

```cpp 

#include <iostream> 
using namespace std;

// Abstract class
class Shape {
public:
    // Pure virtual functions
    virtual double area() const = 0;        // Calculate the area
    virtual double perimeter() const = 0;  // Calculate the perimeter

    // Virtual destructor (important for base classes)
    virtual ~Shape() {}
};

```

### **Access Modifiers:**

 A keyword that determines the visibility or accessibility of a class, method, variable, or other members in object-oriented programming. It controls where and how a particular class or member can be accessed, either within the same class, subclass, or from other classes or packages.

 + Private: An access modifier that can ### **only### ** be accessed within the class.

 + Protected: An access modifier that can be accessed within the same class or by a derived class.

 + Public: An access modifier that can be accessed from anywhere.

```cpp 

#include <iostream> 
using namespace std;

class Example {
private:
    int privateValue;  // Accessible only within this class

protected:
    int protectedValue;  // Accessible in derived classes

public:
    int publicValue;  // Accessible from anywhere
};

```

### **Attributes:**

Characteristics of an object, often represented as class variables.

```cpp 

#include <iostream>
 using namespace std;

class Dog {
public:
    string name;
    int age;
};

```

### **Class:**

 The prototype for an object in an object-oriented language; analogous to a derived type in a procedural language. A class may also be considered to be a set of objects which share a common structure and behaviour. The structure of a class is determined by the class variables which represent the state of an object of that class and the behaviour is given by a set of methods associated with the class.

```cpp 

#include <iostream> 
using namespace std;

#ifndef RECTANGLE_H // Include guard to prevent multiple inclusions
#define RECTANGLE_H

class Rectangle {
private:
    double length; // Length of the rectangle
    double width;  // Width of the rectangle

public:
    // Default constructor
    Rectangle();

    // Parameterized constructor
    Rectangle(double len, double wid);

    // Destructor
    ~Rectangle();

    // Setters
    void setLength(double len);
    void setWidth(double wid);

    // Getters
    double getLength() const;
    double getWidth() const;

    // Member functions
    double calculateArea() const;
    double calculatePerimeter() const;
};

#endif // RECTANGLE_H

```

### **Class Variable:**

A variable that is shared among all instances of a class.

![classVariable](https://github.com/aaniaahh/OOP/blob/main/assignments/OOP_Primer/images/classVariables.jpg)

### **Collections:**

 Containers used to store and manage groups of related objects.

+ Examples of Collections: arrays, class, lists, sets, tree, and etc.


### **Composition:**

A design principle where objects are built by containing other objects, representing a ### **"has-a"### ** relationship.

```cpp

#include <iostream> 
using namespace std;

class Engine {
public:
    void start() { 
        
        cout << "Engine started\n"; }
};

class Car {
private:
    Engine engine; // Car "has-a" Engine
public:
    void startCar() {
        
         engine.start(); }
};

```

### **Concrete Class:**

A class that can be instantiated to create objects and ssed to define fully implemented behavior for objects.

```cpp

#include <iostream>
using namespace std;

// Concrete class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * M_PI * radius;
    }
};

```

### **Constructors:**

A function provided by a class to initialise a newly created object. The constructor function typically has the same name as the class. It may take arguments, e.g. to set various attributes of the object or it may just leave everything undefined to be set elsewhere.

+ Copy Constructor: A constructor that creates a new object as a copy of an existing object. It is used when an object is initialized from another object of the same type.

+ Default Constructor: A constructor that does not take any arguments (or all its parameters have default values). It initializes an object with default values.

+ Parameterized Constructor: A constructor that takes arguments to initialize an object with specific values.

_If you could spot functions with the same name as the class, you've found the constructors of that class._

```cpp 

#include <iostream> 
using namespace std;

public:
    // Default constructor
    Rectangle();

    // Parameterized constructor
    Rectangle(double len, double wid);

    // Copy Constructor
    Rectangle(const Rectangle& other);

```

### **Deep Copy:**

A copy operation where an object and all the objects it references are duplicated, creating a completely independent clone. Changes to the copied object do not affect the original.

```cpp

#include <iostream> 
using namespace std;

class DeepCopyExample {
    int* data;
public:
    DeepCopyExample(int value) {
        data = new int(value);
    }
    DeepCopyExample(const DeepCopyExample& other) {
        data = new int(*other.data);
    }
};

```

### **Derived Class:**

A class that inherits from a base class. It can extend or override functionality defined in the base class.

```cpp 

#include <iostream> 
using namespace std;

class Base {
public:
    void greet() { std::cout << "Hello from Base\n"; }
};

class Derived : public Base {};

```

### **Design Patterns:**

Identifies classes and instances, their roles, collaborations and responsibilities. Each design pattern focuses on a particular object-oriented design problem or issue. It describes when it applies, whether it can be applied in the presence of other design constraints, and the consequences and trade-offs of its use.

+ Singleton: Ensures a class has only one instance.

+ Factory: Creates objects without specifying their exact class.

+ Observer: Defines a dependency where objects get notified of changes.

### **Destructors:**

A function provided by a class in C++ and some other object-oriented languages to delete an object, also know as the inverse of a constructor.

_If you can spot a '~' function in a class, you've found some type of destructor._

```cpp 

#include <iostream> 
using namespace std;

public:
 // Destructor
    ~Rectangle();
```

### **Encapsulation:**

In object-oriented programming, the technique of keeping together data structures and the methods which act on them.

![encapsulation](https://github.com/aaniaahh/OOP/blob/main/assignments/OOP_Primer/images/encapsulation.jpg)

### **Exception Handling:**

Mechanisms to handle runtime errors and if the programmer does not provide a handler for a given exception, a built-in system exception handler will usually be called resulting in abortion of the program run and some kind of error indication being returned to the user.

+ Catch Block: Catches the exception thrown by the try block. It specifies the type of exception it can handle.

+ Throw Statement: Throws an exception object when an error condition is detected. 

+ Try Block: Encloses the code that might throw an exception.

```cpp 

#include <iostream> 
using namespace std;

try {         
     // Code that might throw an exception
     throw SomeExceptionType("Error message");
 } 
catch( ExceptionName e1 )  {   
     // catch block catches the exception that is thrown from try block
 } 

```

### **File I/O in OOP:**

Operations for reading from and writing to files, often encapsulated in classes to manage file handling.

![files](https://github.com/aaniaahh/OOP/blob/main/assignments/OOP_Primer/images/files.png)

### **Friends:**

A key term that is used to access private and protected members from its class, but it is not a member.

```cpp

friend class className;    // declared in the base class

```

### **Generics:**

A Java term that allows classes and methods to operate on different data types without specifying the exact type at compile-time. The advantages of generics are code reusability, avoids function overloading, and once written it can be used for multiple times/cases.

In C++, generics are implemented bY using templates (simple, yet powerful tool).

+ Classes that holds an array, map, and etc can possibly use generics very efficiently.

### **Getter:**

A term used in a class to retrieve values from the private attributes, ensuring encapsulation.

```cpp
#include <iostream> 
using namespace std;

// Getters
    double getLength() const;
    double getWidth() const;

```

### **Inheritance:**

The ability to derive new classes from existing classes. A derived class (or "subclass") inherits the instance variables and methods of the "base class" (or "superclass"), and may add new instance variables and methods. New methods may be defined with the same names as those in the base class, in which case they override the original one.

+ Single Inheritance: A derived class inherits from _only one_ base class.

```cpp 

#include <iostream>
using namespace std;

class Animal {
    public:
        void eat() { cout << "This animal eats food."; }
};
class Dog : public Animal {
    public:
        void bark() { cout << "The dog barks."; }
};

```

+ Multiple Inheritance: A derived class inherits from _two or more_ base classes.

```cpp 

#include <iostream> 
using namespace std;

class A { /* ... */ };
class B { /* ... */ };
class C : public A, public B { /* ... */ };

```

+ MultiLevel Inheritance: A derived class inherits from another derived class.

```cpp 

#include <iostream> 
using namespace std;

class A { /* ... */ };
class B : public A { /* ... */ };
class C : public B { /* ... */ };

```

+ Hierachical Inheritance: Multiple classes inherits from a single base class.

```cpp 

#include <iostream> 
using namespace std;

class A { /* ... */ };
class B : public A { /* ... */ };
class C : public A { /* ... */ };

```

+ Hybrid Inheritance: A combination of two or more types of inheritance. It can often introduce complexities like the diamond problem, which we just try to avoids those.

```cpp

 #include <iostream> 
 using namespace std;

class A { /* ... */ };
class B : public A { /* ... */ };
class C : public A { /* ... */ };
class D : public B, public C { /* ... */ };

```


### **Instance Variable:**

In C++, an instance variable (also called a member variable) is a variable that is associated with each instance of a class. It's declared inside the class definition, but outside any function.

```cpp

#include <iostream> 
using namespace std;

class Rectangle {
public:
    int width;  // Instance variable
    int height; // Instance variable

    int area() {
        return width * height;
    }
};

int main() {
    Rectangle rect1;
    rect1.width = 5;
    rect1.height = 10;

    Rectangle rect2;
    rect2.width = 3;
    rect2.height = 7;

    cout << "Area of rect1: " << rect1.area() << endl;
    cout << "Area of rect2: " << rect2.area() << endl;

    return 0;
}

```

### **Interfaces:**

Define a contract for classes, specifying methods that ### **MUST### ** be implemented. With it typially implementing #include <iostream> using pure virtual classes.

```cpp

#include <iostream> 
using namespace std;
class OS
{
public:
virtual void size() = 0;
void type()
{
cout<<"It is a windows operating system!"<<endl;
}
};
class Windows: public OS
{
public:
void size()
{
cout<<"The size is 4.90gb!"<<endl;
}
};
int main()
{
cout<<"TechVidvan Tutorial: C++ Interfaces!"<<endl<<endl;
Windows data;
data.size();
data.type();
return 0;
}

```

### **Iterators:**

An iterator in C++ is a pointer-like object that points to an element of the STL container. They are generally used to loop through the contents of the STL container in C++. The main advantage of STL iterators is that they make the STL algorithms independent of the type of container used. We can just pass the iterator to the container elements instead of the container itself to the STL algorithms.

```cpp

#include <iostream> 
using namespace std;
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    // Defining an iterator pointing to
    // the beginning of the vector
    vector<int>::iterator first = arr.begin();

    // Defining an iterator pointing to the
      // end of the vector
    vector<int>::iterator last = arr.end();

    }


```

### **Memory Management:**

+ Garbage Collection: Automatic memory cleanup in languages like Java or Python.

+ Pointers: Variables in languages like C++ that hold memory addresses, requiring manual management.

```cpp 

#include <iostream> 
using namespace std;

// declare an int pointer
int* point_var;

// dynamically allocate memory
// using the new keyword 
point_var = new int;

// assign value to allocated memory
*point_var = 45;

```

### **Method:**

A function that is a member of a class and operates on the data members of the class and defines the behavior of the class's objects.

```cpp
#include <iostream> 
using namespace std;

// method to calculate area
 int area() {
        return width * height;
    }

```

### **Method Overloading:**

Method overloading allows you to define multiple functions with the same name within the same scope, but with different parameters. The compiler determines which function to call based on the number and types of arguments passed.

```cpp

#include <iostream> 
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;

    cout << calc.add(2, 3) << std::endl;       // Calls the add function using ints
    cout << calc.add(2.5, 3.7) << std::endl;   // Calls the add function using doubles
    cout << calc.add(1, 2, 3) << std::endl;     // Calls the add function that uses 3 parameters

}

```

### **Multithreading in OOP:**

Sharing a single CPU between multiple tasks (or "threads") in a way designed to minimise the time required to switch threads. This is accomplished by sharing as much as possible of the program execution environment between the different threads so that very little state needs to be saved and restored when changing thread.
_Be sure to #include <thread> at the top of your code_

![threading](https://raw.githubusercontent.com/aaniaahh/OOP/refs/heads/main/assignments/OOP_Primer/images/thread.webp)


### **Objects:**

An instance of the data structure and behavior defined by the object's class. Each object has its own values for the instance variables of its class and can respond to the methods defined by its class.

```cpp

#include <iostream> 
using namespace std;

Class Car {

    private: // add code

    protected: // add code

    public: // add code

};
int main() {
    Car myCar; // creating an object for my Car class
}

```

### **Object Relationships:**

Refer to the different ways in which objects interact or are related to one another within a system. These relationships help define how objects collaborate and depend on each other in the context of the application's design.

+ Association: A general "uses-a" relationship between objects.

  - [ ] A Doctor _uses a_ patient to show what he learned (treats).

+ Aggregation: A weak "has-a" relationship, where the contained object can exist independently.

  - [ ] A department _has a_ lot of employee.

+ Composition: A strong "has-a" relationship, where the contained object depends on the container.

  - [ ] A car _has a_ break pad.

+ Inheritance: A "is-a" relationship, where a subclass inherits from a superclass.

  - [ ] A dog _is a_ type of animal.

### **Object-Oriented Design Principles:**

A design method in which a system is modelled as a collection of cooperating objects and individual objects are treated as instances of a class within a class hierarchy. Four stages can be identified: identify the classes and objects, identify their semantics, identify their relationships and specify class and object interfaces and implementation.

+ Type of OOP Principles: Abstraction, Encapsulations, Inheritance, and Polymorphism

### **Operator Overloading:**

The ability to define or alter custom behavior for operators (e.g., +, ==) in a class. For example, earlier this semester we did a [Fraction Class](https://github.com/aaniaahh/OOP/blob/main/assignments/P01/Fraction.cpp) that contained overloading operators.

```cpp

 Fraction Fraction :: operator-(const Fraction& other) 
    {
        // TODO: Implement the subtraction logic
         // 1. Find the least common denominator (LCD)
        int lcdVal = lcd(denominator, other.denominator);

        // 2. Adjust both fractions to have this denominator
        int numerator1 = numerator * (lcdVal / denominator);
        int numerator2 = other.numerator * (lcdVal / other.denominator);

        // 3. Add the numerators
        int resultNumerator = numerator1 - numerator2;

        // 4. Simply the fraction answered 
        Fraction results(resultNumerator, lcdVal);
        results.reduceFrac();

        // 4. Return the result as a simplified fraction
        return results;
    }
```

### **Overloading:**

Use of a single symbol to represent operators with different argument types, used either, as a monadic operator to negate an expression, or as a dyadic operator to return the difference between two expressions. 

```cpp

#include <iostream>
using namespace std;

class Print {
public:
    void show(int i) {
        cout << "Integer: " << i << std::endl;
    }

    void show(double d) {
        cout << "Double: " << d << std::endl;
    }

    void show(std::string s) {
        cout << "String: " << s << std::endl;
    }
};

int main() {
    Print p;
    p.show(10);        // Calls the integer version
    p.show(10.5);      // Calls the double version
    p.show("Hello");   // Calls the string version
}

```

### **Pointer:**

A variable that stores the memory address of another variable. Commonly used in languages like C++ for dynamic memory allocation and manipulation.

```cpp

#include <iostream>
using namespace std;

class Student {
public:
    int age;

    Student(int a) : age(a) {}
};

int main() {
    Student* studentPtr = new Student(20);  // Pointer to a dynamically allocated Student object
    cout << "Student's age: " << studentPtr->age << std::endl;  // Accessing member via pointer
    delete studentPtr;  // Free the allocated memory
}

```

### **Polymorphism:**

The ability to present the same interface for different underlying data types.

+ Static Polymorphism is resolved during compile-time also known as method overloading.

```cpp
#include <iostream>
using namespace std;

class Calculator {
public:
    // Method to add two integers
    int add(int a, int b) {
        return a + b;
    }

    // Overloaded method to add three integers
    int add(int a, int b, int c) {
        return a + b + c;
    }

    // Overloaded method to add two doubles
    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    Calculator calc;

    cout << "Add two integers: " << calc.add(2, 3) << endl;        // Output: 5
    cout << "Add three integers: " << calc.add(1, 2, 3) << endl;  // Output: 6
    cout << "Add two doubles: " << calc.add(2.5, 3.5) << endl;    // Output: 6.0

    return 0;
}


```

+ Dynamic Polymorphism is resolved during runtime also known as method overriding.

```cpp

#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    virtual void draw() {  // Virtual function
        cout << "Drawing a generic shape" << endl;
    }
};

// Derived class
class Circle : public Shape {
public:
    void draw() override {  // Override base class function
        cout << "Drawing a Circle" << endl;
    }
};

// Derived class
class Rectangle : public Shape {
public:
    void draw() override {  // Override base class function
        cout << "Drawing a Rectangle" << endl;
    }
};

int main() {
    Shape* shapePtr;  // Base class pointer

    Circle circle;
    Rectangle rectangle;

    shapePtr = &circle;
    shapePtr->draw();  // Output: Drawing a Circle (dynamic binding)

    shapePtr = &rectangle;
    shapePtr->draw();  // Output: Drawing a Rectangle (dynamic binding)

    return 0;
}

```

### **Properties:**

Mechanisms to control access to attributes, often using getters and setters.


### **Queues:**

A collection that follows the First-In-First-Out (FIFO) principle, where elements are added to the rear and removed from the front.

 + Enqueue: a term used to add items to the front (looks like the rear) of the queue

 + Dequeue: a term used that removes and returns items from the front of the queue

![queues](https://github.com/aaniaahh/OOP/blob/main/assignments/OOP_Primer/images/queue.jpg)

### **Shallow Copy:**

A copy operation where only the reference to the objects is copied, not the objects themselves. Changes to the referenced objects affect both the original and the copy.

```cpp

#include <iostream>
using namespace std;

class ShallowCopy {
public:
    int* data;

    ShallowCopy(int value) {
        data = new int(value);
    }

    ShallowCopy(const ShallowCopy& obj) {  // Shallow copy
        data = obj.data;
    }

    void display() {
        cout << "Data: " << *data << endl;
    }
};

int main() {
    ShallowCopy obj1(10);
    ShallowCopy obj2 = obj1;  // Shallow copy

    obj1.display();  // Output: Data: 10
    obj2.display();  // Output: Data: 10

    *obj2.data = 20;  // Changing obj2 also changes obj1

    obj1.display();  // Output: Data: 20
    obj2.display();  // Output: Data: 20

    return 0;
}

```

### **Setter:**

A term used in a class to set values, ensuring encapsulation.

```cpp

#include <iostream> 
using namespace std;

// Setters
    void setLength(double len);
    void setWidth(double wid);
```

### **SOLID Principles:**

A set of five principles for good object-oriented design introduced by Robert C. Martin:

+ ### **S### **ingle Responsibility: A class should have only one reason to change, meaning it should have only one job or responsibility.

+ ### **O### **pen/Closed: Software entities (classes, modules, functions, etc.) should be open for extension but closed for modification.

+ ### **L### **iskov Substitution: Objects of a superclass should be replaceable with objects of a subclass without affecting the correctness of the program.

+ ### **I### **nterface Segregation: A client should not be forced to depend on interfaces it does not use.

+ ### **D### **ependency Inversion: High-level modules should not depend on low-level modules. Both should depend on abstractions. Abstractions should not depend on details. Details should depend on abstractions.


### **Stacks:**

A collection that follows the Last-In-First-Out (LIFO) principle, where the last element added to the stack is the first one to be removed. 

+ Pop: A term used to remove the top item from the stack, unless the stack is empty.

+ Push: A term used to push items onto the top of the stack, unless the stack is full.

![stacks](https://github.com/aaniaahh/OOP/blob/main/assignments/OOP_Primer/images/stack.jpg)


### **Static (Methods and Variables):**

Static Members: Belong to the class rather than instances of the class. They can be accessed without creating an object.

```cpp

#include <iostream>
 using namespace std;

class Counter {
private:
    static int count;  // Static member

public:
    Counter() { count++; }

    static void showCount() {  // Static method
        cout << "Count: " << count << endl;
    }
};

int Counter::count = 0;  // Definition of static member

int main() {
    Counter c1, c2, c3;
    Counter::showCount();  // Output: Count: 3
}

```

### **Templates:**

A C++ term that provides a similar functionality, enabling code reuse for multiple data types.

```cpp

#include <iostream>
using namespace std;

template <typename T>

class Calculator {

public:
    T add(T a, T b) { return a + b; }
    T subtract(T a, T b) { return a - b; }
};

int main() {
    Calculator<int> intCalc;
    Calculator<double> doubleCalc;

    cout << "Int addition: " << intCalc.add(3, 5) << endl;          // Output: 8
    cout << "Double subtraction: " << doubleCalc.subtract(7.5, 2.3) << endl;  // Output: 5.2
}

```

### **Test-Driven Development:**

Writing tests before writing code.

![Development](https://github.com/aaniaahh/OOP/blob/main/assignments/OOP_Primer/images/testDevelopment.png)

### **Unit Testing:**

Testing individual components.

![Unit Testing](https://github.com/aaniaahh/OOP/blob/main/assignments/OOP_Primer/images/unitTest.png)

### **UML Diagrams and Modeling:**

Unified Modeling Language (UML) diagrams visually represent object-oriented systems, including class diagrams, sequence diagrams, etc.
 
![UML](https://github.com/aaniaahh/OOP/blob/main/assignments/OOP_Primer/images/umlDiagrams.webp)

### **Virtual Function:**

A memeber function that can be overridden in a derived class to provide specific implementation.
+ _Virtual_ is a keyword in C++ used to enable dynamic runtime method dispatch, supporting polymorphism.

```cpp

#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() {  // Virtual function
        cout << "Base class display function" << endl;
    }
};

class Derived : public Base {
public:
    void display() override {  // Overriding the virtual function
        cout << "Derived class display function" << endl;
    }
};

int main() {
    Base* bPtr;
    Derived d;

    bPtr = &d;
    bPtr->display();  // Output: Derived class display function
}

```
