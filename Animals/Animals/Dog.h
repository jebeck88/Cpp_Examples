#pragma once

#include "AbstractAnimal.h"

/***
 * Interface for an animal
 */
class Dog : public AbstractAnimal
{
public:
	/** ctor */
	Dog(const std::string& name);

	/** dtor */
	virtual ~Dog() = default;

public:
	/** @override */
	virtual const std::string& makeSound() const override;

private:
	static std::string s_strSound;


};