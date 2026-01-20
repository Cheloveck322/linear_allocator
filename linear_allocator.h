#ifndef LINEAR_ALLOCATOR
#define LINEAR_ALLOCATOR

#include <cstddef>
#include <stdlib.h>

class LinearAllocator
{
public: 
    LinearAllocator();
    LinearAllocator(size_t size);
    void* allocate(size_t size);
    void reset();

private:
    size_t _size;
    size_t _busy;
    size_t* _buffer;
};

#endif