#pragma once
class StaticFunctions
{
public:
    static bool isDivisibleByThree(int x)
    {
        return (x % 3 == 0);
    }

    static bool isDivisibleByThirteen(int x)
    {
        return (x % 13 == 0);
    }

private:
    StaticFunctions() = delete;
};

