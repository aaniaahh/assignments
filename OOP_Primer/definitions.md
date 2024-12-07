# Assignment 4 - Basic OOP Terminology

+ Name: Aniah Myles

+ Date: 06 Dec. 2024

+ Class: 2143-102 OOP

## Definitions:

**Abstraction:**

The process of hiding implementation details and showing only the necessary features of an object. It simplifies complexity by providing a clear interface.

**Abstract Classes:**

In object-oriented programming, a class designed only as a parent from which sub-classes MAY be derived, but which is not itself suitable for instantiation. Often used to "abstract out" incomplete sets of features which may then be shared by a group of sibling sub-classes which add different variations of the missing pieces. It can also be noticed if the class has at least one pure virtual function.

```cpp
#include <iostream>
#include <cmath>
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

**Access Modifiers:**

 A keyword that determines the visibility or accessibility of a class, method, variable, or other members in object-oriented programming. It controls where and how a particular class or member can be accessed, either within the same class, subclass, or from other classes or packages.

 + Private: An access modifier that can **only** be accessed within the class.

 + Protected: An access modifier that can be accessed within the same class or by a derived class.

 + Public: An access modifier that can be accessed from anywhere.

```cpp

class Example {
private:
    int privateValue;  // Accessible only within this class

protected:
    int protectedValue;  // Accessible in derived classes

public:
    int publicValue;  // Accessible from anywhere
};

```

**Attributes:**

Characteristics of an object, often represented as class variables.

```cpp

using namespace std;

class Dog {
public:
    string name;
    int age;
};

```

**Class:**

 The prototype for an object in an object-oriented language; analogous to a derived type in a procedural language. A class may also be considered to be a set of objects which share a common structure and behaviour. The structure of a class is determined by the class variables which represent the state of an object of that class and the behaviour is given by a set of methods associated with the class.

```cpp

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

**Class Variable:**

A variable that is shared among all instances of a class. Defined using the * *static* * keyword in many programming languages.

