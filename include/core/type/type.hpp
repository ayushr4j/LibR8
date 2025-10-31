#ifndef AR4J_TYPE_TYPE
#define AR4J_TYPE_TYPE

#include "core/memory/memory.hpp"
#include "string"

namespace ar4j {

    class Type{

        virtual size_t getAlignment();
        virtual size_t getSize();

        virtual Type getMember(std::string string);

    };

    template<typename t>
    class NativeType{

    };

    class DynamicType{
        
    };
    class StaticType{

    };

    /// @brief Variable is Combination of Memory and Type.
    class Variable{  
        Type type;
        Memory memory;
    };

}

#endif //AR4J_TYPE_TYPE