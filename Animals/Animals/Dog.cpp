#include "Dog.h"

std::string Dog::s_strSound("Woof, woof!");

Dog::Dog(const std::string& name) : AbstractAnimal(name)
{
}

const std::string& Dog::makeSound() const
{
    return s_strSound;
}
