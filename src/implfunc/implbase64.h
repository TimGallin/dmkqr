#ifndef DMKQR_HEADER_IMPL_RSA
#define DMKQR_HEADER_IMPL_RSA

#include "formulaexe.h"

class ImplBase64 : public FormulaExe{
public:
	ImplBase64();
	~ImplBase64();

    std::string Run() override; 

	std::string GetFormulaName() override;
};

#endif