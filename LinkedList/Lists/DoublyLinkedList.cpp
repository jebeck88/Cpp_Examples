#include "pch.h"

#include <iostream>
#include <sstream>

#include "DoublyLinkedList.h"


DoublyLinkedList::DoublyLinkedList() :
	spHead(nullptr), spTail(nullptr)
{
}

DoublyLinkedList::~DoublyLinkedList() {}


void DoublyLinkedList::addFront(const std::string& value)
{
	// Create a new node for value
	const auto spNode = std::make_shared<Node>();
	spNode->value = value;

	// Put it at the head;
	spNode->spNext = spHead;
	if (spHead)
	{
		spHead->spPrev = spNode;
	}
	spHead = spNode;

	// If the tail was null, put it there too
	if (!spTail)
	{
		spTail = spNode;
	}
}

void DoublyLinkedList::removeFront()
{
	// If we are not empty, advance the head pointer
	if (spHead)
	{
		// Get a handle to the node being removed
		auto spNode = spHead;

		// Advance spHead beyond the node being removed;
		spHead = spHead->spNext;
		spHead->spPrev.reset();

		// Reset the deleted node's pointers
		spNode->spNext.reset();
		spNode->spPrev.reset();
	}
}

void DoublyLinkedList::addBack(const std::string& value)
{
	// Create a new node
	auto spNode = std::make_shared<Node>();
	spNode->value = value;

	// Put it in the tail
	spNode->spPrev = spTail;
	if (spTail)
	{
		spTail->spNext = spNode;
	}
	spTail = spNode;

	// If the head was null, put it there too
	if (!spHead)
	{
		spHead = spNode;
	}
}

void DoublyLinkedList::removeBack()
{
	// If we are not empty, advance the tail pointer
	if (spTail)
	{
		// Get a handle to the node being removed
		auto spNode = spTail;

		// Advance spTail beyond the node being removed;
		spTail = spTail->spPrev;
		spTail->spNext.reset();

		// Reset the deleted node's pointers
		spNode->spNext.reset();
		spNode->spPrev.reset();
	}
}

void DoublyLinkedList::add(int index, const std::string& value)
{
	if (index == 0)
	{
		addFront(value);
	}

	else if (index >= size())
	{
		addBack(value);
	}

	else
	{

		// Advance to the place where we need to insert the node
		// and get a handle to the predecessor (may be null)
		auto spPredecessor = spHead;
		int i = 0;
		while (spPredecessor && (i++ < index-1))
		{
			spPredecessor = spPredecessor->spNext;
		}

		// Now get a handle to the successor (may be null)
		auto spSuccessor = spPredecessor ? spPredecessor->spNext : nullptr;

		// Create the new node
		auto spNode = std::make_shared<Node>();
		spNode->value = value;
		spNode->spNext = spSuccessor;
		spNode->spPrev = spPredecessor;

		// Fix the predecssor's next pointer
		if (spPredecessor)
		{
			spPredecessor->spNext = spNode;
		}
		else
		{
			spHead = spNode;
		}

		// Fix the sucessors prev pointer
		if (spSuccessor)
		{
			spSuccessor->spPrev = spNode;
		}
		else
		{
			spTail = spNode;
		}
	}
}

void DoublyLinkedList::remove(int index)
{
	// If index is 0, removeFront
	if (index == 0)
	{
		removeFront();
	}

	// If index >= size-1, removeBack
	else if (index >= size() - 1)
	{
		removeBack();
	}

	// Otherwise, remove in the middle
	else
	{
		// Advance to the node to remove
		int i = 0;
		auto spNode = spHead;
		while (spNode && i++ < index)
		{
			spNode = spNode->spNext;
		}

		// Remove the node
		if (spNode)
		{
			// Get handles to the predecessor and successor
			auto spPredecessor = spNode->spPrev;
			auto spSuccesor = spNode->spNext;

			// Wire up the predecessor to the successor
			if (spPredecessor)
			{
				spPredecessor->spNext = spSuccesor;
			}

			if (spSuccesor)
			{
				spSuccesor->spPrev = spPredecessor;
			}

			// Clear out node's pointers
			spNode->spNext.reset();
			spNode->spPrev.reset();
		}
	}
}

const std::string DoublyLinkedList::get(int index) const
{
	if (index < 0 || index > size() - 1)
	{
		throw std::invalid_argument("Index out of range");
	}

	std::string result = "";
	int i = 0;
	auto spNode = spHead;
	
	// Advance spNode to the desired index
	while (spNode && i++ < index)
	{
		spNode = spNode->spNext;
	}

	if (!spNode)
	{
		std::ostringstream ss;
		ss << "Index " << index << " does not exist.";

		throw std::exception(ss.str().c_str());
	}

	return spNode->value;
}

void DoublyLinkedList::clear()
{
	spHead.reset();
	spTail.reset();
}

int DoublyLinkedList::size() const
{
	int size = 0;
	auto spNode = spHead;
	while (spNode)
	{
		++size;
		spNode = spNode->spNext;
	}
	return size;
}

bool DoublyLinkedList::isEmpty() const
{
	return size() == 0;
}

std::string DoublyLinkedList::print() const
{
	std::ostringstream oss;

	oss << "{";
	auto spNode = spHead;
	while (spNode)
	{
		oss << spNode->value;
		if (spNode->spNext)
		{
			oss << ", ";
		}
		spNode = spNode->spNext;
	}
	oss << "}";

	return oss.str();
}





