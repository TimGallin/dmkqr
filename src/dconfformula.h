#ifndef DMKQR_HEADER_FORMULA
#define DMKQR_HEADER_FORMULA

#include "dconfmeta.h"
#include "tinyxml2/tinyxml2.h"
#include "implfunc/formulaexe.h"

#include <map>
class DconfFormula : public DconfMeta, public FormulaExe{
public:
	DconfFormula(DconfMeta* pParent);
    ~DconfFormula();

    int Initial(tinyxml2::XMLElement* pFormulaEle);

    virtual std::string Run() override;

	std::string GetFormulaName() override{ return "scheme"; };
private:
    /*
     *Parse formula.pFormula is a sequence of char with a NULL-terminator.
     */
    int Parse(const char* &p, FormulaExe* pParent);

    FormulaExe* FormulaFactory(const char *pFormula);

	FormulaExe* DotVarFactory(const char *pDotvar);
	
	FormulaExe* ConstFactory(const char *pConst);
	//
	DconfMeta* _pParent;
};

#endif