#include "linear_allocator.h"
#include <iostream>
#include <chrono>

int main()
{
    auto beginMy = std::chrono::steady_clock::now();

    LinearAllocator myAlloc{ 1000000 };
    
    auto endMy = std::chrono::steady_clock::now();

    auto beginSys = std::chrono::steady_clock::now();

    int* systemAlloc = new int(1000000);

    auto endSys = std::chrono::steady_clock::now();

    auto durationMy = std::chrono::duration_cast<std::chrono::nanoseconds>(endMy - beginMy).count();
    auto durationSys = std::chrono::duration_cast<std::chrono::nanoseconds>(endSys - beginSys).count();

    std::cout << durationMy << ' ' << durationSys << std::endl;

    auto matrix = new int[10000][10000];
    int sum = 0;

    auto beginMatrix1 = std::chrono::steady_clock::now();
    for (int i = 0; i < 10000; ++i)
    {
        for (int j = 0; j < 10000; ++j)
        {
            sum += matrix[i][j];
        }
    }
    auto endMatrix1 = std::chrono::steady_clock::now();

    auto beginMatrix2 = std::chrono::steady_clock::now();
    for (int i = 0; i < 10000; ++i)
    {
        for (int j = 0; j < 10000; ++j)
        {
            sum += matrix[j][i];
        }
    }
    auto endMatrix2 = std::chrono::steady_clock::now();

    auto durationMatrix1 = std::chrono::duration_cast<std::chrono::nanoseconds>(endMatrix1 - beginMatrix1).count();
    auto durationMatrix2 = std::chrono::duration_cast<std::chrono::nanoseconds>(endMatrix2 - beginMatrix2).count();

    std::cout << durationMatrix1 << ' ' << durationMatrix2 << std::endl;
    
    return 0;
}