![classVariable](https://github.com/aaniaahh/OOP/blob/main/assignments/OOP_Primer/images/classVariables.jpg)

**Collections:**

 Containers used to store and manage groups of related objects.

+ Examples of Collections: arrays, class, lists, sets, tree, and etc.


**Composition:**

A design principle where objects are built by containing other objects, representing a **"has-a"** relationship.

```cpp

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

**Concrete Class:**

A class that can be instantiated to create objects and ssed to define fully implemented behavior for objects.

```cpp

#include <iostream>
#include <cmath>
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

**Constructors:**

A function provided by a class to initialise a newly created object. The constructor function typically has the same name as the class. It may take arguments, e.g. to set various attributes of the object or it may just leave everything undefined to be set elsewhere.

+ Copy Constructor: A constructor that creates a new object as a copy of an existing object. It is used when an object is initialized from another object of the same type.

+ Default Constructor: A constructor that does not take any arguments (or all its parameters have default values). It initializes an object with default values.

+ Parameterized Constructor: A constructor that takes arguments to initialize an object with specific values.

_If you could spot functions with the same name as the class, you've found the constructors of that class._

```cpp

public:
    // Default constructor
    Rectangle();

    // Parameterized constructor
    Rectangle(double len, double wid);

    // Copy Constructor
    Rectangle(const Rectangle& other);

```

**Deep Copy:**

A copy operation where an object and all the objects it references are duplicated, creating a completely independent clone. Changes to the copied object do not affect the original.

```cpp

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

**Derived Class:**

A class that inherits from a base class. It can extend or override functionality defined in the base class.

```cpp
class Base {
public:
    void greet() { std::cout << "Hello from Base\n"; }
};

class Derived : public Base {};

```

**Design Patterns:**

Identifies classes and instances, their roles, collaborations and responsibilities. Each design pattern focuses on a particular object-oriented design problem or issue. It describes when it applies, whether it can be applied in the presence of other design constraints, and the consequences and trade-offs of its use.

+ Singleton: Ensures a class has only one instance.

+ Factory: Creates objects without specifying their exact class.

+ Observer: Defines a dependency where objects get notified of changes.

**Destructors:**

A function provided by a class in C++ and some other object-oriented languages to delete an object, also know as the inverse of a constructor.

_If you can spot a '~' function in a class, you've found some type of destructor._

```cpp

public:
 // Destructor
    ~Rectangle();
```

**Encapsulation:**

In object-oriented programming, the technique of keeping together data structures and the methods which act on them.



**Exception Handling:**

Mechanisms to handle runtime errors and if the programmer does not provide a handler for a given exception, a built-in system exception handler will usually be called resulting in abortion of the program run and some kind of error indication being returned to the user.


**File I/O in OOP:**

Operations for reading from and writing to files, often encapsulated in classes to manage file handling.


**Friends:**

A key term that is used to access private and protected members of another class.


**Generics:**

A Java term that allows classes and methods to operate on different data types without specifying the exact type at compile-time.

**Getter:**

A term used in a class to retrieve values from the private attributes, ensuring encapsulation.

**Inheritance:**

The ability to derive new classes from existing classes. A derived class (or "subclass") inherits the instance variables and methods of the "base class" (or "superclass"), and may add new instance variables and methods. New methods may be defined with the same names as those in the base class, in which case they override the original one.

+ Single Inheritance: A derived class inherits from _only one_ base class.

```cpp
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
class A { /* ... */ };
class B { /* ... */ };
class C : public A, public B { /* ... */ };

```

+ MultiLevel Inheritance: A derived class inherits from another derived class.

```cpp
class A { /* ... */ };
class B : public A { /* ... */ };
class C : public B { /* ... */ };

```

+ Hierachical Inheritance: Multiple classes inherits from a single base class.

```cpp
class A { /* ... */ };
class B : public A { /* ... */ };
class C : public A { /* ... */ };

```

+ Hybrid Inheritance: A combination of two or more types of inheritance. It can often introduce complexities like the diamond problem, which we just try to avoids those.

```cpp
class A { /* ... */ };
class B : public A { /* ... */ };
class C : public A { /* ... */ };
class D : public B, public C { /* ... */ };

```


**Instance Variable:**

Variables that are specific to an instance of a class.


**Interfaces:**

Define a contract for classes, specifying methods that **MUST** be implemented.

**Iterators:**

Objects used to traverse elements in a collection.


**Member Variable:**

Another term for attributes or fields of a class.


**Memory Management:**

+ Garbage Collection: Automatic memory cleanup in languages like Java or Python.

+ Pointers: Variables in languages like C++ that hold memory addresses, requiring manual management.


**Method Overloading:**

Defining multiple methods with the same name, but different parameter lists in the same class.


**Method:**

A function defined within a class.


**Multiple Inheritance:**

The possibility that a class may have more than one direct superclass in the class hierarchy.


**Multithreading in OOP:**

Sharing a single CPU between multiple tasks (or "threads") in a way designed to minimise the time required to switch threads. This is accomplished by sharing as much as possible of the program execution environment between the different threads so that very little state needs to be saved and restored when changing thread.


**Objects:**

An instance of the data structure and behaviour defined by the object's class. Each object has its own values for the instance variables of its class and can respond to the methods defined by its class.


**Object Relationships:**

Refer to the different ways in which objects interact or are related to one another within a system. These relationships help define how objects collaborate and depend on each other in the context of the application's design.

+ Association: A general "uses-a" relationship between objects.

+ Aggregation: A weak "has-a" relationship, where the contained object can exist independently.

+ Composition: A strong "has-a" relationship, where the contained object depends on the container.

+ Inheritance: A "is-a" relationship, where a subclass inherits from a superclass.


**Object-Oriented Design Principles:**

A design method in which a system is modelled as a collection of cooperating objects and individual objects are treated as instances of a class within a class hierarchy. Four stages can be identified: identify the classes and objects, identify their semantics, identify their relationships and specify class and object interfaces and implementation.


**Operator Overloading:**

The ability to define or alter custom behavior for operators (e.g., +, ==) in a class.


**Overloading:**

Use of a single symbol to represent operators with different argument types, used either, as a monadic operator to negate an expression, or as a dyadic operator to return the difference between two expressions. 


**Pointer:**

A variable that stores the memory address of another variable. Commonly used in languages like C++ for dynamic memory allocation and manipulation.


**Polymorphism:**

The ability to present the same interface for different underlying data types.

+ Static Polymorphism is resolved during compile-time also known as method overloading.
+ Dynamic Polymorphism is resolved during runtime also known as method overriding.


**Properties:**

Mechanisms to control access to attributes, often using getters and setters.

**Pure Virtual Function:**

A virtual function with no implementation, forcing derived classes to provide implementation. 

**Queues:**

A collection that follows the First-In-First-Out (FIFO) principle, where elements are added to the rear and removed from the front.

+ Key words
 + Enqueue: a term used to add items to the front (looks like the rear) of the queue

 + Dequeue: a term used that removes and returns items from the front of the queue

![queues](https://github.com/aaniaahh/OOP/blob/main/assignments/OOP_Primer/images/queue.jpg)

**Shallow Copy:**

A copy operation where only the reference to the objects is copied, not the objects themselves. Changes to the referenced objects affect both the original and the copy.

**Setter:**

A term used in a class to set values, ensuring encapsulation.

**SOLID Principles:**

A set of five principles for good object-oriented design introduced by Robert C. Martin:

+ **S**ingle Responsibility: A class should have only one reason to change, meaning it should have only one job or responsibility.

+ **O**pen/Closed: Software entities (classes, modules, functions, etc.) should be open for extension but closed for modification.

+ **L**iskov Substitution: Objects of a superclass should be replaceable with objects of a subclass without affecting the correctness of the program.

+ **I**nterface Segregation: A client should not be forced to depend on interfaces it does not use.

+ **D**ependency Inversion: High-level modules should not depend on low-level modules. Both should depend on abstractions. Abstractions should not depend on details. Details should depend on abstractions.


**Stacks:**

A collection that follows the Last-In-First-Out (LIFO) principle, where the last element added to the stack is the first one to be removed. 

+ Pop: A term used to remove the top item from the stack, unless the stack is empty.

+ Push: A term used to push items onto the top of the stack, unless the stack is full.

![stacks](https://github.com/aaniaahh/OOP/blob/main/assignments/OOP_Primer/images/stack.jpg)

**Static (Methods and Variables):**

Static Members: Belong to the class rather than instances of the class. They can be accessed without creating an object.


**Templates:**

A C++ term that provides a similar functionality, enabling code reuse for multiple data types.


**Test-Driven Development:**

Writing tests before writing code.


**Unit Testing:**

Testing individual components.


**UML Diagrams and Modeling:**

Unified Modeling Language (UML) diagrams visually represent object-oriented systems, including class diagrams, sequence diagrams, etc.


**Virtual:**

A keyword in C++ used to enable dynamic runtime method dispatch, supporting polymorphism. 


**Virtual Function:**

A memeber function that can be overridden in a derived class to provide specific implementation.


