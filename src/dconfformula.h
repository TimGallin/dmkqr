#ifndef DMKQR_HEADER_FORMULA
#define DMKQR_HEADER_FORMULA

#include "dconfmeta.h"
#include "tinyxml2/tinyxml2.h"
#include "implfunc/formulaexe.h"

#include <map>
class DconfFormula : public DconfMeta, public FormulaExe{
public:
    DconfFormula();
    ~DconfFormula();

    int Initial(tinyxml2::XMLElement* pFormulaEle);

    virtual std::string Run() override;
private:
    /*
     *Parse formula.pFormula is a sequence of char with a NULL-terminator.
     */
    int Parse(const char* pFormula, FormulaExe* pParent);

    FormulaExe* FormulaFactory(const char *pFormula);
};

#endif