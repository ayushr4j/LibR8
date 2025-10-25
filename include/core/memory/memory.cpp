#ifndef AR4J_MEMORY
#define AR4J_MEMORY

#include <stddef.h>
#include <type/reference.hpp>

namespace ar4j
{
    namespace memory
    {
        
        class Memory;

        class Allocator{
        protected:
            /**
            * @brief Holds actual allocated raw pointer and total size of allocation. Must not be used directly.
            * 
            */
            class Segment{
            protected:
                Allocator* alloc;
                void* data;
                size_t allocationSize, offset, size;
            };

        public:
            
            virtual Memory allocate(size_t size){
                size_t reqSize = sizeof(Segment) + size;

            };
            virtual void deallocate(Memory* mem);
        };

        class Memory;
        
        class Allocator::Segment{


        
        };

        /**
         * @brief Holds list of Memory segments in this memory block. also provides way to allocate and deallocate memory
         * 
         */
        class Memory{
        protected:
            Allocator* allocator;
            size_t allocationSize, offset, size, referenceCount;
            
            Object<Memory> next;

            //store list of segments //double linked ?

        public:
            
            void defragment();
            void extend();
            void insert();
            void split(size_t offsetof);

            void remove();

        };



    } // namespace memory
    
} // namespace ar4j


#endif //AR4J_MEMORY