#ifndef AR4J_REFERENCE
#define AR4J_REFERENCE

namespace ar4j
{
    //no namespace for ease of using basic types. basic types are most commonly used part of frameworks
    
    
    class A{
        int a;
        float b;
        double c;
        struct {
            int a; 
            float b;
            double c;
        } d;
    };

    template<typename t>
    class Reference{
        static t dummy;
        template<typename R>
        Reference<R> operator->();

    };

    template<typename T>
    template<typename t >
    Reference<t> Reference<T>::operator->(){
        if constexpr (std::is_pointer_v<R>)
            return dummy;  // R is pointer type
        else
            return Reference<t>{};
    }

    Reference<A> ref;
    

    



    
            
} // namespace ar4j

    
#endif //AR4J_REFERENCE