#pragma once

#include "Animal.h"
#include "Dog.h"
#include "Pig.h"

/// <summary>
/// An animal breeder, implemented as a static class with no instances
/// </summary>
class AnimalBreeder
{
public: 
	// Breeds a dog
	static std::shared_ptr<Dog> breedDog(const std::string& name);

	// Breeds a pig
	static std::shared_ptr<Pig> breedPig(const std::string& name);

private:
	// no instances
	AnimalBreeder() = delete;
	~AnimalBreeder() = default;
};

