#include "dmkqr.h"

#include "dconfpreset.h"
#include "dconfscheme.h"
#include "dconfvar.h"
using namespace std;
using namespace tinyxml2;

DconfScheme::DconfScheme() : _pFirstVar(NULL)
{
}

DconfScheme::~DconfScheme()
{
    if (_pFirstVar){
        while (_pFirstVar) {
            DconfVar* pNext = _pFirstVar->GetSibling();
            delete _pFirstVar;
            _pFirstVar = NULL;
            _pFirstVar= pNext;
        }
    }
}

/*
 *Initial shceme
 */
int DconfScheme::Initial(tinyxml2::XMLElement *pSchemeEle)
{
    if (pSchemeEle == NULL){
        return DMKQR_FAILED;
    }

    //Set name
    const char *pName = pSchemeEle->Attribute("name");
    pName = pName == NULL ? "nameshceme" : pName;
    SetName(pName);

    //Set impl-preset
    tinyxml2::XMLElement *pPreset = pSchemeEle->FirstChildElement(XML_IMPLICIT_PRESET);
    if (pPreset != NULL){
        DconfPreset *pSchemeSet = new DconfPreset(pPreset);
        SetImplPreset(pSchemeSet);
    }

    //Formula

    //Variables
    tinyxml2::XMLElement *pVariableEle = pSchemeEle->FirstChildElement(XML_SCHEME_VAR);

    DconfVar *pTransitVar = NULL;
    while (pVariableEle != NULL){
        DconfVar *pVariable = new DconfVar(pVariableEle);
        if(pTransitVar != NULL){
            pTransitVar->SetSibling(pVariable);    
        }
        
        if(_pFirstVar != NULL){
            _pFirstVar = pVariable;
        }
        
        pTransitVar= pVariable;

         pVariableEle = pVariableEle->NextSiblingElement(XML_SCHEME_VAR);
    }

    return DMKQR_SUCCESS;
}

/*
 *
 */
std::string DconfScheme::Run()
{
}



/*
 *Set&Get Next Sibling scheme.
 */
void DconfScheme::SetSibling(DconfScheme* pNext){
    _pNextScheme = pNext;
}

DconfScheme* DconfScheme::GetSibling(){
    return _pNextScheme;
}


/*
 *Get variable's value via its name.
 */
std::string DconfScheme::GetVarsValue(const char* pName){
    if(pName == NULL){
        return "";
    }

    DconfVar* pTarget = NULL;
    pTarget = _pFirstVar;

    while(pTarget != NULL){
        if(strcmp(pTarget->GetName(), pName) == 0){
            break;
        }

        pTarget = pTarget->GetSibling();
    }

    if(pTarget == NULL){
        return "";
    }

    return pTarget->GetVal();
}