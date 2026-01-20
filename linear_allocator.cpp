#include "linear_allocator.h"

LinearAllocator::LinearAllocator():
    _size{ 10 }, _busy{}, _buffer{}
{
    _buffer = (size_t*)(malloc(_size));
}

LinearAllocator::LinearAllocator(size_t size):
    _size{ size }, _busy{}, _buffer{}
{
    _buffer = (size_t*)(malloc(_size));
}

void* LinearAllocator::allocate(size_t size)
{
    _busy += size;
    if (_busy > _size)
        return nullptr;
    return (void*)(_busy);
}

void LinearAllocator::reset()
{
    _busy = 0;
}