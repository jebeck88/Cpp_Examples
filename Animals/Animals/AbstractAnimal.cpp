#include "AbstractAnimal.h"

#include <sstream>

AbstractAnimal::AbstractAnimal(const std::string& name) : 
	m_strName(name)
{
}

const std::string& AbstractAnimal::name() const
{
	return m_strName;
}

void AbstractAnimal::rename(const std::string& newName)
{
	m_strName = newName;
}

std::string AbstractAnimal::sayHello() const
{
	std::ostringstream oss;

	oss << "My name is \"" << name() << "\" and I say \"" << makeSound() << "\".";

	return oss.str();
}
