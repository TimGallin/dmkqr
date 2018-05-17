#ifndef DMKQR_HEADER_IMPL_RSA
#define DMKQR_HEADER_IMPL_RSA


#include "formulaexe.h"

class ImplTime : public FormulaExe{
public:
	enum Precision{
		Seconds = 0,
		MiliSeconds
	};

	ImplTime(const Precision& precision);
	~ImplTime();

    std::string Run() override; 

	std::string GetFormulaName() override;

    void SetPubKey(const std::string& sCertFile);
    void SetPriKey(const std::string& sCertFile);
private:
	Precision _precision;
};

#endif