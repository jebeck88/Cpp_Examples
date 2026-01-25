#include "AnimalShelter.h"

#include <exception>
#include <iostream>
#include <sstream>
#include <memory>

AnimalShelter& AnimalShelter::getInstance()
{
    // My singleton instance created in a threadsafe way
    static AnimalShelter s_instance;

    // Return the single instance
    return s_instance;
}

void AnimalShelter::donate(std::shared_ptr<Animal> animal)
{
    if (m_animalsMap.contains(animal->name()))
    {
        std::ostringstream oss;
        oss << "Animal with name \"" << animal->name() << "\" already lives at shelter.";
        throw std::exception(oss.str().c_str());
    }

    m_animalsMap[animal->name()] = animal;
}

const Animal& AnimalShelter::borrow(const std::string& name) const
{
    if (!m_animalsMap.contains(name))
    {
        std::ostringstream oss;
        oss << "No animal with name \"" << name << "\" lives at the shelter.";
        throw std::exception(oss.str().c_str());
    }
    return *m_animalsMap.at(name);
}

std::shared_ptr<Animal> AnimalShelter::adopt(const std::string& name)
{
    if (!m_animalsMap.contains(name))
    {
        std::ostringstream oss;
        oss << "No animal with name \"" << name << "\" lives at the shelter";
        throw std::exception(oss.str().c_str());
    }
    auto animal = m_animalsMap[name];
    m_animalsMap.erase(name);
    return animal;
}

const std::vector<std::string> AnimalShelter::names() const
{
    std::vector<std::string> result;
    for (const auto& pair : m_animalsMap)
    {
        result.push_back(pair.first);
    }
    return result;
}

void AnimalShelter::printNames() const
{
    auto allNames = names();
    std::cout << "Animals that live at the shelter: [";
    for( int i = 0; i < allNames.size(); ++i)
    {
        auto name = allNames[i];
        std::cout << "\"" << name << "\"";
        if (i < allNames.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}


