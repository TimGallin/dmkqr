#ifndef DMKQR_HEADER_IMPL_BASE64
#define DMKQR_HEADER_IMPL_BASE64

#include "formulaexe.h"

class ImplBase64 : public FormulaExe{
public:
	ImplBase64();
	~ImplBase64();

    std::string Run() override; 

	std::string GetFormulaName() override;
};

#endif