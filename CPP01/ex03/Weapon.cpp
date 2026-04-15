#include "Weapon.hpp"

Weapon::Weapon() {
    std::cout << "Weapon default constructor called" << std::endl;
    this->type = "";
}

Weapon::Weapon(std::string type) {
    std::cout << "Weapon parameterized constructor called" << std::endl;
    this->type = type;
}

Weapon::~Weapon() {
    std::cout << "Weapon destructor called" << std::endl;
}

void Weapon::setType(const std::string& type) {
    this->type = type;
}

const std::string &Weapon::getType()
{
    return (this->type);
}