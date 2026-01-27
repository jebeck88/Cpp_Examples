#pragma once

#include <string>

#include "Animal.h"

/***
 * Abstract base class for an animal
 */
class AbstractAnimal : public Animal
{
public:
	/** ctor */
	AbstractAnimal(const std::string& name);

	/** dtor */
	virtual ~AbstractAnimal() = default;

public:
	/** @override */
	virtual const std::string& name() const override;

	/** @override */
	virtual void rename(const std::string& newName) override;

	/** @override */
	virtual std::string sayHello() const override final;

private:
	std::string m_strName;

};