#include "pch.h"

#include "lists.h"
#include "ListTestHelper.h"

TEST(LinkedList, TestLinkedList)
{
	// Create a list
	LinkedList l;

	// Test the list
	ListTestHelper::testList(l);

}

TEST(DoublyLinkedList, TestDoublyLinkedList)
{
	// Create a doubly linked list;
	DoublyLinkedList l;

	// Test the list
	ListTestHelper::testList(l);
}