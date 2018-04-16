#include "dmkqr.h"
#include "dconfformula.h"
#include "dconfpreset.h"
#include "implfunc/implrsa.h"
#include "implfunc/implconstant.h"

using namespace tinyxml2;
using namespace std;

DconfFormula::DconfFormula(){

}

DconfFormula::~DconfFormula(){

}

int DconfFormula::Initial(tinyxml2::XMLElement *pFormulaEle){
    if(pFormulaEle == NULL){
        return DMKQR_FAILED;
    }


    return DMKQR_SUCCESS;
}


/*
 *Get implfunc via func name
 */
ImplFunc* DconfFormula::FactoryImplfunc(const std::string& sName){
    ImplFunc* pTarget = NULL;

    if(sName == "RSA"){
        if(GetImplPreset() == NULL){
            return NULL;
        }
        
        ImplRSA* pImplRsa = new ImplRSA;
        pImplRsa->SetPubKey(GetImplPreset()->GetRsaPubKey());
        pImplRsa->SetPriKey(GetImplPreset()->GetRsaPriKey());

        pTarget = static_cast<ImplFunc*>(pImplRsa);
    }else{
    ImplConstan* pImplConstan = new ImplConstan;
    pImplConstan->SetValue(sName);
    pTarget = static_cast<ImplFunc*>(pImplConstan);
    }

    return pTarget;
}


/*
 *Parse formula
 */
int DconfFormula::Parse(const char* pFormula, const int nLength){
    if(pFormula == NULL){
        return DMKQR_FAILED;
    }

    enum{
        sw_start,
        sw_const,
        sw_dot,
        sw_dot_func,
        sw_dot_var,
        sw_variable,
        sw_function,
        sw_parenthesis_open,
        sw_parenthesis_close,
        sw_plus,
        sw_space
    } state = sw_start;

    FormulaChain *pFChain = &_formulaTop;
    auto fAddChain = [&pFChain,this](const string& sName, int type){
        FormulaChain* pFuncPart = new FormulaChain();
        pFuncPart->pTarget = FactoryImplfunc(sName);
        pFChain->pNext = pFuncPart;
        pFChain = pFuncPart;
    };

    const char* pRecord = pFormula;
    const char* p = pRecord;
    while(nLength){
        char ch = *p;
        switch(state){
            case sw_start:
                if(ch == '('){
                    state = sw_parenthesis_open;
                }
                else if(ch == '.'){
                    state = sw_dot;
                }else if(ch == '$'){
                    state = sw_variable;
                }

                state = sw_const;
                break;
            //Implicit variable.timestamp etc.
            case sw_dot:
                if(dmkqr_str2_cmp(p,'_','f','')){
                    state = sw_dot_func;
                }else if(dmkqr_str2_cmp(p,'_','$','')){
                    state = sw_dot_var;
                }else{
                    return DMKQR_PARSE_ERROR;
                }
                p+=1;
                pRecord = p;

            case sw_dot_func:
                if((ch > 'Z' || ch < 'A') && (ch <'0' || ch>'9')){
                    return DMKQR_PARSE_ERROR;
                }
                
                if(ch == '('){
                    fAddChain(string(pRecord,p-pRecord), 1);
                }
                
            default:
                break;

        ++p;

        }
    }

}