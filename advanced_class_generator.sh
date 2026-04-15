#!/bin/bash

# Advanced C++ Class Generator Script
# Usage: ./advanced_class_generator.sh [options]

show_help() {
    echo "Advanced C++ Class Generator Script"
    echo ""
    echo "Usage: $0 [OPTION] ClassName"
    echo ""
    echo "Options:"
    echo "  -b, --base       Generate abstract base class"
    echo "  -d, --derived    Generate derived class (requires base class name)"
    echo "  -s, --singleton  Generate singleton pattern class"
    echo "  -t, --template   Generate template class"
    echo "  -i, --interface  Generate interface (pure virtual class)"
    echo "  -h, --help       Show this help message"
    echo ""
    echo "Examples:"
    echo "  $0 Student                    # Basic class"
    echo "  $0 -b Animal                  # Abstract base class"
    echo "  $0 -d Dog Animal              # Derived class (Dog inherits from Animal)"
    echo "  $0 -s Logger                  # Singleton pattern"
    echo "  $0 -t Container               # Template class"
    echo "  $0 -i IShape                  # Interface"
}

generate_basic_class() {
    CLASS_NAME=$1
    HEADER_FILE="${CLASS_NAME}.hpp"
    SOURCE_FILE="${CLASS_NAME}.cpp"
    HEADER_GUARD=$(echo "${CLASS_NAME}" | tr '[:lower:]' '[:upper:]')_HPP

    # Same as the basic generator - calling the original script
    ./generate_class.sh "$CLASS_NAME"
}

generate_base_class() {
    CLASS_NAME=$1
    HEADER_FILE="${CLASS_NAME}.hpp"
    SOURCE_FILE="${CLASS_NAME}.cpp"
    HEADER_GUARD=$(echo "${CLASS_NAME}" | tr '[:lower:]' '[:upper:]')_HPP

    cat > "$HEADER_FILE" << EOF
#ifndef ${HEADER_GUARD}
#define ${HEADER_GUARD}

#include <iostream>
#include <string>

class $CLASS_NAME {
protected:
    std::string _name;
    int _id;

public:
    // Orthodox Canonical Form
    $CLASS_NAME();
    $CLASS_NAME(const $CLASS_NAME& other);
    $CLASS_NAME& operator=(const $CLASS_NAME& other);
    virtual ~$CLASS_NAME();

    // Parameterized constructor
    $CLASS_NAME(const std::string& name, int id);

    // Pure virtual functions (must be implemented by derived classes)
    virtual void makeSound() const = 0;
    virtual void move() const = 0;

    // Virtual functions (can be overridden)
    virtual void display() const;
    virtual std::string getType() const;

    // Getters
    const std::string& getName() const;
    int getId() const;

    // Setters
    void setName(const std::string& name);
    void setId(int id);
};

#endif // ${HEADER_GUARD}
EOF

    cat > "$SOURCE_FILE" << EOF
#include "$HEADER_FILE"

// Default constructor
${CLASS_NAME}::${CLASS_NAME}() : _name("Unknown"), _id(0) {
    std::cout << "$CLASS_NAME default constructor called" << std::endl;
}

// Copy constructor
${CLASS_NAME}::${CLASS_NAME}(const ${CLASS_NAME}& other) : _name(other._name), _id(other._id) {
    std::cout << "$CLASS_NAME copy constructor called" << std::endl;
}

// Copy assignment operator
${CLASS_NAME}& ${CLASS_NAME}::operator=(const ${CLASS_NAME}& other) {
    std::cout << "$CLASS_NAME copy assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
        _id = other._id;
    }
    return *this;
}

// Virtual destructor
${CLASS_NAME}::~${CLASS_NAME}() {
    std::cout << "$CLASS_NAME destructor called" << std::endl;
}

// Parameterized constructor
${CLASS_NAME}::${CLASS_NAME}(const std::string& name, int id) : _name(name), _id(id) {
    std::cout << "$CLASS_NAME parameterized constructor called" << std::endl;
}

// Virtual functions
void ${CLASS_NAME}::display() const {
    std::cout << "Type: " << getType() << ", Name: " << _name << ", ID: " << _id << std::endl;
}

std::string ${CLASS_NAME}::getType() const {
    return "$CLASS_NAME";
}

// Getters
const std::string& ${CLASS_NAME}::getName() const {
    return _name;
}

int ${CLASS_NAME}::getId() const {
    return _id;
}

// Setters
void ${CLASS_NAME}::setName(const std::string& name) {
    _name = name;
}

