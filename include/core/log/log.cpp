#ifndef AR4J_LOG
#define AR4J_LOG

#include <iostream>

namespace ar4j{

    namespace log{

        
        /**
         * @brief 
         * 
         */
        class Logger{
            
            

            public:

                virtual void log(const char* logString){
                    std::cerr << logString;
                }
                
        };

        Logger* instance;

        template <typename Arg, typename... Args>
        void log(Arg arg, Args... args){
            
        };
        template <typename... Args>
        void logd(Args... args){

        };
        template <typename... Args>
        void error(Args... args){

        };
        template <typename... Args>
        void fatalError(Args... args){

        };

    }


    
    

}

#endif //AR4J_LOG