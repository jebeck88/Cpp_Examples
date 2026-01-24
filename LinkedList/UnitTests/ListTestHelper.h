#pragma once

#include <string>

#include "Lists.h"


class ListTestHelper
{
private:
	// No instances
	ListTestHelper() = default;
	virtual ~ListTestHelper() = default;

	// No copies
	ListTestHelper(const ListTestHelper&) = delete;
	ListTestHelper& operator=(const ListTestHelper&&) = delete;
	ListTestHelper(const ListTestHelper&&) = delete;
	ListTestHelper&& operator=(ListTestHelper&&) = delete;

public:
	// Assertions
	static void assertLength(const List& l, int length);
	static void assertEmpty(const List& l);
	static void assertElement(const List& l, int index, const std::string& expectedValue);


public:
	// tests
	static void testList(List& l);
	static void testAdd(List& l, int index, const std::string value);
	static void testAddFront(List& l, const std::string value);
	static void testAddBack(List& l, const std::string value);
	static void testRemove(List& l, int index);
	static void testRemoveFront(List& l);
	static void testRemoveBack(List& l);
	static void testGet(const List& l, int index, const std::string expectedVaalue = "");
	static void testClear(List& l);
};