void ${CLASS_NAME}::setId(int id) {
    _id = id;
}
EOF

    echo "Generated abstract base class:"
    echo "  - $HEADER_FILE"
    echo "  - $SOURCE_FILE"
}

generate_derived_class() {
    CLASS_NAME=$1
    BASE_CLASS=$2
    HEADER_FILE="${CLASS_NAME}.hpp"
    SOURCE_FILE="${CLASS_NAME}.cpp"
    HEADER_GUARD=$(echo "${CLASS_NAME}" | tr '[:lower:]' '[:upper:]')_HPP

    cat > "$HEADER_FILE" << EOF
#ifndef ${HEADER_GUARD}
#define ${HEADER_GUARD}

#include "${BASE_CLASS}.hpp"

class $CLASS_NAME : public $BASE_CLASS {
private:
    std::string _specialAttribute;

public:
    // Orthodox Canonical Form
    $CLASS_NAME();
    $CLASS_NAME(const $CLASS_NAME& other);
    $CLASS_NAME& operator=(const $CLASS_NAME& other);
    virtual ~$CLASS_NAME();

    // Parameterized constructor
    $CLASS_NAME(const std::string& name, int id, const std::string& specialAttribute);

    // Override pure virtual functions from base class
    virtual void makeSound() const override;
    virtual void move() const override;

    // Override virtual functions
    virtual void display() const override;
    virtual std::string getType() const override;

    // Specific to derived class
    const std::string& getSpecialAttribute() const;
    void setSpecialAttribute(const std::string& attribute);
};

#endif // ${HEADER_GUARD}
EOF

    cat > "$SOURCE_FILE" << EOF
#include "$HEADER_FILE"

// Default constructor
${CLASS_NAME}::${CLASS_NAME}() : ${BASE_CLASS}(), _specialAttribute("Default") {
    std::cout << "$CLASS_NAME default constructor called" << std::endl;
}

// Copy constructor
${CLASS_NAME}::${CLASS_NAME}(const ${CLASS_NAME}& other) : ${BASE_CLASS}(other), _specialAttribute(other._specialAttribute) {
    std::cout << "$CLASS_NAME copy constructor called" << std::endl;
}

// Copy assignment operator
${CLASS_NAME}& ${CLASS_NAME}::operator=(const ${CLASS_NAME}& other) {
    std::cout << "$CLASS_NAME copy assignment operator called" << std::endl;
    if (this != &other) {
        ${BASE_CLASS}::operator=(other);
        _specialAttribute = other._specialAttribute;
    }
    return *this;
}

// Destructor
${CLASS_NAME}::~${CLASS_NAME}() {
    std::cout << "$CLASS_NAME destructor called" << std::endl;
}

// Parameterized constructor
${CLASS_NAME}::${CLASS_NAME}(const std::string& name, int id, const std::string& specialAttribute) 
    : ${BASE_CLASS}(name, id), _specialAttribute(specialAttribute) {
    std::cout << "$CLASS_NAME parameterized constructor called" << std::endl;
}

// Override pure virtual functions
void ${CLASS_NAME}::makeSound() const {
    std::cout << getName() << " (" << getType() << ") makes a sound!" << std::endl;
}

void ${CLASS_NAME}::move() const {
    std::cout << getName() << " (" << getType() << ") is moving!" << std::endl;
}

// Override virtual functions
void ${CLASS_NAME}::display() const {
    ${BASE_CLASS}::display();
    std::cout << "Special Attribute: " << _specialAttribute << std::endl;
}

std::string ${CLASS_NAME}::getType() const {
    return "$CLASS_NAME";
}

// Specific methods
const std::string& ${CLASS_NAME}::getSpecialAttribute() const {
    return _specialAttribute;
}

void ${CLASS_NAME}::setSpecialAttribute(const std::string& attribute) {
    _specialAttribute = attribute;
}
EOF

    echo "Generated derived class:"
    echo "  - $HEADER_FILE (inherits from $BASE_CLASS)"
    echo "  - $SOURCE_FILE"
}

