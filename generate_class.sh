#!/bin/bash

# C++ Class Generator Script
# Usage: ./generate_class.sh ClassName [namespace]

if [ $# -lt 1 ]; then
    echo "Usage: $0 ClassName [namespace]"
    echo "Example: $0 Student"
    echo "Example: $0 Animal zoo"
    exit 1
fi

CLASS_NAME=$1
NAMESPACE=${2:-""}
HEADER_FILE="${CLASS_NAME}.hpp"
SOURCE_FILE="${CLASS_NAME}.cpp"

# Convert class name to uppercase for header guards
HEADER_GUARD=$(echo "${CLASS_NAME}" | tr '[:lower:]' '[:upper:]')_HPP

# Generate header file
cat > "$HEADER_FILE" << EOF
#ifndef ${HEADER_GUARD}
#define ${HEADER_GUARD}

#include <iostream>
#include <string>

EOF

if [ ! -z "$NAMESPACE" ]; then
    echo "namespace $NAMESPACE {" >> "$HEADER_FILE"
    echo "" >> "$HEADER_FILE"
fi

cat >> "$HEADER_FILE" << EOF
class $CLASS_NAME {
private:
    // Private member variables
    std::string _name;
    int _value;

public:
    // Orthodox Canonical Form (Required in C++98)
    $CLASS_NAME();                                    // Default constructor
    $CLASS_NAME(const $CLASS_NAME& other);            // Copy constructor
    $CLASS_NAME& operator=(const $CLASS_NAME& other); // Copy assignment operator
    ~$CLASS_NAME();                                   // Destructor

    // Parameterized constructor
    $CLASS_NAME(const std::string& name, int value);

    // Getters
    const std::string& getName() const;
    int getValue() const;

    // Setters
    void setName(const std::string& name);
    void setValue(int value);

    // Member functions
    void display() const;
    void reset();

    // Static members (example)
    static int getInstanceCount();
    static void printInfo();

private:
    static int _instanceCount;
};

EOF

if [ ! -z "$NAMESPACE" ]; then
    echo "} // namespace $NAMESPACE" >> "$HEADER_FILE"
    echo "" >> "$HEADER_FILE"
fi

echo "#endif // ${HEADER_GUARD}" >> "$HEADER_FILE"

# Generate source file
cat > "$SOURCE_FILE" << EOF
#include "$HEADER_FILE"

EOF

if [ ! -z "$NAMESPACE" ]; then
    echo "namespace $NAMESPACE {" >> "$SOURCE_FILE"
    echo "" >> "$SOURCE_FILE"
fi

cat >> "$SOURCE_FILE" << EOF
// Static member initialization
int ${CLASS_NAME}::_instanceCount = 0;

// Default constructor
${CLASS_NAME}::${CLASS_NAME}() : _name("Unknown"), _value(0) {
    _instanceCount++;
    std::cout << "$CLASS_NAME default constructor called" << std::endl;
}

// Copy constructor
${CLASS_NAME}::${CLASS_NAME}(const ${CLASS_NAME}& other) : _name(other._name), _value(other._value) {
    _instanceCount++;
    std::cout << "$CLASS_NAME copy constructor called" << std::endl;
}

// Copy assignment operator
${CLASS_NAME}& ${CLASS_NAME}::operator=(const ${CLASS_NAME}& other) {
    std::cout << "$CLASS_NAME copy assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
        _value = other._value;
    }
    return *this;
}

// Destructor
${CLASS_NAME}::~${CLASS_NAME}() {
    _instanceCount--;
    std::cout << "$CLASS_NAME destructor called" << std::endl;
}

// Parameterized constructor
${CLASS_NAME}::${CLASS_NAME}(const std::string& name, int value) : _name(name), _value(value) {
    _instanceCount++;
    std::cout << "$CLASS_NAME parameterized constructor called" << std::endl;
}

// Getters
const std::string& ${CLASS_NAME}::getName() const {
    return _name;
}

int ${CLASS_NAME}::getValue() const {
    return _value;
}

// Setters
void ${CLASS_NAME}::setName(const std::string& name) {
    _name = name;
}

void ${CLASS_NAME}::setValue(int value) {
    _value = value;
}

// Member functions
void ${CLASS_NAME}::display() const {
    std::cout << "Name: " << _name << ", Value: " << _value << std::endl;
}

void ${CLASS_NAME}::reset() {
    _name = "Unknown";
    _value = 0;
}

// Static member functions
int ${CLASS_NAME}::getInstanceCount() {
    return _instanceCount;
}

void ${CLASS_NAME}::printInfo() {
    std::cout << "Total $CLASS_NAME instances: " << _instanceCount << std::endl;
}

EOF

if [ ! -z "$NAMESPACE" ]; then
    echo "} // namespace $NAMESPACE" >> "$SOURCE_FILE"
fi

echo "Generated files:"
echo "  - $HEADER_FILE"
echo "  - $SOURCE_FILE"
echo ""
echo "Example usage:"
echo "  #include \"$HEADER_FILE\""
echo ""

if [ ! -z "$NAMESPACE" ]; then
    echo "  using namespace $NAMESPACE;"
fi

echo "  int main() {"
echo "      $CLASS_NAME obj1;                              // Default constructor"
echo "      $CLASS_NAME obj2(\"Test\", 42);               // Parameterized constructor"
echo "      $CLASS_NAME obj3(obj2);                       // Copy constructor"
echo "      obj1 = obj2;                                  // Copy assignment"
echo "      obj1.display();"
echo "      $CLASS_NAME::printInfo();"
echo "      return 0;"
echo "  }"