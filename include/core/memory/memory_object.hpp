#ifndef AR4J_MEMORY_OBJECT
#define AR4J_MEMORY_OBJECT

#include <stddef.h>
#include <core/type/reference.hpp>
#include <atomic>
#include <vector>

#include "./segment.hpp"

namespace ar4j
{
    namespace memory
    {
        
        class Allocator::MemoryObject{
        protected:
            
            Allocator* allocator;

            std::atomic<size_t> referenceCount = 0;
            //store list of segments associated with this memory. each segment acts as continuation of previous segment.
            std::vector<Allocator::Segment> *segments = new std::vector<Allocator::Segment>();

        public:
            
            void defragment();
            void extend();
            void insert();
            void split(size_t offsetof);

            void remove();

            MemoryObject();
            MemoryObject(Allocator::Segment&& segment);


            


            

        };

    } // namespace memory
    
} // namespace ar4j


#endif //AR4J_MEMORY_OBJECT