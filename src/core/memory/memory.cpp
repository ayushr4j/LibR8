#ifndef AR4J_MEMORY_SRC
#define AR4J_MEMORY_SRC

#include "core/memory/memory.hpp"


ar4j::memory::Memory::~Memory(){
    if(alloc != nullptr){
        alloc->releaseReference(*this);
        alloc = nullptr;
    }

}

#endif //AR4J_MEMORY_SRC
