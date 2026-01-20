#ifndef LINEAR_ALLOCATOR
#define LINEAR_ALLOCATOR

#include <cstddef>
#include <stdlib.h>

class LinearAllocator
{
public: 
    LinearAllocator();
    LinearAllocator(std::size_t size);
    void* allocate(std::size_t size);
    void reset();

private:
    std::size_t _size;
    std::size_t _busy;
    std::size_t* _buffer;
};

#endif