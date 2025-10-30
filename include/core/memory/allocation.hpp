#ifndef AR4J_MEMORY_ALLOCATOR_ALLOCATION
#define AR4J_MEMORY_ALLOCATOR_ALLOCATION

#include "./allocator.hpp"

namespace ar4j
{
    namespace memory{

        /// @brief this is reperesents raw memory allocation and it also counts number of references to it and automatically deallocates when reference count goes to 0. 
        class Allocator::Allocation{
            protected:
                /// @brief allocator that was used to allocate this Allocation
                Allocator* alloc = nullptr;   

                /// size is the required size of allocation (excluding any padding, header).
                /// alignment is the alignment requirement for this Allocation. this might be used when moving this memory to other location.
                size_t size, alignment = 1;

                /// raw holds the raw allocated space of this allocation. after which Memory Segment resides (may be padded to meet alignment requirement). data refers to address in this memory which fulfils given alignment requirment and is size bytes.
                void *data, *raw;   

                /// stores number of references created for this memory. help in automatic garbage collection
                std::atomic<size_t> referenceCount = 0;

                Allocation(){};


                Segment getReference(size_t offset, size_t size);
                void releaseReference();

                friend class Segment;
                friend class Allocator;


                virtual Segment operator&();
                virtual const Segment operator&() const;

        };



    }
} // namespace ar4j


#endif //AR4J_MEMORY_ALLOCATOR_ALLOCATION