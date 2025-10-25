#ifndef AR4J_REFERENCE
#define AR4J_REFERENCE

namespace ar4j
{

    namespace memory
    {
        class Memory;
    } // namespace Memory
    

    //no namespace for ease of using basic types. basic types are most commonly used part of frameworks
    
    class Reference{
        memory::Memory mem;
        size_t offset, size;
    };

    template<typename>
    class Object : Reference{

    };


    
            
} // namespace ar4j

    
#endif //AR4J_REFERENCE