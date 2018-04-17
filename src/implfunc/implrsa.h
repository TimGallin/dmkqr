#ifndef DMKQR_HEADER_IMPL_RSA
#define DMKQR_HEADER_IMPL_RSA

#include "formulaexe.h"

class ImplRSA : public FormulaExe{
public:
    ImplRSA();
    ~ImplRSA();

    virtual std::string Run() override; 

    void SetPubKey(const std::string& sCertFile);
    void SetPriKey(const std::string& sCertFile);
};

#endif