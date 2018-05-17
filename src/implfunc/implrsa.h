#ifndef DMKQR_HEADER_IMPL_RSA
#define DMKQR_HEADER_IMPL_RSA

#include "formulaexe.h"

class ImplRSA : public FormulaExe{
public:
    ImplRSA();
    ~ImplRSA();

    std::string Run() override; 

	std::string GetFormulaName() override;

    void SetPubKey(const std::string& sCertFile);
    void SetPriKey(const std::string& sCertFile);

private:
    std::string _sPubkeyFile;
    std::string _sPrikeyFile;
};

#endif