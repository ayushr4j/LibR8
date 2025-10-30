#ifndef AR4J_MEMORY
#define AR4J_MEMORY

#include <stddef.h>
#include <core/type/reference.hpp>

#include "./allocation.hpp"

namespace ar4j
{

    namespace memory {
        /// @brief It acts as a pointer to memory. It supports advanced memory operations such as extending, shrinking memory. splitting memory, inserting memory in between. this works by keeping list connected segments internally. and it automatically defragments them also.
        class Memory{
            protected:
                memory::Allocator::Allocation* alloc;
                size_t offset = 0, size = 0;

                Memory();
                ~Memory();

                friend class Allocator;
            public:
            
                /// @brief return byte at given index in memory
                /// @param i index starts at 0. supports negative indexing. -1 = size - 1, -2 size - 2, so on
                /// @return 
                uint8_t operator[](int64_t i);
                
                Memory operator[](int64_t offset, uint64_t size);
            
        };
    }

    
    
   
    
} // namespace ar4j


#endif //AR4J_MEMORY