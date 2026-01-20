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

    return 0;
}