#ifndef AR4J_MEMORY_ALLOCATOR_SRC
#define AR4J_MEMORY_ALLOCATOR_SRC

#include "core/memory/allocator.hpp"
#include "core/memory/memory.hpp"

using namespace ar4j::memory;

Allocator::Allocation* Allocator::createAllocation(size_t size, size_t alignment){

    size_t requiredSize = sizeof(Allocation) + alignof(Allocation) + size + alignment;  //required size for allocation object + data

    void* raw = new uint8_t[requiredSize];
    uint64_t addr = (uint64_t)raw;
    uint64_t offset = addr % alignof(Allocation);
    void* ptr = raw + offset;                          

    Allocation* alloc = new (ptr) Allocation();
    
    ptr = ptr + sizeof(Allocation);
    offset = ((uint64_t)ptr) % alignment;
    ptr = ptr + offset;

    alloc->raw = raw;
    alloc->alloc = this;
    alloc->size = size;
    alloc->alignment = alignment;
    alloc->data = ptr;

    return alloc;

}

Allocator::Segment Allocator::allocateSegment(size_t size, size_t alignment){

    Allocation* allocation = createAllocation(size,alignment);
    return allocation->getReference(0,size);

}

Memory Allocator::allocate(size_t size, size_t alignment){
    auto obj = new Allocator::MemoryObject(allocateSegment(size,alignment));
    return obj;
}

void Allocator::deallocate(Memory mem){

}

#endif //AR4J_MEMORY_ALLOCATOR_SRC