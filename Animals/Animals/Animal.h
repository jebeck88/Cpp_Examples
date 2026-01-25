#pragma once

#include <string>

/***
 * Interface for an animal
 */
class Animal
{
public:
	/**
	 * Returns the animal's name
	 * @return name
	 */
	virtual const std::string& name() const = 0;

	/**
	 * Returns the animal's sound
	 * @return sound
	 */
	virtual const std::string& makeSound() const = 0;

	/**
	 * Rename the animal
	 */
	virtual void rename(const std::string& newName) = 0;

	/**
	* Animal says helo
	* @returns the animal's greeting
	*/
	virtual std::string sayHello() const = 0;


};
