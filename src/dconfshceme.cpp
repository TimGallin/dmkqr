#include "dmkqr.h"

#include "dconfscheme.h"


using namespace std;
using namespace tinyxml2;

DconfScheme::DconfScheme() : _pFirstVar(NULL), _formula(NULL)
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

    //Variables
    tinyxml2::XMLElement *pVariableEle = pSchemeEle->FirstChildElement(XML_SCHEME_VAR);
	
    DconfVar *pTransitVar = NULL;
    while (pVariableEle != NULL){
        DconfVar *pVariable = new DconfVar(pVariableEle);
        if(pTransitVar != NULL){
            pTransitVar->SetSibling(pVariable);    
        }
        
        if(_pFirstVar == NULL){
            _pFirstVar = pVariable;
        }
        
        pTransitVar= pVariable;

         pVariableEle = pVariableEle->NextSiblingElement(XML_SCHEME_VAR);
    }

	//Formula
	tinyxml2::XMLElement *pFormula = pSchemeEle->FirstChildElement(XML_SCHEME_VAR_FORMULA);
	if (pFormula){
		_formula = new DconfFormula(this);
		_formula->SetImplPreset(GetImplPreset());
		_formula->Initial(pFormula);
	}

    return DMKQR_SUCCESS;
}

/*
 *
 */
std::string DconfScheme::Run()
{
	return _formula->Run();
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
FormulaExe* DconfScheme::GetVariable(const char* pName){
    if(pName == NULL){
		return NULL;
    }

    DconfVar* pTarget = NULL;
    pTarget = _pFirstVar;

    while(pTarget != NULL){
		if (strstr(pName, pTarget->GetName())){
        //if(strcmp(pTarget->GetName(), pName) == 0){
			return pTarget;
        }

        pTarget = pTarget->GetSibling();
    }

	return NULL;
}