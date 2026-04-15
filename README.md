# C++ Class Implementation Guide

## Overview
This directory contains scripts to help you generate and understand C++ class implementations, following 42 School standards and best practices.

## Files Description

### Scripts
- **`generate_class.sh`** - Basic class generator with Orthodox Canonical Form
- **`advanced_class_generator.sh`** - Advanced class patterns (inheritance, singleton, templates, etc.)
- **`demo_classes.sh`** - Creates a comprehensive demo showing all class types

### Usage Examples

#### 1. Basic Class Generation
```bash
./generate_class.sh Student
./generate_class.sh Student school_namespace
```
Creates: `Student.hpp` and `Student.cpp` with:
- Orthodox Canonical Form (required in C++98)
- Default constructor, copy constructor, assignment operator, destructor
- Basic getters/setters and member functions

#### 2. Advanced Class Patterns

##### Abstract Base Class
```bash
./advanced_class_generator.sh -b Animal
```
Creates abstract base class with pure virtual functions.

##### Derived Class
```bash
./advanced_class_generator.sh -d Dog Animal
```
Creates a derived class that inherits from Animal.

##### Singleton Pattern
```bash
./advanced_class_generator.sh -s Logger
```
Creates a singleton class with private constructors and static instance management.

##### Template Class
```bash
./advanced_class_generator.sh -t Container
```
Creates a template class with type-safe container functionality.

##### Interface (Pure Virtual Class)
```bash
./advanced_class_generator.sh -i IProcessor
```
Creates an interface with pure virtual functions and example implementation.

## C++ Class Concepts Explained

### 1. Orthodox Canonical Form
Every C++ class should implement the "Big Four":
- **Default Constructor**: `ClassName()`
- **Copy Constructor**: `ClassName(const ClassName& other)`
- **Copy Assignment Operator**: `ClassName& operator=(const ClassName& other)`
- **Destructor**: `~ClassName()`

### 2. Access Specifiers
- **`private:`** - Members accessible only within the class
- **`protected:`** - Members accessible within the class and its derived classes
- **`public:`** - Members accessible from anywhere

### 3. Inheritance
```cpp
class Base {
    virtual void someFunction() = 0;  // Pure virtual
    virtual void anotherFunction();   // Virtual (can be overridden)
};

class Derived : public Base {
    virtual void someFunction() override;  // Must implement
    virtual void anotherFunction() override;  // Optional override
};
```

### 4. Virtual Functions
- **Virtual**: Can be overridden by derived classes
- **Pure Virtual**: Must be implemented by derived classes (makes class abstract)
- **Virtual Destructor**: Essential for proper cleanup through base class pointers

### 5. Static Members
```cpp
class MyClass {
private:
    static int count;  // Shared by all instances
public:
    static void printCount();  // Can be called without instance
};
```

### 6. Templates (Generic Programming)
```cpp
template <typename T>
class Container {
    T data;
public:
    void set(const T& value) { data = value; }
    T get() const { return data; }
};
```

### 7. Design Patterns

#### Singleton Pattern
Ensures only one instance of a class exists:
```cpp
class Singleton {
private:
    static Singleton* instance;
    Singleton() {}  // Private constructor
public:
    static Singleton* getInstance();
};
```

#### Interface Pattern
Define contracts using pure virtual functions:
```cpp
class IDrawable {
public:
    virtual ~IDrawable() {}
    virtual void draw() = 0;
    virtual void clear() = 0;
};
```

## Compilation Tips

### Basic Compilation
```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program
```

### Makefile Template
```makefile
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = program
SRCS = main.cpp Class1.cpp Class2.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
```

## Common 42 School Requirements

### 1. Orthodox Canonical Form
Always implement the four essential member functions.

### 2. Header Guards
```cpp
#ifndef CLASSNAME_HPP
#define CLASSNAME_HPP
// class definition
#endif
```

### 3. Const Correctness
- Mark member functions `const` if they don't modify the object
- Use `const` references for parameters when appropriate

### 4. Memory Management
- Always pair `new` with `delete`
- Consider RAII (Resource Acquisition Is Initialization)
- Use virtual destructors for polymorphic classes

### 5. Naming Conventions
- Class names: PascalCase (`MyClass`)
- Member variables: underscore prefix (`_memberVar`)
- Functions: camelCase (`memberFunction`)

## Quick Start

1. **Create a basic class:**
   ```bash
   ./generate_class.sh MyClass
   ```

2. **Run the complete demo:**
   ```bash
   ./demo_classes.sh
   cd cpp_class_demo
   make test
   ```

3. **Generate specific pattern:**
   ```bash
   ./advanced_class_generator.sh -s DatabaseManager
   ```

## Advanced Features

### Exception Handling
```cpp
class MyClass {
public:
    void riskyOperation() {
        if (errorCondition) {
            throw std::runtime_error("Operation failed");
        }
    }
};
```

### Operator Overloading
```cpp
class Vector {
public:
    Vector operator+(const Vector& other) const;
    Vector& operator+=(const Vector& other);
    bool operator==(const Vector& other) const;
    std::ostream& operator<<(std::ostream& os, const Vector& v);
};
```

### Friend Functions
```cpp
class MyClass {
private:
    int secret;
public:
    friend void friendFunction(const MyClass& obj);
};
```

## Debugging Tips

1. **Use const correctness** to catch logic errors
2. **Initialize all member variables** in constructors
3. **Use virtual destructors** for inheritance
4. **Check for self-assignment** in operator=
5. **Test copy semantics** thoroughly

## Resources

- C++98 Standard Reference
- 42 School C++ Subject PDFs
- Effective C++ by Scott Meyers
- C++ Core Guidelines

---

Happy coding! 🚀