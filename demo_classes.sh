#!/bin/bash

# C++ Class Implementation Demo Script
# This script demonstrates how to use the generated classes

echo "=== C++ Class Implementation Demo ==="
echo ""

# Create a demo directory
mkdir -p cpp_class_demo
cd cpp_class_demo

echo "1. Generating a basic class..."
../generate_class.sh Person

echo ""
echo "2. Generating an abstract base class..."
../advanced_class_generator.sh -b Animal

echo ""
echo "3. Generating a derived class..."
../advanced_class_generator.sh -d Dog Animal

echo ""
echo "4. Generating a singleton class..."
../advanced_class_generator.sh -s Logger

echo ""
echo "5. Generating a template class..."
../advanced_class_generator.sh -t Container

echo ""
echo "6. Generating an interface..."
../advanced_class_generator.sh -i IProcessor

echo ""
echo "7. Creating a comprehensive test program..."

cat > main.cpp << 'EOF'
#include <iostream>
#include <memory>
#include <vector>

// Include all generated headers
#include "Person.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Logger.hpp"
#include "Container.hpp"
#include "IProcessor.hpp"

int main() {
    std::cout << "=== C++ Class Implementation Demo ===" << std::endl;
    std::cout << std::endl;

    // 1. Basic Class Demo
    std::cout << "1. Basic Class (Person) Demo:" << std::endl;
    Person person1;
    Person person2("Alice", 25);
    Person person3(person2);  // Copy constructor
    person1 = person2;        // Assignment operator
    
    person1.display();
    person2.display();
    Person::printInfo();
    std::cout << std::endl;

    // 2. Inheritance Demo (Animal/Dog)
    std::cout << "2. Inheritance Demo:" << std::endl;
    std::vector<Animal*> animals;
    animals.push_back(new Dog("Buddy", 1, "Golden Retriever"));
    animals.push_back(new Dog("Max", 2, "German Shepherd"));

    for (const auto& animal : animals) {
        animal->display();
        animal->makeSound();
        animal->move();
        std::cout << std::endl;
    }

    // Clean up
    for (auto& animal : animals) {
        delete animal;
    }
    std::cout << std::endl;

    // 3. Singleton Pattern Demo
    std::cout << "3. Singleton Pattern Demo:" << std::endl;
    Logger* logger1 = Logger::getInstance();
    Logger* logger2 = Logger::getInstance();
    
    std::cout << "logger1 == logger2: " << (logger1 == logger2 ? "true" : "false") << std::endl;
    
    logger1->setData("Application started");
    logger2->processData();  // Same instance
    logger1->display();
    Logger::destroyInstance();
    std::cout << std::endl;

    // 4. Template Class Demo
    std::cout << "4. Template Class Demo:" << std::endl;
    Container<int> intContainer(5);
    Container<std::string> stringContainer(3);

    try {
        intContainer.push_back(10);
        intContainer.push_back(20);
        intContainer.push_back(30);
        
        stringContainer.push_back("Hello");
        stringContainer.push_back("World");
        
        intContainer.display();
        intContainer.displayInfo();
        
        stringContainer.display();
        stringContainer.displayInfo();
        
        std::cout << "Element at index 1: " << intContainer.at(1) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // 5. Interface Demo
    std::cout << "5. Interface Demo:" << std::endl;
    IProcessor* processor = new IProcessorImpl();
    
    processor->printInterface();
    processor->display();
    processor->initialize();
    processor->display();
    processor->process();
    processor->display();
    processor->cleanup();
    processor->display();
    
    delete processor;
    std::cout << std::endl;

    std::cout << "=== Demo Complete ===" << std::endl;
    return 0;
}
EOF

echo ""
echo "8. Creating Makefile for compilation..."

cat > Makefile << 'EOF'
# Makefile for C++ Class Demo

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = class_demo

# Source files
SRCS = main.cpp Person.cpp Animal.cpp Dog.cpp Logger.cpp IProcessorImpl.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files (for dependency tracking)
HEADERS = Person.hpp Animal.hpp Dog.hpp Logger.hpp Container.hpp IProcessor.hpp

# Default rule
all: $(NAME)

# Link object files to create executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Test rule
test: $(NAME)
	./$(NAME)

# Debug version
debug: CXXFLAGS += -g -DDEBUG
debug: $(NAME)

# Individual class compilation tests
test-compile: 
	@echo "Testing individual class compilation..."
	$(CXX) $(CXXFLAGS) -c Person.cpp -o person_test.o && echo "✓ Person compiles" || echo "✗ Person failed"
	$(CXX) $(CXXFLAGS) -c Animal.cpp -o animal_test.o && echo "✓ Animal compiles" || echo "✗ Animal failed"  
	$(CXX) $(CXXFLAGS) -c Dog.cpp -o dog_test.o && echo "✓ Dog compiles" || echo "✗ Dog failed"
	$(CXX) $(CXXFLAGS) -c Logger.cpp -o logger_test.o && echo "✓ Logger compiles" || echo "✗ Logger failed"
	$(CXX) $(CXXFLAGS) -c IProcessorImpl.cpp -o iprocessor_test.o && echo "✓ IProcessor compiles" || echo "✗ IProcessor failed"
	rm -f *_test.o

.PHONY: all clean fclean re test debug test-compile
EOF

echo ""
echo "9. Files created in cpp_class_demo/:"
ls -la

echo ""
echo "=== Demo Setup Complete! ==="
echo ""
echo "To test the generated classes:"
echo "1. cd cpp_class_demo"
echo "2. make test-compile  # Test individual compilation"
echo "3. make test         # Compile and run the full demo"
echo ""
echo "Available make targets:"
echo "  make all          # Build the demo"
echo "  make test         # Build and run"
echo "  make debug        # Build with debug info"
echo "  make test-compile # Test individual class compilation"
echo "  make clean        # Clean object files"
echo "  make fclean       # Clean everything"
echo ""

cd ..
echo "Demo directory created at: $(pwd)/cpp_class_demo"