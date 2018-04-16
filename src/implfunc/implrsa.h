#ifndef DMKQR_HEADER_IMPL_RSA
#define DMKQR_HEADER_IMPL_RSA

#include "implfunc.h"

class ImplRSA : public ImplFunc{
public:
    ImplRSA();
    ~ImplRSA();

    virtual std::string Run(ImplFunc *pInnerFunc); 

    void SetPubKey(const std::string& sCertFile);
    void SetPriKey(const std::string& sCertFile);
};

#endif