// TestApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Lists.h"

void testList(List& list)
{
    // Add a couple values to the front
    list.addFront("c");
    std::cout << "Size = " << list.size() << " isEmpty = " << list.isEmpty() << " list: " << list.print() << "\n";
    list.addFront("b");
    std::cout << "Size = " << list.size() << " isEmpty = " << list.isEmpty() << " list: " << list.print() << "\n";
    list.addFront("a");
    std::cout << "Size = " << list.size() << " isEmpty = " << list.isEmpty() << " list: " << list.print() << "\n";
    list.addFront("aa");
    std::cout << "Size = " << list.size() << " isEmpty = " << list.isEmpty() << " list: " << list.print() << "\n";

    // Add a couple values to the back
    list.addBack("x");
    std::cout << "Size = " << list.size() << " isEmpty = " << list.isEmpty() << " list: " << list.print() << "\n";
    list.addBack("y");
    std::cout << "Size = " << list.size() << " isEmpty = " << list.isEmpty() << " list: " << list.print() << "\n";
    list.addBack("z");
    std::cout << "Size = " << list.size() << " isEmpty = " << list.isEmpty() << " list: " << list.print() << "\n";
    list.addBack("zz");
    std::cout << "Size = " << list.size() << " isEmpty = " << list.isEmpty() << " list: " << list.print() << "\n";

    // Add a value to index 0
    list.add(0, "front");
    std::cout << "add(0, front), Size = " << list.size() << " isEmpty = " << list.isEmpty() << " list: " << list.print() << "\n";

    // add a value to index 1000
    list.add(1000, "back");
    std::cout << "size = " << list.size() << " isempty = " << list.isEmpty() << " list: " << list.print() << "\n";

    // add a value to index 2
    list.add(2, "index-2");
    std::cout << "size = " << list.size() << " isempty = " << list.isEmpty() << " list: " << list.print() << "\n";

    // remove front
    list.removeFront();
    std::cout << "size = " << list.size() << " isempty = " << list.isEmpty() << " list: " << list.print() << "\n";
    list.removeFront();
    std::cout << "size = " << list.size() << " isempty = " << list.isEmpty() << " list: " << list.print() << "\n";

    // Remove back
    list.removeBack();
    std::cout << "size = " << list.size() << " isempty = " << list.isEmpty() << " list: " << list.print() << "\n";
    list.removeBack();
    std::cout << "size = " << list.size() << " isempty = " << list.isEmpty() << " list: " << list.print() << "\n";

    // Remove index=1
    list.remove(1);
    std::cout << "size = " << list.size() << " isempty = " << list.isEmpty() << " list: " << list.print() << "\n";

    // Get 0
    std::cout << "list.get(0) = " << list.get(0) << "\n";

    // Get 5
    std::cout << "list.get(5) = " << list.get(5) << "\n";

    // Get 6
    try {
        std::cout << "list.get(6) = " << list.get(6) << "\n";
    }
    catch (std::exception& /*e*/)
    {
        std::cout << "Got an expected exception" << "\n";
    }

    // Clear the list
    list.clear();
    std::cout << "size = " << list.size() << " isempty = " << list.isEmpty() << " list: " << list.print() << "\n";
}

int main()
{
    try
    {
        std::cout << "Hello World!\n";

        // LinkedList test
        //linkedListTest();

        // DoublyLinkedList test
        //testDoublyLinkedList();

        DoublyLinkedList list;

        testList(list);
    }
    catch (const std::exception& e)
    {
        std::cout << "Got an exception, " << e.what() << "\n";;
    }

}

