#include "linear_allocator.h"
#include <stdexcept>

LinearAllocator::LinearAllocator():
    _total_size{ 10 }, _current_pos{}, _buffer{}
{
    _buffer = static_cast<char*>(malloc(_total_size));
    if (!_buffer) throw std::runtime_error("Bad allocation.");
    _current_pos = _buffer;
}

LinearAllocator::LinearAllocator(size_t size):
    _total_size{ size }, _current_pos{}, _buffer{}
{
    _buffer = static_cast<char*>(malloc(_total_size));
    if (!_buffer) throw std::runtime_error("Bad allocation.");
    _current_pos = _buffer;
}

void* LinearAllocator::allocate(size_t size)
{
    if (_current_pos + size > _buffer + _total_size)
        return nullptr;
    
    void* temp = _current_pos;
    _current_pos += size;

    return temp;
}

void LinearAllocator::reset()
{
    _current_pos = _buffer;
}

LinearAllocator::~LinearAllocator()
{
    free(_buffer);
}