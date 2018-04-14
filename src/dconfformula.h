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
        std::string sType;  //operator or impl-function 
        std::string sParam; //parameter of impl-function or operator(+,*,/)
        void* pTarget;      //impl-function pointer

        _tagFormulaChain* pNext;

        _tagFormulaChain(){
            sType = "";
            sParam = "";
            pTarget = NULL;
            pNext = NULL;
        }

        
    }FormulaChain;

    FormulaChain _formulaChain;
};

#endif