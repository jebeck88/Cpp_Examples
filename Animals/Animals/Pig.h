#pragma once
#include "AbstractAnimal.h"

/// <summary>
/// Represents a pig
/// </summary>
class Pig : public AbstractAnimal
{
public: 
	// Ctor
	Pig(const std::string name);

	// Dtor
	virtual ~Pig() = default;

public:
	// @Override
	virtual const std::string& makeSound() const override;

private:
	static const std::string s_strNoise;


};

