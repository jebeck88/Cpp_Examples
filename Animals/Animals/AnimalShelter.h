#pragma once

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <sstream>
#include <vector>

#include "Animal.h"
#include "Dog.h"

/**
 * An animal shelter, implemented as a singleton
 *
 * Holds a collection of donated animals.  Our shelter is a little quirky though.  
 * Every animal in our shelter must have a unique name.  If you try to donate an 
 * animal with a duplicate name we won't accept it. 
 */
class AnimalShelter
{
public:
	/**
	 * Get a handle to the singleton instance 
	 */
	static AnimalShelter& getInstance();

public:
	/// <summary>
	///  Donates an animal
	/// </summary>
	/// <param name="spAnimal">the animal to donate</param>
	void donate(std::shared_ptr<Animal> animal);

	/// <summary>
	/// Looks for an animal with a given name
	/// </summary>
	/// <param name="name">the name</param>
	/// <returns>the animal</returns>
	/// <throws> an exception if an animal doesn't exist with that name
	const Animal& borrow(const std::string& name) const;

	/// <summary>
	/// Adopts an animal with a specific names and removes it from the shelter
	/// </summary>
	/// <param name="name">the name of the animal to adopt</param>
	/// <return> the animal
	std::shared_ptr<Animal> adopt(const std::string& name);

	/// <summary>
	/// Looks for an animal of a specific type with a given name
	/// </summary>
	/// <typeparam name="T">The type of animal to look for</typeparam>
	/// <param name="name">The animal name</param>
	/// <returns>The animal</returns>
	/// <throws> an exception if the animal doesn't exist
	template<typename T>
	const T& borrow(const std::string& name) const
	{
		try
		{
			return dynamic_cast<const T&>(borrow(name));
		}
		catch (const std::exception&)
		{
			std::ostringstream oss;
			oss << "No \"" << typeid(T).name() << "\" with name \"" << name << "\" lives at the shelter.";
			throw std::exception(oss.str().c_str());
		}
	}

	/// <summary>
	/// Get a vector with names of all animals at the shelter
	/// </summary>
	/// <returns>names</returns>
	const std::vector<std::string> names() const;

	/// <summary>
	/// Gets a vector with the names of a specific kind of animal at the shelter
	/// </summary>
	/// <typeparam name="T">The type of animal to look for</typeparam>
	/// <returns>names</returns>
	template<typename T>
	const std::vector<std::string> names() const
	{
		std::vector<std::string> result;
		for (const auto& pair : m_animalsMap)
		{
			auto strName = pair.first;
			auto spAnimal = pair.second;
			if (std::dynamic_pointer_cast<T>(spAnimal))
			{
				result.push_back(strName);
			}
		}
		return result;
	}

	/// <summary>
	/// Print the names of all animals in our shelter
	/// </summary>
	void printNames() const;

	template<typename T>
	void printNames() const
	{
		auto allNames = names<T>();
		std::cout << "\"" << typeid(T).name() << "\" that live at the shelter : [";
		for (int i = 0; i < allNames.size(); ++i)
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


private:
	AnimalShelter() = default;

	// No copies
	AnimalShelter(const AnimalShelter&) = delete;
	AnimalShelter& operator=(const AnimalShelter&) = delete;

private:
	// Animals in my shelter
	std::map <std::string, std::shared_ptr<Animal>> m_animalsMap;

};

