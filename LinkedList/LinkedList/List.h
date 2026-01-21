
#pragma once

#include <string>

class List
{
public:
	/// <summary>
	/// ctor
	/// </summary>
	List();

	/// <summary>
	/// dtor
	/// </summary>
	virtual ~List();

public:
	/// <summary>
	/// Adds an element to the front of the list
	/// </summary>
	/// <param name="value">element to add</param>
	virtual void addFront(const std::string& value) = 0;

	/// <summary>
	/// Adds an element to the back of the list
	/// </summary>
	/// <param name="value"></param>
	virtual void addBack(const std::string & value) = 0;

	/// <summary>
	/// Adds an element at index i, or at the end if the list has fewer than i elements
	/// </summary>
	/// <param name="index">the index position</param>
	/// <param name="value">the element to add</param>
	virtual void add(int index, const std::string & value) = 0;

	/// <summary>
	/// Removes the first element
	/// </summary>
	virtual void removeFront() = 0;

	/// <summary>
	///  Removes the last element
	/// </summary>
	virtual void removeBack() = 0;

	/// <summary>
	/// Removes an element an element
	/// </summary>
	/// <param name="index"></param>
	virtual void remove(int index) = 0;

	/// <summary>
	/// Clears the list
	/// </summary>
	virtual void clear() = 0;

	/// <summary>
	/// Returns true if the list is empty
	/// </summary>
	/// <returns>true if empty</returns>
	virtual bool isEmpty() const = 0;

	/// <summary>
	/// Returns the list size
	/// </summary>
	/// <returns></returns>
	virtual int size() const = 0;

	/// <summary>
	/// Gets an element 
	/// </summary>
	/// <param name="index"></param>
	/// <returns></returns>
	virtual const std::string get(int index) const = 0;

	/// <summary>
	/// Prints the list
	/// </summary>
	virtual std::string print() const = 0;
};