#ifndef AR4J_MEMORY_SEGMENT
#define AR4J_MEMORY_SEGMENT

#include "./allocation.hpp"

namespace ar4j
{
    namespace memory{ 

        
        /// @brief holds reference to Allocation allocated by Allocator. This is used to count references for Segment. Creation of segment object increments ReferenceCount of Segment. and 
        class Allocator::Segment{
            protected:
                Allocation* allocation = nullptr;
                size_t offset,size;

                Segment(){}   

                ~Segment(){
                    removeAllocation();    //remove currently associent allocation object
                }

                
                /// @brief Sets the Allocation object for this segment. release any previous segment objects and increases current reference count
                /// @param allocation new allocation to be associated
                /// @param offset offset from which this segment starts in allocation
                /// @param size size of segment in allocation this reference points to
                void setAllocation(Allocation* allocation, size_t offset, size_t size){
                    
                    Segment segment = allocation->getReference(offset,size);
                    removeAllocation();    //release previous segment
                    *this = segment;


                }
                /// @brief remove the currently assigned reference to Allocation
                void removeAllocation(){
                    if(allocation != nullptr){
                        allocation->releaseReference();
                    }
                    allocation = nullptr;
                }

                friend class Allocation;
        };

    }    
} // namespace ar4j

    
#endif //AR4J_MEMORY_SEGMENT