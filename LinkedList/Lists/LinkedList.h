#pragma once

#include <memory>

#include "List.h"

class LinkedList : public List {

private:

	/// <summary>
	/// Structure for a linked list node element
	/// </summary>
	struct Node
	{
		std::string value;
		std::shared_ptr<Node> nextP;
	};

	/// head of the list
	std::shared_ptr<Node> headP;

public:
	/// <summary>
	/// ctor
	/// </summary>
	LinkedList();

	/// <summary>
	/// dtor
	/// </summary>
	virtual ~LinkedList();

public:
	// @override
	virtual void addFront(const std::string& value);

	// @override
	virtual void addBack(const std::string& value);

	// @override
	virtual void add(int index, const std::string& value);

	// @override
	virtual void removeFront();

	// @override
	virtual void removeBack();

	// @override
	virtual void remove(int index);

	// @override
	virtual void clear();

	// @override
	virtual bool isEmpty() const;

	// @override
	virtual int size() const;

	// @override
	virtual const std::string get(int index) const;

	// @override
	virtual std::string print() const;
};
