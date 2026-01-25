#include <memory>

#include "AnimalBreeder.h"

std::shared_ptr<Dog> AnimalBreeder::breedDog(const std::string& name)
{
	return std::make_shared<Dog>(name);
}

std::shared_ptr<Pig> AnimalBreeder::breedPig(const std::string& name)
{
	return std::make_shared<Pig>(name);
}
