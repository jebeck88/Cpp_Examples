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
	virtual void addFront(const std::string& value) override;

	// @override
	virtual void addBack(const std::string& value) override;

	// @override
	virtual void add(int index, const std::string& value) override;

	// @override
	virtual void removeFront() override;

	// @override
	virtual void removeBack() override;

	// @override
	virtual void remove(int index) override;

	// @override
	virtual void clear() override;

	// @override
	virtual bool isEmpty() const override;

	// @override
	virtual int size() const override;

	// @override
	virtual const std::string get(int index) const override;

	// @override
	virtual std::string print() const override;

private:
	// No Copies
	LinkedList(const LinkedList& other) = delete;
	LinkedList& operator=(const LinkedList& other) = delete;
	LinkedList(LinkedList&& other) = delete;
	LinkedList& operator=(LinkedList&& other) = delete;
};
