// Iterators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cctype>
#include <iostream>

#include <string>
#include <vector>

// Binary search using iterators
template<typename T>
auto find(const std::vector<T>& v, T e)
{
    auto result = v.end();
    auto begin = v.begin();
    auto end = v.end();
    while (begin != end)
    {
        // Calculate the mid -- did we find it?
        auto mid = begin + ((end - begin) / 2);
        if (*mid == e)
        {
            result = mid;
            break;
        }

        if (*mid > e)
        {
            end = mid;
        }
        else
        {
            begin = mid + 1;
        }
    }
    return result;
}

// Returns true if collection contains e, using binary search
template<typename T>
bool contains(std::vector<T> v, T e)
{
    return (find(v, e) != v.end());
}

void toUpperCase(std::string&);
void toLowerCase(std::string&);

int main()
{
    std::string s = "Hello World!";

    toUpperCase(s);
    toLowerCase(s);

    std::cout << s << std::endl;

    const std::vector<int> vals = { 1, 3, 12, 33, 65, 90 };

    auto it = find(vals, 3);
    std::cout << "*find(vals, 3) = " << *it << std::endl;

    std::cout << "contains(val, 12)=" << contains(vals, 12) << std::endl;
    std::cout << "contains(val, 99)=" << contains(vals, 99) << std::endl;
    std::cout << "contains(val, 0)=" << contains(vals, 0) << std::endl;
    std::cout << "contains(val, 1)=" << contains(vals, 1) << std::endl;
    std::cout << "contains(val, 90)=" << contains(vals, 90) << std::endl;

}

// Iterate using a range-for
void toUpperCase(std::string& s)
{
    for (auto& c : s)
    {
        c = std::toupper(c);
    }

    std::cout << s << std::endl;
}

// Iterate using an iterator
void toLowerCase(std::string& s)
{
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        *it = std::tolower(*it);
    }
    std::cout << s << std::endl;
}



