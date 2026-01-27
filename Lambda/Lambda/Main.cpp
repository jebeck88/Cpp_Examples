// Lambda.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <algorithm>
#include <string>
#include <vector>

#include "Functor.h";
#include "StaticFunctions.h"

std::string print(const std::vector<int>& v)
{
    std::string result;
    result += "v= [";
    for (auto i = 0; i < v.size(); ++i)
    {
        result += std::to_string(v[i]);
        if (i < v.size() - 1)
        {
            result += ", ";
        }
    }
    result += "]";
    return result;
}

int main()
{
    // Create a vector with a 100 random integers
    std::vector<int> v(100);
    std::generate(v.begin(), v.end(), std::rand);
    std::cout << "v=" << print(v) << std::endl << std::endl;

    // Count the elements that are divisible by 3 and 13 via function pointers
    auto threeCount = std::count_if(v.cbegin(), v.cend(), StaticFunctions::isDivisibleByThree);
    auto thirteenCount = std::count_if(v.cbegin(), v.cend(), StaticFunctions::isDivisibleByThirteen);
    std::cout << "Static Functions: " << threeCount << " are divisible by 3. " << thirteenCount << " are divisible by thirteen" << std::endl;

    // Count the elements that are divisible by 3 and 13 via functor objects
    threeCount = std::count_if(v.cbegin(), v.cend(), Functor(3));
    thirteenCount = std::count_if(v.cbegin(), v.cend(), Functor(13));
    std::cout << "Functors: " << threeCount << " are divisible by 3. " << thirteenCount << " are divisible by thirteen" << std::endl;

    // Count the elements that are divisible by 3 and 13 via lambdas
    threeCount = std::count_if(v.cbegin(), v.cend(),
        [](int x) {return x % 3 == 0; });
    thirteenCount = std::count_if(v.cbegin(), v.cend(),
        [](int x) {return x % 13 == 0; });
    std::cout << "Lambdas: " << threeCount << " are divisible by 3. " << thirteenCount << " are divisible by thirteen" << std::endl;


}
