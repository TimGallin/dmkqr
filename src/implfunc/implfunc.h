#ifndef DMKQR_HEADER_IMPLFUNC
#define DMKQR_HEADER_IMPLFUNC

#include <string>

class ImplFunc{
public:
    virtual ~ImplFunc();

    /*
     *Every derived class implement this method.
     *The constant is also one of the ImplFuncs, its output is equal to input.
     */
    virtual std::string Run(const std::string& sSource) = 0; 

private:
    ImplFunc();
};

#endif