generate_singleton() {
    CLASS_NAME=$1
    HEADER_FILE="${CLASS_NAME}.hpp"
    SOURCE_FILE="${CLASS_NAME}.cpp"
    HEADER_GUARD=$(echo "${CLASS_NAME}" | tr '[:lower:]' '[:upper:]')_HPP

    cat > "$HEADER_FILE" << EOF
#ifndef ${HEADER_GUARD}
#define ${HEADER_GUARD}

#include <iostream>
#include <string>

class $CLASS_NAME {
private:
    static $CLASS_NAME* _instance;
    std::string _data;

    // Private constructors to prevent external instantiation
    $CLASS_NAME();
    $CLASS_NAME(const $CLASS_NAME& other);
    $CLASS_NAME& operator=(const $CLASS_NAME& other);

public:
    // Destructor
    ~$CLASS_NAME();

    // Static method to get the single instance
    static $CLASS_NAME* getInstance();
    static void destroyInstance();

    // Business logic methods
    void setData(const std::string& data);
    const std::string& getData() const;
    void processData();
    void display() const;
};

#endif // ${HEADER_GUARD}
EOF

    cat > "$SOURCE_FILE" << EOF
#include "$HEADER_FILE"

// Static member initialization
${CLASS_NAME}* ${CLASS_NAME}::_instance = nullptr;

// Private constructor
${CLASS_NAME}::${CLASS_NAME}() : _data("Default Data") {
    std::cout << "$CLASS_NAME instance created" << std::endl;
}

// Private copy constructor (unused)
${CLASS_NAME}::${CLASS_NAME}(const ${CLASS_NAME}& other) : _data(other._data) {
    // This should never be called in a proper singleton implementation
}

// Private assignment operator (unused)
${CLASS_NAME}& ${CLASS_NAME}::operator=(const ${CLASS_NAME}& other) {
    // This should never be called in a proper singleton implementation
    return *this;
}

// Destructor
${CLASS_NAME}::~${CLASS_NAME}() {
    std::cout << "$CLASS_NAME instance destroyed" << std::endl;
}

// Static method to get instance
${CLASS_NAME}* ${CLASS_NAME}::getInstance() {
    if (_instance == nullptr) {
        _instance = new $CLASS_NAME();
    }
    return _instance;
}

// Static method to destroy instance
void ${CLASS_NAME}::destroyInstance() {
    delete _instance;
    _instance = nullptr;
}

// Business methods
void ${CLASS_NAME}::setData(const std::string& data) {
    _data = data;
}

const std::string& ${CLASS_NAME}::getData() const {
    return _data;
}

void ${CLASS_NAME}::processData() {
    std::cout << "Processing data: " << _data << std::endl;
}

void ${CLASS_NAME}::display() const {
    std::cout << "$CLASS_NAME instance - Data: " << _data << std::endl;
}
EOF

    echo "Generated singleton class:"
    echo "  - $HEADER_FILE"
    echo "  - $SOURCE_FILE"
    echo ""
    echo "Usage example:"
    echo "  $CLASS_NAME* instance = $CLASS_NAME::getInstance();"
    echo "  instance->setData(\"My Data\");"
    echo "  instance->processData();"
    echo "  $CLASS_NAME::destroyInstance();"
}

generate_template() {
    CLASS_NAME=$1
    HEADER_FILE="${CLASS_NAME}.hpp"
    HEADER_GUARD=$(echo "${CLASS_NAME}" | tr '[:lower:]' '[:upper:]')_HPP

    cat > "$HEADER_FILE" << EOF
#ifndef ${HEADER_GUARD}
#define ${HEADER_GUARD}

#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class $CLASS_NAME {
private:
    std::vector<T> _data;
    size_t _capacity;

public:
    // Orthodox Canonical Form for template class
    $CLASS_NAME();
    $CLASS_NAME(size_t capacity);
    $CLASS_NAME(const $CLASS_NAME<T>& other);
    $CLASS_NAME<T>& operator=(const $CLASS_NAME<T>& other);
    ~$CLASS_NAME();

    // Container operations
    void push_back(const T& value);
    void pop_back();
    T& at(size_t index);
    const T& at(size_t index) const;
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    // Capacity operations
    size_t size() const;
    size_t capacity() const;
    bool empty() const;
    void clear();
    void resize(size_t newSize);

    // Display functions
    void display() const;
    void displayInfo() const;

    // Iterator support (basic)
    typename std::vector<T>::iterator begin();
    typename std::vector<T>::iterator end();
    typename std::vector<T>::const_iterator begin() const;
    typename std::vector<T>::const_iterator end() const;
};

// Template implementations (must be in header file)

template <typename T>
${CLASS_NAME}<T>::${CLASS_NAME}() : _capacity(10) {
    _data.reserve(_capacity);
    std::cout << "$CLASS_NAME<T> default constructor called" << std::endl;
}

