#include "linear_allocator.h"
#include <iostream>
#include <chrono>

int main()
{
    LinearAllocator myAlloc{ 100000000 };
    auto beginMy = std::chrono::steady_clock::now();

    int* p = new int;
    for (int i = 0; i < 1000000; ++i)
    {
        int* d = (int*)myAlloc.allocate(sizeof(int));
        *d = 5;
        *p = *d;
    }
    auto endMy = std::chrono::steady_clock::now();

    std::cout << *p << std::endl;

    delete p;

    myAlloc.reset();
    volatile char* sink;
    auto beginSys = std::chrono::steady_clock::now();

    for (int i = 0; i < 1000000; ++i)
    {
        int* p = new int;
        *((int*)p) = 5; 
        sink = (char*)p; 

        delete p;
    }

    auto endSys = std::chrono::steady_clock::now();

    std::cout << sink << std::endl;

    auto durationMy = std::chrono::duration_cast<std::chrono::nanoseconds>(endMy - beginMy).count();
    auto durationSys = std::chrono::duration_cast<std::chrono::nanoseconds>(endSys - beginSys).count();

    std::cout << durationMy << ' ' << durationSys << std::endl;

    int* matrix = new int[10000 * 10000];

    int sum = 0;

    auto beginMatrix1 = std::chrono::steady_clock::now();
    for (int i = 0; i < 10000; ++i)
    {
        for (int j = 0; j < 10000; ++j)
        {
            sum += matrix[i];
        }
    }
    auto endMatrix1 = std::chrono::steady_clock::now();

    auto beginMatrix2 = std::chrono::steady_clock::now();
    for (int i = 0; i < 10000; ++i)
    {
        for (int j = 0; j < 10000; ++j)
        {
            sum += matrix[j];
        }
    }
    auto endMatrix2 = std::chrono::steady_clock::now();

    auto durationMatrix1 = std::chrono::duration_cast<std::chrono::nanoseconds>(endMatrix1 - beginMatrix1).count();
    auto durationMatrix2 = std::chrono::duration_cast<std::chrono::nanoseconds>(endMatrix2 - beginMatrix2).count();

    std::cout << durationMatrix1 << ' ' << durationMatrix2 << std::endl;

    delete[] matrix;

    return 0;
}