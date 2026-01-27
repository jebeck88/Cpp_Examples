#pragma once
#ifndef USELESS_H
#define USELESS_H

#include <iostream>

class Useless
{
public:
	// Ctors
	Useless();
	explicit Useless(int k);
	Useless(int k, char c);
	
	// Copy ctor
	Useless(const Useless& other);

	// Move ctor
	Useless(Useless&& other) noexcept;

	// dtor
	~Useless();

	// Add operator (that returns an rValue)
	Useless operator+(const Useless& other) const;

public:
	void print(std::string varName) const;
	void static printCall(std::string methodName);


private:
	// Number of elements
	int m_nElems;

	// Data
	char* m_data;

	// Number of objects
	static int s_nObjects;

};

#endif

