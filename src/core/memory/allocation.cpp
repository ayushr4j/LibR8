#ifndef AR4J_MEMORY_ALLOCATION_SRC
#define AR4J_MEMORY_ALLOCATION_SRC

#include "core/memory/allocation.hpp"
#include "core/memory/segment.hpp"

using namespace ar4j::memory;

Allocator::Segment Allocator::Allocation::getReference(size_t offset, size_t size){
    Segment segment;
    segment.segment = this;
    segment.offset = offset;
    segment.size = size;
    referenceCount++;
    return segment;
}

void Allocator::Allocation::releaseReference(){
    referenceCount--;
    if(referenceCount == 0 && alloc != nullptr){
        alloc->deallocate(this);
    }
}






#endif //AR4J_MEMORY_ALLOCATION_SRC