template <typename T>
${CLASS_NAME}<T>::${CLASS_NAME}(size_t capacity) : _capacity(capacity) {
    _data.reserve(_capacity);
    std::cout << "$CLASS_NAME<T> parameterized constructor called" << std::endl;
}

template <typename T>
${CLASS_NAME}<T>::${CLASS_NAME}(const ${CLASS_NAME}<T>& other) : _data(other._data), _capacity(other._capacity) {
    std::cout << "$CLASS_NAME<T> copy constructor called" << std::endl;
}

template <typename T>
${CLASS_NAME}<T>& ${CLASS_NAME}<T>::operator=(const ${CLASS_NAME}<T>& other) {
    std::cout << "$CLASS_NAME<T> copy assignment operator called" << std::endl;
    if (this != &other) {
        _data = other._data;
        _capacity = other._capacity;
    }
    return *this;
}

template <typename T>
${CLASS_NAME}<T>::~${CLASS_NAME}() {
    std::cout << "$CLASS_NAME<T> destructor called" << std::endl;
}

template <typename T>
void ${CLASS_NAME}<T>::push_back(const T& value) {
    if (_data.size() >= _capacity) {
        throw std::out_of_range("Container is at maximum capacity");
    }
    _data.push_back(value);
}

template <typename T>
void ${CLASS_NAME}<T>::pop_back() {
    if (_data.empty()) {
        throw std::out_of_range("Container is empty");
    }
    _data.pop_back();
}

template <typename T>
T& ${CLASS_NAME}<T>::at(size_t index) {
    if (index >= _data.size()) {
        throw std::out_of_range("Index out of bounds");
    }
    return _data[index];
}

template <typename T>
const T& ${CLASS_NAME}<T>::at(size_t index) const {
    if (index >= _data.size()) {
        throw std::out_of_range("Index out of bounds");
    }
    return _data[index];
}

template <typename T>
T& ${CLASS_NAME}<T>::operator[](size_t index) {
    return _data[index];
}

template <typename T>
const T& ${CLASS_NAME}<T>::operator[](size_t index) const {
    return _data[index];
}

template <typename T>
size_t ${CLASS_NAME}<T>::size() const {
    return _data.size();
}

template <typename T>
size_t ${CLASS_NAME}<T>::capacity() const {
    return _capacity;
}

template <typename T>
bool ${CLASS_NAME}<T>::empty() const {
    return _data.empty();
}

template <typename T>
void ${CLASS_NAME}<T>::clear() {
    _data.clear();
}

template <typename T>
void ${CLASS_NAME}<T>::resize(size_t newSize) {
    _data.resize(newSize);
}

template <typename T>
void ${CLASS_NAME}<T>::display() const {
    std::cout << "$CLASS_NAME contents: ";
    for (const auto& item : _data) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void ${CLASS_NAME}<T>::displayInfo() const {
    std::cout << "Size: " << size() << ", Capacity: " << capacity() << std::endl;
}

// Iterator methods
template <typename T>
typename std::vector<T>::iterator ${CLASS_NAME}<T>::begin() {
    return _data.begin();
}

template <typename T>
typename std::vector<T>::iterator ${CLASS_NAME}<T>::end() {
    return _data.end();
}

template <typename T>
typename std::vector<T>::const_iterator ${CLASS_NAME}<T>::begin() const {
    return _data.begin();
}

template <typename T>
typename std::vector<T>::const_iterator ${CLASS_NAME}<T>::end() const {
    return _data.end();
}

#endif // ${HEADER_GUARD}
EOF

    echo "Generated template class:"
    echo "  - $HEADER_FILE"
    echo ""
    echo "Usage example:"
    echo "  $CLASS_NAME<int> intContainer;"
    echo "  $CLASS_NAME<std::string> stringContainer(20);"
    echo "  intContainer.push_back(42);"
    echo "  stringContainer.push_back(\"Hello\");"
}

