// MoveContructor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Useless.h"

#include <iostream>

int main()
{
    // Explicit contructor
    std::cout << std::endl << "Useless one(10, 'x'); " << std::endl;
    Useless one(10, 'x');

    // Copy contructor
    std::cout << std::endl << "Useless two = one;" << std::endl;
    Useless two = one;

    // Explicit constructor
    std::cout << std::endl << "Useless three(20, 'o');" << std::endl;
    Useless three(20, 'o');

    // Move constructor
    std::cout << std::endl << "Useless four(one + three);" << std::endl;
    Useless four(one + three);

    // Print the objects
    one.print("one");
    two.print("two");
    three.print("three");
    four.print("four");

    std::cout << std::endl << "End of program" << std::endl;
}