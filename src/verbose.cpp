#ifndef VERBOSE_CPP
#define VERBOSE_CPP

    //#define VERBOSE
    
    #ifdef VERBOSE 
        #define verbose(ARGUMENT) std::cout << ARGUMENT << std::endl;
    #else
        #define verbose(ARGUMENT)
    #endif
#endif