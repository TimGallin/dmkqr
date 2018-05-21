#ifndef DMKQR_HEADER_IMPL_RSA
#define DMKQR_HEADER_IMPL_RSA

#include "formulaexe.h"

class ImplRSA : public FormulaExe{
public:
	ImplRSA(const std::string& fPubKey, const std::string& fPriKey);
    ~ImplRSA();

    std::string Run() override; 

	std::string GetFormulaName() override;

    void SetPubKey(const std::string& sCertFile);
    void SetPriKey(const std::string& sCertFile);

private:
	void ReadCert(std::string& sCert, const std::string& sFile);


    std::string _sPubkey;
    std::string _sPrikey;
};

#endif