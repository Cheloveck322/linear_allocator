#include "linear_allocator.h"

LinearAllocator::LinearAllocator():
    _size{ 10 }, _busy{}, _buffer{}
{
    _buffer = reinterpret_cast<std::size_t*>(malloc(_size * sizeof(std::size_t)));
}

LinearAllocator::LinearAllocator(std::size_t size):
    _size{ size }, _busy{}, _buffer{}
{
    _buffer = reinterpret_cast<std::size_t*>(malloc(_size * sizeof(std::size_t)));
}

void* LinearAllocator::allocate(std::size_t size)
{
    _busy += size;
    if (_busy > _size)
        return nullptr;
    return reinterpret_cast<void*>(_busy);
}

void LinearAllocator::reset()
{
    _busy = 0;
}