#ifndef LINEAR_ALLOCATOR
#define LINEAR_ALLOCATOR

#include <cstddef>
#include <stdlib.h>

class LinearAllocator
{
public:
    LinearAllocator();
    LinearAllocator(size_t size);
    ~LinearAllocator();
    
    LinearAllocator(const LinearAllocator&) = delete;
    LinearAllocator& operator=(const LinearAllocator&) = delete;

    void* allocate(size_t size);
    void reset();

private:
    char* _current_pos;
    char* _buffer;
    size_t _total_size;
};

#endif