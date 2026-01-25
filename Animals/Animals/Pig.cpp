#include "Pig.h"

const std::string Pig::s_strNoise("Oink, Oink");

Pig::Pig(const std::string name) : AbstractAnimal(name)
{
}

const std::string& Pig::makeSound() const
{
	return s_strNoise;
}
