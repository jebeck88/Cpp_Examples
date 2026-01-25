// TestApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>

#include "Animal.h"
#include "AnimalBreeder.h"
#include "AnimalShelter.h"
#include "Dog.h"
#include "Pig.h"

int main(int argc, char* argv[])
{
    try
    {
        std::cout << "Hello World!\n";

        // Make a dog the old fashioned way
        const Dog myDog("Bingo");
        std::cout << myDog.sayHello() << std::endl;

        // Get a handle to the animal shelter
        auto& shelter = AnimalShelter::getInstance();

        // Donate some animals and dontate them to the shelter
        shelter.donate(AnimalBreeder::breedDog("Dukie"));
        shelter.donate(AnimalBreeder::breedDog("Princess"));
        shelter.donate(AnimalBreeder::breedDog("Ginger"));
        shelter.donate(AnimalBreeder::breedPig("Porky"));

        // Print the names of the animals in our shelter
        shelter.printNames();
        shelter.printNames<Dog>();
        shelter.printNames<Pig>();

        // donate a duplicate name.  This will throw an exception...
        //shelter.donate(std::make_shared<Dog>("Ginger"));


        // Borrow an animal from the shelter
        const auto& animal = shelter.borrow("Ginger");
        std::cout << animal.sayHello() << std::endl;

        // Adopt an animal from the shelter
        auto spAnimal = shelter.adopt("Ginger");
        std::cout << spAnimal->sayHello() << std::endl;

        // Print the names of the animals in our shelter
        shelter.printNames();
        shelter.printNames<Dog>();
        shelter.printNames<Pig>();

        // borrow an animal with a name that doesn't exist - throws an exception
        //shelter.borrow("Mickey");

        // borrow a dog with a name that corresponds with a pig -- throws an exception
        shelter.borrow<Dog>("Porky");


    }
    catch (std::exception& e)
    {
        std::cerr << e.what();
    }
}