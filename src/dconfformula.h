#ifndef DMKQR_HEADER_FORMULA
#define DMKQR_HEADER_FORMULA

#include "dconfmeta.h"
#include "tinyxml2/tinyxml2.h"
#include "implfunc/implfunc.h"

#include <map>
class DconfFormula : public DconfMeta{
public:
    DconfFormula();
    ~DconfFormula();

    int Initial(tinyxml2::XMLElement* pFormulaEle);

private:

    /*
     *Get implfunc via func name
     */
    ImplFunc* FactoryImplfunc(const std::string& sName);


    typedef struct _tagFormulaChain{
        int nType;  //0:operator +   1:impl-function 
        ImplFunc* pTarget;      //impl-function pointer

        _tagFormulaChain* pNext;

        _tagFormulaChain(){
            nType = -1;
            pTarget = NULL;
            pNext = NULL;
        }

        
    }FormulaChain;


    /*
     *Parse formula
     */
    int Parse(const char* pFormula, const int nLength);

    FormulaChain _formulaTop;
};

#endif