#include "dmkqr.h"
#include "dconfformula.h"
#include "dconfpreset.h"
#include "implfunc/implrsa.h"

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
    }

    return pTarget;
}