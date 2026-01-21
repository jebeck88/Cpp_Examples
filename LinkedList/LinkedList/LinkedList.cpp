#include <iostream>
#include "LinkedList.h"
#include <sstream>

LinkedList::LinkedList() : List(),
    headP(nullptr)
{
}

LinkedList::~LinkedList()
{
    headP.reset();
}

void LinkedList::addFront(const std::string& value)
{
    // Create a new node
    auto nodeP = std::make_shared<Node>();
    nodeP->value = value;

    // Put new node at the front of the list
    nodeP->nextP = headP;
    headP = nodeP;
}

void LinkedList::addBack(const std::string& value)
{
    // Create a new node
    auto newNodeP = std::make_shared<Node>();
    newNodeP->value = value;

    // Is the list empty?
    if (isEmpty())
    {
        headP = newNodeP;
    }
    else
    {
        // Advance nodeP to the last node in the list
        auto nodeP = headP;
        while (nodeP->nextP)
        {
            nodeP = nodeP->nextP;
        }

        // Add new node here
        nodeP->nextP = newNodeP; 
    }
}

void LinkedList::add(int index, const std::string& value)
{
    // Adding to the front?
    if (index == 0)
    {
        addFront(value);
    }

    // Adding to the back?
    else if (index > size() - 1)
    {
        addBack(value);
    }

    // Adding to the middle of a non-empty list
    else
    {
        // Create a new node
        auto newNodeP = std::make_shared<Node>();
        newNodeP->value = value;

        // Advance to index-1
        int pos = 0;
        auto nodeP = headP;
        while (pos < index - 1)
        {
            nodeP = nodeP->nextP;
            ++pos;
        }

        // Insert the new node
        newNodeP->nextP = nodeP->nextP;
        nodeP->nextP = newNodeP;
    }
}

void LinkedList::removeFront()
{
    // Empty
    if (isEmpty())
    {
        return;
    }
    headP = headP->nextP;
}

void LinkedList::removeBack()
{
    // Empty
    if (isEmpty())
    {
        return;
    }

    // Only one element
    else if (size() == 1)
    {
        headP.reset();
    }

    // Advance to second to last node
    else
    {
        auto nodeP = headP;
        while (nodeP->nextP->nextP)
        {
            nodeP = nodeP->nextP;
        }
        nodeP->nextP.reset();
    }
}

void LinkedList::remove(int index)
{
    // check argument
    if (index > size() - 1)
    {
        return;
    }

    // Remove front
    if (index == 0)
    {
        removeFront();
    }
    // Remove back
    else if (index == size() - 1)
    {
        removeBack();
    }
    // Remove middle
    else
    {
        // Advance to index-1
        int pos = 0;
        auto nodeP = headP;
        while (pos < index - 1)
        {
            nodeP = nodeP->nextP;
            ++pos;
        }

        // Remove the node at index
        nodeP->nextP = nodeP->nextP->nextP;
    }
}

int LinkedList::size() const
{
    int result = 0;
    auto nodeP = this->headP;
    while (nodeP)
    {
        ++result;
        nodeP = nodeP->nextP;
    }
    return result;
}

const std::string LinkedList::get(int index) const
{
    if (index < 0 || index > size() - 1)
    {
        throw std::invalid_argument("Index out of range");
    }

    int pos = 0;
    auto nodeP = headP;
    while (pos < index)
    {
        ++pos;
        nodeP = nodeP->nextP;
    }
    return nodeP->value;

}

std::string LinkedList::print() const
{
    std::ostringstream oss;
    oss << "(";
    auto nodeP = headP;
    while (nodeP)
    {
        oss << nodeP->value;
        nodeP = nodeP->nextP;
        if (nodeP)
        {
            oss << ", ";
        }
    }
    oss << ")";
    return oss.str();
}

bool LinkedList::isEmpty() const
{
    return ( size() == 0 );
}

void LinkedList::clear()
{
    headP.reset();
}
