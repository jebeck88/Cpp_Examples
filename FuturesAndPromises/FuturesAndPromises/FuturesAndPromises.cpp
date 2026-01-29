// FuturesAndPromises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <future>
#include <memory>
#include <thread>
#include <vector>


// local function that adds the next fibonacci number to an existing sequence passed by reference
void addNextFibonacciNumber(std::vector<unsigned long>& sequence)
{
    const auto size = sequence.size();
    if( size == 0 || size == 1)
    {
        sequence.push_back(static_cast<unsigned long>(size));

    }
    else
    {
        sequence.push_back(sequence[size - 1] + sequence[size - 2]);
    }
}

// Task function that runs in a helper thread.
// It computes a fibonacci sequence of the requested length and returns it via a promise
void fibonacciTask(std::promise <std::vector<unsigned long>>&& promise, unsigned long l)
{
    // calculate a fibonaccie sequence of length l
    std::vector<unsigned long> result;
    for (unsigned long i = 0; i < l; ++i)
    {
        addNextFibonacciNumber(result);
    }
    
    // Set the value in the promise
    promise.set_value(std::move(result));
}

int main()
{
    // Create a promise
    std::promise<std::vector<unsigned long>> promise;

    // Extract a future from it
    std::future<std::vector<unsigned long>> future = promise.get_future();

    // Create a helper task to compute the fibonacci sequence
    std::thread myThread(fibonacciTask, std::move(promise), 50ul);

    // Wait for the result
    auto result = future.get();

    // Join the thread
    myThread.join();

    // Print the resulting sequence
    std::cout << "Result = [";
    for (auto i = 0; i < result.size(); ++i)
    {
        std::cout << result[i];
        if (i < result.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}
