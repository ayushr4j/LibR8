#ifndef AR4J_MEMORY_ALLOCATOR
#define AR4J_MEMORY_ALLOCATOR

#include <atomic>


namespace ar4j
{
    
    namespace memory
    {
        
        class Memory;


        /**
         * @brief Allocates Contiguous Memory Segments and returns a Reference to it.
         * 
         */
        class Allocator{
        protected:

            class Segment;

            /**
            * @brief Holds actual allocated raw pointer and total size of allocation. Must not be used directly.
            * 
            */
            class Allocation;

            class MemoryObject;

            friend class Segment;
            friend class Allocation;
            friend class MemoryObject;
            friend class Memory;

            virtual Allocation* createAllocation(size_t size, size_t alignment = 1);
            virtual Segment allocateSegment(size_t size, size_t alignment = 1); //deallocates automatically when all segmentReferences are destroyed
            virtual void deallocate(Segment segment);
            virtual void deallocate(Allocation* allocation);
            

        public:
            
            virtual Memory allocate(size_t size, size_t alignment = 1);
            virtual void deallocate(Memory mem);

        };

        

    } // namespace memory
    
} // namespace name


#endif //AR4J_MEMORY_ALLOCATOR