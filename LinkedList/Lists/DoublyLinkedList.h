#pragma once

#include <memory>
#include <string>

#include "List.h"

class DoublyLinkedList : public List {

private:

	/// <summary>
	/// Structure for a linked list node element
	/// </summary>
	struct Node
	{
		std::string value;
		std::shared_ptr<Node> spNext;
		std::shared_ptr<Node> spPrev;
	};

	/// head of the list
	std::shared_ptr<Node> spHead;

	///  tail of the list
	std::shared_ptr<Node> spTail;

public:
	/// <summary>
	/// ctor
	/// </summary>
	DoublyLinkedList();

	/// <summary>
	/// dtor
	/// </summary>
	virtual ~DoublyLinkedList();

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
	DoublyLinkedList(const DoublyLinkedList& other) = delete;
	DoublyLinkedList& operator=(const DoublyLinkedList& other) = delete;
	DoublyLinkedList(DoublyLinkedList&& other) = delete;
	DoublyLinkedList& operator=(DoublyLinkedList&& other) = delete;
};
