#ifndef AR4J_MEMORY
#define AR4J_MEMORY

#include <stddef.h>
#include <core/type/reference.hpp>
#include <atomic>
#include <vector>

#include "./memory_object.hpp"

namespace ar4j
{

    
    namespace memory
    {
        
        /// @brief It acts as a pointer to memory. It supports advanced memory operations such as extending, shrinking memory. splitting memory, inserting memory in between. this works by keeping list connected segments internally. and it automatically defragments them also.
        class Memory{
            protected:
                Allocator::MemoryObject* memory;
                Memory(Allocator::MemoryObject* obj);

                friend class Allocator;
            public:

                
            
        };
        



    } // namespace memory
    
} // namespace ar4j


#endif //AR4J_MEMORY