generate_interface() {
    CLASS_NAME=$1
    HEADER_FILE="${CLASS_NAME}.hpp"
    HEADER_GUARD=$(echo "${CLASS_NAME}" | tr '[:lower:]' '[:upper:]')_HPP

    cat > "$HEADER_FILE" << EOF
#ifndef ${HEADER_GUARD}
#define ${HEADER_GUARD}

#include <iostream>
#include <string>

// Pure virtual interface class
class $CLASS_NAME {
public:
    // Virtual destructor for proper cleanup through interface pointer
    virtual ~$CLASS_NAME() {}

    // Pure virtual functions - must be implemented by concrete classes
    virtual void initialize() = 0;
    virtual void process() = 0;
    virtual void cleanup() = 0;
    virtual bool isValid() const = 0;
    virtual std::string getStatus() const = 0;
    virtual void display() const = 0;

    // Optional: provide some common functionality
    void printInterface() const {
        std::cout << "Interface: $CLASS_NAME" << std::endl;
    }
};

// Example concrete implementation
class ${CLASS_NAME}Impl : public $CLASS_NAME {
private:
    bool _initialized;
    bool _processed;
    std::string _status;

public:
    ${CLASS_NAME}Impl();
    virtual ~${CLASS_NAME}Impl();

    // Implement pure virtual functions
    virtual void initialize() override;
    virtual void process() override;
    virtual void cleanup() override;
    virtual bool isValid() const override;
    virtual std::string getStatus() const override;
    virtual void display() const override;
};

#endif // ${HEADER_GUARD}
EOF

    # Generate implementation file
    SOURCE_FILE="${CLASS_NAME}Impl.cpp"
    cat > "$SOURCE_FILE" << EOF
#include "$HEADER_FILE"

${CLASS_NAME}Impl::${CLASS_NAME}Impl() : _initialized(false), _processed(false), _status("Created") {
    std::cout << "${CLASS_NAME}Impl constructor called" << std::endl;
}

${CLASS_NAME}Impl::~${CLASS_NAME}Impl() {
    std::cout << "${CLASS_NAME}Impl destructor called" << std::endl;
}

void ${CLASS_NAME}Impl::initialize() {
    if (!_initialized) {
        _initialized = true;
        _status = "Initialized";
        std::cout << "${CLASS_NAME}Impl initialized" << std::endl;
    }
}

void ${CLASS_NAME}Impl::process() {
    if (_initialized && !_processed) {
        _processed = true;
        _status = "Processed";
        std::cout << "${CLASS_NAME}Impl processing completed" << std::endl;
    } else if (!_initialized) {
        std::cout << "Error: ${CLASS_NAME}Impl not initialized" << std::endl;
    }
}

void ${CLASS_NAME}Impl::cleanup() {
    _initialized = false;
    _processed = false;
    _status = "Cleaned";
    std::cout << "${CLASS_NAME}Impl cleaned up" << std::endl;
}

bool ${CLASS_NAME}Impl::isValid() const {
    return _initialized;
}

std::string ${CLASS_NAME}Impl::getStatus() const {
    return _status;
}

void ${CLASS_NAME}Impl::display() const {
    std::cout << "Implementation Status: " << _status 
              << ", Valid: " << (isValid() ? "Yes" : "No") 
              << ", Processed: " << (_processed ? "Yes" : "No") << std::endl;
}
EOF

    echo "Generated interface:"
    echo "  - $HEADER_FILE (interface definition)"
    echo "  - $SOURCE_FILE (example implementation)"
    echo ""
    echo "Usage example:"
    echo "  $CLASS_NAME* obj = new ${CLASS_NAME}Impl();"
    echo "  obj->initialize();"
    echo "  obj->process();"
    echo "  obj->display();"
    echo "  delete obj;"
}

# Parse command line arguments
case "$1" in
    -h|--help)
        show_help
        exit 0
        ;;
    -b|--base)
        if [ $# -lt 2 ]; then
            echo "Error: Base class name required"
            exit 1
        fi
        generate_base_class "$2"
        ;;
    -d|--derived)
        if [ $# -lt 3 ]; then
            echo "Error: Derived class name and base class name required"
            echo "Usage: $0 -d DerivedClassName BaseClassName"
            exit 1
        fi
        generate_derived_class "$2" "$3"
        ;;
    -s|--singleton)
        if [ $# -lt 2 ]; then
            echo "Error: Singleton class name required"
            exit 1
        fi
        generate_singleton "$2"
        ;;
    -t|--template)
        if [ $# -lt 2 ]; then
            echo "Error: Template class name required"
            exit 1
        fi
        generate_template "$2"
        ;;
    -i|--interface)
        if [ $# -lt 2 ]; then
            echo "Error: Interface class name required"
            exit 1
        fi
        generate_interface "$2"
        ;;
    -*)
        echo "Error: Unknown option $1"
        show_help
        exit 1
        ;;
    *)
        if [ $# -lt 1 ]; then
            echo "Error: Class name required"
            show_help
            exit 1
        fi
        generate_basic_class "$1"
        ;;
esac